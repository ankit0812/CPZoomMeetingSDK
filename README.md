# Zoom SDK Swift Package

This Swift Package provides a Swift Package Manager integration for the Zoom SDK for iOS.

## Requirements

- iOS 13.0+
- Xcode 13.0+
- Swift 5.5+

## Installation

### Swift Package Manager

Add the following to your `Package.swift` file:

```swift
dependencies: [
    .package(url: "YOUR_GITHUB_REPO_URL", from: "1.0.0")
]
```

Or add it through Xcode:
1. File > Add Packages...
2. Enter your GitHub repository URL
3. Select the version you want to use
4. Click Add Package

## Usage

1. Import the package in your Swift files:
```swift
import ZoomSDK
```

2. Initialize the Zoom SDK in your app:
```swift
// In your AppDelegate or main app file
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    // Initialize Zoom SDK
    MobileRTC.shared().initializeSDK()
    return true
}
```

3. Use the Zoom SDK features as needed in your app.

## License

This package is licensed under the same terms as the Zoom SDK. Please refer to the Zoom SDK documentation for more details.

---
Copyright ©2012-2025 Zoom Communications, Inc. All rights reserved.
