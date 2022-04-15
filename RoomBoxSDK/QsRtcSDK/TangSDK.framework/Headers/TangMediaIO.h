//
//  TangMediaIO.h
//  TangRtcEngineKit
//
//  Copyright (c) 2018 Tang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "TangEnumerates.h"
#import "TangObjects.h"


/** Video pixel format.

 This enumeration defines the pixel format of the video frame. Tang supports three pixel formats on iOS: I420, BGRA, and NV12. For information on the YVU format, see:

   * [FourCC YUV Pixel Formats](http://www.fourcc.org/yuv.php)
   * [Recommended 8-Bit YUV Formats for Video Rendering](https://docs.microsoft.com/zh-cn/windows/desktop/medfound/recommended-8-bit-yuv-formats-for-video-rendering)
 */
typedef NS_ENUM(NSUInteger, TangVideoPixelFormat) {
    /** I420 */
    TangVideoPixelFormatI420   = 1,
    /** BGRA */
    TangVideoPixelFormatBGRA   = 2,
    /** NV12 */
    TangVideoPixelFormatNV12   = 8,
    /** NV21 */
    TangVideoPixelFormatNV21 = 16,
};

/** Video rotation.

 This enumeration defines the rotating angle of the video. Tang supports rotating clockwise by 0, 90, 180, and 270 degrees.
 */
typedef NS_ENUM(NSInteger, TangVideoRotation) {
    /** No rotation */
    TangVideoRotationNone      = 0,
    /** 90 degrees */
    TangVideoRotation90        = 1,
    /** 180 degrees */
    TangVideoRotation180       = 2,
    /** 270 degrees */
    TangVideoRotation270       = 3,
};

/** Video buffer type */
typedef NS_ENUM(NSInteger, TangVideoBufferType) {
   /** Use a pixel buffer to transmit the video data. */
    TangVideoBufferTypePixelBuffer = 1,
    /** Use raw data to transmit the video data. */
    TangVideoBufferTypeRawData     = 2,
};

/** An object supporting video data in two formats; pixel buffer and raw data.

 When the video source is initialized, the media engine passes this object to you and you need to reserve it, and then pass the video frame to the media engine through this object once the video source is initialized.
 Call [bufferType]([TangVideoSinkProtocol bufferType]) to specify a buffer type. The video data can only be transmitted in the corresponding type.
 */
@protocol TangVideoFrameConsumer <NSObject>

/** Uses the video information in the pixel buffer.

 @param pixelBuffer Buffer type
 @param timestamp   Timestamp (ms) of the video frame. For each video frame, you need to set a timestamp.
 @param rotation    TangVideoRotation
 */
- (void)consumePixelBuffer:(CVPixelBufferRef _Nonnull)pixelBuffer
             withTimestamp:(CMTime)timestamp format:(TangVideoPixelFormat)format
                  rotation:(TangVideoRotation)rotation;

/** Uses the video information in the raw data.

 @param rawData   Raw data of the video frame.
 @param timestamp Timestamp (ms) of the video frame.
 @param format    TangVideoPixelFormat
 @param size      Size of the raw video data.
 @param rotation  TangVideoRotation
 */
- (void)consumeRawData:(void * _Nonnull)rawData
         withTimestamp:(CMTime)timestamp
                format:(TangVideoPixelFormat)format
                  size:(CGSize)size
              rotation:(TangVideoRotation)rotation;
@end

/** Defines a set of protocols to implement the custom video source and pass it to the underlying media engine to replace the default video source.

 TangVideoSourceProtocol allows you to take the ownership of the video source and manipulate it.
 By default, when enabling real-time communications, the Tang SDK enables the default video input device (built-in camera) to start video streaming.
 By calling [setVideoSource]([TangRtcEngineKit setVideoSource:]), you can change the default video input device, control it, and send the video source from the specified input device to the Tang Media Engine to handle the remaining video processes; such as video filtering and publishing the video to the RTC connection.
 Once you have implemented this interface, the Tang Media Engine automatically releases the ownership of the current video input device and passes the ownership to you, so that you can use the same video input device to capture the video stream.
 TangVideoSourceProtocol consists of the following methods:

 * Initializes the Video Source ([shouldInitialize](shouldInitialize))
 * Enables the Video Source ([shouldStart](shouldStart))
 * Disables the Video Source ([shouldStop](shouldStop))
 * Releases the Video Source ([shouldDispose](shouldDispose))
 * Retrieves the Buffer Type ([bufferType](bufferType))

 Note:

 * All methods in [TangVideoSourceProtocol]([TangVideoSourceProtocol]) are callbacks. The media engine maintains a finite state machine and uses these methods at the right time. Do not use these methods directly in the app.
 * These methods are synchronized.
 * If the media engine restarts during the process, these methods can be repeated for a couple of times.
 * These methods are not in the primary thread.

 When using the TangVideoSourceProtocol, call TangVideoBufferType, TangVideoPixelFormat, and TangVideoRotation to set the buffer type, pixel format, and rotation angle of the transmitted video.
 */
@protocol TangVideoSourceProtocol <NSObject>
@required
/** See TangVideoFrameConsumer */
@property (strong) id<TangVideoFrameConsumer> _Nullable consumer;
/** Initializes the video source.

 The media engine calls this method to initialize the video source. You can also initialize the video source before this method is called and return YES to the media engine in this method. You need to pass YES or NO in this method to tell the media engine if the video source is initialized.
 When the video source is initialized, the media engine initializes the TangVideoFrameConsumer pointer in TangVideoSourceProtocol, then the video source sends the video frame to the media engine through the TangVideoFrameConsumer method.

 @return * YES: If the external video source is initialized.
 * NO: If the external video source is not ready or fails to initialize, the media engine stops and reports the error.
 */
- (BOOL)shouldInitialize;

/** Enables the video source.

 Call this method when the media engine is ready to start video streaming. You should start the video source to capture the video frame. Once the frame is ready, use TangVideoFrameConsumer to consume the video frame.
 Pass one of the following return values to the media engine:

 * YES: If the external video source is enabled and TangVideoFrameConsumer is called to receive video frames.
 * NO: If the external video source is not ready or fails to enable, the media engine stops and reports the error.

 After YES is returned, video frames can be passed to the media engine through the preset TangVideoFrameConsumer interface method.
 */
- (void)shouldStart;

/** Disables the video source.

 Call this method when the media engine stops streaming. You should then stop capturing the video frame and consuming it. After this method is called, the video frames are discarded by the media engine.
 */
- (void)shouldStop;

/** Releases the video source.

Call this method when TangVideoFrameConsumer is released by the media engine. You can now release the video source as well as TangVideoFrameConsumer.
 */
- (void)shouldDispose;

/** Retrieves the buffer type.

 Passes the buffer type previously set in [TangVideoBufferType]([TangVideoBufferType]) to the media engine. This buffer type is used to set up the correct media engine environment.

 @return return TangVideoBufferType
 */
- (TangVideoBufferType)bufferType;
@end

/** Defines a set of protocols to implement the custom video sink and pass it to the underlying media engine to replace the default video sink.

 TangVideoSinkProtocol allows you to implement the custom video source.
 By default, when you try to enable real-time communications, the Tang SDK enables the default video sink to start video rendering. By calling [setLocalVideoRenderer]([TangRtcEngineKit setLocalVideoRenderer:]) and [setRemoteVideoRenderer]([TangRtcEngineKit setRemoteVideoRenderer:forUserId:]), you can change the default video sink.
 Once you implement this interface, you receive callbacks from the media engine to indicate the state of the custom video sink, the underlying media engine, and enable their synchronization. Follow each callback to handle the resource allocation, and to release and receive the video frame from the media engine.
 TangVideoSinkProtocol defines a set of protocols to create a customized video sink. The TangVideoFrameConsumer interface passes the video frames to the media engine, which then passes them to the renderer.
 After a customized video sink is created, the app passes it to the media engine, see [setLocalVideoRenderer]([TangRtcEngineKit setLocalVideoRenderer:]) and [setRemoteVideoRenderer]([TangRtcEngineKit setRemoteVideoRenderer:forUserId:]).
 TangVideoSinkProtocol consists of the following methods:

 * Initializes the Video Sink ([shouldInitialize](shouldInitialize))
 * Enables the Video Sink ([shouldStart](shouldStart))
 * Disables the Video Sink ([shouldStop](shouldStop))
 * Releases the Video Sink ([shouldDispose](shouldDispose))
 * Retrieves the Buffer Type ([bufferType](bufferType))
 * Retrieves the Pixel Format ([pixelFormat](pixelFormat))
 * (Optional) Outputs the Video in the Pixel Buffer ([renderPixelBuffer](renderPixelBuffer:rotation:))
 * (Optional) Outputs the Video in the Raw Data ([renderRawData](renderRawData:size:rotation:))

 Note: All methods defined in TangVideoSinkProtocol are callbacks. The media engine uses these methods to inform the customized renderer of its internal changes.
 An example is shown in the following steps to customize the video sink:

 1. Call bufferType and TangVideoPixelFormat to set the buffer type and pixel format of the video frame.
 2. Implement [shouldInitialize](shouldInitialize), [shouldStart](shouldStart), [shouldStop](shouldStop), and [shouldDispose](shouldDispose) to manage the customized video sink.
 3. Implement the buffer type and pixel format as specified in TangVideoFrameConsumer.
 4. Create the customized video sink object.
 5. Call the [setLocalVideoRenderer]([TangRtcEngineKit setLocalVideoRenderer:]) and [setRemoteVideoRenderer]([TangRtcEngineKit setRemoteVideoRenderer:forUserId:]) methods to set the local and remote renderers.
 6. The media engine calls functions in TangVideoSinkProtocol according to its internal state.
 */
@protocol TangVideoSinkProtocol <NSObject>
@required
/** Initializes the video  sink.

 You can also initialize the video sink before this method is called and return YES in this method.

 @return * YES: If the video sink is initialized.
 * NO: If the video sink is not ready or fails to initialize, the media engine stops and reports the error.
 */
- (BOOL)shouldInitialize;

/** Enables the video sink.

 Call this method when the media engine starts streaming.

 * YES: If the video sink is ready. The media engine provides the video frame to the custom video sink by calling the TangVideoFrameConsumer interface.
 * NO: If the video sink is not ready.
 */
- (void)shouldStart;

/** Disables the video sink.

 Call this method when the media engine stops video streaming. You should then stop the video sink.
 */
- (void)shouldStop;

/** Releases the video sink.

 Call this method when the media engine wants to release the video sink resources.
 */
- (void)shouldDispose;

/** Retrieves the buffer type and passes the buffer type specified in [TangVideoBufferType]([TangVideoBufferType]) to the media engine.

 @return bufferType TangVideoBufferType
 */
- (TangVideoBufferType)bufferType;

/** Retrieves the pixel format and passes it to the media engine.

 @return pixelFormat TangVideoPixelFormat
 */
- (TangVideoPixelFormat)pixelFormat;

@optional
/** (Optional) Outputs the video in the pixel buffer.

 @param pixelBuffer Video in the pixel buffer.
 @param rotation    Clockwise rotating angle of the video frame. See TangVideoRotation.
 */
- (void)renderPixelBuffer:(CVPixelBufferRef _Nonnull)pixelBuffer
                 rotation:(TangVideoRotation)rotation;

/** (Optional) Outputs the video in the raw data.

 @param rawData  Raw video data.
 @param size     Size of the raw video.
 @param rotation Clockwise rotating angle of the video frame. See TangVideoRotation.
 */
- (void)renderRawData:(void * _Nonnull)rawData
                 size:(CGSize)size
             rotation:(TangVideoRotation)rotation;
@end


#pragma mark - Tang Default Media IO
/** Default camera position */
typedef NS_ENUM(NSInteger, TangRtcDefaultCameraPosition) {
    /** Front camera */
    TangRtcDefaultCameraPositionFront = 0,
    /** Rear camera */
    TangRtcDefaultCameraPositionBack = 1,
};

@interface TangRtcDefaultCamera: NSObject<TangVideoSourceProtocol>
#if TARGET_OS_IPHONE
@property (nonatomic, assign) TangRtcDefaultCameraPosition position;
- (instancetype _Nonnull)initWithPosition:(TangRtcDefaultCameraPosition)position;
#endif
@end

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))
@interface TangRtcScreenCapture: NSObject<TangVideoSourceProtocol>
@property (nonatomic, assign, readonly) BOOL ifWindowShare;
@property (nonatomic, assign, readonly) NSUInteger displayId;
@property (nonatomic, assign, readonly) NSUInteger windowId;
@property (nonatomic, assign, readonly) CGRect rect;
@property (nonatomic, assign, readonly) CGSize dimensions;
@property (nonatomic, assign, readonly) NSInteger frameRate;
@property (nonatomic, assign, readonly) NSInteger bitrate;
@property (nonatomic, assign, readonly) BOOL captureMouseCursor;

+ (instancetype _Nonnull)screenCaptureWithId:(NSUInteger)displayId
                                        rect:(CGRect)rect
                                  dimensions:(CGSize)dimensions
                                   frameRate:(NSInteger)frameRate
                                     bitrate:(NSInteger)bitrate
                          captureMouseCursor:(BOOL)captureMouseCursor;
+ (instancetype _Nonnull)windowCaptureWithId:(NSUInteger)windowId
                                        rect:(CGRect)rect
                                  dimensions:(CGSize)dimensions
                                   frameRate:(NSInteger)frameRate
                                     bitrate:(NSInteger)bitrate
                          captureMouseCursor:(BOOL)captureMouseCursor;
@end
#endif

@interface TangRtcDefaultRenderer: NSObject<TangVideoSinkProtocol>
@property (nonatomic, strong, readonly) VIEW_CLASS * _Nonnull view;
@property (nonatomic, assign) TangVideoRenderMode mode;
- (instancetype _Nonnull)initWithView:(VIEW_CLASS * _Nonnull)view
                           renderMode:(TangVideoRenderMode)mode;
@end
