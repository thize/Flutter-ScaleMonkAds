//  SMTiktokRewardedVideoDelegate.h
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
#endif

@interface SMTiktokRewardedVideoDelegate : NSObject

@property (weak) SMProviderCallbacks* callbacks;
@property (nonatomic, strong) NSString* location;
@property (nonatomic, strong) SMWaterfallEntry* attrProvider;

+ (SMTiktokRewardedVideoDelegate*)delegateFor:(SMWaterfallEntry*)attr withAdsInstance:(SMProviderCallbacks*)ads;

- (bool)isAdAvailable;
- (void)loadAd;
- (bool)showVideoOnTopOfController:(UIViewController*)viewController atAnalyticsTag:(NSString*)location;

@end
