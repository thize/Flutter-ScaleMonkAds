//  SMVungleProvider.h
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
#import "AuctionProviderProtocol.h"
#endif

@class SMProviderCallbacks;

@interface SMVungleProvider : NSObject <SMProviderProtocol, SMVideoProtocol, SMInterstitialProtocol, AuctionProviderProtocol>

@property (nonatomic, copy) NSString* appId;
@property (weak) SMProviderCallbacks* callbacks;

@end