//
//  RoomBoxPlayerInvalidView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/24.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerInvalidView : UIView

@property (nonatomic, copy) dispatch_block_t onActionBlock;

- (void)updateDesclabel:(NSString *)title;
@end

NS_ASSUME_NONNULL_END
