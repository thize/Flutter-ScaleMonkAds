//  SMAdMobProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "SMProviderCallbacks.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMVideoProtocol.h"
#endif



@class SMProviderCallbacks;

@interface SMAdMobProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol>

@property (weak) SMProviderCallbacks* adsInstance;

@end
