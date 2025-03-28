//
//  MobileRTCVideoCapabilityItem.h
//  MobileRTC
//
//  Created by Zoom Communications on 2020/3/9.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobileRTCVideoCapabilityItem : NSObject

/*!
@brief the video frame width.
*/
@property (nonatomic, assign) int width;
/*!
@brief the video frame height.
*/
@property (nonatomic, assign) int height;
/*!
@brief the video frame rate.
*/
@property (nonatomic, assign) int videoFrame;

@end
