//
//  RoomBoxABPlayerProgressBar.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/11.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxPlayerEventProtocol.h"
#import "RoomBoxPlayerProgressRecord.h"
#import "RoomBoxPlayerKnowledgeModel.h"
#import "RoomBoxRecordKnowledgeModel.h"
@import RoomBoxUtils;
NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxABPlayerProgressBarDelegate <NSObject>

@optional
- (void)playerProgressBarOnSelectKnowledges:(NSArray *)dataArray selectedIndex:(NSInteger)selectedIndex targetView:(UIView *)targetView;
- (void)playerProgressBarOnUpdatePlayProgress:(CGFloat)progress;
- (void)playerProgressBarOnUpdatePlayRecord:(NSArray *)records;

@end

typedef void(^CurrentRecordKnowledgeBlock)(RoomBoxRecordKnowledgeModel *model);

@interface RoomBoxABPlayerProgressBar : UIView <RoomBoxPlayerEventProtocol>

@property (nonatomic, copy) CurrentRecordKnowledgeBlock recordBlock;

@property (nonatomic, weak) id<RoomBoxABPlayerProgressBarDelegate> delegate;
@property (nonatomic, weak) id<RBZFPlayerMediaPlayback> player;
@property (nonatomic, strong, readonly) RoomBoxPlayerProgressRecord *record;

- (void)setTotalTime:(NSTimeInterval)time;
- (void)updateCurrentTime:(NSTimeInterval)time;

- (void)addKnowledgeFromArray:(NSArray<RoomBoxPlayerKnowledgeModel *> *)array;
- (void)addKnowledge:(RoomBoxPlayerKnowledgeModel *)model;
- (void)removeKnowledge:(RoomBoxPlayerKnowledgeModel *)model;

//添加录播课题目数据
- (void)addRecordNoteFromArray:(NSArray <RoomBoxRecordKnowledgeModel *>*)recordNoteArray;


@end

NS_ASSUME_NONNULL_END
