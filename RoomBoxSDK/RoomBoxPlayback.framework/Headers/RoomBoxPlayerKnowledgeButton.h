//
//  RoomBoxPlayerKnowledgeButton.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/17.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import "RoomBoxPlayerButton.h"
#import "RoomBoxPlayerKnowledgeModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RoomBoxPlayerKnowledgeButtonStyle) {
    RoomBoxPlayerKnowledgeButtonStyleGreen,
    RoomBoxPlayerKnowledgeButtonStyleOrange,
};

@interface RoomBoxPlayerKnowledgeButton : RoomBoxPlayerButton

@property (nonatomic, weak) RoomBoxPlayerKnowledgeModel *model;

- (void)configUI:(BOOL)viewed style:(RoomBoxPlayerKnowledgeButtonStyle)style;

@end

NS_ASSUME_NONNULL_END
