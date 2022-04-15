//
//  RoomBoxOCDevice.h
//  RBBaseFoundation
//
//  Created by 刘冬冬 on 2020/11/11.
//  Copyright © 2020 RB.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxOCDevice : NSObject
+ (NSString *)getDeviceName;
+ (NSString *)getSystemVersion;
@end

NS_ASSUME_NONNULL_END
