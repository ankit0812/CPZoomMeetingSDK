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
            targets: ["MobileRTC"]),
    ],
    targets: [
        .binaryTarget(
            name: "MobileRTC",
            path: "lib/MobileRTC.xcframework"
        )
    ]
) 