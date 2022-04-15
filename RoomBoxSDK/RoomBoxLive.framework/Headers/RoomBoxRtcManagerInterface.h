//
//  RoomBoxRtcManagerInterface.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2021/3/10.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RoomBoxRtcChannelStats;
@class RoomBoxRtcUserInfo;
@class RoomBoxRtcAudioVolumeInfo;
@class RoomBoxRtcLocalAudioStats;
@class RoomBoxRtcLocalVideoStats;
@class RoomBoxRtcRemoteAudioStats;
@class RoomBoxRtcRemoteVideoStats;

NS_ASSUME_NONNULL_BEGIN

typedef enum RtcInstance {
    RtcInstanceNone     = 0,
    RtcInstanceAgora    = 1 << 0,
    //自研Rtc
    RtcInstanceXdf      = 1 << 1,
    //全时Rtc
    RtcInstanceQS       = 1 << 2
    
}RtcInstance;


@protocol RoomBoxRtcManagerDelegate <NSObject>

@optional
- (void)rtcEngine:(RtcInstance)engine didOccurWarning:(NSInteger)warningCode;

- (void)rtcEngine:(RtcInstance)engine didOccurError:(NSInteger)errorCode;

- (void)rtcEngine:(RtcInstance)engine didJoinChannel:(NSString *_Nonnull)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine didRejoinChannel:(NSString *_Nonnull)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine didLeaveChannelWithStats:(RoomBoxRtcChannelStats *_Nonnull)stats;

- (void)rtcEngine:(RtcInstance)engine didRegisteredLocalUser:(NSString *_Nonnull)userAccount withUid:(NSUInteger)uid;

- (void)rtcEngine:(RtcInstance)engine didUpdatedUserInfo:(RoomBoxRtcUserInfo *_Nonnull)userInfo withUid:(NSUInteger)uid;

- (void)rtcEngine:(RtcInstance)engine didClientRoleChanged:(NSInteger)oldRole newRole:(NSInteger)newRole;

- (void)rtcEngine:(RtcInstance)engine didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine didOfflineOfUid:(NSUInteger)uid reason:(NSUInteger)reason; 

- (void)rtcEngine:(RtcInstance)engine connectionChangedToState:(NSInteger)state reason:(NSUInteger)reason; //AgoraConnectionStateType AgoraConnectionChangedReason

- (void)rtcEngine:(RtcInstance)engine networkTypeChangedToType:(NSInteger)type; //AgoraNetworkType

- (void)rtcEngineConnectionDidLost:(RtcInstance)engine;

- (void)rtcEngineConnectionDidInterrupted:(RtcInstance)engine;

- (void)rtcEngine:(RtcInstance)engine tokenPrivilegeWillExpire:(NSString *_Nonnull)token;

- (void)rtcEngineRequestToken:(RtcInstance)engine;

//媒体事件回调
- (void)rtcEngine:(RtcInstance)engine reportAudioVolumeIndicationOfSpeakers:(NSArray<RoomBoxRtcAudioVolumeInfo *> *_Nonnull)speakers totalVolume:(NSInteger)totalVolume; //AgoraRtcAudioVolumeInfo

- (void)rtcEngine:(RtcInstance)engine activeSpeaker:(NSUInteger)speakerUid;

- (void)rtcEngine:(RtcInstance)engine firstLocalAudioFramePublished:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine firstLocalVideoFrameWithSize:(CGSize)size elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine firstLocalVideoFramePublished:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine videoSizeChangedOfUid:(NSUInteger)uid size:(CGSize)size rotation:(NSInteger)rotation;

- (void)rtcEngine:(RtcInstance)engine remoteVideoStateChangedOfUid:(NSUInteger)uid state:(NSUInteger)state reason:(NSUInteger)reason elapsed:(NSInteger)elapsed; //AgoraVideoRemoteState AgoraVideoRemoteStateReason

- (void)rtcEngine:(RtcInstance)engine localVideoStateChange:(NSInteger)state error:(NSInteger)error; // AgoraLocalVideoStreamState AgoraLocalVideoStreamError

- (void)rtcEngine:(RtcInstance)engine remoteAudioStateChangedOfUid:(NSUInteger)uid state:(NSUInteger)state reason:(NSUInteger)reason elapsed:(NSInteger)elapsed; //AgoraAudioRemoteState AgoraAudioRemoteStateReason

- (void)rtcEngine:(RtcInstance)engine localAudioStateChange:(NSUInteger)state error:(NSUInteger)error; // //AgoraAudioLocalState AgoraAudioLocalError

- (void)rtcEngine:(RtcInstance)engine firstRemoteVideoFrameOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(RtcInstance)engine didAudioPublishStateChange:(NSString *_Nonnull)channel oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState; // AgoraStreamPublishState  AgoraStreamPublishState

- (void)rtcEngine:(RtcInstance)engine didVideoPublishStateChange:(NSString *_Nonnull)channel oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState; //AgoraStreamPublishState AgoraStreamPublishState

- (void)rtcEngine:(RtcInstance)engine didAudioSubscribeStateChange:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;


- (void)rtcEngine:(RtcInstance)engine didVideoSubscribeStateChange:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState; // AgoraStreamSubscribeState  AgoraStreamSubscribeState

- (void)rtcEngine:(RtcInstance)engine didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;

- (void)rtcEngine:(RtcInstance)engine didAudoMuted:(BOOL)muted byUid:(NSUInteger)uid;

//统计数据事件回调
- (void)rtcEngine:(RtcInstance)engine remoteAudioStats:(RoomBoxRtcRemoteAudioStats *_Nonnull)stats; //AgoraRtcRemoteAudioStats

- (void)rtcEngine:(RtcInstance)engine reportRtcStats:(RoomBoxRtcChannelStats *_Nonnull)stats; //AgoraChannelStats

- (void)rtcEngine:(RtcInstance)engine lastmileQuality:(NSUInteger)quality; //AgoraNetworkQuality

- (void)rtcEngine:(RtcInstance)engine networkQuality:(NSUInteger)uid txQuality:(NSUInteger)txQuality rxQuality:(NSUInteger)rxQuality; //AgoraNetworkQuality

- (void)rtcEngine:(RtcInstance)engine lastmileProbeTestResult:(NSObject *_Nonnull)result; //AgoraLastmileProbeResult

- (void)rtcEngine:(RtcInstance)engine localVideoStats:(RoomBoxRtcLocalVideoStats *_Nonnull)stats; //AgoraRtcLocalVideoStats

- (void)rtcEngine:(RtcInstance)engine localAudioStats:(RoomBoxRtcLocalAudioStats *_Nonnull)stats; //AgoraRtcLocalAudioStats

- (void)rtcEngine:(RtcInstance)engine remoteVideoStats:(RoomBoxRtcRemoteVideoStats *_Nonnull)stats; //AgoraRtcRemoteVideoStats


@end

@protocol RoomBoxRtcChannelInterface;

@protocol RoomBoxRtcChannelDelegate <NSObject>

@optional

-(void)rtcChannel:(RtcInstance)engine didOccurWarning:(NSInteger)warningCode;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didOccurError:(NSInteger)errorCode;

-(void)rtcChannelDidJoinChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

-(void)rtcChannelDidRejoinChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

-(void)rtcChannelDidLeaveChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel withStats:(RoomBoxRtcChannelStats *_Nonnull)stats;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didClientRoleChanged:(NSInteger)oldRole newRole:(NSInteger)newRole;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didOfflineOfUid:(NSUInteger)uid reason:(NSUInteger)reason;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel connectionChangedToState:(NSInteger)state reason:(NSUInteger)reason;

-(void)rtcChannelDidLost:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel tokenPrivilegeWillExpire:(NSString *_Nonnull)token;

-(void)rtcChannelRequestToken:(RtcInstance )engine channel:(id<RoomBoxRtcChannelInterface>) channel;

-(void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel activeSpeaker:(NSUInteger)speakerUid;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel videoSizeChangedOfUid:(NSUInteger)uid size:(CGSize)size rotation:(NSInteger)rotation;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel remoteVideoStateChangedOfUid:(NSUInteger)uid state:(NSInteger)state reason:(NSUInteger)reason elapsed:(NSInteger)elapsed;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel remoteAudioStateChangedOfUid:(NSUInteger)uid state:(NSInteger)state reason:(NSUInteger)reason elapsed:(NSInteger)elapsed;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didLocalPublishFallbackToAudioOnly:(BOOL)isFallbackOrRecover;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel reportRtcStats:(RoomBoxRtcChannelStats *)stats;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel networkQuality:(NSUInteger)uid txQuality:(NSUInteger)txQuality rxQuality:(NSUInteger)rxQuality;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel remoteVideoStats:(RoomBoxRtcRemoteVideoStats *)stats;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel remoteAudioStats:(RoomBoxRtcRemoteAudioStats *)stats;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel rtmpStreamingChangedToState:(NSString *_Nonnull)url state:(NSUInteger)state errorCode:(NSUInteger)errorCode;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel rtmpStreamingEventWithUrl:(NSString *_Nonnull)url eventCode:(NSUInteger)eventCode;


- (void)rtcChannelTranscodingUpdated:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel;

- (void)rtcChannel:(RtcInstance)engine channel:(id<RoomBoxRtcChannelInterface>)channel receiveStreamMessageFromUid:(NSUInteger)uid streamId:(NSInteger)streamId data:(NSData *_Nonnull)data;


- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didOccurStreamMessageErrorFromUid:(NSUInteger)uid streamId:(NSInteger)streamId error:(NSInteger)error missed:(NSInteger)missed cached:(NSInteger)cached;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel channelMediaRelayStateDidChange:(NSInteger)state error:(NSInteger)error;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didReceiveChannelMediaRelayEvent:(NSInteger)event;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didAudioPublishStateChange:(NSUInteger)oldState newState:(NSUInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didVideoPublishStateChange:(NSUInteger)oldState newState:(NSUInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didAudioSubscribeStateChange:(NSUInteger)uid oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

- (void)rtcChannel:(RtcInstance)channel channel:(id<RoomBoxRtcChannelInterface>)channel didVideoSubscribeStateChange:(NSUInteger)uid oldState:(NSInteger)oldState newState:(NSInteger)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

@end

@protocol RoomBoxRtcChannelInterface <NSObject>

- (NSString * _Nullable)getId;
//设置角色
-(void)setClientRole:(NSInteger)rtcRole;
//离开频道
-(void)leave;
//销毁
-(void)destory;
//加入频道
-(void)joinChannel:(UInt64)uid withToken:(nullable NSString*)token;
//-(void)joinChannelNoMuteALL:(UInt64)uid withToken:(nullable NSString*)token;
-(void)joinChannelNoMuteLocal:(UInt64)uid withToken:(nullable NSString*)token;

- (void)muteLocalAudioStream:(BOOL)mute;

- (void)muteLocalVideoStream:(BOOL)mute;


- (void)muteRemoteAudioStream:(NSUInteger)uid mute:(BOOL)mute;

- (void)muteAllRemoteAudioStreams:(BOOL)mute;


- (void)muteRemoteVideoStream:(NSUInteger)uid mute:(BOOL)mute;

- (void)muteAllRemoteVideoStreams:(BOOL)mute;

- (void)setRtcChannelDelegate:(id<RoomBoxRtcChannelDelegate> _Nullable)channelDelegate;

- (void)setRemoteRenderMode:(NSUInteger)uid
                      mode:(NSUInteger)mode;


@end

@protocol RoomBoxRtcManagerInterface <NSObject>

-(void)setEnableVideo;

-(void)setDisableVideo;

-(void)setEnableLocalVideo:(BOOL)enabled;


//初始化当前Rtc
-(void)initCurrentRtcEngine:(NSString *) rtcId with:(nullable id<RoomBoxRtcManagerDelegate>) delegate;

-(void)setCurrentRtcEngine:(nullable id<RoomBoxRtcManagerDelegate>) delegate;

//获取当前rtc类型
-(RtcInstance)achieveCurrentRtcEngineType;

//当前Rtc 已经初始化
-(BOOL)achieveCurrentRtcEngineInit;

-(void)setLogPath:(NSString *)filePath;

//setRemoteVideoStream(uid : UInt,type :VideoStreamType)

//Rtc功能
-(void)setRemoteVideoStream:(UInt64)uid withVideo:(int)streamType;

//声音外放
-(void)setEnableSpeakerphone:(BOOL)enableSpeaker;

-(void)enableNetworkQuality;
-(void)unableNetworkQuality;

-(void)setupVideoProfile:(NSString *)level;

//开启预览
-(void)startRtcPreview;
-(void)stopRtcPreview;


//关联视图
-(void)setupLocalVideo:(nullable UIView *)localView with:(UInt64)uid;
-(void)setupRemoteVideo:(nullable UIView *)remoteView with:(UInt64)uid;
-(void)setupRemoteVideo:(nullable UIView *)remoteView channel:(NSString *)channel with:(UInt64)uid;


//加入频道
-(void)joinChannelNoMuteALL:(NSString *)channelID withUid:(UInt64)uid withToken:(nullable NSString*)token;
-(void)joinChannelNoMuteLocal:(NSString *)channelID withUid:(UInt64)uid withToken:(nullable NSString*)token;
-(void)joinChannel:(NSString *)channelID withUid:(UInt64)uid withToken:(nullable NSString*)token;

//离开频道
-(void)leaveRtcChannel;

//设置角色
-(void)setClientRole:(NSInteger)rtcRole;


//音频流订阅
-(void)muteLocalAudioStream:(BOOL)mute;
-(void)muteRemoteAudioStream:(UInt64)uid with:(BOOL)mute;
-(void)muteAllRemoteAudioStreams:(BOOL)mute;


-(void)muteLocalVideoStream:(BOOL)mute;
-(void)muteRemoteVideoStream:(UInt64)uid with:(BOOL)mute;
-(void)muteAllRemoteVideoStreams:(BOOL)mute;


-(void)setRemoteRenderMode:(UInt64)uid with:(NSUInteger)mode;


-(BOOL)isVideoRtcNormal:(UInt64)uid;


-(void)setAudioSessionForWebView;

-(void)setAudioSessionOperationRestriction:(UInt32)operation;

-(nullable id<RoomBoxRtcChannelInterface>)createRtcChannel:(NSString *) channelName;


-(void)registerFrameObserver;

-(void)unregisterFrameObserver;

- (void)localSnapshot:(void (^ _Nullable)(UIImage * _Nonnull image))completion;

//- (void)remoteSnapshotWithUid:(NSUInteger)uid image:(void (^ _Nullable)(UIImage * _Nonnull image))completion;

@end






NS_ASSUME_NONNULL_END
