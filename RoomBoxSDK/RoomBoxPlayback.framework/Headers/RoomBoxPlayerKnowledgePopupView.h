//
//  RoomBoxPlayerKnowledgePopupView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/13.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import "RoomBoxPlayerPopupView.h"

@class RoomBoxPlayerKnowledgeModel;
@class RoomBoxPlayerKnowledgePopupView;

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerKnowledgePopupViewDelegate <NSObject>

- (void)knowledgePopupView:(RoomBoxPlayerKnowledgePopupView *)view selectedKnowledge:(RoomBoxPlayerKnowledgeModel *)knowledge;
- (void)knowledgePopupView:(RoomBoxPlayerKnowledgePopupView *)view deleteKnowledge:(RoomBoxPlayerKnowledgeModel *)knowledge;

@end

@interface RoomBoxPlayerKnowledgePopupView : RoomBoxPlayerPopupView

@property (nonatomic, weak) id<RoomBoxPlayerKnowledgePopupViewDelegate> delegate;

- (void)popupWithKnowledges:(NSArray<RoomBoxPlayerKnowledgeModel *> *)knowledges
         currentSelectIndex:(NSInteger)index
                 targetView:(UIView *)targetView
              containerView:(UIView *)containerView;

@end

NS_ASSUME_NONNULL_END
