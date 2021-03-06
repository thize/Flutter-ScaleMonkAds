//  SMISDemandOnlyInterstitialDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMIronSourceProvider.h"


@interface SMISDemandOnlyInterstitialDelegate : NSObject

- (instancetype)initWithProvider:(SMIronSourceProvider*)provider andAdsInstance:(SMProviderCallbacks*)callbacks;

@property (nonatomic, weak) SMProviderCallbacks* callbacks;

@property (nonatomic, strong) SMIronSourceProvider *provider;
@property (nonatomic, strong) NSString *lastLocationShown;
@property (nonatomic, strong) NSMutableDictionary<NSString*, SMWaterfallEntry*> *interstitialAttrProvider;

- (void)interstitialDidLoad:(NSString *)instanceId;
- (void)interstitialDidFailToLoadWithError:(NSError *)error instanceId:(NSString *)instanceId;
- (void)interstitialDidOpen:(NSString *)instanceId;
- (void)interstitialDidClose:(NSString *)instanceId;
- (void)interstitialDidFailToShowWithError:(NSError *)error instanceId:(NSString *)instanceId;
- (void)didClickInterstitial:(NSString *)instanceId;

@end
