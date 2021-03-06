//  SMWrapperAnalytics.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>

@protocol SMWrapperAnalytics <NSObject>

@required

-(void)sendEvent:(NSString*)event withParams:(NSDictionary<NSString *, NSObject *> *)params;

@end
