//  SMARRendererFactory.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"
#import "SMARRenderer.h"

@interface SMARRendererFactory : NSObject

+ (SMARRenderer *)getRendererForAd:(SMARAd *)ad
                 withEventsObserver:(id<SMARAdLifecycleObserverProtocol>)observer;

@end
