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
  s.vendored_framework = 'ScaleMonkAds.xcframework', 'SMAnalytics.framework', 'SMDeviceInfo.framework', "ScaleMonkAds_AdMob/ScaleMonkAds_AdMob.xcframework", "ScaleMonkAds_AppLovin/ScaleMonkAds_AppLovin.xcframework", "ScaleMonkAds_Facebook/ScaleMonkAds_Facebook.xcframework", "ScaleMonkAds_IronSource/ScaleMonkAds_IronSource.xcframework", "ScaleMonkAds_UnityAds/ScaleMonkAds_UnityAds.xcframework", "ScaleMonkAds_Vungle/ScaleMonkAds_Vungle.xcframework"
  
  s.frameworks = 'iAd', 'WebKit', 'AppTrackingTransparency', 'CoreTelephony', 'SystemConfiguration', 'AdSupport'
  
  s.dependency 'UAObfuscatedString', '~> 0.3.2'
  s.dependency 'DTFoundation/DTASN1', '1.7.13'
  
  s.dependency 'RxSwift', '~> 5'
  s.dependency 'Willow', '~> 5.0'
  
  s.dependency 'Google-Mobile-Ads-SDK', '7.69.0'
  s.dependency 'AppLovinSDK', '6.15.1'
  s.dependency 'FBAudienceNetwork', '6.2.1'
  s.dependency 'IronSourceSDK', '7.0.3'
  s.dependency 'UnityAds', '3.5.1'
  s.dependency 'VungleSDK-iOS', '6.8.1'
end
