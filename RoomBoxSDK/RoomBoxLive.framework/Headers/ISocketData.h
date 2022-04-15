//
//  ISocketData.h
//  AC_project
//
//  Created by www.xdf.cn on 15-1-4.
//  Copyright (c) 2015年 www.xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SVCNumberDefine.h"


#pragma mark - 协议cmd与协议包映射-------------
@interface CMD_Map:NSObject
{
    NSMutableArray<NSString *> * allowClass;//可以被解析的基础数据类型
    //客户端请求部分
    NSDictionary * _cmdMap_c2s;//命令ID与处理类型的映射
    //服务器响应部分
    NSDictionary * _cmdMap_s2c;//命令ID与处理类型的映射

    //命令ID与最终传输的数据结构的映射
    NSMutableDictionary * _structMap;
}
+(CMD_Map * _Nonnull)instance;
/**
 获得指定协议id对应的数据结构体
 */
-(NSArray * _Nullable)dataStructByCommandID:(uint32_t)_commandID type:(int)_type;
/**
 获得指定类型对应的数据结构体
 */
-(id _Nullable )dataStructByClass:(Class _Nonnull)_cla;

/**
 获得指定协议id对应的处理类型
 */
-(Class _Nullable )classTypeByCommandID:(uint32_t)_commandID type:(int)_type;


@end



#pragma mark - 协议包定义部分-------------

@interface ISocketData : NSObject

@end

@interface StatisticsString:ISocketData
@property UInt16Value * _Nonnull KvsKey;
@property StringValue * _Nonnull KvsValue;
@end
@interface StatisticsInt:ISocketData
@property UInt16Value * _Nonnull KvsKey;
@property UInt32Value * _Nonnull KviValue;
@end

@interface StatisticsObj:ISocketData
@property UInt32Value * _Nonnull intKvsNum;
@property NSMutableArray<StatisticsInt *> * _Nonnull intKvs_StatisticsInt;
@property UInt32Value * _Nonnull objKvsNum;
@property NSMutableArray<StatisticsObj *> * _Nonnull objKvs_StatisticsObj;
@end

/**
    获取用户信息
 */
@interface getUserInfo_c2s : ISocketData
@property UInt64Value * _Nonnull Userid;
@end

/**
    用户信息返回
 */
@interface getUserInfo_s2c : ISocketData
@property StringValue * _Nonnull sRetJsonstr;
@end


/**
    获取教室内数据
 */
@interface getClassRoomdata_c2s : ISocketData
@property UInt64Value * _Nonnull cid;
@end

/**
    教室内数据通知
 */
@interface classRoomDataNotify_s2c : ISocketData
@property StringValue * _Nonnull ret_str;
@end

/**
    获取教室内成员数据
 */
@interface getClassRoomMemberList_c2s : ISocketData
@property UInt64Value * _Nonnull cid;
@end

/**
    教室内成员数据通知
 */
@interface classRoomMemberListNotify_s2c : ISocketData
@property StringValue * _Nonnull ret_str;
@end

/**
    获取教材数据
 */
@interface getClassRoomMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull cid;
@end

/**
    教材数据通知
 */

@interface classRoomMaterialDataNotify_s2c : ISocketData
@property StringValue * _Nonnull ret_str;
@end


/**
 发送p2p消息请求
 */
@interface classSendP2pMessage_c2s : ISocketData
@property UInt64Value * _Nonnull cid;
@property UInt64Value * _Nonnull targetUid;
@property StringValue * _Nonnull content;
@end


/**
 下发p2p消息通知
 */
@interface classSendP2pMessageNotify_s2c :ISocketData
@property UInt64Value * _Nonnull cid;
@property UInt64Value * _Nonnull sourceUid;
@property StringValue * _Nonnull content;
@end


/**
 发星星item
 */
@interface classSendStarInfoItem : ISocketData
@property UInt64Value * _Nonnull uid;
@property UInt32Value * _Nonnull starNum;
@end

/**
 发星星c2s
 */
@interface classSendStarInfo_c2s : ISocketData
@property UInt64Value* _Nonnull cid;
@property StringValue* _Nonnull strData;
@property UInt32Value * _Nonnull ItemNum;
@property NSMutableArray<classSendStarInfoItem * > * _Nonnull starInfoArray_classSendStarInfoItem;
@end

/**
    发星星 s2c
 */

@interface classSendStarInfoNotify_s2c : ISocketData
@property UInt32Value * _Nonnull rsp_code;
@end


/**
    星星变化通知
 */
@interface classStarInfoChangedNotify:ISocketData
@property UInt64Value* _Nonnull cid;
@property StringValue* _Nonnull strData;
@property UInt32Value * _Nonnull ItemNum;
@property NSMutableArray<classSendStarInfoItem * > * _Nonnull starInfoArray_classSendStarInfoItem;
@end

/**
 教室内画笔颜色变更
 */
@interface classSetPenColor_c2s : ISocketData
@property UInt64Value* _Nonnull cid;
@property UInt32Value * _Nonnull colorValue;
@end

@interface classSetPenColor_s2c : ISocketData
@property UInt32Value * _Nonnull Rspcode;
@end


@interface classGetPenColor_c2s : ISocketData
@property UInt64Value* _Nonnull cid;
@end

@interface classGetPenColor_s2c : ISocketData
@property UInt32Value * _Nonnull Rspcode;
@property UInt64Value* _Nonnull cid;
@property UInt32Value * _Nonnull colorValue;
@end

/**
 教室内成员变更增量信息请求和通知
 */
@interface classMemberChangeIncrement_c2s : ISocketData
@property UInt64Value * _Nonnull cid;
@property UInt32Value * _Nonnull version;
@end

@interface classMemberChangeIncrement_s2c : ISocketData
@property StringValue * _Nonnull Retstr;
@end

/**
 教室内信息变更通知
 */
@interface  classMessageNotify_s2c : ISocketData
@property UInt64Value * _Nonnull cid;
@property UInt64Value * _Nonnull msgid;

/**
 msgType 值说明
 None            = 0,
 AddUser         = 1,
 DelUser         = 2,
 AddCourseware   = 3,
 DelCourseware   = 4,
 UpdateCourseware= 5
 教室成员列表变更t通知 = 6
 */

@property UInt32Value * _Nonnull msgType;
@property StringValue * _Nonnull content;
@end


/**
 获取课程信息
 */
@interface GetCourseInfo_c2s : ISocketData
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@end

/**
 课程信息
 */
@interface CourseInfo_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@property StringValue * _Nonnull JsonData;
@end

/**
 课程信息变更通知
 */
@interface CourseInfoChangeNotify_s2c : ISocketData
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@end

/**
 回放链接信息变更通知
 */
@interface CourseVideoUrlChangeNotify_s2c : ISocketData
@property UInt64Value * _Nonnull CID_UInt64Value;
@property StringValue * _Nonnull VideoURL;
@end

/**
 获取课程教材列表
 */
@interface GetCourseMaterialList_c2s : ISocketData
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@end

/**
 教材列表
 */
@interface CourseMaterialList_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@property StringValue * _Nonnull JsonData;
@end

/**
 教材列表变更通知
 */
@interface CourseMateriaChangeNotify_s2c : ISocketData
@property UInt16Value * _Nonnull CIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull CID_UInt64Value;
@end


/**
 获取用户某一天的所有课程信息列表
 */
@interface GetUserAllCourseInfoListByDay_c2s : ISocketData
@property UInt64Value * _Nonnull date; //客户端本地当天0点所对应的UTC时间
@end

/**
 用户某一天所有课程信息列表
 */
@interface UserAllCourseListByDay_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull date; //客户端本地当天0点所对应的UTC时间
@property StringValue * _Nonnull JsonData;//包含用户当天所有课程列表信息的数据
@end


/**
 用户课程列表变更通知
 */
@interface CourseListChangeNotify_s2c :ISocketData
@property UInt16Value * _Nonnull DateNum;
@property NSMutableArray<UInt64Value *> * _Nonnull Date_UInt64Value;
@end





@interface AccServerEntity:ISocketData

/**
 接入服务器IP
 */
@property UInt32Value * _Nonnull AccIP;

/**
 供客户端连接的端口数
 */
@property UInt32Value * _Nonnull AccPortNum;

/**
 供客户端连接的端口
 */
@property NSMutableArray<UInt16Value *> * _Nonnull portArr_UInt16Value;
@end


/**
 负载均衡请求
 */
@interface Fuzaijunheng_c2s : ISocketData
/**
 连接失败的服务器数量
 */
@property UInt32Value * _Nonnull FailedServerNum;


/**
 接入服务器IP
 */
@property NSMutableArray<UInt32Value *> * _Nonnull serIPArr_UInt32Value;

/**
 是否手动设置地区运营商：0-否、1-是
 */
@property UInt8Value * _Nonnull IsManualSetting;

/**
 运营商：0-未知、1-电信、2-联通、3-移动、4-教育网
 */
@property UInt8Value * _Nonnull ISPIdx;

/**
 所在地代码：省级代码，0表示未知或者国外
 */
@property UInt64Value * _Nonnull LocationCode;
@end



@interface HttpServerEntity : ISocketData
/**
 协议类型：
 0-http
 1-https
 */
@property UInt8Value * _Nonnull ProtoType;

/**
 Http服务器IP
 */
@property UInt32Value * _Nonnull HttpIP;

/**
 供客户端连接的端口数
 */
@property UInt8Value * _Nonnull HttpPorNum;

/**
 端口数组
 */
@property NSMutableArray<UInt16Value *> * _Nonnull HttpPortArr_UInt16Value;
@end


/**
 负载均衡回执
 */
@interface Fuzaijunheng_s2c : ISocketData
/**
 返回码： 0x00000000-成功 0x00000001-无可用服务
 */
@property UInt32Value * _Nonnull RspCode;

/**
 接入服务器IP数量（服务器返回的字节序不标准）
 */
@property UInt32Value * _Nonnull AccServerIPNum;

/**
 接入服务器可选ip数组
 */
@property NSMutableArray<AccServerEntity *> * _Nonnull serArr_AccServerEntity;

/**
 Http服务器IP数量
 */
@property UInt16Value * _Nonnull HttpServerIPNum;

/**
 Http服务器IP数量
 */
@property NSMutableArray<HttpServerEntity *> * _Nonnull httpSerArr_HttpServerEntity;
@end




/**
 心跳请求
 */
@interface XinTiao_c2s : ISocketData

@end


/**
 心跳回执
 */
@interface XinTiao_s2c : ISocketData

@end


/**
 获取心跳配置请求
 */
@interface GetXinTiaoConfig_c2s : ISocketData

@end


/**
 获取心跳配置回执
 */
@interface GetXinTiaoConfig_s2c : ISocketData
/**
 发送心跳包时间间隔（秒）
 */
@property UInt16Value * _Nonnull Interval;

/**
 服务端检测客户端心跳超时时间（秒），超时后掐断socket
 */
@property UInt16Value * _Nonnull C2STimeout;

/**
 服务端是否向客户端回发心跳包
 */
@property UInt8Value * _Nonnull S2CSwitch;

/**
 客户端检测心跳超时时间（秒），超时后掐断socket重新连接
 */
@property UInt16Value * _Nonnull S2CTimeout;
@end

/**
 服务器端的心跳配置通知
 */
@interface GetXinTiaoConfig_s2cNotify : ISocketData
/**
 发送心跳包时间间隔（秒）
 */
@property UInt16Value * _Nonnull Interval;

/**
 服务端是否向客户端回发心跳包
 */
@property UInt8Value * _Nonnull S2CSwitch;

/**
 客户端检测心跳超时时间（秒），超时后掐断socket重新连接
 */
@property UInt16Value * _Nonnull S2CTimeout;
@end

/**
 客户端接入请求
 */
@interface ClientIn_c2s : ISocketData
/**
 客户端类型
 0x01-PC客户端
 0x02-Andorid客户端
 0x03-IPhone客户端
 0x04-IPad客户端
 0x05-Flash白板客户端
 0x06-Flash AC客户端
 0x07-Mac客户端
 0x08-多说Andorid客户端
 0x09-多说IPhone客户端
 0x0A-B2S Andorid客户端
 0x0B-B2S IPhone客户端
 0x0F-IGS www.xdf.cnHD
 0x10-Web端
 0x21～0x2F-微信直播（比如：0x21-微信PC端、0x22-微信Andorid端、0x32-微信IPhone端）
 */
@property UInt32Value * _Nonnull ClientType;

/**
 客户端版本
 */
@property StringValue * _Nonnull ClientVer;

/**
 客户机标识：MAC
 */
@property StringValue * _Nonnull ClientFlag;

/**
 客户机操作系统标志：0-未知、1-XP、2-Vista、3-Win7、4-Win8
 */
@property UInt8Value * _Nonnull ClientOSFlag;
@end


/**
 客户端接入回执
 */
@interface ClientIn_s2c : ISocketData
/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 用户会话密钥长度
 */
@property UInt32Value * _Nonnull SessionKeyLength;

/**
 用户会话密钥
 */
@property NSMutableArray<Int8Value *> * _Nonnull sessionKeyCharArr_Int8Value;

/**
 客户端软件升级信息
 */
@property StringValue * _Nonnull UpgradeInfo;

/**
 客户端的公网IP
 */
@property UInt32Value * _Nonnull ClientInternetIP;

/**
 客户端引导提示信息
 */
@property StringValue * _Nonnull ClientPilotTips;

/**
 客户端网络状况提交间隔，0表示不提交，单位：秒
 */
@property UInt32Value * _Nonnull NetworkCommitInterval;
@end

/**
 用户登录请求
 */
@interface UserLogin_c2s : ISocketData
/**
 用户登录帐号类型： 0-用户唯一标识号、1-用户名
 */
@property UInt8Value * _Nonnull AccountType;

/**
 用户帐号
 */
@property StringValue * _Nonnull Account;

/**
 验证票据长度
 */
@property UInt32Value * _Nonnull AuthTicketLength;

/**
 验证票据： MD5(MD5(用户密码) + 会话密钥)
 */
@property NSMutableArray<Int8Value *> * _Nonnull AuthTicketCharArr_Int8Value;

/**
 用户登录成功后缺省状态 0-在线、1-忙碌、2-勿扰、3-离开、4-隐身
 */
@property UInt8Value * _Nonnull DefaultStatus;

/**
 扩展用户密码
 */
@property StringValue * _Nonnull ExternPassword;
@end


/**
 用户登录回执
 */
@interface UserLogin_s2c : ISocketData
/**
 返回码： 0x00000000-成功 0x00000009-数据库访问错误
 0x01040001-不支持的客户端版本 0x02010001-未知的帐号类型 0x02010002-帐号格式错 0x02010003-帐号不存在 0x02010004-登录密码错
 0x02010005-帐号已锁定
 0x02010006-帐号未激活
 */
@property UInt32Value * _Nonnull RspCode;

/**
 用户唯一标识号
 */
@property UInt64Value * _Nonnull UID;

/**
 token
 */
@property StringValue * _Nonnull token;

@property UInt8Value * _Nonnull online_status;

/**
 服务器时间
 */
@property UInt64Value * _Nonnull ServerTime;

@end

/**
 用户登出请求
 */
@interface UserLogout_c2s : ISocketData

@end

/**
 用户登出完毕请求
 */
@interface UserLoginComplete_c2s : ISocketData

@end

/**
 强制下线
 */
@interface ForceOut_s2c : ISocketData

/**
 强制用户下线原因code
 */
@property UInt32Value * _Nonnull reasion;
@end

/**
 变更用户在线状态请求
 */
@interface ChangeUserLoginState_c2s : ISocketData

/**
 用户状态： 0-在线、1-忙碌、2-勿扰、3-离开、4-隐身
 */
@property UInt8Value * _Nonnull Status;
@end


/**
 变更用户在线状态回执
 */
@interface ChangeUserLoginState_s2c : ISocketData
/**
 用户状态： 0-在线、1-忙碌、2-勿扰、3-离开、4-隐身
 */
@property UInt8Value * _Nonnull Status;
@end

/**
 上报用户打点数据请求
 */
@interface UploadUserPoint_c2s : ISocketData
/**
 打点数据类型
 */
@property UInt8Value * _Nonnull Type;
@property UInt32Value * _Nonnull Data1;
@property UInt32Value * _Nonnull Data2;
@property UInt32Value * _Nonnull Data3;
@property UInt32Value * _Nonnull Data4;

/**
 MoreData字节长度
 */
@property UInt32Value * _Nonnull MoreDataLength;
@property NSMutableArray<Int8Value *> * _Nonnull MoreDataCharArr_Int8Value;
@end

/**
 PingTest请求
 */
@interface PintTest_c2s : ISocketData
/**
 数据类型
 */
@property UInt8Value * _Nonnull Type;
@property UInt32Value * _Nonnull Data1;
@property UInt32Value * _Nonnull Data2;
@end


/**
 PingTest回执
 */
@interface PintTest_s2c : ISocketData
/**
 数据类型
 */
@property UInt8Value * _Nonnull Type;
@property UInt32Value * _Nonnull Data1;
@property UInt32Value * _Nonnull Data2;
@end

/**
 获取AppQA请求
 */
@interface GetAppQA_c2s : ISocketData
/**
 数据类型
 */
@property UInt32Value * _Nonnull Type;
@property UInt32Value * _Nonnull QaData;
@property StringValue * _Nonnull ExtData;
@end


/**
 获取AppQA回执
 */
@interface GetAppQA_s2c : ISocketData
/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;
@end


/**
 设置AppQA接受者请求
 */
@interface SetAppQARecipient_c2s : ISocketData
@property UInt32Value * _Nonnull Type;
@property UInt32Value * _Nonnull UserNum;
@property NSMutableArray<Int8Value *> * _Nonnull VecUser_Int8Value;
@end


/**
 设置AppQA接受者回执
 */
@interface SetAppQARecipient_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt32Value * _Nonnull Type;
@end

/**
 重置AppQA接受者请求
 */
@interface ResetAppQARecipient_c2s : ISocketData
@property UInt32Value * _Nonnull Type;
@end


/**
 重置AppQA接受者回执
 */
@interface ResetAppQARecipient_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt32Value * _Nonnull Type;
@end

/**
 上传媒体引擎网络数据打点请求
 */
@interface UploadMediaPoint_c2s : ISocketData
@property UInt8Value * _Nonnull Type;
@property UInt64Value * _Nonnull CID;
@property UInt32Value * _Nonnull DelayP2P;
@property UInt32Value * _Nonnull DelayP2S;
@property UInt32Value * _Nonnull PacketLoss;
@property UInt32Value * _Nonnull UpPacketLoss;
@property UInt32Value * _Nonnull DownPacketLoss;
@end

/**
 发布用户自定义通知请求
 */
@interface SendCustomNotify_c2s : ISocketData

/**
 消息类型
 1：红包消息
 2：
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Content;

/**
 目标用户数量
 */
@property UInt32Value * _Nonnull UserIDNum;

/**
 目标用户UID数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull UIDArr_UInt64Value;
@end

/**
 发布用户自定义通知回执
 */
@interface SendCustomNotify_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end


/**
 收到用户自定义通知
 */
@interface ReciveCustomNotify_s2cNotify : ISocketData
/**
 消息类型
 1：红包消息
 2：
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Content;
@end

/**
 获取在线用户数请求
 */
@interface GetOnlineUserNum_c2s : ISocketData
@property UInt32Value * _Nonnull Reserved;
@end


/**
 获取在线用户数回执
 */
@interface GetOnlineUserNum_s2c : ISocketData
@property UInt32Value * _Nonnull UserNum;
@property UInt32Value * _Nonnull Reserved;
@end

/**
 未知
 */
@interface GetUserDotDataSwitch_c2s : ISocketData
@property UInt32Value * _Nonnull Reserved;
@end


/**
 未知
 */
@interface GetUserDotDataSwitch_s2c : ISocketData
@property Int32Value * _Nonnull Switch;
@property UInt32Value * _Nonnull Reserved;
@end

/**
 未知
 */
@interface SetUserDotDataSwitch_c2s : ISocketData
@property Int32Value * _Nonnull Switch;
@property UInt32Value * _Nonnull Reserved;
@end


/**
 未知
 */
@interface SetUserDotDataSwitch_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt32Value * _Nonnull Switch;
@property UInt32Value * _Nonnull Reserved;
@end

/**
 网络质量测试请求
 */
@interface NetWorkTest_c2s : ISocketData

/**
 用户id数量
 */
@property UInt32Value * _Nonnull UserIDNum;

/**
 用户id数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull VecUserIDArr_UInt64Value;

/**
 测试IP数量
 */
@property UInt32Value * _Nonnull TestIPNum;

/**
 测试IP数组
 */
@property NSMutableArray<StringValue *> * _Nonnull VecTestIPArr_StringValue;

/**
 测试端口
 */
@property UInt16Value * _Nonnull Port;

/**
 测试类型：0: all 1: udp 2: ping 3: traceroute
 */
@property UInt8Value * _Nonnull TestType;

/**
 运行时间
 */
@property UInt16Value * _Nonnull RunTime;

/**
 发送带宽
 */
@property UInt32Value * _Nonnull SendBandwidth;

/**
 发送包大小
 */
@property UInt16Value * _Nonnull SendSize;

/**
 接收带宽
 */
@property UInt32Value * _Nonnull ReceiveBandwidth;

/**
 接收包大小
 */
@property UInt16Value * _Nonnull ReceiveSize;

/**
 工作模式： 0：非自动 1：自动
 */
@property UInt8Value * _Nonnull WorkingMode;

/**
 保留字段
 */
@property UInt32Value * _Nonnull Reserved;
@end


/**
 网络质量测试回执
 */
@interface NetWorkTest_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 网络质量测试结果通知
 */
@interface NetWorkTestResult_s2cNotify : ISocketData

/**
 IP数量
 */
@property UInt32Value * _Nonnull TestIPNum;

/**
 测试IP数组
 */
@property NSMutableArray<StringValue *> * _Nonnull VecTestIPArr_StringValue;

/**
 测试端口
 */
@property UInt16Value * _Nonnull Port;

/**
 测试类型：0: all 1: udp 2: ping 3: traceroute
 */
@property UInt8Value * _Nonnull TestType;

/**
 运行时间
 */
@property UInt16Value * _Nonnull RunTime;

/**
 发送带宽
 */
@property UInt32Value * _Nonnull SendBandwidth;

/**
 发送包大小
 */
@property UInt16Value * _Nonnull SendSize;

/**
 接收带宽
 */
@property UInt32Value * _Nonnull ReceiveBandwidth;

/**
 接收包大小
 */
@property UInt16Value * _Nonnull ReceiveSize;

/**
 工作模式： 0：非自动 1：自动
 */
@property UInt8Value * _Nonnull WorkingMode;
@property UInt32Value * _Nonnull Reserved;
@end

/**
 获取服务器时间请求
 */
@interface GetServerTime_c2s : ISocketData

@end


/**
 获取服务器时间回执
 */
@interface GetServerTime_s2c : ISocketData

/**
 服务器时间(1970+seconds)
 */
@property UInt64Value * _Nonnull ServerTime;

/**
 UTC时区 (+表示东 –表示西)
 */
@property Int32Value * _Nonnull UTCZone;

/**
 保留字段
 */
@property Int32Value * _Nonnull Reserved;
@end

/**
 获取用户在线状态请求
 */
@interface GetUserOnlineState_c2s : ISocketData
/**
 查询的用户ID数量
 */
@property UInt32Value * _Nonnull UserIDNum;

/**
 用户ID数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull UserIDArr_UInt64Value;
@end

@interface UserOnLineStateEntity : ISocketData
/**
 用户ID
 */
@property UInt64Value * _Nonnull UserID;

/**
 用户在线状态
 */
@property UInt8Value * _Nonnull State;

/**
 用户客户端类型
 */
@property UInt8Value * _Nonnull ClientType;

/**
 保留字段
 */
@property UInt8Value * _Nonnull Reserved;
@end

/**
 获取用户在线状态回执
 */
@interface GetUserOnlineState_s2c : ISocketData
/**
 用户数量
 */
@property UInt32Value * _Nonnull UserNum;

/**
 用户信息数组
 */
@property NSMutableArray<UserOnLineStateEntity *> * _Nonnull userArr_UserOnLineStateEntity;
@end

/**
 A端发送聊天消息请求
 */
@interface A_SendMsg_c2s : ISocketData
/**
 消息ID，上行缺省不填写
 */
@property UInt64Value * _Nonnull MessageID;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SentTime;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息文字
 */
@property StringValue * _Nonnull ChatMessage;
@end

/**
 B端收到聊天消息
 */
@interface B_ReciveMsg_s2c : ISocketData

/**
 消息ID，配合聊天消息文本确认（0x00120011）协议使用
 */
@property UInt64Value * _Nonnull MessageID;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SentTime;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息文字
 */
@property StringValue * _Nonnull ChatMessage;
@end

@interface OffLineMsgEntity : ISocketData
/**
 消息ID
 */
@property UInt64Value * _Nonnull MessageID;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SentTime;

/**
 发送者UID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息文字
 */
@property StringValue * _Nonnull ChatMessage;
@end;

/**
 批量聊天消息文本（离线消息）收到消息后客户端需要发送聊天消息文本确认
 */
@interface ReciveOffLineMsg_s2cNotify : ISocketData

@property UInt32Value * _Nonnull Reserved;
/**
 消息数量
 */
@property UInt32Value * _Nonnull MessageCount;

/**
 消息数组
 */
@property NSMutableArray<OffLineMsgEntity *> * _Nonnull msgArr_OffLineMsgEntity;
@end

/**
 B端发送已经收到聊天消息的确认请求
 */
@interface B_SendMsgOk_c2s : ISocketData

/**
 消息ID，填写聊天消息文字下行（0x00120010）中MessageID的最大值
 */
@property UInt64Value * _Nonnull MessageID;

/**
 确认码，缺省填写1
 */
@property UInt16Value * _Nonnull AckCode;
@end


/**
 获取课程列表请求
 */
@interface GetClassList_c2s : ISocketData

/**
 请求Web Server协议类型
 0：http
 1：https
 */
@property UInt8Value * _Nonnull ProtoType;

/**
 0：post
 1：get
 */
@property UInt8Value * _Nonnull ReqType;

/**
 比如
 Ac/MyLesson/getTeaLessonList
 */
@property StringValue * _Nonnull Path;

/**
 以&分割的参数列表，比如
 relId=1546600&type=stu&token=1546600_2d98d1ab6668604e81c8e94f251a1d23stu&buildver=2.6.178.78&lang=En&emergency=ac&ssoToken=xxxxxxxx&from=pc&query=qqqqqqq
 */
@property StringValue * _Nonnull Params;

/**
 保留字段
 */
@property StringValue * _Nonnull ExtData;
@end


/**
 获取课程列表回执
 */
@interface GetClassList_s2c : ISocketData
/**
 0：成功
 */
@property UInt32Value * _Nonnull RspCode;
@property UInt32Value * _Nonnull HttpCode;
@property StringValue * _Nonnull Result;
@end

/**
 获取群信息请求
 */
@interface GetGroupInfo_c2s : ISocketData
@property UInt64Value * _Nonnull GID;
@end


/**
 获取群信息回执
 */
@interface GetGroupInfo_s2c : ISocketData

/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识
 */
@property UInt64Value * _Nonnull GID;

/**
 群主用户唯一标识
 */
@property UInt64Value * _Nonnull OwnerUID;

/**
 群信息版本
 */
@property UInt32Value * _Nonnull InfoVer;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 群状态：0-正常、1-锁定
 */
@property UInt8Value * _Nonnull Status;

/**
 群名称
 */
@property StringValue * _Nonnull Name;

/**
 群类型
 */
@property UInt32Value * _Nonnull Type;

/**
 VIP群标识：0-非VIP群
 */
@property UInt8Value * _Nonnull VIPFlag;

/**
 群等级
 */
@property UInt8Value * _Nonnull Level;

/**
 群认证方式：0-任何人可以加入、1-需要身份验证、2-不允许加入
 */
@property UInt8Value * _Nonnull AuthType;

/**
 群简介
 */
@property StringValue * _Nonnull Brief;

/**
 群公告
 */
@property StringValue * _Nonnull Notice;
@end

/**
 群组信息变更通知
 */
@interface GroupInfoChangeNotify_s2cNotify : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群信息版本
 */
@property UInt32Value * _Nonnull InfoVer;

/**
 群状态：0-正常、1、锁定
 */
@property UInt8Value * _Nonnull Status;
@end

/**
 获取群用户列表请求
 */
@interface GetGroupUserList_c2s : ISocketData
@property UInt64Value * _Nonnull GID;
@end

@interface GroupUserInfo : ISocketData

/**
 群成员用户唯一标识
 */
@property UInt64Value * _Nonnull UID;

/**
 群成员在线状态：
 第1字节-PC、第2字节-Mobile、第3字节-Web
 0-离线、1-在线、2-忙碌、3-勿扰、4-离开、5-隐身
 */
@property UInt32Value * _Nonnull Status;

/**
 群成员权限
 */
@property UInt8Value * _Nonnull Right;

/**
 群名片更改设置：0-不允许被修改、1-允许管理员修改
 */
@property UInt8Value * _Nonnull CardSetting;

/**
 群名片版本
 */
@property UInt32Value * _Nonnull CardInfoVer;

/**
 昵称
 */
@property StringValue * _Nonnull Nickname;

/**
 群身份：0-普通成员、1-管理员、255-群主
 */
@property UInt8Value * _Nonnull Identity;

/**
 群名片性别
 */
@property UInt8Value * _Nonnull Gender;

/**
 群名片电话
 */
@property StringValue * _Nonnull Tel;

/**
 群名片邮箱
 */
@property StringValue * _Nonnull Email;

/**
 群名片个人说明
 */
@property StringValue * _Nonnull Comment;
@end

/**
 获取群用户列表回执
 */
@interface GetGroupUserList_s2c : ISocketData
/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 群成员数量
 */
@property UInt32Value * _Nonnull MemberNum;

/**
 组成员
 */
@property NSMutableArray<GroupUserInfo *> * _Nonnull memberArr_GroupUserInfo;
@end

/**
 群组成员列表变更通知
 */
@interface GroupUserListChange_s2cNotify : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;
@end

@interface SyncGroupUserEntity : ISocketData
/**
 群成员用户唯一标识
 */
@property UInt64Value * _Nonnull UID;

/**
 群成员身份
 */
@property UInt8Value * _Nonnull Identity;

/**
 群成员用户昵称
 */
@property StringValue * _Nonnull NickName;
@end
/**
 同步群组成员列表请求
 */
@interface SyncGroupUserList_c2s : ISocketData
/**
 群ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群名称
 */
@property StringValue * _Nonnull Name;


/**
 群成员数量
 */
@property UInt32Value * _Nonnull arrNum;

/**
 群成员
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull members_SyncGroupUserEntity;
@end


/**
 同步群组成员列表回执
 */
@interface SyncGroupUserList_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;
@end

/**
 创建群组请求
 */
@interface CreateGroup_c2s : ISocketData
/**
 群名称
 */
@property StringValue * _Nonnull Name;
/**
 群类型
 */
@property UInt32Value * _Nonnull Type;

/**
 VIP群标识：0-非VIP群
 */
@property UInt8Value * _Nonnull VIPFlag;

/**
 群认证方式：0-任何人可以加入、1-需要身份验证、2-不允许加入
 */
@property UInt8Value * _Nonnull AuthType;

/**
 群简介
 */
@property StringValue * _Nonnull Brief;

/**
 群公告
 */
@property StringValue * _Nonnull Notice;

/**
 群成员数量
 */
@property UInt32Value * _Nonnull MemberNum;

/**
 群成员信息
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull memberArr_SyncGroupUserEntity;
@end


/**
 群建群组回执
 */
@interface CreateGroup_s2c : ISocketData

/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群名称
 */
@property StringValue * _Nonnull Name;

/**
 群类型
 */
@property UInt32Value * _Nonnull Type;

/**
 VIP群标识：0-非VIP群
 */
@property UInt8Value * _Nonnull VIPFlag;

/**
 群认证方式：0-任何人可以加入、1-需要身份验证、2-不允许加入
 */
@property UInt8Value * _Nonnull AuthType;

/**
 群简介
 */
@property StringValue * _Nonnull Brief;

/**
 群公告
 */
@property StringValue * _Nonnull Notice;

/**
 群成员数量
 */
@property UInt32Value * _Nonnull MemberNum;

/**
 群成员信息
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull memberArr_SyncGroupUserEntity;
@end

/**
 创建群组通知
 */
@interface CreateGroup_s2cNotify : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 0：创建群组时被加入到群组；1：被加入到群组
 */
@property UInt8Value * _Nonnull OperateType;
@end

/**
 删除群组请求
 */
@interface DeleteGroup_c2s : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;
@end


/**
 删除群组回执
 */
@interface DeleteGroup_s2c : ISocketData

/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识
 */
@property UInt64Value * _Nonnull GID;

/**
 群名称
 */
@property StringValue * _Nonnull Name;
@end

/**
 删除群组通知
 */
@interface DeleteGroup_s2cNotify : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群名称
 */
@property StringValue * _Nonnull Name;

/**
 0：群组被解除；1：群成员被从群组移出
 */
@property UInt8Value * _Nonnull OperateType;
@end

/**
 添加用户到群组请求
 */
@interface AddUserToGroup_c2s : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 添加群成员数量
 */
@property UInt32Value * _Nonnull AddMemberNum;

/**
 成员数组
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull memberArr_SyncGroupUserEntity;
@end


/**
 添加用户到群组回执
 */
@interface AddUserToGroup_s2c : ISocketData
/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识
 */
@property UInt64Value * _Nonnull uint64;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 添加群成员数量
 */
@property UInt32Value * _Nonnull AddMemberNum;
/**
 成员数组
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull memberArr_SyncGroupUserEntity;
@end

/**
 添加用户到群组的通知
 */
@interface AddUserToGroup_s2cNotify : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 加入类型：0-被邀请、1-主动申请被批准
 */
@property UInt8Value * _Nonnull AddType;

/**
 邀请者用户唯一标识
 */
@property UInt64Value * _Nonnull InviteUID;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 添加群成员数量
 */
@property UInt32Value * _Nonnull AddMemberNum;
/**
 成员数组
 */
@property NSMutableArray<SyncGroupUserEntity *> * _Nonnull memberArr_SyncGroupUserEntity;
@end

/**
 删除用户到群组请求
 */
@interface DeleteUserToGroup_c2s : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 删除的群成员数量
 */
@property UInt32Value * _Nonnull DelMemberNum;

/**
 用户ID数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull UIDArr_UInt64Value;
@end


/**
 删除用户到群组回执
 */
@interface DeleteUserToGroup_s2c : ISocketData

/**
 返回码： 0x00000000-成功
 */
@property UInt32Value * _Nonnull RspCode;

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 删除的群成员数量
 */
@property UInt32Value * _Nonnull DelMemberNum;
/**
 用户ID数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull UIDArr_UInt64Value;
@end

@interface DeleteGroupUser : ISocketData

/**
 群成员用户唯一标识
 */
@property UInt64Value * _Nonnull UID;

/**
 昵称
 */
@property StringValue * _Nonnull NickName;
@end
/**
 删除用户到群组的通知
 */
@interface DeleteUserToGroup_s2cNotify : ISocketData
/**
 群唯一标识
 */
@property UInt64Value * _Nonnull GID;

/**
 管理员用户唯一标识ID
 */
@property UInt64Value * _Nonnull AdminUID;

/**
 群成员列表版本
 */
@property UInt32Value * _Nonnull MemberListVer;

/**
 群成员数量
 */
@property UInt32Value * _Nonnull MemberNum;

/**
 群成员信息
 */
@property NSMutableArray<DeleteGroupUser *> * _Nonnull memberArr_DeleteGroupUser;
@end

/**
 群组成员在线状态变更通知
 */
@interface MemberOnlineStatusChange_s2cNotify : ISocketData

/**
 群唯一标识
 */
@property UInt64Value * _Nonnull GID;

/**
 群成员用户唯一标识ID
 */
@property UInt64Value * _Nonnull UID;

/**
 群成员在线状态：
 第1字节-PC、第2字节-Mobile、第3字节-Web
 0-离线、1-在线、2-忙碌、3-勿扰、4-离开、5-隐身
 */
@property UInt32Value * _Nonnull Status;
@end

@interface GroupUserState : ISocketData
@property UInt64Value * _Nonnull UID;
@property UInt32Value * _Nonnull Status;
@end

/**
 批量群组成员在线状态变更通知
 */
@interface MoreMemberOnlineStatusChange_s2cNotify : ISocketData
/**
 群唯一标识
 */
@property UInt64Value * _Nonnull GID;

/**
 群成员数量
 */
@property UInt32Value * _Nonnull MemberNum;

/**
 成员信息
 */
@property NSMutableArray<GroupUserState *> * _Nonnull memberArr_GroupUserState;
@end

/**
 管理员下发聊天消息请求
 */
@interface AdminSendMsgInGroup_c2s : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 发送消息的管理员UID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 本地聊天消息编号
 */
@property UInt32Value * _Nonnull Sequence;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息内容
 */
@property StringValue * _Nonnull ChatMsg;
@end


/**
 管理员下发聊天消息回执
 */
@interface AdminSendMsgInGroup_s2c : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 本地聊天消息编号
 */
@property UInt32Value * _Nonnull Sequence;

/**
 0：发送成功；1：群不存在，发送失败；2：发送内容包含敏感词，发送失败
 */
@property UInt8Value * _Nonnull Status;

/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;

/**
 发送消息的服务器时间
 */
@property UInt32Value * _Nonnull SendTime;
@end

/**
 组内发送聊天消息请求
 */
@interface SendMsgInGroup_c2s : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 本地聊天消息编号
 */
@property UInt32Value * _Nonnull Sequence;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SendTime;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息内容
 */
@property StringValue * _Nonnull ChatMsg;
@end

/**
 服务器确认该聊天记录的发送结果
 */
@interface SendMsgInGroupOk_s2cNotify : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 本地聊天消息编号
 */
@property UInt32Value * _Nonnull Sequence;

/**
 0：发送成功；1：群不存在，发送失败；2：发送内容包含敏感词，发送失败
 */
@property UInt8Value * _Nonnull Status;

/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;

/**
 发送消息的服务器时间
 */
@property UInt32Value * _Nonnull SendTime;
@end

/**
 收到组内聊天消息
 */
@interface ReciveMsgInGroup_s2c : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;

/**
 发送聊天消息的用户唯一标识ID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SendTime;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息内容
 */
@property StringValue * _Nonnull ChatMsg;
@end

@interface OfflineMsgInGroupEntity : ISocketData
/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;

/**
 发送聊天消息的用户唯一标识ID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 发送时间
 */
@property UInt32Value * _Nonnull SendTime;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息设置： font=宋体\r\n
 */
@property StringValue * _Nonnull Option;

/**
 聊天消息内容
 */
@property StringValue * _Nonnull ChatMsg;
@end
/**
 向服务器发送是否已经收到消息的恢复
 */
@interface ReciveMsgInGroupOk_c2s : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;
@end

/**
 收到离线时间段内未收到的组聊天消息
 */
@interface ReciveOfflineMsgInGroup_s2cNotify : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 离线消息数量
 */
@property UInt32Value * _Nonnull MsgNum;

/**
 消息数组
 */
@property NSMutableArray<OfflineMsgInGroupEntity *> * _Nonnull msgArr_OfflineMsgInGroupEntity;
@end

/**
 获取组内聊天消息记录请求
 */
@interface GetGroupMsgRecord_c2s : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 0：从BeginMsgID向前获取消息
 1：从BeginMsgID后获取消息
 */
@property UInt8Value * _Nonnull Direction;

/**
 起始群聊天消息ID
 */
@property UInt64Value * _Nonnull BeginMsgID;

/**
 群消息数量
 */
@property UInt32Value * _Nonnull MsgNum;
@end


/**
 获取组内聊天消息记录回执
 */
@interface GetGroupMsgRecord_s2c : ISocketData

/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;

/**
 0：从BeginMsgID向前获取消息
 1：从BeginMsgID后获取消息
 */
@property UInt8Value * _Nonnull Direction;

/**
 起始群聊天消息ID
 */
@property UInt64Value * _Nonnull BeginMsgID;

/**
 群消息数量
 */
@property UInt32Value * _Nonnull MsgNum;

/**
 消息集合
 */
@property NSMutableArray<OfflineMsgInGroupEntity *> * _Nonnull msgArr_OfflineMsgInGroupEntity;
@end

/**
 上报进去群 日志请求
 */
@interface UploadJoinGroupLog_c2s : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;
@end

/**
 上报离开群 日志请求
 */
@interface UploadLeaveGroupLog_c2s : ISocketData
/**
 群唯一标识ID
 */
@property UInt64Value * _Nonnull GID;
@end

/**
 添加敏感词请求
 */
@interface AddSensitiveWords_c2s : ISocketData

/**
 敏感词数量
 */
@property UInt32Value * _Nonnull WordNum;

/**
 敏感词数组
 */
@property NSMutableArray<StringValue *> * _Nonnull wordArr_StringValue;
@end


/**
 添加敏感词回执
 */
@interface AddSensitiveWords_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;

/**
 敏感词数量
 */
@property UInt32Value * _Nonnull WordNum;
@end

/**
 删除敏感词请求
 */
@interface DeleteSensitiveWords_c2s : ISocketData
/**
 敏感词数量
 */
@property UInt32Value * _Nonnull WordNum;

/**
 敏感词数组
 */
@property NSMutableArray<StringValue *> * _Nonnull wordArr_StringValue;
@end


/**
 删除敏感词回执
 */
@interface DeleteSensitiveWords_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;

/**
 敏感词数量
 */
@property UInt32Value * _Nonnull WordNum;
@end

/**
 清空敏感词请求
 */
@interface ClearSensitiveWords_c2s : ISocketData

@end


/**
 清空敏感词回执
 */
@interface ClearSensitiveWords_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 获取教室设置请求
 */
@interface GetCommonConfig_c2s : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;
@end


/**
 获取教室设置回执
 */
@interface GetCommonConfig_s2c : ISocketData

/**
 错误码
 */
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 最大文本消息长度
 */
@property UInt32Value * _Nonnull TxtMsgSize;

/**
 发送文本消息频率
 */
@property UInt32Value * _Nonnull TxtMsgRate;

/**
 第0位：能否切换PDF页码，0-禁止；1-允许
 第4位：教室能否文本发言，0-禁止；1-允许
 */
@property UInt32Value * _Nonnull Set;

/**
 自定义设置数量
 */
@property UInt32Value * _Nonnull SetArrayNum;

/**
 setting信息
 */
@property NSMutableArray<UInt32Value *> * _Nonnull settingArr_UInt32Value;
@end

/**
 设置教室设置请求
 */
@interface SetCommonConfig_c2s : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 最大文本消息长度
 */
@property UInt32Value * _Nonnull TxtMsgSize;

/**
 发送文本消息频率
 */
@property UInt32Value * _Nonnull TxtMsgRate;

/**
 设置
 */
@property UInt32Value * _Nonnull Set;

/**
 自定义设置数量
 */
@property UInt32Value * _Nonnull SetArrayNum;
/**
 setting信息
 */
@property NSMutableArray<UInt32Value *> * _Nonnull settingArr_UInt32Value;
@end


/**
 设置教室设置回执
 */
@interface SetCommonConfig_s2c : ISocketData

/**
 错误码
 */
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 最大文本消息长度
 */
@property UInt32Value * _Nonnull TxtMsgSize;

/**
 发送文本消息频率
 */
@property UInt32Value * _Nonnull TxtMsgRate;

/**
 设置
 */
@property UInt32Value * _Nonnull Set;

/**
 自定义设置数量
 */
@property UInt32Value * _Nonnull SetArrayNum;
/**
 setting信息
 */
@property NSMutableArray<UInt32Value *> * _Nonnull settingArr_UInt32Value;
@end

/**
 收到教室设置通知
 */
@interface CommonConfig_s2cNotify : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 最大文本消息长度
 */
@property UInt32Value * _Nonnull TxtMsgSize;

/**
 发送文本消息频率
 */
@property UInt32Value * _Nonnull TxtMsgRate;

/**
 设置
 */
@property UInt32Value * _Nonnull Set;

/**
 自定义设置数量
 */
@property UInt32Value * _Nonnull SetArrayNum;
/**
 setting信息
 */
@property NSMutableArray<UInt32Value *> * _Nonnull settingArr_UInt32Value;
@end

/**
 获取媒体引擎相关配置请求
 */
@interface GetMediaConfig_c2s : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;
@end


/**
 获取媒体引擎相关配置回执
 */
@interface GetMediaConfig_s2c : ISocketData

@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 第0位：0-不开启客户端本地媒体录制；1-开启
 第1位：0-不开启服务端媒体录制；1-开启
 第2位：0-不开始服务端直播；1-开启
 */
@property UInt32Value * _Nonnull Flag;

/**
 自定义配置项数量
 */
@property UInt8Value * _Nonnull ConfItemNum;

/**
 自定义配置项
 */
@property NSMutableArray<UInt32Value *> * _Nonnull ConfArray_UInt32Value;
@end

/**
 获取教室内最大支持在线人数请求
 */
@interface GetClassRoomMax_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull Reserved;
@end


/**
 获取教室内最大支持在线人数回执
 */
@interface GetClassRoomMax_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 最高在线人数
 */
@property UInt32Value * _Nonnull MaxLiveNum;

/**
 最高在线人数时间
 */
@property UInt32Value * _Nonnull MaxLiveNumTime;
@property UInt32Value * _Nonnull Reserved;
@end

/**
 获取aliveRoom数量请求
 */
@interface GetAliveRoomCount_c2s : ISocketData
@property UInt32Value * _Nonnull Reserved;
@end


/**
 获取aliveRoom数量回执
 */
@interface GetAliveRoomCount_s2c : ISocketData
/**
 教室数量
 */
@property UInt32Value * _Nonnull ClassNum;
@property UInt32Value * _Nonnull Reserved;
@end


/**
 进入教室请求
 */
@interface JoinRoom_c2s : ISocketData
/**
 学校ID
 */
@property UInt64Value * _Nonnull SID;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 教材ID
 */
@property UInt64Value * _Nonnull CourseID;

/**
 用户角色
 */
@property UInt8Value * _Nonnull UserRole;

/**
 用户身份
 */
@property UInt8Value * _Nonnull UserIdentity;

/**
 用户权限
 */
@property UInt8Value * _Nonnull UserRight;

/**
 保留字段
 */
@property UInt8Value * _Nonnull reserved_3;

/**
 
 */
@property UInt32Value * _Nonnull UserSwitchFlag;

/**
 用户昵称
 */
@property StringValue * _Nonnull UserName;

/**
 本地可用sdk数量
 */
@property UInt32Value * _Nonnull AVSDKNum;

/**
 本地可用sdk列表
 */
@property NSMutableArray<UInt8Value *> * _Nonnull AVSDKArr_UInt8Value;

/**
 用户custom数据
 */
@property StringValue * _Nonnull UserCusData;
@end

@interface AssistantEntity : ISocketData
/**
 用户ID
 */
@property UInt64Value * _Nonnull AssistID;

/**
 用户昵称
 */
@property StringValue * _Nonnull UserName;

/**
 用户权限
 */
@property UInt8Value * _Nonnull Identity;

/**
 用户权限
 */
@property UInt8Value * _Nonnull UserRight;

/**
 用户开关
 */
@property UInt8Value * _Nonnull UserSwitchFlag;

/**
 客户端类型
 */
@property UInt8Value * _Nonnull ClientType;

/**
 用户角色
 */
@property UInt8Value * _Nonnull UserRole;
@end

@interface CustomEntity : ISocketData

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户昵称
 */
@property StringValue * _Nonnull UserName;

/**
 用户权限
 */
@property UInt8Value * _Nonnull Identity;

/**
 用户权限
 第0位：能否文本发言，0-允许；1-禁止
 第1位：是否是付费用户，0-否；1-是
 第2位：是否是B2S付费用户，0-否；1-是
 第3位：用户是否隐身，0-否；1-是
 */
@property UInt32Value * _Nonnull UserRight;

/**
 用户开关
 */
@property UInt8Value * _Nonnull UserSwitchFlag;

/**
 客户端类型
 */
@property UInt8Value * _Nonnull ClientType;

/**
 用户角色
 */
@property UInt8Value * _Nonnull UserRole;
@end

/**
 进入教室回执
 */
@interface JoinRoom_s2c : ISocketData
/**
 0x00000000：进入教室成功
 0x00100001：教室不存在
 0x00100014：教室人数超过上限
 0x00100030：排麦人数超过上限
 */
@property UInt32Value * _Nonnull RspCode;

/**
 学校ID
 */
@property UInt64Value * _Nonnull SID;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 
 */
@property UInt64Value * _Nonnull CourseID;

/**
 学校名称
 */
@property StringValue * _Nonnull SchoolName;

/**
 教室名称
 */
@property StringValue * _Nonnull ClassName;

/**
 开始上课时间
 */
@property UInt32Value * _Nonnull StartTime;

/**
 课程状态
 */
@property UInt8Value * _Nonnull Status;

/**
 消息模式
 */
@property UInt8Value * _Nonnull MsgMode;
@property UInt64Value * _Nonnull SwitchFlag;
@property UInt64Value * _Nonnull OperatonFlag;

/**
 校长ID
 */
@property UInt64Value * _Nonnull OwnerID;

/**
 校长是否在教室内
 */
@property UInt8Value * _Nonnull OwnerIn;

/**
 校长名称
 */
@property StringValue * _Nonnull OwnerName;

/**
 老师ID
 */
@property UInt64Value * _Nonnull TeacherID;

/**
 老师是否在教室内
 */
@property UInt8Value * _Nonnull TeacherIn;

/**
 老师名称
 */
@property StringValue * _Nonnull TeacherName;

/**
 助教数量
 */
@property UInt32Value * _Nonnull AssistantNum;

/**
 助教数组
 */
@property NSMutableArray<AssistantEntity *> * _Nonnull AssistantArr_AssistantEntity;

/**
 用户数量
 */
@property UInt32Value * _Nonnull CustomNum;

/**
 用户数组
 */
@property NSMutableArray<CustomEntity *> * _Nonnull CustomArr_CustomEntity;

/**
 用户对应的mediaID数量
 */
@property UInt32Value * _Nonnull MediaIdNum;

/**
 用户对应的mediaID数组
 */
@property NSMutableArray<UInt32Value *> * _Nonnull mediaIDArr_UInt32Value;

/**
 自定义数据数量
 */
@property UInt32Value * _Nonnull customDataNum;

/**
 用户自定义数据数组
 */
@property NSMutableArray<StringValue *> * _Nonnull customDataArr_StringValue;
@end

/**
 其他人进入教室通知
 */
@interface OtherUserJoinRoom_s2cNotify : ISocketData
/**
 学校ID
 */
@property UInt64Value * _Nonnull SID;

/**
 课程ID
 */
@property UInt64Value * _Nonnull CID;

/**
 教材ID
 */
@property UInt64Value * _Nonnull CourseID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户昵称
 */
@property StringValue * _Nonnull UserName;

/**
 用户角色，对应ACRoleType
 */
@property UInt8Value * _Nonnull UserIdentity;

/**
 用户权限
 */
@property UInt32Value * _Nonnull UserRight;


/**
 消息开关
 */
@property UInt64Value * _Nonnull UserSwitchFlag;

/**
 客户端类型
 */
@property UInt8Value * _Nonnull ClientType;

/**
 用户角色
 */
@property UInt8Value * _Nonnull UserRole;

/**
 用户的mediaID
 */
@property UInt32Value * _Nonnull MediaID;

/**
 用户自定义数据
 */
@property StringValue * _Nonnull UserCusData;

/**
 时间
 */
@property UInt64Value * _Nonnull Time;
@end

/**
 进入教室完毕请求
 */
@interface JoinRoomComplete_c2s : ISocketData
@property UInt64Value * _Nonnull SID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull CourseID;
@end
/**
 进入教室完成 pb 新协议下发必备条件
 */

@interface joinRoomCompleteNew_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@end
/**
 离开教室请求
 */
@interface LeaveRoom_c2s : ISocketData
@property UInt64Value * _Nonnull SID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull CourseID;
@end

/**
 其他人离开教室通知
 */
@interface OtherUserLeaveRoom_s2cNotify : ISocketData
/**
 学校ID
 */
@property UInt64Value * _Nonnull SID;

/**
 课程ID
 */
@property UInt64Value * _Nonnull CID;

/**
 教材ID
 */
@property UInt64Value * _Nonnull CourseID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户昵称
 */
@property StringValue * _Nonnull UserName;

/**
 不知道做什么的权限
 */
@property UInt8Value * _Nonnull UserIdentity;


/**
 消息开关
 */
@property UInt64Value * _Nonnull UserSwitchFlag;
/**
 时间
 */
@property UInt64Value * _Nonnull Time;
@end

/**
 被踢出教室通知
 */
@interface KickOutRoom_s2cNotify : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 0：被管理员移出教室，Description字段为管理员UID
 1：同一UID在异地进入同一教室，Description字段为异地客户端的“IP|客户端类型”
 */
@property UInt8Value * _Nonnull Reason;

/**
 见Reason字段说明
 */
@property StringValue * _Nonnull Description;
@end

/**
 教室被服务端关闭通知
 */
@interface RoomClosed_s2cNotify : ISocketData
@property UInt64Value * _Nonnull SID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull CourseID;
@property UInt16Value * _Nonnull Reason;
@end

/**
 发送聊天 发送图片确认消息
 */
@interface ChatMsgSendImageComfirm : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull Type;
@property StringValue * _Nonnull Content;
@end

/**
 发送教室内聊天消息请求
 */
@interface ChatMsgInRoom_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property StringValue * _Nonnull Option;
@property StringValue * _Nonnull Text;
@end


/**
 发送教室内聊天消息回执
 */
@interface ChatMsgInRoom_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property StringValue * _Nonnull Option;
@property StringValue * _Nonnull Text;
@end

/**
 聊天消息回执（服务器接收确认）
 */
@interface ChatMsgInRoomOk_s2c : ISocketData

/**
 班级唯一标识ID
 */
@property UInt64Value * _Nonnull CID;

/**
 本地聊天消息编号
 */
@property UInt32Value * _Nonnull Sequence;

/**
 0：发送成功
 1：班级不存在，发送失败
 2：发送内容包含敏感词，发送失败
 3：教室已被禁言，发送失败
 4：用户已被禁用，发送失败
 5：用户不在教室，发送失败
 */
@property UInt8Value * _Nonnull Status;

/**
 群聊天消息ID
 */
@property UInt64Value * _Nonnull MsgID;

/**
 发送消息的服务器时间
 */
@property UInt32Value * _Nonnull SendTime;
@end

@interface WhiteBoardItem : ISocketData
@property UInt64Value * _Nonnull UID;
@property UInt32Value * _Nonnull ItemClientSeq;
@property UInt32Value * _Nonnull ItemServerSeq;
@property UInt32Value * _Nonnull Color;
@property UInt32Value * _Nonnull Reserved;
@property UInt8Value * _Nonnull FontSize;
@property UInt32Value * _Nonnull ItemDataLength;
@property NSMutableArray<UInt8Value*> * _Nonnull ItemData_UInt8Value;
@end

/**
 白板数据请求
 */
@interface WhiteBoardData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull Page;
@property UInt32Value * _Nonnull SentTime;
@property UInt32Value * _Nonnull MD5Length;
@property NSMutableArray<UInt8Value *> * _Nonnull md5_UInt8Value;
/**
 0：None,
 1：Add,
 2：Delete,
 3：Edit,
 4：Clear,
 5：Syn
 */
@property UInt8Value * _Nonnull ItemOperate;
@property UInt32Value * _Nonnull ItemNum;
@property NSMutableArray<WhiteBoardItem *> * _Nonnull itemArr_WhiteBoardItem;
@end


/**
 白板数据回执
 */
@interface WhiteBoardData_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull Page;
@property UInt32Value * _Nonnull SentTime;
@property UInt32Value * _Nonnull MD5Length;
@property NSMutableArray<UInt8Value *> * _Nonnull md5_UInt8Value;
/**
 0：None,
 1：Add,
 2：Delete,
 3：Edit,
 4：Clear,
 5：Syn
 */
@property UInt8Value * _Nonnull ItemOperate;
@property UInt32Value * _Nonnull ItemNum;
@property NSMutableArray<WhiteBoardItem *> * _Nonnull itemArr_WhiteBoardItem;
@end

/**
 多页白板数据请求
 */
@interface GetWbDataByPage : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull Page;
@end



/**
 光标同步请求
 */
@interface CursorSync_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property UInt8Value * _Nonnull PencilType;
@property UInt32Value * _Nonnull X_Offset;
@property UInt32Value * _Nonnull Y_Offset;
@end


/**
 光标同步回执
 */
@interface CursorSync_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property UInt8Value * _Nonnull PencilType;
@property UInt32Value * _Nonnull X_Offset;
@property UInt32Value * _Nonnull Y_Offset;
@end

/**
 发送翻页同步协议
 */
@interface PageSync_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property UInt8Value * _Nonnull Type;
@property UInt16Value * _Nonnull TotalPage;
@property UInt16Value * _Nonnull CurrentPage;
@property StringValue * _Nonnull CurrentPageMD5;
@end


/**
 收到翻页同步协议
 */
@interface PageSync_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SentTime;
@property UInt8Value * _Nonnull Type;
@property UInt16Value * _Nonnull TotalPage;
@property UInt16Value * _Nonnull CurrentPage;
@property StringValue * _Nonnull CurrentPageMD5;
@end


@interface PageHistroyEntity : ISocketData
/**
 课件类型
 */
@property UInt8Value * _Nonnull Type;

/**
 总页码
 */
@property UInt16Value * _Nonnull TotalPage;

/**
 当前页码
 */
@property UInt16Value * _Nonnull CurrentPage;
@end
/**
 进入教室成功后客户端会收到该下发消息通知
 */
@interface PageHistroyNotify_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull ItemNum;
@property NSMutableArray<PageHistroyEntity *> * _Nonnull itemArr_PageHistroyEntity;
@end

/**
 变更文档页请求
 */
@interface PageChange_c2s : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 课件类型
 */
@property UInt8Value * _Nonnull Type;

/**
 总页码
 */
@property UInt16Value * _Nonnull TotalPage;

/**
 当前页码
 */
@property UInt16Value * _Nonnull CurrentPage;
@end


/**
 变更文档页回执
 */
@interface PageChange_s2c : ISocketData

/**
 
 */
@property UInt32Value * _Nonnull RspCode;

/**
 课程ID
 */
@property UInt64Value * _Nonnull CID;

/**
 课件类型
 */
@property UInt8Value * _Nonnull Type;

/**
 总页码
 */
@property UInt16Value * _Nonnull TotalPage;

/**
 当前页码
 */
@property UInt16Value * _Nonnull CurrentPage;
@end

/**
 变更文档页通知
 */
@interface PageChange_s2cNotify : ISocketData

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 课件类型
 */
@property UInt8Value * _Nonnull Type;

/**
 总页码
 */
@property UInt16Value * _Nonnull TotalPage;

/**
 当前页码
 */
@property UInt16Value * _Nonnull CurrentPage;
@end


/**
 强制用户退出教室请求
 */
@interface KickOutUserFromRoom_c2s : ISocketData

/**
 操作目标用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;
@property UInt32Value * _Nonnull reserved;
@end

/**
 强制用户退出教室回执
 */
@interface KickOutUserFromRoom_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 教室内打点数据上报请求
 */
@interface RoomPointUpLoad_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull Type;
@property UInt32Value * _Nonnull Data1;
@property UInt32Value * _Nonnull Data2;
@property UInt32Value * _Nonnull Data3;
@property UInt32Value * _Nonnull Data4;
@property StringValue * _Nonnull MoreData;
@end

/**
 小测试出题请求
 */
@interface PostQuestion_c2s : ISocketData
/**
 课程唯一标识
 */
@property UInt64Value * _Nonnull CID;

/**
 问题标识号：单课内唯一标识号，0表示结束测验
 */
@property UInt64Value * _Nonnull QuestionID;

/**
 类型：0-单选、1-多选
 */
@property UInt8Value * _Nonnull Type;

/**
 问题标题
 */
@property StringValue * _Nonnull Title;

/**
 问题内容
 */
@property StringValue * _Nonnull Content;

/**
 答案选项个数
 */
@property UInt32Value * _Nonnull OptionNum;

/**
 答案选项内容
 */
@property NSMutableArray<StringValue *> * _Nonnull items_StringValue;

/**
 正确答案个数
 */
@property UInt32Value * _Nonnull AnserNum;

/**
 正确答案编号
 */
@property NSMutableArray<UInt8Value *> * _Nonnull AnserItem_UInt8Value;

/**
 出题人的UID
 */
@property UInt64Value * _Nonnull UID;
@end

/**
 小测试出题回执
 */
@interface PostQuestion_s2c : ISocketData
/**
 课程唯一标识
 */
@property UInt64Value * _Nonnull CID;

/**
 问题标识号：单课内唯一标识号，0表示结束测验
 */
@property UInt64Value * _Nonnull QuestionID;

/**
 类型：0-单选、1-多选
 */
@property UInt8Value * _Nonnull Type;

/**
 问题标题
 */
@property StringValue * _Nonnull Title;

/**
 问题内容
 */
@property StringValue * _Nonnull Content;

/**
 答案选项个数
 */
@property UInt32Value * _Nonnull OptionNum;

/**
 答案选项内容
 */
@property NSMutableArray<StringValue *> * _Nonnull items_StringValue;

/**
 正确答案个数
 */
@property UInt32Value * _Nonnull AnserNum;

/**
 正确答案编号
 */
@property NSMutableArray<UInt8Value *> * _Nonnull AnserItem_UInt8Value;

/**
 出题人的UID
 */
@property UInt64Value * _Nonnull UID;
@end

/**
 小测试答题请求
 */
@interface AnswerQuestion_c2s : ISocketData
/**
 课程唯一标识
 */
@property UInt64Value * _Nonnull CID;

/**
 问题标识号
 */
@property UInt64Value * _Nonnull QuestionID;

/**
 出题人的UID，提交答案时：!=0表示提交给指定的UID；=0表示提交给教室内所有人
 */
@property UInt64Value * _Nonnull UID;

/**
 答案个数
 */
@property UInt32Value * _Nonnull AnserNum;

/**
 答案编号
 */
@property NSMutableArray<UInt8Value *> * _Nonnull itemArr_UInt8Value;
@end

/**
 小测试答题回执
 */
@interface AnswerQuestion_s2c : ISocketData
/**
 课程唯一标识
 */
@property UInt64Value * _Nonnull CID;

/**
 问题标识号
 */
@property UInt64Value * _Nonnull QuestionID;

/**
 出题人的UID，提交答案时：!=0表示提交给指定的UID；=0表示提交给教室内所有人
 */
@property UInt64Value * _Nonnull UID;

/**
 答案个数
 */
@property UInt32Value * _Nonnull AnserNum;

/**
 答案编号
 */
@property NSMutableArray<UInt8Value *> * _Nonnull itemArr_UInt8Value;
@end

/**
 设置客户端定时发送音视频质量统计数据的时间间隔请求
 */
@interface SetMediaDataUploadStep_c2s : ISocketData

/**
 客户端发送统计数据时间间隔（秒），0表示不上传统计数据
 */
@property UInt32Value * _Nonnull TimerInterval;
@end

/**
 设置客户端定时发送音视频质量统计数据的时间间隔回执
 */
@interface SetMediaDataUploadStep_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 获取客户端定时发送音视频质量统计数据的时间间隔请求
 */
@interface GetMediaDataUploadStep_c2s : ISocketData
@property UInt32Value * _Nonnull Reserved;
@end

/**
 获取客户端定时发送音视频质量统计数据的时间间隔回执
 */
@interface GetMediaDataUploadStep_s2c : ISocketData
@property UInt32Value * _Nonnull TimerInterval;
@property UInt32Value * _Nonnull Reserved;
@end


/**
 客户端定时发送音视频质量统计数据
 */
@interface UploadMediaDataInRoom_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
/**
 延时p2p
 */
@property UInt32Value * _Nonnull DelayP2P;

/**
 延时p2s
 */
@property UInt32Value * _Nonnull DelayP2S;

/**
 丢包
 */
@property UInt32Value * _Nonnull PacketLoss;

/**
 保留
 */
@property UInt32Value * _Nonnull Reserved;
/**
 保留
 */
@property StringValue * _Nonnull StrExt;
@end

/**
 修改用户权限请求
 */
@interface SetUserRight_c2s : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户权限
 第0位：能否文本发言，0-允许；1-禁止
 第1位：是否是付费用户，0-否；1-是
 第2位：是否是B2S付费用户，0-否；1-是
 第3位：用户是否隐身，0-否；1-是
 */
@property UInt32Value * _Nonnull Right;

/**
 保留
 */
@property UInt32Value * _Nonnull Reserved;
@end

/**
 修改用户权限回执
 */
@interface SetUserRight_s2c : ISocketData

/**
 返回码
 */
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户权限
 */
@property UInt32Value * _Nonnull Right;

/**
 保留
 */
@property UInt32Value * _Nonnull Reserved;
@end

/**
 用户权限发生变更通知
 */
@interface UserRightChange_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull UID;

/**
 用户权限
 */
@property UInt32Value * _Nonnull Right;

/**
 保留
 */
@property UInt32Value * _Nonnull Reserved;
@end

/**
 魔法表情请求
 */
@interface Magic_c2s : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Content;
@end

/**
 魔法表情回执
 */
@interface Magic_s2c : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 用户ID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Content;
@end

/**
 代课请求
 */
@interface Substitution_c2s : ISocketData
/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Msg;
@property UInt16Value * _Nonnull TargetUIDNum;

/**
 消息投递目标用户UID 数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull TargetIDArr_UInt64Value;
@end

/**
 代课响应
 */
@interface Substitution_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 代课通知
 */
@interface Substitution_s2cNotify : ISocketData

/**
 消息类型
 */
@property UInt8Value * _Nonnull Type;

/**
 消息内容
 */
@property StringValue * _Nonnull Msg;
@end

/**
 约课请求
 */
@interface ScheduleCourse_c2s : ISocketData

/**
 取消预约
 预约课程
 变更上课方式
 变更教材
 */
@property UInt8Value * _Nonnull Type;


@property UInt64Value * _Nonnull UID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull TID;
@property UInt64Value * _Nonnull BeginTime;
@property StringValue * _Nonnull CourseName;
@property StringValue * _Nonnull Other;
@property UInt8Value * _Nonnull CourseTool;
@end

/**
 约课响应
 */
@interface ScheduleCourse_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt8Value * _Nonnull Type;
@property UInt64Value * _Nonnull UID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull TID;
@property StringValue * _Nonnull Other;
@end

/**
 约课通知
 */
@interface ScheduleCourse_s2cNotify : ISocketData
@property UInt8Value * _Nonnull Type;
@property UInt64Value * _Nonnull UID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull TID;
@property UInt64Value * _Nonnull BeginTime;
@property StringValue * _Nonnull CourseName;
@property StringValue * _Nonnull Other;
@property UInt8Value * _Nonnull CourseTool;
@end

/**
 发送教室通用Notice请求
 */
@interface SendCurrentNotice_c2s : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 通知内容
 */
@property StringValue * _Nonnull Notice;

/**
 目标用户UID数量
 0-发给所有用户
 */
@property UInt16Value * _Nonnull TargetUIDNum;

/**
 目标用户UID
 */
@property NSMutableArray<UInt64Value *> * _Nonnull TargeUIDArr_UInt64Value;
@end

/**
 发送教室通用Notice响应
 */
@interface SendCurrentNotice_s2c : ISocketData

/**
 错误返回码
 */
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 通知内容
 */
@property StringValue * _Nonnull Notice;

/**
 目标用户UID数量
 0-发给所有用户
 */
@property UInt16Value * _Nonnull TargetUIDNum;

/**
 目标用户UID
 */
@property NSMutableArray<UInt64Value *> * _Nonnull TargeUIDArr_UInt64Value;
@end

/**
 发送教室通用Notice通知
 */
@interface CurrentNotice_s2cNotify : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 发送者UID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 通知内容
 */
@property StringValue * _Nonnull Notice;
@end

@interface StorageEntty1 : ISocketData
@property StringValue * _Nonnull Key;
@property StringValue * _Nonnull Value;
@end

/**
 添加教室通用Storage请求
 */
@interface AddCurrentStorage_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull ItemNum;
@property NSMutableArray<StorageEntty1 *> * _Nonnull items_StorageEntty1;
@end

/**
 添加教室通用Storage响应
 */
@interface AddCurrentStorage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull ItemNum;
@property NSMutableArray<StorageEntty1 *> * _Nonnull items_StorageEntty1;
@end

/**
 删除教室通用Storage请求
 */
@interface DeleteCurrentStorage_c2s : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 key数量
 0-删除所有key
 */
@property UInt16Value * _Nonnull KeyNum;

@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

/**
 删除教室通用Storage响应
 */
@interface DeleteCurrentStorage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 key数量
 0-删除所有key
 */
@property UInt16Value * _Nonnull KeyNum;

@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

/**
 获取教室通用Storage请求
 */
@interface GetCurrentStorage_c2s : ISocketData
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 key数量
 0-获取所有key
 */
@property UInt16Value * _Nonnull KeyNum;

@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

@interface StorageEntity2 : ISocketData
@property StringValue * _Nonnull Key;
@property StringValue * _Nonnull Value;

/**
 key所有者UID
 */
@property UInt64Value * _Nonnull OwnerUID;
@end

/**
 获取教室通用Storage响应
 */
@interface GetCurrentStorage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

@property UInt16Value * _Nonnull ItemNum;

@property NSMutableArray<StorageEntity2 *> * _Nonnull itemArr_StorageEntity2;
@end

/**
 下发教室ConsistentStorage通知
 */
@interface ConsistentStorage_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
/**
 0-syn
 1-add
 2-del
 */
@property UInt8Value * _Nonnull Operate;
@property UInt16Value * _Nonnull ItemNum;
@property NSMutableArray<StorageEntity2 *> * _Nonnull itemArr_StorageEntity2;
@end


/**
 添加教室通用ConsistentStorage请求
 */
@interface AddCurrentConsistentStorage_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull ItemNum;
@property NSMutableArray<StorageEntty1 *> * _Nonnull itemArr_StorageEntty1;
@end

/**
 添加教室通用ConsistentStorage响应
 */
@interface AddCurrentConsistentStorage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull ItemNum;
@property NSMutableArray<StorageEntty1 *> * _Nonnull itemArr_StorageEntty1;
@end

/**
 删除教室通用ConsistentStorage请求
 */
@interface DeleteCurrentConsistentStorage_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
/**
 key数量
 0-删除所有key
 */
@property UInt16Value * _Nonnull KeyNum;
@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

/**
 删除教室通用ConsistentStorage响应
 */
@interface DeleteCurrentConsistentStorage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull KeyNum;
@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

/**
 获取教室通用ConsistentStorage请求
 */
@interface GetCurrentConsistentStorage_c2s : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 key数量
 0-获取所有key
 */
@property UInt16Value * _Nonnull KeyNum;
@property NSMutableArray<StringValue *> * _Nonnull keyArr_StringValue;
@end

/**
 获取教室（公开课、小班课等）使用的AV SDK请求
 */
@interface ClassMatchedSDK_c2s : ISocketData

/**
 教室类型
 1-公开课
 2-小班课
 3-
 */
@property UInt8Value * _Nonnull ClassType;
@end

/**
 获取教室（公开课、小班课等）使用的AV SDK响应
 */
@interface ClassMatchedSDK_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
/**
 教室类型
 */
@property UInt8Value * _Nonnull ClassType;

/**
 使用的AV SDK
 */
@property UInt8Value * _Nonnull AVSDK;
@end

/**
 请求变更AV SDK列表请求
 */
@interface ConfirmAVSDKList_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull OkSDK;
@property UInt32Value * _Nonnull SDKNum;

/**
 1-YY1；2-YY2；3：QQ
 */
@property NSMutableArray<UInt8Value *> * _Nonnull VecSDKArr_UInt8Value;
@end

/**
 请求变更AV SDK列表响应
 */
@interface ConfirmAVSDKList_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@end


/**
 变更AV SDK列表通知
 */
@interface SDKListChange_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property UInt8Value * _Nonnull OkSDK;
@property UInt32Value * _Nonnull SDKNum;
@property NSMutableArray<UInt8Value *> * _Nonnull VecSDKArr_UInt8Value;
@end


/**
 请求切换sdk
 */
@interface ReqChangeAVSDK_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull SDKID;
@property UInt8Value * _Nonnull Req;
@end


/**
 收到请求切换sdk的通知
 */
@interface ReqChangeAVSDK_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property UInt8Value * _Nonnull SDKID;
@property UInt8Value * _Nonnull Req;
@end

/**
 应答切换sdk
 */
@interface RspChangeAVSDK_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull SDKID;
@property UInt8Value * _Nonnull Rsp;
@end

/**
 收到应答切换sdk的通知
 */
@interface ResChangeAVSDK_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property UInt8Value * _Nonnull SDKID;
@property UInt8Value * _Nonnull Rsp;
@end

/**
 获取当前教室正在使用的sdk请求
 */
@interface GetCurrentSDK_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@end

/**
 获取当前教室正在使用的sdk响应
 */
@interface GetCurrentSDK_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull SDKID;
@end

/**
 请求变更AV SDK列表请求
 */
@interface RequestChangeSDKList_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull OkSDK;
@property UInt32Value * _Nonnull SDKNum;
@property NSMutableArray<UInt8Value *> * _Nonnull VecSDKArr_UInt8Value;
@end

/**
 请求变更AV SDK列表响应
 */
@interface RequestChangeSDKList_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@end




/**
 请求变更AV SDK列表2请求
 */
@interface RequestChangeSDKList2_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull SDKNum;
@property NSMutableArray<UInt8Value *> * _Nonnull VecSDKArr_UInt8Value;
@end

/**
 请求变更AV SDK列表2响应
 */
@interface RequestChangeSDKList2_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@end



/**
 变更AV SDK列表通知2
 */
@interface SDKListChange2_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property UInt8Value * _Nonnull SDKNum;
@property NSMutableArray<UInt8Value *> * _Nonnull VecSDKArr_UInt8Value;
@end


/**
 举手请求
 */
@interface HandUp_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull UID;
/**
 操作类型：
 0:none
 1:add
 2:delete
 3:clear(清空，UID 不起作用)
 */
@property UInt16Value * _Nonnull OpType;  //1
@end

/**
 举手响应
 */
@interface HandUp_s2c : ISocketData

/**
 返回码
 0x00000000：成功
 0x00100030：排麦人数已超过上限
 0xFFFFFFFF：错误
 */
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@end

/**
 放手请求
 */
@interface HandDown_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull UID;
/**
 操作类型：
 0:none
 1:add
 2:delete
 3:clear(清空，UID 不起作用)
 */
@property UInt16Value * _Nonnull OpType;  // 2
@end

/**
 放手响应
 */
@interface HandDown_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@end

/**
 举手列表同步
 */
@interface HandListChangeNotify_s2c : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt32Value * _Nonnull HandUserNum;
@property NSMutableArray<UInt64Value *> * _Nonnull userIdArr_UInt64Value;
@end




/**
 设置发言列表请求
 */
@interface SetHandList_c2s : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 1：举手，添加到发言队列最尾
 2：放手，从发言队列移除
 3：点名，添加到发言队列最前
 4：从发言队列移除
 */
@property UInt8Value * _Nonnull OpType;
@property UInt64Value * _Nonnull TargetUID;
@end

/**
 设置发言列表响应
 */
@interface SetHandList_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;

/**
 1：举手，添加到发言队列最尾
 2：放手，从发言队列移除
 3：点名，添加到发言队列最前
 4：从发言队列移除
 */
@property UInt8Value * _Nonnull OpType;
@property UInt64Value * _Nonnull TargetUID;
@end

/**
 发言列表变更通知
 */
@interface HandListChange_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 0：同步发言列表（进入教室完成后下发该通知）
 1：举手，添加到发言队列最尾
 2：放手，从发言队列移除
 3：点名，添加到发言队列最前
 4：从发言队列移除
 */
@property UInt8Value * _Nonnull OpType;

/**
 操作目标用户ID
 */
@property UInt64Value * _Nonnull TargetUID;

/**
 允许当前在发言的人数，队列前N个用户可以发言
 */
@property UInt16Value * _Nonnull AllowSpeakNum;

/**
 发言列表人数
 */
@property UInt32Value * _Nonnull LineUserNum;
@property NSMutableArray<UInt64Value *> * _Nonnull userIdArr_UInt64Value;
@end


/**
 上报智能感知用户设备变化请求
 */
@interface UploadDeviceStatusChanged_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property StringValue * _Nonnull DeviceStatus;
@end

/**
 上报智能感知用户设备变化响应
 */
@interface UploadDeviceStatusChanged_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

/**
 智能感知通知
 */
@interface DeviceStatus_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 用户个数
 */
@property UInt16Value * _Nonnull DeviceNum;

/**
 用户设备状态信息数组
 */
@property NSMutableArray<StringValue *> * _Nonnull VecDeviceStatusArr_StringValue;

/**
 通知标示（1-第一次下发通知；2-非第一次通知）
 */
@property UInt8Value * _Nonnull InitFlag;
@end

/**
 获取1v1进出教室时间记录请求
 */
@interface Get1v1Record_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@end


@interface RecordEntity : ISocketData

/**
 类型 0:进入教室 1：退出教室
 */
@property UInt8Value * _Nonnull EnterType;

/**
 时间
 */
@property UInt64Value * _Nonnull Time;
@end

@interface UserRecordEntity : ISocketData
@property UInt64Value * _Nonnull UID;
@property UInt8Value * _Nonnull Identtity;
@property StringValue * _Nonnull UserName;
@property UInt32Value * _Nonnull RecordNum;
@property NSMutableArray<RecordEntity *> * _Nonnull arr_RecordEntity;
@end
/**
 1v1进出教室时间记录通知
 */
@interface OneToOneRecord_s2cNotify : ISocketData

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 教室人数
 */
@property UInt32Value * _Nonnull UserNum;

/**
 用户进出教室信息数组
 */
@property NSMutableArray<UserRecordEntity *> * _Nonnull arr_UserRecordEntity;
@end

/**
 更换教材请求
 */
@interface ReqChangeMaterial_c2s : ISocketData
@property UInt64Value * _Nonnull CID;

/**
 教材信息
 */
@property StringValue * _Nonnull TextbookData;
@end

/**
 更换教材响应
 */
@interface ReqChangeMaterial_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull UID;
@end

/**
 更换教材确认
 */
@interface MaterialChangeOk_c2s : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@end

/**
 更换教材通知
 */
@interface MaterialChange_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property StringValue * _Nonnull TextbookData;
@end

/**
 发送教材相关的通用通知请求
 */
@interface SendMaterialCurrentNotice_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
/**
 通知类型
 */
@property UInt8Value * _Nonnull Type;

/**
 通知内容
 */
@property StringValue * _Nonnull NotifyData;
@end

/**
 发送教材相关的通用通知响应
 */
@interface SendMaterialCurrentNotice_s2c : ISocketData

/**
 返回码
 */
@property UInt32Value * _Nonnull RspCode;

/**
 教室ID
 */
@property UInt64Value * _Nonnull CID;

/**
 通知类型
 */
@property UInt8Value * _Nonnull Type;

/**
 通知内容
 */
@property StringValue * _Nonnull NotifyData;
@end


/**
 收到教材相关的通用通知
 */
@interface ReciveMaterialCurrentNotice_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull SourceUID;
@property UInt8Value * _Nonnull Type;
@property StringValue * _Nonnull NotifyData;
@end

/**
 设置教材的通用设置
 */
@interface SetMaterial_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property StringValue * _Nonnull Setting;
@end

/**
 设置教材的通用设置
 */
@interface SetMaterial_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property StringValue * _Nonnull Setting;
@end


/**
 下发教材的通用设置通知
 */
@interface SetMaterial_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property StringValue * _Nonnull Setting;
@end


/**
 设置教材的当前页码请求
 */
@interface SetPDFPage_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull CurPage;
@property StringValue * _Nonnull Reserved;
@end

/**
 设置教材的当前页码响应
 */
@interface SetPDFPage_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull CurPage;
@property StringValue * _Nonnull Reserved;
@end


/**
 教材的当前页码变更通知
 */
@interface SetPDFPage_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull CurPage;
@property StringValue * _Nonnull Reserved;
@end

/**
 设置教材当前页的滚动条位置请求
 */
@interface SetScrollPosition_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;
@property StringValue * _Nonnull PosX;
@property StringValue * _Nonnull PosY;
@end

/**
 设置教材当前页的滚动条位置响应
 */
@interface SetScrollPosition_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;
@property StringValue * _Nonnull PosX;
@property StringValue * _Nonnull PosY;
@end


/**
 教材当前页的滚动条位置变更通知
 */
@interface SetScrollPosition_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;
@property StringValue * _Nonnull PosX;
@property StringValue * _Nonnull PosY;
@end


@interface OpDataEntity : ISocketData

/**
 操作数据编号
 */
@property UInt32Value * _Nonnull ServerSeq;

/**
 操作数据生产者UID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 操作数据字符串数据
 */
@property StringValue * _Nonnull OpStrData;

/**
 操作数据字节数据长度
 */
@property UInt16Value * _Nonnull OpByteDataLen;

/**
 操作数据字节数据
 */
@property NSMutableArray<UInt8Value *> * _Nonnull OpByteDataArr_UInt8Value;
@end
/**
 下发教材操作数据通知通知
 */
@interface MaterialData_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 1：Add
 2：Delete
 3：Edit
 4：Clear
 5：Syn
 */
@property UInt8Value * _Nonnull Operate;

@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<OpDataEntity *> * _Nonnull dataArr_OpDataEntity;
@end

/**
 获取教材指定页的操作数据请求
 */
@interface GetMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;
/**
 起始操作数据序号（暂时填0）
 */
@property UInt32Value * _Nonnull BeginSeq;
@end


@interface MaterialDataEntity : ISocketData

/**
 客户端本地操作数据编号
 */
@property UInt32Value * _Nonnull ClientSeq;

/**
 操作数据字符串数据
 */
@property StringValue * _Nonnull OpStrData;

/**
 操作数据字节数据长度
 */
@property UInt16Value * _Nonnull OpByteDataLen;

/**
 操作数据字节数据
 */
@property NSMutableArray<UInt8Value *> * _Nonnull arr_UInt8Value;
@end

/**
 添加教材数据请求
 */
@interface AddMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity *> * _Nonnull arr_MaterialDataEntity;
@end

@interface MaterialDataEntity1 : ISocketData

/**
 操作数据编号
 */
@property UInt32Value * _Nonnull ServerSeq;

/**
 客户端本地操作数据编号
 */
@property UInt32Value * _Nonnull ClientSeq;

/**
 操作数据字符串数据
 */
@property StringValue * _Nonnull OpStrData;

/**
 操作数据字节数据长度
 */
@property UInt16Value * _Nonnull OpByteDataLen;

/**
 操作数据字节数据
 */
@property NSMutableArray<UInt8Value *> * _Nonnull OpByteDataArr_UInt8Value;

@end

/**
 添加教材数据响应
 */
@interface AddMaterialData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity1 *> * _Nonnull dataArr_MaterialDataEntity1;
@end


@interface MaterialDataEntity2 : ISocketData
/**
 客户端本地操作数据编号
 */
@property UInt32Value * _Nonnull ServerSeq;

/**
 操作数据字符串数据
 */
@property StringValue * _Nonnull OpStrData;

/**
 操作数据字节数据长度
 */
@property UInt16Value * _Nonnull OpByteDataLen;

/**
 操作数据字节数据
 */
@property NSMutableArray<UInt8Value *> * _Nonnull OpByteData_UInt8Value;
@end
/**
 编辑教材数据请求
 */
@interface EditMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<MaterialDataEntity2 *> * _Nonnull dataArr_MaterialDataEntity2;
@end

/**
 编辑教材数据响应
 */
@interface EditMaterialData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity1 *> * _Nonnull dataArr_MaterialDataEntity1;
@end


/**
 删除教材数据请求
 */
@interface DeleteMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<UInt32Value *> * _Nonnull arr_UInt32Value;
@end

/**
 删除教材数据响应
 */
@interface DeleteMaterialData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<UInt32Value *> * _Nonnull arr_UInt32Value;
@end


/**
 清除教材数据请求
 */
@interface ClearMaterialData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@end

/**
 清除教材数据响应
 */
@interface ClearMaterialData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@end


@interface BookDataEntity : ISocketData

/**
 图形编号
 */
@property UInt32Value * _Nonnull ServerSeq;

/**
 图形生产者UID
 */
@property UInt64Value * _Nonnull SourceUID;

/**
 图形字符串数据
 */
@property StringValue * _Nonnull GraphicStrData;

/**
 图形字节数据长度
 */
@property UInt16Value * _Nonnull GraphicByteDataLen;

/**
 具体数据
 */
@property NSMutableArray<UInt8Value *> * _Nonnull arr_UInt8Value;
@end
/**
 下发教材板书数据通知
 */
@interface MaterialBookData_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
/**
 1：Add
 2：Delete
 3：Edit
 4：Clear
 5：Syn
 */
@property UInt8Value * _Nonnull Operate;
@property UInt16Value * _Nonnull GraphicNum;

@property NSMutableArray<BookDataEntity *> * _Nonnull dataArr_BookDataEntity;
@end

/**
 添加教材板书数据请求
 */
@interface GetMaterialBookData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@property UInt32Value * _Nonnull BeginSeq;
@end

/**
 添加教材板书数据请求
 */
@interface AddMaterialBookData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity *> * _Nonnull arr_MaterialDataEntity;
@end

/**
 添加教材板书数据响应
 */
@interface AddMaterialBookData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity1 *> * _Nonnull dataArr_MaterialDataEntity1;
@end

/**
 编辑教材板书数据请求
 */
@interface EditMaterialBookData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<MaterialDataEntity2 *> * _Nonnull dataArr_MaterialDataEntity2;
@end

/**
 编辑教材板书数据响应
 */
@interface EditMaterialBookData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
/**
 页码
 */
@property UInt16Value * _Nonnull Page;

/**
 操作数据数量
 */
@property UInt16Value * _Nonnull OpDataNum;

@property NSMutableArray<MaterialDataEntity1 *> * _Nonnull dataArr_MaterialDataEntity1;
@end


/**
 删除教材板书数据请求
 */
@interface DeleteMaterialBookData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<UInt32Value *> * _Nonnull arr_UInt32Value;
@end

/**
 删除教材板书数据响应
 */
@interface DeleteMaterialBookData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@property UInt16Value * _Nonnull OpDataNum;
@property NSMutableArray<UInt32Value *> * _Nonnull arr_UInt32Value;
@end


/**
 清除教材板书数据请求
 */
@interface ClearMaterialBookData_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@end

/**
 清除教材板书数据响应
 */
@interface ClearMaterialBookData_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;
@property UInt16Value * _Nonnull TextbookID;
@property UInt8Value * _Nonnull TextbookType;
@property UInt16Value * _Nonnull Page;
@end

/**
 获取画笔颜色请求
 */
@interface GetPenColor_c2s : ISocketData
@property UInt64Value * _Nonnull CID;
@end

/**
 获取画笔颜色响应
 */
@interface GetPenColor_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@property UInt64Value * _Nonnull CID;

/**
 颜色值
 */
@property UInt32Value * _Nonnull PenColor;
@end

/**
 万人教室在线人数通知
 */
@interface MillionClassroomsOnlineUsers_s2cNotify : ISocketData
@property UInt64Value * _Nonnull CID;
@property UInt32Value * _Nonnull UserNum;
@end

/**
 约课通知2
 */
@interface ScheduleCourse2_s2cNotify : ISocketData
@property UInt8Value * _Nonnull Type;
@property UInt64Value * _Nonnull UID;
@property UInt64Value * _Nonnull CID;
@property UInt64Value * _Nonnull TID;
@property UInt64Value * _Nonnull BeginTime;
@property StringValue * _Nonnull CourseName;
@property StringValue * _Nonnull Other;
@property UInt8Value * _Nonnull CourseTool;
@end

/**
 上报客户端统计信息
 */
@interface UploadClientStatistics_c2s : ISocketData
@property UInt16Value * _Nonnull MID;
@property UInt64Value * _Nonnull UID;
@property UInt64Value * _Nonnull CID;
@property UInt8Value * _Nonnull SDK;
@property UInt32Value * _Nonnull stringKvsNum;
@property NSMutableArray<StatisticsString *> * _Nonnull stringKvs_StatisticsString;
@property UInt32Value * _Nonnull intKvsNum;
@property NSMutableArray<StatisticsInt *> * _Nonnull intKvs_StatisticsInt;
@property UInt32Value * _Nonnull objKvsNum;
@property NSMutableArray<StatisticsObj *> * _Nonnull objKvs_StatisticsObj;
@end


@interface UploadClientStatistics_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end


@interface PushUploadLog_c2s : ISocketData
/**
 0：ACdoctor上报日志
 */
@property UInt8Value * _Nonnull Type;
@property UInt32Value * _Nonnull UserIDNum;
@property NSMutableArray<UInt64Value *> * _Nonnull uidArr_UInt64Value;
/**
 UTF8-JSON
 */
@property StringValue * _Nonnull OpParam;
@end

@interface PushUploadLog_s2c : ISocketData
@property UInt32Value * _Nonnull RspCode;
@end

@interface PushUploadLog_s2cNotify : ISocketData
/**
 0：ACdoctor上报日志
 */
@property UInt8Value * _Nonnull Type;

/**
 UTF8-JSON
 */
@property StringValue * _Nonnull OpParam;
@end
/**
 课中用户实体
 */
@interface ClassRoomUserEntity : CustomEntity
/**
 用户的mediaID，这个字段现在不用了，mediaID由程序内部自己算
 */
@property UInt32Value * _Nonnull MediaID;

/**
 用户自定义数据
 */
@property StringValue * _Nonnull UserCusData;

/**
 进or出教室时间
 */
@property UInt64Value * _Nonnull Time;
@end

@interface CurrentPushNotifyItem : ISocketData
/**
 自增的消息序号
 */
@property UInt64Value * _Nonnull MsgSeq;

/**
 消息类型
 1-    通用用户push消息
 2-    用户课表变更通知
 3-    课程信息变更通知
 4-    课程教材变更通知
 */
@property UInt16Value * _Nonnull MsgType;

/**
 保留字段1
 */
@property UInt16Value * _Nonnull ResUint16;

/**
 保留字段2
 */
@property UInt32Value * _Nonnull ResUint32;

/**
 信息有效开始时间
 */
@property UInt64Value * _Nonnull BeginTime;

/**
 信息有效结束时间
 */
@property UInt64Value * _Nonnull EndTime;

/**
 消息内容JSON字符串,如果MsgType == 2，则Content的格式为
 {
 "type":1,
 "uid":2,
 "cid":3,
 "tid":4,
 "beg_tm":5,
 "course_name":"abc",
 "course_tool":1,
 "other":""
 }
 */
@property StringValue * _Nonnull Content;

/**
 扩展字段，预留
 */
@property StringValue * _Nonnull Ext;
@end
/**
 服务器下发通用推送通知
 */
@interface CurrentPushNotify_s2cNofify : ISocketData

/**服务端是否还有其他的客户端未接受的消息*/
@property UInt8Value * _Nonnull HasMoreMsg;

/**
 消息数量
 */
@property UInt8Value * _Nonnull MsgNum;

/**
 消息体集合
 */
@property NSMutableArray<CurrentPushNotifyItem *>* _Nonnull itemArr_CurrentPushNotifyItem;

/**
 预留
 */
@property StringValue * _Nonnull Reserved;
@end

/**
 请求更多的推送通知
 */
@interface ReqMorePushNotify_c2s : ISocketData
@end

/**
 向服务器上报已经处理过的推送通知信息
 */
@interface UploadPushNotifyExecResult_c2s : ISocketData
/**
 消息数量
 */
@property UInt8Value * _Nonnull MsgNum;

/**
 消息ID数组
 */
@property NSMutableArray<UInt64Value *> * _Nonnull MsgSeqArr_UInt64Value;
@end

@interface UserAVCtrlItem : ISocketData
/** 用户ID
 */
@property UInt64Value * _Nonnull uid;
/** 1：音频模式 2：小视频模式 3：大视频模式
 */
@property UInt8Value * _Nonnull mode;
/** 0-关闭；1-开启 第0位：语音 第1位：Camera视频
 */
@property UInt8Value * _Nonnull avState;
/** 视频窗口X坐标
 */
@property UInt16Value * _Nonnull posX;
/** 视频窗口Y坐标
 */
@property UInt16Value * _Nonnull posY;
/** 视频窗口参照背景区域大小宽度
 */
@property UInt16Value * _Nonnull width;
/** 视频窗口参照背景区域大小高度
 */
@property UInt16Value * _Nonnull height;
/** 保留字段
 */
@property UInt16Value * _Nonnull reserved;

@end

/**
 用户音视频控制列表变更通知
 */
@interface UserAVCtrlListNotify_s2c : ISocketData
/** 教室ID
 */
@property UInt64Value * _Nonnull cid;
/** 教室ID
 */
@property UInt64Value * _Nonnull source_uid;
/** 用户音视频控制列表版本号，从1开始递增
 */
@property UInt32Value * _Nonnull version;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;
/** 视频控制列表
 */
@property NSMutableArray<UserAVCtrlItem *> * _Nonnull itemArr_UserAVCtrlItem;

@end

/**
 请求用户音视频控制列表（客户端定时请求服务端)
 */
@interface ReqUserAVCtrlList_c2s : ISocketData

/** 教室ID
 */
@property UInt64Value * _Nonnull cid;
/** 用户音视频控制列表版本号，从1开始递增
 */
@property UInt32Value * _Nonnull version;

@end


/**
 重置用户音视频控制列表
 */
@interface ResetUserAVCtrlListReq_c2s : ISocketData

/** 教室ID
 */
@property UInt64Value * _Nonnull cid;

@end

/**
 重置用户音视频控制列表 响应
 */
@interface ResetUserAVCtrlListRsp_s2c : ISocketData

/**
 返回码
 0x00000000-成功
 */
@property UInt32Value * _Nonnull rspCode;
/** 教室id
 */
@property UInt64Value * _Nonnull cid;

@end

/**
 修改用户的音视频模式
 */
@interface ChangeUserAVModeReq_c2s : ISocketData
/** 教室ID
 */
@property UInt64Value * _Nonnull cid;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;
/** 视频控制列表
 */
@property NSMutableArray<UserAVCtrlItem *> * _Nonnull itemArr_UserAVCtrlItem;
@end


/**
 修改用户的音视频模式 响应
 */
@interface ChangeUserAVModeRsp_s2c : ISocketData
/**
 返回码
 0x00000000-成功
 */
@property UInt32Value * _Nonnull rspCode;
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;

@property NSMutableArray<UInt64Value *> * _Nonnull uidArr_UInt64Value;
@end

/**
 用户授权控制列表变更通知数组对象
 */
@interface UserAuthListItem : ISocketData

/**
 用户ID
 */
@property UInt64Value * _Nonnull uid;

/**
 0-关闭；1-开启
 第0位：白板开关
 */
@property UInt16Value * _Nonnull switchState;

@end

/**
 用户授权控制列表变更通知
 */
@interface UserAuthListNotify_s2c : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/** 用户授权控制列表版本号，从1开始递增
 */
@property UInt32Value * _Nonnull version;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;
/**
 用户授权控制列表
 */
@property NSMutableArray<UserAuthListItem *> * _Nonnull itemArr_UserAuthListItem;

@end

/**
请求用户授权控制列表（客户端定时请求服务端）
 */
@interface ReqUserAuthList_c2s : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/** 用户授权控制列表版本号，从1开始递增
 */
@property UInt32Value * _Nonnull version;
@end

/**
 重置用户授权控制列表
 */
@interface ResetUserAuthListReq_c2s : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
@end

@interface ResetUserAuthListRsp_s2c : ISocketData

/**
 返回码
 0x00000000-成功
 */
@property UInt32Value * _Nonnull rspCode;
/** 教室id
 */
@property UInt64Value * _Nonnull cid;

@end

/**
 修改用户的授权
 */
@interface ChangeUserAuthReq_c2s : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;
/**
 修改用户的授权列表
 */
@property NSMutableArray<UserAuthListItem *> * _Nonnull itemArr_UserAuthListItem;

@end
/**
 修改用户的授权响应
 */
@interface ChangeUserAuthRsp_s2c : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/** 用户数量
 */
@property UInt16Value * _Nonnull userNum;

@property NSMutableArray<UInt64Value *> * _Nonnull uidArr_UInt64Value;

@end


@interface ChatMsgItem : ISocketData

/**用户ID
 */
@property UInt64Value * _Nonnull UID;
/**发送时间
 */
@property UInt64Value * _Nonnull sentTime;

@property StringValue * _Nonnull pption;
/**内容
 */
@property StringValue  * _Nonnull text;


@end

@interface ChatOfflineMsgNotify_s2c : ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/**
 消息数量
 */
@property UInt32Value * _Nonnull MsgCount;
/**消息数组
 */
@property NSMutableArray<ChatMsgItem *> * _Nonnull msgArr_ChatMsgItem;

@end

@interface SVC_ClassRoomSendPoint_S2C: ISocketData
/** 教室id
 */
@property UInt64Value * _Nonnull cid;
/**
 消息数量
 */
@property UInt8Value * _Nonnull stype;
@end
