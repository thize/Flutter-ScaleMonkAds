//  SMISDemandOnlyRewardedVideoDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMIronSourceProvider.h"


@interface SMISDemandOnlyRewardedVideoDelegate : NSObject

- (instancetype)initWithProvider:(SMIronSourceProvider*)provider andAdsInstance:(SMProviderCallbacks*)callbacks;

- (void)rewardedVideoDidLoad:(NSString *)instanceId;
- (void)rewardedVideoDidFailToLoadWithError:(NSError *)error instanceId:(NSString *)instanceId;
- (void)rewardedVideoDidOpen:(NSString *)instanceId;
- (void)rewardedVideoDidClose:(NSString *)instanceId;
- (void)rewardedVideoDidFailToShowWithError:(NSError *)error instanceId:(NSString *)instanceId;
- (void)rewardedVideoDidClick:(NSString *)instanceId;
- (void)rewardedVideoAdRewarded:(NSString *)instanceId;

@property (nonatomic, weak) SMProviderCallbacks* callbacks;

@property (nonatomic, strong) SMIronSourceProvider *provider;
@property (nonatomic, strong) NSString *lastLocationShown;
@property (nonatomic, strong) NSMutableDictionary<NSString*, SMWaterfallEntry*> *videoAttrProvider;

@end
