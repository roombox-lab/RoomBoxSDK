//
//  RoomBoxMemoryUtil.h
//  XDFLog
//
//  Created by 刘冬冬 on 2020/11/10.
//  Copyright © 2020 xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <mach/mach.h>
NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxMemoryUtil : NSObject
//当前app内存使用量
+ (NSInteger)useMemoryForApp;
+ (NSInteger)availableMemory;
+ (NSInteger)totolUsageMemory;
//设备总的内存
+ (NSInteger)totalMemoryForDevice;
@end

NS_ASSUME_NONNULL_END
