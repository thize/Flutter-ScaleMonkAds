//  SMBannerViewProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
@import UIKit;

@class SMBannerView;


@protocol SMBannerViewProtocol <NSObject>


@property (nonatomic) UIViewController* viewController;
@property (nonatomic) bool isLoaded;
@property (nonatomic) NSString* bannerTag;
@property (nonatomic) SMBannerView* owner;


- (void) requestLoad;
- (void) notifyBannerShown;

@end
