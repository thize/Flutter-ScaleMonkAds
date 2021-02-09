#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SMDeviceInfo.h"
#import "SMDeviceInfoLog.h"
#import "SMNetworkReachability.h"
#import "SMSmartParser.h"

FOUNDATION_EXPORT double SMDeviceInfoVersionNumber;
FOUNDATION_EXPORT const unsigned char SMDeviceInfoVersionString[];

