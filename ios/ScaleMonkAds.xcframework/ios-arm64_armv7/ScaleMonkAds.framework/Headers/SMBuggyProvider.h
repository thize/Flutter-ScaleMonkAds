//  SMBuggyProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#if DEBUG

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#import "SMVideoProtocol.h"

@interface SMBuggyProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol>
- (instancetype)initBuggyWithCache:(bool)cache;
@end

#endif
