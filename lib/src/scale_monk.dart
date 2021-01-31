library scale_monk;

import 'package:flutter/services.dart';
import 'package:scale_monk/scale_monk.dart';

class ScaleMonk {
  static String? _androidApplicationId;
  static String? _iosApplicationId;
  static Function(BannerAdEvent)? _bannerAdEventListener;
  static Function(InterstitialAdEvent)? _interstitialAdEventListener;
  static Function(RewardedVideoAdEvent)? _rewardAdEventListener;

  static const MethodChannel _channel = MethodChannel('scale_monk');

  //! ScaleMonk

  /// Define the ScaleMonk App Id for Android and iOS. At least one of the keys must be set, otherwise an error will be
  /// thrown during the initialization.
  static void setApplicationIds(
      {String? androidApplicationId, String? iosApplicationId}) {
    _androidApplicationId = androidApplicationId;
    _iosApplicationId = iosApplicationId;
  }

  /// Initialize the ScaleMonk plugin.
  static Future<bool> initialize() async {
    assert(_androidApplicationId != null || _iosApplicationId != null,
        'You must set at least one of the keys for Android or iOS');

    // Register the callbacks
    _setCallbacks();

    return await _channel.invokeMethod('initialize', {
      'androidApplicationId': _androidApplicationId,
      'iosApplicationId': _iosApplicationId,
    }) as Future<bool>;
  }

  /// Shows an ad of certain type [adType].
  ///
  /// Use the constants in the class `AdType` to specify what ad should be shown.
  ///
  /// Returns `true` if the ad is shown.
  static Future<bool> show(AdType adType, {String? tag}) async {
    assert(_androidApplicationId != null || _iosApplicationId != null,
        'You must set at least one of the keys for Android or iOS');

    return await _channel.invokeMethod('show', {
      'adType': adType.index,
      'tag': tag,
    }) as Future<bool>;
  }

  /// This removes the current `Banner` and stop loading more banners.
  static Future<bool> stopLoadingBanners() async {
    return await _channel.invokeMethod('stopLoadingBanners') as Future<bool>;
  }

  /// In order to facilitate compliance with General Data Protection Regulation (GDPR),
  /// this method takes the consent status of users. If consent is given,
  /// the partners mediation providers will be able to send targeted ads.

  /// By sending YES user accepts to share information to receive
  /// tarheted ads. By sending NO user accepts to share information
  /// to receive tarheted ads.
  static Future setHasGDPRConsent() async {
    return _channel.invokeMethod('setHasGDPRConsent');
  }

  /// If the user is under age of consent call this method with [YES],
  /// otherwise you can call this method with false. If you dont call
  /// this method we assume the user is not under age of consent and
  /// you have to send whether the user accpeted or not the consent
  static Future setUserCanGiveGDPRConsent({required bool hasConsent}) async {
    return _channel.invokeMethod('setUserCanGiveGDPRConsent', {
      'hasConsent': hasConsent,
    });
  }

  /// This method allows you to specify whether you would like your
  /// app to be treated as `child-directed` for purposes of the `Children’s`
  /// `Online Privacy Protection Act (COPPA)`.
  /// `http://business.ftc.gov/privacy-and-security/childrens-privacy`

  /// If you call this method with [YES], you are indicating that your app
  /// should be treated as child-directed for purposes of
  /// the `Children’s Online Privacy Protection Act (COPPA)`
  static Future setIsApplicationChildDirected() async {
    return _channel.invokeMethod('setIsApplicationChildDirected');
  }

  //! Callbacks

  static void _setCallbacks() {
    _channel.setMethodCallHandler((call) {
      //TODO: remover print no fim de tudo
      print('_setCallbacks call.method = ${call.method}');
      if (call.method.startsWith('onBanner')) {
        _bannerAdEventListener?.call(
          bannerAdEventFromString(call.method.replaceFirst('onBanner', '')),
        );
      } else if (call.method.startsWith('onInterstitial')) {
        _interstitialAdEventListener?.call(
          interstitialAdEventFromString(
              call.method.replaceFirst('onInterstitial', '')),
        );
      } else if (call.method.startsWith('onRewarded')) {
        _rewardAdEventListener?.call(
          rewardedVideoAdEventFromString(
              call.method.replaceFirst('onRewarded', '')),
        );
      }
      return Future.value();
    });
  }

  /// Define a callback to track Banner Ad events.
  ///
  /// It receives a function [callback] with parameter `event` of type `BannerAdEvent`.
  static set setBannerCallback(Function(BannerAdEvent event) callback) {
    _bannerAdEventListener = callback;
  }

  /// Define a callback to track Interstitial Ad events.
  ///
  /// It receives a function [callback] with parameter `event` of type `InterstitialAdEvent`.
  static set setInterstitialCallback(
      Function(InterstitialAdEvent event) callback) {
    _interstitialAdEventListener = callback;
  }

  /// Define a callback to track Reward Ad events.
  ///
  /// It receives a function [callback] with parameter `event` of type `RewardedVideoAdEvent`.
  static set setRewardCallback(Function(RewardedVideoAdEvent event) callback) {
    _rewardAdEventListener = callback;
  }
}
