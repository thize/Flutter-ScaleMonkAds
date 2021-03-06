//
//  BannerListener.swift
//  scale_monk
//
//  Created by Giovani Lobato on 2021-01-30.
//

import Foundation
import ScaleMonkAds

extension SwiftScaleMonkPlugin: SMRewardedAdEventListener {
    public func onRewardedClick(_ tag: String!) {
        channel?.invokeMethod("onRewardedClick", arguments: nil)
    }
    
    public func onRewardedViewStart(_ tag: String!) {
        channel?.invokeMethod("onRewardedViewStart", arguments: nil)
    }

    public func onRewardedFinishWithNoReward(_ tag: String) {
        channel?.invokeMethod("onRewardedFinishWithNoReward", arguments: nil)
    }

    public func onRewardedFinish(withReward tag: String!) {
        channel?.invokeMethod("onRewardedFinishWithReward", arguments: nil)
    }
 
    public func onRewardedFail(_ tag: String!) {
        channel?.invokeMethod("onRewardedFail", arguments: nil)
    }

    public func onRewardedReady() {
        channel?.invokeMethod("onRewardedReady", arguments: nil)
    }
}
