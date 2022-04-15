//
//  RoomBoxPlayerRefreshFooterView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/20.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RoomBoxPlayerRefreshComponent;

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (RoomBoxPlayerRefresh)

@property (nonatomic, strong, nullable) RoomBoxPlayerRefreshComponent *rbp_footer;

@end

/** 刷新控件的状态 */
typedef NS_ENUM(NSInteger, RoomBoxPlayerRefreshState) {
    /** 普通闲置状态 */
    RoomBoxPlayerRefreshStateIdle = 1,
    /** 松开就可以进行刷新的状态 */
    RoomBoxPlayerRefreshStatePulling,
    /** 正在刷新中的状态 */
    RoomBoxPlayerRefreshStateRefreshing,
    /** 即将刷新的状态 */
    RoomBoxPlayerRefreshStateWillRefresh,
    /** 所有数据加载完毕，没有更多的数据了 */
    RoomBoxPlayerRefreshStateNoMoreData
};

/** 刷新用到的回调类型 */
typedef void (^RoomBoxPlayerRefreshComponentAction)(void);

/** 刷新控件的基类 */
@interface RoomBoxPlayerRefreshComponent : UIView {
    /** 父控件 */
    __weak UIScrollView *_scrollView;
}

/** 创建footer */
+ (instancetype)footerWithRefreshingBlock:(RoomBoxPlayerRefreshComponentAction)refreshingBlock;
/** 创建footer */
+ (instancetype)footerWithRefreshingTarget:(id)target refreshingAction:(SEL)action;

/** 初始化 */
- (void)prepare NS_REQUIRES_SUPER;
/** 摆放子控件frame */
- (void)placeSubviews NS_REQUIRES_SUPER;
/** 当scrollView的contentOffset发生改变的时候调用 */
- (void)scrollViewContentOffsetDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;
/** 当scrollView的contentSize发生改变的时候调用 */
- (void)scrollViewContentSizeDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;
/** 当scrollView的拖拽状态发生改变的时候调用 */
- (void)scrollViewPanStateDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;

/** 父控件 */
@property (nonatomic, weak, readonly) UIScrollView *scrollView;

#pragma mark - 刷新回调
/** 正在刷新的回调 */
@property (nonatomic, copy, nullable) RoomBoxPlayerRefreshComponentAction refreshingBlock;
/** 设置回调对象和回调方法 */
- (void)setRefreshingTarget:(id)target refreshingAction:(SEL)action;

/** 回调对象 */
@property (nonatomic, weak) id refreshingTarget;
/** 回调方法 */
@property (nonatomic, assign) SEL refreshingAction;
/** 触发回调 */
- (void)executeRefreshingCallback;

/** 忽略多少scrollView的contentInset的bottom */
@property (nonatomic, assign) CGFloat ignoredScrollViewContentInsetBottom;

/** 自动触发次数, 默认为 1, 仅在拖拽 ScrollView 时才生效, 如果为 -1, 则为无限触发 */
@property (nonatomic, assign) NSInteger autoTriggerTimes;

/** 拉拽的百分比 */
@property (nonatomic, assign) CGFloat pullingPercent;
/** 根据拖拽比例自动切换透明度 */
@property (nonatomic, assign, getter=isAutomaticallyChangeAlpha) BOOL automaticallyChangeAlpha;

/** 显示刷新状态的label */
@property (nonatomic, strong, readonly) UILabel *stateLabel;

#pragma mark - 刷新状态控制
/** 是否自动刷新(默认为YES) */
@property (nonatomic, assign, getter=isAutomaticallyRefresh) BOOL automaticallyRefresh;

/** 当底部控件出现多少时就自动刷新(默认为1.0，也就是底部控件完全出现时，才会自动刷新) */
@property (nonatomic, assign) CGFloat triggerAutomaticallyRefreshPercent;

/** 开始刷新后的回调(进入刷新状态后的回调) */
@property (nonatomic, copy, nullable) RoomBoxPlayerRefreshComponentAction beginRefreshingCompletionBlock;
/** 带动画的结束刷新的回调 */
@property (nonatomic, copy, nullable) RoomBoxPlayerRefreshComponentAction endRefreshingAnimationBeginAction;
/** 结束刷新的回调 */
@property (nonatomic, copy, nullable) RoomBoxPlayerRefreshComponentAction endRefreshingCompletionBlock;

/** 是否正在刷新 */
@property (nonatomic, assign, readonly, getter=isRefreshing) BOOL refreshing;

/** 刷新状态 */
@property (nonatomic, assign) RoomBoxPlayerRefreshState state;

/** 进入刷新状态 */
- (void)beginRefreshing;
- (void)beginRefreshingWithCompletionBlock:(void (^)(void))completionBlock;

/** 结束刷新状态 */
- (void)endRefreshing;
- (void)endRefreshingWithCompletionBlock:(void (^)(void))completionBlock;

/** 提示没有更多的数据 */
- (void)endRefreshingWithNoMoreData;

/** 重置没有更多的数据（消除没有更多数据的状态） */
- (void)resetNoMoreData;

/** 设置state状态下的文字 */
- (void)setTitle:(NSString *)title forState:(RoomBoxPlayerRefreshState)state;

@end

@interface RoomBoxPlayerRefreshFooterView : RoomBoxPlayerRefreshComponent

@end

NS_ASSUME_NONNULL_END
