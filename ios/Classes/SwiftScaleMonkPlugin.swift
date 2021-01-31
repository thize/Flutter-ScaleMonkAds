import Flutter
import UIKit
import StackConsentManager
import ScaleMonkAds

public class SwiftScaleMonkPlugin: NSObject, FlutterPlugin {
    internal var channel: FlutterMethodChannel?
    // var scaleMonkAds: ScaleMonkAds?
    // var scaleMonkAds: AnyObject

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
        case "stopLoadingBanners": stopLoadingBanners(call, result)
        case "setHasGDPRConsent": setHasGDPRConsent(call, result)
        case "setUserCanGiveGDPRConsent": setUserCanGiveGDPRConsent(call, result)
        case "setIsApplicationChildDirected": setIsApplicationChildDirected(call, result)
        default: result(FlutterMethodNotImplemented)
        }
    }

    //! ScaleMonk

    private func initialize(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // let args = call.arguments as! [String: Any]
        // let applicationId = args["iosApplicationId"] as! String

        // // Registering callbacks
        // setCallbacks()

        // // initialize
        // scaleMonkAds = ScaleMonkAds(applicationId: applicationId)
        // scaleMonkAds.initialize({ success in
        //     result(success)
        // })
    }

    private func show(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // let args = call.arguments as! [String: Any]
        // let adType = args["adType"] as! Int
        // let tag = args["tag"] as? String
        // let rootViewController = UIApplication.shared.keyWindow?.rootViewController
        // switch adType {
        // case 0: return scaleMonkAds.showBannerAd(viewController: rootViewController, tag: tag)
        // case 1: return scaleMonkAds.showInterstitialAd(viewController: rootViewController, tag: tag)
        // case 2: return scaleMonkAds.showRewardedVideoAd(viewController: rootViewController, tag: tag)
        // default: return scaleMonkAds.showBannerAd(viewController: rootViewController, tag: tag)
        // }
    }

    private func stopLoadingBanners(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // scaleMonkAds.stopLoadingBanners()
        // result(nil)
    }

    private func setHasGDPRConsent(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // scaleMonkAds.setHasGDPRConsent(status in result(status))
    }

    private func setUserCanGiveGDPRConsent(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // let args = call.arguments as! [String: Any]
        // let hasConsent = args["hasConsent"] as! Bool
        // scaleMonkAds.setUserCanGiveGDPRConsent(hasConsent)
        // result(nil)
    }

    private func setIsApplicationChildDirected(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
        // scaleMonkAds.setIsApplicationChildDirected(status in result(status))
    }

    private func setCallbacks() {
        // scaleMonkAds.addVideoListener(listener: self)
        // scaleMonkAds.addInterstitialListener(listener: self)
        // scaleMonkAds.addBannerListener(listener: self)
    }
    
    //! Consent Manager
    
    // private func fetchConsentInfo(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
    //     let args = call.arguments as! [String: Any]
    //     let applicationId = args["iosApplicationId"] as! String

    //     STKConsentManager.shared().synchronize(withAppKey: applicationId) { error in
    //         if error == nil {
    //             result([
    //                 "acceptedVendors": [],
    //                 "status": STKConsentManager.shared().consentStatus.rawValue,
    //                 "zone": STKConsentManager.shared().regulation.rawValue,
    //             ])
    //         } else {
    //             result(FlutterError(code: "CONSENT_INFO_ERROR", message: "Failed to fetch the consent info",
    //                                 details: error))
    //         }
    //     }
    // }
    
    // private func shouldShowConsent(_ call: FlutterMethodCall, _ result: @escaping FlutterResult) {
    //     let args = call.arguments as! [String: Any]
    //     let applicationId = args["iosApplicationId"] as! String
        
    //     STKConsentManager.shared().synchronize(withAppKey: applicationId) { error in
    //         if error == nil {
    //             result(STKConsentManager.shared().shouldShowConsentDialog == .true)
    //         } else {
    //             result(FlutterError(code: "CONSENT_CHECK_ERROR", message: "Failed to check if consent is needed",
    //                                 details: error))
    //         }
    //     }
    // }
    
    // private func requestConsentAuthorization(_ result: @escaping FlutterResult) {
    //     STKConsentManager.shared().loadConsentDialog { error in
    //         if error == nil {
    //             let controller = UIApplication.shared.keyWindow?.rootViewController
    //             STKConsentManager.shared().showConsentDialog(fromRootViewController: controller!, delegate: nil)
    //             result(nil)
    //         } else {
    //             result(FlutterError(code: "CONSENT_WINDOW_ERROR", message: "Error showing the consent window",
    //                                 details: error))
    //         }
    //     }
    // }
}
