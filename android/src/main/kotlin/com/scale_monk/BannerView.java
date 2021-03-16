package com.scale_monk;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.scalemonk.ads.ScaleMonkAds;
import com.scalemonk.libs.ads.core.domain.banner.BannerContainer;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;

import static android.content.Context.LAYOUT_INFLATER_SERVICE;
import static io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import static io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.BinaryMessenger;
import io.flutter.plugin.platform.PlatformView;

public class BannerView implements PlatformView, MethodCallHandler  {
    private BannerContainer bannerContainer;
    private final MethodChannel methodChannel;

    BannerView(Context context, BinaryMessenger messenger) {
        bannerContainer = new BannerContainer(ScaleMonkPlugin.Companion.getActivityInstance());
        methodChannel = new MethodChannel(messenger, "plugins.com.scale_monk/banner");
        methodChannel.setMethodCallHandler(this);
    }

    @Override
    public View getView() {
        return bannerContainer;
    }

    @Override
    public void onMethodCall(MethodCall methodCall, MethodChannel.Result result) {
        switch (methodCall.method) {
            case "show":
                show();
                break;
            default:
                result.notImplemented();
        }

    }

    private void show() {
        ScaleMonkAds.showBanner(ScaleMonkPlugin.Companion.getActivityInstance(), bannerContainer, "tag");
    }

    @Override
    public void dispose() {}
}