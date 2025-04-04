//
//  MobileRTCMeetingService+BO.h
//  MobileRTC
//
//  Created by Zoom Communications on 2020/2/11.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//


#import <MobileRTC/MobileRTC.h>
#import <MobileRTC/MobileRTCBORole.h>

/*!
 @brief Creates Breakout Room meetings-related objects and fetches Breakout Room-related status information.
 */
@interface MobileRTCMeetingService (BO)

/*!
@brief Object for creating Breakout Room meetings defined in  [MobileRTCBOCreator].
*/
- (MobileRTCBOCreator * _Nullable)getCreatorHelper;

/*!
@brief Object for administrator management of Breakout Room meetings defined in [MobileRTCBOAdmin].
*/
- (MobileRTCBOAdmin * _Nullable)getAdminHelper;

/*!
@brief Object for help assistant of Breakout Room meetings defined in [MobileRTCBOAssistant].
*/
- (MobileRTCBOAssistant * _Nullable)getAssistantHelper;

/*!
@brief Object for attendee functionality of Breakout Room meetings defined in [MobileRTCBOAttendee].
*/
- (MobileRTCBOAttendee * _Nullable)getAttedeeHelper;

/*!
@brief Object for Breakout Room meeting id information defined in [MobileRTCBOData].
*/
- (MobileRTCBOData * _Nullable)getDataHelper;

/*!
@brief Has Breakout Room meeting began.
*/
- (BOOL)isBOMeetingStarted;

/*!
@brief Is Breakout Room feature enabled in meeting.
*/
- (BOOL)isBOMeetingEnabled;

/*!
@brief Is currently in Breakout Room during meeting.
*/
- (BOOL)isInBOMeeting;

/*!
 @brief Query if the host is broadcasting voice to BO.
 @return true means that the host is broadcasting, otherwise it's not broadcasting.
 */
- (BOOL)isBroadcastingVoiceToBO;

/*!
@brief Get current Breakout status.
@return Enum for Breakout status. [MobileRTCBOStatus]
*/
- (MobileRTCBOStatus)getBOStatus;

/*!
 @brief Get the name of the BO you are going to.
 @return The value is join bo name which you are going to.
 @note When you enter a BO or are switched to another BO by the host, maybe you need the BO name to display on transfer UI.
 */
- (NSString * _Nullable)getJoiningBOName;

@end


