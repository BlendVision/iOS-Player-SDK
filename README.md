# iOS-Player-SDK

- [Installation](#installation)
    - [Swift Package Manager](#using-swift-package-manager)
    - [Add the Player SDK to the Project directly](#add-the-player-sdk-to-the-project-directly)
- [Getting Started](#getting-started)
    - [Configure the license key](#configure-the-license-key)
- [Samples](#samples)

## Installation
To add the `BVPLAYER` SDK as a dependency to your project, you have two options: Swift Package Manager or adding the SDK bundle directly.

## Dependency
iOS Player SDK has a dependency on the GoogleCast framework version 4.7.1.04.11. This dependency enables integration with Google Cast for casting media content to Chromecast devices.

### Using [Swift Package Manager](https://swift.org/package-manager/)
[Swift Package Manager](https://swift.org/package-manager/) is a tool for managing the distribution of Swift frameworks. It integrates with the Swift build system to automate the process of downloading, compiling, and linking dependencies.

#### Using Xcode
To integrate using Xcode 13, open your Project file and specify it in `Project > Package Dependencies` using the following URL:

```
https://github.com/BlendVision/iOS-Player-SDK
```

#### Using `Package.swift`
To integrate using Apple's Swift Package Manager, add the following as a dependency to your `Package.swift` and replace `Version Number` with the desired version of the SDK.

```swift
.package(name: "BVPlayer", url: "https://github.com/BlendVision/bvplayer-ios", .exact("Version Number"))
```

And then specify the `BVPlayer` as a dependency of the desired target. Here is an example of a `Package.swift` file:

```swift
let package = Package(
  ...
  dependencies: [
    ...
    .package(name: "BVPlayer", url: "https://github.com/BlendVision/bvplayer-ios", .exact("Version Number"))
  ],
  targets: [
    .target(name: "<NAME_OF_YOUR_PACKAGE>", dependencies: ["BVPlayer"])
  ]
  ...
)
```

##### Limitation
Executing `swift build` from the command line is currently not supported. Open the Package in Xcode if you are developing another Package depending on `BVPlayer`.

### Add the Player SDK to the Project directly
When using Xcode, go to the `General` page or your app target and add the SDK bundle (`BVPlayer.xcframework`) under `Linked Frameworks and Libraries`. The latest SDK for iOS can be downloaded [here](https://github.com/BlendVision/iOS-Player-SDK/releases/download/3.0.0/BVPlayer-3.0.0.7953271_Release.xcframework.zip).

## Getting Started
### Configure the license key

- You can set the license key via the `UniPlayerConfig.key` property when creating a `UniPlayer` instance.

## Samples

For samples using the BV Player iOS SDK see [here](https://github.com/BlendVision/iOS-Player-SDK).
For a sample using the Swift Package Manager for integration, see sample named `BasicPlaybackSPM`.
