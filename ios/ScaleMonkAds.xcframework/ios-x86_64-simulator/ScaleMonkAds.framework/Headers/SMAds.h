//  SMAds.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import "SMRewardedVideoAdEventListener.h"
#import "SMInterstitialAdEventListener.h"
#import "SMBannerAdEventListener.h"
#import "SMBannerView.h"

@interface SMAds : NSObject

+ (SMAds*)sharedInstance;

- (instancetype)initWith:(NSString *)applicationId;

- (void)initialize:(void (^)(BOOL))done;

- (void)addVideoListener:(id<SMRewardedVideoAdEventListener>)listener;

- (void)addInterstitialListener:(id<SMInterstitialAdEventListener>)listener;

- (void)addBannerListener:(id<SMBannerAdEventListener>)listener;

- (void)clearVideoListeners;

- (void)clearInterstitialListeners;

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController
                                      andTag:(NSString *)tag
NS_SWIFT_NAME(showInterstitialAd(viewController:tag:));

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController
NS_SWIFT_NAME(showInterstitialAd(viewController:));

- (void)showRewardedVideoAdWithViewController:(UIViewController *)viewController
                                       andTag:(NSString *)tag
NS_SWIFT_NAME(showRewardedVideoAd(viewController:tag:));

- (void)showRewardedVideoAdWithViewController:(UIViewController *)viewController
NS_SWIFT_NAME(showRewardedVideoAd(viewController:));

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView
                                andTag:(NSString *)tag
NS_SWIFT_NAME(showBannerAd(viewController:bannerView:tag:));

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView
NS_SWIFT_NAME(showBannerAd(viewController:bannerView:));

- (void)stopLoadingBanners;

- (void)setIsApplicationChildDirected:(BOOL)childDirectedTreatment;

- (void)setHasGDPRConsentWithStatus:(BOOL)status
NS_SWIFT_NAME(setHasGDPRConsent(status:));

- (void)setUserCantGiveGDPRConsentWithStatus:(BOOL)status
NS_SWIFT_NAME(setUserCantGiveGDPRConsent(status:));

- (BOOL)isInterstitialReadyToShowWithTag:(NSString *)tag
NS_SWIFT_NAME(isInterstitialReadyToShow(tag:));

- (BOOL)isRewardedReadyToShowWithTag:(NSString *)tag
NS_SWIFT_NAME(isRewardedReadyToShow(tag:));

- (BOOL)isInterstitialReadyToShow
NS_SWIFT_NAME(isInterstitialReadyToShow());

- (BOOL)isRewardedReadyToShow
NS_SWIFT_NAME(isRewardedReadyToShow());

@end

