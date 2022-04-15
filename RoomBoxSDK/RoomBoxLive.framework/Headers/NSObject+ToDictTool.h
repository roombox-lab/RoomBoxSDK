//
//  NSObject+ToDictTool.h
//  RoomBoxSDK
//
//  Created by 逯常松 on 2021/7/3.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ToDictTool)

//将model转字典
+ (NSDictionary *)dicFromObject:(NSObject *)object;

@end

NS_ASSUME_NONNULL_END
