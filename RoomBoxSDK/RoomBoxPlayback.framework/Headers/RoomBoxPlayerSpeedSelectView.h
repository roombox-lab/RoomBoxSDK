//
//  RoomBoxPlayerSpeedSelectView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/7/29.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerSpeedSelectViewDelegate <NSObject>

@optional
- (void)speedSelectViewOnDismiss;
- (void)speedSelectViewOnSelectSpeed:(id)data;

@end

@interface RoomBoxPlayerSpeedSelectView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerSpeedSelectViewDelegate> delegate;
@property (nonatomic, weak) UIView *anchorView;

- (void)showPanelView:(UIView *)targetView;

@end

NS_ASSUME_NONNULL_END
