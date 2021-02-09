#import <Foundation/Foundation.h>
#import "SMAnalyticsBuilder.h"

@class SMTopazAnalyticsSession;
@protocol SMAnalyticsEventModifier;
@protocol SMAnalyticsHeaderModifier;

typedef void (^SMAnalyticsSetupBlock)(SMAnalyticsBuilder *);

@interface SMAnalytics : NSObject

/**
 Returns whether this is the first user session after fresh installation or not.
 */
@property(nonatomic, readonly) bool isFirstSession;

/**
 Returns whether this is a reinstall or not.
 */
@property(nonatomic, readonly) bool isReinstall;

/**
 Returns the number of sessions after the latest installation.
 */
@property(nonatomic, readonly) int numSessions;

/**
 Returns the FIU (first install user ID).
 */
@property(nonatomic, readonly) NSString *firstInstallId;

/**
 Returns the app version of the first installation.

 Example: If the first app version installed was '1.2.3 (10)' and the application is now at
 '2.0.0 (50)', this property will return '1.2.3 (10)'.
 */
@property(nonatomic, readonly) NSString *firstInstallAppVersion;

/**
 Returns the date of first installation.

 The date format is 'yyyy-MM-dd' (example: '2016-03-11').
 */
@property(nonatomic, readonly) NSString *activationDate;

/**
 Returns how many days the user has been sending analytics events.

 Note that this is a string.
 */
@property(nonatomic, readonly) NSString *daysActive;

/**
 Sets up the SMAnalytics shared instance by using a setup block.

 The block parameter will contain a builder that can configure the SMAnalytics instance.

 After calling this, you can access the SMAnalytics instance by calling
 [SMAnalytics sharedInstance].

 You will usually call this method as soon as the application starts, preferably at
 'application:didFinishLaunchingWithOptions:' in your AppDelegate class.

 @param setupBlock The setup block instance.
 */
+ (void)setupWithBlock:(SMAnalyticsSetupBlock)setupBlock;

/**
 Returns the configured SMAnalytics sharedInstance.

 You must call [SMAnalytics setupWithBlock:] before using this instance.

 @return The SMAnalytics instance.
 */
+ (SMAnalytics *)sharedInstance;

- (instancetype)init __unavailable;

/**
 Creates an instance of SMAnalytics using a builder instance.

 @param builder The builder instance.

 @return The newly created SMAnalytics instance.
 */
- (instancetype)initWithBuilder:(SMAnalyticsBuilder *)builder;

/**
 Sends an event with empty parameters to all available loggers.

 @param eventName The event name.
 */
- (void)sendEvent:(NSString *)eventName;

/**
 Sends an event with parameters to all available loggers.

 @param eventName The event name.
 @param params The event parameters.
 */
- (void)sendEvent:(NSString *)eventName params:(NSDictionary *)params;

/**
 Sends an event once per install with empty parameters to all available loggers.

 @param eventName The event name.
 */
- (void)sendOneTimeEvent:(NSString *)eventName;

/**
 Sends an event once per install with parameters to all available loggers.

 @param eventName The event name.
 @param params The event parameters.
 */
- (void)sendOneTimeEvent:(NSString *)eventName params:(NSDictionary *)params;

// TODO: document 'OpenSession' events API.
- (void)sendOneTimeEventInOpenSession:(NSString *)eventName;
- (void)sendOneTimeEventInOpenSession:(NSString *)eventName params:(NSDictionary *)params;

/**
 Adds the instance to a list of event modifiers.

 Each modifier in the list will be called before an event is sent.

 @param modifier The event modifier instance.

 @see SMAnalyticsEventModifier protocol.
 */
- (void)addEventModifier:(id<SMAnalyticsEventModifier>)modifier;

/**
 Adds a header modifier instance to the Topaz logger.

 Before an event is sent, the Topaz logger will add all the custom header params from all registered
 modifiers.

 Note: header modifiers only apply for the Topaz logger.

 @param modifier The event modifier instance.

 @see SMAnalyticsHeaderModifier protocol.
 */
- (void)addHeaderModifier:(id<SMAnalyticsHeaderModifier>)modifier;

// TODO: document UserAttributes API.
- (void)setUserAttribute:(NSString *)key value:(NSString *)value;
- (NSString *)getUserAtttribute:(NSString *)key;

/**
 Flushes all buffered events to Topaz.
 */
- (void)uploadEvents;

@end
