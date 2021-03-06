//  SMARAdType.h
//
//  © 2020 ScaleMonk, Inc. All Rights Reserved.
// Licensed under the ScaleMonk SDK License Agreement
// https://www.scalemonk.com/legal/en-US/mediation-license-agreement/index.html
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
  SMARAdTypeInterstitial,
  SMARAdTypeRewardedVideo,
  SMARAdTypeBanner,

  SMARAdTypeUnknownType,
} SMARAdType;

NS_ASSUME_NONNULL_END
