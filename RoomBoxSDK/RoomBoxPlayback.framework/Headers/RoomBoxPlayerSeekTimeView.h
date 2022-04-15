//
//  RoomBoxPlayerSeekTimeView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/7/31.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerSeekTimeView : UIView

- (void)updateCurrentTime:(NSTimeInterval)currentTime totalTime:(NSTimeInterval)totalTime;

+ (CGFloat)defaultWidth;

+ (CGFloat)defaultHeight;

@end

NS_ASSUME_NONNULL_END
