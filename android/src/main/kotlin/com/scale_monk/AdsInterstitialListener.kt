import android.content.Context
import com.scalemonk.ads.InterstitialEventListener

/**
 * Example implementation of the InterstitialEventListener
 */
internal class AdsInterstitialListener(private var context: Context, channel: MethodChannel) : InterstitialEventListener {
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

    override fun onInterstitialReady(tag: String?) {
        channel.invokeMethod("onInterstitialReady", null)
    }
}
