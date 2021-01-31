//
//  BannerListener.swift
//  scale_monk
//
//  Created by Giovani Lobato on 2021-01-30.
//

import Foundation
import ScaleMonkAds

extension SwiftScaleMonkPlugin: BannerEventListener {
    public func onBannerFailWithTag(_: String) {
        channel?.invokeMethod("onBannerFail", arguments: nil)
    }
    
    public func onBannerCompletedWithTag(_: String) {
        channel?.invokeMethod("onBannerCompleted", arguments: nil)
    }
}
