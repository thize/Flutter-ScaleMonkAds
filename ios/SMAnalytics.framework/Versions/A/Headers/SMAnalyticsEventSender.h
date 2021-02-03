#import <Foundation/Foundation.h>

@protocol SMAnalyticsEventSender

- (void)startSession;
- (void)sendEvent:(NSString *)event;
- (void)sendEvent:(NSString *)event params:(NSDictionary *)params;

@end
