#import "SMAnalyticsEventSender.h"

@class SMTopazAnalyticsSession;

@interface SMTopazEventSender : NSObject <SMAnalyticsEventSender>

+ (SMTopazEventSender *)topazWithSession:(SMTopazAnalyticsSession *)session;

@end
