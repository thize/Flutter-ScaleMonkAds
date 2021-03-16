part of 'scale_monk.dart';

AdType adTypeFromString(String st) =>
    _stringToEnum(st: st, values: AdType.values) as AdType;

enum AdType {
  _banner,
  interstitial,
  reward,
}

RewardedVideoAdEvent rewardedVideoAdEventFromString(String st) =>
    _stringToEnum(st: st, values: RewardedVideoAdEvent.values)
        as RewardedVideoAdEvent;

enum RewardedVideoAdEvent {
  ///	The user clicks to see an Ad
  click,

  ///	The Ad starts to show
  viewStart,

  ///	The Ad was closed before getting the reward
  finishWithNoReward,

  ///	The Ad was closed with reward
  finishWithReward,

  ///	The Ad fails to be shown
  fail,

  ///	The Ad is ready to be shown
  ready,
}

InterstitialAdEvent interstitialAdEventFromString(String st) =>
    _stringToEnum(st: st, values: InterstitialAdEvent.values)
        as InterstitialAdEvent;

enum InterstitialAdEvent {
  /// The user clicks to see an Ad
  click,

  /// The Ad starts to show
  viewStart,

  /// The user close the Ad
  view,

  /// The Ad fails to be shown
  fail,

  /// The Ad is ready to be shown
  ready,
}

BannerAdEvent bannerAdEventFromString(String st) =>
    _stringToEnum(st: st, values: BannerAdEvent.values) as BannerAdEvent;

enum BannerAdEvent {
  /// Fails to show banner
  fail,

  /// The Ad was shown
  completed,
}

dynamic _stringToEnum({required String st, required List<dynamic> values}) {
  final fixed = st = st[0].toLowerCase() + st.substring(1);
  final first = values.first.toString();
  final String enumType = first.substring(0, first.indexOf('.') + 1);
  final String strRes = '$enumType$fixed';
  final enumRes =
      values.firstWhere((e) => e.toString() == strRes, orElse: () => null);
  return enumRes ?? values.first;
}
