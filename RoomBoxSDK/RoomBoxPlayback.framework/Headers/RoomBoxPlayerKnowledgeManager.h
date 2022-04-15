//
//  RoomBoxPlayerKnowledgeManager.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/11.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomBoxPlayerKnowledgeModel.h"
#import "RoomBoxPlayerKnowledgeSelectView.h"

NS_ASSUME_NONNULL_BEGIN

@class RoomBoxPlayerKnowledgeManager;
@protocol RoomBoxPlayerKnowledgeManagerDelegate <NSObject>

//播放选中的知识点
- (void)knowledgeManager:(RoomBoxPlayerKnowledgeManager *)manager didSelectKnowledge:(RoomBoxPlayerKnowledgeModel *)knowledge;
//删除知识点
- (void)knowledgeManager:(RoomBoxPlayerKnowledgeManager *)manager deleteKnowledge:(RoomBoxPlayerKnowledgeModel *)knowledge;

@optional
//视图关闭
- (void)knowledgeManagerSelectViewOnDismiss:(RoomBoxPlayerKnowledgeManager *)manager;
//速览模式变更
- (void)knowledgeManager:(RoomBoxPlayerKnowledgeManager *)manager quickLookModeChangeTo:(BOOL)mode interrupt:(BOOL)interrupt;
//速览结束
- (void)knowledgeManagerQuickLookFinished:(RoomBoxPlayerKnowledgeManager *)manager;
//展示知识点
- (void)knowledgemanager:(RoomBoxPlayerKnowledgeManager *)manager showKnowledges:(NSArray<RoomBoxPlayerKnowledgeModel *> *)knowledges;

@end

@interface RoomBoxPlayerKnowledgeManager : NSObject

@property (nonatomic, weak) id<RoomBoxPlayerKnowledgeManagerDelegate> delegate;
//播控展示视图
@property (nonatomic, strong, readonly) RoomBoxPlayerKnowledgeSelectView *knowledgeSelectView;
//是否是速览模式
@property (nonatomic, assign, readonly) BOOL isQuickLookMode;
//所有知识点
@property (nonatomic, copy, readonly) NSArray<RoomBoxPlayerKnowledgeModel *> *knowledges;
//当前正在播放的知识点
@property (nonatomic, strong, readonly) RoomBoxPlayerKnowledgeModel *knowledgeInPlaying;

@property (nonatomic, copy, readonly) NSString *totalTimeValueString;
@property (nonatomic, copy, readonly) NSString *totalTimeShortString;


- (void)updateKnowledges:(NSArray<RoomBoxPlayerKnowledgeModel *> *)knowledges;
//更新当前播放时间点
- (void)updatePlayTime:(NSTimeInterval)time;
//取消快览模式
- (void)cancelQuickLookMode:(BOOL)interrupt;

//展示知识点
- (void)showKnowledges:(NSArray<RoomBoxPlayerKnowledgeModel *> *)knowledges index:(NSInteger)idx targetView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
