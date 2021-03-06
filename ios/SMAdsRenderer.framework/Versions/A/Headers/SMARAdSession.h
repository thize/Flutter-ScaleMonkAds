//  SMARAdSession.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"
#import "SMARAdLifecycleObserverProtocol.h"
#import "SMARAdObserver.h"
#import "SMARAdSessionObserverProtocol.h"
#import "SMARAdSessionState.h"
#import "SMARRenderer.h"

@interface SMARAdSession : NSObject <SMARAdLifecycleObserverProtocol>

@property(nonatomic, readonly) SMARAdSessionState state;
@property(nonatomic, strong, readonly) SMARAd* ad;
@property(nonatomic, strong, readonly) SMARRenderer* renderer;
@property(nonatomic, strong, readonly) id<SMARAdObserver> viewer;
@property(nonatomic, strong, readonly) id<SMARAdSessionObserverProtocol> manager;

- (instancetype)initForAd:(SMARAd*)ad
               withViewer:(id<SMARAdObserver>)viewer
              withManager:(id<SMARAdSessionObserverProtocol>)manager;
- (NSString*)getId;
- (void)prepare;
- (void)startWithViewController:(UIViewController*)viewController;
- (bool)needsFullscreen;

@end
