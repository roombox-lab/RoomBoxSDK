//
//  RoomBoxABPlayerKnowledgeSelectView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
@class RoomBoxPlayerKnowledgeModel;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    RoomBoxABPlayerKnowledgeSelectViewTypeList = 0, //知识点列表模式
    RoomBoxABPlayerKnowledgeSelectViewTypeTimeline, //时间轴知识点模式
} RoomBoxABPlayerKnowledgeSelectViewType;

@protocol RoomBoxABPlayerKnowledgeSelectViewDelegate <NSObject>

@optional
- (void)knowledgeSelectViewOnDismiss;
- (void)knowledgeSelectViewChangedQuickLookModeTo:(BOOL)model;
- (void)knowledgeSelectViewOnSelectknowledge:(RoomBoxPlayerKnowledgeModel *)knowledge;

@end

@interface RoomBoxABPlayerKnowledgeSelectView : UIView

@property (nonatomic, weak) id<RoomBoxABPlayerKnowledgeSelectViewDelegate> delegate;
@property (nonatomic, assign) RoomBoxABPlayerKnowledgeSelectViewType selectViewType;

- (void)updateKnowledges:(NSArray<RoomBoxPlayerKnowledgeModel *> *)knowledges currentKnowledge:(RoomBoxPlayerKnowledgeModel *)currentKnowledge;
- (void)updateCurrentKnowledge:(RoomBoxPlayerKnowledgeModel *)currentKnowledge;
- (void)updateTotalTimeShortString:(NSString *)timeValue;

- (void)showPanelView:(UIView *)targetView ;
//取消快览模式
- (void)cancelQuickLookMode;

@end

NS_ASSUME_NONNULL_END
