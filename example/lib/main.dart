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
    initScaleMonk();
    super.initState();
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
      // TODO: androidApplicationId
      androidApplicationId: 'sm-9999999-99999999',
      // TODO: iosApplicationId
      iosApplicationId: 'sm-0000000-00000000',
    );
    print('initialize = $initialize');
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
              child: Text('call setHasGDPRConsent'),
              onPressed: () async {
                await ScaleMonk.setHasGDPRConsent();
              },
            ),
            RaisedButton(
              child: Text('call setIsApplicationChildDirected'),
              onPressed: () async {
                await ScaleMonk.setIsApplicationChildDirected();
              },
            ),
            RaisedButton(
              child: Text('call setUserCantGiveGDPRConsent: true'),
              onPressed: () async {
                await ScaleMonk.setUserCantGiveGDPRConsent(hasConsent: true);
              },
            ),
            _showAd('Banner', AdType.banner),
            _showAd('Interstitial', AdType.interstitial),
            _showAd('Reward', AdType.reward),
          ],
        ),
      ),
    );
  }

  RaisedButton _showAd(String name, AdType type) {
    return RaisedButton(
      child: Text('Show $name Ad'),
      onPressed: () async {
        var status = await ScaleMonk.show(AdType.reward, tag: 'tag-example');
        print('$name Ad, show = $status');
      },
    );
  }
}
