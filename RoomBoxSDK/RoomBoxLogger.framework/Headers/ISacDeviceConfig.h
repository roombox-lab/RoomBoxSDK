//
//  ISacDeviceConfig.h
//  LogSend
//
//  Created by 吴云海 on 2019/6/25.
//  Copyright © 2019 吴云海. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ISacDeviceConfig : NSObject

//获取使用平台
+ (NSString *)deviceName;

//s数据加密
+(NSString *)sha1Decode:(NSString *)input;

@end

NS_ASSUME_NONNULL_END
