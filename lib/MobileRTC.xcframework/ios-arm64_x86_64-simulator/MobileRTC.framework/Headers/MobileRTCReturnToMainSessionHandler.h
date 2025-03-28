//
//  MobileRTCReturnToMainSessionHandler.h
//  MobileRTC
//
//  Created by Zoom Communications on 2021/5/31.
//  Copyright © Zoom Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MobileRTCReturnToMainSessionHandler : NSObject

/*!
@brief go back to main session for the main session invitation.
@return whether return succeed or not.
*/
- (BOOL)returnToMainSession;

/*!
@brief ingore the main session invitation.
*/
- (void)ignore;

@end

NS_ASSUME_NONNULL_END
