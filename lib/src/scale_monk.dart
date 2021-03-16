library scale_monk;

import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

part 'banner_view.dart';
part 'types.dart';

class ScaleMonk {
  static String? _iosApplicationId;
  static Function(BannerAdEvent)? _bannerAdEventListener;
  static Function(InterstitialAdEvent)? _interstitialAdEventListener;
  static Function(RewardedVideoAdEvent)? _rewardAdEventListener;

  static const MethodChannel _channel = MethodChannel('scale_monk');

  static ValueNotifier<bool> _initialized = ValueNotifier<bool>(false);

  //! ScaleMonk

  /// ScaleMonkAds uses your unique applicationId to
  /// identify your app. To obtain this id, go to the
  /// ScaleMonk Dashboard, in the menu select Manage > Applications
  /// and copy the application id of your app.
  static Future<bool> initialize({String? iosApplicationId}) async {
    _iosApplicationId = iosApplicationId;
    // Register the callbacks
    _setCallbacks();
    _initialized.value = await _channel.invokeMethod('initialize', {
      'iosApplicationId': _iosApplicationId,
    }) as bool;
    return _initialized.value;
  }

  /// Shows an ad of certain type [adType].
  ///
  /// Use the constants in the class `AdType` to specify what ad should be shown.
  ///
  /// Returns `true` if the ad is shown.
  static void show(AdType adType, {String? tag}) {
    _channel.invokeMethod('show', {
      'adType': adType.index + 1,
      'tag': tag,
    });
  }

  /// You'll likely want to check availability before offering
  /// the user the possibility of seeing an ad to get a reward using this method
  static Future<bool> isRewardedReadyToShow({String? tag}) async {
    return await _channel.invokeMethod('isRewardedReadyToShow', {
      'tag': tag,
    }) as bool;
  }

  /// This removes the current `Banner` and stop loading more banners.
  static void stopLoadingBanners() {
    _channel.invokeMethod('stopLoadingBanners');
  }

  /// In order to facilitate compliance with General Data Protection Regulation (GDPR),
  /// this method takes the consent status of users. If consent is given,
  /// the partners mediation providers will be able to send targeted ads.

  /// By sending YES user accepts to share information to receive
  /// tarheted ads. By sending NO user accepts to share information
  /// to receive tarheted ads.
  static void setHasGDPRConsent({required bool status}) {
    _channel.invokeMethod('setHasGDPRConsent', {
      'status': status,
    });
  }

  /// If the user is under age of consent call this method with [YES],
  /// otherwise you can call this method with false. If you dont call
  /// this method we assume the user is not under age of consent and
  /// you have to send whether the user accpeted or not the consent
  static void setUserCantGiveGDPRConsent({required bool status}) {
    _channel.invokeMethod('setUserCantGiveGDPRConsent', {
      'status': status,
    });
  }

  /// This method allows you to specify whether you would like your
  /// app to be treated as `child-directed` for purposes of the `Children’s`
  /// `Online Privacy Protection Act (COPPA)`.
  /// `http://business.ftc.gov/privacy-and-security/childrens-privacy`

  /// If you call this method with [YES], you are indicating that your app
  /// should be treated as child-directed for purposes of
  /// the `Children’s Online Privacy Protection Act (COPPA)`
  static void setIsApplicationChildDirected(bool value) {
    _channel.invokeMethod('setIsApplicationChildDirected', {
      'value': value,
    });
  }

  //! Tracking Authorization
  static Future<bool> requestTrackingAuthorization() async {
    return await _channel.invokeMethod('requestTrackingAuthorization') as bool;
  }

  //! Callbacks

  static void _setCallbacks() {
    _channel.setMethodCallHandler((call) {
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
