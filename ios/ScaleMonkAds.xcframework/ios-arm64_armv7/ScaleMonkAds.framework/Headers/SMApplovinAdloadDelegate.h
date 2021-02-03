//  SMApplovinAdloadDelegate.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>

@class SMWaterfallEntry;

@protocol SMApplovinAddloadProtocol <NSObject>

- (void) didFailToLoadAdWithAttrProvider:(SMWaterfallEntry*)attrProvider;
- (void) didLoadAdWithAttrProvider:(SMWaterfallEntry*)attrProvider ad:(ALAd*)ad;

@end


@interface SMApplovinAdloadDelegate : NSObject <ALAdLoadDelegate>

- (instancetype)initWithAttrProvider:(SMWaterfallEntry*)attrProvider delegate:(id<SMApplovinAddloadProtocol>)delegate;

@end

