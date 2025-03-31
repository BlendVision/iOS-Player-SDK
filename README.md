# iOS Player SDK

The `BVPlayer` SDK enables seamless media playback on iOS. This guide helps you integrate the SDK into your project, configure it, and explore sample apps.

- [Installation](#installation)
  - [Swift Package Manager](#using-swift-package-manager)
- [Samples](#samples)
- [Requirements](#requirements)
- [Support](#support)

---

## Installation

The `BVPlayer` SDK can be integrated into your iOS project using **Swift Package Manager (SPM)**.

### Using Swift Package Manager

[Swift Package Manager (SPM)](https://swift.org/package-manager/) automates the process of downloading, compiling, and linking dependencies for Swift projects.

#### Using Xcode
1. Open your project in Xcode 13 or later.
2. Navigate to `Project > Package Dependencies`.
3. Click the `+` button and add the following URL:
   ```
   https://github.com/BlendVision/iOS-Player-SDK
   ```
4. Select the desired version (e.g., `3.0.0`) and add the package to your target.

#### Using `Package.swift`
Add the `BVPlayer` SDK as a dependency in your `Package.swift` file. Replace `Version Number` with the desired SDK version (e.g., `3.0.0`):

```swift
let package = Package(
    name: "YourPackageName",
    dependencies: [
        .package(name: "BVPlayer", url: "https://github.com/BlendVision/bvplayer-ios", .exact("Version Number"))
    ],
    targets: [
        .target(name: "YourTargetName", dependencies: ["BVPlayer"])
    ]
)
```

---

## Samples

Explore sample projects to see the `BVPlayer` SDK in action:
- **General Samples**: Check out the [iOS-Player-Samples repository](https://github.com/BlendVision/iOS-Player-Samples) for various examples.
- **Swift Package Manager Sample**: The `BasicPlaybackSPM` sample demonstrates integration using SPM.

---

## Requirements

- **iOS Version**: iOS 14.0 or later
- **Xcode Version**: Xcode 14 or later

---

## Support

For issues, questions, or contributions:
- **GitHub Issues**: Report bugs or request features on the [GitHub Issues page](https://github.com/BlendVision/iOS-Player-SDK/issues).
- **Documentation**: Refer to the [official documentation](https://developers.blendvision.com/_/sdk/player/ios/documentation/bvplayer) for detailed API references.
- **Community**: Join the discussion on [GitHub Discussions](https://github.com/BlendVision/iOS-Player-SDK/discussions).
```
