// FILENAME: RoomBoxIMRoomV1.h
//
//  Created by 赵亮 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import "RoomV1Tcp.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMRoomV1 : NSObject


// 删除房间属性
+ (void)postAttrCleanSend:(RoomV1PostAttrCleanRequest *)request andBlock:(void (^)(RoomV1PostAttrCleanReply * _Nullable reply))block;


// 删除房间属性
+ (void)postAttrDeleteSend:(RoomV1PostAttrDeleteRequest *)request andBlock:(void (^)(RoomV1PostAttrDeleteReply * _Nullable reply))block;


// 查询房间属性
+ (void)postAttrQuerySend:(RoomV1PostAttrQueryRequest *)request andBlock:(void (^)(RoomV1PostAttrQueryReply * _Nullable reply))block;


// 设置房间属性
+ (void)postAttrSetSend:(RoomV1PostAttrSetRequest *)request andBlock:(void (^)(RoomV1PostAttrSetReply * _Nullable reply))block;


// 进入房间
+ (void)postEnterSend:(RoomV1PostEnterRequest *)request andBlock:(void (^)(RoomV1PostEnterReply * _Nullable reply))block;


// 退出房间
+ (void)postExitSend:(RoomV1PostExitRequest *)request andBlock:(void (^)(RoomV1PostExitReply * _Nullable reply))block;


// 获取房间信息
+ (void)postInfoSend:(RoomV1PostInfoRequest *)request andBlock:(void (^)(RoomV1PostInfoReply * _Nullable reply))block;


// 消息确认
+ (void)postMsgAckSend:(RoomV1PostMsgAckRequest *)request andBlock:(void (^)(RoomV1PostMsgAckReply * _Nullable reply))block;


// 消息历史
+ (void)postMsgHistorySend:(RoomV1PostMsgHistoryRequest *)request andBlock:(void (^)(RoomV1PostMsgHistoryReply * _Nullable reply))block;


// 发送消息
+ (void)postMsgSendSend:(RoomV1PostMsgSendRequest *)request andBlock:(void (^)(RoomV1PostMsgSendReply * _Nullable reply))block;


// 发送图片
+ (void)postMsgSendPicSend:(RoomV1PostMsgSendPicRequest *)request andBlock:(void (^)(RoomV1PostMsgSendPicReply * _Nullable reply))block;


// 发送文本消息
+ (void)postMsgSendTextSend:(RoomV1PostMsgSendTextRequest *)request andBlock:(void (^)(RoomV1PostMsgSendTextReply * _Nullable reply))block;


// 消息撤回
+ (void)postWithdrawSend:(RoomV1PostWithdrawRequest *)request andBlock:(void (^)(RoomV1PostWithdrawReply * _Nullable reply))block;


@end

NS_ASSUME_NONNULL_END
