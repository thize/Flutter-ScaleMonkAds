//  SMBannerAdEventListener.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>

@protocol SMBannerAdEventListener <NSObject>
@optional
- (void)onBannerFail:(NSString *)tag;
- (void)onBannerCompleted:(NSString *)tag;
@end
