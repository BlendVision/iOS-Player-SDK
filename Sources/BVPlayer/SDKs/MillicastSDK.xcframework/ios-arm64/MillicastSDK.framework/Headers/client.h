/**
 * @file client.h
 * @author David Baldassin
 * @copyright Copyright 2021 CoSMoSoftware.
 * @date 07/2021
 */

#import <Foundation/Foundation.h>
#import <MillicastSDK/exports.h>

// Forward declaration
@class MCStatsReport;

/**
 * @brief The DegradationPreferences enum
 * @brief Based on the spec in https://w3c.github.io/webrtc-pc/#idl-def-rtcdegradationpreference.
 */

#ifdef __cplusplus
enum MCDegradationPreferences
{
  DISABLED,            /**< Don't take any actions based on over-utilization signals. */
  MAINTAIN_RESOLUTION, /**< On over-use, request lower resolution, possibly causing down-scaling. */
  MAINTAIN_FRAMERATE,  /**< On over-use, request lower frame rate, possibly causing frame drops. */
  BALANCED             /**< Try to strike a "pleasing" balance between frame rate or resolution. */
};
#else
typedef enum
{
  DISABLED,            /**< Don't take any actions based on over-utilization signals. */
  MAINTAIN_RESOLUTION, /**< On over-use, request lower resolution, possibly causing down-scaling. */
  MAINTAIN_FRAMERATE,  /**< On over-use, request lower frame rate, possibly causing frame drops. */
  BALANCED             /**< Try to strike a "pleasing" balance between frame rate or resolution. */
} MCDegradationPreferences;
#endif

/**
 * @brief Settings for the minimum, maximum and start bitrates of the streams.
 */

MILLICAST_API @interface MCBitrateSettings : NSObject
@property(nonatomic) NSInteger maxBitrateKbps;   /** The minimum bitrate in kilobits per second */
@property(nonatomic) NSInteger minBitrateKbps;   /** The maximum bitrate in kilobits per second */
@property(nonatomic) NSInteger startBitrateKbps; /** The start bitrate in kilobits per second */
@end

/**
 * @brief The Client Listener protocol which contains methods that will be called
 * on specific events from a Client object.
 */

@protocol MCListener

/**
 * @brief onConnected is called when the WebSocket connection to Millicast is opened
 */

- (void)onConnected;

/**
 * @brief onConnectionError is called when we try to connect to millicast but it fails
 * @param status The HTTP status code
 * @param reason The reason why the client could not connect
 */

- (void)onConnectionError:(int)status withReason:(NSString *)reason;

/**
 * @brief Called when an error message in received from Millicast in response of a websocket command
 * @param message The recevied error message
 */
- (void)onSignalingError:(NSString *)message;

/**
 * @brief onStatsReport is called when a new rtc stats report has been collected.
 * @remarks You must enable the stats to be able to receive a report.
 * @see enableStats
 */

- (void)onStatsReport:(MCStatsReport *)report;

/**
 * @brief Called when a new viewer join the stream or when a viewer quit the stream
 * @param count The current number of viewers.
 */
- (void)onViewerCount:(int)count;

@end

MILLICAST_API @interface MCClientOptions : NSObject

/* multisource options */

/** @brief The id/name of the sourceyou want to publish (publisher only) */
@property(nonatomic, retain) NSString *sourceId;
/** @brief the receiving source you want to pin (subscriber only) */
@property(nonatomic, retain) NSString *pinnedSourceId;
/** @brief the sources you don't want to receive (subscriber only) */
@property(nonatomic, retain) NSArray *excludedSourceId;
/** @brief enable discontinuous transmission on the publishing side, so audio data is only sent when a user’s voice is detected. */
@property(nonatomic, assign) BOOL dtx;
/** @brief the number of multiplxed audio tracks you want to receive (subscriber only) */
@property(nonatomic, assign) int multiplexedAudioTrack;

/* Codecs options (for the publisher only) */
/** @brief The video codec to use (publisher only) */
@property(nonatomic, retain) NSString *videoCodec;
/** @brief The audio codec to use (publisher only) */
@property(nonatomic, retain) NSString *audioCodec;

/* General connection options */
/** @brief Which strategy the use in order to limit the bandwidth usage */
@property(nonatomic, assign) MCDegradationPreferences degradationPreferences;

/** @brief Determines the minimum, maximum and start bitrates */
@property(nonatomic, retain) MCBitrateSettings *bitrateSettings;

/** @brief Enable / disable stereo */
@property(nonatomic, assign) BOOL stereo;
/** @brief Enable the rate at which you want to receive stats report (not implemented yet) */
@property(nonatomic, assign) int statsDelayMs;

@end

/**
 * @brief The Client base class.
 * @brief This is the base class to handle a connection with the Millicast platform.
 */

@protocol MCClient

- (void)setOptions:(MCClientOptions *)opts;

/**
 * @brief connect and open a websocket connection with the millicast platform.
 * @return false if an error occured, true otherwise.
 * @remarks You must set valid credentials before using this method.
 * @remarks returning true does not mean you are connected.
 * You are connected when the Listener's method on_connected is called.
 */

- (BOOL)connect;

/**
 * @brief connection and open a webscoket connection using directly the websocket url and the jwt.
 * @param wsUrl The websocket url returned by the director api
 * @param jwt The JSON Web Token returned by the director api
 * @return true if nothing went wrong during the opening of the websocket connection.
 * You are  connected when the Listener's method on_connected is called.
 */

- (BOOL)connectWithData:(NSString *)wsUrl jwt:(NSString *)jwt;

/**
 * @brief isConnected
 * @return return true if the client is connected to millicast, false otherwise.
 */

- (BOOL)isConnected;

/**
 * @brief disconnect from millicast.
 * @return false if an error occured, true otherwise.
 */

- (BOOL)disconnect;

/**
 * @brief setListener : set the client listener to receive event from the client.
 * @param listener The Client listener
 */

- (void)setListener:(id<MCListener>)listener;

/**
 * @brief Enable the rtc stats collecting.
 * The stats are collected once the client is either publishing or subscribed.
 * @param enable true to enable the stats, false to disable the stats.
 */

- (void)enableStats:(BOOL)enable;

@end

/**
 * @brief Clean and free the memory of dynamic objects.
 * @remarks Call this after all sdk objects have been destroyed. You would likely call this function just before the app exit.
 */

MILLICAST_API @interface MCCleanup : NSObject

+ (void)cleanup;

@end
