//  SMRTBWaterfallEntry.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#ifndef SMRTBWaterfallEntry_h
#define SMRTBWaterfallEntry_h

#import "SMWaterfallEntry.h"

@interface SMRTBWaterfallEntry : SMWaterfallEntry

@property(nonatomic) int waterfallIndex;
@property(nonatomic) NSString *payload;
@property(nonatomic) NSString *payloadFormat;
@property(nonatomic) NSString *auctionId;
@property(nonatomic) NSString *impressionPayload;
@property(nonatomic) NSString *providerId;

- (instancetype)initWithProvider:(id <SMProviderProtocol>)provider
               providerPlacement:(NSString *)providerPlacement
                       forAdType:(AdTypeEnum)adType;

@end

#endif /* SMRTBWaterfallEntry_h */
