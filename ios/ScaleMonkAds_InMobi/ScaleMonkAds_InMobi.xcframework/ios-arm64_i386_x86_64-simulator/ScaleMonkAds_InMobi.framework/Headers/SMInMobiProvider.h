//  SMInMobiProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerViewProtocol.h"
#import "SMBannerView.h"
#import "SMIMHeaderBiddingInterstitial.h"
#import "AuctionProviderProtocol.h"
#import "SMAdsRTBLoggerProtocol.h"
#endif

@class SMProviderCallbacks;

@interface SMInMobiProvider : NSObject <SMProviderProtocol, AuctionProviderProtocol, SMInterstitialProtocol, SMBannerProtocol>

@property(nonatomic, copy) NSString *accountId;
@property(weak) SMProviderCallbacks *callbacks;

- (void)headerBiddingWithInterstitialPlacement:(NSString *)placement;

@end

