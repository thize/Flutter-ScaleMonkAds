//  SMAds.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMRewardedAdEventListener.h"
#import "SMInterstitialAdEventListener.h"
#import "SMBannerAdEventListener.h"
#import "SMBannerView.h"
#import "SMSessionService.h"
#import "SMWrapperAnalytics.h"
#import "SMAnalyticsListener.h"

@interface SMAds : NSObject

+ (SMAds *)sharedInstance;


- (instancetype)init;

- (instancetype)initWithCustomUserId: (NSString *)customUserId andAnalytics: (id<SMWrapperAnalytics>) analytics;

- (instancetype)initWithApplicationId:(NSString *)applicationId;

- (instancetype)initWithApplicationId:(NSString *)applicationId andCustomUserId: (NSString *)customUserId andAnalytics: (id<SMWrapperAnalytics>) analytics;

- (void)initialize:(void (^)(BOOL))done;

- (void)initialize;

- (void)addRewardedListener:(id<SMRewardedAdEventListener>)listener;

- (void)addInterstitialListener:(id<SMInterstitialAdEventListener>)listener;

- (void)addBannerListener:(id<SMBannerAdEventListener>)listener;

- (void)clearRewardedListeners;

- (void)clearInterstitialListeners;

- (void)clearBannerListeners;

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController
                                      andTag:(NSString *)tag
NS_SWIFT_NAME(showInterstitialAd(viewController:tag:));

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController
NS_SWIFT_NAME(showInterstitialAd(viewController:));

- (void)showRewardedAdWithViewController:(UIViewController *)viewController
                                  andTag:(NSString *)tag
NS_SWIFT_NAME(showRewardedAd(viewController:tag:));

- (void)showRewardedAdWithViewController:(UIViewController *)viewController
NS_SWIFT_NAME(showRewardedAd(viewController:));

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView
                                andTag:(NSString *)tag
NS_SWIFT_NAME(showBannerAd(viewController:bannerView:tag:));

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView
NS_SWIFT_NAME(showBannerAd(viewController:bannerView:));

- (void)stopLoadingBanners;

- (void)stopLoadingBannersWithTag:(NSString *)tag;

- (void)setIsApplicationChildDirected:(BOOL)childDirectedTreatment;

- (void)setHasGDPRConsentWithStatus:(BOOL)status
NS_SWIFT_NAME(setHasGDPRConsent(status:));

- (void)setUserCantGiveGDPRConsentWithStatus:(BOOL)status
NS_SWIFT_NAME(setUserCantGiveGDPRConsent(status:));

- (BOOL)isInterstitialReadyToShowWithTag:(NSString *)tag
NS_SWIFT_NAME(isInterstitialReadyToShow(tag:));

- (BOOL)isRewardedReadyToShowWithTag:(NSString *)tag
NS_SWIFT_NAME(isRewardedReadyToShow(tag:));

- (BOOL)areInterstitialsEnabled;

- (BOOL)areRewardedEnabled;

- (BOOL)areBannersEnabled;

- (void)enablePolicy:(NSString*) policyName withSessionService: (id<SMSessionService>) sessionService;

- (void)setExtraInfo:(NSDictionary*)extraInfo;
- (BOOL)isInterstitialReadyToShow
NS_SWIFT_NAME(isInterstitialReadyToShow());

- (BOOL)isRewardedReadyToShow
NS_SWIFT_NAME(isRewardedReadyToShow());

- (void)addAnalytics: (id<SMAnalyticsListener>) analytics;
NS_SWIFT_NAME(add(analytics:));

@end

