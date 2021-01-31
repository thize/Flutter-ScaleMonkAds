//  SMVideoProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMWaterfallEntry.h"

@protocol SMVideoProtocol <NSObject>
/**
 Checks if there is an available video ad for an attributed provider.

 @param attrProvider The attributed provider.

 @return Whether there is a video ad is available for the attributed provider.
 */
- (bool)isVideoAvailableForAttrProvider:(SMWaterfallEntry*)attrProvider;

/**
 Triggers a provider SDK video cache.

 @param attrProvider The attributed provider.
 */
- (void)loadVideoForAttrProvider:(SMWaterfallEntry*)attrProvider;

/**
 Triggers a provider SDK video display.

 @param attrProvider The attributed provider.
 @param viewController The view controller that implements the delegates for that provider.
 @param tag The game tag where the ad will be displayed (like menu or shop).
 */
- (bool)showVideoForAttrProvider:(SMWaterfallEntry*)attrProvider
               onTopOfController:(UIViewController*)viewController
             atAnalyticsTag:(NSString*)tag;

/**
 Returns information about auto cache for video ads.

 @return Whether the provider makes auto cache or not.
 */
- (bool)hasVideoAutoCache;

@optional

// TODO (vitor.araujo): It this method being used anywhere?
/**
 Triggers an action when the app is being terminated.
 */
- (void)willTerminate;

@end
