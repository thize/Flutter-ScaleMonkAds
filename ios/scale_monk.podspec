#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint scale_monk.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'scale_monk'
  s.version          = '1.0.0'
  s.summary          = 'A Flutter plugin to display ads from ScaleMonk.'
  s.description      = <<-DESC
A Flutter plugin to display ads from ScaleMonk; it supports the new reqs for iOS 14+ and GDPR/CCPA consent.
                       DESC
  s.homepage         = 'https://pub.dev/packages/scalemonk'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Giovani Lobato' => 'thizeml@gmail.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '10.0'
  s.requires_arc = true

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.1'

  # ScaleMonkAds
  s.static_framework = true
  s.vendored_framework = 'ScaleMonkAds.xcframework', 'SMAnalytics.framework', 'SMDeviceInfo.framework', 'SMAdsRenderer.framework', "ScaleMonkAds_AdColony/ScaleMonkAds_AdColony.xcframework", "ScaleMonkAds_AdMob/ScaleMonkAds_AdMob.xcframework", "ScaleMonkAds_Amazon/ScaleMonkAds_Amazon.xcframework", "ScaleMonkAds_AppLovin/ScaleMonkAds_AppLovin.xcframework", "ScaleMonkAds_AppLovinMediation/ScaleMonkAds_AppLovinMediation.xcframework", "ScaleMonkAds_Chartboost/ScaleMonkAds_Chartboost.xcframework", "ScaleMonkAds_Facebook/ScaleMonkAds_Facebook.xcframework", "ScaleMonkAds_Fyber/ScaleMonkAds_Fyber.xcframework", "ScaleMonkAds_InMobi/ScaleMonkAds_InMobi.xcframework", "ScaleMonkAds_IronSource/ScaleMonkAds_IronSource.xcframework", "ScaleMonkAds_MoPub/ScaleMonkAds_MoPub.xcframework", "ScaleMonkAds_Renderer/ScaleMonkAds_Renderer.xcframework", "ScaleMonkAds_Smaato/ScaleMonkAds_Smaato.xcframework", "ScaleMonkAds_Tapjoy/ScaleMonkAds_Tapjoy.xcframework", "ScaleMonkAds_Tiktok/ScaleMonkAds_Tiktok.xcframework", "ScaleMonkAds_UnityAds/ScaleMonkAds_UnityAds.xcframework", "ScaleMonkAds_Vungle/ScaleMonkAds_Vungle.xcframework"
  
  s.frameworks = 'iAd', 'WebKit', 'CoreTelephony', 'SystemConfiguration', 'AdSupport'
  
  s.dependency 'UAObfuscatedString', '~> 0.3.2'
  s.dependency 'DTFoundation/DTASN1', '1.7.13'
  
  s.dependency 'RxSwift', '~> 5'
  s.dependency 'Willow', '~> 5.0'
  
  s.dependency 'GoogleAds-IMA-iOS-SDK', '3.11.3'
  s.dependency 'AdColony', '4.3.1'
  s.dependency 'Google-Mobile-Ads-SDK', '7.69.0'
  s.dependency 'AmazonPublisherServicesSDK', '3.2.1'
  s.dependency 'AppLovinSDK', '6.15.1'
  s.dependency 'AppLovinMediationAdColonyAdapter', '4.3.1.0'
  s.dependency 'AppLovinMediationByteDanceAdapter', '3.3.6.2.0'
  s.dependency 'AppLovinMediationChartboostAdapter', '8.4.0.1'
  s.dependency 'AppLovinMediationFacebookAdapter', '6.2.1.0'
  s.dependency 'AppLovinMediationFyberAdapter', '7.8.0.0'
  s.dependency 'AppLovinMediationGoogleAdapter', '7.69.0.1'
  s.dependency 'AppLovinMediationInMobiAdapter', '9.1.1.1'
  s.dependency 'AppLovinMediationIronSourceAdapter', '7.0.3.0.2'
  s.dependency 'AppLovinMediationSmaatoAdapter', '21.6.10.0'
  s.dependency 'AppLovinMediationTapjoyAdapter', '12.7.0.0'
  s.dependency 'AppLovinMediationUnityAdsAdapter', '3.5.1.1'
  s.dependency 'AppLovinMediationVungleAdapter', '6.8.1.0'
  s.dependency 'ChartboostSDK', '8.4.0'
  s.dependency 'FBAudienceNetwork', '6.2.1'
  s.dependency 'Fyber_Marketplace_SDK', '7.8.0'
  s.dependency 'InMobiSDK', '9.1.1'
  s.dependency 'IronSourceSDK', '7.0.3'
  s.dependency 'mopub-ios-sdk/Core', '5.14.1'
  s.dependency 'smaato-ios-sdk', '21.6.10'
  s.dependency 'TapjoySDK', '12.7.0'
  s.dependency 'Bytedance-UnionAD', '3.3.6.2'
  s.dependency 'UnityAds', '3.5.1'
  s.dependency 'VungleSDK-iOS', '6.8.1'
end
