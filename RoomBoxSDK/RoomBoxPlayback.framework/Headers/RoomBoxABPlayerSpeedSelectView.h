//
//  RoomBoxABPlayerSpeedSelectView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/7/29.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxABPlayerSpeedSelectViewDelegate <NSObject>

@optional
- (void)speedSelectViewOnDismiss;
- (void)speedSelectViewOnSelectSpeed:(id)data;

@end

@interface RoomBoxABPlayerSpeedSelectView : UIView

@property (nonatomic, strong, readonly) UITableView *tableView;
@property (nonatomic, weak) id<RoomBoxABPlayerSpeedSelectViewDelegate> delegate;
@property (nonatomic, weak) UIView *anchorView;

- (void)showPanelView:(UIView *)targetView;

@end

NS_ASSUME_NONNULL_END
