//
//  QsVideoFrameObserver.h
//  Alamofire
//
//  Created by Joey on 2021/4/23.
//

#import <Foundation/Foundation.h>
//#import <TangSDK/TangRtcEngineKit.h>
//#import <TangSDK/TangObjects.h>
//#import <TangSDK/TangRtcEngineKit.h>

@class TangRtcEngineKit;

NS_ASSUME_NONNULL_BEGIN

@interface QsVideoFrameObserver : NSObject

- (BOOL)isVideoNormalWithUid:(int64_t)uid;

- (void)registerObserverWithKit:(TangRtcEngineKit *)kit;

- (void)unRegisterObserver;

@end

NS_ASSUME_NONNULL_END
