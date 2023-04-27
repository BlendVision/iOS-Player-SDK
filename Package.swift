// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "BVPlayerUtilities",
    defaultLocalization: "en",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "BVPlayerUtilities",
            targets: ["BVPlayer"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .target(
            name: "BVPlayer",
            dependencies: ["MillicastSDK", "HLSParser", "SwiftWebVTT"]),
        .binaryTarget(
            name: "MillicastSDK",
            path: "Sources/BVPlayer/SDKs/MillicastSDK.xcframework"
        ),
        .binaryTarget(
            name: "SwiftWebVTT",
            path: "Sources/BVPlayer/SDKs/SwiftWebVTT.xcframework"
        ),
        .binaryTarget(
            name: "HLSParser",
            path: "Sources/BVPlayer/SDKs/HLSParser.xcframework"
        )
    ]
)
