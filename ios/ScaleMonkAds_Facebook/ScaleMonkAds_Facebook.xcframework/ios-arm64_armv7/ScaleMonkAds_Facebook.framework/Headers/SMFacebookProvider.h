//  SMFacebookProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>

#ifdef SM_MEDIATION_FRAMEWORK
@import ScaleMonkAds;
#else
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#import "SMVideoProtocol.h"
#import "AuctionProviderProtocol.h"
#endif



@class SMProviderCallbacks;

@interface SMFacebookProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol, AuctionProviderProtocol>

@property (weak) SMProviderCallbacks* callbacks;

@end

@interface SMFacebookBannerView : UIView <SMBannerViewProtocol>

@property (nonatomic) UIViewController* viewController;
@property (nonatomic) bool isLoaded;
@property (nonatomic) NSString* bannerLocation;
@property (nonatomic) SMBannerView* owner;

@end

