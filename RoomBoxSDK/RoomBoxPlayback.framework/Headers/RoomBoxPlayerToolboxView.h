//
//  RoomBoxPlayerToolboxView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/12.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RoomBoxPlayerToolboxView;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    RoomBoxPlayerToolboxActionTypeScreenshot = 0,
    RoomBoxPlayerToolboxActionTypeMarkKey,
    RoomBoxPlayerToolboxActionTypeMarkDifficulty,
    RoomBoxPlayerToolboxActionTypeMark,
} RoomBoxPlayerToolboxActionType;

@protocol RoomBoxPlayerToolboxViewDelegate <NSObject>

//划重点视图是否打开
- (void)toolboxView:(RoomBoxPlayerToolboxView *)view knowledgeSelectShow:(BOOL)show;
//截屏按钮点击
- (void)toolboxView:(RoomBoxPlayerToolboxView *)view actionType:(RoomBoxPlayerToolboxActionType)type;

@end

@interface RoomBoxPlayerToolboxView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerToolboxViewDelegate> delegate;

@property (nonatomic, strong) UIButton *markButton;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
