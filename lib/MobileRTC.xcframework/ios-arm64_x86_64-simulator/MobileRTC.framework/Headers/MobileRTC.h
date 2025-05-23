//
//  MobileRTC.h
//  MobileRTC
//
//  Created by Zoom Communications on 8/7/14.
//  Copyright (c) Zoom Communications, Inc. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <MobileRTC/MobileRTCConstants.h>
#import <MobileRTC/MobileRTCMeetingUserInfo.h>
#import <MobileRTC/MobileRTCRoomDevice.h>
#import <MobileRTC/MobileRTCAuthService.h>
#import <MobileRTC/MobileRTCMeetingService.h>
#import <MobileRTC/MobileRTCAutoFramingParameter.h>
#import <MobileRTC/MobileRTCMeetingService+AppShare.h>
#import <MobileRTC/MobileRTCMeetingService+InMeeting.h>
#import <MobileRTC/MobileRTCMeetingService+Customize.h>
#import <MobileRTC/MobileRTCMeetingService+Audio.h>
#import <MobileRTC/MobileRTCMeetingService+Video.h>
#import <MobileRTC/MobileRTCMeetingService+User.h>
#import <MobileRTC/MobileRTCMeetingService+Chat.h>
#import <MobileRTC/MobileRTCMeetingService+Avatar.h>
#import <MobileRTC/MobileRTCMeetingService+Webinar.h>
#import <MobileRTC/MobileRTCMeetingService+QA.h>
#import <MobileRTC/MobileRTCMeetingService+VirtualBackground.h>
#import <MobileRTC/MobileRTCMeetingService+Interpretation.h>
#import <MobileRTC/MobileRTCMeetingService+BO.h>
#import <MobileRTC/MobileRTCMeetingService+Reaction.h>
#import <MobileRTC/MobileRTCMeetingService+LiveTranscription.h>
#import <MobileRTC/MobileRTCMeetingService+RawArchiving.h>
#import <MobileRTC/MobileRTCMeetingService+Phone.h>
#import <MobileRTC/MobileRTCMeetingService+SmartSummary.h>
#import <MobileRTC/MobileRTCMeetingService+AICompanion.h>
#import <MobileRTC/MobileRTCMeetingService+Whiteboard.h>
#import <MobileRTC/MobileRTCMeetingService+Polling.h>
#import <MobileRTC/MobileRTCMeetingService+Encryption.h>
#import <MobileRTC/MobileRTCMeetingSettings.h>
#import <MobileRTC/MobileRTCInviteHelper.h>
#import <MobileRTC/MobileRTCMeetingChat.h>
#import <MobileRTC/MobileRTCMeetingDelegate.h>
#import <MobileRTC/MobileRTCVideoView.h>
#import <MobileRTC/MobileRTCMeetingActionItem.h>
#import <MobileRTC/MobileRTCAnnotationService.h>
#import <MobileRTC/MobileRTCRemoteControlService.h>
#import <MobileRTC/MobileRTCCameraControlService.h>
#import <MobileRTC/MobileRTCWaitingRoomService.h>
#import <MobileRTC/MobileRTCRenderer.h>
#import <MobileRTC/MobileRTCAudioRawDataHelper.h>
#import <MobileRTC/MobileRTCVideoSourceHelper.h>
#import <MobileRTC/MobileRTCShareSourceHelper.h>
#import <MobileRTC/MobileRTCAudioSourceHelper.h>
#import <MobileRTC/MobileRTCSMSService.h>
#import <MobileRTC/MobileRTCDirectShareService.h>
#import <MobileRTC/MobileRTCReminderHelper.h>

/*!
 @brief MobileRTCSDKInitContext.
 */
@interface MobileRTCSDKInitContext : NSObject
/*!
 @brief [Required] domain The domain is used to start/join a ZOOM meeting.
 */
@property (nonatomic, copy)   NSString                      * _Nullable domain;
/*!
 @brief [Optional] enableLog Set MobileRTC log enable or not. The path of Log: Sandbox/AppData/tmp/
 */
@property (nonatomic, assign) BOOL                          enableLog;
/*!
 @brief [Optional] bundleResPath Set the path of MobileRTC resource bundle.
 */
@property (nonatomic, copy) NSString                        * _Nullable bundleResPath;
/*!
 @brief [Optional] Locale fo Customer.
 */
@property (nonatomic, assign) MobileRTC_ZoomLocale          locale;
/*!
 @brief [Optional] The video rawdata memory mode. Default is MobileRTCRawDataMemoryModeStack, only for rawdataUI.
 */
@property (nonatomic, assign) MobileRTCRawDataMemoryMode    videoRawdataMemoryMode;
/*!
 @brief [Optional] The share rawdata memory mode. Default is MobileRTCRawDataMemoryModeStack, only for rawdataUI.
 */
@property (nonatomic, assign) MobileRTCRawDataMemoryMode    shareRawdataMemoryMode;
/*!
 @brief [Optional] The audio rawdata memory mode. Default is MobileRTCRawDataMemoryModeStack, only for rawdataUI.
 */
@property (nonatomic, assign) MobileRTCRawDataMemoryMode    audioRawdataMemoryMode;
/*!
 @brief [Optional] If you use screen share, you need create group id in your apple developer account, and setup here.
 */
@property (nonatomic, copy) NSString                        * _Nullable appGroupId;
/*!
 @brief [Optional] If you use direct screen share, you need create replaykit bundle identifier in your apple developer account, and setup here.
 */
@property (nonatomic, copy) NSString                        * _Nullable replaykitBundleIdentifier;

@property (nonatomic, assign) NSInteger                     wrapperType;

/*!
 @brief Enable Custom In-Meeting UI in meeting.
 */
@property (assign, nonatomic) BOOL enableCustomizeMeetingUI;

@end

/*!
 MobileRTC
 @brief Initialize the class to acquire all the services. 
 @warning Access to the class and all the other components of the MobileRTC by merging <MobileRTC/MobileRTC.h> into source code.
 @warning The user can only obtain SDK configuration by initializing the class.  
 */
@interface MobileRTC : NSObject
/*!
 @brief MobileRTC domain, read-only.  
 */
@property (copy, nonatomic, readonly) NSString * _Nullable mobileRTCDomain;

/*!
 @brief The path of MobileRTC Resources Bundle, read-only. 
 */
@property (copy, nonatomic, readonly) NSString * _Nullable mobileRTCResPath;

/*!
 @brief The name of APP Localizable file for MobileRTC, read-only.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable mobileRTCCustomLocalizableName;

/*!
 @brief Call the function to get the MobileRTC client.
 @warning The sharedSDK will be instantiated only once over the lifespan of the application. Configure the client with the specified key and secret.
 @return A preconfigured MobileRTC client.
 */
+ (MobileRTC * _Nonnull)sharedRTC;

/*!
 @brief Call the function to initialize MobileRTC.
 @warning The instance will be instantiated only once over the lifespan of the application.
 @param context Initialize the parameter configuration of the SDK, please See [MobileRTCSDKInitContext]
 */
- (BOOL)initialize:(MobileRTCSDKInitContext * _Nonnull)context;

/*!
 @brief Call the function to switch MobileRTC domain.
 @param newDomain The new domain.
 @return YES indicates successfully. Otherwise not.
 @warning After switch domain, need to auth again.
 */
- (BOOL)switchDomain:(NSString * _Nonnull)newDomain force:(BOOL)force;

/*!
 @brief Set the name of Localizable file for MobileRTC.
 @warning This method is optional, MobileRTC will read Custom Localizable file from App’s main bundle first.
 @param localizableName The name of APP Localizable file for MobileRTC.
 */
- (void)setMobileRTCCustomLocalizableName:(NSString * _Nullable)localizableName;

/*!
 @brief Get the root navigation controller of MobileRTC client.
 @return The root navigation controller.
 */
- (UINavigationController * _Nullable)mobileRTCRootController;

/*!
 @brief Set the MobileRTC client root navigation controller.
 @param navController The root navigation controller for pushing MobileRTC meeting UI.
 @warning This method is optional, call the method if the window's rootViewController of the application is the UINavigationController, prefer to set the root view controller.<UINavigationController>.
 @warning If not set the root view controller. Zoom meeting will displayed on the  WINDOW which level same as app window, create by SDK.
 @warning In that case, if you want to disaplay customized UI of you app above Zoom meeting view, should get meeting view(call "- (UIView * _Nullable)meetingView;) and then add your customized view to the meeting view.
 */
- (void)setMobileRTCRootController:(UINavigationController * _Nullable)navController;

/*!
 @brief Check the MobileRTC version.  
 @return The version of MobileRTC.
 */
- (NSString * _Nullable)mobileRTCVersion;

/*!
 @brief Query if the MobileRTC is authorized successfully or not. 
 @return YES indicates authorized successfully. Otherwise not.
 */
- (BOOL)isRTCAuthorized;

/*!
 @brief Query if custom meeting UI is supported by MobileRTC. 
 @return YES indicates support. Otherwise not.
 */
- (BOOL)isSupportedCustomizeMeetingUI;

/*!
 @brief Query if custom meeting UI is enable by MobileRTC.
 @return YES indicates enable. Otherwise not.
 */
- (BOOL)isEnabledCustomizeMeetingUI;

/*!
 @brief Get the default authentication service.  
 @warning The MobileRTC can not be called unless the authentication service is called successfully. 
 @return The preconfigured authentication service. 
 */
- (MobileRTCAuthService * _Nullable)getAuthService;

/*!
 @brief Get the default meeting service.  
 @return The default meeting service.  
 */
- (MobileRTCMeetingService * _Nullable)getMeetingService;

/*!
 @brief Get the MobileRTC default meeting settings. 
 @return The MobileRTC default meeting settings. 
 */
- (MobileRTCMeetingSettings * _Nullable)getMeetingSettings;

/*!
 @brief Get the MobileRTC default annotation service.   
 @return The preconfigured annotation service.  
 */
- (MobileRTCAnnotationService * _Nullable)getAnnotationService;

/*!
 @brief Get the default MobileRTC remote control service.   
 @return The preconfigured remote control service. 
 */
- (MobileRTCRemoteControlService * _Nullable)getRemoteControlService;

/*!
 @brief Get the default MobileRTC camera control service.
 @return The preconfigured camera control service.
 */
- (MobileRTCCameraControlService * _Nullable)getCameraControlService:(NSInteger)userId;

/*!
 @brief Revoke camera control privilege.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)revokeCameraControlPrivilege;

/*!
 @brief Get the default MobileRTC waiting room service.
 @return The MobileRTC waiting room service.
 */
- (MobileRTCWaitingRoomService * _Nullable)getWaitingRoomService;

/*!
 @brief Get the default MobileRTC sms service.
 @return The MobileRTC sms service.
 */
- (MobileRTCSMSService * _Nullable)getSMSService;

/*!
@brief Get the default MobileRTC direct share service.
@return The MobileRTC direct share service.
*/
- (MobileRTCDirectShareService * _Nullable)getDirectShareService;

/*!
@brief Get the default MobileRTC reminder helper.
@return The MobileRTC reminder helper.
*/
- (MobileRTCReminderHelper * _Nullable)getReminderHelper;

/*!
@brief Get the video source helper.@see MobileRTCVideoSourceHelper
@return The object of MobileRTCVideoSourceHelper.
*/
- (MobileRTCVideoSourceHelper * _Nullable)getVideoSourceHelper;

/*!
@brief Get the video source helper.@see MobileRTCShareSourceHelper
@return The object of MobileRTCShareSourceHelper.
*/
- (MobileRTCShareSourceHelper * _Nullable)getShareSourceHelper;

/*!
 @brief Get the languages supported by MobileRTC.   
 @warning The languages supported by MobileRTC are English, German, Spanish, Japanese, French, Simplified Chinese, Traditional Chinese.
 @return An array of languages supported by MobileRTC.
 */
- (NSArray <NSString *> * _Nonnull)supportedLanguages;

/*!
 @brief Set the MobileRTC language.
 @warning Choose one of the languages supported by MobileRTC.  
 @param lang The specified language.  
 */
- (void)setLanguage:(NSString * _Nullable)lang;

/*!
 @brief Notify common layer that application will resign active. Call the systematical method and then call the appWillResignActive via applicationWillResignActive.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationWillResignActive:(UIApplication *)application".  
 */
- (void)appWillResignActive;

/*!
 @brief Notify common layer that application did become active. Call the appDidBecomeActive via applicationDidBecomeActive.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationDidBecomeActive:(UIApplication *)application". 
 */
- (void)appDidBecomeActive;

/*!
 @brief Notify common layer that application did enter background. Call the appDidEnterBackground via applicationDidEnterBackground.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationDidEnterBackground:(UIApplication *)application".
 */
- (void)appDidEnterBackground;

/*!
 @brief Notify common layer that application will terminate. Call the appWillTerminate via applicationWillTerminate.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationWillTerminate:(UIApplication *)application".
 */
- (void)appWillTerminate;

/*!
 @brief cleanup the SDK.
 @warning user will clean up the SDK when no longer need the SDK instance, only can call this method after initialized.
 */
- (void)cleanup;

/*!
@brief Notify MobileRTC when the root UIViewController's traitCollection will change
@param newCollection The first parameter of willTransitionToTraitCollection:withTransitionCoordinator which is UIContentContainer method.
@param coordinator The second parameter of willTransitionToTraitCollection:withTransitionCoordinator which is UIContentContainer method.
@warning Not work in Custom In-Meeting UI.
@warning Call this method when the window.rootViewController recevived willTransitionToTraitCollection:withTransitionCoordinator.
*/
- (void)willTransitionToTraitCollection:(UITraitCollection *_Nullable)newCollection withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>_Nullable)coordinator;

/*!
@brief Notify MobileRTC when the root UIViewController's view size will change
@param size The first parameter of viewWillTransitionToSize:withTransitionCoordinator.
@param coordinator the second parameter of viewWillTransitionToSize:withTransitionCoordinator.
@warning Not work in Custom In-Meeting UI.
@warning Call this method when the window.rootViewController recevived viewWillTransitionToSize:withTransitionCoordinator.
*/
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>_Nullable)coordinator;

/*!
 @brief Gets whether you have permission to use raw data.
 @warning It is necessary to call the method after auth success.
 */
- (BOOL)hasRawDataLicense;

@end
