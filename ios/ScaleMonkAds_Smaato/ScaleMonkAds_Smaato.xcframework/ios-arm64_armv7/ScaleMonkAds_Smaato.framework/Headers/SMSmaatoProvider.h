//  SMSmaatoProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#import "SMVideoProtocol.h"
#import "SMAds.h"
#endif

@interface SMSmaatoProvider : NSObject <SMProviderProtocol, SMBannerProtocol, SMInterstitialProtocol, SMVideoProtocol>

@property(weak) SMProviderCallbacks *adsInstance;
@property(nonatomic) NSString *publisherId;

@end
