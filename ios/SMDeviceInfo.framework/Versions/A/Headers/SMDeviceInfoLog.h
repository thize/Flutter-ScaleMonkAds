//
//  SMDeviceInfoLog.h
//  SMDeviceInfo
//
//  Copyright © 2018 SM. All rights reserved.
//

#ifndef SMDeviceInfoLog_h
#define SMDeviceInfoLog_h

#define SM_DEVICE_INFO_LOG_TAG @"[SMDeviceInfo] "

#define SM_SAFE_STRING(string) (string ? string : @"")

#ifdef SM_DEVICE_INFO_LOG_COLORS_ENABLE
#define SM_DEVICE_INFO_XCODE_COLORS_ESCAPE @"\033["
#define SM_DEVICE_INFO_XCODE_COLORS_RESET SM_DEVICE_INFO_XCODE_COLORS_ESCAPE @";"
#define SM_DEVICE_INFO_XCODE_COLORS(color) SM_DEVICE_INFO_XCODE_COLORS_ESCAPE color
#else
#define SM_DEVICE_INFO_XCODE_COLORS_ESCAPE
#define SM_DEVICE_INFO_XCODE_COLORS_RESET
#define SM_DEVICE_INFO_XCODE_COLORS(color)
#endif

#ifdef DEBUG
#define SMDeviceInfoAssert(cond, frmt, ...)                                      \
    NSAssert(cond,                                                               \
             SM_DEVICE_INFO_XCODE_COLORS(@"fg255,0,255;") SM_DEVICE_INFO_LOG_TAG \
             @"(Assert) "                                                        \
             @"{%@:%d} " frmt SM_DEVICE_INFO_XCODE_COLORS_RESET,                 \
             @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMDeviceInfoAssert(cond, frmt, ...)
#endif

#endif /* SMDeviceInfoLog_h */
