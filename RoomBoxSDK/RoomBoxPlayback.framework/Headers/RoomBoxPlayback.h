//
//  RoomBoxPlayback.h
//  RoomBoxPlayBack
//
//  Created by 刘冬冬 on 2021/5/26.
//

#import <Foundation/Foundation.h>

#import "RoomBoxPlayBackInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlaybackDelegate <NSObject>
//离开
@optional
-(void)playbackLeaveComplete;

//将要离开
-(void)playbackWillLeave;

//鉴权失败
-(void)playbackLoginFailed;

////登入房间前屏幕旋转状态，退出后恢复 不设置会自动判断
-(UIDeviceOrientation )playbackPreOrientation;

//登入房间前传入屏幕横屏旋转方向只能传其他方向无效(UIDeviceOrientationLandscapeLeft,UIDeviceOrientationLandscapeRight)，进入后使用，不设置使用默认
-(UIDeviceOrientation )playbackLandscapeOrientation;


@end



@interface RoomBoxPlayback : NSObject

//url如果http开头表示播放的网络视频,否则位本地视频
+(void)enterPlayBackFromVC:(UIViewController *)vc uid:(NSString *)uid cid:(NSString *)cid token:(NSString *)token nickName:(NSString *)nickName url:(NSString *__nullable)url title:(NSString *__nullable)title bizCode:(NSString * __nullable)bizCode delegate:(id<RoomBoxPlaybackDelegate >)delegate ;

@end

NS_ASSUME_NONNULL_END

