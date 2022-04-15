//
//  XDFExternalAudio.h
//  RoomBoxSDK
//
//  Created by 刘冬冬 on 2020/1/16.
//  Copyright © 2020 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AudioOptions.h"
#import "XDFAudioDataHandler.h"

@class AgoraRtcEngineKit;
@class XDFExternalAudio;
@interface XDFExternalAudio : NSObject
@property (nonatomic, weak, setter=setAudioDataHandler:) XDFAudioDataHandler *audioHandler;
+ (instancetype)sharedExternalAudio;
- (void)setupExternalAudioWithAgoraKit:(AgoraRtcEngineKit *)agoraKit sampleRate:(int)sampleRate channels:(int)channels audioCRMode:(AudioCRMode)audioCRMode IOType:(IOUnitType)ioType;
- (void)registerObserverWithKit:(AgoraRtcEngineKit *)agoraKit sampleRate:(int)sampleRate channels:(int)channels audioCRMode:(AudioCRMode)audioCRMode;
- (void)startWork;
- (void)stopWork;
@end

