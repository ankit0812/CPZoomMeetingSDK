//
//  MobileRTCWaitingRoomService.h
//  MobileRTC
//
//  Created by Zoom Communications on 2019/3/6.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @brief WaitingRoom LayoutType.
 Here are more detailed structural descriptions.
 */
typedef NS_ENUM(NSUInteger, MobileRTCWaitingRoomLayoutType) {
    MobileRTCWaitingRoomLayoutType_Default = 0,
    MobileRTCWaitingRoomLayoutType_Logo,
    MobileRTCWaitingRoomLayoutType_Video,
};

/*!
 @brief Downloading Status of MobileRTCCustomWaitingRoomData.
 Here are more detailed structural descriptions.
 */
typedef NS_ENUM(NSUInteger, MobileRTCCustomWaitingRoomDataStatus) {
    MobileRTCCustomWaitingRoomDataStatus_Init,
    MobileRTCCustomWaitingRoomDataStatus_Downloading,
    MobileRTCCustomWaitingRoomDataStatus_Download_OK,
    MobileRTCCustomWaitingRoomDataStatus_Download_Fail,
};

/*!
 @brief The WaitingRoom Customize Data Info.
 Here are more detailed structural descriptions..
 */
@interface MobileRTCCustomWaitingRoomData : NSObject

@property (nonatomic, retain) NSString * _Nullable title;

@property (nonatomic, retain) NSString * _Nullable descriptionString;

@property (nonatomic, retain) NSString * _Nullable logoPath;

@property (nonatomic, retain) NSString * _Nullable imagePath;

@property (nonatomic, retain) NSString * _Nullable videoPath;

@property (nonatomic, assign) MobileRTCWaitingRoomLayoutType type;

@property (nonatomic, assign) MobileRTCCustomWaitingRoomDataStatus status;

@end

/*!
 MobileRTCWaitingRoomServiceDelegate
 @brief Meeting host enabled the waiting room feature, then the delegate will receive this notification  #only for custom UI#.
 */
@protocol MobileRTCWaitingRoomServiceDelegate <NSObject>
@optional

/*!
 MobileRTCWaitingRoomServiceDelegate
 @brief Meeting host enabled the waiting room feature, then the delegate will receive this notification  #only for custom UI#.
         onWaitingRoomUserJoin: will notify the host someone entery the waiting room.
         onWaitingRoomUserLeft: will notify the host someone left from waiting room.
 */
- (void)onWaitingRoomUserJoin:(NSUInteger)userId;
- (void)onWaitingRoomUserLeft:(NSUInteger)userId;

/*!
 @brief During the waiting room, this callback event will be triggered when host change audio status.
 @param audioCanTurnOn YES means audio can be turned on. Otherwise not.
 */
- (void)onWaitingRoomPresetAudioStatusChanged:(BOOL)audioCanTurnOn;

/*!
 @brief During the waiting room, this callback event will be triggered when host change video status.
 @param videoCanTurnOn YES means video can be turned on. Otherwise not.
 */
- (void)onWaitingRoomPresetVideoStatusChanged:(BOOL)videoCanTurnOn;

/*!
 @brief During the waiting room, this callback event will be triggered when requestCustomWaitingRoomData called.
 @param data The WaitingRoom Customize Data Info.
 */
- (void)onCustomWaitingRoomDataUpdated:(MobileRTCCustomWaitingRoomData *_Nullable)data;

/**
 * @brief Callback of that waiting room user name changed.
 * @param userID The ID of user whose user name has changed.
 * @param userName The new name of user.
 */
- (void)onWaitingRoomUserNameChanged:(NSInteger)userID userName:(nonnull NSString *)userName;

@end

@interface MobileRTCWaitingRoomService : NSObject

/*!
 @brief Waiting Room service delegate.
 */
@property (weak, nonatomic) id<MobileRTCWaitingRoomServiceDelegate> _Nullable delegate;

/*!
 @brief Is this meeting support Waiting Room feature.
 @return Yes if support waiting room.
 */
-(BOOL)isSupportWaitingRoom;

/*!
 @brief Is this meeting enabled Waiting Room feature.
 @return Yes if enabled.
 */
-(BOOL)isWaitingRoomOnEntryFlagOn;

/*!
 Query if enableWaitingRoomOnEntry feature locked.
 
 @return YES means enabled. NO not.
 */
-(BOOL)isWaitingRoomOnEntryLocked;
/*!
 @brief enable or disable waiting room feature of this meeting.
 @return the result of this operation.
 */
- (MobileRTCMeetError)enableWaitingRoomOnEntry:(BOOL)bEnable;

/*!
 @brief get the waiting room user id list.
 @return waiting room user list.
 */
- (nullable NSArray <NSNumber *> *)waitingRoomList;

/*!
 @brief get the user detail information in waiting room.
 @return waiting room user information.
 */
- (nullable MobileRTCMeetingUserInfo*)waitingRoomUserInfoByID:(NSUInteger)userId;

/*!
 @brief admit the user go to meeting fram waiting room.
 @return the result of this operation.
 @warning Only meeting host/co-host can run the function.
 */
- (MobileRTCSDKError)admitToMeeting:(NSUInteger)userId;

/*!
 @brief Permit all of the users currently in the waiting room to join the meeting.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 Otherwise failed, the return is error. For more details, see [MobileRTCSDKError] enum.
 */
- (MobileRTCSDKError)admitAllToMeeting;
/*!
 @brief put the user to waiting room from meeting.
 @return the result of this operation.
 @warning Only meeting host/co-host can run the function.
 */
- (MobileRTCSDKError)putInWaitingRoom:(NSUInteger)userId;

/*!
 @brief Determine if the attendee is enabled to turn on audio when joining the meeting.
 @return YES indicates to enable to turn on.
 */
- (BOOL)isAudioEnabledInWaitingRoom;

/*!
 @brief Determine if the attendee is enabled to turn on video when joining the meeting.
 @return YES indicates to enable to turn on.
 */
- (BOOL)isVideoEnabledInWaitingRoom;

/*!
 @brief Get the WaitingRoom CustomizeData information in the waiting room.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
 */
- (MobileRTCSDKError)requestCustomWaitingRoomData;

/**
 * @brief Determine if host or cohost is enabled to rename user in the waiting room.
 * @return True indicates to enable to turn on.
 */
- (BOOL)canRenameUser;

/**
 * @brief Change user's screen name in the waiting room.
 * @param userID Tnto waiting room byhe ID of user who is put i host/co-host.
 * @param userName The new user name.
 * @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise failed.
 */
- (MobileRTCSDKError)renameUser:(NSInteger)userID newUserName:(nonnull NSString * )userName;

/**
 * @brief Determine if host or cohost is enabled to expel user in the waiting room.
 * @return True indicates can expel user.
 */
- (BOOL)canExpelUser;

/**
 * @brief Remove the specified user from waiting room.
 * @param userID The ID of user who is put into waiting room by host/co-host.
 * @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise failed.
 */
- (MobileRTCSDKError)expelUser:(NSInteger)userID;

@end
