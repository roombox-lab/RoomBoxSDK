// FILENAME: RoomBoxIMNormaV1.h
//
//  Created by 赵亮 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import "NormaV1Tcp.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMNormaV1 : NSObject


// 要求更新avcontrol list
+ (void)postAvcontrolGetSend:(NormaV1PostAvcontrolGetRequest *)request andBlock:(void (^)(NormaV1PostAvcontrolGetReply * _Nullable reply))block;


// 全量更新上墙连麦和轮台数据
+ (void)postAvcontrolUpdateSend:(NormaV1PostAvcontrolUpdateRequest *)request andBlock:(void (^)(NormaV1PostAvcontrolUpdateReply * _Nullable reply))block;


// 清除学生举手信息
+ (void)postHandsUpClearSend:(NormaV1PostHandsUpClearRequest *)request andBlock:(void (^)(NormaV1PostHandsUpClearReply * _Nullable reply))block;


// 学生举手落手
+ (void)postHandsUpHandsSend:(NormaV1PostHandsUpHandsRequest *)request andBlock:(void (^)(NormaV1PostHandsUpHandsReply * _Nullable reply))block;


// 学生举手信息列表
+ (void)postHandsUpListSend:(NormaV1PostHandsUpListRequest *)request andBlock:(void (^)(NormaV1PostHandsUpListReply * _Nullable reply))block;


// 老师回应学生举手
+ (void)postHandsUpResponseSend:(NormaV1PostHandsUpResponseRequest *)request andBlock:(void (^)(NormaV1PostHandsUpResponseReply * _Nullable reply))block;


// 给举手的学生发星星
+ (void)postHandsUpStarSend:(NormaV1PostHandsUpStarRequest *)request andBlock:(void (^)(NormaV1PostHandsUpStarReply * _Nullable reply))block;


// 举手功能开关
+ (void)postHandsUpSwitchSend:(NormaV1PostHandsUpSwitchRequest *)request andBlock:(void (^)(NormaV1PostHandsUpSwitchReply * _Nullable reply))block;


// 给的学生组发星星
+ (void)postStarAddSend:(NormaV1PostStarAddRequest *)request andBlock:(void (^)(NormaV1PostStarAddReply * _Nullable reply))block;


// 签到发星星
+ (void)postStarSignSend:(NormaV1PostStarSignRequest *)request andBlock:(void (^)(NormaV1PostStarSignReply * _Nullable reply))block;


// 
+ (void)postStarSignConfSend:(NormaV1PostStarSignConfRequest *)request andBlock:(void (^)(NormaV1PostStarSignConfReply * _Nullable reply))block;


// 全量更新用户订阅列表
+ (void)postSubscribeSend:(NormaV1PostSubscribeRequest *)request andBlock:(void (^)(NormaV1PostSubscribeReply * _Nullable reply))block;


// 获取订阅列表
+ (void)postSubscribeInfoSend:(NormaV1PostSubscribeInfoRequest *)request andBlock:(void (^)(NormaV1PostSubscribeInfoReply * _Nullable reply))block;


// 获取教室视频控制
+ (void)postVideosSend:(NormaV1PostVideosRequest *)request andBlock:(void (^)(NormaV1PostVideosReply * _Nullable reply))block;


// 更新教室视频控制
+ (void)postVideosUpdateSend:(NormaV1PostVideosUpdateRequest *)request andBlock:(void (^)(NormaV1PostVideosUpdateReply * _Nullable reply))block;


@end

NS_ASSUME_NONNULL_END
