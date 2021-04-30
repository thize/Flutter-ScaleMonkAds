//  SMAppLovinInterstitialDelegate.h
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
#import "SMInterstitialProtocol.h"
#import "SMApplovinAdloadDelegate.h"
#endif

@class SMProviderCallbacks;

@interface SMAppLovinInterstitialDelegate : NSObject<SMInterstitialProtocol, SMApplovinAddloadProtocol>

@property (nonatomic, weak) SMProviderCallbacks* callbacks;

- (instancetype)initWithSdk:(ALSdk *)sdk
               andCallbacks:(SMProviderCallbacks*)callbacks;

- (void)updateConfigsWithSdk:(ALSdk *)appLovinSdk;

@end
