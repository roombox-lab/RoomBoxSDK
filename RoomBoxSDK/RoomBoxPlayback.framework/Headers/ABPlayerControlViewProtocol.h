//
//  ABPlayerControlViewProtocol.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ABPlayerControlViewState) {
    ABPlayerControlViewStateLoading = 0, //
    ABPlayerControlViewStateReady,
    ABPlayerControlViewStatePlaying,
    ABPlayerControlViewStatePaused,
    ABPlayerControlViewStateBuffering,
    ABPlayerControlViewStateBufferingEnd,
    ABPlayerControlViewStateFailed,//播放过程中失败
    ABPlayerControlViewStateGetCourseFailed,//未绑定课程资源
    ABPlayerControlViewStateTrialEnd,//试听结束
    ABPlayerControlViewStatePlayEnd
};


/// 播放控制协议
@protocol ABPlayerControlViewProtocol <NSObject>

/// 初始化contorlView
/// @param config view内部依据config来配置
- (UIView *)initWithABPlayerControlConfig:(id)config;

/// 更新controlview的状态 controlview根据状态展示对应view
/// @param status 播控状态
- (void)showStatus:(ABPlayerControlViewState)status;

/// 更新播放器进度和总时间
/// @param currentTime 当前播放时间
/// @param duration 总时长
- (void)updateCurrentTime:(NSTimeInterval)currentTime
                 duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
