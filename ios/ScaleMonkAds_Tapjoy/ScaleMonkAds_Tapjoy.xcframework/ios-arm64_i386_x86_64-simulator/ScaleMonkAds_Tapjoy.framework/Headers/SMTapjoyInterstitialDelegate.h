//  SMTapjoyInterstitialDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMWaterfallEntry.h"
#import "SMProviderCallbacks.h"
#endif

@interface SMTapjoyInterstitialDelegate : NSObject

@property (nonatomic) NSString* analyticsTag;

- (void)requestInterstitial:(SMWaterfallEntry *)attrProvider;
- (instancetype)initWithAdsInstance:(SMProviderCallbacks*)callbacks;
- (bool)adReadyFor:(SMWaterfallEntry *)attrProvider;
- (bool)showAd:(SMWaterfallEntry *)attrProvider withController:(UIViewController*)viewController withTag:(NSString*)location;

@end
