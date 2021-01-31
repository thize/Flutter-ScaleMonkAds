//  SMProviderCallbacks.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMProvidersSetup.h"
#import "SMAnalyticsListener.h"
#import "SMBannerView.h"
#import "SMWaterfallEntry.h"

@interface SMProviderCallbacks : NSObject

#pragma mark Providers callbacks

/**
 This method is called by the providers to inform the SDK that a cache request has succeeded.

 @param attr The attributed provider instance.

 @warning You should not use this method.
 */
- (void)didCacheSuccessWithAttrProvider:(SMWaterfallEntry* _Nullable)attr;

/**
 This method is called by the providers to inform the SDK that a cache request has failed.

 @param attr The attributed provider instance.

 @warning You should not use this method.
 */
- (void)didCacheFailWithAttrProvider:(SMWaterfallEntry* _Nullable)attr;

/**
 This method is called by the providers to inform the SDK that the ad has started being displayed on
 screen.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad is being displayed (like menu or store).

 @warning You should not use this method.
 */
- (void)didViewStartWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                          withTag:(NSString* _Nullable)tag;

/**
 This method is called by the providers to inform the SDK that the ad was not displayed due to an
 error in the provider SDK.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad failed to display (like menu or store).

 @warning You should not use this method.
 */
- (void)didViewErrorWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                             withTag:(NSString* _Nullable)tag
                    errorDescription:(NSString* _Nullable)error;

/**
 This method is called by the providers to inform the SDK that the ad being displayed was clicked by the
 user.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad was clicked (like menu or store).

 @warning You should not use this method.
 */
- (void)didViewClickWithAttrProvider:(SMWaterfallEntry* _Nullable )attr
                          withTag:(NSString* _Nullable)tag;

/**
 This method is called by the providers to inform the SDK that the user can receive the reward for
 watching the ad.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad was clicked (like menu or store).

 @warning You should not use this method.
 */
- (void)didViewRewardWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                           withTag:(NSString* _Nullable)tag;

/**
 This method is called by the providers to inform the SDK that the user cannot receive the reward for
 watching the ad.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad was clicked (like menu or store).

 @warning You should not use this method.
 */
- (void)didViewNoRewardWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                             withTag:(NSString* _Nullable)tag;

/**
 This method is called by the providers to inform the SDK that the ad being displayed was closed by the
 user.

 If the display was successful, the video delegate method `completedVideoDisplayAtTag:` is called.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad was clicked (like menu or store).
 @param completed Whether the display was successful or not.

 @warning You should not use this method.

 @see SMVideoDelegate protocol.
 */
- (void)didViewCloseWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                          withTag:(NSString* _Nullable)tag
                    completedDisplay:(bool)completed;

/**
 This method is called by the providers to inform the SDK that the banner ad being displayed has
 generated an impression.

 @param attr The attributed provider instance.
 @param tag The game tag where the ad was clicked (like menu or store).

 @warning You should not use this method.
 */
- (void)didCompleteBannerViewWithAttrProvider:(SMWaterfallEntry* _Nullable)attr
                                   withTag:(NSString* _Nullable)tag;

@end
