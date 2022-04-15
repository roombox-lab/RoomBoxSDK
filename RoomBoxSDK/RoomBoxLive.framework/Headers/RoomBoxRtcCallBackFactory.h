//
//  RoomBoxRtcCallBackFactory.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2021/3/15.
//  Copyright © 2021 XDF. All rights reserved.
//  回调工厂管理类

#import <Foundation/Foundation.h>
#import "RoomBoxRtcManagerInterface.h"


NS_ASSUME_NONNULL_BEGIN


@protocol RoomBoxRtcCallBackFactoryDelegate <NSObject>

-(nullable id)sharedInstance;

+(void)sharedDestory;

@end

@interface RoomBoxRtcCallBackFactory : NSObject

+ (id<RoomBoxRtcManagerDelegate>)sharedInstance;

+ (void)sharedDestory;

+ (void)sharedClearAllData;

//添加关联对象 用于回调
+ (NSInteger)addCatagoryObjectWith:(NSString *)className;

+ (void)removeCatagoryObjectWith:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
