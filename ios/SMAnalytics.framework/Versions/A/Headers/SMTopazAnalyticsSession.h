//  TopAnalyticsSession.h
//  Copyright (C) 2013 Char Software Inc., DBA Localytics
//
//  This code is provided under the Localytics Modified BSD License.
//  A copy of this license has been distributed in a file called LICENSE
//  with this source code.
//
// Please visit www.localytics.com for more information.

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#define MARKETING_PLATFORM

#ifndef TOPAZ_CLIENT_VERSION
#define TOPAZ_CLIENT_VERSION @"2.1.20"
#endif

/*!
 @class TopAnalyticsSession
 @discussion The class which manages creating, collecting, & uploading a TopAnalytics session.
 Please see the following guides for information on how to best use this
 library, sample code, and other useful information:
 <ul>
 <li><a href="http://wiki.localytics.com/index.php?title=Developer's_Integration_Guide">
 Main Developer's Integration Guide</a></li>
 </ul>


 <strong>Best Practices</strong>
 <ul>
 <li>Instantiate the TopAnalyticsSession object in applicationDidFinishLaunching.</li>
 <li>Open your session and begin your uploads in applicationDidFinishLaunching. This way the
 upload has time to complete and it all happens before your users have a
 chance to begin any data intensive actions of their own.</li>
 <li>Close the session in applicationWillTerminate, and in applicationDidEnterBackground.</li>
 <li>Resume the session in applicationWillEnterForeground.</li>
 <li>Do not call any TopAnalytics functions inside a loop.  Instead, calls
 such as <code>tagEvent</code> should follow user actions.  This limits the
 amount of data which is stored and uploaded.</li>
 <li>Do not use multiple LocalticsSession objects to upload data with
 multiple application keys.  This can cause invalid state.</li>
 </ul>

 @author TopAnalytics
 */

#import "SMAnalyticsHeaderModifier.h"

// Forward declaration
@protocol SMTopazAnalyticsSessionDelegate;
@class SMTopazAnalyticsDatabase;

@interface SMTopazAnalyticsSession : NSObject {
    BOOL _delaySession;  // Whether or not the server should delay processing on this upload
    NSString *_facebookAttribution;  // Facebook attribution cookie
}

+ (void)logMessage:(NSString *)message;

/*!
 @property loggingEnabled
 @abstract (Optional) Determines whether or TopAnalytics debugging information is shown
 to the console. The default is NO
 */
@property(nonatomic, assign) BOOL loggingEnabled;

/*!
 @property sessionTimeoutInterval
 @abstrac (Optional) If an App stays in the background for more than this many seconds,
 start a new session when it returns to foreground.
 */
@property(atomic) float sessionTimeoutInterval;

/*!
 @property topAnalyticsDelegate
 @abstract (Optional) Assign this delegate to the class you'd like to register to recieve
 the TopAnalytics delegate callbacks (Defined at the end of this file)
 */
@property(nonatomic, assign) id<SMTopazAnalyticsSessionDelegate> SMAnalyticsDelegate;

/*!
 @property isInstallUser
 @abstract Determines whether or not user is installing app. The default is NO
 */
@property(nonatomic, assign) BOOL isInstallUser;

#pragma mark Public Methods

- (SMTopazAnalyticsSession *)initWithPreSessionActors:(NSArray *)preSessionActors
                                      preUploadActors:(NSArray *)preUploadActors
                                  reinstallAttributes:(NSArray *)recoverable
                                       userAttributes:(NSDictionary *)attributes
                                       applicationId:(NSString *)applicationId;

/*!
 @method startSession
 @abstract An optional convenience initialize method that also calls the TopAnalyticsSession, open &
 upload methods. Best Practice is to call open & upload immediately after TopAnalytics Session when
 loading an app, this method facilitates that behavior. It is recommended that this call be placed
 in <code>applicationDidFinishLaunching</code>.
 */
- (void)startSession;

/*!
 @method open
 @abstract Opens the TopAnalytics session. Not necessary if you choose to use startSession.
 The session time as presented on the website is the time between <code>open</code> and the
 final <code>close</code> so it is recommended to open the session as early as possible, and close
 it at the last moment.  The session must be opened before any tags can
 be written.  It is recommended that this call be placed in
 <code>applicationDidFinishLaunching</code>. <br> If for any reason this is called more than once
 every subsequent open call will be ignored.
 */
- (void)open;

/*!
 @method resume
 @abstract Resumes the TopAnalytics session.  When the App enters the background, the session is
 closed and the time of closing is recorded.  When the app returns to the foreground, the session
 is resumed.  If the time since closing is greater than BACKGROUND_SESSION_TIMEOUT, (15 seconds
 by default) a new session is created, and uploading is triggered.  Otherwise, the previous session
 is reopened.
 */
- (void)resume;

/*!
 @method close
 @abstract Closes the TopAnalytics session.  This should be called in
 <code>applicationWillTerminate</code>.
 <br>
 If close is not called, the session will still be uploaded but no
 events will be processed and the session time will not appear. This is
 because the session is not yet closed so it should not be used in
 comparison with sessions which are closed.
 */
- (void)close;

/*!
 @method tagEvent
 @abstract Allows a session to tag a particular event as having occurred.  For
 example, if a view has three buttons, it might make sense to tag
 each button click with the name of the button which was clicked.
 For another example, in a game with many levels it might be valuable
 to create a new tag every time the user gets to a new level in order
 to determine how far the average user is progressing in the game.
 <br>
 <strong>Tagging Best Practices</strong>
 <ul>
 <li>DO NOT use tags to record personally identifiable information.</li>
 <li>The best way to use tags is to create all the tag strings as predefined
 constants and only use those.  This is more efficient and removes the risk of
 collecting personal information.</li>
 <li>Do not set tags inside loops or any other place which gets called
 frequently.  This can cause a lot of data to be stored and uploaded.</li>
 </ul>
 <br>
 See the tagging guide at: http://wiki.localytics.com/
 @param event The name of the event which occurred.
 @param attributes (Optional) An object/hash/dictionary of key-value pairs, contains
 contextual data specific to the event.
 @param rerportAttributes (Optional) Additional attributes used for custom reporting.
 Available to Enterprise customers, please contact services for more details.
 @param customerValueIncrease (Optional) Numeric value, added to customer lifetime value.
 Integer expected. Try to use lowest possible unit, such as cents for US currency.
 */
- (void)tagEvent:(NSString *)event;

- (void)tagEvent:(NSString *)event attributes:(NSDictionary *)attributes;

/*!
 @method tagScreen
 @abstract Allows tagging the flow of screens encountered during the session.
 @param screen The name of the screen
 */
- (void)tagScreen:(NSString *)screen;

/*!
 @method upload
 @abstract Creates a low priority thread which uploads any TopAnalytics data already stored
 on the device.  This should be done early in the process life in order to
 guarantee as much time as possible for slow connections to complete.  It is also reasonable
 to upload again when the application is exiting because if the upload is cancelled the data
 will just get uploaded the next time the app comes up.
 */
- (void)upload;

/*!
 @method TopAnalyticsSession
 @abstract Initializes the TopAnalytics Object.  Not necessary if you choose to use startSession.
 @param applicationKey The key unique for each application generated at www.localytics.com
 */
- (void)SMAnalyticsSession:(NSString *)appKey;

/*!
 @method setOptIn
 @abstract (OPTIONAL) Allows the application to control whether or not it will collect user data.
 Even if this call is used, it is necessary to continue calling upload().  No new data will be
 collected, so nothing new will be uploaded but it is necessary to upload an event telling the
 server this user has opted out.
 @param optedIn True if the user is opted in, false otherwise.
 */
- (void)setOptIn:(BOOL)optedIn;

/*!
 @method setLocation
 @abstract Stores the user's location.  This will be used in all event and session calls.
 If your application has already collected the user's location, it may be passed to TopAnalytics
 via this function.  This will cause all events and the session close to include the locatin
 information.  It is not required that you call this function.
 @param deviceLocation The user's location.
 */
- (void)setLocation:(CLLocationCoordinate2D)deviceLocation;

/*!
 @method setCustomDimension
 @abstract Sets the value of a custom dimension. Custom dimensions are dimensions
 which contain user defined data unlike the predefined dimensions such as carrier, model, and
 country. Once a value for a custom dimension is set, the device it was set on will continue to
 upload that value until the value is changed. To clear a value pass nil as the value. The proper
 use of custom dimensions involves defining a dimension with less than ten distinct possible values
 and assigning it to one of the four available custom dimensions. Once assigned this definition
 should never be changed without changing the App Key otherwise old installs of the application will
 pollute new data.
 */
- (void)setCustomDimension:(int)dimension value:(NSString *)value;

/*!
 @method customDimension
 @abstract Gets the custom dimension value for a given dimension. Avoid calling this on the main
 thread, as it may take some time for all pending database execution. */
- (NSString *)customDimension:(int)dimension;

/*!
 @method setValueForIdentifier
 @abstract Sets the value of a custom identifier. Identifiers are a form of key/value storage
 which contain custom user data. Identifiers might include things like email addresses, customer
 IDs, twitter handles, and facebook IDs. Once a value is set, the device it was set on will continue
 to upload that value until the value is changed. To delete a property, pass in nil as the value.
 */
- (void)setValueForIdentifier:(NSString *)identifierName value:(NSString *)value;
- (NSString *)getValueForIdentifier:(NSString *)identifierName;

/*!
 @method setCustomerName
 @abstract Record the customer name
 Once this value is set, the device it was set on will continue to upload that value until the value
 is changed. To delete the value, pass in nil.
 */
- (void)setCustomerName:(NSString *)email;

/*!
 @method setCustomerId
 @abstract Record your custom customer identifier
 Once this value is set, the device it was set on will continue to upload that value until the value
 is changed. To delete the value, pass in nil.
 */
- (void)setCustomerId:(NSString *)customerId;

/*!
 @method setCustomerId
 @abstract Record the customer's email address
 Once this value is set, the device it was set on will continue to upload that value until the value
 is changed. To delete the value, pass in nil.
 */
- (void)setCustomerEmail:(NSString *)email;

- (void)setFirstAccess;
- (void)executeInOpenSession:(void (^)())action;

- (void)addHeaderModifier:(id<SMAnalyticsHeaderModifier>)modifier;

@property(nonatomic, assign) BOOL delaySession;
@property(nonatomic, retain) NSString *facebookAttribution;

- (SMTopazAnalyticsDatabase *)db;
@property(nonatomic, readonly) dispatch_group_t criticalGroup;
@property(nonatomic, readonly) dispatch_queue_t queue;

@property(nonatomic, readonly) bool isFirstSession;
@property(nonatomic, readonly) bool isReinstall;
@property(nonatomic, readonly) int numSessions;

@property(nonatomic, readonly) NSString *firstInstallId;
@property(nonatomic, readonly) NSString *firstInstallAppVersion;
@property(nonatomic, readonly) NSString *activationDate;
@property(nonatomic, readonly) NSString *daysActive;
@property(nonatomic, readonly) NSString *applicationId;

@end

@protocol SMTopazAnalyticsSessionDelegate <NSObject>
@optional

/*!
 @method SMAnalyticsResumedSession
 @abstract Register for this callback to be notified when SMAnalytics has either
 resumed a previous session or created a new one. See the on the 'resume' method
 for additional details.
 @param didResumeExistingSession This flag will indicate if SMAnalytics restored an existing
 session or started a new one.
 */
- (void)SMAnalyticsResumedSession:(BOOL)didResumeExistingSession;

@end
