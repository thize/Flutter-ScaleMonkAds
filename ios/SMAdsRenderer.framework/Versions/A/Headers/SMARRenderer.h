//  SMARRenderer.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <UIKit/UIViewController.h>

#import "SMARAd.h"
#import "SMARAdLifecycleObserverProtocol.h"
#import "SMARRendererActionsProtocol.h"

@interface SMARRenderer : NSObject <SMARRendererActionsProtocol>

@property(nonatomic, strong, readonly) SMARAd *ad;
@property(nonatomic, strong, readonly) UIViewController *viewController;
@property(nonatomic, strong) id<SMARAdLifecycleObserverProtocol> eventsObserver;

- (instancetype)initWithAd:(SMARAd *)ad observer:(id<SMARAdLifecycleObserverProtocol>)observer;

@end
