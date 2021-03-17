//  SMAdColonyInterstitialDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMInterstitialProtocol.h"
#import "SMProviderCallbacks.h"
#endif

@interface SMAdColonyInterstitialDelegate : NSObject

@property (nonatomic, strong) NSString* location;
@property (nonatomic, strong) SMWaterfallEntry* attrProvider;

@property (weak) SMProviderCallbacks* callbacks;

+ (SMAdColonyInterstitialDelegate*) delegateFor:(SMWaterfallEntry *)attr withAdsInstance:(SMProviderCallbacks*)ads;

- (bool)isAdAvailable;
- (void)cacheAd:(NSDictionary<NSString *,NSString *> *)options;
- (bool)showOnTopOfController:(UIViewController*)viewController atAnalyticsTag:(NSString*)location;

@end
