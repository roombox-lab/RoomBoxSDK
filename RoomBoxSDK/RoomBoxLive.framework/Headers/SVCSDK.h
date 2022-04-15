//  svc服务SDK的主入口
//  SVCSDK.h
//  51TalkAC
//
//  Created by guominglong on 2018/1/23.
//  Copyright © 2018年 51talk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SVCDefine.h"
#import "SVCModels.h"
#import "ISocketData.h"
//#import "GPBProtocolBuffers.h"
#import <Protobuf/GPBProtocolBuffers.h>


#define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 1

@interface SVCSDK : NSObject
{
    int currentLbsIdx;//当前正在尝试的lbs地址索引
    int currentAccIdx;//当前正在尝试的acc地址索引
    NSThread * sdkThread;//sdk运行的独立线程
    enum SvcConnectState _svcConnectState;
}

#pragma mark - vars define
/**
 svc uid
 */
@property (nonatomic, assign) uint64_t loginUid;

/**
 重连lbs用的计时器
 */
@property (nonatomic,strong) NSTimer * lbsTimer;

/**
 重连lbs用的计时器时间间隔
 */
@property (nonatomic,assign) NSTimeInterval lbsTimerInterval;

/**
 心跳计时器
 */
@property (nonatomic,strong) NSTimer * heartbeatTimer;

@property (nonatomic,strong) SVC_Config * config;
@property (nonatomic,assign,getter=getSvcConnectState,setter=setSvcConnectState:)enum SvcConnectState svcConnectState;

@property (nonatomic, assign) double serviceTimeDiffer;

#pragma mark - methods define
/**
 单例
 */
+(SVCSDK *)instance;

-(void)startNetThead;

-(void)closeNetThead;

-(void)setSvcConnectState:(enum SvcConnectState)state;
/**
 svc连接状态
 */
-(enum SvcConnectState)getSvcConnectState;


-(void)socketError:(NSNotification *)notify;
-(void)socketConnected:(NSNotification *)notify;
-(void)socketDisconnect:(NSNotification *)notify;
/**
 收到了一个数据包
 */
-(void)recivedPack:(NSNotification *)notify;

/**
 启动心跳
 */
-(void)startHeartbeat:(NSTimeInterval)timeStep;
/**
 心跳的具体执行函数
 */
-(void)heartBeatFun;

/**
 客户端接入
 */
-(void)clientIn;





@end



#pragma mark - 外部业务层用到的对公methods define
@interface SVCSDK(PublicMethod)

/**
 初始化sdk
 @param _config 初始化sdk需要的配置文件
 */
-(void)initSDK:(SVC_Config *)_config;


/**
 svc登录
 */
-(void)login:(uint64_t)uid;

/**
 登出
 */

-(void)loginOut;

/**
 向Acc（即svc）服务器发送协议包
 */
-(void)sendCurrentDataToAcc:(ISocketData *)reqData cmd:(uint32_t)_pkgcmd;

//新白板协议
-(void)sendCurrentDataToAcc:(NSData *)reqData exHeader:(NSData *)header commandid:(uint32_t)cmdid;
//新白板协议
- (void)sendCurrentDataToAcc:(NSData *)reqData exHeader:(NSData *)header commandid:(uint32_t)cmdid sequence:(uint32_t)seq roomid:(uint64_t)cid;

/**
 重连lbs
 */
-(void)reLinkLBS;

/*
 * 获取当前登入的Uid
 */
-(uint64_t)getLoginId;

@end
