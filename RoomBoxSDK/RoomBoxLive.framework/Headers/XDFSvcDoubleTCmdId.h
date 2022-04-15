//
//  XDFSvcDoubleTCmdId.h
//  RoomBoxSDK
//
//  Created by 刘冬冬 on 2020/5/11.
//  Copyright © 2020 XDF. All rights reserved.
//

#ifndef XDFSvcDoubleTCmdId_h
#define XDFSvcDoubleTCmdId_h

//教室SDK切换
const static uint32_t cmd_os_getAVSDKList_c2s = 0x00130117;
const static uint32_t cmd_os_getAVSDKList_s2c = 0x00130118;
const static uint32_t cmd_os_AVSDKList_notify = 0x00130119;

//学生获取教室信息
const static uint32_t cmd_os_cls_base = 0x00450000;
const static uint32_t cmd_os_getClsInfo_c2s = 0x00450010;
const static uint32_t cmd_os_getClsInfo_s2c = 0x00450011;
const static uint32_t cmd_os_clsInfoChange_notify = 0x00450012;
const static uint32_t cmd_os_clsInfoClose_notify = 0x0045001D;

//主讲获取教室信息
const static uint32_t cmd_ot_getClsInfo_c2s = 0x00430010;
const static uint32_t cmd_ot_getClsInfo_s2c = 0x00430011;
const static uint32_t cmd_ot_clsInfoChange_notify = 0x00430012;
const static uint32_t cmd_ot_clsInfoClose_notify = 0x0043001F;

//助教获取教室信息
const static uint32_t cmd_oa_getClsInfo_c2s = 0x00440010;
const static uint32_t cmd_oa_getClsInfo_s2c = 0x00440011;
const static uint32_t cmd_oa_clsInfoChange_notify = 0x00440012;
const static uint32_t cmd_oa_clsInfoClose_notify = 0x0044001F;

//学生进教室
const static uint32_t cmd_os_clsEnter_c2s = 0x00450020;
const static uint32_t cmd_os_clsEnter_s2c = 0x00450021;
const static uint32_t cmd_os_clsEnter_complete = 0x00450022;

//主讲进教室
const static uint32_t cmd_ot_clsEnter_c2s = 0x00430020;
const static uint32_t cmd_ot_clsEnter_s2c = 0x00430021;
const static uint32_t cmd_ot_clsEnter_complete = 0x00430022;

//助教进教室
const static uint32_t cmd_oa_clsEnter_c2s = 0x00440020;
const static uint32_t cmd_oa_clsEnter_s2c = 0x00440021;
const static uint32_t cmd_oa_clsEnter_complete = 0x00440022;

//学生离开教室
const static uint32_t cmd_os_clsLeave_c2s = 0x00450023;
const static uint32_t cmd_os_clsLeave_s2c = 0x00450024;
const static uint32_t cmd_os_clsForceLeave_notify = 0x00450027;

//助教离开教室
const static uint32_t cmd_oa_clsLeave_c2s = 0x00440023;
const static uint32_t cmd_oa_clsLeave_s2c = 0x00440024;
const static uint32_t cmd_oa_clsForceLeave_notify = 0x00440027;

//主讲离开教室
const static uint32_t cmd_ot_clsLeave_c2s = 0x00430023;
const static uint32_t cmd_ot_clsLeave_s2c = 0x00430024;
const static uint32_t cmd_ot_clsForceLeave_notify = 0x00430027;

//学生版本管理
const static uint32_t cmd_os_getVersionList_c2s = 0x0045002D;
const static uint32_t cmd_os_getVersionList_s2c = 0x0045002E;
const static uint32_t cmd_os_getVersionList_notify = 0x0045002F;

//主讲版本管理
const static uint32_t cmd_ot_getVersionList_c2s = 0x0043002D;
const static uint32_t cmd_ot_getVersionList_s2c = 0x0043002E;
const static uint32_t cmd_ot_getVersionList_notify = 0x0043002F;

//助教版本管理
const static uint32_t cmd_oa_getVersionList_c2s = 0x0044002D;
const static uint32_t cmd_oa_getVersionList_s2c = 0x0044002E;
const static uint32_t cmd_oa_getVersionList_notify = 0x0044002F;

const static uint32_t cmd_os_getTeaList_c2s = 0x00450030;
const static uint32_t cmd_os_getTeaList_s2c = 0x00450031;
const static uint32_t cmd_os_teaListChange_notify = 0x00450032;

const static uint32_t cmd_os_getAssistList_c2s = 0x00450033;
const static uint32_t cmd_os_getAssistList_s2c = 0x00450034;
const static uint32_t cmd_os_assistListChange_notify = 0x00450035;

const static uint32_t cmd_os_getStuList_c2s = 0x00450036;
const static uint32_t cmd_os_getStuList_s2c = 0x00450037;
const static uint32_t cmd_os_stuListChange_notify = 0x00450038;

//主讲模式变更
const static uint32_t cmd_os_getLectureMode_c2s = 0x00450041;
const static uint32_t cmd_os_getLectureMode_s2c = 0x00450042;
const static uint32_t cmd_os_lectureModeChange_notify = 0x00450043;

const static uint32_t cmd_ot_getLectureMode_c2s = 0x00430041;
const static uint32_t cmd_ot_getLectureMode_s2c = 0x00430042;
const static uint32_t cmd_ot_lectureModeChange_notify = 0x00430043;

const static uint32_t cmd_oa_getLectureMode_c2s = 0x00440041;
const static uint32_t cmd_oa_getLectureMode_s2c = 0x00440042;
const static uint32_t cmd_oa_lectureModeChange_notify = 0x00440043;

const static uint32_t cmd_os_setting_notify = 0x00450044;
const static uint32_t cmd_os_setting_c2s = 0x00450045;
const static uint32_t cmd_os_setting_s2c = 0x00450046;

const static uint32_t cmd_ot_setting_notify = 0x00430044;
const static uint32_t cmd_ot_setting_c2s = 0x00430045;
const static uint32_t cmd_ot_setting_s2c = 0x00430046;

const static uint32_t cmd_oa_setting_notify = 0x00440044;
const static uint32_t cmd_oa_setting_c2s = 0x00440045;
const static uint32_t cmd_oa_setting_s2c = 0x00440046;

const static uint32_t cmd_os_UserAuthChange_notify = 0x00450059;

const static uint32_t cmd_os_getCrsware_c2s = 0x0045005A;
const static uint32_t cmd_os_getCrsware_s2c = 0x0045005B;
const static uint32_t cmd_os_crswareChange_notify = 0x0045005C;

const static uint32_t cmd_oa_getCrsware_c2s = 0x0044005A;
const static uint32_t cmd_oa_getCrsware_s2c = 0x0044005B;
const static uint32_t cmd_oa_crswareChange_notify = 0x0044005C;

const static uint32_t cmd_ot_getCrsware_c2s = 0x0043005A;
const static uint32_t cmd_ot_getCrsware_s2c = 0x0043005B;
const static uint32_t cmd_ot_crswareChange_notify = 0x0043005C;

const static uint32_t cmd_os_setCurTbPage_c2s = 0x00450060;
const static uint32_t cmd_os_setCurTbPage_s2c = 0x00450061;
const static uint32_t cmd_os_curTbPage_notify = 0x00450062;

const static uint32_t cmd_oa_setCurTbPage_c2s = 0x00440060;
const static uint32_t cmd_oa_setCurTbPage_s2c = 0x00440061;
const static uint32_t cmd_oa_curTbPage_notify = 0x00440062;

const static uint32_t cmd_ot_setCurTbPage_c2s = 0x00430060;
const static uint32_t cmd_ot_setCurTbPage_s2c = 0x00430061;
const static uint32_t cmd_ot_curTbPage_notify = 0x00430062;

const static uint32_t cmd_os_addWhiteBoard_c2s = 0x00450063;
const static uint32_t cmd_os_addWhiteBoard_s2c = 0x00450064;

const static uint32_t cmd_oa_addWhiteBoard_c2s = 0x00440063;
const static uint32_t cmd_oa_addWhiteBoard_s2c = 0x00440064;

const static uint32_t cmd_ot_addWhiteBoard_c2s = 0x00430063;
const static uint32_t cmd_ot_addWhiteBoard_s2c = 0x00430064;

//下边2个暂时不做  不知道传递给白板的数据格式
const static uint32_t cmd_os_delWhiteBoard_c2s = 0x00450065;
const static uint32_t cmd_os_delWhiteBoard_s2c = 0x00450066;

const static uint32_t cmd_oa_delWhiteBoard_c2s = 0x00440065;
const static uint32_t cmd_oa_delWhiteBoard_s2c = 0x00440066;

const static uint32_t cmd_ot_delWhiteBoard_c2s = 0x00430065;
const static uint32_t cmd_ot_delWhiteBoard_s2c = 0x00430066;

const static uint32_t cmd_os_reqSyncCurTbPageSet = 0x00450068;
const static uint32_t cmd_os_reqSyncPage_notify = 0x00450067;

const static uint32_t cmd_oa_reqSyncCurTbPageSet = 0x00440068;
const static uint32_t cmd_oa_reqSyncPage_notify = 0x00440067;

const static uint32_t cmd_ot_reqSyncCurTbPageSet = 0x00430068;
const static uint32_t cmd_ot_reqSyncPage_notify = 0x00430067;
//回应对应：0x00450062、0x00450067

//板书数据
const static uint32_t cmd_os_gettbPageBoardData_notify = 0x00450070;
const static uint32_t cmd_os_getTbPageBoardData_c2s = 0x00450071;
const static uint32_t cmd_os_getTbPageBoardData_s2c = 0x00450072;
const static uint32_t cmd_os_addTbPageBoardData_c2s = 0x00450073;
const static uint32_t cmd_os_addTbPageBoardData_s2c = 0x00450074;
const static uint32_t cmd_os_delTbPageBoardData_c2s = 0x00450075;
const static uint32_t cmd_os_delTbPageBoardData_s2c = 0x00450076;
const static uint32_t cmd_os_editTbPageBoardData_c2s = 0x00450077;
const static uint32_t cmd_os_editTbPageBoardData_s2c = 0x00450078;
const static uint32_t cmd_os_clearTbPageBoardData_c2s = 0x00450079;
const static uint32_t cmd_os_clearTbPageBoardData_s2c = 0x0045007A;

const static uint32_t cmd_oa_gettbPageBoardData_notify = 0x00440070;
const static uint32_t cmd_oa_getTbPageBoardData_c2s = 0x00440071;
const static uint32_t cmd_oa_getTbPageBoardData_s2c = 0x00440072;
const static uint32_t cmd_oa_addTbPageBoardData_c2s = 0x00440073;
const static uint32_t cmd_oa_addTbPageBoardData_s2c = 0x00440074;
const static uint32_t cmd_oa_delTbPageBoardData_c2s = 0x00440075;
const static uint32_t cmd_oa_delTbPageBoardData_s2c = 0x00440076;
const static uint32_t cmd_oa_editTbPageBoardData_c2s = 0x00440077;
const static uint32_t cmd_oa_editTbPageBoardData_s2c = 0x00440078;
const static uint32_t cmd_oa_clearTbPageBoardData_c2s = 0x00440079;
const static uint32_t cmd_oa_clearTbPageBoardData_s2c = 0x0044007A;

const static uint32_t cmd_ot_gettbPageBoardData_notify = 0x00430070;
const static uint32_t cmd_ot_getTbPageBoardData_c2s = 0x00430071;
const static uint32_t cmd_ot_getTbPageBoardData_s2c = 0x00430072;
const static uint32_t cmd_ot_addTbPageBoardData_c2s = 0x00430073;
const static uint32_t cmd_ot_addTbPageBoardData_s2c = 0x00430074;
const static uint32_t cmd_ot_delTbPageBoardData_c2s = 0x00430075;
const static uint32_t cmd_ot_delTbPageBoardData_s2c = 0x00430076;
const static uint32_t cmd_ot_editTbPageBoardData_c2s = 0x00430077;
const static uint32_t cmd_ot_editTbPageBoardData_s2c = 0x00430078;
const static uint32_t cmd_ot_clearTbPageBoardData_c2s = 0x00430079;
const static uint32_t cmd_ot_clearTbPageBoardData_s2c = 0x0043007A;

//增量获取板书数据  暂时不错
const static uint32_t cmd_os_pageBoardDataChange_c2s = 0x0045007B;
const static uint32_t cmd_os_pageBoardDataChange_s2c = 0x0045007C;
const static uint32_t cmd_os_pageBoardDataChange_notify = 0x0045007D;

//用户开关变更
const static uint32_t cmd_os_doubleTUserSwitchChange_notify = 0x00450092;

//麦序
const static uint32_t cmd_os_doubleTMicQueque_notify = 0x004500AC;
const static uint32_t cmd_os_doubleTMicQueque_c2s = 0x004500AD; //客户端定时请求同步连麦麦序列表

//小工具
const static uint32_t cmd_os_get_consistentStorage_c2s = 0x004500C6;
const static uint32_t cmd_os_get_consistentStorage_s2c = 0x004500C7;
const static uint32_t cmd_os_consistentStorage_notify = 0x004500C8;
const static uint32_t cmd_os_add_consistentStorage_c2s = 0x004500C9;
const static uint32_t cmd_os_add_consistentStorage_rsp_s2c = 0x004500CA;

const static uint32_t cmd_oa_get_consistentStorage_c2s = 0x004400C6;
const static uint32_t cmd_oa_get_consistentStorage_s2c = 0x004400C7;
const static uint32_t cmd_oa_consistentStorage_notify = 0x004400C8;
const static uint32_t cmd_oa_add_consistentStorage_c2s = 0x004400C9;
const static uint32_t cmd_oa_add_consistentStorage_rsp_s2c = 0x004400CA;

const static uint32_t cmd_ot_get_consistentStorage_c2s = 0x004300C6;
const static uint32_t cmd_ot_get_consistentStorage_s2c = 0x004300C7;
const static uint32_t cmd_ot_consistentStorage_notify = 0x004300C8;
const static uint32_t cmd_ot_add_consistentStorage_c2s = 0x004300C9;
const static uint32_t cmd_ot_add_consistentStorage_rsp_s2c = 0x004300CA;

// 聊天
const static uint32_t cmd_os_chatMsg_c2s = 0x004500B3;
const static uint32_t cmd_os_chatMsg_s2c = 0x004500B5;
const static uint32_t cmd_os_chatMsgAck_s2c = 0x004500B6;
const static uint32_t cmd_os_chatLatestMsg_notify = 0x004500B9;
const static uint32_t cmd_os_chatMsgMediaOk_c2s = 0x004500BA;
const static uint32_t cmd_os_chatMsgMediaOk_s2c = 0x004500BB;
const static uint32_t cmd_os_chatMsgMediaOk_notify = 0x004500BC;


//答题卡  点赞
const static uint32_t cmd_os_QuizState_notify = 0x004500E4;
const static uint32_t cmd_os_recvQuizACK = 0x004500E5;
const static uint32_t cmd_os_submitQuiz_c2s = 0x004500E6;
const static uint32_t cmd_os_submitQuiz_s2c = 0x004500E7;
const static uint32_t cmd_os_GiveALike_notify  = 0x004500EA;
const static uint32_t cmd_os_MsgReminding_notify  = 0x004500ED;

//星星
const static uint32_t cmd_os_userStarNumber_notify = 0x004500A2;
//星星接受
const static uint32_t cmd_os_AddUserStarNumber_notify = 0x0013020D;
#endif /* XDFSvcDoubleTCmdId_h */
