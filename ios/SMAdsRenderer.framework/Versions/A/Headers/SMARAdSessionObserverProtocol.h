//  SMARAdSessionObserverProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


@class SMARAdSession;

@protocol SMARAdSessionObserverProtocol

- (void)sessionStarted:(SMARAdSession *)session;
- (void)sessionFinished:(SMARAdSession *)session;

@end
