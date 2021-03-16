import android.content.Context
import com.scalemonk.libs.ads.core.delivery.BannerEventListener
import io.flutter.plugin.common.MethodChannel

/**
 * Example implementation of the BannerEventListener
 */
fun adsBannerListener(channel: MethodChannel) : BannerEventListener {
    return object : BannerEventListener {
        override fun onBannerFail(tag: String?) {
            channel.invokeMethod("onBannerFail", null)
        }

        override fun onBannerCompleted(tag: String?) {
            channel.invokeMethod("onBannerCompleted", null)
        }
    }
}
