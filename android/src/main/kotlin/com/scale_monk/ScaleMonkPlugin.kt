package com.scale_monk

import adsBannerListener
import adsInterstitialListener
import adsRewardedListener
import android.app.Activity
import android.content.Context
import androidx.annotation.NonNull
import com.scalemonk.ads.ScaleMonkAds
import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result

class ScaleMonkPlugin: FlutterPlugin, MethodCallHandler, ActivityAware {
  private lateinit var activity: Activity
  private lateinit var channel : MethodChannel
  private lateinit var context : Context

  companion object {
    var activityInstance: Activity? = null
  }


  fun init(call: MethodCall, result: Result){
    ScaleMonkAds.initialize(activity, Runnable {
      ScaleMonkAds.addRewardedListener(adsRewardedListener(channel))
      ScaleMonkAds.addInterstitialListener(adsInterstitialListener(channel))
      ScaleMonkAds.addBannerListener(adsBannerListener(channel))
      result.success(true)
    })
  }

  fun show(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val adType = args["adType"] as Int
    val tag = args["tag"] as String
    when (adType) {
      0 -> {
      }
      1 -> {
        ScaleMonkAds.showInterstitial(activity, tag)
      }
      2 -> {
        ScaleMonkAds.showRewarded(activity, tag)
      }
      else -> {
        result.notImplemented()
      }
    }
    result.success(null)
  }

  fun isRewardedReadyToShow(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val tag = args["tag"] as String
    result.success(ScaleMonkAds.isRewardedReadyToShow(tag))
  }

  fun stopLoadingBanners(call: MethodCall, result: Result){
    // ScaleMonkAds.stopBanner(activity, activity.findViewById(R.id.bannerContainer), "")
    result.success(null)
  }

  fun setHasGDPRConsent(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val status = args["status"] as Boolean
    ScaleMonkAds.setHasGDPRConsent(status)
    result.success(null)
  }

  fun setUserCantGiveGDPRConsent(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val status = args["status"] as Boolean
    ScaleMonkAds.setUserCantGiveGDPRConsent(status)
    result.success(null)
  }

  fun setIsApplicationChildDirected(call: MethodCall, result: Result){
    val args = call.arguments as Map<*, *>
    val value = args["value"] as Boolean
    ScaleMonkAds.setIsApplicationChildDirected(value)
    result.success(null)
  }

  override fun onAttachedToEngine(@NonNull flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
    channel = MethodChannel(flutterPluginBinding.binaryMessenger, "scale_monk")
    channel.setMethodCallHandler(this)
    flutterPluginBinding.getPlatformViewRegistry().registerViewFactory("plugins.com.scale_monk/banner", BannerViewFactory(flutterPluginBinding.binaryMessenger))
    context = flutterPluginBinding.applicationContext
  }



  override fun onMethodCall(@NonNull call: MethodCall, @NonNull result: Result) {
    when (call.method) {
      "initialize" -> {
        init(call, result)
      }
      "show" -> {
        show(call, result)
      }
      "showBanner" -> {
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

  override fun onAttachedToActivity(binding: ActivityPluginBinding) {
    activity = binding.activity
    activityInstance = binding.activity
  }

  override fun onDetachedFromActivityForConfigChanges() {}
  override fun onReattachedToActivityForConfigChanges(binding: ActivityPluginBinding) {}
  override fun onDetachedFromActivity() {}
}
