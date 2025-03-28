//
//  MobileRTCMeetingService+Reaction.h
//  MobileRTC
//
//  Created by Zoom Communications on 2020/12/3.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

NS_ASSUME_NONNULL_BEGIN


@interface MobileRTCMeetingService (Reaction)

/*!
 @brief Determine if the Reaction feature is enabled.
 @return YES means Reaction feature is enabled, otherwise not.
 */
- (BOOL)isEmojiReactionEnabled;

/**
 * @brief Send emoji reaction.
 * @param type - The type of the emoji reaction.
 * @return If the function succeeds, it will return MobileRTCSDKError_Succuss, otherwise not.
 * @warning MobileRTCEmojiReactionSkinTone doesn't work for MobileRTCEmojiReactionType_Heart type. To set MobileRTCEmojiReactionSkinTone, use -[MobileRTCMeetingSettings setReactionSkinTone] in MobileRTCMeetingSettings.h file
 */
- (MobileRTCSDKError)sendEmojiReaction:(MobileRTCEmojiReactionType)type;

/**
 * @brief Send the emoji feedback.
 * @param type  Specify the emoji feedback type to be sent. See {@link MobileRTCEmojiFeedbackType}.
 * @return If the function succeeds, it will return MobileRTCMeetError_Success, otherwise not.
 */
- (MobileRTCSDKError)sendEmojiFeedback:(MobileRTCEmojiFeedbackType)type;

/**
 * @brief Cancel the emoji feedback.
 * @return If the function succeeds, it will return MobileRTCMeetError_Success, otherwise not.
 */
- (MobileRTCSDKError)cancelEmojiFeedback;
@end

NS_ASSUME_NONNULL_END
