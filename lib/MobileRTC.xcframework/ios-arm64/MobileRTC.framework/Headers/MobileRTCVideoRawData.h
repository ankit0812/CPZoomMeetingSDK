//
//  MobileRTCVideoRawData.h
//  MobileRTC
//
//  Created by Zoom Communications on 2019/8/6.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobileRTCVideoRawData : NSObject

/*!
 @brief The y-data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *yBuffer;

/*!
 @brief The u-data data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *uBuffer;

/*!
 @brief The v-data data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *vBuffer;

/*!
 @brief The video data's size.
 */
@property (nonatomic, assign) CGSize size;

/*!
 @brief The data pointer to a video's alpha data.
 */
@property (nonatomic, assign) char *alphaBuffer;

/*!
 @brief the alpha buffer data length
 */
@property (nonatomic, assign) unsigned int alphaBufferLen;

/*!
 @brief The video data's raw data format defined in {@link MobileRTCVideoRawDataFormat}.
 */
@property (nonatomic, assign) MobileRTCFrameDataFormat format;

/*!
 @brief The video data's rotation defined in {@link MobileRTCVideoRawDataRotation}.
 */
@property (nonatomic, assign) MobileRTCVideoRawDataRotation rotation;

/*!
 @brief Whether adding a reference is allowed.
 @return true if allow. Otherwise, false.
 */
- (BOOL)canAddRef;

/*!
 @brief Add to reference count.
 @return true if successfully added. Otherwise, this returns false.
 */
- (BOOL)addRef;

/*!
 @brief Subtract from reference count.
 */
- (NSInteger)releaseRef;

@end

