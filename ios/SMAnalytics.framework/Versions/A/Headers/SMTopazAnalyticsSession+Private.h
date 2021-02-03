//  TopAnalyticsSession+Private.h
//  Copyright (C) 2013 Char Software Inc., DBA Localytics
//
//  This code is provided under the Localytics Modified BSD License.
//  A copy of this license has been distributed in a file called LICENSE
//  with this source code.
//
// Please visit www.localytics.com for more information.

#import "SMTopazAnalyticsDatabase.h"
#import "SMTopazAnalyticsSession.h"
#import "SMTopazAnalyticsUploader.h"

#define CLIENT_VERSION_PREFIX @"iOS"

@interface SMTopazAnalyticsSession () {
    BOOL _hasInitialized;           // Whether or not the session object has been initialized.
    BOOL _isSessionOpen;            // Whether or not this session has been opened.
    float _sessionTimeoutInterval;  // If an App stays in the background for more
                                    // than this many seconds, start a new session
                                    // when it returns to foreground.
   @private
#pragma mark Member Variables
    dispatch_queue_t _queue;  // Queue of TopAnalytics block objects.
    dispatch_queue_t _openSessionQueue;
    dispatch_group_t _criticalGroup;  // Group of blocks the must complete before backgrounding.
    NSString *_sessionUUID;           // Unique identifier for this session.
    NSString *_applicationKey;        // Unique identifier for the instrumented application
    NSTimeInterval _lastSessionStartTimestamp;  // The start time of the most recent session.
    NSDate *_sessionResumeTime;                 // Time session was started or resumed.
    NSDate *_sessionCloseTime;                  // Time session was closed.
    NSMutableString
        *_unstagedFlowEvents;  // Comma-delimited list of app screens and events tagged during this
                               // session that have NOT been staged for upload.
    NSMutableString *_stagedFlowEvents;  // App screens and events tagged during this session that
                                         // HAVE been staged for upload.
    NSMutableString *_screens;  // Comma-delimited list of screens tagged during this session.
    NSTimeInterval _sessionActiveDuration;  // Duration that session open.
    BOOL _sessionHasBeenOpen;               // Whether or not this session has ever been open.
    SMTopazAnalyticsDatabase *_db;          // TopAnalytics database reference
    SMTopazAnalyticsUploader *_uploader;    // TopAnalytics uploader reference
    NSString *_applicationId;    // TopAnalytics uploader reference
}

@property(nonatomic, retain) NSString *applicationKey;
@property(nonatomic, readonly) dispatch_queue_t openSessionQueue;
@property(atomic) BOOL isSessionOpen;
@property(atomic) BOOL hasInitialized;
@property(nonatomic, retain) NSString *sessionUUID;
@property(nonatomic, assign) NSTimeInterval lastSessionStartTimestamp;
@property(nonatomic, retain) NSDate *sessionResumeTime;
@property(nonatomic, retain) NSDate *sessionCloseTime;
@property(nonatomic, retain) NSMutableString *unstagedFlowEvents;
@property(nonatomic, retain) NSMutableString *stagedFlowEvents;
@property(nonatomic, retain) NSMutableString *screens;
@property(nonatomic, assign) NSTimeInterval sessionActiveDuration;
@property(nonatomic, assign) BOOL sessionHasBeenOpen;
@property(nonatomic, assign) NSInteger sessionNumber;
@property(nonatomic, retain) NSString *applicationId;

// Private methods.
- (void)reopenPreviousSession;
- (void)addFlowEventWithName:(NSString *)name type:(NSString *)eventType;
- (void)addScreenWithName:(NSString *)name;
- (NSString *)blobHeaderStringWithSequenceNumber:(int)nextSequenceNumber;
- (BOOL)ll_isOptedIn;
- (BOOL)createOptEvent:(BOOL)optState;
- (BOOL)saveApplicationFlowAndRemoveOnResume:(BOOL)removeOnResume;
- (NSString *)formatAttributeWithName:(NSString *)paramName value:(NSString *)paramValue;
- (NSString *)formatAttributeWithName:(NSString *)paramName
                                value:(NSString *)paramValue
                                first:(BOOL)firstAttribute;
- (void)uploadCallback:(NSDictionary *)info;
+ (BOOL)appKeyIsValid:(NSString *)appKey;
- (void)ll_open;
- (SMTopazAnalyticsUploader *)uploader;
- (BOOL)uploadIsNeeded;
- (void)setDB:(SMTopazAnalyticsDatabase *)db;

// Datapoint methods.
- (NSString *)customDimensions;
- (NSString *)locationDimensions;
- (NSString *)hashString:(NSString *)input;
- (NSString *)randomUUID;
- (NSString *)escapeString:(NSString *)input;
- (NSString *)installationId;
- (NSTimeInterval)currentTimestamp;
- (NSString *)uniqueDeviceIdentifier;
- (NSDictionary *)identifiers;

@end
