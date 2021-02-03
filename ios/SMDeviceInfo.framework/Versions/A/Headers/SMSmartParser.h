//
//  SMSmartValidator.h
//  SMDeviceInfo
//
//  Copyright © 2018 SM. All rights reserved.
//

#import <Foundation/Foundation.h>

// Class to parse the provision profile
@interface SMSmartParser : NSObject

- (id)initWithData:(NSData *)data;

@property(strong, nonatomic, readonly) NSDictionary *dict;

@end
