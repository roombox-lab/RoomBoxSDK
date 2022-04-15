//
//  RoomBoxFPSUtil.h
//  XDFLog
//
//  Created by 刘冬冬 on 2020/11/10.
//  Copyright © 2020 xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RoomBoxFPSBlock)(NSInteger fps);

@interface RoomBoxFPSUtil : NSObject

- (void)start;
- (void)end;
- (void)addFPSBlock:(RoomBoxFPSBlock)block;

@end

NS_ASSUME_NONNULL_END
