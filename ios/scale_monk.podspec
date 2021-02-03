#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint scale_monk.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'scale_monk'
  s.version          = '0.1.1'
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
  s.static_framework = true
  s.requires_arc = true

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.1'

  # ScaleMonkAds
  s.frameworks = 'iAd', 'WebKit', 'CoreTelephony', 'SystemConfiguration', 'AdSupport'
  
  s.dependency 'RxSwift', '~> 5'
  s.dependency 'Willow', '~> 5.0'
  
  s.dependency 'Google-Mobile-Ads-SDK', '7.64.0'
  s.dependency 'AppLovinSDK', '6.14.5'
  s.dependency 'FBAudienceNetwork', '6.2.0'
  s.dependency 'IronSourceSDK', '7.0.3.0'
  s.dependency 'UnityAds', '3.5.1'
  s.dependency 'VungleSDK-iOS', '6.8.0'

  s.preserve_paths = 'ScaleMonkAds.xcframework'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-framework ScaleMonkAds' }
  s.vendored_frameworks = 'ScaleMonkAds.xcframework'

  s.preserve_paths = 'SMAnalytics.framework'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-framework SMAnalytics' }
  s.vendored_frameworks = 'SMAnalytics.framework'

  s.preserve_paths = 'SMDeviceInfo.framework'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-framework SMDeviceInfo' }
  s.vendored_frameworks = 'SMDeviceInfo.framework'
end
