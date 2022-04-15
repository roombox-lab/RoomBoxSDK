//
//  RoomBoxIM.h
//  im-sdk-ios
//
//  Created by 赵亮 on 2021/6/10.
//

#import <Foundation/Foundation.h>
#import "RoomBoxIMMessage.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    IMConnectUnknow = 0,
    IMConnectting,
    IMConnectFailed,
    IMConnectRetry,
    IMConnectSuccess,
    IMConnectKickout
}IMConnectStatus;

typedef enum {
    IMLoginning = 0,
    IMLoginSuccess,
    IMLoginOut,
    IMLoginFailed
} IMLoginStatus;


typedef enum {
    Test = 0,
    Release = 1
}RoomBoxIMEnviroment;


static const NSNotificationName RoomBoxIMInit = @"RoomBoxIMInit";

static const NSNotificationName RoomBoxIMConnectStatusChanged = @"RoomBoxIMConnectStatusChanged";

static const NSNotificationName RoomBoxIMConnectSuccess = @"RoomBoxIMConnectSuccess";

static const NSNotificationName RoomBoxIMConnectRetry = @"RoomBoxIMContectRetry";

static const NSNotificationName RoomBoxIMConnectFailed = @"RoomBoxIMConnectFailed";

static const NSNotificationName RoomBoxIMConnectKickOut = @"RoomBoxIMConnectKickOut";


@interface RoomBoxIM : NSObject

+ (RoomBoxIM *) shareInstance;

@property (nonatomic,assign) IMConnectStatus connectStatus;
@property (nonatomic,assign) IMLoginStatus loginStatus;
@property (nonatomic,assign) float delay; //连接延时
@property (nonatomic,assign) uint32_t timeout; //超时时间(单位：毫秒)

- (void)setEnviroment:(RoomBoxIMEnviroment )enviroment;

//设置lbs host
- (void)setLbsHost:(NSString * __nonnull)lbsHost;

//设置日志回调
- (void)setLoggerCallback:(void(^ __nullable)(NSString *__nullable message))block;

//IM连接
- (void)initWithUid:(NSString *)uid andToken:(NSString *)token andDeviceId:(NSString *) deviceId;

//发送消息
- (void)sendMessageWithPath:(NSString * __nonnull)path andData:(NSData * __nonnull)data andBlock:(void(^ __nullable)(NSData * __nullable response)) block;

//接收所有消息
- (void)receiveAllMessageUsingBlock:(void(^ __nullable)(NSString *__nullable commandType,NSData *__nullable message)) block;

//接收指定类型的消息
- (void)receiveMessageByType:(NSString *)type UsingBlock:(void(^ __nullable)(NSString *__nullable commandType,RoomBoxIMMessage *__nullable message)) block;

//获取SDK的版本号
- (NSString *)getSDKVersion;

//暂停连接
- (void)pauseConnect;
//恢复连接
- (void)resumeConnect;
//强制重连
- (void)forceReConnect;
// IM断开连接
- (void)disconnect;

@end

NS_ASSUME_NONNULL_END
