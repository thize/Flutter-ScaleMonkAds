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

- (void)addVideoListener:(id <SMRewardedVideoAdEventListener>)listener;

- (void)addInterstitialListener:(id <SMInterstitialAdEventListener>)listener;

- (void)addBannerListener:(id <SMBannerAdEventListener>)listener;

- (void)clearVideoListeners;

- (void)clearInterstitialListeners;

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController
                                 andTag:(NSString *)tag;

- (void)showInterstitialAdWithViewController:(UIViewController *)viewController;

- (void)showRewardedVideoAdWithViewController:(UIViewController *)viewController
                                  andTag:(NSString *)tag;

- (void)showRewardedVideoAdWithViewController:(UIViewController *)viewController;

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView
                           andTag:(NSString *)tag;

- (void)showBannerAdWithViewController:(UIViewController *)viewController
                            bannerView:(SMBannerView *)bannerView;

- (void)stopLoadingBanners;

- (void)setIsApplicationChildDirected: (BOOL)childDirectedTreatment;

-(void)setHasGDPRConsentWithStatus: (BOOL) status;

-(void)setUserCantGiveGDPRConsentWithIsUserUnderAgeOfConsent: (BOOL) status;

@end

