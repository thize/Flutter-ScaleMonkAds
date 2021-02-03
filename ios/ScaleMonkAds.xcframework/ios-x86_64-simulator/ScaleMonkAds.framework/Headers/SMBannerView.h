//  SMBannerView.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef bool (^BannerConditionsBlock)(void);

@protocol SMBannerViewProtocol;

@interface SMBannerView : UIView

@property(nonatomic) IBOutlet UIViewController *viewController;
@property(nonatomic, copy) NSString *location;
@property(nonatomic) UIView <SMBannerViewProtocol> *providerBannerView;

@end
