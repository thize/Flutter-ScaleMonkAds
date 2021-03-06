//  SMARVASTInAppBrowser.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@import StoreKit;


@interface SMARVASTInAppBrowser : NSObject <WKNavigationDelegate, SKStoreProductViewControllerDelegate>

@property(nonatomic, weak) UIViewController *inAppBrowserViewController;
@property(nonatomic, weak) WKWebView *inAppBrowser;

- (void)setUpWithViewController:(UIViewController*)viewController webView:(WKWebView *)webview completion:(void(^)(NSString *, SKStoreProductViewController *, UIViewController *))completion;

@end
