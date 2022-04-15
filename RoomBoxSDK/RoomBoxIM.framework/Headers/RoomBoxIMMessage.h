//
//  RoomBoxIMMessage.h
//  RoomBoxIM
//
//  Created by 赵亮 on 2021/6/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef enum RoomBoxIMRole {
    NoneRole = 0,   // 无效角色
    User = 1,       // 用户
    Room = 2,       // 房间
    JID = 3,       // 连接ID
    Tag = 4,        // 标签
    Server = 5,     // 服务
    VGroup = 6,     // 虚拟组
    Device = 7,     // 设备
    Connect = 8,    // 连接模式
}RoomBoxIMRole;


typedef enum  RoomBoxIMContentType {
    JSON = 0,
    PB = 1,
}RoomBoxIMContentType;

@interface RoomBoxIMMessage : NSObject

@property (nonatomic,strong) NSString *msgID;

@property (nonatomic,strong) NSString *type;

@property (nonatomic,strong) NSString *sendType;

@property (nonatomic,strong) NSString *sendId;

@property (nonatomic,strong) NSData *content;

@property (nonatomic,assign) RoomBoxIMContentType contentType;

@property (nonatomic,strong) NSString *strExtra;

@property (nonatomic,strong) NSData *bExtra;

@property (nonatomic,assign) UInt64 sendTime;

@property (nonatomic,assign) RoomBoxIMRole sendRole;


@end

NS_ASSUME_NONNULL_END
