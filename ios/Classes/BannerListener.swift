//
//  BannerListener.swift
//  scale_monk
//
//  Created by Giovani Lobato on 2021-01-30.
//

import Foundation
import ScaleMonkAds

extension SwiftScaleMonkPlugin: SMBannerAdEventListener {
    public func onBannerFail(_: String) {
        channel?.invokeMethod("onBannerFail", arguments: nil)
    }
    
    public func onBannerCompleted(_: String) {
        channel?.invokeMethod("onBannerCompleted", arguments: nil)
    }
}
