//
//  SMAnalyticsLog.h
//  SMAnalytics
//
//  Copyright © 2015 SM. All rights reserved.
//

#ifndef SMAnalyticsLog_h
#define SMAnalyticsLog_h

#define SM_ANALYTICS_LOG_TAG @"[SMAnalytics] "

#ifdef SM_ANALYTICS_LOG_COLORS_ENABLE
#define SM_ANALYTICS_XCODE_COLORS_ESCAPE @"\033["
#define SM_ANALYTICS_XCODE_COLORS_RESET SM_ANALYTICS_XCODE_COLORS_ESCAPE @";"
#define SM_ANALYTICS_XCODE_COLORS(color) SM_ANALYTICS_XCODE_COLORS_ESCAPE color
#else
#define SM_ANALYTICS_XCODE_COLORS_ESCAPE
#define SM_ANALYTICS_XCODE_COLORS_RESET
#define SM_ANALYTICS_XCODE_COLORS(color)
#endif

#ifdef DEBUG
#define SMAnalyticsAssert(cond, frmt, ...)                                                     \
    NSAssert(cond,                                                                             \
             SM_ANALYTICS_XCODE_COLORS(@"fg255,0,255;") SM_ANALYTICS_LOG_TAG @"(Assert) "      \
                                                                             @"{%@:%d} " frmt, \
             @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMAnalyticsAssert(cond, frmt, ...)
#endif

#if defined(SM_ANALYTICS_LOG_LEVEL) && SM_ANALYTICS_LOG_LEVEL >= 1
#define SMAnalyticsLogError(frmt, ...)                                   \
    NSLog((SM_ANALYTICS_XCODE_COLORS(@"fg255,0,0;") SM_ANALYTICS_LOG_TAG \
           @"(Error) "                                                   \
           @"{%@:%d} " frmt SM_ANALYTICS_XCODE_COLORS_RESET),            \
          @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMAnalyticsLogError(frmt, ...)
#endif

#if defined(SM_ANALYTICS_LOG_LEVEL) && SM_ANALYTICS_LOG_LEVEL >= 2
#define SMAnalyticsLogWarning(frmt, ...)                                   \
    NSLog((SM_ANALYTICS_XCODE_COLORS(@"fg255,150,0;") SM_ANALYTICS_LOG_TAG \
           @"(Warn) "                                                      \
           @"{%@:%d} " frmt SM_ANALYTICS_XCODE_COLORS_RESET),              \
          @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMAnalyticsLogWarning(frmt, ...)
#endif

#if defined(SM_ANALYTICS_LOG_LEVEL) && SM_ANALYTICS_LOG_LEVEL >= 3
#define SMAnalyticsLogInfo(frmt, ...)                                      \
    NSLog((SM_ANALYTICS_XCODE_COLORS(@"fg255,255,0;") SM_ANALYTICS_LOG_TAG \
           @"(Info) "                                                      \
           @"{%@:%d} " frmt SM_ANALYTICS_XCODE_COLORS_RESET),              \
          @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMAnalyticsLogInfo(frmt, ...)
#endif

#if defined(SM_ANALYTICS_LOG_LEVEL) && SM_ANALYTICS_LOG_LEVEL >= 4
#define SMAnalyticsLogDebug(frmt, ...)                                   \
    NSLog((SM_ANALYTICS_XCODE_COLORS(@"fg0,255,0;") SM_ANALYTICS_LOG_TAG \
           @"(Debug) "                                                   \
           @"{%@:%d} " frmt SM_ANALYTICS_XCODE_COLORS_RESET),            \
          @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMAnalyticsLogDebug(frmt, ...)
#endif

#if defined(SM_ANALYTICS_LOG_LEVEL) && SM_ANALYTICS_LOG_LEVEL >= 5
#define SMAnalyticsLogTrace(frmt, ...)                                       \
    NSLog((SM_ANALYTICS_XCODE_COLORS(@"fg255,255,255;") SM_ANALYTICS_LOG_TAG \
           @"(Trace) "                                                       \
           @"{%@::%d:%s}" frmt SM_ANALYTICS_XCODE_COLORS_RESET),             \
          @(__FILE__).lastPathComponent, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#else
#define SMAnalyticsLogTrace(frmt, ...)
#endif

#endif /* SMAnalyticsLog_h */
