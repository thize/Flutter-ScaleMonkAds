//  SMARError.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>

#import "SMARAdFormat.h"

typedef enum {
  SMARErrorBadPayload,
  SMARErrorNetworkFailed,
  SMARErrorLoadingFailed,
  SMARErrorPlayingFailed,
  SMARErrorNetworkTimeout,
  SMARErrorUnsupportedAdFormat,
  SMARErrorUnknown
} SMARErrorCode;

@interface SMARError : NSObject

+ (NSError *)errorWithCode:(SMARErrorCode)code withDescription:(NSString *)description;

+ (NSError *)malformedPayload:(NSString *)details;

+ (NSError *)networkFailed:(NSString *)details;

+ (NSError *)networkTimeout:(NSString *)details;

+ (NSError *)loadingFailed:(NSString *)details;

+ (NSError *)playingFailed:(NSString *)details;

+ (NSError *)unsupportedFormat:(SMARAdFormat)format;

+ (NSError *)unknown;

@end
