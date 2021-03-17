//  SMAdColonyProvider.h
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
#import "SMVideoProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "AuctionProviderProtocol.h"
#endif

@interface SMAdColonyProvider : NSObject<SMProviderProtocol, SMVideoProtocol, SMInterstitialProtocol, SMBannerProtocol, AuctionProviderProtocol>

@property (nonatomic, copy) NSString* appId;
@property (weak) SMProviderCallbacks* callbacks;
@property (nonatomic, copy) NSArray<NSString*>* rtbZoneIds;

@end
