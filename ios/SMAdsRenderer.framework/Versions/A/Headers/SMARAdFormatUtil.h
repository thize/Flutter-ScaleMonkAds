//  SMARAdFormatUtil.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAdFormat.h"

@interface SMARAdFormatUtil : NSObject

+ (SMARAdFormat)fromContentTypeToAdFormat:(NSString *)contentType;
+ (NSString *)fromAdFormatToContentType:(SMARAdFormat)format;

@end
