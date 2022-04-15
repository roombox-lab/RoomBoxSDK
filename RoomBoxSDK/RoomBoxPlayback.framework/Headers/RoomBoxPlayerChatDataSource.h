//
//  RoomBoxPlayerChatDataSource.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomBoxPlayerRefreshFooterView.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerChatDataSource : NSObject <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, weak) UITableView *tableView;
@property (nonatomic, weak) UIView *emptyView;
@property (nonatomic, weak) RoomBoxPlayerRefreshFooterView *footer;

@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *token;

- (void)requestData;
- (void)loadMoreData;

@end

NS_ASSUME_NONNULL_END
