//
//  SMDeviceInfo.h
//  SMDeviceInfo
//
//  Copyright © 2016 SM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SMNetworkReachability.h"

NS_ASSUME_NONNULL_BEGIN

@interface SMDeviceInfo : NSObject

- (instancetype)init __unavailable;

+ (bool)isSmart;  // Jailbroken?

+ (NSString *_Nullable)advertisingId;

+ (NSString *)appBundle;                  // "com.something.appname"
+ (NSString *)appVersion;                 // "1.2.32016-050"
+ (NSString *)appVersionWithBuildNumber;  // "1.2.3 (987)"
+ (NSString *)systemVersion;              // "9.1"
+ (NSString *)languageCode;               // "en", "pt"
+ (NSString *)regionCode;                 // "US", "BR"
+ (NSString *)
    deviceModel;  // "iPhone7,1" == iPhone 6 Plus (https://www.theiphonewiki.com/wiki/Models)
+ (NSString *)deviceType;                // "iPhone", "iPod'
+ (NSString *)modelSizeString;           // "16GB"
+ (double)availableMemory;               // free RAM in bytes
+ (NSString *)bootTime;                  // "12345678" -> seconds since epoch
+ (NSString *)mobileCarrierName;         // "T-Mobile"
+ (NSString *)mobileCarrierCountryCode;  // "724"
+ (NSString *)mobileCarrierNetworkCode;  // "324"
+ (NSString *)deviceName;                // "Josezinho's iPhone"
+ (NSString *)vendorIdentifier;
+ (SMNetworkNetworkStatus)connectionType;  // See SMNetworkNetworkStatus enum.
+ (NSString *)connectionTypeName;          // "Offline, Wifi, CTRadioAccessTechnologyGPRS,
                                           // CTRadioAccessTechnologyHSDPA"
+ (NSString *)timeZoneName;                // "America/Argentina/Buenos_Aires
                             // (https://en.wikipedia.org/wiki/List_of_tz_database_time_zones)"

@end

NS_ASSUME_NONNULL_END
