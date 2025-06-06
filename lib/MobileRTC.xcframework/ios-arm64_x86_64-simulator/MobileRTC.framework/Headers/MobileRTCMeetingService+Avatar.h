//
//  MobileRTCMeetingService+Avatar.h
//  MobileRTC
//
//  Created by Zoom on 10/10/22.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

/*!
@brief 3d avatar image item.
*/
@interface MobileRTC3DAvatarImageInfo : NSObject
/*!
 @brief Determine the usage of current image.
 */
@property (nonatomic, assign) BOOL isSelected;

/*!
 @brief Get the file path of current image.
 */
@property (nonatomic, copy) NSString * _Nullable imagePath;

/*!
 @brief Get the name of current image.
 */
@property (nonatomic, copy) NSString * _Nullable imageName;

/*!
 @brief Get the index of current image.
 */
@property (nonatomic, assign) NSInteger index;

/*!
 @brief Determine if it is the most recently used image.
 */
@property(nonatomic,assign) BOOL isLastUsed;

@end


/*!
 @brief for 3d avatar interface
 */
@interface MobileRTCMeetingService (Avatar)

/*!
 @brief Determine if the 3D avatar feature is supported by video device.
 @return Yes indicates that the video device supports the 3D avatar feature.
 */
- (BOOL)is3DAvatarSupportedByDevice;

/*!
 @brief Determine if the 3D avatar feature is enabled.
 @return Yes indicates the video filter feature is enabled.
 */
- (BOOL)is3DAvatarEnabled;

/*!
 @brief Get the array of the video filter images.
 @return the array of <MobileRTC3DAvatarImageInfo*> if the call success, otherwise return nil.
 */
- (NSArray <MobileRTC3DAvatarImageInfo* >* _Nullable)get3DAvatarImageList;

/*!
 @brief Specify an image to be the video filter image.
 @param imageInfo Specify the image to use.
 @return success of errors of this function call.
 @warning Will close the 3D avatar when the imageInfo.index is -1.
 */
- (MobileRTCSDKError)set3DAvatarImage:(MobileRTC3DAvatarImageInfo*_Nullable)imageInfo;

/*!
 @brief Determine if show the last used avatar in the meeting.
 @param bShow YES indicates to show the last used avatar.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.Otherwise failed.
 */
- (MobileRTCSDKError)showAvatar:(BOOL)bShow;

/*!
 @brief Determine if the meeting is showing the avatar.
 @return YES indicates the meeting is showing the avatar.
 */
- (BOOL)isShowAvatar;

/*!
 @brief Enable or disable 3D avatar effect when join meeting
 @param enable Ture if enable 3D avatar effect, otherwise false
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed, returns calling error. For more details, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)enable3DAvatarEffectForAllMeeting:(BOOL)enable;

/*!
 @brief Determine whether 3D avatar is enabled when the join meeting
 @return True if enabled, otherwise false.
 */
- (BOOL)is3DAvatarEffectForAllMeetingEnabled;
@end

