//  SMARAdSessionManager.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"
#import "SMARAdSession.h"
#import "SMARAdSessionObserverProtocol.h"

@interface SMARAdSessionManager : NSObject <SMARAdSessionObserverProtocol>

+ (instancetype)sharedInstance;

- (SMARAdSession *)newSessionForAd:(SMARAd *)ad withObserver:(id<SMARAdObserver>)observer;
- (SMARAdSession *)retrieveFor:(SMARAd *)ad;
- (void)prepareSession:(SMARAdSession *)session;
- (void)startSession:(SMARAdSession *)session
    withViewController:(UIViewController *)viewController;

@end
