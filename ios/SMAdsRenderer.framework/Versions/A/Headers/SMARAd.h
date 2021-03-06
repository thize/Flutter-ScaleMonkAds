//  SMARAd.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import "SMARAdFormat.h"
#import "SMARAdType.h"
#import "SMARConfiguration.h"

@interface SMARAd : NSObject

@property(nonatomic, strong, readonly) NSUUID *id;
@property(nonatomic, strong) NSString *payload;
@property(nonatomic) int skipOffsetInSeconds;
@property(nonatomic) bool isSkippable;
@property(nonatomic) SMARAdFormat format;
@property(nonatomic) SMARAdType adType;

- (instancetype)initWithPayload:(NSString *)payload
                    contentType:(NSString *)contentType
                         adType:(SMARAdType)adType
                         config:(SMARConfiguration *)config;

- (NSString *)getId;
- (NSString *)skipOffsetAsTimeString;
- (bool)isFullscreen;

+ (int)skipOffsetForAdType:(SMARAdType)adType withConfig:(SMARConfiguration *)config;

@end
