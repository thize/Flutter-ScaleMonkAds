//  SMAppLovinProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import <AppLovinSDK/AppLovinSDK.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "SMBannerProtocol.h"
#endif

@class SMProviderCallbacks;
@class ALSdk;

@interface SMAppLovinProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, SMBannerProtocol>

@property (nonatomic, copy) NSString* key;
@property (nonatomic, copy) NSString* bannerZoneId;
@property (nonatomic, weak) SMProviderCallbacks* callbacks;

@end
