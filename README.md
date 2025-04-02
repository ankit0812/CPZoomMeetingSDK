# CPZoomMeetingSDK

A Swift Package for integrating Zoom SDK into iOS applications.

## Installation

### Swift Package Manager

1. Add the package to your Xcode project:
   - In Xcode, go to File > Add Packages
   - Enter the repository URL
   - Select the version you want to use

2. After adding the package, you need to reassemble the framework:
   ```bash
   chmod +x reassemble.sh
   ./reassemble.sh
   ```

## Usage

```swift
import CPZoomMeetingSDK

// Initialize the SDK
let authService = MobileRTCAuthService()
authService.sdkKey = "YOUR_SDK_KEY"
authService.sdkSecret = "YOUR_SDK_SECRET"

// Start a meeting
let meetingService = MobileRTCMeetingService()
meetingService.startMeeting(withMeetingNumber: "YOUR_MEETING_NUMBER", userName: "YOUR_USER_NAME")
```

## Requirements

- iOS 13.0+
- Xcode 13.0+
- Swift 5.5+

## License

This package is licensed under the MIT License. See the LICENSE file for details.

---
Copyright ©2012-2025 Zoom Communications, Inc. All rights reserved.
