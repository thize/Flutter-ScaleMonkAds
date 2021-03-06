//  SMARLogger.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#ifndef SMARLog_h
#define SMARLog_h

#define SMAR_LOG_TAG @"[SMAR] "

#ifdef SMAR_LOG_COLORS_ENABLE
#define SMAR_XCODE_COLORS_ESCAPE @"\033["  //
#define SMAR_XCODE_COLORS_RESET SMAR_XCODE_COLORS_ESCAPE @";"
#define SMAR_XCODE_COLORS(color) SMAR_XCODE_COLORS_ESCAPE color
#else
#define SMAR_XCODE_COLORS_ESCAPE
#define SMAR_XCODE_COLORS_RESET
#define SMAR_XCODE_COLORS(color)
#endif

#ifdef DEBUG
#define SMAR_LOG_LEVEL 5
#define SMARAssert(cond, frmt, ...)                         \
  NSAssert(cond,                                             \
           SMAR_XCODE_COLORS(@"fg255,0,255;") SMAR_LOG_TAG \
           @"(Assert) "                                      \
           @"{%@:%d} " frmt SMAR_XCODE_COLORS_RESET,        \
           @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMARAssert(cond, frmt, ...)
#endif

#if defined(SMAR_LOG_LEVEL) && SMAR_LOG_LEVEL >= 1
#define SMARLogError(frmt, ...)                                                                   \
  NSLog(                                                                                           \
      (SMAR_XCODE_COLORS(@"fg255,0,0;") SMAR_LOG_TAG @"(Error) "                                 \
                                                       @"{%@:%d} " frmt SMAR_XCODE_COLORS_RESET), \
      @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMARLogError(frmt, ...)
#endif

#if defined(SMAR_LOG_LEVEL) && SMAR_LOG_LEVEL >= 2
#define SMARLogWarning(frmt, ...)                         \
  NSLog((SMAR_XCODE_COLORS(@"fg255,150,0;") SMAR_LOG_TAG \
         @"(Warn) "                                        \
         @"{%@:%d} " frmt SMAR_XCODE_COLORS_RESET),       \
        @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMARLogWarning(frmt, ...)
#endif

#if defined(SMAR_LOG_LEVEL) && SMAR_LOG_LEVEL >= 3
#define SMARLogInfo(frmt, ...)                            \
  NSLog((SMAR_XCODE_COLORS(@"fg255,255,0;") SMAR_LOG_TAG \
         @"(Info) "                                        \
         @"{%@:%d} " frmt SMAR_XCODE_COLORS_RESET),       \
        @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMARLogInfo(frmt, ...)
#endif

#if defined(SMAR_LOG_LEVEL) && SMAR_LOG_LEVEL >= 4
#define SMARLogDebug(frmt, ...)                                                                   \
  NSLog(                                                                                           \
      (SMAR_XCODE_COLORS(@"fg0,255,0;") SMAR_LOG_TAG @"(Debug) "                                 \
                                                       @"{%@:%d} " frmt SMAR_XCODE_COLORS_RESET), \
      @(__FILE__).lastPathComponent, __LINE__, ##__VA_ARGS__)
#else
#define SMARLogDebug(frmt, ...)
#endif

#if defined(SMAR_LOG_LEVEL) && SMAR_LOG_LEVEL >= 5
#define SMARLogTrace(frmt, ...)                             \
  NSLog((SMAR_XCODE_COLORS(@"fg255,255,255;") SMAR_LOG_TAG \
         @"(Trace) "                                         \
         @"{%@::%d:%s} " frmt SMAR_XCODE_COLORS_RESET),     \
        @(__FILE__).lastPathComponent, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#else
#define SMARLogTrace(frmt, ...)
#endif

#endif /* SMARLogger_h */
