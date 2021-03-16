part of 'scale_monk.dart';

class SMBanner extends StatelessWidget {
  const SMBanner({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ValueListenableBuilder(
      valueListenable: ScaleMonk._initialized,
      builder: (c, bool initialized, w) {
        if (initialized) return _BannerView();
        return SizedBox();
      },
    );
  }
}

class _BannerView extends StatefulWidget {
  const _BannerView({Key? key}) : super(key: key);

  @override
  __BannerViewState createState() => __BannerViewState();
}

class __BannerViewState extends State<_BannerView> {
  final _channel = new MethodChannel('plugins.com.scale_monk/banner');

  @override
  void initState() {
    super.initState();
    if (Platform.isIOS) {
      ScaleMonk.show(AdType._banner);
    }
  }

  @override
  void dispose() {
    ScaleMonk.stopLoadingBanners();
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
    return SizedBox(
      height: 50,
      width: 320,
      child: AndroidView(
        viewType: 'plugins.com.scale_monk/banner',
        key: UniqueKey(),
        onPlatformViewCreated: (int i) {
          _channel.invokeMethod('show');
        },
      ),
    );
  }
}
