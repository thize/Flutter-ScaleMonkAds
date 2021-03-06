//  SMChartboostProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import <UIKit/UIKit.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "AuctionProviderProtocol.h"
#endif

#if __has_include("ObjectiveSugar.h")
#error "SMAds - Incompatible Pods in use!! I regret to inform you that you can't have Chartboost and ObjectiveSugar in the same project. \
Both have categories that add the same methods to NSArray and NSDictionary, what leads to undefined behaviour."
#endif

@interface SMChartboostProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, AuctionProviderProtocol>

@property (nonatomic, copy) NSString* appId;
@property (nonatomic, copy) NSString* signature;

@property (weak) SMProviderCallbacks* adsInstance;

@end

