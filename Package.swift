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
            url: "https://github.com/BlendVision/iOS-Player-SDK/releases/download/2.5.2/KKSPlayer-2.5.2.45.xcframework.zip",
            checksum: "cb8d3aff41fc087bec37198384ec11a8268b04bdf416c976405e0366856a2fdc"
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
