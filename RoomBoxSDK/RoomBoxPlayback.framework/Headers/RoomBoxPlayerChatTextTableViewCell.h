//
//  RoomBoxPlayerChatTextTableViewCell.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxPlayerChatModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerChatTextTableViewCell : UITableViewCell

- (void)updateData:(RoomBoxPlayerChatModel *)data;

@end

NS_ASSUME_NONNULL_END
