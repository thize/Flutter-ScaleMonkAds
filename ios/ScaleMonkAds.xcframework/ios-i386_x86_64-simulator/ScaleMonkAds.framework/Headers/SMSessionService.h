//  SMSessionService.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

@protocol SMSessionService <NSObject>

@required

- (NSString *)getFirstInstallId;
- (NSString *)getActivationDate;
- (BOOL)isFreshInstall;
- (BOOL)isFirstSession;
- (NSInteger)getSessionCount;
- (NSInteger)getDaysActive;
- (NSString *)getUserType;
- (NSString *)getCustomUserId;
- (NSDictionary *)getExtraInfo;
- (NSInteger)getShownAdsForType:(NSString*) type;
- (void)shownAdForType:(NSString*) type;

@end
