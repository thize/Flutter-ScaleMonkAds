//  SMAdsSDKRenderer.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import "SMAdsRendererProtocol.h"

@interface SMAdsSDKRenderer : NSObject <SMAdsRenderer>

/**
 The SM Ads Renderer instance previously initialized.

 @return The shared SMAdsRenderer instance.
*/
+ (SMAdsSDKRenderer *)sharedInstance;

@end
