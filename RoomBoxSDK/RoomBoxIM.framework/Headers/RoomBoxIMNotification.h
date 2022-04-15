// FILENAME: RoomBoxIMNotification.h
//  RoomBoxIM
//

#import <Foundation/Foundation.h>
#import "RoomBoxIMMessage.h"
#import "NotifyNotify.pbobjc.h"


NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMNotification : NSObject


// NOTIFY Galaxy:Location 位置消息内容
+ (void)receiveRoomBoxIMNotifyGalaxyLocationNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyLocation * __nonnull body))block;


// NOTIFY Galaxy:Pic 图片消息内容
+ (void)receiveRoomBoxIMNotifyGalaxyPicNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyPic * __nonnull body))block;


// NOTIFY Galaxy:Temporary 临时测试专用结构类型
+ (void)receiveRoomBoxIMNotifyGalaxyTemporaryNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyTemporary * __nonnull body))block;


// NOTIFY Galaxy:Text 文本消息内容 消息内容
+ (void)receiveRoomBoxIMNotifyGalaxyTextNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyText * __nonnull body))block;


// NOTIFY Galaxy:Withdraw 消息撤回通知
+ (void)receiveRoomBoxIMNotifyGalaxyWithdrawNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyWithdraw * __nonnull body))block;


// NOTIFY roombox:phoenix:add_board AddBoardNotify 添加白板广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixAddBoardNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixAddBoard * __nonnull body))block;


// NOTIFY roombox:phoenix:trans_board TransBoardNotify 透传白板通知
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixTransBoardNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixTransBoard * __nonnull body))block;


// NOTIFY roombox:phoenix:operation OperationNotify 白板操作广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixOperationNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixOperation * __nonnull body))block;


// NOTIFY roombox:phoenix:add_attr AddAttrNotify 添加属性广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixAddAttrNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixAddAttr * __nonnull body))block;


// NOTIFY roombox:phoenix:del_attr DelAttrNotify 添加属性广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixDelAttrNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixDelAttr * __nonnull body))block;


// NOTIFY roombox:phoenix:clean_attr CleanAttrNotify 添加属性广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixCleanAttrNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixCleanAttr * __nonnull body))block;


// NOTIFY roombox:phoenix:random_choose RandomChooseNotify 随机选人通知
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixRandomChooseNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixRandomChoose * __nonnull body))block;


// NOTIFY roombox:phoenix:responder:open ResponderOpenNotify 开启抢答器广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixResponderOpenNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixResponderOpen * __nonnull body))block;


// NOTIFY roombox:phoenix:responder:rob ResponderRobNotify 抢抢答器广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixResponderRobNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixResponderRob * __nonnull body))block;


// NOTIFY roombox:phoenix:responder:close ResponderCloseNotify 关闭抢答器广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixResponderCloseNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixResponderClose * __nonnull body))block;


// NOTIFY roombox:phoenix:set_multi_attr SetMultiAttrNotify 添加属性广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSetMultiAttrNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSetMultiAttr * __nonnull body))block;


// NOTIFY roombox:phoenix:clean_multi_attr CleanMultiAttrNotify 清空增量属性广播
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixCleanMultiAttrNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixCleanMultiAttr * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:class_info SmallBdClassInfoNotify
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdClassInfoNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdClassInfo * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:give
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdGiveNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdGive * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:ungive
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdUngiveNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdUngive * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:op
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdOpNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdOp * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:praise
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdPraiseNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdPraise * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:pub
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdPubNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdPub * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:unpub
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdUnpubNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdUnpub * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:praise_pub
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdPraisePubNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdPraisePub * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:close
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdCloseNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdClose * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:lock
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdLockNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdLock * __nonnull body))block;


// NOTIFY roombox:phoenix:smallbd:unlock
+ (void)receiveRoomBoxIMNotifyRoomboxPhoenixSmallbdUnlockNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxPhoenixSmallbdUnlock * __nonnull body))block;


// NOTIFY roombox:class:student_change 【 端上比对自己本地的版本+1是否等于开始版本，如果不等，说明版本错误 】 每个班级会聚合发送，所以有开始版本和结束版本 学生加入房间，学生信息更改-> 用于学生在线列表的变化
+ (void)receiveRoomBoxIMNotifyRoomboxClassStudentChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassStudentChange * __nonnull body))block;


// NOTIFY roombox:class:user_join_exit 老师/助教/其他身份加入教室
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserJoinExitNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserJoinExit * __nonnull body))block;


// NOTIFY roombox:class:student_numbers_update 学生数量变化通知
+ (void)receiveRoomBoxIMNotifyRoomboxClassStudentNumbersUpdateNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassStudentNumbersUpdate * __nonnull body))block;


// NOTIFY roombox:class:class_info_change 教室信息变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassInfoChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassInfoChange * __nonnull body))block;


// NOTIFY roombox:class:class_ver_manager_change 教室版本管理器信息变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassVerManagerChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassVerManagerChange * __nonnull body))block;


// NOTIFY roombox:class:class_mode_change 教室模式变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassModeChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassModeChange * __nonnull body))block;


// NOTIFY roombox:class:class_panel_mode_change 教室面板模式变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassPanelModeChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassPanelModeChange * __nonnull body))block;


// NOTIFY roombox:class:class_common_set_change 教室授权变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassCommonSetChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassCommonSetChange * __nonnull body))block;


// NOTIFY roombox:class:class_rtc_sdk_change 教室Rtc版本变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassRtcSdkChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassRtcSdkChange * __nonnull body))block;


// NOTIFY roombox:class:class_close 教室关闭
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassCloseNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassClose * __nonnull body))block;


// NOTIFY roombox:class:user_switch_update 用户开关变化
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserSwitchUpdateNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserSwitchUpdate * __nonnull body))block;


// NOTIFY roombox:class:user_right_update 用户权限变化，用户通知自己
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserRightUpdateNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserRightUpdate * __nonnull body))block;


// NOTIFY roombox:class:user_kit_out 用户被踢出
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserKitOutNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserKitOut * __nonnull body))block;


// NOTIFY roombox:class:roster_change 花名册变化
+ (void)receiveRoomBoxIMNotifyRoomboxClassRosterChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassRosterChange * __nonnull body))block;


// NOTIFY roombox:class:user_star_change 用户星星变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserStarChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserStarChange * __nonnull body))block;


// NOTIFY roombox:class:user_info_change 用户信息变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserInfoChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserInfoChange * __nonnull body))block;


// NOTIFY roombox:class:class_recorder_mode_change (上课时）教室录播播放模式
+ (void)receiveRoomBoxIMNotifyRoomboxClassClassRecorderModeChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassClassRecorderModeChange * __nonnull body))block;


// NOTIFY roombox:class:wall_user_info_change 上墙用户信息变更
+ (void)receiveRoomBoxIMNotifyRoomboxClassWallUserInfoChangeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassWallUserInfoChange * __nonnull body))block;


// NOTIFY roombox:class:user_enter_txt 用户加入教室文本通知
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserEnterTxtNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserEnterTxt * __nonnull body))block;


// NOTIFY roombox:class:user_like_info 用户点赞通知
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserLikeInfoNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserLikeInfo * __nonnull body))block;


// NOTIFY roombox:class:user_total_num 主教室用户总数量通知
+ (void)receiveRoomBoxIMNotifyRoomboxClassUserTotalNumNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxClassUserTotalNum * __nonnull body))block;


// NOTIFY Quiz:send                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyQuizSendNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyQuizSend * __nonnull body))block;


// NOTIFY Quiz:finish                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyQuizFinishNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyQuizFinish * __nonnull body))block;


// NOTIFY Quiz:giveAlike                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyQuizGiveAlikeNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyQuizGiveAlike * __nonnull body))block;


// NOTIFY Quiz:prick                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyQuizPrickNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyQuizPrick * __nonnull body))block;


// NOTIFY Exam:finish                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyExamFinishNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyExamFinish * __nonnull body))block;


// NOTIFY Exam:send                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的答题卡
+ (void)receiveRoomBoxIMNotifyExamSendNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyExamSend * __nonnull body))block;


// NOTIFY Star:send_red_package                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type 老师发的红包信息
+ (void)receiveRoomBoxIMNotifyStarSendRedPackageNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyStarSendRedPackage * __nonnull body))block;


// NOTIFY Galaxy:Room:BanChat 房间全体禁言通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomBanChatNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomBanChat * __nonnull body))block;


// NOTIFY Galaxy:Room:BanUserChat 房间禁言用户通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomBanUserChatNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomBanUserChat * __nonnull body))block;


// NOTIFY Galaxy:Room:Embed 房间嵌套信息变更通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomEmbedNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomEmbed * __nonnull body))block;


// NOTIFY Galaxy:Room:Enter 进房间通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomEnterNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomEnter * __nonnull body))block;


// NOTIFY Galaxy:Room:Exit 退出房间通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomExitNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomExit * __nonnull body))block;


// NOTIFY Galaxy:Room:Info 房间信息变更通知
+ (void)receiveRoomBoxIMNotifyGalaxyRoomInfoNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyGalaxyRoomInfo * __nonnull body))block;


// 下面这行注释不能删除, svc会解析 NOTIFY JavaNotify:CoursewareUpdate
+ (void)receiveRoomBoxIMNotifyJavaNotifyCoursewareUpdateNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyJavaNotifyCoursewareUpdate * __nonnull body))block;


// NOTIFY roombox:norma:hands_up_list HandsUpListChangeNotify 举手列表变化通知
+ (void)receiveRoomBoxIMNotifyRoomboxNormaHandsUpListNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxNormaHandsUpList * __nonnull body))block;


// NOTIFY roombox:norma:hands_up_clear HandsUpListChangeNotify 举手列表清空通知
+ (void)receiveRoomBoxIMNotifyRoomboxNormaHandsUpClearNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxNormaHandsUpClear * __nonnull body))block;


// NOTIFY roombox:norma:subscribe_state SubscribeStateNotify 被订阅状态通知
+ (void)receiveRoomBoxIMNotifyRoomboxNormaSubscribeStateNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyRoomboxNormaSubscribeState * __nonnull body))block;


// 运营位变更通知                           // message 注释说明（可不写） NOTIFY JavaNotify:OperationPosition                   // 特殊注释行，以NOTIFY开头的注释具有特殊意义，后面表示下面的message的type
+ (void)receiveRoomBoxIMNotifyJavaNotifyOperationPositionNotifyUsingBlock:(void (^)(RoomBoxIMMessage * __nonnull message, RoomBoxIMNotifyJavaNotifyOperationPosition * __nonnull body))block;


@end

NS_ASSUME_NONNULL_END

