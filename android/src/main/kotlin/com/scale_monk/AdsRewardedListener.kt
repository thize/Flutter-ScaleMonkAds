import android.content.Context
import com.scalemonk.libs.ads.core.delivery.RewardedEventListener
import io.flutter.plugin.common.MethodChannel

/**
 * Example implementation of the RewardedEventListener
 */

fun adsRewardedListener(channel: MethodChannel) : RewardedEventListener {
    return object : RewardedEventListener {
        override fun onRewardedClick(tag: String?) {
            channel.invokeMethod("onRewardedClick", null)
        }

        override fun onRewardedViewStart(tag: String?) {
            channel.invokeMethod("onRewardedViewStart", null)
        }

        override fun onRewardedFinishWithNoReward(tag: String?) {
            channel.invokeMethod("onRewardedFinishWithNoReward", null)
        }

        override fun onRewardedFinishWithReward(tag: String?) {
            channel.invokeMethod("onRewardedFinishWithReward", null)
        }

        override fun onRewardedFail(tag: String?) {
            channel.invokeMethod("onRewardedFail", null)
        }

        override fun onRewardedReady() {
            channel.invokeMethod("onRewardedReady", null)
        }
    }
}
