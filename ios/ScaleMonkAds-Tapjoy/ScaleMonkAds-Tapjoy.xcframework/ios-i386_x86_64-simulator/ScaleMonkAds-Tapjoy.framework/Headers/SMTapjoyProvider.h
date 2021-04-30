//  SMTapjoyProvider.h
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
#import "SMVideoProtocol.h"
#endif

@class SMTapjoyRewardedVideoDelegate;
@class SMTapjoyInterstitialDelegate;

@interface SMTapjoyProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol>

@property (nonatomic, weak) SMProviderCallbacks* callbacks;
@property (nonatomic) NSString* appKey;

@end
