import 'package:flutter/material.dart';
import 'package:scale_monk/scale_monk.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  bool initialize = false;

  @override
  void initState() {
    super.initState();
    initScaleMonk();
  }

  Future initScaleMonk() async {
    ScaleMonk.setBannerCallback = (BannerAdEvent event) {
      print('Banner ad triggered the event $event');
    };
    ScaleMonk.setInterstitialCallback = (InterstitialAdEvent event) {
      print('Interstitial ad triggered the event $event');
    };
    ScaleMonk.setRewardCallback = (RewardedVideoAdEvent event) {
      print('Reward ad triggered the event $event');
    };
    initialize = await ScaleMonk.initialize(
      androidApplicationId: 'sm-9999999-99999999',
      iosApplicationId: 'sm-test-app-scalemonk-6407705726',
    );
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: const Text('ScaleMonk Example App')),
        body: _Body(initialize: initialize),
      ),
    );
  }
}

class _Body extends StatefulWidget {
  final bool initialize;

  const _Body({Key key, @required this.initialize}) : super(key: key);

  @override
  __BodyState createState() => __BodyState();
}

class __BodyState extends State<_Body> {
  bool shouldShow = false;

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Text('initialize = ${widget.initialize}'),
            RaisedButton(
              child: Text('call setHasGDPRConsentWithStatus'),
              onPressed: () {
                ScaleMonk.setHasGDPRConsentWithStatus(true);
              },
            ),
            RaisedButton(
              child: Text('call setIsApplicationChildDirected'),
              onPressed: () {
                ScaleMonk.setIsApplicationChildDirected(true);
              },
            ),
            RaisedButton(
              child: Text('call setUserCantGiveGDPRConsentWithStatus'),
              onPressed: () {
                ScaleMonk.setUserCantGiveGDPRConsentWithStatus(true);
              },
            ),
            RaisedButton(
              child: Text('requestTrackingAuthorization'),
              onPressed: () async {
                final dyn = await ScaleMonk.requestTrackingAuthorization();
                print('dyn = $dyn');
              },
            ),
            RaisedButton(
              child: Text('isRewardedReadyToShow'),
              onPressed: () async {
                final dyn =
                    await ScaleMonk.isRewardedReadyToShow(andTag: 'andTag');
                print('isRewardedReadyToShow = $dyn');
              },
            ),
            _showAd('Banner', AdType.banner),
            _showAd('Interstitial', AdType.interstitial),
            _showAd('Reward', AdType.reward),
            RaisedButton(
              child: Text('stopLoadingBanners'),
              onPressed: () {
                ScaleMonk.stopLoadingBanners();
              },
            ),
            SizedBox(height: 50),
          ],
        ),
      ),
    );
  }

  RaisedButton _showAd(String name, AdType type) {
    return RaisedButton(
      child: Text('Show $name Ad'),
      onPressed: () {
        ScaleMonk.show(type, andTag: 'andTag');
      },
    );
  }
}
