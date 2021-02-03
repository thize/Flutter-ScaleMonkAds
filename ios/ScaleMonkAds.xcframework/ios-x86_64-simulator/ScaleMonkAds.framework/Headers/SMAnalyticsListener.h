//  SMAnalyticsListener.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>

@protocol SMAnalyticsListener <NSObject>
@required
- (void)onEventReceived:(NSString *)eventName
            eventParams:(NSDictionary<NSString *, NSObject *> *)eventParams;
@end
