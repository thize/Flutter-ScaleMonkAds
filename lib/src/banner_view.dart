import 'dart:io';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:scale_monk/scale_monk.dart';

class BannerView extends StatefulWidget {
  const BannerView({Key? key}) : super(key: key);

  @override
  _BannerViewState createState() => _BannerViewState();
}

class _BannerViewState extends State<BannerView> {
  final _channel = new MethodChannel('plugins.com.scale_monk/banner');

  @override
  void initState() {
    super.initState();
    if (Platform.isIOS) {
      ScaleMonk.show(AdType.banner);
    }
  }

  @override
  void dispose() {
    try {
      ScaleMonk.stopLoadingBanners();
    } catch (_) {}
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    if (Platform.isIOS) {
      return SizedBox(
        height: 50,
        width: 320,
      );
    }
    return Container(
      height: 50,
      width: 320,
      color: Colors.yellow,
      child: AndroidView(
        viewType: 'plugins.com.scale_monk/banner',
        key: UniqueKey(),
        creationParams: {'Id': 1},
        creationParamsCodec: StandardMessageCodec(),
        onPlatformViewCreated: (int i) {
          Future.delayed(const Duration(seconds: 8)).whenComplete(() {
            _channel.invokeMethod('show');
          });
        },
      ),
    );
  }
}
