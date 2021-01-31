//  SMIronSourceProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMVideoProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerViewProtocol.h"

@class SMProviderCallbacks;

@interface SMIronSourceProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol>

@property (weak) SMProviderCallbacks* callbacks;

@property (nonatomic, copy) NSString* appKey;
@property (nonatomic, copy) NSString* segmentId;

@property (nonatomic, copy) NSString* bannerPlacementId;

+ (SMIronSourceProvider*) ironSourceWithAppKey:(NSString*)appKey andSegmentId:(NSString*)segmentId;

@end
