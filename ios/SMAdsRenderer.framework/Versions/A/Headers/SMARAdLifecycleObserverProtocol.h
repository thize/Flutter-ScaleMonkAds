//  SMARAdLifecycleObserverProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//
@class SKStoreProductViewController;

@protocol SMARAdLifecycleObserverProtocol

- (void)adLoaded;
- (void)adImpressed;
- (void)adClicked;
- (void)adStarted;
- (void)adEnded;
- (void)adClosed;
- (void)adLoadFailed:(NSError *)error;
- (void)adRenderFailed:(NSError *)error;
- (void)linkClickedWithAppId: (NSString*) appId withStoreViewCtrl:(SKStoreProductViewController *) storeViewCtrl withUiViewCtrl: (UIViewController *) uiViewCtrl;
@end
