AdType adTypeFromString(String st) =>
    _stringToEnum(st: st, values: AdType.values) as AdType;

enum AdType {
  banner,
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
  String aux = st;
  for (var i = 1; i < aux.length; i++) {
    if (aux[i] == aux[i].toUpperCase()) {
      aux = '${aux[0].toLowerCase()}${aux.substring(1)}';
      i++;
    }
  }
  final String enumType = aux.substring(0, aux.indexOf('.') + 1);
  final String strRes = '$enumType$aux';
  final enumRes =
      values.firstWhere((e) => e.toString() == strRes, orElse: () => null);
  return enumRes ?? values.first;
}
