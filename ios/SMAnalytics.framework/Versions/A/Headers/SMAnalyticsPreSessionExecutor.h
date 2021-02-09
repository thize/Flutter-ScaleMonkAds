#import <Foundation/Foundation.h>

@interface SMAnalyticsPreSessionExecutor : NSObject

- (instancetype)initWithStartAction:(void (^)())startAction
                        eventAction:(void (^)())eventAction
                              queue:(dispatch_queue_t)queue
                             actors:(NSArray *)actors;

- (void)enterPreSessionTask;
- (void)leavePreSessionTask;
- (void)executePreSessionActivities;

@end
