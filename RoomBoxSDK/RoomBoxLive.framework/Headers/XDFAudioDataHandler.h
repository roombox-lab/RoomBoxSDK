//
//  XDFAudioDataHandler.h
//  RoomBoxSDK
//
//  Created by 刘冬冬 on 2020/1/17.
//  Copyright © 2020 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AudioOptions.h"
#import <AgoraRtcEngineKit/AgoraRtcEngineKit.h>
//@import AgoraRtcEngineKit;

typedef NS_ENUM(int, XDFAudioRecordStatus) {
    XDFAudioRecordStatusIniting = -1,
    XDFAudioRecordStatusStoped = 0,
    XDFAudioRecordStatusOnRecording = 1
};
NS_ASSUME_NONNULL_BEGIN
typedef void(^XDFFetchDataBlock)(NSData *data);
@interface XDFAudioDataHandler : NSObject
//int samples;  //number of samples in this frame
//int bytesPerSample;  //number of bytes per sample: 2 for PCM16
//int channels;  //number of channels (data are interleaved if stereo)
//int samplesPerSec;
@property (nonatomic, assign) int samples;
@property (nonatomic, assign) int bytesPerSample;
@property (nonatomic, assign) int channels;
@property (nonatomic, assign) int samplesPerSec;
@property (nonatomic, assign) int samplesRate;
@property (nonatomic, assign) AudioCRMode audioMode;
@property (nonatomic, assign, getter=getInternalSedonds) int internalSedonds;
@property (nonatomic, assign) XDFAudioRecordStatus recordStatus;
- (void)appendData:(NSData *)data;
- (void)stopAudioRecord;
- (void)fetchDataEach2Secondes:(XDFFetchDataBlock )block;
- (void)startAudioRecord;
- (void)initRecord:(AgoraRtcEngineKit * _Nullable )agoraKit sampleRate:(int)sampleRate channels:(int)channels audioCRMode:(AudioCRMode)audioCRMode IOType:(IOUnitType)ioType;
- (void)initNativeRecordSampleRate:(int)sampleRate channels:(int)channels audioCRMode:(AudioCRMode)audioCRMode IOType:(IOUnitType)ioType;
@end

NS_ASSUME_NONNULL_END
