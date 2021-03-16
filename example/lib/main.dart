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
      iosApplicationId: 'sm-9498217944987982-3021189126',
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

  const _Body({Key? key, required this.initialize}) : super(key: key);

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
            ElevatedButton(
              child: Text('call setHasGDPRConsent'),
              onPressed: () {
                ScaleMonk.setHasGDPRConsent(status: true);
              },
            ),
            ElevatedButton(
              child: Text('call setUserCantGiveGDPRConsent'),
              onPressed: () {
                ScaleMonk.setUserCantGiveGDPRConsent(status: false);
              },
            ),
            ElevatedButton(
              child: Text('call setIsApplicationChildDirected'),
              onPressed: () {
                ScaleMonk.setIsApplicationChildDirected(true);
              },
            ),
            ElevatedButton(
              child: Text('requestTrackingAuthorization'),
              onPressed: () async {
                final res = await ScaleMonk.requestTrackingAuthorization();
                print('requestTrackingAuthorization = $res');
              },
            ),
            ElevatedButton(
              child: Text('isRewardedReadyToShow'),
              onPressed: () async {
                final res = await ScaleMonk.isRewardedReadyToShow(tag: 'tag');
                print('isRewardedReadyToShow = $res');
              },
            ),
            _showAd('Interstitial', AdType.interstitial),
            _showAd('Reward', AdType.reward),
            SMBanner(),
            ElevatedButton(
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

  ElevatedButton _showAd(String name, AdType type) {
    return ElevatedButton(
      child: Text('Show $name Ad'),
      onPressed: () {
        ScaleMonk.show(type, tag: 'tag');
      },
    );
  }
}
