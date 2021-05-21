//  SMIMHeaderBiddingInterstitial.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <InMobiSDK/InMobiSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMIMHeaderBiddingInterstitial : NSObject

@property(nonatomic) NSString *placement;
@property(nonatomic) double bidPrice;

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (NSDictionary *)getBidData;

- (bool)hasBid;

@end

NS_ASSUME_NONNULL_END
