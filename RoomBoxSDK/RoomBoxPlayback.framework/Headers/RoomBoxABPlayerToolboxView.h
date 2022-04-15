//
//  RoomBoxABPlayerToolboxView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/12.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RoomBoxABPlayerToolboxView;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    RoomBoxABPlayerToolboxActionTypeScreenshot = 0,
    RoomBoxABPlayerToolboxActionTypeMarkKey,
    RoomBoxABPlayerToolboxActionTypeMarkDifficulty,
    RoomBoxABPlayerToolboxActionTypeMark,
} RoomBoxABPlayerToolboxActionType;

@protocol RoomBoxABPlayerToolboxViewDelegate <NSObject>

//划重点视图是否打开
- (void)toolboxView:(RoomBoxABPlayerToolboxView *)view knowledgeSelectShow:(BOOL)show;
//截屏按钮点击
- (void)toolboxView:(RoomBoxABPlayerToolboxView *)view actionType:(RoomBoxABPlayerToolboxActionType)type;

@end

@interface RoomBoxABPlayerToolboxView : UIView

@property (nonatomic, weak) id<RoomBoxABPlayerToolboxViewDelegate> delegate;

@property (nonatomic, strong) UIButton *markButton;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
