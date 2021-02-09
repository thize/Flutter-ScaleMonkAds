#import <Foundation/Foundation.h>

@protocol SMAnalyticsPreSessionActor

- (void)executePreSessionActionWithCompletion:(void (^)())completion;

@end
