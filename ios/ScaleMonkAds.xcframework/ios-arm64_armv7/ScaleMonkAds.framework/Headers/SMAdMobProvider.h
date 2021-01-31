//  SMAdMobProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#import "SMVideoProtocol.h"

@class SMProviderCallbacks;

@interface SMAdMobProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol>

@property (weak) SMProviderCallbacks* adsInstance;
+ (SMAdMobProvider*) admobDefault;

@end
