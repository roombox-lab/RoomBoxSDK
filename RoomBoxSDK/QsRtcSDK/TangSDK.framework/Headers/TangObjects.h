//
//  TangObjects.h
//  TangRtcEngineKit
//
//  Copyright (c) 2018 Tang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "TangEnumerates.h"
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView VIEW_CLASS;
typedef UIColor COLOR_CLASS;
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView VIEW_CLASS;
typedef NSColor COLOR_CLASS;
#endif

/**
 * The class of TangAudioFrame.
 */

 @interface TangAudioFrame: NSObject
 @property (assign, nonatomic) NSInteger samplesPerChannel;
 @property (assign, nonatomic) NSInteger bytesPerSample;
 @property (assign, nonatomic) NSInteger channels;
 @property (assign, nonatomic) NSInteger samplesPerSec;
 @property (strong, nonatomic) NSData* _Nullable buffer;
 @property (assign, nonatomic) int64_t renderTimeMs;
 @property (assign, nonatomic) NSInteger avSyncType;
@end


/** Properties of the video canvas object.
 */
@interface TangRtcVideoCanvas : NSObject
/** The video display view.

 VIEW_CLASS is a general name for this property. See the following definitions for iOS and macOS:

 - iOS: NSGNetView
 - MacOS: NSView
 */
@property (strong, nonatomic) VIEW_CLASS* _Nullable view;
/** Render mode of the view: TangVideoRenderMode
 */
@property (assign, nonatomic) TangVideoRenderMode renderMode;
/** Name of the channel.
 */
@property (copy, nonatomic) NSString* _Nullable channel;
/** User ID of the view.
 */
@property (assign, nonatomic) NSUInteger uid;
@end

/** The configurations of the last-mile network probe test. */
@interface TangLastmileProbeConfig : NSObject
/** Sets whether or not to test the uplink network. Some users, for example, the audience in a Live-broadcast channel, do not need such a test.

- NO: disables the test.
- YES: enables the test.
*/
@property (assign, nonatomic) BOOL probeUplink;
/** Sets whether or not to test the downlink network.

- NO: disables the test.
- YES: enables the test.
*/
@property (assign, nonatomic) BOOL probeDownlink;
/** The expected maximum sending bitrate (Kbps) of the local user.

The value ranges between 100 and 5000. We recommend setting this parameter according to the bitrate value set by [setVideoEncoderConfiguration]([TangRtcEngineKit setVideoEncoderConfiguration:]). */
@property (assign, nonatomic) NSUInteger expectedUplinkBitrate;
/** The expected maximum receiving bitrate (Kbps) of the local user.

The value ranges between 100 and 5000.
*/
@property (assign, nonatomic) NSUInteger expectedDownlinkBitrate;
@end

/** The last-mile network probe test result in one direction (uplink or downlink). */
@interface TangLastmileProbeOneWayResult : NSObject
/** The packet loss rate (%). */
@property (assign, nonatomic) NSUInteger packetLossRate;
/** The network jitter (ms). */
@property (assign, nonatomic) NSUInteger jitter;
/* The estimated available bandwidth (Kbps). */
@property (assign, nonatomic) NSUInteger availableBandwidth;
@end

/** The uplink and downlink last-mile network probe test result. */
@interface TangLastmileProbeResult : NSObject
/* The state of the probe test.

See [TangLastmileProbeResultState](TangLastmileProbeResultState).
*/
@property (assign, nonatomic) TangLastmileProbeResultState state;
/** The round-trip delay time (ms). */
@property (assign, nonatomic) NSUInteger rtt;
/** The uplink last-mile network report

See [TangLastmileProbeOneWayResult](TangLastmileProbeOneWayResult).
*/
@property (strong, nonatomic) TangLastmileProbeOneWayResult *_Nonnull uplinkReport;
/** The downlink last-mile network report

See [TangLastmileProbeOneWayResult](TangLastmileProbeOneWayResult).
*/
@property (strong, nonatomic) TangLastmileProbeOneWayResult *_Nonnull downlinkReport;
@end

/** Statistics of the local video stream.
 */
@interface TangRtcLocalVideoStats : NSObject
/** Bitrate (Kbps) sent in the reported interval, which does not include the bitrate of the re-transmission video after packet loss. */
@property (assign, nonatomic) NSUInteger sentBitrate;
/** Frame rate (fps) sent in the reported interval, which does not include the frame rate of the re-transmission video after packet loss. */
@property (assign, nonatomic) NSUInteger sentFrameRate;
/** The encoder output frame rate (fps) of the local video. */
@property (assign, nonatomic) NSUInteger encoderOutputFrameRate;
/** The renderer output frame rate (fps) of the local video. */
@property (assign, nonatomic) NSUInteger rendererOutputFrameRate;
/** The target bitrate (Kbps) of the current encoder. This value is estimated by the SDK based on the current network conditions. */
@property (assign, nonatomic) NSUInteger sentTargetBitrate;
/** The target frame rate (fps) of the current encoder. */
@property (assign, nonatomic) NSUInteger sentTargetFrameRate;
/** Quality change of the local video in terms of target frame rate and target bit rate in this reported interval, see [TangVideoQualityAdaptIndication](TangVideoQualityAdaptIndication). */
@property (assign, nonatomic) TangVideoQualityAdaptIndication qualityAdaptIndication;
/** The encoding bitrate (Kbps), which does not include the bitrate of the re-transmission video after packet loss.
 */
@property (assign, nonatomic) NSUInteger encodedBitrate;
/** The width of the encoding frame (px).
 */
@property (assign, nonatomic) NSUInteger encodedFrameWidth;
/** The height of the encoding frame (px).
 */
@property (assign, nonatomic) NSUInteger encodedFrameHeight;
/** The value of the sent frame rate, represented by an aggregate value.
 */
@property (assign, nonatomic) NSUInteger encodedFrameCount;
/** The codec type of the local video：

 - TangVideoCodecTypeVP8 = 1: VP8.
 - TangVideoCodecTypeH264 = 2: (Default) H.264.
 */
@property (assign, nonatomic) TangVideoCodecType codecType;

/** The packet loss rate (%) from the local client to Tang's edge server,
 * before network countermeasures.
*/
@property (assign, nonatomic) NSInteger txPacketLossRate;

@property (assign, nonatomic) NSInteger captureFrameRate;
/** The PSNR point to show the quality of video, nomal level is in [20,40].
  */
@property (assign, nonatomic) NSUInteger videoQualityPoint;
@end

/** Statistics of the remote video stream.
 */
@interface TangRtcRemoteVideoStats : NSObject
/** User ID of the user sending the video streams.
 */
@property (assign, nonatomic) NSUInteger uid;
/** Time delay (ms). **DEPRECATED**
 */
@property (assign, nonatomic) NSUInteger __deprecated delay;
/** Width (pixels) of the video stream.
 */
@property (assign, nonatomic) NSUInteger width;
/** Height (pixels) of the video stream.
 */
@property (assign, nonatomic) NSUInteger height;
/** The average bitrate (Kbps) of the received video stream.
 */
@property (assign, nonatomic) NSUInteger receivedBitrate;
/** The decoder output frame rate (fps) of the remote video.
 */
@property (assign, nonatomic) NSUInteger decoderOutputFrameRate;
/** The renderer output frame rate (fps) of the remote video.
 */
@property (assign, nonatomic) NSUInteger rendererOutputFrameRate;
/** Packet loss rate (%) of the remote video stream after network countermeasures.
 */
@property (assign, nonatomic) NSUInteger packetLossRate;
/** Video stream type (high-stream or low-stream).
 */
@property (assign, nonatomic) TangVideoStreamType rxStreamType;
/** The total freeze time (ms) of the remote video stream after the remote user joins the channel. In a video session where the frame rate is set to no less than 5 fps, video freeze occurs when the time interval between two adjacent renderable video frames is more than 500 ms.
 */
@property (assign, nonatomic) NSUInteger totalFrozenTime;
/** The total video freeze time as a percentage (%) of the total time when the video is available.
 */
@property (assign, nonatomic) NSUInteger frozenRate;
/** The total active time (ms) of the remote video stream after the remote user joins the channel.
 */
@property (assign, nonatomic) NSUInteger totalActiveTime;
/** The total active time (ms) of the remote video stream after the remote user publish the video stream.
 */
@property (assign, nonatomic) NSInteger publishDuration;
@end

/** The statistics of the local audio stream.
 */
@interface TangRtcLocalAudioStats : NSObject
/** The number of channels.
 */
@property (assign, nonatomic) NSUInteger numChannels;
/** The sample rate (Hz).
 */
@property (assign, nonatomic) NSUInteger sentSampleRate;
/** The average sending bitrate (Kbps).
 */
@property (assign, nonatomic) NSUInteger sentBitrate;
/** The audio packet loss rate (%)
 */
@property (assign, nonatomic) NSUInteger txPacketLossRate;
@end

/** The statistics of the remote audio stream.
 */
@interface TangRtcRemoteAudioStats : NSObject
/** User ID of the user sending the audio stream.
 */
@property (assign, nonatomic) NSUInteger uid;
/** Audio quality received by the user.
 */
@property (assign, nonatomic) NSUInteger quality;
/** Network delay (ms) from the sender to the receiver.
 */
@property (assign, nonatomic) NSUInteger networkTransportDelay;
/** Network delay (ms) from the receiver to the jitter buffer.
 */
@property (assign, nonatomic) NSUInteger jitterBufferDelay;
/** Packet loss rate in the reported interval.
 */
@property (assign, nonatomic) NSUInteger audioLossRate;
/** The number of channels.
 */
@property (assign, nonatomic) NSUInteger numChannels;
/** The sample rate (Hz) of the received audio stream in the reported interval.
 */
@property (assign, nonatomic) NSUInteger receivedSampleRate;
/** The average bitrate (Kbps) of the received audio stream in the reported interval.
 */
@property (assign, nonatomic) NSUInteger receivedBitrate;
/** The total freeze time (ms) of the remote audio stream after the remote user joins the channel. 
 *
 * In every two seconds, the audio frame loss rate reaching 4% is counted as one audio freeze. The total audio freeze time = The audio freeze number &times; 2000 ms.
 */
@property (assign, nonatomic) NSUInteger totalFrozenTime;
/** The total audio freeze time as a percentage (%) of the total time when the audio is available.
 */
@property (assign, nonatomic) NSUInteger frozenRate;
/** The total active time (ms) of the remote audio stream after the remote user joins the channel.
 */
@property (assign, nonatomic) NSUInteger totalActiveTime;
/** The total active time (ms) of the remote audio stream after the remote user publish the audio stream.
 */
@property (assign, nonatomic) NSInteger publishDuration;
@end

/** Properties of the audio volume information.

An array containing the user ID and volume information for each speaker:

- uid: User ID of the speaker. The uid of the local user is 0.
- volume：Volume of the speaker. The value ranges between 0 (lowest volume) and 255 (highest volume).
 */
@interface TangRtcAudioVolumeInfo : NSObject
/** User ID of the speaker.
 */
@property (assign, nonatomic) NSUInteger uid;
/** The volume of the speaker. The value ranges between 0 (lowest volume) to 255 (highest volume).
 */
@property (assign, nonatomic) NSUInteger volume;
/** Whether current signal contains human voice.
 */
@property (assign, nonatomic) NSUInteger vad;
/** The channel ID, which indicates which channel the speaker is in.
 */
@property (copy, nonatomic) NSString * _Nonnull channelId;
@end

/** Configurations of rhythm player.
 */
@interface TangRtcRhythmPlayerConfig : NSObject
/** Beats per measure.
 */
@property (assign, nonatomic) NSUInteger beatsPerMeasure;
/** Beats per minute.
 */
@property (assign, nonatomic) NSUInteger beatsPerMinute;
/** Whether rhythm publish to far end.
 */
@property (assign, nonatomic) BOOL publish;
@end

/** Statistics of the channel
 */
@interface TangChannelStats: NSObject
/** Call duration (s), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger duration;
/** Total number of bytes transmitted, represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger txBytes;
/** Total number of bytes received, represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger rxBytes;
/** Total number of audio bytes sent (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger txAudioBytes;
/** Total number of video bytes sent (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger txVideoBytes;
/** Total number of audio bytes received (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger rxAudioBytes;
/** Total number of video bytes received (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger rxVideoBytes;
/** Total packet transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger txKBitrate;
/** Total receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger rxKBitrate;
/** Audio packet transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger txAudioKBitrate;
/** Audio receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger rxAudioKBitrate;
/** Video transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger txVideoKBitrate;
/** Video receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger rxVideoKBitrate;
/** Client-server latency (ms)
 */
@property (assign, nonatomic) NSInteger lastmileDelay;
/** The packet loss rate (%) from the local client to Tang's edge server, before network countermeasures.
 */
@property (assign, nonatomic) NSInteger txPacketLossRate;
/** The packet loss rate (%) from Tang's edge server to the local client, before network countermeasures.
 */
@property (assign, nonatomic) NSInteger rxPacketLossRate;
/** Number of users in the channel.

- Communication profile: The number of users in the channel.
- Live broadcast profile:

  - If the local user is an audience: The number of users in the channel = The number of hosts in the channel + 1.
  - If the user is a host: The number of users in the channel = The number of hosts in the channel.
 */
@property (assign, nonatomic) NSInteger userCount;
/** Application CPU usage (%).
 */
@property (assign, nonatomic) double cpuAppUsage;
/** System CPU usage (%).
 */
@property (assign, nonatomic) double cpuTotalUsage;
/** GatewayRtt
 */
@property (assign, nonatomic) NSInteger gatewayRtt;


@property (assign, nonatomic) double memoryAppUsageRatio;

@property (assign, nonatomic) double memoryTotalUsageRatio;

@property (assign, nonatomic) NSInteger memoryAppUsageInKbytes;
@end

/** Properties of the video encoder configuration.
 */
@interface TangVideoEncoderConfiguration: NSObject
/** The video frame dimension (px) used to specify the video quality in the total number of pixels along a frame's width and height. The default value is 640 x 360.

You can customize the dimension, or select from the following list:

 - TangVideoDimension120x120
 - TangVideoDimension160x120
 - TangVideoDimension180x180
 - TangVideoDimension240x180
 - TangVideoDimension320x180
 - TangVideoDimension240x240
 - TangVideoDimension320x240
 - TangVideoDimension424x240
 - TangVideoDimension360x360
 - TangVideoDimension480x360
 - TangVideoDimension640x360
 - TangVideoDimension480x480
 - TangVideoDimension640x480
 - TangVideoDimension840x480
 - TangVideoDimension960x720
 - TangVideoDimension1280x720
 - TangVideoDimension1920x1080 (macOS only)
 - TangVideoDimension2540x1440 (macOS only)
 - TangVideoDimension3840x2160 (macOS only)

 Note:

 - The dimension does not specify the orientation mode of the output ratio. For how to set the video orientation, see [TangVideoOutputOrientationMode](TangVideoOutputOrientationMode).
 - Whether 720p can be supported depends on the device. If the device cannot support 720p, the frame rate will be lower than the one listed in the table. Tang optimizes the video in lower-end devices.
 - iPhones do not support video frame dimensions above 720p.
 */
@property (assign, nonatomic) CGSize dimensions;

/** The frame rate of the video (fps). 

 You can either set the frame rate manually or choose from the following options. The default value is 15. We do not recommend setting this to a value greater than 30.

  *  TangVideoFrameRateFps1(1): 1 fps
  *  TangVideoFrameRateFps7(7): 7 fps
  *  TangVideoFrameRateFps10(10): 10 fps
  *  TangVideoFrameRateFps15(15): 15 fps
  *  TangVideoFrameRateFps24(24): 24 fps
  *  TangVideoFrameRateFps30(30): 30 fps
  *  TangVideoFrameRateFps60(30): 60 fps (macOS only)
 */
@property (assign, nonatomic) NSInteger frameRate;

/** The minimum video encoder frame rate (fps).

The default value is DEFAULT_MIN_BITRATE(-1) (the SDK uses the lowest encoder frame rate). For information on scenarios and considerations, see [Set the Video Profile (iOS)](../../../videoProfile_ios) or [Set the Video Profile (macOS)](../../../videoProfile_mac).
*/
@property (assign, nonatomic) NSInteger minFrameRate;

/** The bitrate of the video.

 Sets the video bitrate (Kbps). Refer to the table below and set your bitrate. If you set a bitrate beyond the proper range, the SDK automatically adjusts it to a value within the range. You can also choose from the following options:

 - TangVideoBitrateStandard: (recommended) the standard bitrate mode. In this mode, the bitrates differ between the Live-broadcast and Communication profiles:

     - Communication profile: the video bitrate is the same as the base bitrate.
     - Live-broadcast profile: the video bitrate is twice the base bitrate.

 - TangVideoBitrateCompatible: the compatible bitrate mode. In this mode, the bitrate stays the same regardless of the profile. In the Live-broadcast profile, if you choose this mode, the video frame rate may be lower than the set value.

Tang uses different video codecs for different profiles to optimize the user experience. For example, the Communication profile prioritizes the smoothness while the Live-broadcast profile prioritizes the video quality (a higher bitrate). Therefore, Tang recommends setting this parameter as TangVideoBitrateStandard.

**Video Bitrate Table**

| Resolution        	| Frame Rate (fps) 	| Base Bitrate (Kbps, for Communication) 	| Live Bitrate (Kbps, for Live Broadcast) 	|
|-------------------	|------------------	|----------------------------------------	|-----------------------------------------	|
| 160 &times; 120   	| 15               	| 65                                     	| 130                                     	|
| 120 &times; 120   	| 15               	| 50                                     	| 100                                     	|
| 320 &times; 180   	| 15               	| 140                                    	| 280                                     	|
| 180 &times; 180   	| 15               	| 100                                    	| 200                                     	|
| 240 &times; 180   	| 15               	| 120                                    	| 240                                     	|
| 320 &times; 240   	| 15               	| 200                                    	| 400                                     	|
| 240 &times; 240   	| 15               	| 140                                    	| 280                                     	|
| 424 &times; 240   	| 15               	| 220                                    	| 440                                     	|
| 640 &times; 360   	| 15               	| 400                                    	| 800                                     	|
| 360 &times; 360   	| 15               	| 260                                    	| 520                                     	|
| 640 &times; 360   	| 30               	| 600                                    	| 1200                                    	|
| 360 &times; 360   	| 30               	| 400                                    	| 800                                     	|
| 480 &times; 360   	| 15               	| 320                                    	| 640                                     	|
| 480 &times; 360   	| 30               	| 490                                    	| 980                                     	|
| 640 &times; 480   	| 15               	| 500                                    	| 1000                                    	|
| 480 &times; 480   	| 15               	| 400                                    	| 800                                     	|
| 640 &times; 480   	| 30               	| 750                                    	| 1500                                    	|
| 480 &times; 480   	| 30               	| 600                                    	| 1200                                    	|
| 848 &times; 480   	| 15               	| 610                                    	| 1220                                    	|
| 848 &times; 480   	| 30               	| 930                                    	| 1860                                    	|
| 640 &times; 480   	| 10               	| 400                                    	| 800                                     	|
| 1280 &times; 720  	| 15               	| 1130                                   	| 2260                                    	|
| 1280 &times; 720  	| 30               	| 1710                                   	| 3420                                    	|
| 960 &times; 720   	| 15               	| 910                                    	| 1820                                    	|
| 960 &times; 720   	| 30               	| 1380                                   	| 2760                                    	|
| 1920 &times; 1080 	| 15               	| 2080                                   	| 4160                                    	|
| 1920 &times; 1080 	| 30               	| 3150                                   	| 6300                                    	|
| 1920 &times; 1080 	| 60               	| 4780                                   	| 6500                                    	|
| 2560 &times; 1440 	| 30               	| 4850                                   	| 6500                                    	|
| 2560 &times; 1440 	| 60               	| 6500                                   	| 6500                                    	|
| 3840 &times; 2160 	| 30               	| 6500                                   	| 6500                                    	|
| 3840 &times; 2160 	| 60               	| 6500                                   	| 6500                                    	|


**Note:**

The base bitrate in this table applies to the Communication profile. The Live-broadcast profile generally requires a higher bitrate for better video quality. Tang recommends setting the bitrate mode as TangVideoBitrateStandard. You can also set the bitrate as twice the base bitrate.


*/
@property (assign, nonatomic) NSInteger bitrate;

/** The minimum encoding bitrate.

Sets the minimum encoding bitrate (Kbps).

The Tang SDK automatically adjusts the encoding bitrate to adapt to network conditions. Using a value greater than the default value forces the video encoder to output high-quality images but may cause more packet loss and hence sacrifice the smoothness of the video transmission. Unless you have special requirements for image quality, Tang does not recommend changing this value.

**Note:**

This parameter applies only to the Live-broadcast profile.*/
@property (assign, nonatomic) NSInteger minBitrate;

/** The video orientation mode of the video: TangVideoOutputOrientationMode.

 * TangVideoOutputOrientationModeAdaptative(0): (Default) The output video always follows the orientation of the captured video, because the receiver takes the rotational information passed on from the video encoder.
   - If the captured video is in landscape mode, the output video is in landscape mode.
   - If the captured video is in portrait mode, the output video is in portrait mode.
 * TangVideoOutputOrientationModeFixedLandscape(1): The output video is always in landscape mode. If the captured video is in portrait mode, the video encoder crops it to fit the output. This applies to situations where the receiver cannot process the rotational information. For example, CDN live streaming.
 * TangVideoOutputOrientationModeFixedPortrait(2): The output video is always in portrait mode. If the captured video is in landscape mode, the video encoder crops it to fit the output. This applies to situations where the receiver cannot process the rotational information. For example, CDN live streaming.

For scenarios with video rotation, Tang provides [Basic: Video Rotation Guide](https://docs.Tang.io/en/2.3/product/Interactive%20Broadcast/Quickstart%20Guide/rotation_guide_ios) to guide users on how to set this parameter to get the preferred video orientation.

 */
@property (assign, nonatomic) TangVideoOutputOrientationMode orientationMode;

/** The video encoding degradation preference under limited bandwidth.

TangDegradationPreference:

* TangDegradationMaintainQuality(0): (Default) Degrades the frame rate to guarantee the video quality.
* TangDegradationMaintainFramerate(1): Degrades the video quality to guarantee the frame rate.
*/
@property (assign, nonatomic) TangDegradationPreference degradationPreference;

/** Sets the mirror mode of the published local video stream. It only affects the video that the remote user sees. See [TangVideoMirrorMode](TangVideoMirrorMode).
 <p>**Note**</p>
 <p>The SDK disables the mirror mode by default.</p>
 */
@property (assign, nonatomic) TangVideoMirrorMode mirrorMode;


/** Initializes and returns a newly allocated TangVideoEncoderConfiguration object with the specified video resolution.

 @param size Video resolution.
 @param frameRate Video frame rate.
 @param bitrate Video bitrate.
 @param orientationMode TangVideoOutputOrientationMode.
 @return An initialized TangVideoEncoderConfiguration object.
 */
- (instancetype _Nonnull)initWithSize:(CGSize)size
                            frameRate:(TangVideoFrameRate)frameRate
                              bitrate:(NSInteger)bitrate
                      orientationMode:(TangVideoOutputOrientationMode)orientationMode;

/** Initializes and returns a newly allocated TangVideoEncoderConfiguration object with the specified video width and height.

 @param width Width of the video.
 @param height Height of the video.
 @param frameRate Video frame rate.
 @param bitrate Video bitrate.
 @param orientationMode TangVideoOutputOrientationMode.
 @return An initialized TangVideoEncoderConfiguration object.
 */
- (instancetype _Nonnull)initWithWidth:(NSInteger)width
                                height:(NSInteger)height
                             frameRate:(TangVideoFrameRate)frameRate
                               bitrate:(NSInteger)bitrate
                       orientationMode:(TangVideoOutputOrientationMode)orientationMode;
@end

/** Properties of the screen sharing encoding parameters.
 */
@interface TangScreenCaptureParameters: NSObject
/**  The maximum encoding dimensions for screen sharing.

The default value is 1920 x 1080 pixels, that is, 2073600 pixels. Tang uses the value of this parameter to calculate the charges.

If the aspect ratio is different between the encoding dimensions and screen dimensions, Tang applies the following algorithms for encoding. Suppose the encoding dimensions are 1920 x 1080:

- If the value of the screen dimensions is lower than that of the encoding dimensions, for example, 1000 x 1000, the SDK uses 1000 x 1000 for encoding.
- If the value of the screen dimensions is higher than that of the encoding dimensions, for example, 2000 x 1500, the SDK uses the maximum value under 1920 x 1080 with the aspect ratio of the screen dimension (4:3) for encoding, that is, 1440 x 1080.

In either case, Tang uses the value of this parameter to calculate the charges.
 */
@property (assign, nonatomic) CGSize dimensions;

/** The frame rate (fps) of the shared region. The default value is 5. We do not recommend setting this to a value greater than 15.
 */
@property (assign, nonatomic) NSInteger frameRate;

/** The bitrate (Kbps) of the shared region. The default value is 0 (the SDK works out a bitrate according to the dimensions of the current screen).
 */
@property (assign, nonatomic) NSInteger bitrate;

/** Sets whether or not to capture the mouse for screen sharing.

- YES: (Default) Capture the mouse.
- NO: Do not capture the mouse.
 */
@property (assign, nonatomic) BOOL captureMouseCursor;

@end

/** A class for providing user-specific CDN live audio/video transcoding settings.
 */
@interface TangLiveTranscodingUser: NSObject
/** User ID of the CDN live host.
 */
@property (assign, nonatomic) NSUInteger uid;
/** Position and size of the video frame.
 */
@property (assign, nonatomic) CGRect rect;
/**  Layer position of the video frame. The value ranges between 0 and 100.

From v2.3.0, the Tang SDK supports setting zOrder as 0.

    - 0: (Default) Lowest.
    - 100: Highest.

 Note: If the value is set to < 0 or > 100, the ERR_INVALID_ARGUMENT error occurs.
 */
@property (assign, nonatomic) NSInteger zOrder;
/** Transparency of the video frame.

 The value ranges between 0.0 and 1.0:

 * 0.0: Completely transparent.
 * 1.0: (Default) Opaque.
 */
@property (assign, nonatomic) double alpha;
/** The audio channel of the sound.

 The default value is 0:

    - 0: (Default) Supports dual channels. Depends on the upstream of the broadcaster.
    - 1: The audio stream of the broadcaster uses the FL audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels will be mixed into mono first.
    - 2: The audio stream of the broadcaster uses the FC audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels will be mixed into mono first.
    - 3: The audio stream of the broadcaster uses the FR audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels will be mixed into mono first.
    - 4: The audio stream of the broadcaster uses the BL audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels will be mixed into mono first.
    - 5: The audio stream of the broadcaster uses the BR audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels will be mixed into mono first.

Note: If your setting is not 0, you may need a specialized player.
 */
@property (assign, nonatomic) NSInteger audioChannel;
@end

/** Image properties.

 A class for setting the properties of the watermark and background images in live broadcasting.
 */
@interface TangImage: NSObject
/** URL address of the image on the broadcasting video.

The maximum length of this parameter is 1024 bytes.
 */
@property (strong, nonatomic) NSURL *_Nonnull url;
/** Position and size of the image on the broadcasting video in CGRect.
 */
@property (assign, nonatomic) CGRect rect;
@end

/** the configuration of camera capturer.
 */
@interface TangCameraCapturerConfiguration: NSObject
/** This preference will balance the performance and preview quality by adjusting camera output frame size.
 */
@property (assign, nonatomic) TangCameraCaptureOutputPreference preference;
@end

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

/** TangRtcDeviceInfo array.
 */
@interface TangRtcDeviceInfo : NSObject
@property (assign, nonatomic) int __deprecated index;

/** Device type: TangMediaDeviceType.
 */
@property (assign, nonatomic) TangMediaDeviceType type;

/** Device ID.
 */
@property (copy, nonatomic) NSString * _Nullable deviceId;

/** Device name.
 */
@property (copy, nonatomic) NSString * _Nullable deviceName;
@end
#endif

/** Video frame containing the Tang SDK's encoded video data.
 */
@interface TangVideoFrame : NSObject
/** Video format:

 * 1: I420
 * 2: BGRA
 * 3: NV21
 * 4: RGBA
 * 5: IMC2
 * 7: ARGB
 * 8: NV12
 * 12: iOS texture (CVPixelBufferRef)
 */
@property (assign, nonatomic) NSInteger format;

/** Timestamp of the incoming video frame (ms).

An incorrect timestamp results in frame loss or unsynchronized audio and video.

 */
@property (assign, nonatomic) CMTime time; // Time for this frame.

@property (assign, nonatomic) int stride DEPRECATED_MSG_ATTRIBUTE("use strideInPixels instead");

/** Line spacing of the incoming video frame, which must be in pixels instead of bytes. For textures, it is the width of the texture.
 */
@property (assign, nonatomic) int strideInPixels; // Number of pixels between two consecutive rows. Note: in pixel, not byte. Not used for iOS textures.

/** Height of the incoming video frame
 */
@property (assign, nonatomic) int height; // Number of rows of pixels. Not used for iOS textures.

/** CVPixelBuffer
 */
@property (assign, nonatomic) CVPixelBufferRef _Nullable textureBuf;

/** Raw data buffer
 */
@property (strong, nonatomic) NSData * _Nullable dataBuf;  // Raw data buffer. Not used for iOS textures.

/** (Optional) The number of pixels trimmed from the left. The default value is 0.
 */
@property (assign, nonatomic) int cropLeft;   // Number of pixels to crop on the left boundary.
/** (Optional) The number of pixels trimmed from the top. The default value is 0.
 */
@property (assign, nonatomic) int cropTop;    // Number of pixels to crop on the top boundary.
/** (Optional) The number of pixels trimmed from the right. The default value is 0.
 */
@property (assign, nonatomic) int cropRight;  // Number of pixels to crop on the right boundary.
/** (Optional) The number of pixels trimmed from the bottom. The default value is 0.
 */
@property (assign, nonatomic) int cropBottom; // Number of pixels to crop on the bottom boundary.
/** (Optional) The clockwise rotation of the incoming video frame.

Optional values: 0, 90, 180, or 270. The default value is 0.
 */
@property (assign, nonatomic) int rotation;   // 0, 90, 180, 270. See document for rotation calculation.
/* Note
 * 1. strideInPixels
 *    Stride is in pixels, not bytes.
 * 2. About the frame width and height.
 *    No field is defined for the width. However, it can be deduced by:
 *       croppedWidth = (strideInPixels - cropLeft - cropRight)
 *    And
 *       croppedHeight = (height - cropTop - cropBottom)
 * 3. About crop.
 *    _________________________________________________________________.....
 *    |                        ^                                      |  ^
 *    |                        |                                      |  |
 *    |                     cropTop                                   |  |
 *    |                        |                                      |  |
 *    |                        v                                      |  |
 *    |                ________________________________               |  |
 *    |                |                              |               |  |
 *    |                |                              |               |  |
 *    |<-- cropLeft -->|          valid region        |<- cropRight ->|
 *    |                |                              |               | height
 *    |                |                              |               |
 *    |                |_____________________________ |               |  |
 *    |                        ^                                      |  |
 *    |                        |                                      |  |
 *    |                     cropBottom                                |  |
 *    |                        |                                      |  |
 *    |                        v                                      |  v
 *    _________________________________________________________________......
 *    |                                                               |
 *    |<---------------- strideInPixels ----------------------------->|
 *
 *    If your buffer contains garbage data, you can crop them. For example, if the frame size is
 *    360 &times; 640, often the buffer stride is 368, that is, the extra 8 pixels on the
 *    right are for padding, and should be removed. In this case, you can set:
 *    strideInPixels = 368;
 *    height = 640;
 *    cropRight = 8;
 *    // cropLeft, cropTop, cropBottom are set to a default of 0
 */
@end

@interface TangVideoRawData : NSObject
@property (nonatomic, assign) int type;
@property (nonatomic, assign) int width;  //width of video frame
@property (nonatomic, assign) int height;  //height of video frame
@property (nonatomic, assign) int yStride;  //stride of Y data buffer
@property (nonatomic, assign) int uStride;  //stride of U data buffer
@property (nonatomic, assign) int vStride;  //stride of V data buffer
@property (nonatomic, assign) int rotation; // rotation of this frame (0, 90, 180, 270)
@property (nonatomic, assign) int64_t renderTimeMs; // timestamp
@property (nonatomic, assign) char* yBuffer;  //Y data buffer
@property (nonatomic, assign) char* uBuffer;  //U data buffer
@property (nonatomic, assign) char* vBuffer;  //V data buffer

@end


/** The image enhancement options in [setBeautyEffectOptions]([TangRtcEngineKit setBeautyEffectOptions:options:]). */
@interface TangBeautyOptions : NSObject

/** The lightening contrast level

[TangLighteningContrastLevel](TangLighteningContrastLevel), used with the lighteningLevel property:

- 0: Low contrast level.
- 1: (Default) Normal contrast level.
- 2: High contrast level.
*/
@property (nonatomic, assign) TangLighteningContrastLevel lighteningContrastLevel;

/** The brightness level.

The default value is 0.7. The value ranges from 0.0 (original) to 1.0.
 */
@property (nonatomic, assign) float lighteningLevel;

/** The sharpness level.

The default value is 0.5. The value ranges from 0.0 (original) to 1.0. This parameter is usually used to remove blemishes.
 */
@property (nonatomic, assign) float smoothnessLevel;

/** The redness level.

The default value is 0.1. The value ranges from 0.0 (original) to 1.0. This parameter adjusts the red saturation level.
*/
@property (nonatomic, assign) float rednessLevel;

@end

/** The user information, including the user ID and user account. */
@interface TangUserInfo : NSObject
/** The user ID of a user.
 */
@property (nonatomic, assign) NSUInteger uid;
/** The user account of a user.
 */
@property (copy, nonatomic) NSString * _Nullable userAccount;
@end

@interface TangRtcChannelMediaOptions : NSObject

@property (nonatomic, assign) BOOL autoSubscribeAudio;

@property (nonatomic, assign) BOOL autoSubscribeVideo;

@end

/** The configuration of audio recording. */
@interface TangAudioRecordingConfiguration : NSObject

/** The absolute file path of the recording file. The string of the file name is in UTF-8.

 The SDK determines the storage format of the recording file by the file name suffix:

 - .wav: Large file size with high fidelity.
 - .aac: Small file size with low fidelity.

 Ensure that the directory to save the recording file exists and is writable.
 */
@property (copy, nonatomic) NSString * _Nullable filePath;

/** Sets the audio recording quality. See TangAudioRecordingQuality.

 @note It is effective only when the recording format is AAC.
 */
@property (assign, nonatomic) TangAudioRecordingQuality recordingQuality;

/** The position of recording. See TangAudioRecordingPosition.
 */
@property (assign, nonatomic) TangAudioRecordingPosition recordingPosition;
@end

//__attribute__((visibility("default"))) @interface TangRtcChannelInfo : NSObject
//
//@property (nonatomic, copy) NSString * _Nonnull channelId;
//
//@end

@interface TangRtcEngineConfig: NSObject
 /** The App ID issued to you by Tang. See [How to get the App ID](https://docs.Tang.io/en/Tang%20Platform/token#get-an-app-id). Only users in apps with the same App ID can join the same channel and communicate with each other. Use an App ID to create only one TangRtcEngineKit instance.  To change your App ID, call [destroy]([TangRtcEngineKit destroy]) to `destroy` the current TangRtcEngineKit instance, and after `destroy` returns 0, call [sharedEngineWithConfig]([TangRtcEngineKit sharedEngineWithConfig:delegate:]) to create an TangRtcEngineKit instance with the new App ID.
  */
 @property (copy, nonatomic) NSString * _Nullable appId;
 /** The region for connection. This advanced feature applies to scenarios that have regional restrictions. <p>For the regions that Tang supports, see TangAreaCode. After specifying the region, the SDK connects to the Tang servers within that region.</p>
  
  @note The SDK supports specifying only one region.
  */
 @property (nonatomic, assign) NSUInteger areaCode;
 @end
