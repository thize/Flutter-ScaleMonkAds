import android.content.Context
import com.scalemonk.ads.BannerEventListener

/**
 * Example implementation of the BannerEventListener
 */
internal class AdsBannerListener(private var context: Context, channel: MethodChannel) : BannerEventListener {
    override fun onBannerFail(tag: String?) {
        channel.invokeMethod("onBannerFail", null)
    }

    override fun onBannerCompleted(tag: String?) {
        channel.invokeMethod("onBannerCompleted", null)
    }
}
