//
//  BannerListener.swift
//  scale_monk
//
//  Created by Giovani Lobato on 2021-01-30.
//

import Foundation
import ScaleMonkAds

extension SwiftScaleMonkPlugin: SMInterstitialAdEventListener {
    public func onInterstitialClick(_: String) {
        channel?.invokeMethod("onInterstitialClick", arguments: nil)
    }

    public func onInterstitialFail(_: String) {
        channel?.invokeMethod("onInterstitialFail", arguments: nil)
    }

    public func onInterstitialView(_: String) {
        channel?.invokeMethod("onInterstitialView", arguments: nil)
    }

    public func onInterstitialViewStart(_: String) {
        channel?.invokeMethod("onInterstitialViewStart", arguments: nil)
    }

    public func onInterstitialReady() {
        channel?.invokeMethod("onInterstitialReady", arguments: nil)
    }
}
