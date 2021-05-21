#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint scale_monk.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'scale_monk'
  s.version          = '1.4.0'
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
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => "i386, arm64" }
  s.swift_version = '5.1'

  # ScaleMonkAds
  s.static_framework = true
  
  s.dependency 'ScaleMonkAds', '1.3.0'
  s.dependency 'ScaleMonkAds-AdColony', '4.3.1.2'
  s.dependency 'ScaleMonkAds-AdMob', '7.69.0.2'
  s.dependency 'ScaleMonkAds-AppLovin', '6.15.2.0'
  s.dependency 'ScaleMonkAds-Chartboost', '8.4.0.1'
  s.dependency 'ScaleMonkAds-Facebook', '6.2.1.2'
  s.dependency 'ScaleMonkAds-Fyber', '7.8.0.1'
  s.dependency 'ScaleMonkAds-InMobi', '9.1.1.3'
  s.dependency 'ScaleMonkAds-IronSource', '7.0.3.1'
  s.dependency 'ScaleMonkAds-Mintegral', '6.7.6.0.1'
  s.dependency 'ScaleMonkAds-Mopub', '5.14.1.2'
  s.dependency 'ScaleMonkAds-Smaato', '21.6.10.1'
  s.dependency 'ScaleMonkAds-Tapjoy', '12.7.0.1'
  s.dependency 'ScaleMonkAds-Tiktok', '3.3.6.3'
  s.dependency 'ScaleMonkAds-UnityAds', '3.6.0.0'
  s.dependency 'ScaleMonkAds-Vungle', '6.8.1.1'
end
