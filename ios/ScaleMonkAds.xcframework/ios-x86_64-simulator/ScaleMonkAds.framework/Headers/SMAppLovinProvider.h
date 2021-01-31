//  SMAppLovinProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "SMBannerProtocol.h"

@class SMProviderCallbacks;
@class ALSdk;

@interface SMAppLovinProvider : NSObject<SMProviderProtocol, SMInterstitialProtocol, SMVideoProtocol, SMBannerProtocol>

@property (nonatomic, copy) NSString* key;
@property (nonatomic, copy) NSString* bannerZoneId;
@property (nonatomic, weak) SMProviderCallbacks* callbacks;

+ (SMAppLovinProvider*) appLovinWithKey:(NSString *)key;

@end
