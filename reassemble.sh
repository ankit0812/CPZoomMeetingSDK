#!/bin/bash

# Create directories if they don't exist
mkdir -p "lib/MobileRTC.xcframework/ios-arm64_x86_64-simulator/MobileRTC.framework"
mkdir -p "lib/MobileRTC.xcframework/ios-arm64/MobileRTC.framework"

# Reassemble simulator binary
cat chunks/simulator_* > "lib/MobileRTC.xcframework/ios-arm64_x86_64-simulator/MobileRTC.framework/MobileRTC"

# Reassemble device binary
cat chunks/device_* > "lib/MobileRTC.xcframework/ios-arm64/MobileRTC.framework/MobileRTC"

# Make the binaries executable
chmod +x "lib/MobileRTC.xcframework/ios-arm64_x86_64-simulator/MobileRTC.framework/MobileRTC"
chmod +x "lib/MobileRTC.xcframework/ios-arm64/MobileRTC.framework/MobileRTC"

echo "Framework reassembled successfully!"
