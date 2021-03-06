//  SMAmazonProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "AuctionProviderProtocol.h"
#import "SMSkAdNetworkProtocol.h"
#import <DTBiOSSDK/DTBiOSSDK.h>
#import "SMAdsRTBLoggerProtocol.h"
#endif

@class SMAds;

@interface SMAmazonProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, AuctionProviderProtocol, SMSkAdNetworkProtocol>

@property(weak) SMProviderCallbacks *adsInstance;
@property(nonatomic, copy) NSString *appId;

@end
