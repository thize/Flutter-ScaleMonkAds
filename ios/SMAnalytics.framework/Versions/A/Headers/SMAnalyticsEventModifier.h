#import <Foundation/Foundation.h>

@protocol SMAnalyticsEventModifier

- (void)editParameters:(NSMutableDictionary *)params ofEvent:(NSString *)event;

@end
