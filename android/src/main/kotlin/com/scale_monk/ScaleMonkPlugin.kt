package com.scale_monk

import AdsBannerListener
import AdsInterstitialListener
import AdsRewardedListener
import android.content.Context
import androidx.annotation.NonNull
import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.common.PluginRegistry.Registrar
import com.scalemonk.ads.ScaleMonkAds

class ScaleMonkPlugin: FlutterPlugin, MethodCallHandler {
  private lateinit var channel : MethodChannel
  private lateinit var context : Context

  override fun onAttachedToEngine(@NonNull flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
    channel = MethodChannel(flutterPluginBinding.binaryMessenger, "scale_monk")
    channel.setMethodCallHandler(this)
    context = flutterPluginBinding.applicationContext
  }

  override fun onMethodCall(@NonNull call: MethodCall, @NonNull result: Result) {
    when (call.method) {
      "init" -> {
        init(call, result)
      }
      "show" -> {
        show(call, result)
      }
      "isRewardedReadyToShow" -> {
        isRewardedReadyToShow(call, result)
      }
      "stopLoadingBanners" -> {
        stopLoadingBanners(call, result)
      }
      "setHasGDPRConsent" -> {
        setHasGDPRConsent(call, result)
      }
      "setUserCantGiveGDPRConsent" -> {
        setUserCantGiveGDPRConsent(call, result)
      }
      "setIsApplicationChildDirected" -> {
        setIsApplicationChildDirected(call, result)
      }
      "requestTrackingAuthorization" -> {
        result.success(true)
      }
      else -> {
        result.notImplemented()
      }
    }
  }

  override fun onDetachedFromEngine(@NonNull binding: FlutterPlugin.FlutterPluginBinding) {
    channel.setMethodCallHandler(null)
  }

  fun init(call: MethodCall, result: Result){
    ScaleMonkAds.initialize(context, {})
    ScaleMonkAds.addRewardedListener(AdsRewardedListener(context, channel))
    ScaleMonkAds.addInterstitialListener(AdsInterstitialListener(context, channel))
    ScaleMonkAds.addBannerListener(AdsBannerListener(context, channel))
    result.success(null)
  }

  fun show(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val adType = args["adType"] as Int
    val tag = args["tag"] as String
    when (adType) {
      0 -> {
        ScaleMonkAds.showBanner(context, findViewById(R.id.bannerContainer), tag)
      }
      1 -> {
        ScaleMonkAds.showInterstitial(context, tag)
      }
      2 -> {
        ScaleMonkAds.showRewarded(context, tag)
      }
      else -> {

      }
    }
    result(null)
  }

  fun isRewardedReadyToShow(call: MethodCall, result: Result){
    result.success(null)
  }

  fun stopLoadingBanners(call: MethodCall, result: Result){
    ScaleMonkAds.stopBanner(context, findViewById(R.id.bannerContainer), "")
    result.success(null)
  }

  fun setHasGDPRConsent(call: MethodCall, result: Result){
    result.success(null)
  }

  fun setUserCantGiveGDPRConsent(call: MethodCall, result: Result){
    result.success(null)
  }

  fun setIsApplicationChildDirected(call: MethodCall, result: Result){
    result.success(null)
  }
}
