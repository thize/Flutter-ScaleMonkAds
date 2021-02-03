//  SMRewardedVideoAdEventListener.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>

@protocol SMRewardedVideoAdEventListener <NSObject>
@optional

- (void)onRewardedClick:(NSString *)tag;
- (void)onRewardedViewStart:(NSString *)tag;
- (void)onRewardedFinishWithNoReward:(NSString *)tag;
- (void)onRewardedFinishWithReward:(NSString *)tag;
- (void)onRewardedFail:(NSString *)tag;
- (void)onRewardedReady;
- (void)onRewardedNotReady;

@end
