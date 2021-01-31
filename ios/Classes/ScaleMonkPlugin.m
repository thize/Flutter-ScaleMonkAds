#import "ScaleMonkPlugin.h"
#if __has_include(<scale_monk/scale_monk-Swift.h>)
#import <scale_monk/scale_monk-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "scale_monk-Swift.h"
#endif

@implementation ScaleMonkPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftScaleMonkPlugin registerWithRegistrar:registrar];
}
@end
