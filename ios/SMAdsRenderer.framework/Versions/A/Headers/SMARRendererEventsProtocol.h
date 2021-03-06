//  SMARRendererEventsProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"

@protocol SMARRendererEventsProtocol

- (void)adImpressed:(SMARAd *)ad;
- (void)adClicked:(SMARAd *)ad;
- (void)adStarted:(SMARAd *)ad;
- (void)adEnded:(SMARAd *)ad;
- (void)adClosed:(SMARAd *)ad;

@end
