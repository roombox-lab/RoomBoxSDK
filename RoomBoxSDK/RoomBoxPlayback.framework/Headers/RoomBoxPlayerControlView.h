//
//  RoomBoxPlayerControlView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxPlayerProgressView.h"
#import "RoomBoxPlayerNavigatorView.h"
@import RoomBoxUtils;
@class RoomBoxPlayerLogUtil;
@class RoomBoxPlayerKnowledgeModel;
@class RoomBoxPlayerVideoConfigModel;

@class RoomBoxPlayerHandler;

typedef void(^VoidBlock)(void);

@interface RoomBoxPlayerControlView : UIView <RBZFPlayerMediaControl>

@property (nonatomic, strong, readonly) RoomBoxPlayerNavigatorView *navigatorView;
@property (nonatomic, strong, readonly) RoomBoxPlayerProgressView *progressView;

@property (nonatomic, weak) RoomBoxPlayerLogUtil *logger;

@property (nonatomic, copy) dispatch_block_t onBackBlock;
@property (nonatomic, copy) dispatch_block_t onScreenshotBlock;
@property (nonatomic, copy) void(^onAddMarkBlock)(RoomBoxPlayerKnowledgeModel *);
@property (nonatomic, copy) void(^onDeleteMarkBlock)(RoomBoxPlayerKnowledgeModel *);
@property (nonatomic, copy) void(^onPlayProgressDidUpdateBlock)(CGFloat progress);

@property (nonatomic, weak) RoomBoxPlayerHandler *playerHandler;
@property (nonatomic, assign) BOOL isLocalPlay;
@property (nonatomic, copy) NSString *remoteUrl;
@property (nonatomic, copy) NSString *copyright;
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *token;

@property (nonatomic, copy) VoidBlock playFinishBlock;
/* 是否是录播课有题目，不能滑动 */
@property (nonatomic, assign) BOOL isRecordExistNote;

- (instancetype)initWithParams:(NSDictionary *)dict;

- (void)updateAssetTitle:(NSString *)title;

- (void)showLoadingView;
- (void)hideLoadingView;

- (void)didAddKnowledge:(RoomBoxPlayerKnowledgeModel *)model;
- (void)didDeleteKnowledge:(RoomBoxPlayerKnowledgeModel *)model;

- (void)updateKnowledgeList:(NSArray<RoomBoxPlayerKnowledgeModel *> *)list;

// 宝箱奖励相关
- (void)showTaskViewWithConfig:(RoomBoxPlayerVideoConfigModel *)config;
- (void)updateTaskViewCurrentDuration:(CGFloat)duration;
- (void)updateTaskComplete;

// 视频无效相关
- (void)updateInvaildStatus;

- (void)loadData;

- (void)updateUIWithNewNoteExist;

@end
