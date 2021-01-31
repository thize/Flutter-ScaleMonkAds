//  SMBannerProtocol.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMBannerViewProtocol.h"
#import "SMWaterfallEntry.h"
#import "SMBannerView.h"

@protocol SMBannerProtocol <NSObject>

/**
 Triggers the provider display of a banner ad.

 @param attProvider The attributed provider instance.
 @param tag The game tag from where the ad will be displayed (like menu or store).
 @param view The view where the banner will be displayed into.
 */
- (void)showBannerForAttrProvider:(SMWaterfallEntry*)attProvider
                       withTag:(NSString*)tag
                throughBannerView:(SMBannerView*)view;

/**
 Clears the view controller state related to this provider banner instance.
 */
- (void)clearBannerState;

/**
 Triggers the provider banner ad close.

 @param attr The attributed provider instance.
 */
- (void)closeBannerForAttrProvider:(SMWaterfallEntry*)attr;

@end
