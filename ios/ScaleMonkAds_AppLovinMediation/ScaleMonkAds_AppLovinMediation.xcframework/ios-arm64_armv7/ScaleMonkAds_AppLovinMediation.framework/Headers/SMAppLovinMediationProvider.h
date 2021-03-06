//  SMAppLovinMediationProvider.h
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
#endif

#define kRegularBanners       @"regular_banners"
#define kRegularInterstitials @"regular_interstitials"
#define kRegularVideos        @"regular_videos"

NS_ASSUME_NONNULL_BEGIN

@class SMProviderCallbacks;

@interface SMAppLovinMediationProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, SMBannerProtocol>
@property (nonatomic, copy) NSString* key;
@property (weak) SMProviderCallbacks* callbacks;

@end

NS_ASSUME_NONNULL_END
