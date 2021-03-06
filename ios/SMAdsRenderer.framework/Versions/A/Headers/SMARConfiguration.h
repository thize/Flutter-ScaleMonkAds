//  SMARConfiguration.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>

@interface SMARConfiguration : NSObject

/**
 @brief This flag enables or disables the renderer test mode. This feature
 is currently not working.
*/
@property(nonatomic) bool testModeEnabled;

/**
 @brief This defines the default value when interstitial should display the Skip
 Ad button. The value is in seconds and it's default value is 5.
*/
@property(nonatomic) int interstitialDefaultSkipOffset;

/**
 @brief This defines the default value when rewarded videos should display the
 Skip Ad button. The value is in seconds and it's default value is 30.
*/
@property(nonatomic) int rewardedVideoDefaultSkipOffset;

/**
 @brief This defines the banner unit id that's used by some implementations of the renderer
*/
@property(nonatomic) NSString* bannerUnitId;

/**
 @brief This defines the interstitial unit id that's used by some implementations of the renderer
*/
@property(nonatomic) NSString* interstitialUnitId;

/**
 @brief This defines the rewarded video unit id that's used by some implementations of the renderer
*/
@property(nonatomic) NSString* rewardedUnitId;

@end
