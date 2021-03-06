//  SMAdsRendererProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <UIKit/UIViewController.h>
#import "SMARAd.h"
#import "SMARAdObserver.h"
#import "SMARAdType.h"
#import "SMARConfiguration.h"
#import "SMARInitializationDelegate.h"

@protocol SMAdsRenderer <NSObject>

/**
 Initializes the Ads Renderer, using a SMARConfiguration instance and
 initialization delegate, which receives the initialization success status.

 @param config The config instance which will configure the renderer instance.
 @param delegate The delegate that will observe the renderer setup. This
 instance is not mandatory, hence it can be nil.
*/
- (void)initWithConfig:(SMARConfiguration *)config
              delegate:(id<SMARInitializationDelegate>)delegate;

/**
 Instantiates and returns an ad which can be consumed by the renderer.

 @param payload The ad content that will be used by the renderer.
 @param contentType A string used to identify the ad format. @see
 SMARConstants.h.
 @param adType The ad type regarding its media (Eg: interstitial, rewarded,
 etc.).

 @return A SMARAd instance representing the issued ad.
*/
- (SMARAd *)newAdWithPayload:(NSString *)payload
                  contentType:(NSString *)contentType
                       adType:(SMARAdType)adType;

/**
 Trigger the loading of the ad's assets and prepare its rendering session in the
 corresponding renderer.

 As soon the ad is ready to be displayed, the class instance that is given as a
 parameter will be notified through the corresponding delegate method.

 This methods automatically defines which renderer should be used (MRAID, VAST,
 etc.) according to the ad's type.

 @param ad The ad instance that should be prepared.
 @param observer The delegate instance that will observe the ad lifecycle.
*/
- (void)prepare:(SMARAd *)ad withAdObserver:(id<SMARAdObserver>)observer;

/**
 Triggers the rendering flow of the given ads instance.

 This methods also needs to receive an UIViewController instance, which will be
 used as the rendering canvas.

 @param ad The ad instance that should be rendered.
 @param viewController The UIViewController that will be used to display the ad.
*/
- (void)render:(SMARAd *)ad withViewController:(UIViewController *)viewController;

/**
 Checks if the ad is ready.

 @param ad The ad instance that should be checked.
*/
- (bool)isAdReady:(SMARAd *)ad;

@end
