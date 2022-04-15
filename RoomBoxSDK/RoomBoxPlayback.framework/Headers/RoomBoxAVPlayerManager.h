//
//  RoomBoxAVPlayerManager.h
//  RoomBoxPlayer
//
//  Created by 婉华孙 on 2019/9/18.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
@import RoomBoxUtils;

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxAVPlayerManager : NSObject<RBZFPlayerMediaPlayback>

@property (nonatomic, strong, readonly) AVURLAsset *asset;
@property (nonatomic, strong, readonly) AVPlayerItem *playerItem;
@property (nonatomic, strong, readonly) AVPlayer *player;
@property (nonatomic, assign) NSTimeInterval timeRefreshInterval;
/// 视频请求头
@property (nonatomic, strong) NSDictionary *requestHeader;


@end

NS_ASSUME_NONNULL_END
