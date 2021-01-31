//  SMInterstitialProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMWaterfallEntry.h"

@protocol SMInterstitialProtocol <NSObject>

/**
 Checks if there is an available interstitial ad for an attributed provider.

 @param attrProvider The attributed provider.

 @return Whether there is an interstitial ad is available for the attributed provider.
 */
- (bool) isInterstitialAvailableForAttrProvider:(SMWaterfallEntry*)attrProvider;

/**
 Triggers a provider SDK interstitial cache.

 @param attrProvider The attributed provider.
 */
- (void) cacheInterstitialForAttrProvider:(SMWaterfallEntry*)attrProvider;

/**
 Triggers a provider SDK interstitial display.

 Some adnets might return an error while starting a display of a previously cached ad. For this reason,
 we return a boolean informing whether the sdk managed to start the cached ad display.

 @param attrProvider The attributed provider.
 @param tag The game tag where the ad will be displayed (like menu or shop).

 @return Whether the sdk managed to start the cached ad display.
 */
- (bool) showInterstitialForAttrProvider:(SMWaterfallEntry*)attrProvider
                     atAnalyticsTag:(NSString*)tag;

/**
 Returns information about auto cache for interstitial ads.

 @return Whether the provider makes auto cache or not.
 */
- (bool) hasInterstitialAutoCache;

@optional

/**
 Triggers a provider SDK interstitial display using a view controller.

 @param attrProvider The attributed provider.
 @param viewController The view controller that implements the delegates for that provider.
 @param tag The game tag where the ad will be displayed (like menu or shop).
 */
- (bool) showInterstitialForAttrProvider:(SMWaterfallEntry*)attrProvider
                       onTopOfController:(UIViewController*)viewController
                     atAnalyticsTag:(NSString*)tag;

@end
