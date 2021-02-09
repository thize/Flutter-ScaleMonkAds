//  ScalemonkAds.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// http://www.scalemonk.com/legal/en-US/mediation-license-agreement 
//

#import <Foundation/Foundation.h>

//! Project version number for Mediation.
FOUNDATION_EXPORT double MediationVersionNumber;

//! Project version string for Mediation.
FOUNDATION_EXPORT const unsigned char MediationVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <Mediation/PublicHeader.h>


/// Public
#import "SMAds.h"
#import "SMAnalyticsListener.h"
#import "SMBannerAdEventListener.h"
#import "SMBannerView.h"
#import "SMInterstitialAdEventListener.h"
#import "SMRewardedVideoAdEventListener.h"

/// Private
#import "SMBannerViewProtocol.h"
#import "SMMonitoringReachability.h"
#import "AuctionProviderProtocol.h"
#import "ExecuteWithObjCExceptionHandling.h"
#import "SMAdsConstants.h"
#import "SMAdsRTBLoggerProtocol.h"
#import "SMBannerProtocol.h"
#import "SMBuggyProvider.h"
#import "SMInterstitialProtocol.h"
#import "SMProviderCallbacks.h"
#import "SMProviderProtocol.h"
#import "SMProvidersSetup.h"
#import "SMRTBWaterfallEntry.h"
#import "SMVideoProtocol.h"
#import "SMWaterfallEntry.h"
#import "SMAdMobProvider.h"
#import "SMApplovinAdloadDelegate.h"
#import "SMAppLovinInterstitialDelegate.h"
#import "SMAppLovinProvider.h"
#import "SMAppLovinVideoDelegate.h"
#import "SMFacebookProvider.h"
#import "SMUnityAdsProvider.h"
#import "SMVungleProvider.h"