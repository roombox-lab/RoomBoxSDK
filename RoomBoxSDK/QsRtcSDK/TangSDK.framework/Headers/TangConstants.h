//
//  TangConstants.h
//  TangRtcEngineKit
//
//  Copyright (c) 2018 Tang. All rights reserved.
//
#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

/** The standard bitrate set in [setVideoEncoderConfiguration]([TangRtcEngineKit setVideoEncoderConfiguration:]).

(Recommended) The standard bitrate mode. In this mode, the bitrate under the live broadcast and communication profiles differs:

    - Communication profile: The video bitrate is the same as the base bitrate.
    - Live broadcast profile: The video bitrate is twice the base bitrate.
 */
extern NSInteger const TangVideoBitrateStandard;

/** The compatible bitrate set in [setVideoEncoderConfiguration]([TangRtcEngineKit setVideoEncoderConfiguration:]).

The compatible bitrate mode. In this mode, the bitrate stays the same regardless of the channel profile. In a live broadcast channel, if you choose this mode, the video frame rate may be lower than the set value.
 */
extern NSInteger const TangVideoBitrateCompatible;

/** Use the default minimum bitrate.
 */
extern NSInteger const TangVideoBitrateDefaultMin;

/** 120 &times; 120
 */
extern CGSize const TangVideoDimension120x120;
/** 160 &times; 120
 */
extern CGSize const TangVideoDimension160x120;
/** 180 &times; 180
 */
extern CGSize const TangVideoDimension180x180;
/** 240 &times; 180
 */
extern CGSize const TangVideoDimension240x180;
/** 320 &times; 180
 */
extern CGSize const TangVideoDimension320x180;
/** 240 &times; 240
 */
extern CGSize const TangVideoDimension240x240;
/** 320 &times; 240
 */
extern CGSize const TangVideoDimension320x240;
/** 424 &times; 240
 */
extern CGSize const TangVideoDimension424x240;
/** 360 &times; 360
 */
extern CGSize const TangVideoDimension360x360;
/** 480 &times; 360
 */
extern CGSize const TangVideoDimension480x360;
/** 640 &times; 360
 */
extern CGSize const TangVideoDimension640x360;
/** 480 &times; 480
 */
extern CGSize const TangVideoDimension480x480;
/** 640 &times; 480
 */
extern CGSize const TangVideoDimension640x480;
/** 840 &times; 480
 */
extern CGSize const TangVideoDimension840x480;
/** 960 &times; 720 (Hardware dependent)
 */
extern CGSize const TangVideoDimension960x720;
/** 1280 &times; 720 (Hardware dependent)
 */
extern CGSize const TangVideoDimension1280x720;
#if TARGET_OS_MAC && !TARGET_OS_IPHONE
/** 1920 &times; 1080 (Hardware dependent, macOS only)
 */
extern CGSize const TangVideoDimension1920x1080;
/** 25400 &times; 1440 (Hardware dependent, macOS only)
 */
extern CGSize const TangVideoDimension2540x1440;
/** 3840 &times; 2160 (Hardware dependent, macOS only)
 */
extern CGSize const TangVideoDimension3840x2160;



#endif

typedef NS_ENUM(NSUInteger, TangViewOrientationFixedState) {
    TangViewOrientationNone = 0,
    TangViewOrientationFixedLandScape = 1,
    TangViewOrientationFixedPortrait = 2,
};
