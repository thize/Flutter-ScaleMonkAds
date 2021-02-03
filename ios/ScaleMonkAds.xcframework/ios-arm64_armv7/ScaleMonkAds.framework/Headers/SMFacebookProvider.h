//  SMFacebookProvider.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import "SMProviderProtocol.h"
#import "SMInterstitialProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBannerView.h"
#import "SMVideoProtocol.h"
#import "AuctionProviderProtocol.h"

@class SMProviderCallbacks;

@interface SMFacebookProvider : NSObject <SMProviderProtocol, SMInterstitialProtocol, SMBannerProtocol, SMVideoProtocol, AuctionProviderProtocol>

@property (weak) SMProviderCallbacks* callbacks;

+ (SMFacebookProvider*) facebookDefault;

@end

@interface SMFacebookBannerView : UIView <SMBannerViewProtocol>

@property (nonatomic) UIViewController* viewController;
@property (nonatomic) bool isLoaded;
@property (nonatomic) NSString* bannerLocation;
@property (nonatomic) SMBannerView* owner;

- (instancetype) initWithPlacementId:(NSString*)bannerPlacementId;

@end

