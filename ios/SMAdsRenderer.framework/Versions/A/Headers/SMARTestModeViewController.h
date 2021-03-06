//  SMARTestModeViewController.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SMARAdLifecycleObserverProtocol.h"

@interface SMARTestModeViewController : UIViewController

@property(nonatomic, strong) id<SMARAdLifecycleObserverProtocol> eventsObserver;

- (void)setObserver:(id<SMARAdLifecycleObserverProtocol>)observer;

- (IBAction)clickStarted:(id)sender;

- (IBAction)clickImpressed:(id)sender;

- (IBAction)clickClicked:(id)sender;

- (IBAction)clickEnded:(id)sender;

- (IBAction)clickClosed:(id)sender;

- (IBAction)clickLoaded:(id)sender;

- (IBAction)clickClose:(id)sender;

@end
