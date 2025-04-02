// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "CPZoomMeetingSDK",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "CPZoomMeetingSDK",
            targets: ["CPZoomMeetingSDK"]),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "CPZoomMeetingSDK",
            dependencies: ["MobileRTC"]),
        .binaryTarget(
            name: "MobileRTC",
            path: "lib/MobileRTC.xcframework"
        )
    ]
) 