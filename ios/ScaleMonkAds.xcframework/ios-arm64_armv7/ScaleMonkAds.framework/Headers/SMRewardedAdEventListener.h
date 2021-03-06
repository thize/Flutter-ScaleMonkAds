//  SMRewardedAdEventListener.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

@protocol SMRewardedAdEventListener <NSObject>
@optional

- (void)onRewardedClick:(NSString *)tag;

- (void)onRewardedViewStart:(NSString *)tag;

- (void)onRewardedFinishWithNoReward:(NSString *)tag;

- (void)onRewardedFinishWithReward:(NSString *)tag;

- (void)onRewardedFail:(NSString *)tag;

- (void)onRewardedReady;

- (void)onRewardedNotReady;

@end
