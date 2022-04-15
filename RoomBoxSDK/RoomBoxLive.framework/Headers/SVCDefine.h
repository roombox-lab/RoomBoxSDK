//
//  SVCDefine.h
//  
//
//  Created by www.xdf.cn on 2018/1/23.
//  Copyright © 2018年 www.xdf.cn. All rights reserved.
//

#ifndef SVCDefine_h
#define SVCDefine_h


#endif /* SVCDefine_h */




#pragma mark - SvcConnectState ----------svc连接状态定义
enum SvcConnectState:NSUInteger {
    LBS_Normal = 0,/*LBS未连接*/
    LBS_Connecting = 1,/*LBS连接中*/
    LBS_Connected = 2,/*LBS连接完毕*/
    SVC_Normal = 3,/*SVC未连接*/
    SVC_Connecting = 4,/*SVC连接中*/
    SVC_Connected = 5,/*SVC连接完毕*/
    Close_ByUser = 6,/*Socket被用户断开*/
    Close_ByServer = 7,/*Socket被服务器断开*/
    Error_SvcConnect = 8,/*socket链接发生错误*/
    LoginState_Normal = 9,/*未登录*/
    LoginState_Loginning = 10,/*登录中*/
    LoginState_Logined = 11,/*已登录*/
    SVC_Clientining = 12/*正在执行客户端接入*/
};


#pragma mark - ACCommandType ----------svc协议头定义
enum ACCommandType:uint32_t {
    //未知用法
    SVC_GetUserDotDataSwitch = 0x00110031,//
    SVC_SetUserDotDataSwitch = 0x00110032,//
    SVC_ForceUserOut = 0x00110040,//强制用户退出
    SVC_AppQA = 0x0011001A,//请求app QA
    SVC_SetAppQARecipient = 0x0011001C,//设置app QA接收者
    SVC_ResetAppQARecipient = 0x0011001D,//重置app QA接收者
    SVC_PushUploadLog = 0x00110038,//推送立即上报日志
    SVC_PushUploadLogNotify = 0x00110039,//推送立即上报日志通知
    SVC_SetTimeCheckInterval = 0x00110101,//设置服务器时间校验间隔时长
    SVC_GetTimeCheckInterval = 0x00110102,//获取服务器时间校验间隔时长
    SVC_SetCacheExpireTime = 0x00110104,//设置客户端缓存过期时长
    SVC_GetCacheExpireTime = 0x00110105,//获取客户端缓存过期时长
    SVC_GetClassOrderList = 0x00130030,//
    SVC_AddClassOrderNotify = 0x00130036,//
    SVC_DelClassOrderNotify = 0x00130038,
    SVC_UpdateClassOrderNotify = 0x0013003A,
    SVC_AllocSDKRoomID_C2S = 0x0013003B,
    SVC_DKRoomIDChangeNotify = 0x0013003C,
    SVC_SDKRoomIDFreeNotify = 0x0013003D,
    SVC_SetSDKRoomIDs_C2S = 0x0013003F,
    SVC_CourseMsgNotify = 0x00130052,
    SVC_CourseMsgNotifyNotify = 0x00130053,
    SVC_StuReqExpCourse = 0x00130080,//学生发起体验课呼叫
    SVC_ReqExpCourseNotifyTea = 0x00130081,//将学员的申请通知老师
    SVC_TeaRspExpCourse = 0x00130082,//老师回复学员上体验课的请求
    SVC_RspExpCourseActNotifyStu = 0x00130083,//将老师的回复通知学员
    SVC_StuHangupExpCourse = 0x00130084,//学生挂断体验课
    SVC_HangupExpCourseNotifyTea  = 0x00130085,//将学生挂断通知老师
    SVC_ExpCourseTeaChangeStatus = 0x00130086,//老师更改体验课相关状态
    SVC_MediaSDKBiLi = 0x00130101,//获取AV SDK（YY1、YY2、QQ等）分配比例
    
    //没有数据结构体的
    SVC_AppQANotify = 0x0011001B,//AppQA通知
    
    // 基本
    LBS_ConnectV2 = 0x00100011,                        //负载均衡
    SVC_KeepConnet = 0x00110001,                 //给心跳保持长连接
    SVC_GetHeartBeatConfig = 0x0011000E,//获取心跳配置
    SVC_HeartBeatNotify = 0x0011000F, //心跳配置通知
    SVC_ClientIn = 0x00110011,//接入服务
    SVC_Login = 0x00110012,//登录
    SVC_ForceQuit = 0x00110014,//强制下线
    SVC_Logout = 0x00110013,//登出
    SVC_LoginComplete = 0x00110015,//登录完成
    SVC_ChangeUserLoginState = 0x00110016,//变更个人在线状态
    SVC_UploadUserPoint = 0x00110017,//上报用户打点数据
    SVC_PintTest = 0x00110019,//ping svc协议
    SVC_UploadMediaPoint = 0x0011001E,//上传媒体引擎数据打点
    SVC_SendCustomNotify = 0x00110020,//发布用户自定义通知
    SVC_ReciveCustomNotify = 0x00110021,//收到用户自定义的通知
    SVC_GetOnlineUserNum = 0x00110030,//获取在线用户数
    SVC_NetWorkTest = 0x00110035,//网络质量测试
    SVC_NetWorkTestResultNotify = 0x00110036,//网络质量测试结果通知
    SVC_GetServerTime = 0x00110103,//获取服务器时间
    
   
//======================================================================
    //sac mac client new add command id
     Connect_ForceLogout         = 0x00110014,
    
    
    SVC_Connect_GetUserInfo = 0x00110022,  //获取用户信息请求
    SVC_Connect_UserInfoNotify = 0x00110023,   // 获取用户信息应答
    
    Class_GetClassRoomData = 0x00130008,  //教室内数据 弃用 instead Class_Cmd_ReqGetCourseInfo_c2s
    Class_ClassRoomDataNotify = 0x00130009, //弃用 instead Class_Cmd_RspCourseInfo_s2c
    
    Class_GetClassRoomMemberList = 0x0013000A,  // 教室内成员数据
    Class_ClassRoomDataMemberListNotify = 0x0013000B,
    Class_ClassRoomMaterialReq = 0x0013000C,            //教材数据请求
    Class_ClassRoomMaterialNotify = 0x0013000D,         //教材数据通知
    
    SVC_JoinRoom = 0x00130113,//进入教室4
    SVC_JoinRoomCallBack = 0x00130110,//进入教室成功与否的回执
    SVC_OtherUserJoinRoomNotify = 0x00130011,//其他人进入教室通知
    
    SVC_JoinRoomComplete         = 0x00130012, //进入教室完毕
    SVC_JoinRoomCommplete_new  = 0x0013001F,  //进入教室完毕c新

    SVC_LeaveRoom                 = 0x00130013, //离开教室
    SVC_OtherUserLeaveRoomNotify = 0x00130014,//其他人离开教室通知
    SVC_KickOutUserFromRoom = 0x0013001A,//从教室内踢出用户
    
    SVC_UserDefine = 0x0013002F,//自定义
    
    SVC_ClassRoomSendPointReq  = 0x00130062,   //发送教室打点请求
    
    Class_CommP2PMessageReq     = 0x00130125,  //发送p2p消息请求
    Class_CommP2PMessageNotify  = 0x00130126,   //发送p2p消息通知
    
    
    //举手
    SVC_HandUp = 0x0013012A,//举手
    SVC_HandDown = 0x0013012A,//放手
    SVC_HandResp = 0x0013012B, //举手和放手的应答
    
    SVC_HandListChangeNotify = 0x0013012C,  //同步举手列表
    
    
    //上麦和下麦
    SVC_SetMicList = 0x00130122,//改变上麦发言列表
    SVC_MicListChangeNotify = 0x00130123,//发言上麦列表变更通知
    
    //发星星
    Class_SetUserStarInfo           = 0x00130031,
    Class_SetUserStarInfoNotify        = 0x00130032,
    Class_UserStarInfoChangeNotify  = 0x00130033,
    Class_AddUserStarC2S            = 0x00130066,    //添加星星数量为增量
    Class_AddUserStarRsp            = 0x00130067,
    
    //新增授权、音视频命令
    Class_UserAVCtrlListNotify      = 0x00130130,
    Class_ReqUserAVCtrlList         = 0x00130131,
    Class_ResetUserAVCtrlListReq    = 0x00130132,
    Class_ResetUserAVCtrlListRsp    = 0x00130133,
    Class_ChangeUserAVModeReq       = 0x00130134,
    Class_ChangeUserAVModeRsp       = 0x00130135,
    Class_UserAuthListNotify        = 0x00130138,
    Class_ReqUserAuthList           = 0x00130139,
    Class_ResetUserAuthListReq      = 0x0013013A,
    Class_ResetUserAuthListRsp      = 0x0013013B,
    Class_ChangeUserAuthReq         = 0x0013013C,
    Class_ChangeUserAuthRsp         = 0x0013013D,
    
    //多页白板数据请求
    SVC_CMD_GetWBDrawData = 0x0013002C,
    
    //聊天
    SVC_cmd_chatImageComfirm = 0x00130024,
    
    //设置教材画笔颜色
     SVC_cmd_Class_SetPenColor_c2s            = 0x0013015C,
     SVC_cmd_Class_SetPenColor_s2c   = 0x0013015D,
    
    
    //请求教材画笔颜色
     SVC_cmd_Class_GetPenColor_c2s              = 0x0013015B,                  //1对多教室颜色协议
     SVC_cmd_Class_GetPenColor_s2c  = 0x0013015B,
    
    //教室内用户列表变更
    Class_Cmd_MessageNotify_s2c = 0x0013004A,
    Class_Cmd_ReqMemberChangeIncrement_c2s = 0x0013004B,
    Class_Cmd_RspMemberChange_s2c = 0x0013004C,
    
    //获取课程信息
    Class_Cmd_ReqGetCourseInfo_c2s = 0x001A0010,
    Class_Cmd_RspCourseInfo_s2c = 0x001A0011,
    Class_Cmd_CourseInfoChangeNotify_s2c = 0x001A0012,
    Class_Cmd_VideoUrlChangeNotify_s2c = 0x001A0013,
    
    //获取课程教材列表
    Class_Cmd_ReqGetCourseMaterialList_c2s = 0x001A0020,
    Class_Cmd_RspCourseMaterialList_s2c = 0x001A0021,
    Class_Cmd_CourseMaterialChangeNotify_s2c = 0x001A0022,
    
    //获取用户某一天的所有课程信息列表
    Class_Cmd_ReqGetAllCourseInfoListByDay_c2s = 0x001A0030,
    Class_Cmd_RspAllCourseInfoListByDay_s2c = 0x001A0031,
    
    //用户课程列表变更通知（增加、删除课程）
    Class_Cmd_CourseListChangeNotify_s2c = 0x001A0032,
    
//==========================================================
    
    //联系人管理
    SVC_GetUserOnlineState = 0x00160010,//获取某个用户的在线状态
    
    //PVP服务
    SVC_A_SendMessage = 0x00120010,//A端发送私聊消息
    SVC_B_SendMessageOK = 0x00120011,//B端发送收到了聊天消息的确认
    SVC_GetClassList = 0x00120100,//获取用户课程列表(紧急进入教室)
    
    //群组服务
    SVC_GetGroupInfo = 0x00180021,//获取群信息
    SVC_GroupInfoChangeNotify = 0x00180022,// 群组信息变更
    SVC_GetGroupMembers = 0x00180023,// 获取群组成员列表
    SVC_GroupMembersChange = 0x00180024,// 群组成员列表变更通知
    SVC_SyncGroupMemberList = 0x0018002F,//同步群组成员列表(群组不存在时创建群组 慎用)
    SVC_CreatGroup = 0x00180030,// 创建群组
    SVC_CreateGroupNotify = 0x00180031,//创建群组结果通知
    SVC_DeleteGroup = 0x00180032,//解散群组
    SVC_DeleteGroupNotify = 0x00180033,//解散群组
    SVC_AddUserToGroup = 0x00180036,//添加群组成员
    SVC_AddUserToGroupNotify = 0x00180037,//添加群组成员通知
    SVC_DeleteUserFromGroup = 0x00180038,//删除群组成员
    SVC_DeleteUserFromGroupNotify = 0x00180039,//删除群组成员通知
    SVC_MemberOnlineStatusChange = 0x0018003a,//群组成员在线状态变更通知
    SVC_MoreMemberOnlineStatusChange = 0x0018003b,//群组批次成员在线状态变更通知
    SVC_AdminSendMsgInGroup = 0x0018003F,//管理员下发聊天消息（不用再教室）
    SVC_SendMsgInGroup = 0x00180040,//组内发送聊天
    SVC_SendMsgInGroupOk = 0x00180041,//服务器确认该聊天记录的发送结果
    SVC_ReciveMsgInGroup = 0x00180042,//服务器下发聊天消息
    SVC_ReciveMsgInGroupOk = 0x00180043,//服务服务器，自己是否已经收到消息
    SVC_ReciveOfflineGroupMessage = 0x00180044,//收到服务器下发的离线时的组聊天消息
    SVC_GetGroupMessageRecord = 0x00180045,//获取组聊天消息记录
    SVC_UploadJoinGroupLog = 0x00180050,//发送进入群日志
    SVC_UploadLeaveGroupLog = 0x00180051,//发送离开群日志
    SVC_AddSensitiveWords = 0x00180055,//添加聊天消息敏感词
    SVC_DeleteSensitiveWords = 0x00180056,//删除聊天消息敏感词
    SVC_ClearSensitiveWords = 0x00180057,//清空所有聊天消息敏感词
    
    //课中服务
    SVC_GetCommonConfig = 0x00130001,//获取教室配置
    SVC_SetCommonConfig = 0x00130002,//设置教室配置
    SVC_CommonConfigNotify = 0x00130003,//教室设置通知
    SVC_GetMediaConfig = 0x00130004,//获取媒体引擎相关的配置
    SVC_ClassRoomMax = 0x0013000E,//获取教室内最高在线人数限制
    SVC_GetAliveRoomCount = 0x0013000F,//获取Alive教室数量
    
  
    
    SVC_KickOutRoomNotify = 0x00130111,//被踢出教室通知
    SVC_RoomClosedNotify = 0x00130015,//教室被服务端关闭的通知
    SVC_ChatMsgInRoom = 0x00130016,//教室内聊天消息
    SVC_ChatMsgInRoomOk = 0x0013001B,//聊天消息回执（服务器接收确认）
  //  SVC_WhiteBoardData = 0x00130017,//白板数据
    SVC_ChatMsgOffLineNotify = 0x00130023,//教室内离线消息
    
    SVC_WhiteBoardDataReq = 0x0013002C,//白板数据
    SVC_WhiteBoardData = 0x0013002D,//白板数据
    
    SVC_CursorSync = 0x00130018,//光标同步
    SVC_PageSync = 0x00130019,//演示文档页
    SVC_PageHistroyNotify = 0x0013001C,//进入教室成功后客户端会收到该下发消息
    SVC_ChangePage = 0x0013001D,//变更演示文档页
    SVC_ChangePageNotify = 0x0013001E,//变更演示文档页通知
   
    SVC_RoomPointUpLoad = 0x00130020,//教室内数据打点上报
    SVC_PostAQuestion = 0x00130021,//小测试出题
    SVC_AnswerAQuestion = 0x00130022,//小测试答题
    SVC_SetMediaDataUploadStep = 0x00130025,//设置客户端定时发送音视频质量统计数据的时间间隔
    SVC_GetMediaDataUploadStep = 0x00130026,//设置客户端定时发送音视频质量统计数据的时间间隔
    SVC_UploadMediaDataInRoom = 0x00130027,//教室内定时上报媒体引擎数据打点
    SVC_SetUserRight = 0x0013002A,//修改用户权限
    SVC_UserRightChangeNotify = 0x0013002B,//修改用户权限通知
   
   
    
    SVC_Substitution = 0x0013004E,//代课
    SVC_SubstitutionNotify = 0x0013004F,//代课通知
    SVC_ScheduleCourse = 0x00130050,//约课
    
    SVC_SendCurrentNotice = 0x001300F0,//发送教室通用Notice
    SVC_CurrentNoticenNotify = 0x001300F1,//收到教室通用Notice通知
    
    SVC_AddCurrentStorage = 0x001300F3,//添加教室通用Storage
    SVC_DeleteCurrentStorage = 0x001300F4,//删除教室通用Storage
    SVC_GetCurrentStorage = 0x001300F5,//获取教室通用Storage
    
    SVC_ConsistentStorageNotify = 0x001300F8,//下发教室ConsistentStorage通知
    SVC_AddCurrentConsistentStorage = 0x001300F9,//添加教室通用ConsistentStorage
    SVC_DeleteCurrentConsistentStorage = 0x001300FA,//删除教室通用ConsistentStorage
    SVC_GetCurrentConsistentStorage = 0x001300FB,//获取教室通用ConsistentStorage
    
    SVC_ClassMatchedSDK = 0x00130104,//获取教室（公开课、小班课等）使用的AV SDK
    SVC_ConfirmAVSDKList = 0x00130114,// 上报本地支持的sdk列表
    SVC_RequestChangeSDKList = 0x00130115,//请求变更AV SDK列表
    SVC_SDKListChangeNotify = 0x00130116,//变更AV SDK列表通知
    SVC_ReqChangeAVSDK = 0x00130117,//请求切换sdk
    SVC_ReqChangeAVSDKNotify = 0x00130118,//收到请求切换sdk的通知
    SVC_RspChangeAVSDK = 0x00130119,//客户端应答sdk切换
    SVC_RspChangeAVSDKNotify = 0x0013011A,//收到了对方的sdk切换应答通知
    SVC_GetCurrentSDK = 0x0013011B,//获取教室内当前正在使用的sdk
    SVC_RequestChangeSDKList2 = 0x0013011C,//请求变更AV SDK列表2
    SVC_SDKListChangeNotify2 = 0x0013011D,//变更AV SDK列表通知2
    
    
    SVC_UploadDeviceStatusChanged = 0x00130141,//上报智能感知变化
    SVC_DeviceStatusNotify = 0x00130142,//智能感知通知
    SVC_Get1v1Record = 0x00130143,//获取1v1进出教室记录
    SVC_1v1RecordNotify = 0x00130144,//1v1进出教室记录通知
    SVC_ReqChangeMaterial = 0x00130145,//请求更换教材
    SVC_MaterialChangeNotify = 0x00130146,//更换教材通知，或者是更换教材通知确认
    SVC_SendMaterialCurrentNotice = 0x00130147,//发送教材相关的通用通知
    SVC_ReciveMaterialCurrentNoticeNotify = 0x00130148,//收到教材相关的通用通知
    SVC_SetMaterial = 0x0013014A,//设置教材的通用设置
    SVC_MaterialSettingNotify = 0x0013014B,//下发教材的通用设置通知
    SVC_SetPDFPage = 0x0013014C,//设置教材当前页码
    SVC_PDFPageNotify = 0x0013014D,//下发教材当前页码通知
    SVC_SetScrollPosition = 0x0013014E,//设置教材当前页的滚动条位置
    SVC_ScrollPositionNotify = 0x0013014F,//下发教材当前页的滚动条位置通知
    SVC_MaterialDataNotify = 0x00130150,//下发教材操作数据通知
    SVC_GetMaterialData = 0x0013015F,//获取教材指定页的操作数据
    SVC_AddMaterialData = 0x00130151,//添加教材操作数据
    SVC_DeleteMaterialData = 0x00130152,//删除教材操作数据
    SVC_EditMaterialData = 0x00130153,//编辑教材操作数据
    SVC_ClearMaterialData = 0x00130154,//清除教材操作数据
    SVC_MaterialBookDataNotify = 0x00130155,//下发教材板书数据通知
    SVC_GetMaterialBookData = 0x00130156,//获取教材指定页的板书数据
    SVC_AddMaterialBookData = 0x00130157,//添加教材板书数据
    SVC_DeleteMaterialBookData = 0x00130158,//删除教材板书数据
    SVC_EditMaterialBookData = 0x00130159,//编辑教材板书数据
    SVC_ClearMaterialBookData = 0x0013015A,//清除教材板书数据
    SVC_GetPenColor = 0x0013015B,//获取画笔颜色
    SVC_MillionClassroomsOnlineUsersNotify = 0x00130165,//万人教室在线人数通知
    SVC_UploadClientStatistics = 0x00140013, //客户端统计信息上报
    
    SVC_CurrentPushNotify = 0x00190056,//服务器下发通用推送通知（服务器默认每次最多下发10条）
    SVC_ReqMorePushNotify = 0x00190058,//向服务器请求更多的推送通知
    SVC_UploadPushNotifyExecResult = 0x00190057,//向服务器上报已经处理过的推送通知信息
    SVC_ScheduleCourse2Notify = 0x00130170,//约课通知2
    
    
    //新白板协议
    SVC_GetCrswareC2S             = 0x001300AA,  //CrswareListGetC2S
    SVC_GetCrswareS2C             = 0x001300AB,  //CrswareListGetS2C
    SVC_CrswareChangeNofity       = 0x001300AC,  //CrswareListChangeNotify
    SVC_SetCurTbPageC2S           = 0x001300B0,  //TBSetC2S
    SVC_SetCurTbPageS2C           = 0x001300B1,  //TBSetS2C
    SVC_CurTbPageNotify           = 0x001300B2,  //TBNotify
    SVC_AddTbBlankPageC2S         = 0x001300B3,  //TBWPageAddC2S
    SVC_AddTbBlankPageS2C         = 0x001300B4,  //TBWPageAddS2C
    SVC_DelTbBlankPageC2S         = 0x001300B5,  //TBWPageDelC2S
    SVC_DelTbBlankPageS2C         = 0x001300B6,  //TBWPageDelS2C
    SVC_TbPageListChangeNotify    = 0x001300B7,  //TBPageListNotify
    SVC_ReqSyncCurTbPageSet       = 0x001300B8,  //CrswareSync
    SVC_SetTbPageScrollbarPosC2S  = 0x001300B9,  //TBPageScrollSetC2S
    SVC_SetTbPageScrollbarPosS2C  = 0x001300BA,  //TBPageScrollSetS2C
    SVC_TbPageScrollbarPosNotify  = 0x001300BB,  //TBPageScrollNotify
    SVC_SetTbPageCursorPosC2S     = 0x001300BC,  //TBPageCursorSetC2S
    SVC_SetTbPageCursorPosS2C     = 0x001300BD,  //TBPageCursorSetS2C
    SVC_TbPageCursorPosNotify     = 0x001300BE,  //TBPageCursorNotify
    SVC_TBPageBoardDataNotify     = 0x001300C0,  //TBPageBoardNotify
    SVC_GetTBPageBoardData        = 0x001300C1,  //TBPageBoardGetC2S
    SVC_GetTBPageBoardDataC2S     = 0x001300C2,
    SVC_AddTBPageBoardDataC2S     = 0x001300C3,  //TBPageBoardAddC2S
    SVC_AddTBPageBoardDataS2C     = 0x001300C4,  //TBPageBoardAddS2C
    SVC_DelTbPageBoardDataC2S     = 0x001300C5,  //TBPageBoardDelC2S
    SVC_DelTbPageBoardDataS2C     = 0x001300C6,  //TBPageBoardDelS2C
    SVC_EditTbPageBoardDataC2S    = 0x001300C7,  //TBPageBoardEditC2S
    SVC_EditTbPageBoardDataS2C    = 0x001300C8,  //TBPageBoardEditS2C
    SVC_ClearTbPageBoardDataC2S   = 0x001300C9,  //TBPageBoardClearC2S
    SVC_ClearTbPageBoardDataS2C   = 0x001300CA,  //TBPageBoardClearS2C
    SVC_TbPageOpDataNotify        = 0x001300D0,
    SVC_GetTbPageOpDataC2S        = 0x001300D1,
    SVC_GetTbPageOpDataS2C        = 0x001300D2,
    SVC_AddTbPageOpDataC2S        = 0x001300D3,
    SVC_AddTbPageOpDataS2C        = 0x001300D4,
    SVC_DelTbPageOpDataC2S        = 0x001300D5,
    SVC_DelTbPageOpDataS2C        = 0x001300D6,
    SVC_EditTbPageOpDataC2S       = 0x001300D7,
    SVC_EditTbPageOpDataS2C       = 0x001300D8,
    SVC_ClearTbPageOpDataC2S      = 0x001300D9,
    SVC_ClearTbPageOpDataS2C      = 0x001300DA,
    

};

#pragma mark-数据包操作类型
enum PacketOperationType {
    PacketOperationType_Encode = 0,
    PacketOperationType_Decode = 1
};
#pragma mark-通知定义
/**
 socket链接发生错误
 */
static const NSNotificationName SocketNotify_Error = @"socket.SocketNotify_Error";
/**
 socket链接成功
 */
static const NSNotificationName SocketNotify_LinkSuccess = @"socket.SocketNotify_LinkSuccess";

/**
 acc socket链接成功
 */
static const NSNotificationName SocketNotify_AccLinkSuccess = @"socket.SocketNotify_AccLinkSuccess";

/**
 socket链接断开
 */
static const NSNotificationName SocketNotify_LinkDisConnect = @"socket.SocketNotify_LinkDisConnect";

/**
 acc socket链接断开
 */
static const NSNotificationName SocketNotify_AccLinkDisConnect = @"socket.SocketNotify_AccLinkDisConnect";

/**
 收到lbs返回的数据
 */
static const NSNotificationName SDKNotify_ReciveLBSInfo = @"svcsdk.SDK_ReciveLBSInfo";


/**
 解析到了一个可用的数据包
 */
static const NSNotificationName SocketNotify_SocketData = @"socket.Socketnotify_SocketData";


/**
 一个需要用户自行处理的数据包
 */
static const NSNotificationName SocketNotify_NeedUserExecPackage = @"socket.Socketnotify_NeedUserExecPackage";

static const NSNotificationName SocketNotify_PBDataExecPackage = @"socket.SocketNotify_PBDataExecPackage";

/**
 svc登录成功
 */
static const NSNotificationName SocketNotify_SVCLoginSuccess = @"socket.SocketNotify_SVCLoginSuccess";

/**
 svc登录失败
 */
static const NSNotificationName SocketNotify_SVCLoginFaild = @"socket.SocketNotify_SVCLoginFaild";

/**
 svc状态变更
 */
static const NSNotificationName SocketNotify_SVCConnectStateChange = @"socket.SocketNotify_SVCConnectStateChange";

/**
 解析到了一个可用的白板pb 数据包
 */
static const NSNotificationName SocketNotify_SocketData_PBData = @"socket.Socketnotify_SocketData_PBData";
