#ifndef GNetPropertiesDefine_h
#define GNetPropertiesDefine_h

//=========================属性名称定义=================================
//1. meeting
#define kPROP_CONF_STATUS                         @"status"       //unintVar
#define kPROP_CONF_LOCKED                         @"locked"       //unintVar
#define kPROP_CONF_TITLE                          @"title"        //strVar
#define kPROP_CONF_MEETINGREADY                   @"meetingReady" //boolVar
#define kPROP_CONF_STOPREASON                     @"stopReason"
#define kPROP_CONF_NETWORKSTATUS                  @"networkStatus"
#define kPROP_CONF_NETWORKTYPE                    @"networkType"
#define kPROP_CONF_NETWORKQUALITY                 @"networkQuality"
#define kPROP_CONF_RECORDING                      @"recording"        //boolVar
#define kPROP_CONF_STARTRECORDTIME                @"startRecordTime"  //unintVar
#define kPROP_CONF_ENDECORDTIME                   @"endRecordTime"    //unintVar
#define kPROP_CONF_TOTALECORDTIME                 @"totalRecordTime"  //unintVar
#define kPROP_CONF_RECORDPASSWORD                 @"recordPassword"   //strVar
#define kPROP_CONF_USERS                          @"users"            //
#define kPROP_CONF_CANUSEH264DESTOP               @"canUseH264Destop" //boolVar

//2.user
#define kPROP_USER_INDEX                          @"index"    //unintVar
#define kPROP_USER_TYPE                           @"type"     //unintVar
#define kPROP_USER_CLIENTTYPE                     @"clientType" //unintVar
#define kPROP_USER_UMSUSERID                      @"umsUserID"  //unintVar
#define kPROP_USER_USERNAME                       @"userName"   //strVar
#define kPROP_USER_EMAIL                          @"email"      //strVar
#define kPROP_USER_MOBILE                         @"mobile"     //strVar
#define kPROP_USER_STATUS                         @"status"     //unintVar
#define kPROP_USER_ROLES                          @"roles"      //unintVar
#define kPROP_USER_POWER                          @"power"      //
#define kPROP_USER_ISSPEAKING                     @"isSpeaking" //boolVar
#define kPROP_USER_AUDIOSTATUS                    @"audioStatus"//unintVar
#define kPROP_USER_PHONENUM                       @"phoneNum"   //strVar
#define kPROP_USER_PHONECONNECT                   @"phoneConnect" //unintVar
#define kPROP_USER_VCARDLINE                      @"vcardLine"   //strVar
#define kPROP_USER_GROUPNAME                      @"groupName"   //strVar
#define kPROP_USER_ISDURING                       @"isDuring"
#define kPROP_USER_DEPARTMENT                     @"department"
#define kPROP_USER_JOBTITLE                       @"jobTitle"
#define kPROP_USER_INVAITTEID                     @"inviteeID"
#define kPROP_USER_DOMAIN                         @"domain"
#define kPROP_USER_CUSTOMSTR                      @"customStr"  //strVar
#define kPROP_USER_VERSION                        @"version"    //unintVar
#define kPROP_USER_BIND                           @"bind"       //unintVar
#define kPROP_USER_EARNUM                         @"earNum"     //unintVar
#define kPROP_USER_MICNUM                         @"micNum"     //unintVar
#define kPROP_USER_MUTESTATE                      @"muteState"  //unintVar
#define kPROP_USER_AUDIOSHARED                    @"audioShared"//boolVar
#define kPROP_USER_VIDEOS                         @"videos"     //NSarray<unintVar>
#define kPROP_USER_CAMERAS                        @"cameras"   //

//3.audio
#define kPROP_AUDIO_MUTEALL                       @"muteAll"            //boolVar
#define kPROP_AUDIO_MUTEOPERATOR                  @"muteOperator"       //strVar
#define kPROP_AUDIO_RECORDING                     @"recording"          //boolVar
#define kPROP_AUDIO_MUTEASSOCIATE                 @"muteAssociate"      //boolVar
#define kPROP_AUDIO_LOCKASSOCIATE                 @"lockAssociate"      //boolVar
#define kPROP_AUDIO_PHONERECORDING                @"phoneRecording"     //boolVar
#define kPROP_AUDIO_PHONELOCK                     @"phoneLock"          //boolVar

//4.video
#define kPROP_VIDEO_PROVIDER                       @"provider"          //unintVar
#define kPROP_VIDEO_DEVICEID                       @"deviceID"          //strVar
#define kPROP_VIDEO_CAMERA_STATUS                  @"status"            //unintVar
#define kPROP_VIDEO_CAMERA_ISSHARED                @"isShared"

//5.desktop
#define kPROP_DESKTOP_PROVIDER                     @"provider"          //unintVar
#define kPROP_DESKTOP_CONTROLLER                   @"controller"        //unintVar
#define kPROP_DESKTOP_TYPE                         @"type"              //unintVar
#define kPROP_DESKTOP_WIDTH                        @"width"             //unintVar
#define kPROP_DESKTOP_HEIGHT                       @"height"            //unintVar
#define kPROP_DESKTOP_COMMENT                      @"comment"



//=========================属性值定义=================================
//1. meeting

typedef enum
{
    status_disconnected = 1,
    status_connected = 2,
    status_started = 3,
    status_stoped = 4,
    status_connecting = 5,
    
    // 以下的状态需要用户退出用户重新入会
    status_user_error = 100, // 对应传输状态 402
    status_meeting_error = 200, // 对应传输状态 401
    
}MeetingStatus;

/**
 * @enum QuitReason
 * @brief 用户离开的原因
 */
typedef enum
{
    selfleft = 1,                    //!< 自己主动离开
    host_terminate_meeting = 2,        //!< 会议被结束
    host_kick_out = 3,                //!< 被踢出会议
    servers_stopped = 4,            //!< 服务器停止服务
    network_disconnect = 5,            //!< 网络断开
    too_many_users = 6                //!< 会议中用户已经满
}QSQuitReason;


//2.user
typedef enum
{
    client_pc_mac = 2,
    client_ios_android = 6,
    client_record = 7,
    client_other = 13,    //其他客户端 h323server
}QSClientType;

/**
 * @enum UserType
 * @brief 用户类型
 */
typedef enum
{
    user_data = 0,        //!< 数据用户
    user_phone = 1,        //!< 电话用户
}QSUserType;

typedef enum
{
    off_line = 0,
    on_line = 1,
    on_line_in_blacklist = 2,
    off_line_in_blacklist = 3,
    kick_out = 4,
    user_exit = 5,
    kick_out_by_server = 6, //被BMS踢出会议，在入会超方时，BMS会将该入会用户踢出
}QSUserStatus;

typedef enum
{
    status_none = 0,
    voip_unmute = 1,
    voip_mute_by_self = 2,
    voip_mute_by_host = 3,
    pstn_unmute = 4,
    pstn_mute_by_self = 5,
    pstn_mute_by_host = 6,
    pstn_calling = 7,
    pstn_corridor = 10,   //走廊模式
    voip_listen_only = 11 //没有耳麦，仅听会议内容，不能发言
}QSUserAudioStatus;

typedef enum
{
    guest = 1,            //!< 参会者
    presenter = 2,        //!< 主讲人
    host = 4,            //!< 主持人
}QSUserRoles;


//=========================
typedef enum{
    none = 0,             //!< 空
    video = 1,            //!< 视频流
    desktop = 2,          //!< 桌面流
    whiteboard = 3,       //!< 白板流
    audio = 4             //!< 音频流
}NSStreamType;

typedef enum {
    device_none = 0,            //!< 空值
    microphone = 1,        //!< 麦克风
    speaker = 2,        //!< 扬声器
    camera = 3,            //!< 摄像头
    dekstop = 4            //!< 桌面
}NSDeviceType;


//白板
typedef enum
{
    graffite    = 0x01,        //!< 随手绘制
    pointer        = 0x02,        //!< 激光笔
    iselect        = 0x03,        //!< 选择
    eraser        = 0x04,        //!< 擦除
}NSGraphicToolType;

typedef enum{
    myself = 1,
    others = 2,
    all    = 3
}NSClearType;

typedef enum{
    watchMode = 1,
    commentMode = 2,
}NSWhiteBoardHandleMode;

typedef enum{
    fill = 0x01,
    keep_radio_fill = 0x02,
    keep_radio_cut = 0x03,
    keep_actual = 0x04,
}NSStretchMode;

typedef enum{
    vpm_ok = 0,
    vpm_general_error = -1,
    vpm_memory = -2,
    vpm_parameter_error = -3,
    vpm_sale_error = -4,
    vpm_uninitialized = -5,
    
}NSStreamVPMResult;

typedef enum{
    
    videoType_preview = 0,//本地预览
    videoType_share,
    videoType_video,
    videoType_desktop,
    
}NSStopVideoType;

typedef NS_ENUM(NSUInteger, GNETClientType) {
    GNETClientType_Unkonw,
    GNETClientType_PC = 2,
    GNETClientType_Mobile = 6,
//    GNETGNETClientType_MCU = 13,
//    GNETClientType_BOX = 14,
    GNETClientType_MCU = 13,
    GNETClientType_BOX = 14,
    GNETClientTypeNew_MCU = 20 // 6.0 新增硬件设备类型(保持兼容，与 13 共存)

};

typedef NS_ENUM(NSUInteger, VideoResolutionType) {
    VideoResolutionType_Default,//默认
    VideoResolutionType_Min,//最小分辨率，仅适用于6路视频
};

#endif
