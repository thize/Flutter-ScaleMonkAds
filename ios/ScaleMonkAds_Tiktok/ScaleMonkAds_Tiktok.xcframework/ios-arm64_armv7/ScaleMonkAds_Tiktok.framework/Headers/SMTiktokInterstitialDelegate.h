//  SMTiktokInterstitialDelegate.h
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
#endif

@interface SMTiktokInterstitialDelegate : NSObject

@property (weak) SMProviderCallbacks* callbacks;
@property (nonatomic, strong) NSString* location;
@property (nonatomic, strong) SMWaterfallEntry* attrProvider;

+ (SMTiktokInterstitialDelegate*)delegateFor:(SMWaterfallEntry*)attr withAdsInstance:(SMProviderCallbacks*)ads;

- (bool)isAdAvailable;
- (void)cacheAd;
- (bool)showInterstitialOnTopOfController:(UIViewController*)viewController atAnalyticsTag:(NSString*)location;

@end
