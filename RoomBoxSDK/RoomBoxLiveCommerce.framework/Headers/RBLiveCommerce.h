//
//  RBLiveCommerce.h
//  AliyunLogProducer
//
//  Created by liangyl on 2021/12/7.
//  外部暴露方法

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//进入房间状态
typedef NS_ENUM(NSInteger, RBLCommerceJoinRoomError) {
    RBLCommerceJoinRoomNetworkError = -1000,            //网络链接错误
    RBLCommerceJoinRoomAuthError = -2000,               //SDK鉴权失败
    RBLCommerceJoinRoomUserInfoError = -2001,           //userId或classId为空
    RBLCommerceJoinRoomQuickEnterError = -2002,         //快速进入房间失败
    RBLCommerceJoinRoomClassInfoError = -2004,          //获取课程信息失败
    RBLCommerceJoinRoomAddUserError = -2006,            //添加观众失败
    RBLCommerceJoinRoomUserRoleError = -2007,           //用户角色错误
    RBLCommerceJoinRoomClassTypeError = -2008,          //课程类型不支持
    RBLCommerceJoinRoomStreamAddressError = -2009,      //获取推拉流地址错误
    RBLCommerceJoinRoomParamError = 1001,               //参数格式错误
    RBLCommerceJoinRoomUserNotFoundError = 3003,        //用户不存在
    RBLCommerceJoinRoomClassNotFoundError = 600032,     //教室不存在
    RBLCommerceJoinRoomNotSuportError = 400,            //暂不支持该模块
    RBLCommerceJoinRoomInternalError = 500,             //内部错误
    RBLCommerceJoinRoomNoPermissionsError = 5077,       //无权限进入
};

//离开房间原因
typedef NS_ENUM(NSInteger, RBLCommerceLeaveRoomState) {
    RBLCommerceLeaveRoomUserClose = 0,                  //用户主动离开
    RBLCommerceLeaveRoomKickout = 1,                    //互踢
    RBLCommerceLeaveRoomTimeOver = 2,                   //房间结束
    RBLCommerceLeaveRoomDeleted = 3,                    //用户被删除
    RBLCommerceLeaveRoomBlacklist = 4,                  //用户被拉黑
    RBLCommerceLeaveRoomSystemClose = 5,                //系统关闭
    RBLCommerceLeaveRoomSystemError = 6,                //其它错误
};


@protocol RBLiveCommerceDelegate <NSObject>

@required
/// 用户加入房间成功
/// @param liveVC 直播间控制器
- (void)roomLiveJoinRoomSuccess:(UIViewController * __nonnull)liveVC;

/// 用户加入房间错误
/// @param state 错误状态
- (void)roomLiveJoinRoomError:(RBLCommerceJoinRoomError)state;

/// 用户进入直播间之前屏幕朝向
- (UIDeviceOrientation)roomLivePreOrientation;

@optional
/// 用户点击关注事件回调
/// @param isFollow 是否关注
/// @param anchorId 主播id
/// @param userId 用户id
- (void)roomLiveFollowAction:(BOOL)isFollow
                 andAnchorId:(NSString *)anchorId
                   andUserId:(NSString *)userId;

/// 用户离开房间
/// @param state 离开房间原因
- (void)roomLiveLevaeRoomWithType:(RBLCommerceLeaveRoomState)state;

@end


@interface RBLiveCommerce : NSObject


/// 主播or超管进入房间
/// @param roomid 房间id
/// @param uid 用户id
/// @param token 用户token
/// @param bizCode bizCode
/// @param isFollow 是否关注主播
/// @param topVC 上层控制器
/// @param delegate 直播代理
+ (void)enterBroadCasterRoomWithRoomId:(NSString *)roomid
                                andUid:(NSString *)uid
                              andToken:(NSString *)token
                            andBizCode:(NSString *)bizCode
                           andIsFollow:(BOOL)isFollow
                              andTopVC:(UIViewController * __nonnull)topVC
                           andDelegate:(id<RBLiveCommerceDelegate> __nonnull)delegate;


/// 观众进入房间
/// @param roomid 房间id
/// @param uid 用户id
/// @param bizCode bizCode
/// @param isFollow 是否关注主播
/// @param topVC 上层控制器
/// @param delegate 直播代理
+ (void)enterAudienceRoomWithRoomId:(NSString *)roomid
                             andUid:(NSString *)uid
                         andBizCode:(NSString *)bizCode
                        andIsFollow:(BOOL)isFollow
                           andTopVC:(UIViewController * __nonnull)topVC
                        andDelegate:(id<RBLiveCommerceDelegate> __nonnull)delegate;


/// 设置关注状态
/// @param isFollow 是否关注主播
+ (void)configUserFollowState:(BOOL)isFollow;

@end

NS_ASSUME_NONNULL_END
