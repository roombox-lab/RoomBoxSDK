/*
 * XDFIJKMediaPlayback.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, XDFIJKMPMovieScalingMode) {
    XDFIJKMPMovieScalingModeNone,       // No scaling
    XDFIJKMPMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    XDFIJKMPMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    XDFIJKMPMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, XDFIJKMPMoviePlaybackState) {
    XDFIJKMPMoviePlaybackStateStopped,
    XDFIJKMPMoviePlaybackStatePlaying,
    XDFIJKMPMoviePlaybackStatePaused,
    XDFIJKMPMoviePlaybackStateInterrupted,
    XDFIJKMPMoviePlaybackStateSeekingForward,
    XDFIJKMPMoviePlaybackStateSeekingBackward
};

typedef NS_OPTIONS(NSUInteger, XDFIJKMPMovieLoadState) {
    XDFIJKMPMovieLoadStateUnknown        = 0,
    XDFIJKMPMovieLoadStatePlayable       = 1 << 0,
    XDFIJKMPMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    XDFIJKMPMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

typedef NS_ENUM(NSInteger, XDFIJKMPMovieFinishReason) {
    XDFIJKMPMovieFinishReasonPlaybackEnded,
    XDFIJKMPMovieFinishReasonPlaybackError,
    XDFIJKMPMovieFinishReasonUserExited
};

// -----------------------------------------------------------------------------
// Thumbnails

typedef NS_ENUM(NSInteger, XDFIJKMPMovieTimeOption) {
    XDFIJKMPMovieTimeOptionNearestKeyFrame,
    XDFIJKMPMovieTimeOptionExact
};

@protocol XDFIJKMediaPlayback;

#pragma mark XDFIJKMediaPlayback

@protocol XDFIJKMediaPlayback <NSObject>

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (void)shutdown;
- (void)setPauseInBackground:(BOOL)pause;

- (void)setEnableSEI:(BOOL)enable;

// XDFVideoInfo
- (NSString *)xdf_vdec;
- (float)xdf_decode_vfps;
- (float)xdf_render_vfps;
- (int64_t)xdf_bit_rate;
- (int64_t)xdf_tcp_speed;
- (int64_t)xdf_latest_seek_load_duration;

@property(nonatomic, strong, readonly) NSMutableArray *cropGLViewArray;

@property(nonatomic, readonly)  UIView *view;
@property(nonatomic)            NSTimeInterval currentPlaybackTime;
@property(nonatomic, readonly)  NSTimeInterval duration;
@property(nonatomic, readonly)  NSTimeInterval playableDuration;
@property(nonatomic, readonly)  NSInteger bufferingProgress;

@property(nonatomic, readonly)  BOOL isPreparedToPlay;
@property(nonatomic, readonly)  XDFIJKMPMoviePlaybackState playbackState;
@property(nonatomic, readonly)  XDFIJKMPMovieLoadState loadState;
@property(nonatomic, readonly) int isSeekBuffering;
@property(nonatomic, readonly) int isAudioSync;
@property(nonatomic, readonly) int isVideoSync;

@property(nonatomic, readonly) int64_t numberOfBytesTransferred;

@property(nonatomic, readonly) CGSize naturalSize;
@property(nonatomic) XDFIJKMPMovieScalingMode scalingMode;
@property(nonatomic) BOOL shouldAutoplay;

@property (nonatomic) BOOL allowsMediaAirPlay;
@property (nonatomic) BOOL isDanmakuMediaAirPlay;
@property (nonatomic, readonly) BOOL airPlayMediaActive;

@property (nonatomic) float playbackRate;
@property (nonatomic) float playbackVolume;

- (UIImage *)thumbnailImageAtCurrentTime;

#pragma mark Notifications

#ifdef __cplusplus
#define XDFIJK_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define XDFIJK_EXTERN extern __attribute__((visibility ("default")))
#endif

// -----------------------------------------------------------------------------
//  MPMediaPlayback.h

// Posted when the prepared state changes of an object conforming to the MPMediaPlayback protocol changes.
// This supersedes MPMoviePlayerContentPreloadDidFinishNotification.
XDFIJK_EXTERN NSString *const XDFIJKMPMediaPlaybackIsPreparedToPlayDidChangeNotification;

// -----------------------------------------------------------------------------
//  MPMoviePlayerController.h
//  Movie Player Notifications

// Posted when the scaling mode changes.
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerScalingModeDidChangeNotification;

// Posted when movie playback ends or a user exits playback.
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerPlaybackDidFinishNotification;
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerPlaybackDidFinishReasonUserInfoKey; // NSNumber (XDFIJKMPMovieFinishReason)

// Posted when the playback state changes, either programatically or by the user.
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerPlaybackStateDidChangeNotification;

// Posted when the network load state changes.
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerLoadStateDidChangeNotification;

// Posted when the movie player begins or ends playing video via AirPlay.
XDFIJK_EXTERN NSString* const XDFIJKMPMoviePlayerIsAirPlayVideoActiveDidChangeNotification;

// -----------------------------------------------------------------------------
// Movie Property Notifications

// Calling -prepareToPlay on the movie player will begin determining movie properties asynchronously.
// These notifications are posted when the associated movie property becomes available.
XDFIJK_EXTERN NSString* const XDFIJKMPMovieNaturalSizeAvailableNotification;

// -----------------------------------------------------------------------------
//  Extend Notifications

XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerVideoDecoderOpenNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerFirstVideoFrameRenderedNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerFirstAudioFrameRenderedNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerFirstAudioFrameDecodedNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerFirstVideoFrameDecodedNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerOpenInputNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerFindStreamInfoNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerComponentOpenNotification;

XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerDidSeekCompleteNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerDidSeekCompleteTargetKey;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerDidSeekCompleteErrorKey;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerDidAccurateSeekCompleteCurPos;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerAccurateSeekCompleteNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerSeekAudioStartNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerSeekVideoStartNotification;

XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerDidDecodeSEIInfoNotification;
XDFIJK_EXTERN NSString *const XDFIJKMPMoviePlayerOnFrameCropRectInvalidNotification;

@end

#pragma mark XDFIJKMediaUrlOpenDelegate

// Must equal to the defination in ijkavformat/ijkavformat.h
typedef NS_ENUM(NSInteger, XDFIJKMediaEvent) {

    // Notify Events
    XDFIJKMediaEvent_WillHttpOpen         = 1,       // attr: url
    XDFIJKMediaEvent_DidHttpOpen          = 2,       // attr: url, error, http_code
    XDFIJKMediaEvent_WillHttpSeek         = 3,       // attr: url, offset
    XDFIJKMediaEvent_DidHttpSeek          = 4,       // attr: url, offset, error, http_code
    // Control Message
    XDFIJKMediaCtrl_WillTcpOpen           = 0x20001, // XDFIJKMediaUrlOpenData: no args
    XDFIJKMediaCtrl_DidTcpOpen            = 0x20002, // XDFIJKMediaUrlOpenData: error, family, ip, port, fd
    XDFIJKMediaCtrl_WillHttpOpen          = 0x20003, // XDFIJKMediaUrlOpenData: url, segmentIndex, retryCounter
    XDFIJKMediaCtrl_WillLiveOpen          = 0x20005, // XDFIJKMediaUrlOpenData: url, retryCounter
    XDFIJKMediaCtrl_WillConcatSegmentOpen = 0x20007, // XDFIJKMediaUrlOpenData: url, segmentIndex, retryCounter
};

#define XDFIJKMediaEventAttrKey_url            @"url"
#define XDFIJKMediaEventAttrKey_host           @"host"
#define XDFIJKMediaEventAttrKey_error          @"error"
#define XDFIJKMediaEventAttrKey_time_of_event  @"time_of_event"
#define XDFIJKMediaEventAttrKey_http_code      @"http_code"
#define XDFIJKMediaEventAttrKey_offset         @"offset"
#define XDFIJKMediaEventAttrKey_file_size      @"file_size"

// event of XDFIJKMediaUrlOpenEvent_xxx
@interface XDFIJKMediaUrlOpenData: NSObject

- (id)initWithUrl:(NSString *)url
            event:(XDFIJKMediaEvent)event
     segmentIndex:(int)segmentIndex
     retryCounter:(int)retryCounter;

@property(nonatomic, readonly) XDFIJKMediaEvent event;
@property(nonatomic, readonly) int segmentIndex;
@property(nonatomic, readonly) int retryCounter;

@property(nonatomic, retain) NSString *url;
@property(nonatomic, assign) int fd;
@property(nonatomic, strong) NSString *msg;
@property(nonatomic) int error; // set a negative value to indicate an error has occured.
@property(nonatomic, getter=isHandled)    BOOL handled;     // auto set to YES if url changed
@property(nonatomic, getter=isUrlChanged) BOOL urlChanged;  // auto set to YES by url changed

@end

@protocol XDFIJKMediaUrlOpenDelegate <NSObject>

- (void)willOpenUrl:(XDFIJKMediaUrlOpenData*) urlOpenData;

@end

@protocol XDFIJKMediaNativeInvokeDelegate <NSObject>

- (int)invoke:(XDFIJKMediaEvent)event attributes:(NSDictionary *)attributes;

@end
