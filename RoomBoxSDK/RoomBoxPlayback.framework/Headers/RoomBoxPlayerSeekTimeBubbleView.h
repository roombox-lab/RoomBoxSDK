//
//  RoomBoxPlayerSeekTimeBubbleView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/8/18.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerSeekTimeBubbleView : UIView

+ (CGFloat)defaultWidth;
+ (CGFloat)defaultHeight;
- (void)updateText:(BOOL)forward;

@end

NS_ASSUME_NONNULL_END
