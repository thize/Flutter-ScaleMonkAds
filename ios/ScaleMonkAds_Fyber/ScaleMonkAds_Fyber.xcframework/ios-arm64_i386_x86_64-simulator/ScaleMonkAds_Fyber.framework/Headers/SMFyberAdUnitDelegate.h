//  SMFyberAdUnitDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMAds.h"
#import "SMProviderProtocol.h"
#endif

@class SMProviderCallbacks;

@interface SMFyberAdUnitDelegate : NSObject

@property(weak) SMProviderCallbacks *adsInstance;
@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic) NSString *analyticsLocation;
@property(nonatomic) BOOL ready;
@property(nonatomic) BOOL isLoading;
@property(nonatomic) SMWaterfallEntry *attrProvider;

- (void)clearState;

- (void)requestAd;

- (void)requestAndShowAdThroughView:(UIView *)view atLocation:(NSString *)location;

- (void)showAdsAtLocation:(NSString *)analyticsLocation withView:(UIView *)viewController;

- (instancetype)initWithAdsInstance:(SMProviderCallbacks *)adsInstance withAttrProvider:(SMWaterfallEntry *)attrProvider;

@end
