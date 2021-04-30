#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint scale_monk.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'scale_monk'
  s.version          = '1.2.0'
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
  s.vendored_framework = 'ScaleMonkAds_AdColony/ScaleMonkAds_AdColony.xcframework', 'ScaleMonkAds_Fyber/ScaleMonkAds_Fyber.xcframework', 'ScaleMonkAds_Vungle/ScaleMonkAds_Vungle.xcframework', 'ScaleMonkAds-AdMob/ScaleMonkAds-AdMob.xcframework', 'ScaleMonkAds-AppLovin/ScaleMonkAds-AppLovin.xcframework', 'ScaleMonkAds-Facebook/ScaleMonkAds-Facebook.xcframework', 'ScaleMonkAds-IronSource/ScaleMonkAds-IronSource.xcframework', 'ScaleMonkAds-Mintegral/ScaleMonkAds-Mintegral.xcframework', 'ScaleMonkAds-Tapjoy/ScaleMonkAds-Tapjoy.xcframework', 'ScaleMonkAds-UnityAds/ScaleMonkAds-UnityAds.xcframework', 'ScaleMonkAds.xcframework', 'SMAnalytics.framework', 'SMDeviceInfo.framework'
  s.frameworks = 'iAd', 'WebKit', 'AppTrackingTransparency', 'CoreTelephony', 'SystemConfiguration', 'AdSupport'
  
  s.dependency 'UAObfuscatedString', '~> 0.3.2'
  s.dependency 'DTFoundation/DTASN1', '1.7.13'
  
  s.dependency 'RxSwift', '~> 5'
  s.dependency 'Willow', '~> 5.0'
  
  s.dependency 'AdColony', '4.3.1'
  s.dependency 'Google-Mobile-Ads-SDK', '7.69.0'
  s.dependency 'AppLovinSDK', '10.2.0'
  s.dependency 'FBAudienceNetwork', '6.2.1'
  s.dependency 'Fyber_Marketplace_SDK', '7.8.0'
  s.dependency 'IronSourceSDK', '7.1.5.0'
  s.dependency 'VungleSDK-iOS', '6.8.1'
  s.dependency 'MintegralAdSDK', '6.7.6.0'
  s.dependency 'UnityAds', '3.6.0.0'
  s.dependency 'TapjoySDK', '12.7.1'
end
