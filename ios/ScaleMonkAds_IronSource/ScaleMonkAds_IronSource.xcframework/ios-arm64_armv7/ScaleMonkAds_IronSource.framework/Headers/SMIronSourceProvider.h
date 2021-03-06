//  SMIronSourceProvider.h
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
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerViewProtocol.h"
#endif

@class SMProviderCallbacks;

@interface SMIronSourceProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol>

@property (weak) SMProviderCallbacks* callbacks;

@property (nonatomic, copy) NSString* appKey;
@property (nonatomic, copy) NSString* segmentId;

@property (nonatomic, copy) NSString* bannerPlacementId;

@end
