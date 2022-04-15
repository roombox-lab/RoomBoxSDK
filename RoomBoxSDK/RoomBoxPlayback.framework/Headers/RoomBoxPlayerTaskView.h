//
//  RoomBoxPlayerTaskView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/19.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
@class RoomBoxPlayerTaskView;

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerTaskViewDelegate <NSObject>
//展示完动画后回调
- (void)playerTaskViewTaskDidComplete:(RoomBoxPlayerTaskView *)view;
- (void)playerTaskViewWillShowAnimate:(RoomBoxPlayerTaskView *)view;

@end

@interface RoomBoxPlayerTaskView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerTaskViewDelegate> delegate;
@property (nonatomic, weak) UIView *popContainerView;

- (void)configWithAward:(NSInteger)starCount targetDuration:(CGFloat)targetDuration totalDuration:(CGFloat)totalDuration;

- (void)updateCurrentDuration:(CGFloat)duration;
- (void)updateTaskComplete;
- (void)reset;

- (void)show:(BOOL)show isAward:(BOOL)isAward;

@end


NS_ASSUME_NONNULL_END
