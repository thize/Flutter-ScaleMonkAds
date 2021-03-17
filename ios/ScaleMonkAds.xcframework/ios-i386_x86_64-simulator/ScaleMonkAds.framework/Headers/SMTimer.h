//  SMTimer.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
//  Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTimer : NSObject

/**
 Initializes a new SMTimer instance.

 @return the SMTimer instance
 */
- (instancetype)init;

/**
 Starts a timer for a given key.

 If you start a timer for a previously started key, the timer will reset.

 @param key the key to retrieve the timer.
 */
- (void)startTimerFor:(NSString *)key;

/**
 Returns the elapsed time in milliseconds for a key.

 @param key the key to retrieve the timer.

 @return The elapsed time in milliseconds if a timer exists for key, otherwise -1.
 */
- (NSNumber *)elapsedTimeFor:(NSString *)key;

/**
Remove timer with the given key.

@param key the key of the timer that will be removed.
*/
- (void)clearTimerFor:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
