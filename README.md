# [ScaleMonk Ads](https://scalemonk.github.io/mediation-docs/#/)

[![Pub Version](https://img.shields.io/pub/v/scale_monk?color=blue)](https://pub.dev/packages/scale_monk)
[![ISC License](https://img.shields.io/npm/l/vimdb?color=important)](LICENSE)

A Flutter plugin to display ads from ScaleMonk. It currently supports __Banner__, __Interstitial__ and __Reward__ ads.

**Note: Currently only iOS platform is supported.**

## ⚙️ Installation

**[ScaleMonk Docs](https://scalemonk.github.io/mediation-docs/#/)**

1. Add the dependency to the `pubspec.yaml` file in your project:

```yaml
dependencies:
  scale_monk: any
```

2. Install the plugin by running the command below in the terminal, in your project's root directory:

```
$ flutter pub get
```

### iOS

Admob 7.42.0 requires the App ID to be included in `Info.plist`. Failure to do so will result in a crash on launch of your app.\
The lines should look like:
```xml
<key>GADApplicationIdentifier</key>
<string>[ADMOB_APP_ID]</string>
```

On your Podfile:

Ensure that the iOS version specified on the Podfile is at least 10.0:

```ruby
platform :ios, '10.0'
```

add these lines:

```ruby
post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      if ['RxSwift', 'Willow'].include? target.name
        config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
      end
    end
  end
end
```

## 📱 Usage

### Initialization

You can initialize ScaleMonk with the function:

```dart
// Initialize ScaleMonk
await ScaleMonk.initialize(
    androidApplicationId: '<your-scaleMonk-android-id>',
    iosApplicationId: '<your-scaleMonk-ios-id>',
);
// At this point you are ready to display ads
```

## 👮🏾‍♂️ Consent to track the user

Before you initialize the plugin and start displaying ads, you might need to collect the user's consent to be tracked online, depending on his location or the operating system that he is using.

### For iOS 14+ only

Follow the [iOS 14+ Support Guide](https://scalemonk.github.io/mediation-docs/#/mediation-sdk-ios/ios14?id=ios-14-support)


Since iOS 14+ you are required to request a specific permission before you can have access to Apple's IDFA (a sort of proprietary cookie used by Apple to track users among multiple advertisers. To request this permission call the function `ScaleMonk.requestTrackingAuthorization()`:

```dart
// iOS 14+: request permission to track users
// on iOS <= 13 and Android this function does nothing; it just returns true
await ScaleMonk.requestTrackingAuthorization();
```

For iOS versions before 14 and for Android devices this function won't do anything, so it's safe to call it on any device OS or version.

## GDPR

To comply with General Data Protection Regulation (GDPR) you'll have to provide the consent status of your users. If consent is given, the partners' mediation providers will be able to send targeted ads.

By sending true the user accepts to share information to receive targeted ads. By sending false the user doesn't give consent to receive targeted ads.

```dart
ScaleMonk.setHasGDPRConsent(status: Bool)
```

If the user is under the age of consent call this method with YES, otherwise you can call this method using false.\
If you don't call this method we assume the user is not under the age of consent and you have to send whether the user accepted or not the consent
```dart
ScaleMonk.setUserCantGiveGDPRConsent(status: Bool)
```

## COPPA: Child Directed Treatment

This method allows you to specify whether you would like your app to be treated as child-directed for purposes of the Children’s Online Privacy Protection Act (COPPA)

```dart
ScaleMonk.setIsApplicationChildDirected(Bool)
```

## 💵 Showing ads

After you collect all the permissions and the plugin properly initialized, you are ready to display the ads:

### Banner, Interstitial & Reward ads

To show an banner, interstitial or reward ad, call the function `ScaleMonk.show()` passing the type of ad that you would like to show as a paremeter (mandatory) and the Tag (optional)

```dart
ScaleMonk.show(AdType.banner, tag: "optional-tag");
ScaleMonk.show(AdType.interstitial, tag: "optional-tag");
ScaleMonk.show(AdType.reward, tag: "optional-tag");
```

### Close Banner

```dart
ScaleMonk.stopLoadingBanners();
```

### Checking if the rewarded video is ready to be shown

You'll likely want to check availability before offering the user the possibility of seeing an ad to get a reward using this method:\
Note that the rewarded video caching doesn't depend on a specific tag so this parameter is optional.

```dart
ScaleMonk.isRewardedReadyToShow(tag: "optional-tag");
```

## ♻️ Callbacks

You can define callbacks to your ads and track when an event occurs; it can be done by calling the callback below:

```dart
ScaleMonk.setBannerCallback = (BannerAdEvent event) {};
ScaleMonk.setInterstitialCallback = (InterstitialAdEvent event) {};
ScaleMonk.setRewardCallback = (RewardedVideoAdEvent event) {};
```

And if later I don't want to track reward events anymore, I just need to pass the value `null` to the same callback:

```dart
 ScaleMonk.setRewardCallback = null;
```

## 📝 License

**scalemonk** is released under the ISC License. See [LICENSE](LICENSE) for details.

## 👨🏾‍💻 Author

Giovani Lobato ([GitHub](https://github.com/thize))
