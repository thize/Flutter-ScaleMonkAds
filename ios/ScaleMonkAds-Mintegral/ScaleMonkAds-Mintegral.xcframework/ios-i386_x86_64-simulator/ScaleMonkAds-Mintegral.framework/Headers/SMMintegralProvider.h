//  SMMintegralProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "AuctionProviderProtocol.h"
#import "SMVideoProtocol.h"
#import "SMInterstitialProtocol.h"
#endif

@interface SMMintegralProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, AuctionProviderProtocol>

@property(weak) SMProviderCallbacks *callbacks;
@property (nonatomic) NSString* appId;
@property (nonatomic) NSString* appKey;


@end
