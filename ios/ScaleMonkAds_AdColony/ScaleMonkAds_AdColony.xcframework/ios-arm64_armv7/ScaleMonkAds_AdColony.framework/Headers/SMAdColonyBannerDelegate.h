//  SMAdColonyBannerDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMBannerProtocol.h"
#import "SMProviderCallbacks.h"
#endif

@interface SMAdColonyBannerDelegate : NSObject

@property (weak) SMProviderCallbacks* adsInstance;
@property (nonatomic, strong) NSString* location;
@property (nonatomic, strong) SMWaterfallEntry* attrProvider;

+ (SMAdColonyBannerDelegate*) delegateFor:(SMWaterfallEntry*)attr withAdsInstance:(SMProviderCallbacks *)ads;

- (void)close;
- (bool)isActive;
- (void)showOnView:(SMBannerView*)view atAnalyticsTag:(NSString*)location;

@end

