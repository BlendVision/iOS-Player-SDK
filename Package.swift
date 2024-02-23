// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "BVPlayer",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "BVPlayer",
            targets: ["BVPlayer"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(
            name: "BVPlayer",
            url: "https://github.com/BlendVision/iOS-Player-SDK/releases/download/3.0.0/BVPlayer-3.0.0.7953271_Release.xcframework.zip",
            checksum: "f7a662404f0b2fa8e0acc7b5e4a55ee43de3399049d4c5448781679127a2e077"
        )
    ]
)
