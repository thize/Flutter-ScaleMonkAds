//  AuctionProviderProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import "SMAdsConstants.h"

@protocol AuctionProviderProtocol <NSObject>
@required
- (NSDictionary<NSString *, NSObject *>*)providerDataForAdType:(AdTypeEnum)adType;
@end
