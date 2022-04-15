//
//  RoomBoxXDFVideoFrameObserver.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2021/3/12.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class XdfRtcEngineKit;

@interface RoomBoxXDFVideoFrameObserver : NSObject

- (BOOL)isVideoNormalWithUid:(int64_t)uid;

- (void)registerObserverWithKit:(XdfRtcEngineKit *)kit;

- (void)unRegisterObserver;

@end

NS_ASSUME_NONNULL_END
