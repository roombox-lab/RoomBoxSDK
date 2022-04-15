//
//  RoomBoxRtcManagerEnum.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2021/3/10.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomBoxRtcManagerInterface.h"

NS_ASSUME_NONNULL_BEGIN



@interface RoomBoxRtcManagerFactory: NSObject

+ (instancetype)sharedInstance;

+ (void)sharedDestory;

- (nullable id<RoomBoxRtcManagerInterface>)achieveCurrentRtcInstance:(RtcInstance) instance;

- (RtcInstance)achieveCurrentRtcInstanceType:(RtcInstance) instance;
@end

NS_ASSUME_NONNULL_END
