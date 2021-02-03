//  SMISDemandOnlyRewardedVideoDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import "IronSource/IronSource.h"
#import "SMIronSourceProvider.h"


@interface SMISDemandOnlyRewardedVideoDelegate : NSObject<ISDemandOnlyRewardedVideoDelegate>

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
