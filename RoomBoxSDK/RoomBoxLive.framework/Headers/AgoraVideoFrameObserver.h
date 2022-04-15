//
//  AgoraVideoFrameObserver.h
//  sac_mac
//
//  Created by Mrlu on 2019/7/3.
//  Copyright © 2019 SAC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AgoraVideoRawData.h"

NS_ASSUME_NONNULL_BEGIN
@class AgoraRtcEngineKit;


@interface AgoraVideoFrameObserver : NSObject


- (BOOL)isVideoNormalWithUid:(int64_t)uid;

- (void)registerObserverWithKit:(AgoraRtcEngineKit *)kit;

- (void)unRegisterObserver;

- (void)localSnapshot:(void (^ _Nullable)(UIImage * _Nonnull image))completion;

- (void)remoteSnapshotWithUid:(NSUInteger)uid image:(void (^ _Nullable)(UIImage * _Nonnull image))completion;

- (void)yuvToUIImageWithVideoRawData:(AgoraVideoRawData *)data;

@end

NS_ASSUME_NONNULL_END
