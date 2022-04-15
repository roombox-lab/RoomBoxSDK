//
//  ISacWifiConfig.h
//  RoomBoxSDK
//
//  Created by 婉华孙 on 2019/7/29.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ISacWifiConfig : NSObject

//+ (void)getDeviceInfo;

+ (NSString *)getMacAddress;

+ (NSString *)getDeviceIPAddresses;

+ (NSString *)getVersionString;

+ (NSString *)macaddress;

+ (NSString *)getOperatorInfomation;
@end

NS_ASSUME_NONNULL_END
