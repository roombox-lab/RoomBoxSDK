//
//  TangRtcEngineKit.h
//  GNetTangSDK
//
//  Created by xiaoyu on 2021/1/7.
//  Copyright © 2021 Loren Zhai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TangConstants.h"
#import "TangObjects.h"
#import "TangMediaIO.h"
#import "TangMediaMetadata.h"
#import "TangLogWriter.h"


@class TangRtcEngineKit;
@class TangRtcChannel;

@protocol TangAudioFrameDelegate <NSObject>
@required

- (BOOL)onRecordAudioFrame:(TangAudioFrame* _Nonnull)frame;
- (BOOL)onPlaybackAudioFrame:(TangAudioFrame* _Nonnull)frame;
- (BOOL)onMixedAudioFrame:(TangAudioFrame* _Nonnull)frame;
- (BOOL)onPlaybackAudioFrameBeforeMixing:(TangAudioFrame* _Nonnull)frame uid:(NSUInteger)uid;
@end


@protocol TangVideoFrameDelegate <NSObject>
@required

-(void)onCaptureVideoFrame:(TangVideoRawData* _Nonnull)videoFrame;

-(BOOL)onRenderVideoFrameWithUID:(unsigned int)uid andVideoFrame:(TangVideoRawData* _Nonnull)videoFrame;

@end


@protocol TangRtcEngineDelegate <NSObject>
@optional

#pragma mark Delegate Methods

#pragma mark Core Delegate Methods

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didOccurWarning:(TangWarningCode)warningCode;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didOccurError:(TangErrorCode)errorCode;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didApiCallExecute:(NSInteger)error api:(NSString * _Nonnull)api result:(NSString * _Nonnull)result;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didJoinChannel:(NSString * _Nonnull)channel withUid:(NSUInteger)uid elapsed:(NSInteger) elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didRejoinChannel:(NSString * _Nonnull)channel withUid:(NSUInteger)uid elapsed:(NSInteger) elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didLeaveChannelWithStats:(TangChannelStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didRegisteredLocalUser:(NSString * _Nonnull)userAccount withUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didUpdatedUserInfo:(TangUserInfo * _Nonnull)userInfo withUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didClientRoleChanged:(TangClientRole)oldRole newRole:(TangClientRole)newRole;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didOfflineOfUid:(NSUInteger)uid reason:(TangUserOfflineReason)reason;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine connectionChangedToState:(TangConnectionStateType)state reason:(TangConnectionChangedReason)reason;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine networkTypeChangedToType:(TangNetworkType)type;

- (void)rtcEngineConnectionDidLost:(TangRtcEngineKit * _Nonnull)engine;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine tokenPrivilegeWillExpire:(NSString *_Nonnull)token;

- (void)rtcEngineRequestToken:(TangRtcEngineKit * _Nonnull)engine;


#pragma mark Media Delegate Methods
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didMicrophoneEnabled:(BOOL)enabled;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine reportAudioVolumeIndicationOfSpeakers:(NSArray<TangRtcAudioVolumeInfo *> * _Nonnull)speakers totalVolume:(NSInteger)totalVolume;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine activeSpeaker:(NSUInteger)speakerUid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstLocalAudioFrame:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstRemoteAudioFrameOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstRemoteAudioFrameDecodedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstLocalVideoFrameWithSize:(CGSize)size elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstRemoteVideoDecodedOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine firstRemoteVideoFrameOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didVideoEnabled:(BOOL)enabled byUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didLocalVideoEnabled:(BOOL)enabled byUid:(NSUInteger)uid;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine videoSizeChangedOfUid:(NSUInteger)uid size:(CGSize)size rotation:(NSInteger)rotation;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine remoteVideoStateChangedOfUid:(NSUInteger)uid state:(TangVideoRemoteState)state;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine remoteVideoStateChangedOfUid:(NSUInteger)uid state:(TangVideoRemoteState)state reason:(TangVideoRemoteStateReason)reason elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine localVideoStateChange:(TangLocalVideoStreamState)state error:(TangLocalVideoStreamError)error;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine remoteAudioStateChangedOfUid:(NSUInteger)uid state:(TangAudioRemoteState)state reason:(TangAudioRemoteStateReason)reason elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine localAudioStateChange:(TangAudioLocalState)state error:(TangAudioLocalError)error;

#pragma mark Fallback Delegate Methods

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didLocalPublishFallbackToAudioOnly:(BOOL)isFallbackOrRecover;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid;


#pragma mark Device Delegate Methods

/**-----------------------------------------------------------------------------
 * @name Device Delegate Methods
 * -----------------------------------------------------------------------------
 */

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine device:(NSString * _Nonnull)deviceId type:(TangMediaDeviceType)deviceType
     stateChanged:(NSInteger) state;

#endif
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didAudioRouteChanged:(TangAudioOutputRouting)routing;

#if TARGET_OS_IPHONE

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine cameraFocusDidChangedToRect:(CGRect)rect;
#endif

#if TARGET_OS_IPHONE
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine cameraExposureDidChangedToRect:(CGRect)rect;
#endif

#pragma mark Statistics Delegate Methods

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine reportRtcStats:(TangChannelStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine lastmileQuality:(TangNetworkQuality)quality;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine networkQuality:(NSUInteger)uid txQuality:(TangNetworkQuality)txQuality rxQuality:(TangNetworkQuality)rxQuality;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine lastmileProbeTestResult:(TangLastmileProbeResult * _Nonnull)result;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine localVideoStats:(TangRtcLocalVideoStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine localAudioStats:(TangRtcLocalAudioStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine remoteVideoStats:(TangRtcRemoteVideoStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine remoteAudioStats:(TangRtcRemoteAudioStats * _Nonnull)stats;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine audioTransportStatsOfUid:(NSUInteger)uid delay:(NSUInteger)delay lost:(NSUInteger)lost rxKBitRate:(NSUInteger)rxKBitRate;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine videoTransportStatsOfUid:(NSUInteger)uid delay:(NSUInteger)delay lost:(NSUInteger)lost rxKBitRate:(NSUInteger)rxKBitRate;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didPublishAudioStateChanged:(NSString *_Nonnull)channel oldState:(TangStreamPublishState)oldState newState:(TangStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didPublishVideoStateChanged:(NSString *_Nonnull)channel oldState:(TangStreamPublishState)oldState newState:(TangStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didSubscribeAudioStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(TangStreamSubscribeState)oldState newState:(TangStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;
- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didSubscribeVideoStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(TangStreamSubscribeState)oldState newState:(TangStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

#pragma mark Audio Player Delegate Methods

- (void)rtcEngineLocalAudioMixingDidFinish:(TangRtcEngineKit * _Nonnull)engine;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine localAudioMixingStateDidChanged:(TangAudioMixingStateCode)state errorCode:(TangAudioMixingErrorCode)errorCode;

- (void)rtcEngineRemoteAudioMixingDidStart:(TangRtcEngineKit * _Nonnull)engine;

- (void)rtcEngineRemoteAudioMixingDidFinish:(TangRtcEngineKit * _Nonnull)engine;

- (void)rtcEngineDidAudioEffectFinish:(TangRtcEngineKit * _Nonnull)engine soundId:(NSInteger)soundId;

- (void)rtcEngineAirPlayIsConnected:(TangRtcEngineKit * _Nonnull)engine;

#pragma mark Stream Message Delegate Methods

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine receiveStreamMessageFromUid:(NSUInteger)uid streamId:(NSInteger)streamId data:(NSData * _Nonnull)data;

- (void)rtcEngine:(TangRtcEngineKit * _Nonnull)engine didOccurStreamMessageErrorFromUid:(NSUInteger)uid streamId:(NSInteger)streamId error:(NSInteger)error missed:(NSInteger)missed cached:(NSInteger)cached;


#pragma mark Miscellaneous Delegate Methods

- (void)rtcEngineMediaEngineDidLoaded:(TangRtcEngineKit * _Nonnull)engine;

- (void)rtcEngineMediaEngineDidStartCall:(TangRtcEngineKit * _Nonnull)engine;


@end

#pragma mark - TangRtcEngineKit

@interface TangRtcEngineKit : NSObject

#pragma mark Core Service

+ (instancetype)sharedEngineWithAppId:(NSString * _Nonnull)appId
                                       logPath:(NSString * _Nullable)logPath
                                      delegate:(id<TangRtcEngineDelegate> _Nullable)delegate;

+ (instancetype)sharedEngineWithConfig:(TangRtcEngineConfig * _Nonnull)config
                                        logPath:(NSString * _Nullable)logPath
                                       delegate:(id<TangRtcEngineDelegate> _Nullable)delegate;

+ (void)destroy;

+(NSString * _Nonnull)getVersion;

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))
-(void)registerAudioFrameObserver:(id<TangAudioFrameDelegate>_Nullable)frameObserver;
#endif

- (int)setClientRole:(TangClientRole)role;

- (int)setChannelProfile:(TangChannelProfile)profile;

- (int)joinChannelByToken:(NSString * _Nullable)token
                channelId:(NSString * _Nonnull)channelId
                     info:(NSString * _Nullable)info
                      uid:(NSUInteger)uid
              joinSuccess:(void(^ _Nullable)(NSString * _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock;

- (int)leaveChannel:(void(^ _Nullable)(TangChannelStats * _Nonnull stat))leaveChannelBlock;

- (int)switchChannelByToken:(NSString * _Nullable)token
                  channelId:(NSString * _Nonnull)channelId
                joinSuccess:(void(^ _Nullable)(NSString * _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock;

- (int)enableVideo;

- (int)disableVideo;

#pragma mark Core Audio

- (int)enableAudio;

- (int)disableAudio;

- (int)setRecordingDeviceVolume:(int)volume;

- (int)getRecordingDeviceVolume;

- (BOOL)getRecordingDeviceMute;

- (int)muteLocalAudioStream:(BOOL)mute;

- (int)adjustPlaybackSignalVolume:(NSInteger)volume;

- (int)getPlaybackDeviceVolume:(int)volume;

- (BOOL)getPlaybackDeviceMute;

- (int)enableLocalAudio:(BOOL)enabled;

- (int)muteRemoteAudioStream:(NSUInteger)uid mute:(BOOL)mute;

- (int)muteAllRemoteAudioStreams:(BOOL)mute;

- (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)mute;

- (int)setAudioProfile:(TangAudioProfile)profile scenario:(TangAudioScenario)scenario;

- (int)startPreview;

- (int)stopPreview;

- (int)enableLocalVideo:(BOOL)enabled;

- (int)muteLocalVideoStream:(BOOL)mute;

- (int)muteRemoteVideoStream:(NSUInteger)uid
                        mute:(BOOL)mute;

- (int)muteAllRemoteVideoStreams:(BOOL)mute;

- (int)setDefaultMuteAllRemoteVideoStreams:(BOOL)mute;

- (int)enableAudioVolumeIndication:(NSInteger)interval
                            smooth:(NSInteger)smooth
                        report_vad:(BOOL)report_vad;

- (int)setupLocalVideo:(TangRtcVideoCanvas * _Nullable)local;

- (int)setVideoEncoderConfiguration:(TangVideoEncoderConfiguration * _Nonnull)config;

- (int)setupRemoteVideo:(TangRtcVideoCanvas * _Nullable)remote;

- (int)startAudioMixing:(NSString *  _Nonnull)filePath
               loopback:(BOOL)loopback
                replace:(BOOL)replace
                  cycle:(NSInteger)cycle;

- (int)stopAudioMixing;

- (int)pauseAudioMixing;

- (int)resumeAudioMixing;

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))
- (int)setDeviceVolume:(TangMediaDeviceType)type volume:(int)volume;

- (int)getDeviceVolume:(TangMediaDeviceType)type;

#endif

- (int)getAudioMixingDuration;

- (int)getAudioMixingCurrentPosition;

- (int)setAudioMixingPosition:(NSInteger)pos;

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))
- (void)monitorDeviceChange:(BOOL)enabled;

- (NSArray<TangRtcDeviceInfo *> * _Nullable)enumerateDevices:(TangMediaDeviceType)type;

- (TangRtcDeviceInfo * _Nullable)getDeviceInfo:(TangMediaDeviceType)type;

- (int)setDevice:(TangMediaDeviceType)type deviceId:(NSString * _Nonnull)deviceId;
#endif

- (int)enableLastmileTest;

- (int)disableLastmileTest;

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

- (int)startRecordingDeviceTest:(int)indicationInterval;

- (int)stopRecordingDeviceTest;

- (int)startPlaybackDeviceTest:(NSString * _Nonnull)audioFileName;

- (int)stopPlaybackDeviceTest;

-(int)startDeviceTest:(void*)view;

-(int)stopDeviceTest;
#endif

- (int)startCaptureDeviceTest:(VIEW_CLASS *_Nonnull)view;

- (int)stopCaptureDeviceTest;

- (int)setLocalVideoMirrorMode:(TangVideoMirrorMode)mode;

#if (TARGET_OS_IPHONE)
-(int)switchCamera;
#endif

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

-(int)enableLoopbackRecording:(BOOL)enabled
                   deviceName:(NSString * _Nullable)deviceName;
#endif

- (int)addPublishStreamUrl:(NSString * _Nonnull)url transcodingEnabled:(BOOL)transcodingEnabled;

- (int)removePublishStreamUrl:(NSString * _Nonnull)url;

- (void)setExternalVideoSource:(BOOL)enable useTexture:(BOOL)useTexture pushMode:(BOOL)pushMode;

- (void)setExternalAudioSource:(BOOL)enable sampleRate:(NSInteger)sampleRate channels:(NSInteger)channels;

- (int)setPlaybackAudioFrameParametersWithSampleRate:(NSInteger)sampleRate
                                             channel:(NSInteger)channel
                                                mode:(TangAudioRawFrameOperationMode)mode
                                      samplesPerCall:(NSInteger)samplesPerCall;

-(int)pushVideoFrame:(TangVideoFrame*_Nonnull)frame;

-(int)pushAudioFrame:(TangAudioFrame*_Nonnull)frame;

-(int)enableWebSdkInteroperability:(BOOL)enable;

- (int)setLogFilter:(NSUInteger)filter;

- (int)setLogFile:(NSString * _Nonnull)filePath;

- (int)setLogFileSize:(NSUInteger)fileSizeInKBytes;

//ios
- (void * _Nullable)getNativeHandle;

- (int)setRecordingAudioFrameParametersWithSampleRate:(NSInteger)sampleRate
                                              channel:(NSInteger)channel
                                                 mode:(TangAudioRawFrameOperationMode)mode
                                       samplesPerCall:(NSInteger)samplesPerCall;

- (int)setRemoteDefaultVideoStreamType:(TangVideoStreamType)streamType;

- (int)setRemoteVideoStream:(NSUInteger)uid
                       type:(TangVideoStreamType)streamType;
#if (TARGET_OS_IPHONE)
- (int)setEnableSpeakerphone:(BOOL)enableSpeaker;

#endif

- (BOOL)enableAEC:(BOOL)enabled;

- (int)setRemoteRenderMode:(NSUInteger)uid
                      mode:(TangVideoRenderMode)mode;

- (void)setVideoSource:(id<TangVideoSourceProtocol> _Nullable)videoSource;

- (id<TangVideoSourceProtocol> _Nullable)videoSource;

- (int)adjustRecordingSignalVolume:(NSInteger)volume;

-(void)setScreenOrientationFixedState:(TangViewOrientationFixedState)state;
//----------------------------待定-------------------------------------------
- (int)adjustAudioMixingVolume:(NSInteger)volume;

- (int)startEchoTestWithInterval:(NSInteger)interval
                  successBlock:(void(^ _Nullable)(NSString * _Nonnull channel, NSUInteger uid, NSInteger elapsed))successBlock;

- (int)setCameraCapturerConfiguration:(TangCameraCapturerConfiguration * _Nullable)configuration;

- (NSString * _Nullable)getCallId;

@property (nonatomic, weak) id<TangRtcEngineDelegate> _Nullable delegate;



@end
