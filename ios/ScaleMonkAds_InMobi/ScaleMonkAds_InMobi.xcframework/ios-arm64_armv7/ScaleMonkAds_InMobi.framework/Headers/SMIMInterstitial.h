//  SMIMInterstitial.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <InMobiSDK/InMobiSDK.h>


@interface SMIMInterstitial : IMInterstitial

@property(nonatomic, strong) NSString *placement;

- (bool)hasBid;

- (instancetype)initWithPlacement:(NSString *)placementId delegate:(id <IMInterstitialDelegate>)delegate;

@end
