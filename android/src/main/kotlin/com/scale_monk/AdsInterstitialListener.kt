import android.content.Context
import com.scalemonk.libs.ads.core.delivery.InterstitialEventListener
import io.flutter.plugin.common.MethodChannel


/**
 * Example implementation of the InterstitialEventListener
 */
fun adsInterstitialListener(channel: MethodChannel) : InterstitialEventListener {
    return object : InterstitialEventListener {
        override fun onInterstitialClick(tag: String?) {
            channel.invokeMethod("onInterstitialClick", null)
        }

        override fun onInterstitialFail(tag: String?) {
            channel.invokeMethod("onInterstitialFail", null)
        }

        override fun onInterstitialView(tag: String?) {
            channel.invokeMethod("onInterstitialView", null)
        }

        override fun onInterstitialViewStart(tag: String?) {
            channel.invokeMethod("onInterstitialViewStart", null)
        }

        override fun onInterstitialReady() {
            channel.invokeMethod("onInterstitialReady", null)
        }
    }
}
