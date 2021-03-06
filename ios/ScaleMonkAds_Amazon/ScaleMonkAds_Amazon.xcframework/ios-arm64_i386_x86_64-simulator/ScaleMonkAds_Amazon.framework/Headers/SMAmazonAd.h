//  SMAmazonAd.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMAds.h"
#import "SMARAd.h"
#import "SMAdsRTBLoggerProtocol.h"
#import "SMTimer.h"
#import "SMProviderProtocol.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SMAmazonAd : NSObject

@property NSString *slotId;
@property NSDictionary *amazonBidParams;
@property SMARAd *ad;
@property SMWaterfallEntry *providerAttributed;
@property SMWaterfallEntry *requestProviderAttributed;
@property id <SMAdsRTBLoggerProtocol> logger;
@property SMTimer *bidTimer;

- (bool)hasBid;

- (NSDictionary<NSString *, NSObject *> *)consumeBidDataForAdType:(AdTypeEnum)adType;

- (void)requestBid;

@end

NS_ASSUME_NONNULL_END
