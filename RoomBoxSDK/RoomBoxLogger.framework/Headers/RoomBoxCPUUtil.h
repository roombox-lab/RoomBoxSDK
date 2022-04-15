//
//  RoomBoxCPUUtil.h
//  XDFLog
//
//  Created by 刘冬冬 on 2020/11/10.
//  Copyright © 2020 xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxCPUUtil : NSObject
//获取app CPU使用率
+ (CGFloat)cpuUsageForApp;
//获取CPU使用率
+ (CGFloat)cpuUsage;
@end

NS_ASSUME_NONNULL_END
