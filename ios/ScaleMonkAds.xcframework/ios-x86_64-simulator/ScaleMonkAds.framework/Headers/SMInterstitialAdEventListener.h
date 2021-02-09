//  SMInterstitialAdEventListener.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>

@protocol SMInterstitialAdEventListener <NSObject>
@optional
- (void) onInterstitialClick:(NSString *)tag;
- (void) onInterstitialFail:(NSString *)tag;
- (void) onInterstitialView:(NSString *)tag;
- (void) onInterstitialViewStart:(NSString *)tag;
- (void) onInterstitialReady;
- (void) onInterstitialNotReady;

@end
