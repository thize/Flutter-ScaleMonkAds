import Flutter
import UIKit
import ScaleMonkAds
import AppTrackingTransparency

public class SwiftScaleMonkPlugin: NSObject, FlutterPlugin {
    internal var channel: FlutterMethodChannel?
    var scaleMonkAds: SMAds? = nil

    public static func register(with registrar: FlutterPluginRegistrar) {
        let instance = SwiftScaleMonkPlugin()
        instance.channel = FlutterMethodChannel(name: "scale_monk", binaryMessenger: registrar.messenger())
        
        registrar.addMethodCallDelegate(instance, channel: instance.channel!)
    }
    
    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        switch call.method {
        //! ScaleMonk
        case "initialize": initialize(call, result)
        case "show": show(call, result)
        case "isRewardedReadyToShow": isRewardedReadyToShow(call, result)
        case "stopLoadingBanners": stopLoadingBanners(call, result)
        case "setHasGDPRConsent": setHasGDPRConsent(call, result)
        case "setUserCantGiveGDPRConsent": setUserCantGiveGDPRConsent(call, result)
        case "setIsApplicationChildDirected": setIsApplicationChildDirected(call, result)
        case "requestTrackingAuthorization": requestTrackingAuthorization(call, result)
        default: result(FlutterMethodNotImplemented)
        }
    }

    //! ScaleMonk

    private func initialize(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let applicationId = args["iosApplicationId"] as! String
        scaleMonkAds = SMAds(applicationId: applicationId)!

        // Registering callbacks
        setCallbacks()
        
        // initialize
        scaleMonkAds!.initialize { success in
            result(success)
        }
    }

    private func show(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let adType = args["adType"] as! Int
        let tag = args["tag"] as? String ?? ""
        let controller = UIApplication.shared.keyWindow?.rootViewController
        switch adType {
        case 0:
            let bannerView = SMBannerView()
            bannerView.viewController = controller
            let left = ((controller?.view.bounds.width ?? 320) - 320) / 2
            var top = (controller?.view.bounds.height ?? 50) - 50
            if #available(iOS 11.0, *) {
                let bottomPadding = UIApplication.shared.keyWindow?.safeAreaInsets.bottom ?? 0.0
                top = top - bottomPadding
            }
            bannerView.frame = CGRect(x: left, y: top, width: 320, height: 50)
            controller!.view.addSubview(bannerView)
            scaleMonkAds!.showBannerAd(viewController: controller, bannerView: bannerView, tag: tag)
        case 1: scaleMonkAds!.showInterstitialAd(viewController: controller, tag: tag)
        case 2: scaleMonkAds!.showRewardedAd(viewController: controller, tag: tag)
        default: result(nil)
        }
        result(nil)
    }

    private func stopLoadingBanners(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        scaleMonkAds!.stopLoadingBanners()
        result(nil)
    }

    private func setHasGDPRConsent(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let status = args["status"] as! Bool
        scaleMonkAds!.setHasGDPRConsent(status: status)
        result(nil)
    }

    private func setUserCantGiveGDPRConsent(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let status = args["status"] as! Bool
        scaleMonkAds!.setUserCantGiveGDPRConsent(status: status)
        result(nil)
    }

    private func setIsApplicationChildDirected(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let value = args["value"] as! Bool
        scaleMonkAds!.setIsApplicationChildDirected(value)
        result(nil)
    }

    private func isRewardedReadyToShow(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        let args = call.arguments as! [String: Any]
        let tag = args["tag"] as? String ?? ""
        result(scaleMonkAds!.isRewardedReadyToShow(tag: tag))
    }

    private func setCallbacks() {
        // scaleMonkAds!.addVideoListener(self)
        scaleMonkAds!.addInterstitialListener(self)
        scaleMonkAds!.addBannerListener(self)
    }

    //! Tracking Authorization

    private func requestTrackingAuthorization(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        if #available(iOS 14, *) {
            ATTrackingManager.requestTrackingAuthorization(completionHandler: { status in
                result(status == ATTrackingManager.AuthorizationStatus.authorized)
            })
        }
        else {
          result(true)
        }
    }
}
