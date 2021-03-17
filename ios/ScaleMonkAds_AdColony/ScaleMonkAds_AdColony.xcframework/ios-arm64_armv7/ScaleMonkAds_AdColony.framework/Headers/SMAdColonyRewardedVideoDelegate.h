//  SMAdColonyRewardedVideoDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMAdColonyInterstitialDelegate.h"
#import "SMProviderProtocol.h"
#import "SMVideoProtocol.h"
#endif

@interface SMAdColonyRewardedVideoDelegate : SMAdColonyInterstitialDelegate

- (void) finishedWithReward;
- (void) finishedWithNoReward;

+ (SMAdColonyRewardedVideoDelegate *) delegateFor:(SMWaterfallEntry *)attr withAdsInstance:(SMProviderCallbacks *)ad;

@end
