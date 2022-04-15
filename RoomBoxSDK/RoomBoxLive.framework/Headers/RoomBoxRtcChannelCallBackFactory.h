//
//  RoomBoxRtcChannelCallBackFactory.h
//  RoomBoxSDK
//
//  Created by 赵亮 on 2021/7/5.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomBoxRtcManagerInterface.h"

NS_ASSUME_NONNULL_BEGIN


@protocol RoomBoxRtcChannelCallBackFactoryDelegate <NSObject>

-(nullable id)sharedInstance;

+(void)sharedDestory;

@end

@interface RoomBoxRtcChannelCallBackFactory : NSObject

+ (id<RoomBoxRtcChannelDelegate>)sharedInstance;

+ (void)sharedDestory;

+ (void)sharedClearAllData;

//添加关联对象 用于回调
+ (NSInteger)addCatagoryObjectWith:(NSString *)className;

+ (void)removeCatagoryObjectWith:(NSString *)className;


@end

NS_ASSUME_NONNULL_END
