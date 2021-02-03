//  SMWaterfallEntry.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMAdsConstants.h"

typedef NS_ENUM(NSInteger, TestMode) {
    TestModeFill,
    TestModeNoFill,
    TestModeTimeOut,
    TestModeNone,
    TestModeVerbose
};

@interface SMWaterfallEntry : NSObject

@property (nonatomic, strong) NSString *providerPlacement;
@property (nonatomic, strong) NSString *customName;
@property (nonatomic) id<SMProviderProtocol> provider;
@property (nonatomic) AdTypeEnum adType;
@property (nonatomic) TestMode testMode;

/**
 Initializes a SMWaterfallEntry instance using a tuple {provider instance, placement, ad type}

 @param provider The provider instance.
 @param providerPlacement The placement id.
 @param adType The ad format.

 @return The initialized SMWaterfallEntry instance.
 */
- (instancetype)initWithProvider:(id<SMProviderProtocol>)provider
               providerPlacement:(NSString*)providerPlacement
                       forAdType:(AdTypeEnum)adType;

/**
 Initializes a SMWaterfallEntry instance using a tuple {provider instance, placement, ad type} and
 a custom name.

 @param provider The provider instance.
 @param providerPlacement The placement id.
 @param adType The ad format.
 @param customName A custom name.

 @return The initialized SMWaterfallEntry instance with a custom name.
 */
- (instancetype)initWithProvider:(id<SMProviderProtocol>)provider
               providerPlacement:(NSString*)providerPlacement
                       forAdType:(AdTypeEnum)adType
                  withCustomName:(NSString*)customName;


- (NSString*)name;

- (bool)isRTB;

@end
