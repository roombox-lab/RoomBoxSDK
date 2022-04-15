// FILENAME: RoomBoxIMPhoenixV1.h
//
//  Created by 赵亮 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import "PhoenixV1Tcp.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMPhoenixV1 : NSObject


// 添加教室kv存储
+ (void)postAttrAddSend:(PhoenixV1PostAttrAddRequest *)request andBlock:(void (^)(PhoenixV1PostAttrAddReply * _Nullable reply))block;


// 清空教室kv存储
+ (void)postAttrCleanSend:(PhoenixV1PostAttrCleanRequest *)request andBlock:(void (^)(PhoenixV1PostAttrCleanReply * _Nullable reply))block;


// 删除教室kv存储
+ (void)postAttrDelSend:(PhoenixV1PostAttrDelRequest *)request andBlock:(void (^)(PhoenixV1PostAttrDelReply * _Nullable reply))block;


// 获取教室kv存储
+ (void)postAttrGetSend:(PhoenixV1PostAttrGetRequest *)request andBlock:(void (^)(PhoenixV1PostAttrGetReply * _Nullable reply))block;


// 添加白板数据
+ (void)postBoardAddSend:(PhoenixV1PostBoardAddRequest *)request andBlock:(void (^)(PhoenixV1PostBoardAddReply * _Nullable reply))block;


// 获取白板数据
+ (void)postBoardGetSend:(PhoenixV1PostBoardGetRequest *)request andBlock:(void (^)(PhoenixV1PostBoardGetReply * _Nullable reply))block;


// 设置操作数据
+ (void)postBoardOperateSend:(PhoenixV1PostBoardOperateRequest *)request andBlock:(void (^)(PhoenixV1PostBoardOperateReply * _Nullable reply))block;


// 透传白板数据
+ (void)postBoardTransSend:(PhoenixV1PostBoardTransRequest *)request andBlock:(void (^)(PhoenixV1PostBoardTransReply * _Nullable reply))block;


// 获取板书版本
+ (void)postBoardVersionSend:(PhoenixV1PostBoardVersionRequest *)request andBlock:(void (^)(PhoenixV1PostBoardVersionReply * _Nullable reply))block;


// 
+ (void)postMultiAttrCleanSend:(PhoenixV1PostMultiAttrCleanRequest *)request andBlock:(void (^)(PhoenixV1PostMultiAttrCleanReply * _Nullable reply))block;


// 获取属性存储可根据版本号获取增量
+ (void)postMultiAttrGetSend:(PhoenixV1PostMultiAttrGetRequest *)request andBlock:(void (^)(PhoenixV1PostMultiAttrGetReply * _Nullable reply))block;


// 添加属性存储（可增量，可覆盖）
+ (void)postMultiAttrSetSend:(PhoenixV1PostMultiAttrSetRequest *)request andBlock:(void (^)(PhoenixV1PostMultiAttrSetReply * _Nullable reply))block;


// 添加空白页
+ (void)postPageAddSend:(PhoenixV1PostPageAddRequest *)request andBlock:(void (^)(PhoenixV1PostPageAddReply * _Nullable reply))block;


// 删除空白页
+ (void)postPageDelSend:(PhoenixV1PostPageDelRequest *)request andBlock:(void (^)(PhoenixV1PostPageDelReply * _Nullable reply))block;


// 页列表信息
+ (void)postPageInfoSend:(PhoenixV1PostPageInfoRequest *)request andBlock:(void (^)(PhoenixV1PostPageInfoReply * _Nullable reply))block;


// 设置教材总页码
+ (void)postPageNumsSend:(PhoenixV1PostPageNumsRequest *)request andBlock:(void (^)(PhoenixV1PostPageNumsReply * _Nullable reply))block;


// 随机选择
+ (void)postRandomChooseSend:(PhoenixV1PostRandomChooseRequest *)request andBlock:(void (^)(PhoenixV1PostRandomChooseReply * _Nullable reply))block;


// 获取随机选择信息
+ (void)postRandomChooseGetSend:(PhoenixV1PostRandomChooseGetRequest *)request andBlock:(void (^)(PhoenixV1PostRandomChooseGetReply * _Nullable reply))block;


// 
+ (void)postResponderCloseSend:(PhoenixV1PostResponderCloseRequest *)request andBlock:(void (^)(PhoenixV1PostResponderCloseReply * _Nullable reply))block;


// 
+ (void)postResponderLatestSend:(PhoenixV1PostResponderLatestRequest *)request andBlock:(void (^)(PhoenixV1PostResponderLatestReply * _Nullable reply))block;


// 
+ (void)postResponderOpenSend:(PhoenixV1PostResponderOpenRequest *)request andBlock:(void (^)(PhoenixV1PostResponderOpenReply * _Nullable reply))block;


// 
+ (void)postResponderRobSend:(PhoenixV1PostResponderRobRequest *)request andBlock:(void (^)(PhoenixV1PostResponderRobReply * _Nullable reply))block;


// 
+ (void)postSmallbdClassInfoSend:(PhoenixV1PostSmallbdClassInfoRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdClassInfoReply * _Nullable reply))block;


// 
+ (void)postSmallbdCloseSend:(PhoenixV1PostSmallbdCloseRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdCloseReply * _Nullable reply))block;


// 
+ (void)postSmallbdConfSend:(PhoenixV1PostSmallbdConfRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdConfReply * _Nullable reply))block;


// 
+ (void)postSmallbdGiveSend:(PhoenixV1PostSmallbdGiveRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdGiveReply * _Nullable reply))block;


// 
+ (void)postSmallbdInfoSend:(PhoenixV1PostSmallbdInfoRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdInfoReply * _Nullable reply))block;


// 
+ (void)postSmallbdLockSend:(PhoenixV1PostSmallbdLockRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdLockReply * _Nullable reply))block;


// 
+ (void)postSmallbdOpSend:(PhoenixV1PostSmallbdOpRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdOpReply * _Nullable reply))block;


// 老师赞扬
+ (void)postSmallbdPraiseSend:(PhoenixV1PostSmallbdPraiseRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdPraiseReply * _Nullable reply))block;


// 
+ (void)postSmallbdPubSend:(PhoenixV1PostSmallbdPubRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdPubReply * _Nullable reply))block;


// 
+ (void)postSmallbdPubPraiseSend:(PhoenixV1PostSmallbdPubPraiseRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdPubPraiseReply * _Nullable reply))block;


// 收到小黑板上报
+ (void)postSmallbdReceiveSend:(PhoenixV1PostSmallbdReceiveRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdReceiveReply * _Nullable reply))block;


// 
+ (void)postSmallbdSearchSend:(PhoenixV1PostSmallbdSearchRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdSearchReply * _Nullable reply))block;


// 
+ (void)postSmallbdSnoteSend:(PhoenixV1PostSmallbdSnoteRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdSnoteReply * _Nullable reply))block;


// 
+ (void)postSmallbdSnoteReportSend:(PhoenixV1PostSmallbdSnoteReportRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdSnoteReportReply * _Nullable reply))block;


// 
+ (void)postSmallbdStuInfoSend:(PhoenixV1PostSmallbdStuInfoRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdStuInfoReply * _Nullable reply))block;


// 
+ (void)postSmallbdUngiveSend:(PhoenixV1PostSmallbdUngiveRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdUngiveReply * _Nullable reply))block;


// 
+ (void)postSmallbdUnlockSend:(PhoenixV1PostSmallbdUnlockRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdUnlockReply * _Nullable reply))block;


// 
+ (void)postSmallbdUnpubSend:(PhoenixV1PostSmallbdUnpubRequest *)request andBlock:(void (^)(PhoenixV1PostSmallbdUnpubReply * _Nullable reply))block;


@end

NS_ASSUME_NONNULL_END
