//
//  RoomBoxABPlayerKnowledgeListView.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/19.
//

#import <UIKit/UIKit.h>
@protocol RoomBoxABPlayerKnowledgeListViewDataSource;

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxABPlayerKnowledgeListBubbleView : UIView


- (void)fillContentWithData:(id<RoomBoxABPlayerKnowledgeListViewDataSource>)data;

@end

NS_ASSUME_NONNULL_END
