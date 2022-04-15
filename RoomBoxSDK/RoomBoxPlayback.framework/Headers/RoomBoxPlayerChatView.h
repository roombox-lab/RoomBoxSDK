//
//  RoomBoxPlayerChatView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerChatView : UIView

@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *token;

@property (nonatomic, copy) dispatch_block_t onDismissBlock;

- (void)loadData;
- (void)show:(UIButton *)sender;
- (void)dismiss;

@end

NS_ASSUME_NONNULL_END
