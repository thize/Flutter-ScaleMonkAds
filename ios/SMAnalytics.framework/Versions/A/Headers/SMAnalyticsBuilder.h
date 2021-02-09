//
//  SMAnalyticsBuilder.h
//  SMAnalytics
//
//  Copyright © 2015 SM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SMTopazAnalyticsSession;
@class SMAnalytics;

@interface SMAnalyticsBuilder : NSObject

@property(nonatomic, copy) NSArray *reinstallAttributes;
@property(nonatomic, copy) NSDictionary *userAttributes;
@property(nonatomic, strong) NSString *applicationId;

- (NSArray *)eventSenders;
- (SMTopazAnalyticsSession *)session;

- (SMAnalytics *)build;

@end
