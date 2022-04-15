//
//  Svc_CmdId.h
//  svc_test
//
//  Created by lixuegang on 2019/7/16.
//  Copyright © 2019 com.SAC.sac-mac. All rights reserved.
//

#ifndef Svc_CmdId_h
#define Svc_CmdId_h

#include "stdint.h"

//page
const static uint32_t cmd_wb_setCurPage_c2s = 0x001300B0;
const static uint32_t cmd_wb_setCurPage_s2c = 0x001300B1;
const static uint32_t cmd_wb_curPageNotify_s2c = 0x001300B2;

//scrollbar
const static uint32_t cmd_wb_setCurPageScrollbarPos_c2s = 0x001300B9;
const static uint32_t cmd_wb_setCurPageScrollbarPos_s2c = 0x001300BA;
const static uint32_t cmd_wb_CurPageScrollbarPosNotify_s2c = 0x001300BB;

//muse pos
const static uint32_t cmd_wb_setCurMusePos_c2s = 0x001300BC;
const static uint32_t cmd_wb_setCurMusePos_s2c = 0x001300BD;
const static uint32_t cmd_wb_curMusePosNotify_s2c = 0x001300BE;

//pagedrawdata
const static uint32_t cmd_wb_DataNotify_s2c = 0x001300C0;

const static uint32_t cmd_wb_getDataByPage_c2s = 0x001300C1;
const static uint32_t cmd_wb_getDataByPage_s2c = 0x001300C2;

const static uint32_t cmd_wb_addData_c2s = 0x001300C3;
const static uint32_t cmd_wb_addData_s2c = 0x001300C4;

const static uint32_t cmd_wb_deleData_c2s = 0x001300C5;
const static uint32_t cmd_wb_deleData_s2c = 0x001300C6;

const static uint32_t cmd_wb_editData_c2s = 0x001300C7;
const static uint32_t cmd_wb_editData_s2c = 0x001300C8;

const static uint32_t cmd_wb_emptyData_c2s = 0x001300C9;
const static uint32_t cmd_wb_emptyData_s2c = 0x001300CA;

// add new page
const static uint32_t cmd_wb_addNewBlankPage_c2s = 0x001300B3;
const static uint32_t cmd_wb_addNewBlankPage_s2c = 0x001300B4;

const static uint32_t cmd_wb_deleBlankPage_c2s = 0x001300B5;
const static uint32_t cmd_wb_deleBlankPage_s2c = 0x001300B6;

const static uint32_t cmd_wb_pagelistChangeNotify = 0x001300B7;
const static uint32_t cmd_wb_SynRoomData = 0x001300B8;
//pen color
const static uint32_t cmd_wb_getPenColor_c2s = 0x00380119;
const static uint32_t cmd_wb_getPenColor_s2c = 0x0038011A;

//手写板子班协议
const static uint32_t cmd_sub_add_consistentStorag_c2s = 0x004100C4;
const static uint32_t cmd_sub_add_consistentStorag_rsp_s2c = 0x004100C5;

//教室
//获取教室信息
const static uint32_t largeClass_cmd_wb_classInfo_c2s = 0x00410010;//已用
const static uint32_t largeClass_cmd_wb_classInfo_s2c = 0x00410011;//已用

//教室信息变更通知
const static uint32_t largeClass_cmd_wb_classInfoNotify_c2s = 0x00410012;

//进入教室
const static uint32_t largeClass_cmd_wb_enterClass_c2s = 0x00410020;//已用
const static uint32_t largeClass_cmd_wb_enterClass_s2c = 0x00410021;//已用

//教室成员列表变更通知
const static uint32_t largeClass_cmd_wb_adminListNotify_s2c = 0x00410022;

//进入教室完成
const static uint32_t largeClass_cmd_wb_enterClassCompleted_c2s = 0x00410024;//已用

const static uint32_t largeClass_cmd_wb_getClassIDInfo_c2s = 0x0041000E;//新增获取大班课房间ID协议
const static uint32_t largeClass_cmd_wb_getClassIDInfo_s2c = 0x0041000F;//新增获取大班课房间ID协议

//离开教室
const static uint32_t largeClass_cmd_wb_leaveClass_c2s = 0x00410025;
const static uint32_t largeClass_cmd_wb_leaveClass_s2c = 0x00410026;

//进入教室通知
const static uint32_t largeClass_cmd_wb_enterClassNotify_s2c = 0x00410027;

//离开教室通知
const static uint32_t largeClass_cmd_wb_leaveClassNotify_s2c = 0x00410028;

//强制离开教室
const static uint32_t largeClass_cmd_wb_forceLeaveClass_c2s = 0x00410029;
const static uint32_t largeClass_cmd_wb_forceLeaveClass_s2c = 0x0041002a;

//强制离开教室通知
const static uint32_t largeClass_cmd_wb_forceLeaveClassNotify_s2c = 0x0041002b;

//关闭教室
const static uint32_t largeClass_cmd_wb_closeClass_c2s = 0x0041002c;
const static uint32_t largeClass_cmd_wb_closeClass_s2c = 0x0041002d;

//教室关闭通知
const static uint32_t largeClass_cmd_wb_closeClassNotify_s2c = 0x0041002e;

//教室人数变更通知
const static uint32_t largeClass_cmd_wb_userNumNotify_s2c = 0x0041002f;

//增量获取管理员列表信息(母教室+子教室)
const static uint32_t largeClass_cmd_wb_adminList_c2s = 0x00410030;
const static uint32_t largeClass_cmd_wb_adminList_s2c = 0x00410031;

//定时请求同步当前教室的相关设置（演讲模式、文本聊天开关设置等
const static uint32_t largeClass_cmd_wb_syncSettings_c2s = 0x00410040;

const static uint32_t largeClass_cmd_wb_switchMSModeNotify_s2c = 0x00410043;

//更改教室设置（uint32数值型设置
const static uint32_t largeClass_cmd_wb_setting_c2s = 0x00410044;
const static uint32_t largeClass_cmd_wb_setting_s2c = 0x00410045;
const static uint32_t largeClass_cmd_wb_settingNotify_s2c = 0x00410046;


//个人设置
const static uint32_t largeClass_cmd_wb_personalNotify_s2c = 0x00410049;

//答题卡
const static uint32_t cmd_wb_quizStart_c2s = 0x001300E0;
const static uint32_t cmd_wb_quizStart_s2c = 0x001300E1;
const static uint32_t cmd_wb_quizStartNotify = 0x001300E2;

const static uint32_t cmd_wb_quizEnd_c2s = 0x001300E3;
const static uint32_t cmd_wb_quizEnd_s2c = 0x001300E4;
const static uint32_t cmd_wb_quizEndNotify = 0x001300E5;

const static uint32_t cmd_wb_quizSubmitAnswer_c2s = 0x001300E6;
const static uint32_t cmd_wb_quizSubmitAnswer_s2c = 0x001300E7;
const static uint32_t cmd_wb_quizSubmitAnswerNotify = 0x001300E8;

const static uint32_t cmd_wb_quizGiveALike_c2s = 0x001300E9;
const static uint32_t cmd_wb_quizGiveALike_s2c = 0x001300EA;
const static uint32_t cmd_wb_quizGiveALikeNotify = 0x001300EB;

const static uint32_t cmd_wb_quizRecvACK_c2s = 0x001300EC;
const static uint32_t cmd_wb_quizGiveUpNotify = 0x001300ED;

// 新版本收到答题卡消息
const static uint32_t cmd_wb_multiple_quizStartNotify = 0x00130182;
// 新版本ack消息确认收到答题卡
//int Class_quizACK = 0x001300ec;
// 新版本学生端提交答案请求
const static uint32_t cmd_wb_multiple_quizSubmitAnswer_c2s = 0x00130186;
// 新版本学生端提交答案响应
const static uint32_t cmd_wb_multiple_quizSubmitAnswerRep_s2c = 0x00130187;
// 新版本收到答题结束消息
const static uint32_t cmd_wb_multiple_quizEndAnswerNotify = 0x00130185;
// 学生收到戳一戳
const static uint32_t cmd_wb_multiple_msgRemindingNotify = 0x00130202;

///=======以下是大班的子班教材白板信令////////////////
const static uint32_t largeclass_cmd_wb_List_c2s = 0x0041005a;//已用
const static uint32_t largeclass_cmd_wb_List_s2c = 0x0041005b;
const static uint32_t largeclass_cmd_wb_List_MlschangeNotify = 0x0041005c;
const static uint32_t largeclass_cmd_wb_List_SclchangeNotify = 0x0041005d;

//设置当前使用的教材+课件页码
const static uint32_t largeclass_cmd_wb_setPage_c2s = 0x00410060;
const static uint32_t largeclass_cmd_wb_setPage_s2c = 0x00410061;
const static uint32_t largeclass_cmd_wb_setPageNotify = 0x00410062;//已用

//添加课件空白页
const static uint32_t largeclass_cmd_wb_newPage_c2s = 0x00410063;
const static uint32_t largeclass_cmd_wb_newPage_s2c = 0x00410064;

//删除课件空白页
const static uint32_t largeclass_cmd_wb_delPage_c2s = 0x00410065;
const static uint32_t largeclass_cmd_wb_delPage_s2c = 0x00410066;

//课件页列表（课件页->教材页、空白页映射关系）变更通知
const static uint32_t largeclass_cmd_wb_pageChangeNotify = 0x00410067;//已用

//定时请求同步当前课件的相关设置（当前教材、当前页码、课件页列表）
const static uint32_t largeclass_cmd_wb_syncSetting_c2s = 0x00410068;//已用

//设置课件页的滚动条位置
const static uint32_t largeclass_cmd_wb_setScroll_c2s = 0x00410069;
const static uint32_t largeclass_cmd_wb_setScroll_s2c = 0x0041006a;
const static uint32_t largeclass_cmd_wb_setScrollNotify = 0x0041006b;

//设置教材页的鼠标位置
const static uint32_t largeclass_cmd_wb_mousePos_c2s = 0x0041006c;
const static uint32_t largeclass_cmd_wb_mousePos_s2c = 0x0041006d;
const static uint32_t largeclass_cmd_wb_mousePosNotify = 0x0041006e;

//下发课件页的板书数据通知
const static uint32_t largeclass_cmd_wb_getData_c2s = 0x00410071;
const static uint32_t largeclass_cmd_wb_getData_s2c = 0x00410072;
const static uint32_t largeclass_cmd_wb_getDataNotify = 0x00410070;//已用

//添加课件页板书数据
const static uint32_t largeclass_cmd_wb_addData_c2s = 0x00410073;//已用
const static uint32_t largeclass_cmd_wb_addData_s2c = 0x00410074;//已用

//删除课件页板书数据
const static uint32_t largeclass_cmd_wb_delData_c2s = 0x00410075;//已用
const static uint32_t largeclass_cmd_wb_delData_s2c = 0x00410076;//已用

//编辑课件页板书数据
const static uint32_t largeclass_cmd_wb_editData_c2s = 0x00410077;
const static uint32_t largeclass_cmd_wb_editData_s2c = 0x00410078;

//清空课件页板书数据
const static uint32_t largeclass_cmd_wb_clearData_c2s = 0x00410079;
const static uint32_t largeclass_cmd_wb_clearData_s2c = 0x0041007a;

//开始连麦
const static uint32_t largeclass_cmd_connectmic_start_c2s = 0x00410090;
const static uint32_t largeclass_cmd_connectmic_start_s2c = 0x00410091;
//结束连麦
const static uint32_t largeclass_cmd_connectmic_stop_c2s = 0x00410092;
const static uint32_t largeclass_cmd_connectmic_stop_s2c = 0x00410093;
//连麦开关状态通知
const static uint32_t largeclass_cmd_connectmic_status_Notify = 0x00410094;
//连麦举手
const static uint32_t largeclass_cmd_connectmic_HandUp_c2s = 0x00410095;
const static uint32_t largeclass_cmd_connectmic_HandUp_s2c = 0x00410096;
const static uint32_t largeclass_cmd_connectmic_HandUp_Notify = 0x00410097;
//连麦放手
const static uint32_t largeclass_cmd_connectmic_HandDown_c2s = 0x00410098;
const static uint32_t largeclass_cmd_connectmic_HandDown_s2c = 0x00410099;
const static uint32_t largeclass_cmd_connectmic_HandDown_Notify = 0x0041009a;

//修改连麦麦序列表
const static uint32_t largeclass_cmd_connectmic_OrderList_c2s = 0x0041009b;
const static uint32_t largeclass_cmd_connectmic_OrderList_s2c = 0x0041009c;
const static uint32_t largeclass_cmd_connectmic_OrderList_Notify = 0x0041009d;

//定时请求连麦麦序列表
const static uint32_t largeclass_cmd_connectmic_Sync_OrderList_c2s = 0x0041009e;

const static uint32_t largeclass_cmd_connectmic_RandomLineup_c2s = 0x0041009f;
const static uint32_t largeclass_cmd_connectmic_RandomLineup_s2c = 0x004100a0;

//=======以下是大班课子班聊天信令=======//
const static uint32_t largeClass_cmd_chat_send_c2s = 0x004100b3;
const static uint32_t largeClass_cmd_chat_receive_s2c = 0x004100b5;
const static uint32_t largeClass_cmd_chat_receive_c2s = 0x004100b6;
const static uint32_t largeClass_cmd_chat_recentHistory_s2c = 0x004100b9;
const static uint32_t largeClass_cmd_chat_mediaOK_s2c = 0x004100bc;

//戳一戳
const static uint32_t largeclass_cmd_remind_notify = 0x004100e2;

//开始答题（答题卡）
const static uint32_t largeclass_cmd_AnswerCard_Start_c2s = 0x004100a5;
const static uint32_t largeclass_cmd_AnswerCard_Start_s2c = 0x004100a6;
const static uint32_t largeclass_cmd_AnswerCard_Start_Notify_s2c = 0x004100a7;
const static uint32_t largeclass_cmd_AnswerCard_StartMultiple_c2s = 0x004100d0;
const static uint32_t largeclass_cmd_AnswerCard_StartMultiple_s2c = 0x004100d1;
const static uint32_t largeclass_cmd_AnswerCard_StartMultiple_Notify_s2c = 0x004100d2;
const static uint32_t largeclass_cmd_AnswerCard_ackMultiple_c2s = 0x004100B1;

//51)    结束答题
const static uint32_t largeclass_cmd_AnswerCard_Stop_c2s = 0x004100a8;
const static uint32_t largeclass_cmd_AnswerCard_Stop_s2c = 0x004100a9;
const static uint32_t largeclass_cmd_AnswerCard_Stop_Notify_s2c = 0x004100aa;
const static uint32_t largeclass_cmd_AnswerCard_StopMultiple_c2s = 0x004100d3;
const static uint32_t largeclass_cmd_AnswerCard_StopMultiple_s2c = 0x004100d4;
const static uint32_t largeclass_cmd_AnswerCard_StopMultiple_Notify_s2c = 0x004100d5;

//53)    提交答案
const static uint32_t largeclass_cmd_AnswerCard_Answer_c2s = 0x004100ab;
const static uint32_t largeclass_cmd_AnswerCard_Answer_s2c = 0x004100ac;
const static uint32_t largeclass_cmd_AnswerCard_Answer_Notify_s2c = 0x004100ad;
const static uint32_t largeclass_cmd_AnswerCard_AnswerMultiple_c2s = 0x004100d6;
const static uint32_t largeclass_cmd_AnswerCard_AnswerMultiple_s2c = 0x004100d7;
const static uint32_t largeclass_cmd_AnswerCard_AnswerMultiple_Notify_s2c = 0x004100d8;

//53)    答案点赞
const static uint32_t largeclass_cmd_AnswerCard_GiveAlike_c2s = 0x004100ae;
const static uint32_t largeclass_cmd_AnswerCard_GiveAlike_s2c = 0x004100af;
const static uint32_t largeclass_cmd_AnswerCard_GiveAlike_Notify_s2c = 0x004100b0;

//      小工具
const static uint32_t largeclass_cmd_smallTools_Notify_s2c = 0x004100C3;


// 大班、双师H5教材列表协议
const static uint32_t commonclass_cmd_getCrsWareInfoV2_c2s = 0x001A0025;
const static uint32_t commonclass_cmd_getCrsWareInfoV2_s2c = 0x001A0026;

#endif /* Svc_CmdId_h */
