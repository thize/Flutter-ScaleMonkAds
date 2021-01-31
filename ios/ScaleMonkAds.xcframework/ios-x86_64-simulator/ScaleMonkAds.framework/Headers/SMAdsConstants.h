//  SMAdsConstants.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#ifndef _SMADS_Constants_
#define _SMADS_Constants_

#define kProviderAdColony   @"adcolony"
#define kProviderAdMob      @"admob"
#define kProviderAppLovin   @"applovin"
#define kProviderChartboost @"chartboost"
#define kProviderFacebook   @"facebook"
#define kProviderFlurry     @"flurry"
#define kProviderInMobi     @"inmobi"
#define kProviderLeadbolt   @"leadbolt"
#define kProviderMoPub      @"mopub"
#define kProviderTopPromo   @"toppromo"
#define kProviderUnityAds   @"unityads"
#define kProviderVungle     @"vungle"
#define kProviderIronSource @"ironsource"
#define kProviderCrossPromo @"crosspromo"
#define kProviderSmaato     @"smaato"
#define kProviderSurvey     @"supla"
#define kProviderTiktok     @"tiktok"
#define kProviderFyber      @"fyber"
#define kProviderMyTarget   @"mytarget"
#define kProviderMintegral  @"mintegral"
#define kProviderTapjoy     @"tapjoy"
#define kProviderTappx      @"tappx"
#define kProviderScaleMonk  @"scalemonk"
#define kProviderAmazon     @"amazon"
#define kProviderGenericRenderer @"generic"
#define kProviderAppLovinMediation   @"applovinmediation"
#define kProviderMoPubMediation      @"mopubmediation"


typedef enum {
    /**
     Unknown ad type, used as default.
     */
    AdTypeUnknown = 0,
    /**
     Banner ad format.
     */
    AdTypeBanner,
    /**
     Interstitial ad format.
     */
    AdTypeInterstitial,
    /**
     Rewarded video ad format.
     */
    AdTypeRewardedVideo,
} AdTypeEnum;

#endif
