//  SMARRendererActionsProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAd.h"

@protocol SMARRendererActionsProtocol

- (void)prepare;
- (void)renderWithViewController:(UIViewController *)viewController;

@end
