// FILENAME: RoomBoxIMClassV1.h
//
//  Created by 赵亮 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import "ClassV1Tcp.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMClassV1 : NSObject


// 教室动态信息/定时获取
+ (void)postActiveSend:(ClassV1PostActiveRequest *)request andBlock:(void (^)(ClassV1PostActiveReply * _Nullable reply))block;


// 更新教室权限
+ (void)postCommonSetUpdateSend:(ClassV1PostCommonSetUpdateRequest *)request andBlock:(void (^)(ClassV1PostCommonSetUpdateReply * _Nullable reply))block;


// 进入教室
+ (void)postEnterSend:(ClassV1PostEnterRequest *)request andBlock:(void (^)(ClassV1PostEnterReply * _Nullable reply))block;


// 离开教室
+ (void)postExitSend:(ClassV1PostExitRequest *)request andBlock:(void (^)(ClassV1PostExitReply * _Nullable reply))block;


// 获取教室分班信息
+ (void)postGradesSend:(ClassV1PostGradesRequest *)request andBlock:(void (^)(ClassV1PostGradesReply * _Nullable reply))block;


// 获取教室信息
+ (void)postInfoSend:(ClassV1PostInfoRequest *)request andBlock:(void (^)(ClassV1PostInfoReply * _Nullable reply))block;


// 更新教室模式
+ (void)postModeUpdateSend:(ClassV1PostModeUpdateRequest *)request andBlock:(void (^)(ClassV1PostModeUpdateReply * _Nullable reply))block;


// 消息删除
+ (void)postMsgDelSend:(ClassV1PostMsgDelRequest *)request andBlock:(void (^)(ClassV1PostMsgDelReply * _Nullable reply))block;


// 更新教室面板模式
+ (void)postPanelModeUpdateSend:(ClassV1PostPanelModeUpdateRequest *)request andBlock:(void (^)(ClassV1PostPanelModeUpdateReply * _Nullable reply))block;


// 更新（上课时）教室录播播放模式
+ (void)postRecorderModeUpdateSend:(ClassV1PostRecorderModeUpdateRequest *)request andBlock:(void (^)(ClassV1PostRecorderModeUpdateReply * _Nullable reply))block;


// 获取花名册
+ (void)postRostersSend:(ClassV1PostRostersRequest *)request andBlock:(void (^)(ClassV1PostRostersReply * _Nullable reply))block;


// 教室统计数据上报
+ (void)postStaticUpdateSend:(ClassV1PostStaticUpdateRequest *)request andBlock:(void (^)(ClassV1PostStaticUpdateReply * _Nullable reply))block;


// 获取学员列表
+ (void)postStudentsSend:(ClassV1PostStudentsRequest *)request andBlock:(void (^)(ClassV1PostStudentsReply * _Nullable reply))block;


// 更新设备变化/ 进入教室时，传入初始值，当变化时传入
+ (void)postStudentsDeviceStatusSend:(ClassV1PostStudentsDeviceStatusRequest *)request andBlock:(void (^)(ClassV1PostStudentsDeviceStatusReply * _Nullable reply))block;


// 批量获取学员信息
+ (void)postStudentsInfosSend:(ClassV1PostStudentsInfosRequest *)request andBlock:(void (^)(ClassV1PostStudentsInfosReply * _Nullable reply))block;


// 学生数量
+ (void)postStudentsNumbersSend:(ClassV1PostStudentsNumbersRequest *)request andBlock:(void (^)(ClassV1PostStudentsNumbersReply * _Nullable reply))block;


// 随机获取学生
+ (void)postStudentsRandomSend:(ClassV1PostStudentsRandomRequest *)request andBlock:(void (^)(ClassV1PostStudentsRandomReply * _Nullable reply))block;


// 更新学员统计信息 固定，每30秒统计,如果有更新则更新，无更新就不用请求，【用户退出前，请求一次】
+ (void)postStudentsStaticUpdateSend:(ClassV1PostStudentsStaticUpdateRequest *)request andBlock:(void (^)(ClassV1PostStudentsStaticUpdateReply * _Nullable reply))block;


// 获取自己的用户信息
+ (void)postUserInfoSend:(ClassV1PostUserInfoRequest *)request andBlock:(void (^)(ClassV1PostUserInfoReply * _Nullable reply))block;


// 学员权限更新(http://cwiki.yclassroom.com/pages/viewpage.action?pageId=13242853)
+ (void)postUsersRightUpdateSend:(ClassV1PostUsersRightUpdateRequest *)request andBlock:(void (^)(ClassV1PostUsersRightUpdateReply * _Nullable reply))block;


// 用户状态更新
+ (void)postUsersStatusUpdateSend:(ClassV1PostUsersStatusUpdateRequest *)request andBlock:(void (^)(ClassV1PostUsersStatusUpdateReply * _Nullable reply))block;


// 学员权限更新
+ (void)postUsersSwitchUpdateSend:(ClassV1PostUsersSwitchUpdateRequest *)request andBlock:(void (^)(ClassV1PostUsersSwitchUpdateReply * _Nullable reply))block;


// 班级版本管理
+ (void)postVersionsManagersSend:(ClassV1PostVersionsManagersRequest *)request andBlock:(void (^)(ClassV1PostVersionsManagersReply * _Nullable reply))block;


@end

NS_ASSUME_NONNULL_END
