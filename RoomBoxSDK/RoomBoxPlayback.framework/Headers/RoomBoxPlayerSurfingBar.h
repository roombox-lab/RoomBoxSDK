//
//  RoomBoxPlayerSurfingBar.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/18.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxPlayerKnowledgeModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerSurfingBarDelegate <NSObject>

@optional
- (void)playerSurfingBarOnSelectKnowledges:(NSArray *)dataArray selectedIndex:(NSInteger)selectedIndex targetView:(UIView *)targetView;

@end

@interface RoomBoxPlayerSurfingBar : UIView

@property (nonatomic, weak) id<RoomBoxPlayerSurfingBarDelegate> delegate;

- (void)setTotalTime:(NSTimeInterval)totalTime;
- (void)addKnowledgeFromArray:(NSArray<RoomBoxPlayerKnowledgeModel *> *)array;

@end

NS_ASSUME_NONNULL_END
