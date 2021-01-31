//  SMAppLovinVideoDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>

#import "SMVideoProtocol.h"
#import "SMApplovinAdloadDelegate.h"

@class SMProviderCallbacks;

@interface SMAppLovinVideoDelegate : NSObject <SMVideoProtocol,
    ALAdDisplayDelegate,
    ALAdVideoPlaybackDelegate,
    ALAdRewardDelegate,
    SMApplovinAddloadProtocol>

@property (nonatomic, weak) SMProviderCallbacks* callbacks;

- (instancetype) initWithSdk:(ALSdk*)sdk
              andCallbacks:(SMProviderCallbacks*)callbacks;

- (void) updateConfigsWithSdk:(ALSdk *)appLovinSdk;

@end

