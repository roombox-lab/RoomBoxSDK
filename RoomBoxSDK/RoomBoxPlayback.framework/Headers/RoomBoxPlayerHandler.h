//
//  RoomBoxPlayerHandler.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/5.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
@import RoomBoxUtils;
NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerHandler : RBZFPlayerController

// 重新绑定网络状态监听
- (void)rebuildReachabilityMonitor;

@end

NS_ASSUME_NONNULL_END
