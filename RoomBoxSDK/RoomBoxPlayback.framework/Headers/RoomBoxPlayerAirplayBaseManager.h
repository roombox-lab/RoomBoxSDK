//
//  RoomBoxPlayerAirplayBaseManager.h
//  RoomBoxPlayBack
//
//  Created by 刘冬冬 on 2021/5/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol RoomBoxPlayerAirplayManagerDelegate <NSObject>

@optional
- (void)airplayerManagerDidFindServices:(NSArray *)services;
- (void)airplayerManagerConnectionDidFailed:(NSError *)error;
- (void)airplayerManagerDidUpdatePlayStatus:(NSUInteger)playStatus;
- (void)airplayerManagerDidUpdateProgress:(NSInteger)currentTime totalTime:(NSInteger)totalTime;
- (void)airplayerManagerPlayDidFailed:(NSError *)error;

@end


@protocol RoomBoxPlayerAirplayManagerPlayerDelegate <NSObject>
- (void)play;

/**
 暂停播放
 */
- (void)pause;

/**
 继续播放
 */
- (void)resumePlay;

/**
 进度调节

 @param seekTime 调节进度的位置，单位秒
 */
- (void)seekTo:(NSInteger)seekTime;

/**
 退出播放
 */
- (void)stop;

@end
@protocol RoomBoxPlayerAirplayManagerBaseDelegate <NSObject>

@property (nonatomic, weak) id<RoomBoxPlayerAirplayManagerPlayerDelegate> player;


@end

@interface RoomBoxPlayerAirplayBaseManager : NSObject<RoomBoxPlayerAirplayManagerBaseDelegate>
@property (nonatomic, weak) id<RoomBoxPlayerAirplayManagerDelegate> delegate;
@property (nonatomic, assign) NSUInteger playStatus;
@property (nonatomic, strong) id player;

- (void)startSearchingService;
- (void)stopSearchingService;
- (void)connectAirplayWithService:(id)service;
- (void)disconnectAirplay;
- (void)updateUrl:(NSString *)url currentTime:(NSInteger)time;

- (NSInteger)currentTime;
- (NSInteger)totalTime;

@end

NS_ASSUME_NONNULL_END
