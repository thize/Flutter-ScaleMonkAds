# ScaleMonk Ads

[![Pub Version](https://img.shields.io/pub/v/scalemonk?color=blue)](https://pub.dev/packages/scale_monk)
[![ISC License](https://img.shields.io/npm/l/vimdb?color=important)](LICENSE)

A Flutter plugin to display ads from ScaleMonk. It currently supports __Banner__, __Interstitial__ and __Reward__ ads.

## ⚙️ Installation

1. Add the dependency to the `pubspec.yaml` file in your project:

```yaml
dependencies:
  scale_monk_ads: any
```

2. Install the plugin by running the command below in the terminal, in your project's root directory:

```
$ flutter pub get
```

3. Follow the ScaleMonk installation instructions available for [iOS](google.com) and [Android](google.com). However, ignore the steps to include the ScaleMonk SDK dependencies in Gradle (Android) and Cocoapods (iOS) since these steps will be done by this package.

### Extra steps for Android only

4. The ScaleMonk framework includes mutiple libraries from different ad providers, so it's very likely that the inclusion of this plugin in your project will make it exceed to 64K limit method count of Android. To solve this problem you need to enable multidex in your project; follow the instructions [here](https://developer.android.com/studio/build/multidex) to learn how to do that.

5. Your Android project must use Gradle 4.0.1 or greater. If you are using an older version, please upgrade it by editing the file `android/build.gradle`.

6. Google Ads Key

### iOS

Admob 7.42.0 requires the App ID to be included in `Info.plist`. Failure to do so will result in a crash on launch of your app. The lines should look like:

```xml
<key>GADApplicationIdentifier</key>
<string>[ADMOB_APP_ID]</string>
```

### Android

Starting in version 17.0.0, if you are an AdMob publisher you are now required to add your AdMob app ID in your **AndroidManifest.xml** file. Once you find your AdMob app ID in the AdMob UI, add it to your manifest adding the following tag:

```xml
<manifest>
    <application>
        <!-- TODO: Replace with your real AdMob app ID -->
        <meta-data
            android:name="com.google.android.gms.ads.APPLICATION_ID"
            android:value="ca-app-pub-################~##########"/>
    </application>
</manifest>
```

## 📱 Usage

Import the plugin as early as possible somewhere in your project (ideally in the file `main.dart`), then initialize the plugin by calling the functions `ScaleMonk.setAppKeys()` and `ScaleMonk.initialize()`:

### Initialization

First you need to set the app keys:

```dart
// Set the ScaleMonk app keys
ScaleMonk.setApplicationIds(
  androidApplicationId: '<your-scaleMonk-android-id>',
  iosApplicationId: '<your-scaleMonk-ios-id>',
);
```

Where `androidAppKey` and `iosAppKey` are the keys associated with your app in your ScaleMonk account. At least one of these keys must be set before the initialization (either Android or iOS), otherwise you will get an error.

Afterwards you can initialize ScaleMonk with the function:

```dart
// Initialize ScaleMonk
await ScaleMonk.initialize();
// At this point you are ready to display ads
```

## 👮🏾‍♂️ Consent to track the user

Before you initialize the plugin and start displaying ads, you might need to collect the user's consent to be tracked online, depending on his location or the operating system that he is using.

### For iOS 14+ only

Since iOS 14+ you are required to request a specific permission before you can have access to Apple's IDFA (a sort of proprietary cookie used by Apple to track users among multiple advertisers... ah Apple, always Apple 🙄). To request this permission call the function `ScaleMonk.requestIOSTrackingAuthorization()`:

```dart
// iOS 14+: request permission to track users
// on iOS <= 13 and Android this function does nothing; it just returns true
await ScaleMonk.requestIOSTrackingAuthorization();
```

For iOS versions before 14 and for Android devices this function won't do anything, so it's safe to call it on any device OS or version.

### For users protected by GDPR/CCPA privacy laws

Depending on the location of your users, they might be protected by the privacy laws GDPR or CCPA. These laws require, among other things, that app developers must collect user consent before the advertisers can track them online. You can check if the user is protected by any privacy laws, by calling the function `ScaleMonk.shouldShowConsent()`:

```dart
bool shouldShow = await ScaleMonk.shouldShowConsent();
if (shouldShow) { /* Request user consent */ }
```

Keep in mind that the function above will also return `false` if the user previously accepted or declined the request to be tracked online. So it's important to always call this function in advance to avoid annoying the user with permission requests that he already answered.

After you determine if you need to request user consent, you have two options to collect this consent:

1. You can design the UI with all the legal information and multiple options to let the user decline, accept or partially accept the options to be tracked. After you collect this information yourself, you then need to pass the value `true` or `false` to the parameter `hasConsent` during the ScaleMonk initialization.

or:

2. You can use the UI provided by the Consent Manager framework. With this option you can't customize the UI used to collect the user consent, however it does the heavy lifting for you of creating and displaying a window with all the legal wording, permission options and everything that is necessary to get the user's permission to be tracked. If you decide to go with option # 2 then you must call two functions:

    2.1. Call the function `ScaleMonk.requestConsentAuthorization()` to display a window requesting the user consent to be tracked:
    ```dart
    await ScaleMonk.requestConsentAuthorization();
    ```

    2.2. After the user grants or decline consent, you can call the function `ScaleMonk.fetchConsentInfo()` to fetch the consent info:
    ```dart
    var consent = await ScaleMonk.fetchConsentInfo();
    var hasConsent = consent.status == ConsentStatus.PERSONALIZED || consent.status == ConsentStatus.PARTLY_PERSONALIZED;
    await ScaleMonk.setHasGDPRConsent(hasConsent: hasConsent)
    ```

## 💵 Showing ads

After you collect all the permissions and the plugin properly initialized, you are ready to display the ads:

### Banner, Interstitial & Reward ads

To show an banner, interstitial or reward ad, call the function `ScaleMonk.show()` passing the type of ad that you would like to show as a paremeter (mandatory) and the [placement name](https://faq.appodeal.com/en/articles/1154394-placements) (optional):

```dart
ScaleMonk.show(AdType.BANNER, tag: "optional-tag"); // Show a banner ad
ScaleMonk.show(AdType.INTERSTITIAL, tag: "optional-tag");  // Show an interstitial ad
ScaleMonk.show(AdType.REWARD, tag: "optional-tag");        // Show a reward ad
```

## ♻️ Callbacks

You can define callbacks to your ads and track when an event occurs; it can be done by calling the callback functions below:

- `ScaleMonk.setBannerCallback((event) {})`
- `ScaleMonk.setInterstitialCallback((event) {})`
- `ScaleMonk.setRewardCallback((event) {})`

And if later I don't want to track reward events anymore, I just need to pass the value `null` to the same callback function:

```dart
ScaleMonk.setRewardCallback(null);
```

## 📝 License

**scalemonk** is released under the ISC License. See [LICENSE](LICENSE) for details.

## 👨🏾‍💻 Author

Giovani Lobato ([GitHub](https://github.com/thize))
