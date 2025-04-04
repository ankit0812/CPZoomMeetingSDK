//
//  MobileRTCRemoteControlService.h
//  MobileRTC
//
//  Created by Zoom Communications on 2018/6/22.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MobileRTCRemoteControlDelegate;

/*!
 @brief MobileRTCRemoteControlInputType An Enumeration of input types when the Enter key or Delete on the keyboard is pressed.
 */
typedef enum
{
    MobileRTCRemoteControl_Del,
    MobileRTCRemoteControl_Return
} MobileRTCRemoteControlInputType;

/*!
 @brief It provides Remote Control Service.
 1.Be assigned be a remote control(Notify by "remoteControlPrivilegeChanged:" check with "isHaveRemoteControlRight").
 2.Need to grab the currently control(Call "grabRemoteControl:", check with "isRemoteController").
 3.Can do the remote action.
 */
@interface MobileRTCRemoteControlService : NSObject

/*!
 @brief Callback event of receiving remote control. 
 */
@property (weak, nonatomic) id<MobileRTCRemoteControlDelegate> _Nullable delegate;

/*!
 @brief Query if current user have control privilege. You can have this  after be assigned to have  remote control privilege.
 @param remoteShareView The remote shared view.
 @return YES means that the user got  remote control privilege. Otherwise not.
 @warning In ZoomUI Mode, If remoteShareView is nil ,That means the currently active Zoom Subscribe Share View.
 */
- (BOOL)isHaveRemoteControlRight:(MobileRTCActiveShareView * _Nonnull)remoteShareView;

/*!
 @brief Query if the current user gets  remote control privilege.
 @param remoteShareView The remote shared view.
 @return YES means that the user got  remote control privilege. Otherwise not.
 @warning In ZoomUI Mode, If remoteShareView is nil ,That means the currently active Zoom Subscribe Share View.
 */
- (BOOL)isRemoteController:(MobileRTCActiveShareView * _Nonnull)remoteShareView;

/*!
 @brief Set to enable remote control. User should tap the screen icon once received the privilege to control one's screen remotely.  
 @param remoteShareView The remote shared view.
 @return The result of grabbing the remote control.
 */
- (MobileRTCRemoteControlError)grabRemoteControlView:(MobileRTCActiveShareView * _Nonnull)remoteShareView;

/*!
 @brief Simulate a mouse click with a finger clicking once on the screen.
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlSingleTap:(CGPoint)point;

/*!
 @brief Simulate a mouse double-click with a finger clicking twice successively on the screen.
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlDoubleTap:(CGPoint)point;

/*!
 @brief Simulate a mouse right-click with a finger pressing phone screen for more than 3 seconds. 
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlLongPress:(CGPoint)point;

/*!
 @brief Simulate a mouse scroll with two fingers scrolling up and down.
 @param point It is recommended to pass the arguments: CGPointMake(0, -1) for scrolling up, It is recommended to pass the arguments: CGPointMake(0, 1) for scrolling down.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlDoubleScroll:(CGPoint)point;

/*!
 @brief Move remote cursor by dragging mouse icon on phone screen.
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlSingleMove:(CGPoint)point;

/*!
 @brief Simulate a mouse right-click with a finger pressing phone screen for more than 3 seconds.
 This method is used to simulate a mouse left-click, such as long press on mouse icon.
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlMouseLeftDown:(CGPoint)point;

/*!
 @brief Simulate release the left mouse button.
 @param point The point where user clicks corresponds to the location of the content.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlMouseLeftUp:(CGPoint)point;

/*!
 @brief Simulate a mouse left-click and drag. User clicks the mouse icon on the screen for 3s and drag it. 
 @param point The trajectory of the simulated mouse.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlMouseLeftDrag:(CGPoint)point;

/*!
 @brief Simulate a keyboard to input text.
 @param str Input text from keyboard.
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlCharInput:(NSString * _Nonnull)str;

/*!
 @brief Simulate Enter key or delete key of the keyboard.
 @param key A value of the enumeration of MobileRTCRemoteControlInputType. 
 @return The result of the operation.
 */
- (MobileRTCRemoteControlError)remoteControlKeyInput:(MobileRTCRemoteControlInputType)key;
@end

/*!
 @brief Callback event of receiving remote control. 
 */
@protocol MobileRTCRemoteControlDelegate <NSObject>

@optional
/*!
 @brief Callback event of the following values when the privilege of remote control changes.
 @param isMyControl YES means that the current user got the remote control privilege. Otherwise not. 
 */
- (void)remoteControlPrivilegeChanged:(BOOL)isMyControl DEPRECATED_MSG_ATTRIBUTE("Use onRemoteControlPrivilegeChanged instead");
/*!
 @brief Callback event of these values when the privilege of  changes.
 @param isMyControl YES means that the current user got the remote control privilege. Otherwise not.
 */
- (void)onRemoteControlPrivilegeChanged:(BOOL)isMyControl;

/*!
 @brief Callback event of the following values when remote control starts.
 @param resultValue A value of MobileRTCRemoteControlError enumeration.
 */
- (void)startRemoteControlCallBack:(MobileRTCRemoteControlError)resultValue DEPRECATED_MSG_ATTRIBUTE("Use onEnterOrLeaveRemoteControllingStatus instead");

/*!
 @brief Callback event of these values when remote control starts.
 @param isEnter YES means that grab Remote Control View success . Otherwise not.
 */
- (void)onEnterOrLeaveRemoteControllingStatus:(BOOL)isEnter;

@end

