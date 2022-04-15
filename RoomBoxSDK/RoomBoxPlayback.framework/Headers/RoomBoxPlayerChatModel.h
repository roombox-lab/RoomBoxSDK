//
//  RoomBoxPlayerChatModel.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RoomBoxPlayerChatMsgType) {
    RoomBoxPlayerChatMsgTypeText = 1,
    RoomBoxPlayerChatMsgTypeImage = 2,
};

@interface RoomBoxPlayerChatContent : NSObject

@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) RoomBoxPlayerChatMsgType type;

@end

@interface RoomBoxPlayerChatModel : NSObject

// interface define
@property (nonatomic, copy) NSString *msgId;
@property (nonatomic, assign) NSInteger uid;
@property (nonatomic, assign) NSInteger role;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *realName;
@property (nonatomic, assign) NSInteger sentTime;
@property (nonatomic, copy) NSString *option;
@property (nonatomic, copy) NSArray<RoomBoxPlayerChatContent *> *content;

// self define
@property (nonatomic, assign) BOOL isMine;  // 消息是否是我发出的

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (RoomBoxPlayerChatContent *)msgContent;

- (CGFloat)height;
- (NSString *)dateString;
- (NSAttributedString *)msgAttributedString;

@end

NS_ASSUME_NONNULL_END
