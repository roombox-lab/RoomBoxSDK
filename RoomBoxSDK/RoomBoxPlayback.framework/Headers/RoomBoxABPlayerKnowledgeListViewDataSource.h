//
//  RoomBoxABPlayerKnowledgeListViewDataSource.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxABPlayerKnowledgeListItemViewSource <NSObject>

@property (nonatomic, copy) NSString *knowledgeItemViewTitle;

@property (nonatomic, copy) NSString *knowledgeItemViewContent;


@end

@protocol RoomBoxABPlayerKnowledgeListViewDataSource <NSObject>

@property (nonatomic, copy) NSArray <id<RoomBoxABPlayerKnowledgeListItemViewSource>> *knowledgeListDataSource;

@end

NS_ASSUME_NONNULL_END
