//  SMARAdObserver.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"
#import <StoreKit/StoreKit.h>

@protocol SMARAdObserver

@optional

/**
 Called when the ad is ready to be rendered.

 You can assume that all assets were loaded and the renderer is ready to start a
 session.

 @param ad The ad instance that is ready.
*/
- (void)adLoaded:(SMARAd *)ad;

/**
 Called when the ad is about to start, right after the ad view enters the screen.

 @param ad The ad instance that is being displayed.
*/
- (void)adStarted:(SMARAd *)ad;

/**
 Called when the ad has been fully displayed, meaning that a complete view
 happened.

 @param ad The ad instance that had finished.
*/
- (void)adEnded:(SMARAd *)ad;

/**
 Called when the ad is clicked.

 It may or may not send the user to another screen.

 @param ad The ad instance that was clicked.
*/
- (void)adClicked:(SMARAd *)ad;


/**
 Called when an itunes link is clicked.

 It may or may not send the user to another screen.

 @param ad The ad instance that was clicked.
 @param appId the id of the app in the store.
 */
- (void)linkClicked:(SMARAd *)ad appId: (NSString*)appId storeViewCtrl:(SKStoreProductViewController *) storeViewCtrl  uiViewCtrl: (UIViewController *) uiViewCtrl;

/**
 Called when the ad view leaves the screen, meaning that the ad was closed.

 May be triggered automatically or by an user input.

 @param ad The ad instance that was closed.
 @param fullyViewed Flag that indicated if the ad was completed or not.
*/
- (void)adClosed:(SMARAd *)ad isFullyViewed:(bool)fullyViewed;

/**
 Called when the impression event is issued in the ad.

 There is no standard that defines a clear moment when a impression must be
 issued and that depends on the renderer used.

 @param ad The ad instance that was impressed.
*/
- (void)adImpressed:(SMARAd *)ad;

/**
 Called when there is an error during the preparation of the ad.

 @param ad The ad instance which triggered the error.
 @param error The error instance.
*/
- (void)adLoadFailed:(SMARAd *)ad withError:(NSError *)error;

/**
 Called when there is an error during the rendering of the ad.

 @param ad The ad instance which triggered the error.
 @param error The error instance.
*/
- (void)adRenderFailed:(SMARAd *)ad withError:(NSError *)error;

@end
