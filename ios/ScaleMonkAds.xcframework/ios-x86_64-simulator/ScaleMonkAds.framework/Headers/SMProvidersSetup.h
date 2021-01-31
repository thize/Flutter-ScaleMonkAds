//  SMProvidersSetup.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMAdsRTBLoggerProtocol.h"

#if __has_include("SMChartboostProvider.h")
#import "SMChartboostProvider.h"
#define SM_ADS_CHARTBOOST_AVAILABLE
#endif


#if __has_include("SMAppLovinProvider.h")
#import "SMAppLovinProvider.h"
#define SM_ADS_APPLOVIN_AVAILABLE
#endif

#if __has_include("SMAppLovinMediationProvider.h")
#import "SMAppLovinMediationProvider.h"
#define SM_ADS_APPLOVIN_MEDIATION_AVAILABLE
#endif


#if __has_include("SMFyberProvider.h")
#import "SMFyberProvider.h"
#define SM_ADS_FYBER_AVAILABLE
#endif


#if __has_include("SMUnityAdsProvider.h")
#import "SMUnityAdsProvider.h"
#define SM_ADS_UNITYADS_AVAILABLE
#endif


#if __has_include("SMAdColonyProvider.h")
#import "SMAdColonyProvider.h"
#define SM_ADS_ADCOLONY_AVAILABLE
#endif 


#if __has_include("SMVungleProvider.h")
#import "SMVungleProvider.h"
#define SM_ADS_VUNGLE_AVAILABLE
#endif


#if __has_include("SMAdMobProvider.h")
#import "SMAdMobProvider.h"
#define SM_ADS_ADMOB_AVAILABLE
#endif


#if __has_include("SMMopubProvider.h")
#import "SMMopubProvider.h"
#define SM_ADS_MOPUB_AVAILABLE
#endif

#if __has_include("SMMopubMediationProvider.h")
#import "SMMopubMediationProvider.h"
#define SM_ADS_MOPUB_MEDIATION_AVAILABLE
#endif

#if __has_include("SMMintegralProvider.h")
#import "SMMintegralProvider.h"
#define SM_ADS_MINTEGRAL_AVAILABLE
#endif


#if __has_include("SMInMobiProvider.h")
#import "SMInMobiProvider.h"
#define SM_ADS_INMOBI_AVAILABLE
#endif


#if __has_include("SMFacebookProvider.h")
#import "SMFacebookProvider.h"
#define SM_ADS_FACEBOOK_AVAILABLE
#endif

#if __has_include("SMIronSourceProvider.h")
#import "SMIronSourceProvider.h"
#define SM_ADS_IRONSOURCE_AVAILABLE
#endif

#if __has_include("SMSmaatoProvider.h")
#import "SMSmaatoProvider.h"
#define SM_ADS_SMAATO_AVAILABLE
#endif

#if __has_include("SMTapjoyProvider.h")
#import "SMTapjoyProvider.h"
#define SM_ADS_TAPJOY_AVAILABLE
#endif

#if __has_include("SMTiktokProvider.h")
#import "SMTiktokProvider.h"
#define SM_ADS_TIKTOK_AVAILABLE
#endif


#if __has_include("SMMyTargetProvider.h")
#import "SMMyTargetProvider.h"
#define SM_ADS_MYTARGET_AVAILABLE
#endif

#if __has_include("SMAmazonProvider.h")
#import "SMAmazonProvider.h"
#define SM_ADS_AMAZON_AVAILABLE
#endif

#if __has_include("SMGenericProvider.h")
#import "SMGenericProvider.h"
#define SM_ADS_GENERIC_RENDERER_AVAILABLE
#endif

@interface SMProvidersSetup : NSObject

#ifdef SM_ADS_ADCOLONY_AVAILABLE
@property (nonatomic) SMAdColonyProvider* adColony;
#endif

#ifdef SM_ADS_APPLOVIN_AVAILABLE
@property (nonatomic) SMAppLovinProvider* appLovin;
#endif

#ifdef SM_ADS_MINTEGRAL_AVAILABLE
@property (nonatomic) SMMintegralProvider* mintegral;
#endif

#ifdef SM_ADS_APPLOVIN_MEDIATION_AVAILABLE
@property (nonatomic) SMAppLovinMediationProvider* appLovinMediation;
#endif

#ifdef SM_ADS_CHARTBOOST_AVAILABLE
@property (nonatomic) SMChartboostProvider* chartboost;
#endif

#ifdef SM_ADS_UNITYADS_AVAILABLE
@property (nonatomic) SMUnityAdsProvider* unityAds;
#endif

#ifdef SM_ADS_VUNGLE_AVAILABLE
@property (nonatomic) SMVungleProvider* vungle;
#endif

#ifdef SM_ADS_ADMOB_AVAILABLE
@property (nonatomic) SMAdMobProvider* adMob;
#endif

#ifdef SM_ADS_MOPUB_AVAILABLE
@property (nonatomic) SMMopubProvider* mopub;
#endif

#ifdef SM_ADS_MOPUB_MEDIATION_AVAILABLE
@property (nonatomic) SMMopubMediationProvider* mopubMediation;
#endif

#ifdef SM_ADS_INMOBI_AVAILABLE
@property (nonatomic) SMInMobiProvider* inmobi;
#endif

#ifdef SM_ADS_FACEBOOK_AVAILABLE
@property (nonatomic) SMFacebookProvider* facebook;
#endif

#ifdef SM_ADS_FYBER_AVAILABLE
@property (nonatomic) SMFyberProvider* fyber;
#endif

#ifdef SM_ADS_IRONSOURCE_AVAILABLE
@property (nonatomic) SMIronSourceProvider* ironsource;
#endif

#ifdef SM_ADS_SMAATO_AVAILABLE
@property (nonatomic) SMSmaatoProvider* smaato;
#endif

#ifdef SM_ADS_TAPJOY_AVAILABLE
@property (nonatomic) SMTapjoyProvider* tapjoy;
#endif

#ifdef SM_ADS_TIKTOK_AVAILABLE
@property (nonatomic) SMTiktokProvider* tiktok;
#endif

#ifdef SM_ADS_MYTARGET_AVAILABLE
@property (nonatomic) SMMyTargetProvider* mytarget;
#endif

#ifdef SM_ADS_AMAZON_AVAILABLE
@property (nonatomic) SMAmazonProvider* amazon;
#endif

#ifdef SM_ADS_GENERIC_RENDERER_AVAILABLE
@property (nonatomic) SMGenericProvider* genericRenderer;
#endif

/**
 Pass the providers setup configs from RemoteConfig to the providers.

 The configDict parameter is a dictionary representation of the `providersSetup` key from RC where the
 key is the provider id and the value is a dictionary containing multiple {config key, config value}
 entries.

 @param configDict the dictionary with all configurations from all providers.
 @param logger used to track bid request and bid latency events for SDK side RTB providers
 */
- (void)updateWithConfigDict:(NSDictionary*)configDict
                      logger:(id<SMAdsRTBLoggerProtocol>)logger;


/**
 Returns the array of installed providers. A provider is installed if there is a provider entry in the
 podfile and a provider header is found within the application.

 @return Array of all installed providers
 */
- (NSArray*)allProviders;

/**
 Returns a dictionary with a key equal to providers name and value equals to providers object, but only containing providers that supports RTB.

 @return Dictionary with all providers that supports RTB.
 */
- (NSDictionary*)rtbProviders;

@end
