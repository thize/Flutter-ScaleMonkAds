//  SMMopubProvider.h
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
#import "SMVideoProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#endif

#define kRegularBanners           @"regular_banners"
#define kRegularInterstitials     @"regular_interstitials"
#define kRegularVideos            @"regular_videos"

@class SMProviderCallbacks;

@interface SMMopubProvider : NSObject <
        SMProviderProtocol,
        SMInterstitialProtocol,
        SMBannerProtocol,
        SMVideoProtocol
        >

@property(weak) SMProviderCallbacks *callbacks;

@property(nonatomic) bool videoWatched;
@property(nonatomic) NSString *lastLocation;
@property(nonatomic) UIViewController *controllerToUse;
@property(nonatomic) NSMutableDictionary<NSString *, NSString *> *bannerAnalyticsLocations;

@property(nonatomic) NSMutableDictionary<NSString *, SMWaterfallEntry *> *bannerAttrProvider;
@property(nonatomic) NSMutableDictionary<NSString *, SMWaterfallEntry *> *videoAttrProvider;
@property(nonatomic) NSMutableDictionary<NSString *, SMWaterfallEntry *> *interstitialAttrProvider;

- (SMWaterfallEntry *)getAttrProviderForAdType:(AdTypeEnum)adType andPlacement:(NSString *)placement;

- (SMWaterfallEntry *)getVideoAttrProviderForPlacement:(NSString *)placement;

@end
