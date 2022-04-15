//
//  TangRtcEngine SDK
//
//  Copyright (c) 2019 tang.io. All rights reserved.
//

/**
 @defgroup createTangRtcEngine Create an TangRtcEngine
 */

#ifndef TANG_RTC_ENGINE_H
#define TANG_RTC_ENGINE_H
#include "TangBase.hpp"
#include "ITangMediaEngine.hpp"

using namespace tang::media;

namespace tang {
namespace rtc {
	typedef unsigned int uid_t;
	typedef void* view_t;
	/** Maximum length of the device ID.
	*/
	enum MAX_DEVICE_ID_LENGTH_TYPE
	{
		/** The maximum length of the device ID is 512 bytes.
		*/
		MAX_DEVICE_ID_LENGTH = 512
	};
	/** Maximum length of user account.
	 */
	enum MAX_USER_ACCOUNT_LENGTH_TYPE
	{
		/** The maximum length of user account is 255 bytes.
		 */
		MAX_USER_ACCOUNT_LENGTH = 256
	};
	/** Maximum length of channel id.
	 */
	enum MAX_CHANNEL_ID_LENGTH_TYPE
	{
		/** The maximum length of channel id is 64 bytes.
		 */
		MAX_CHANNEL_ID_LENGTH = 65
	};
	/** Formats of the quality report.
	*/
	enum QUALITY_REPORT_FORMAT_TYPE
	{
		/** 0: The quality report in JSON format,
		*/
		QUALITY_REPORT_JSON = 0,
		/** 1: The quality report in HTML format.
		*/
		QUALITY_REPORT_HTML = 1,
	};

	enum MEDIA_ENGINE_EVENT_CODE_TYPE
	{
		/** 0: For internal use only.
		 */
		MEDIA_ENGINE_RECORDING_ERROR = 0,
		/** 1: For internal use only.
		 */
		MEDIA_ENGINE_PLAYOUT_ERROR = 1,
		/** 2: For internal use only.
		 */
		MEDIA_ENGINE_RECORDING_WARNING = 2,
		/** 3: For internal use only.
		 */
		MEDIA_ENGINE_PLAYOUT_WARNING = 3,
		/** 10: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_FILE_MIX_FINISH = 10,
		/** 12: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_FAREND_MUSIC_BEGINS = 12,
		/** 13: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_FAREND_MUSIC_ENDS = 13,
		/** 14: For internal use only.
		 */
		MEDIA_ENGINE_LOCAL_AUDIO_RECORD_ENABLED = 14,
		/** 15: For internal use only.
		 */
		MEDIA_ENGINE_LOCAL_AUDIO_RECORD_DISABLED = 15,
		// media engine role changed
		/** 20: For internal use only.
		 */
		MEDIA_ENGINE_ROLE_BROADCASTER_SOLO = 20,
		/** 21: For internal use only.
		 */
		MEDIA_ENGINE_ROLE_BROADCASTER_INTERACTIVE = 21,
		/** 22: For internal use only.
		 */
		MEDIA_ENGINE_ROLE_AUDIENCE = 22,
		/** 23: For internal use only.
		 */
		MEDIA_ENGINE_ROLE_COMM_PEER = 23,
		/** 24: For internal use only.
		 */
		MEDIA_ENGINE_ROLE_GAME_PEER = 24,
		// iOS adm sample rate changed
		/** 110: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ADM_REQUIRE_RESTART = 110,
		/** 111: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ADM_SPECIAL_RESTART = 111,
		/** 112: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ADM_USING_COMM_PARAMS = 112,
		/** 113: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ADM_USING_NORM_PARAMS = 113,
		// audio mix state
		/** 710: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_PLAY = 710,
		/** 711: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_PAUSED = 711,
		/** 712: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_RESTART = 712,
		/** 713: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_STOPPED = 713,
		/** 714: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_ERROR = 714,
		//Mixing error codes
		/** 701: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_OPEN = 701,
		/** 702: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_TOO_FREQUENT = 702,
		/** 703: The audio mixing file playback is interrupted. For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_INTERRUPTED_EOF = 703,
		/** 0: For internal use only.
		 */
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_NO_ERROR = 0,
	};

	/** The states of the local user's audio mixing file.
	*/
	enum AUDIO_MIXING_STATE_TYPE {
		/** 710: The audio mixing file is playing.
		*/
		AUDIO_MIXING_STATE_PLAYING = 710,
		/** 711: The audio mixing file pauses playing.
		*/
		AUDIO_MIXING_STATE_PAUSED = 711,
		/** 713: The audio mixing file stops playing.
		*/
		AUDIO_MIXING_STATE_STOPPED = 713,
		/** 714: An exception occurs when playing the audio mixing file. See #AUDIO_MIXING_ERROR_TYPE.
		*/
		AUDIO_MIXING_STATE_FAILED = 714,
	};

	/** The error codes of the local user's audio mixing file.
	*/
	enum AUDIO_MIXING_ERROR_TYPE {
		/** 701: The SDK cannot open the audio mixing file.
		*/
		AUDIO_MIXING_ERROR_CAN_NOT_OPEN = 701,
		/** 702: The SDK opens the audio mixing file too frequently.
		*/
		AUDIO_MIXING_ERROR_TOO_FREQUENT_CALL = 702,
		/** 703: The audio mixing file playback is interrupted.
		 */
		AUDIO_MIXING_ERROR_INTERRUPTED_EOF = 703,
		/** 0: The SDK can open the audio mixing file.
		*/
		AUDIO_MIXING_ERROR_OK = 0,
	};

	enum XLA_EXP_NET_POOR_REASON {
		XLA_EXP_NET_REMOTE_POOR = 1,
		XLA_EXP_NET_GATWAYRTT_POOR = 2,
		XLA_EXP_NET_WANRTT_POOR = 4,
		XLA_EXP_NET_VOSRTT_POOR = 8,
		XLA_EXP_NET_LINKSPEED_POOR = 16,
		XLA_EXP_NET_RSSI_POOR = 32,
		XLA_EXP_NET_WIFI_BLUETOOTH_COEXIST = 64,
	};

	/** Media device states.
	 */
	enum MEDIA_DEVICE_STATE_TYPE
	{
		/** 0: The device plugged
		*/
		MEDIA_DEVICE_STATE_PLUGGED = 0,
		/** 1: The device is active.
		*/
		MEDIA_DEVICE_STATE_ACTIVE = 1,
		/** 2: The device is disabled.
		*/
		MEDIA_DEVICE_STATE_DISABLED = 2,
		/** 4: The device is not present.
		*/
		MEDIA_DEVICE_STATE_NOT_PRESENT = 4,
		/** 8: The device is unplugged.
		*/
		MEDIA_DEVICE_STATE_UNPLUGGED = 8
	};

	/** Media device types.
	 */
	enum MEDIA_DEVICE_TYPE
	{
		/** -1: Unknown device type.
		*/
		UNKNOWN_AUDIO_DEVICE = -1,
		/** 0: Audio playback device.
		*/
		AUDIO_PLAYOUT_DEVICE = 0,
		/** 1: Audio recording device.
		*/
		AUDIO_RECORDING_DEVICE = 1,
		/** 2: Video renderer.
		*/
		VIDEO_RENDER_DEVICE = 2,
		/** 3: Video capturer.
		*/
		VIDEO_CAPTURE_DEVICE = 3,
		/** 4: Application audio playback device.
		*/
		AUDIO_APPLICATION_PLAYOUT_DEVICE = 4,
	};

	/** Local video state types
	 */
	enum LOCAL_VIDEO_STREAM_STATE
	{
		/** Initial state */
		LOCAL_VIDEO_STREAM_STATE_STOPPED = 0,
		/** The capturer starts successfully. */
		LOCAL_VIDEO_STREAM_STATE_CAPTURING = 1,
		/** The first video frame is successfully encoded. */
		LOCAL_VIDEO_STREAM_STATE_ENCODING = 2,
		/** The local video fails to start. */
		LOCAL_VIDEO_STREAM_STATE_FAILED = 3
	};

	/** Local video state error codes
	 */
	enum LOCAL_VIDEO_STREAM_ERROR {
		/** The local video is normal. */
		LOCAL_VIDEO_STREAM_ERROR_OK = 0,
		/** No specified reason for the local video failure. */
		LOCAL_VIDEO_STREAM_ERROR_FAILURE = 1,
		/** No permission to use the local video device. */
		LOCAL_VIDEO_STREAM_ERROR_DEVICE_NO_PERMISSION = 2,
		/** The local video capturer is in use. */
		LOCAL_VIDEO_STREAM_ERROR_DEVICE_BUSY = 3,
		/** The local video capture fails. Check whether the capturer is working properly. */
		LOCAL_VIDEO_STREAM_ERROR_CAPTURE_FAILURE = 4,
		/** The local video encoding fails. */
		LOCAL_VIDEO_STREAM_ERROR_ENCODE_FAILURE = 5,
		/** No camera device. */
		LOCAL_VIDEO_STREAM_ERROR_DEVICE_NOT_FOUND = 6,
	};

	/** Local audio state types.
	 */
	enum LOCAL_AUDIO_STREAM_STATE
	{
		/** 0: The local audio is in the initial state.
		 */
		LOCAL_AUDIO_STREAM_STATE_STOPPED = 0,
		/** 1: The recording device starts successfully.
		 */
		LOCAL_AUDIO_STREAM_STATE_RECORDING = 1,
		/** 2: The first audio frame encodes successfully.
		 */
		LOCAL_AUDIO_STREAM_STATE_ENCODING = 2,
		/** 3: The local audio fails to start.
		 */
		LOCAL_AUDIO_STREAM_STATE_FAILED = 3
	};

	/** Local audio state error codes.
	 */
	enum LOCAL_AUDIO_STREAM_ERROR
	{
		/** 0: The local audio is normal.
		 */
		LOCAL_AUDIO_STREAM_ERROR_OK = 0,
		/** 1: No specified reason for the local audio failure.
		 */
		LOCAL_AUDIO_STREAM_ERROR_FAILURE = 1,
		/** 2: No permission to use the local audio device.
		 */
		LOCAL_AUDIO_STREAM_ERROR_DEVICE_NO_PERMISSION = 2,
		/** 3: The microphone is in use.
		 */
		LOCAL_AUDIO_STREAM_ERROR_DEVICE_BUSY = 3,
		/** 4: The local audio recording fails. Check whether the recording device
		 * is working properly.
		 */
		LOCAL_AUDIO_STREAM_ERROR_RECORD_FAILURE = 4,
		/** 5: The local audio encoding fails.
		 */
		LOCAL_AUDIO_STREAM_ERROR_ENCODE_FAILURE = 5,
		/** 6: No recording audio device.
		*/
		LOCAL_AUDIO_STREAM_ERROR_NO_RECORDING_DEVICE = 6,
		/** 7: No playout audio device.
		*/
		LOCAL_AUDIO_STREAM_ERROR_NO_PLAYOUT_DEVICE = 7
	};

	/** Audio recording qualities.
	*/
	enum AUDIO_RECORDING_QUALITY_TYPE
	{
		/** 0: Low quality. The sample rate is 32 kHz, and the file size is around
		 * 1.2 MB after 10 minutes of recording.
		*/
		AUDIO_RECORDING_QUALITY_LOW = 0,
		/** 1: Medium quality. The sample rate is 32 kHz, and the file size is
		 * around 2 MB after 10 minutes of recording.
		*/
		AUDIO_RECORDING_QUALITY_MEDIUM = 1,
		/** 2: High quality. The sample rate is 32 kHz, and the file size is
		 * around 3.75 MB after 10 minutes of recording.
		*/
		AUDIO_RECORDING_QUALITY_HIGH = 2,
	};

	/** Network quality types. */
	enum QUALITY_TYPE
	{
		/** 0: The network quality is unknown. */
		QUALITY_UNKNOWN = 0,
		/**  1: The network quality is excellent. */
		QUALITY_EXCELLENT = 1,
		/** 2: The network quality is quite good, but the bitrate may be slightly lower than excellent. */
		QUALITY_GOOD = 2,
		/** 3: Users can feel the communication slightly impaired. */
		QUALITY_POOR = 3,
		/** 4: Users cannot communicate smoothly. */
		QUALITY_BAD = 4,
		/** 5: The network is so bad that users can barely communicate. */
		QUALITY_VBAD = 5,
		/** 6: The network is down and users cannot communicate at all. */
		QUALITY_DOWN = 6,
		/** 7: Users cannot detect the network quality. (Not in use.) */
		QUALITY_UNSUPPORTED = 7,
		/** 8: Detecting the network quality. */
		QUALITY_DETECTING = 8,
	};

	/** Video display modes. */
	enum RENDER_MODE_TYPE
	{
		/**
	  1: Uniformly scale the video until it fills the visible boundaries (cropped). One dimension of the video may have clipped contents.
	   */
		RENDER_MODE_HIDDEN = 1,
		/**
	2: Uniformly scale the video until one of its dimension fits the boundary (zoomed to fit). Areas that are not filled due to disparity in the aspect ratio are filled with black.
	 */
		RENDER_MODE_FIT = 2,
		/** **DEPRECATED** 3: This mode is deprecated.
		 */
		RENDER_MODE_ADAPTIVE = 3,
	};

	/** Video mirror modes. */
	enum VIDEO_MIRROR_MODE_TYPE
	{
		/** 0: The default mirror mode is determined by the SDK. */
		VIDEO_MIRROR_MODE_AUTO = 0,//determined by SDK
		/** 1: Enable mirror mode. */
		VIDEO_MIRROR_MODE_ENABLED = 1,//enabled mirror
		/** 2: Disable mirror mode. */
		VIDEO_MIRROR_MODE_DISABLED = 2,//disable mirror
		/** 2: mirror updown enable*/
		VIDEO_MIRROR_MODE_UPDOWN_ENABLED = 3,
		/** 2: mirror updown disable. */
		VIDEO_MIRROR_MODE_UPDOWN_DISABLED
	};

	/** **DEPRECATED** Video profiles. */
	enum VIDEO_PROFILE_TYPE
	{
		/** 0: 160 &times; 120, frame rate 15 fps, bitrate 65 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_120P = 0,
		/** 2: 120 &times; 120, frame rate 15 fps, bitrate 50 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_120P_3 = 2,
		/** 10: 320&times;180, frame rate 15 fps, bitrate 140 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_180P = 10,
		/** 12: 180 &times; 180, frame rate 15 fps, bitrate 100 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_180P_3 = 12,
		/** 13: 240 &times; 180, frame rate 15 fps, bitrate 120 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_180P_4 = 13,
		/** 20: 320 &times; 240, frame rate 15 fps, bitrate 200 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_240P = 20,
		/** 22: 240 &times; 240, frame rate 15 fps, bitrate 140 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_240P_3 = 22,
		/** 23: 424 &times; 240, frame rate 15 fps, bitrate 220 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_240P_4 = 23,
		/** 30: 640 &times; 360, frame rate 15 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P = 30,
		/** 32: 360 &times; 360, frame rate 15 fps, bitrate 260 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P_3 = 32,
		/** 33: 640 &times; 360, frame rate 30 fps, bitrate 600 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P_4 = 33,
		/** 35: 360 &times; 360, frame rate 30 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P_6 = 35,
		/** 36: 480 &times; 360, frame rate 15 fps, bitrate 320 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P_7 = 36,
		/** 37: 480 &times; 360, frame rate 30 fps, bitrate 490 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_360P_8 = 37,
		/** 38: 640 &times; 360, frame rate 15 fps, bitrate 800 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_LANDSCAPE_360P_9 = 38,
		/** 39: 640 &times; 360, frame rate 24 fps, bitrate 800 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_LANDSCAPE_360P_10 = 39,
		/** 100: 640 &times; 360, frame rate 24 fps, bitrate 1000 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_LANDSCAPE_360P_11 = 100,
		/** 40: 640 &times; 480, frame rate 15 fps, bitrate 500 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P = 40,
		/** 42: 480 &times; 480, frame rate 15 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_3 = 42,
		/** 43: 640 &times; 480, frame rate 30 fps, bitrate 750 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_4 = 43,
		/** 45: 480 &times; 480, frame rate 30 fps, bitrate 600 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_6 = 45,
		/** 47: 848 &times; 480, frame rate 15 fps, bitrate 610 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_8 = 47,
		/** 48: 848 &times; 480, frame rate 30 fps, bitrate 930 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_9 = 48,
		/** 49: 640 &times; 480, frame rate 10 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_480P_10 = 49,
		/** 50: 1280 &times; 720, frame rate 15 fps, bitrate 1130 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_720P = 50,
		/** 52: 1280 &times; 720, frame rate 30 fps, bitrate 1710 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_720P_3 = 52,
		/** 54: 960 &times; 720, frame rate 15 fps, bitrate 910 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_720P_5 = 54,
		/** 55: 960 &times; 720, frame rate 30 fps, bitrate 1380 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_720P_6 = 55,
		/** 60: 1920 &times; 1080, frame rate 15 fps, bitrate 2080 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_1080P = 60,
		/** 62: 1920 &times; 1080, frame rate 30 fps, bitrate 3150 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_1080P_3 = 62,
		/** 64: 1920 &times; 1080, frame rate 60 fps, bitrate 4780 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_1080P_5 = 64,
		/** 66: 2560 &times; 1440, frame rate 30 fps, bitrate 4850 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_1440P = 66,
		/** 67: 2560 &times; 1440, frame rate 60 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_1440P_2 = 67,
		/** 70: 3840 &times; 2160, frame rate 30 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_4K = 70,
		/** 72: 3840 &times; 2160, frame rate 60 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_LANDSCAPE_4K_3 = 72,
		/** 1000: 120 &times; 160, frame rate 15 fps, bitrate 65 Kbps. */
		VIDEO_PROFILE_PORTRAIT_120P = 1000,
		/** 1002: 120 &times; 120, frame rate 15 fps, bitrate 50 Kbps. */
		VIDEO_PROFILE_PORTRAIT_120P_3 = 1002,
		/** 1010: 180 &times; 320, frame rate 15 fps, bitrate 140 Kbps. */
		VIDEO_PROFILE_PORTRAIT_180P = 1010,
		/** 1012: 180 &times; 180, frame rate 15 fps, bitrate 100 Kbps. */
		VIDEO_PROFILE_PORTRAIT_180P_3 = 1012,
		/** 1013: 180 &times; 240, frame rate 15 fps, bitrate 120 Kbps. */
		VIDEO_PROFILE_PORTRAIT_180P_4 = 1013,
		/** 1020: 240 &times; 320, frame rate 15 fps, bitrate 200 Kbps. */
		VIDEO_PROFILE_PORTRAIT_240P = 1020,
		/** 1022: 240 &times; 240, frame rate 15 fps, bitrate 140 Kbps. */
		VIDEO_PROFILE_PORTRAIT_240P_3 = 1022,
		/** 1023: 240 &times; 424, frame rate 15 fps, bitrate 220 Kbps. */
		VIDEO_PROFILE_PORTRAIT_240P_4 = 1023,
		/** 1030: 360 &times; 640, frame rate 15 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P = 1030,
		/** 1032: 360 &times; 360, frame rate 15 fps, bitrate 260 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P_3 = 1032,
		/** 1033: 360 &times; 640, frame rate 30 fps, bitrate 600 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P_4 = 1033,
		/** 1035: 360 &times; 360, frame rate 30 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P_6 = 1035,
		/** 1036: 360 &times; 480, frame rate 15 fps, bitrate 320 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P_7 = 1036,
		/** 1037: 360 &times; 480, frame rate 30 fps, bitrate 490 Kbps. */
		VIDEO_PROFILE_PORTRAIT_360P_8 = 1037,
		/** 1038: 360 &times; 640, frame rate 15 fps, bitrate 800 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_PORTRAIT_360P_9 = 1038,
		/** 1039: 360 &times; 640, frame rate 24 fps, bitrate 800 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_PORTRAIT_360P_10 = 1039,
		/** 1100: 360 &times; 640, frame rate 24 fps, bitrate 1000 Kbps.
		 @note Live broadcast profile only.
		 */
		VIDEO_PROFILE_PORTRAIT_360P_11 = 1100,
		/** 1040: 480 &times; 640, frame rate 15 fps, bitrate 500 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P = 1040,
		/** 1042: 480 &times; 480, frame rate 15 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_3 = 1042,
		/** 1043: 480 &times; 640, frame rate 30 fps, bitrate 750 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_4 = 1043,
		/** 1045: 480 &times; 480, frame rate 30 fps, bitrate 600 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_6 = 1045,
		/** 1047: 480 &times; 848, frame rate 15 fps, bitrate 610 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_8 = 1047,
		/** 1048: 480 &times; 848, frame rate 30 fps, bitrate 930 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_9 = 1048,
		/** 1049: 480 &times; 640, frame rate 10 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_PORTRAIT_480P_10 = 1049,
		/** 1050: 720 &times; 1280, frame rate 15 fps, bitrate 1130 Kbps. */
		VIDEO_PROFILE_PORTRAIT_720P = 1050,
		/** 1052: 720 &times; 1280, frame rate 30 fps, bitrate 1710 Kbps. */
		VIDEO_PROFILE_PORTRAIT_720P_3 = 1052,
		/** 1054: 720 &times; 960, frame rate 15 fps, bitrate 910 Kbps. */
		VIDEO_PROFILE_PORTRAIT_720P_5 = 1054,
		/** 1055: 720 &times; 960, frame rate 30 fps, bitrate 1380 Kbps. */
		VIDEO_PROFILE_PORTRAIT_720P_6 = 1055,
		/** 1060: 1080 &times; 1920, frame rate 15 fps, bitrate 2080 Kbps. */
		VIDEO_PROFILE_PORTRAIT_1080P = 1060,
		/** 1062: 1080 &times; 1920, frame rate 30 fps, bitrate 3150 Kbps. */
		VIDEO_PROFILE_PORTRAIT_1080P_3 = 1062,
		/** 1064: 1080 &times; 1920, frame rate 60 fps, bitrate 4780 Kbps. */
		VIDEO_PROFILE_PORTRAIT_1080P_5 = 1064,
		/** 1066: 1440 &times; 2560, frame rate 30 fps, bitrate 4850 Kbps. */
		VIDEO_PROFILE_PORTRAIT_1440P = 1066,
		/** 1067: 1440 &times; 2560, frame rate 60 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_PORTRAIT_1440P_2 = 1067,
		/** 1070: 2160 &times; 3840, frame rate 30 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_PORTRAIT_4K = 1070,
		/** 1072: 2160 &times; 3840, frame rate 60 fps, bitrate 6500 Kbps. */
		VIDEO_PROFILE_PORTRAIT_4K_3 = 1072,
		/** Default 640 &times; 360, frame rate 15 fps, bitrate 400 Kbps. */
		VIDEO_PROFILE_DEFAULT = VIDEO_PROFILE_LANDSCAPE_360P,
	};

	/** Audio profiles.

	Sets the sample rate, bitrate, encoding mode, and the number of channels:*/
	enum AUDIO_PROFILE_TYPE // sample rate, bit rate, mono/stereo, speech/music codec
	{
		/**
		 0: Default audio profile.

		 - In the Communication profile, the default value is #AUDIO_PROFILE_SPEECH_STANDARD;
		 - In the Live-broadcast profile, the default value is #AUDIO_PROFILE_MUSIC_STANDARD.
		 */
		AUDIO_PROFILE_DEFAULT = 0, // use default settings
		/**
		 1: A sample rate of 32 kHz, audio encoding, mono, and a bitrate of up to 18 Kbps.
		 */
		AUDIO_PROFILE_SPEECH_STANDARD = 1, // 32Khz, 18Kbps, mono, speech
		/**
		 2: A sample rate of 48 kHz, music encoding, mono, and a bitrate of up to 48 Kbps.
		 */
		AUDIO_PROFILE_MUSIC_STANDARD = 2, // 48Khz, 48Kbps, mono, music
		/**
		 3: A sample rate of 48 kHz, music encoding, stereo, and a bitrate of up to 56 Kbps.
		 */
		AUDIO_PROFILE_MUSIC_STANDARD_STEREO = 3, // 48Khz, 56Kbps, stereo, music
		/**
		 4: A sample rate of 48 kHz, music encoding, mono, and a bitrate of up to 128 Kbps.
		 */
		AUDIO_PROFILE_MUSIC_HIGH_QUALITY = 4, // 48Khz, 128Kbps, mono, music
		/**
		 5: A sample rate of 48 kHz, music encoding, stereo, and a bitrate of up to 192 Kbps.
		 */
		AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO = 5, // 48Khz, 192Kbps, stereo, music
		/**
		 6: A sample rate of 16 kHz, audio encoding, mono, and Acoustic Echo Cancellation (AES) enabled.
		 */
		AUDIO_PROFILE_IOT = 6,
		AUDIO_PROFILE_NUM = 7,
	};

	/** Audio application scenarios.
	*/
	enum AUDIO_SCENARIO_TYPE // set a suitable scenario for your app type
	{
		/** 0: Default. */
		AUDIO_SCENARIO_DEFAULT = 0,
		/** 1: Entertainment scenario, supporting voice during gameplay. */
		AUDIO_SCENARIO_CHATROOM_ENTERTAINMENT = 1,
		/** 2: Education scenario, prioritizing smoothness and stability. */
		AUDIO_SCENARIO_EDUCATION = 2,
		/** 3: Live gaming scenario, enabling the gaming audio effects in the speaker mode in a live broadcast scenario. Choose this scenario for high-fidelity music playback. */
		AUDIO_SCENARIO_GAME_STREAMING = 3,
		/** 4: Showroom scenario, optimizing the audio quality with external professional equipment. */
		AUDIO_SCENARIO_SHOWROOM = 4,
		/** 5: Gaming scenario. */
		AUDIO_SCENARIO_CHATROOM_GAMING = 5,
		/** 6: Applicable to the IoT scenario. */
		AUDIO_SCENARIO_IOT = 6,
		AUDIO_SCENARIO_NUM = 7,
	};

	/** Channel profiles.
	*/
	enum CHANNEL_PROFILE_TYPE
	{
		/** 0: Communication.

		 This is used in one-on-one calls or group calls, where all users in the channel can talk freely.
		 */
		CHANNEL_PROFILE_COMMUNICATION = 0,
		/** 1: Live Broadcast.

		 Host and audience roles that can be set by calling the \ref IRtcEngine::setClientRole "setClientRole" method. The host sends and receives voice, while the audience receives voice only with the sending function disabled.
		 */
		CHANNEL_PROFILE_LIVE_BROADCASTING = 1,
		/** 2: Gaming.

		 @note This profile applies to the tang Gaming SDK only.

		 Any user in the channel can talk freely. This mode uses the codec with low-power consumption and low bitrate by default.
		 */
		CHANNEL_PROFILE_GAME = 2,
	};

	/** Client roles in a live broadcast. */
	enum CLIENT_ROLE_TYPE
	{
		/** 1: Host */
		CLIENT_ROLE_BROADCASTER = 1,
		/** 2: Audience */
		CLIENT_ROLE_AUDIENCE = 2,
	};

	/** Reasons for a user being offline. */
	enum USER_OFFLINE_REASON_TYPE
	{
		/** 0: The user quits the call. */
		USER_OFFLINE_QUIT = 0,
		/** 1: The SDK times out and the user drops offline because no data packet is received within a certain period of time. If the user quits the call and the message is not passed to the SDK (due to an unreliable channel), the SDK assumes the user dropped offline. */
		USER_OFFLINE_DROPPED = 1,
		/** 2: (Live broadcast only.) The client role switched from the host to the audience. */
		USER_OFFLINE_BECOME_AUDIENCE = 2,
	};
	/**
	 States of the RTMP streaming.
	 */
	enum RTMP_STREAM_PUBLISH_STATE
	{
		/** The RTMP streaming has not started or has ended. This state is also triggered after you remove an RTMP address from the CDN by calling removePublishStreamUrl.
		 */
		RTMP_STREAM_PUBLISH_STATE_IDLE = 0,
		/** The SDK is connecting to tang's streaming server and the RTMP server. This state is triggered after you call the \ref IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" method.
		 */
		RTMP_STREAM_PUBLISH_STATE_CONNECTING = 1,
		/** The RTMP streaming publishes. The SDK successfully publishes the RTMP streaming and returns this state.
		 */
		RTMP_STREAM_PUBLISH_STATE_RUNNING = 2,
		/** The RTMP streaming is recovering. When exceptions occur to the CDN, or the streaming is interrupted, the SDK tries to resume RTMP streaming and returns this state.

		 - If the SDK successfully resumes the streaming, #RTMP_STREAM_PUBLISH_STATE_RUNNING (2) returns.
		 - If the streaming does not resume within 60 seconds or server errors occur, #RTMP_STREAM_PUBLISH_STATE_FAILURE (4) returns. You can also reconnect to the server by calling the \ref IRtcEngine::removePublishStreamUrl "removePublishStreamUrl" and \ref IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" methods.
		 */
		RTMP_STREAM_PUBLISH_STATE_RECOVERING = 3,
		/** The RTMP streaming fails. See the errCode parameter for the detailed error information. You can also call the \ref IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" method to publish the RTMP streaming again.
		 */
		RTMP_STREAM_PUBLISH_STATE_FAILURE = 4,
	};

	/**
	 Error codes of the RTMP streaming.
	 */
	enum RTMP_STREAM_PUBLISH_ERROR
	{
		/** The RTMP streaming publishes successfully. */
		RTMP_STREAM_PUBLISH_ERROR_OK = 0,
		/** Invalid argument used. If, for example, you do not call the \ref IRtcEngine::setLiveTranscoding "setLiveTranscoding" method to configure the LiveTranscoding parameters before calling the addPublishStreamUrl method, the SDK returns this error. Check whether you set the parameters in the *setLiveTranscoding* method properly. */
		RTMP_STREAM_PUBLISH_ERROR_INVALID_ARGUMENT = 1,
		/** The RTMP streaming is encrypted and cannot be published. */
		RTMP_STREAM_PUBLISH_ERROR_ENCRYPTED_STREAM_NOT_ALLOWED = 2,
		/** Timeout for the RTMP streaming. Call the \ref IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" method to publish the streaming again. */
		RTMP_STREAM_PUBLISH_ERROR_CONNECTION_TIMEOUT = 3,
		/** An error occurs in tang's streaming server. Call the addPublishStreamUrl method to publish the streaming again. */
		RTMP_STREAM_PUBLISH_ERROR_INTERNAL_SERVER_ERROR = 4,
		/** An error occurs in the RTMP server. */
		RTMP_STREAM_PUBLISH_ERROR_RTMP_SERVER_ERROR = 5,
		/** The RTMP streaming publishes too frequently. */
		RTMP_STREAM_PUBLISH_ERROR_TOO_OFTEN = 6,
		/** The host publishes more than 10 URLs. Delete the unnecessary URLs before adding new ones. */
		RTMP_STREAM_PUBLISH_ERROR_REACH_LIMIT = 7,
		/** The host manipulates other hosts' URLs. Check your app logic. */
		RTMP_STREAM_PUBLISH_ERROR_NOT_AUTHORIZED = 8,
		/** tang's server fails to find the RTMP streaming. */
		RTMP_STREAM_PUBLISH_ERROR_STREAM_NOT_FOUND = 9,
		/** The format of the RTMP streaming URL is not supported. Check whether the URL format is correct. */
		RTMP_STREAM_PUBLISH_ERROR_FORMAT_NOT_SUPPORTED = 10,
	};

	/** States of importing an external video stream in a live broadcast. */
	enum INJECT_STREAM_STATUS
	{
		/** 0: The external video stream imported successfully. */
		INJECT_STREAM_STATUS_START_SUCCESS = 0,
		/** 1: The external video stream already exists. */
		INJECT_STREAM_STATUS_START_ALREADY_EXISTS = 1,
		/** 2: The external video stream to be imported is unauthorized. */
		INJECT_STREAM_STATUS_START_UNAUTHORIZED = 2,
		/** 3: Import external video stream timeout. */
		INJECT_STREAM_STATUS_START_TIMEDOUT = 3,
		/** 4: Import external video stream failed. */
		INJECT_STREAM_STATUS_START_FAILED = 4,
		/** 5: The external video stream stopped importing successfully. */
		INJECT_STREAM_STATUS_STOP_SUCCESS = 5,
		/** 6: No external video stream is found. */
		INJECT_STREAM_STATUS_STOP_NOT_FOUND = 6,
		/** 7: The external video stream to be stopped importing is unauthorized. */
		INJECT_STREAM_STATUS_STOP_UNAUTHORIZED = 7,
		/** 8: Stop importing external video stream timeout. */
		INJECT_STREAM_STATUS_STOP_TIMEDOUT = 8,
		/** 9: Stop importing external video stream failed. */
		INJECT_STREAM_STATUS_STOP_FAILED = 9,
		/** 10: The external video stream is corrupted. */
		INJECT_STREAM_STATUS_BROKEN = 10,
	};
	/** Remote video stream types. */
	enum REMOTE_VIDEO_STREAM_TYPE
	{
		/** 0: High-stream video. */
		REMOTE_VIDEO_STREAM_HIGH = 0,
		/** 1: Low-stream video. */
		REMOTE_VIDEO_STREAM_LOW = 1,
	};

	/** Use modes of the \ref media::IAudioFrameObserver::onRecordAudioFrame "onRecordAudioFrame" callback. */
	enum RAW_AUDIO_FRAME_OP_MODE_TYPE
	{
		/** 0: Read-only mode: Users only read the \ref tang::media::IAudioFrameObserver::AudioFrame "AudioFrame" data without modifying anything. For example, when users acquire the data with the tang SDK, then push the RTMP streams. */
		RAW_AUDIO_FRAME_OP_MODE_READ_ONLY = 0,
		/** 1: Write-only mode: Users replace the \ref tang::media::IAudioFrameObserver::AudioFrame "AudioFrame" data with their own data and pass the data to the SDK for encoding. For example, when users acquire the data. */
		RAW_AUDIO_FRAME_OP_MODE_WRITE_ONLY = 1,
		/** 2: Read and write mode: Users read the data from \ref tang::media::IAudioFrameObserver::AudioFrame "AudioFrame", modify it, and then play it. For example, when users have their own sound-effect processing module and perform some voice pre-processing, such as a voice change. */
		RAW_AUDIO_FRAME_OP_MODE_READ_WRITE = 2,
	};

	/** Audio-sample rates. */
	enum AUDIO_SAMPLE_RATE_TYPE
	{
		/** 32000: 32 kHz */
		AUDIO_SAMPLE_RATE_32000 = 32000,
		/** 44100: 44.1 kHz */
		AUDIO_SAMPLE_RATE_44100 = 44100,
		/** 48000: 48 kHz */
		AUDIO_SAMPLE_RATE_48000 = 48000,
	};

	/** Video codec profile types. */
	enum VIDEO_CODEC_PROFILE_TYPE
	{  /** 66: Baseline video codec profile. Generally used in video calls on mobile phones. */
		VIDEO_CODEC_PROFILE_BASELINE = 66,
		/** 77: Main video codec profile. Generally used in mainstream electronics such as MP4 players, portable video players, PSP, and iPads. */
		VIDEO_CODEC_PROFILE_MAIN = 77,
		/** 100: (Default) High video codec profile. Generally used in high-resolution broadcasts or television. */
		VIDEO_CODEC_PROFILE_HIGH = 100,
	};

	/** Video codec types */
	enum VIDEO_CODEC_TYPE {
		/** Standard VP8 */
		VIDEO_CODEC_VP8 = 1,
		/** Standard H264 */
		VIDEO_CODEC_H264 = 2,
		/** Enhanced VP8 */
		VIDEO_CODEC_EVP = 3,
		/** Enhanced H264 */
		VIDEO_CODEC_E264 = 4,
	};

	/** Video Codec types. */
	enum VIDEO_CODEC_TRANSCODING_TYPE
	{
		VIDEO_CODEC_H264_TRANSCODING = 1,
		VIDEO_CODEC_H265_TRANSCODING = 2,
	};

	/** Audio equalization band frequencies. */
	enum AUDIO_EQUALIZATION_BAND_FREQUENCY
	{
		/** 0: 31 Hz */
		AUDIO_EQUALIZATION_BAND_31 = 0,
		/** 1: 62 Hz */
		AUDIO_EQUALIZATION_BAND_62 = 1,
		/** 2: 125 Hz */
		AUDIO_EQUALIZATION_BAND_125 = 2,
		/** 3: 250 Hz */
		AUDIO_EQUALIZATION_BAND_250 = 3,
		/** 4: 500 Hz */
		AUDIO_EQUALIZATION_BAND_500 = 4,
		/** 5: 1 kHz */
		AUDIO_EQUALIZATION_BAND_1K = 5,
		/** 6: 2 kHz */
		AUDIO_EQUALIZATION_BAND_2K = 6,
		/** 7: 4 kHz */
		AUDIO_EQUALIZATION_BAND_4K = 7,
		/** 8: 8 kHz */
		AUDIO_EQUALIZATION_BAND_8K = 8,
		/** 9: 16 kHz */
		AUDIO_EQUALIZATION_BAND_16K = 9,
	};

	/** Audio reverberation types. */
	enum AUDIO_REVERB_TYPE
	{
		/** 0: The level of the dry signal (db). The value is between -20 and 10. */
		AUDIO_REVERB_DRY_LEVEL = 0, // (dB, [-20,10]), the level of the dry signal
		/** 1: The level of the early reflection signal (wet signal) (dB). The value is between -20 and 10. */
		AUDIO_REVERB_WET_LEVEL = 1, // (dB, [-20,10]), the level of the early reflection signal (wet signal)
		/** 2: The room size of the reflection. The value is between 0 and 100. */
		AUDIO_REVERB_ROOM_SIZE = 2, // ([0,100]), the room size of the reflection
		/** 3: The length of the initial delay of the wet signal (ms). The value is between 0 and 200. */
		AUDIO_REVERB_WET_DELAY = 3, // (ms, [0,200]), the length of the initial delay of the wet signal in ms
		/** 4: The reverberation strength. The value is between 0 and 100. */
		AUDIO_REVERB_STRENGTH = 4, // ([0,100]), the strength of the reverberation
	};

	/** Local voice changer options. */
	enum VOICE_CHANGER_PRESET {
		/** 0: The original voice (no local voice change).
		*/
		VOICE_CHANGER_OFF = 0, //Turn off the voice changer
		/** 1: An old man's voice.
		*/
		VOICE_CHANGER_OLDMAN = 1,
		/** 2: A little boy's voice.
		*/
		VOICE_CHANGER_BABYBOY = 2,
		/** 3: A little girl's voice.
		*/
		VOICE_CHANGER_BABYGIRL = 3,
		/** 4: The voice of a growling bear.
		*/
		VOICE_CHANGER_ZHUBAJIE = 4,
		/** 5: Ethereal vocal effects.
		*/
		VOICE_CHANGER_ETHEREAL = 5,
		/** 6: Hulk's voice.
		*/
		VOICE_CHANGER_HULK = 6
	};

	/** Local voice reverberation presets. */
	enum AUDIO_REVERB_PRESET {
		/** 0: The original voice (no local voice reverberation).
		*/
		AUDIO_REVERB_OFF = 0, // Turn off audio reverb
		/** 1: Pop music.
		*/
		AUDIO_REVERB_POPULAR = 1,
		/** 2: R&B.
		*/
		AUDIO_REVERB_RNB = 2,
		/** 3: Rock music.
		*/
		AUDIO_REVERB_ROCK = 3,
		/** 4: Hip-hop.
		*/
		AUDIO_REVERB_HIPHOP = 4,
		/** 5: Pop concert.
		*/
		AUDIO_REVERB_VOCAL_CONCERT = 5,
		/** 6: Karaoke.
		*/
		AUDIO_REVERB_KTV = 6,
		/** 7: Recording studio.
		*/
		AUDIO_REVERB_STUDIO = 7
	};
	/** Audio codec profile types. The default value is LC_ACC. */
	enum AUDIO_CODEC_PROFILE_TYPE
	{
		/** 0: LC-AAC, which is the low-complexity audio codec type. */
		AUDIO_CODEC_PROFILE_LC_AAC = 0,
		/** 1: HE-AAC, which is the high-efficiency audio codec type. */
		AUDIO_CODEC_PROFILE_HE_AAC = 1,
	};

	/** Remote audio states.
	 */
	enum REMOTE_AUDIO_STATE
	{
		/** 0: The remote audio is in the default state, probably due to
		 * #REMOTE_AUDIO_REASON_LOCAL_MUTED (3),
		 * #REMOTE_AUDIO_REASON_REMOTE_MUTED (5), or
		 * #REMOTE_AUDIO_REASON_REMOTE_OFFLINE (7).
		 */
		REMOTE_AUDIO_STATE_STOPPED = 0,  // Default state, audio is started or remote user disabled/muted audio stream
		/** 1: The first remote audio packet is received.
		 */
		REMOTE_AUDIO_STATE_STARTING = 1,  // The first audio frame packet has been received
		/** 2: The remote audio stream is decoded and plays normally, probably
		 * due to #REMOTE_AUDIO_REASON_NETWORK_RECOVERY (2),
		 * #REMOTE_AUDIO_REASON_LOCAL_UNMUTED (4), or
		 * #REMOTE_AUDIO_REASON_REMOTE_UNMUTED (6).
		 */
		REMOTE_AUDIO_STATE_DECODING = 2,  // The first remote audio frame has been decoded or fronzen state ends
		/** 3: The remote audio is frozen, probably due to
		 * #REMOTE_AUDIO_REASON_NETWORK_CONGESTION (1).
		 */
		REMOTE_AUDIO_STATE_FROZEN = 3,    // Remote audio is frozen, probably due to network issue
		/** 4: The remote audio fails to start, probably due to
		 * #REMOTE_AUDIO_REASON_INTERNAL (0).
		 */
		REMOTE_AUDIO_STATE_FAILED = 4,    // Remote audio play failed
	};

	/** Remote audio state reasons.
	 */
	enum REMOTE_AUDIO_STATE_REASON
	{
		/** 0: Internal reasons.
		 */
		REMOTE_AUDIO_REASON_INTERNAL = 0,
		/** 1: Network congestion.
		 */
		REMOTE_AUDIO_REASON_NETWORK_CONGESTION = 1,
		/** 2: Network recovery.
		 */
		REMOTE_AUDIO_REASON_NETWORK_RECOVERY = 2,
		/** 3: The local user stops receiving the remote audio stream or
		 * disables the audio module.
		 */
		REMOTE_AUDIO_REASON_LOCAL_MUTED = 3,
		/** 4: The local user resumes receiving the remote audio stream or
		 * enables the audio module.
		 */
		REMOTE_AUDIO_REASON_LOCAL_UNMUTED = 4,
		/** 5: The remote user stops sending the audio stream or disables the
		 * audio module.
		 */
		REMOTE_AUDIO_REASON_REMOTE_MUTED = 5,
		/** 6: The remote user resumes sending the audio stream or enables the
		 * audio module.
		 */
		REMOTE_AUDIO_REASON_REMOTE_UNMUTED = 6,
		/** 7: The remote user leaves the channel.
		 */
		REMOTE_AUDIO_REASON_REMOTE_OFFLINE = 7,
	};

	/** Remote video states. */
	// enum REMOTE_VIDEO_STATE
	// {
	//     // REMOTE_VIDEO_STATE_STOPPED is not used at this version. Ignore this value.
	//     // REMOTE_VIDEO_STATE_STOPPED = 0,  // Default state, video is started or remote user disabled/muted video stream
	//       /** 1: The remote video is playing. */
	//       REMOTE_VIDEO_STATE_RUNNING = 1,  // Running state, remote video can be displayed normally
	//       /** 2: The remote video is frozen. */
	//       REMOTE_VIDEO_STATE_FROZEN = 2,    // Remote video is frozen, probably due to network issue.
	// };

	/** The state of the remote video. */
	enum REMOTE_VIDEO_STATE {
		/** 0: The remote video is in the default state, probably due to #REMOTE_VIDEO_STATE_REASON_LOCAL_MUTED (3), #REMOTE_VIDEO_STATE_REASON_REMOTE_MUTED (5), or #REMOTE_VIDEO_STATE_REASON_REMOTE_OFFLINE (7).
		 */
		REMOTE_VIDEO_STATE_STOPPED = 0,

		/** 1: The first remote video packet is received.
		 */
		REMOTE_VIDEO_STATE_STARTING = 1,

		/** 2: The remote video stream is decoded and plays normally, probably due to #REMOTE_VIDEO_STATE_REASON_NETWORK_RECOVERY (2), #REMOTE_VIDEO_STATE_REASON_LOCAL_UNMUTED (4), #REMOTE_VIDEO_STATE_REASON_REMOTE_UNMUTED (6), or #REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK_RECOVERY (9).
		 */
		REMOTE_VIDEO_STATE_DECODING = 2,

		/** 3: The remote video is frozen, probably due to #REMOTE_VIDEO_STATE_REASON_NETWORK_CONGESTION (1) or #REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK (8).
		 */
		REMOTE_VIDEO_STATE_FROZEN = 3,

		/** 4: The remote video fails to start, probably due to #REMOTE_VIDEO_STATE_REASON_INTERNAL (0).
		 */
		REMOTE_VIDEO_STATE_FAILED = 4
	};

	enum STREAM_PUBLISH_STATE {
		PUB_STATE_IDLE = 0,
		PUB_STATE_NO_PUBLISHED = 1,
		PUB_STATE_PUBLISHING = 2,
		PUB_STATE_PUBLISHED = 3
	};

	enum STREAM_SUBSCRIBE_STATE {
		SUB_STATE_IDLE = 0,
		SUB_STATE_NO_SUBSCRIBED = 1,
		SUB_STATE_SUBSCRIBING = 2,
		SUB_STATE_SUBSCRIBED = 3
	};

	/** The remote video frozen type. */
	enum XLA_REMOTE_VIDEO_FROZEN_TYPE {
		/** 0: 500ms video frozen type.
		 */
		XLA_REMOTE_VIDEO_FROZEN_500MS = 0,
		/** 1: 200ms video frozen type.
		 */
		XLA_REMOTE_VIDEO_FROZEN_200MS = 1,
		/** 2: 600ms video frozen type.
		 */
		XLA_REMOTE_VIDEO_FROZEN_600MS = 2,
		/** 3: max video frozen type.
		 */
		XLA_REMOTE_VIDEO_FROZEN_TYPE_MAX = 3,
	};

	/** The remote audio frozen type. */
	enum XLA_REMOTE_AUDIO_FROZEN_TYPE {
		/** 0: 80ms audio frozen.
		 */
		XLA_REMOTE_AUDIO_FROZEN_80MS = 0,
		/** 1: 200ms audio frozen.
		 */
		XLA_REMOTE_AUDIO_FROZEN_200MS = 1,
		/** 2: max audio frozen type.
		 */
		XLA_REMOTE_AUDIO_FROZEN_TYPE_MAX = 2,
	};

	/** The reason of the remote video state change. */
	enum REMOTE_VIDEO_STATE_REASON {
		/** 0: Internal reasons.
		 */
		REMOTE_VIDEO_STATE_REASON_INTERNAL = 0,

		/** 1: Network congestion.
		 */
		REMOTE_VIDEO_STATE_REASON_NETWORK_CONGESTION = 1,

		/** 2: Network recovery.
		 */
		REMOTE_VIDEO_STATE_REASON_NETWORK_RECOVERY = 2,

		/** 3: The local user stops receiving the remote video stream or disables the video module.
		 */
		REMOTE_VIDEO_STATE_REASON_LOCAL_MUTED = 3,

		/** 4: The local user resumes receiving the remote video stream or enables the video module.
		 */
		REMOTE_VIDEO_STATE_REASON_LOCAL_UNMUTED = 4,

		/** 5: The remote user stops sending the video stream or disables the video module.
		 */
		REMOTE_VIDEO_STATE_REASON_REMOTE_MUTED = 5,

		/** 6: The remote user resumes sending the video stream or enables the video module.
		 */
		REMOTE_VIDEO_STATE_REASON_REMOTE_UNMUTED = 6,

		/** 7: The remote user leaves the channel.
		 */
		REMOTE_VIDEO_STATE_REASON_REMOTE_OFFLINE = 7,

		/** 8: The remote media stream falls back to the audio-only stream due to poor network conditions.
		 */
		REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK = 8,

		/** 9: The remote media stream switches back to the video stream after the network conditions improve.
		 */
		REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK_RECOVERY = 9

	};

	/** Video frame rates. */
	enum FRAME_RATE
	{
		/** 1: 1 fps */
		FRAME_RATE_FPS_1 = 1,
		/** 7: 7 fps */
		FRAME_RATE_FPS_7 = 7,
		/** 10: 10 fps */
		FRAME_RATE_FPS_10 = 10,
		/** 15: 15 fps */
		FRAME_RATE_FPS_15 = 15,
		/** 24: 24 fps */
		FRAME_RATE_FPS_24 = 24,
		/** 30: 30 fps */
		FRAME_RATE_FPS_30 = 30,
		/** 60: 60 fps (Windows and macOS only) */
		FRAME_RATE_FPS_60 = 60,
	};

	/** Video output orientation modes.
	 */
	enum ORIENTATION_MODE {
		/** 0: (Default) Adaptive mode.

		 The video encoder adapts to the orientation mode of the video input device.

		 - If the width of the captured video from the SDK is greater than the height, the encoder sends the video in landscape mode. The encoder also sends the rotational information of the video, and the receiver uses the rotational information to rotate the received video.
		 - When you use a custom video source, the output video from the encoder inherits the orientation of the original video. If the original video is in portrait mode, the output video from the encoder is also in portrait mode. The encoder also sends the rotational information of the video to the receiver.
		 */
		ORIENTATION_MODE_ADAPTIVE = 0,
		/** 1: Landscape mode.

		 The video encoder always sends the video in landscape mode. The video encoder rotates the original video before sending it and the rotational infomation is 0. This mode applies to scenarios involving CDN live streaming.
		 */
		ORIENTATION_MODE_FIXED_LANDSCAPE = 1,//rotate 90
		/** 2: Portrait mode.

		 The video encoder always sends the video in portrait mode. The video encoder rotates the original video before sending it and the rotational infomation is 0. This mode applies to scenarios involving CDN live streaming.
		 */
		ORIENTATION_MODE_FIXED_PORTRAIT = 2,//rotate 0

		ORIENTATION_MODE_FIXED_LANDSCAPE_EXT = 3//rotate 270
	};

	/** Video degradation preferences when the bandwidth is a constraint. */
	enum DEGRADATION_PREFERENCE {
		/** 0: (Default) Degrade the frame rate in order to maintain the video quality. */
		MAINTAIN_QUALITY = 0,
		/** 1: Degrade the video quality in order to maintain the frame rate. */
		MAINTAIN_FRAMERATE = 1,
		/** 2: (For future use) Maintain a balance between the frame rate and video quality. */
		MAINTAIN_BALANCED = 2,
	};

	/** Stream fallback options. */
	enum STREAM_FALLBACK_OPTIONS
	{
		/** 0: No fallback behavior for the local/remote video stream when the uplink/downlink network conditions are poor. The quality of the stream is not guaranteed. */
		STREAM_FALLBACK_OPTION_DISABLED = 0,
		/** 1: Under poor downlink network conditions, the remote video stream, to which you subscribe, falls back to the low-stream (low resolution and low bitrate) video. You can set this option only in the \ref IRtcEngine::setRemoteSubscribeFallbackOption "setRemoteSubscribeFallbackOption" method. Nothing happens when you set this in the \ref IRtcEngine::setLocalPublishFallbackOption "setLocalPublishFallbackOption" method. */
		STREAM_FALLBACK_OPTION_VIDEO_STREAM_LOW = 1,
		/** 2: Under poor uplink network conditions, the locally published video stream falls back to audio only.

		Under poor downlink network conditions, the remote video stream, to which you subscribe, first falls back to the low-stream (low resolution and low bitrate) video; and then to an audio-only stream if the network conditions worsen.*/
		STREAM_FALLBACK_OPTION_AUDIO_ONLY = 2,
	};

	/** Camera capturer configuration.
	*/
	enum CAPTURER_OUTPUT_PREFERENCE
	{
		/** 0: (Default) self-adapts the camera output parameters to the system performance and network conditions to balance CPU consumption and video preview quality.
		*/
		CAPTURER_OUTPUT_PREFERENCE_AUTO = 0,
		/** 2: Prioritizes the system performance. The SDK chooses the dimension and frame rate of the local camera capture closest to those set by \ref IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration".
		*/
		CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1,
		/** 2: Prioritizes the local preview quality. The SDK chooses higher camera output parameters to improve the local video preview quality. This option requires extra CPU and RAM usage for video pre-processing.
		*/
		CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2,
	};

	/** The priority of the remote user.
	 */
	enum PRIORITY_TYPE
	{
		/** 50: The user's priority is high.
		 */
		PRIORITY_HIGH = 50,
		/** 100: (Default) The user's priority is normal.
		*/
		PRIORITY_NORMAL = 100,
	};

	/** Connection states. */
	enum CONNECTION_STATE_TYPE
	{
		/** 1: The SDK is disconnected from tang's edge server.

		 - This is the initial state before calling the \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method.
		 - The SDK also enters this state when the application calls the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method.
		 */
		CONNECTION_STATE_DISCONNECTED = 1,
		/** 2: The SDK is connecting to tang's edge server.

		 - When the application calls the \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method, the SDK starts to establish a connection to the specified channel, triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" callback, and switches to the #CONNECTION_STATE_CONNECTING state.
		 - When the SDK successfully joins the channel, it triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" callback and switches to the #CONNECTION_STATE_CONNECTED state.
		 - After the SDK joins the channel and when it finishes initializing the media engine, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess" callback.
		 */
		CONNECTION_STATE_CONNECTING = 2,
		/** 3: The SDK is connected to tang's edge server and has joined a channel. You can now publish or subscribe to a media stream in the channel.

		 If the connection to the channel is lost because, for example, if the network is down or switched, the SDK automatically tries to reconnect and triggers:
		 - The \ref tang::rtc::IRtcEngineEventHandler::onConnectionInterrupted "onConnectionInterrupted" callback (deprecated).
		 - The \ref tang::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" callback and switches to the #CONNECTION_STATE_RECONNECTING state.
		 */
		CONNECTION_STATE_CONNECTED = 3,
		/** 4: The SDK keeps rejoining the channel after being disconnected from a joined channel because of network issues.

		 - If the SDK cannot rejoin the channel within 10 seconds after being disconnected from tang's edge server, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionLost "onConnectionLost" callback, stays in the #CONNECTION_STATE_RECONNECTING state, and keeps rejoining the channel.
		 - If the SDK fails to rejoin the channel 20 minutes after being disconnected from tang's edge server, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" callback, switches to the #CONNECTION_STATE_FAILED state, and stops rejoining the channel.
		 */
		CONNECTION_STATE_RECONNECTING = 4,
		/** 5: The SDK fails to connect to tang's edge server or join the channel.

		 You must call the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method to leave this state, and call the \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method again to rejoin the channel.

		 If the SDK is banned from joining the channel by tang's edge server (through the RESTful API), the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionBanned "onConnectionBanned" (deprecated) and \ref tang::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" callbacks.
		 */
		CONNECTION_STATE_FAILED = 5,
	};

	/** Reasons for a connection state change. */
	enum CONNECTION_CHANGED_REASON_TYPE
	{
		/** 0: The SDK is connecting to tang's edge server. */
		CONNECTION_CHANGED_CONNECTING = 0,
		/** 1: The SDK has joined the channel successfully. */
		CONNECTION_CHANGED_JOIN_SUCCESS = 1,
		/** 2: The connection between the SDK and tang's edge server is interrupted. */
		CONNECTION_CHANGED_INTERRUPTED = 2,
		/** 3: The connection between the SDK and tang's edge server is banned by tang's edge server. */
		CONNECTION_CHANGED_BANNED_BY_SERVER = 3,
		/** 4: The SDK fails to join the channel for more than 20 minutes and stops reconnecting to the channel. */
		CONNECTION_CHANGED_JOIN_FAILED = 4,
		/** 5: The SDK has left the channel. */
		CONNECTION_CHANGED_LEAVE_CHANNEL = 5,
		/** 6: The connection failed since Appid is not valid. */
		CONNECTION_CHANGED_INVALID_APP_ID = 6,
		/** 7: The connection failed since channel name is not valid. */
		CONNECTION_CHANGED_INVALID_CHANNEL_NAME = 7,
		/** 8: The connection failed since token is not valid, possibly because:

		 - The App Certificate for the project is enabled in Dashboard, but you do not use Token when joining the channel. If you enable the App Certificate, you must use a token to join the channel.
		 - The uid that you specify in the \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method is different from the uid that you pass for generating the token.
		 */
		CONNECTION_CHANGED_INVALID_TOKEN = 8,
		/** 9: The connection failed since token is expired. */
		CONNECTION_CHANGED_TOKEN_EXPIRED = 9,
		/** 10: The connection is rejected by server. */
		CONNECTION_CHANGED_REJECTED_BY_SERVER = 10,
		/** 11: The connection changed to reconnecting since SDK has set a proxy server. */
		CONNECTION_CHANGED_SETTING_PROXY_SERVER = 11,
		/** 12: When SDK is in connection failed, the renew token operation will make it connecting. */
		CONNECTION_CHANGED_RENEW_TOKEN = 12,
		/** 13: The IP Address of SDK client has changed. i.e., Network type or IP/Port changed by network operator might change client IP address. */
		CONNECTION_CHANGED_CLIENT_IP_ADDRESS_CHANGED = 13,
		/** 14: Timeout for the keep-alive of the connection between the SDK and tang's edge server. The connection state changes to CONNECTION_STATE_RECONNECTING(4). */
		CONNECTION_CHANGED_KEEP_ALIVE_TIMEOUT = 14,
	};

	/** Network type. */
	enum NETWORK_TYPE
	{
		/** -1: The network type is unknown. */
		NETWORK_TYPE_UNKNOWN = -1,
		/** 0: The SDK disconnects from the network. */
		NETWORK_TYPE_DISCONNECTED = 0,
		/** 1: The network type is LAN. */
		NETWORK_TYPE_LAN = 1,
		/** 2: The network type is Wi-Fi(including hotspots). */
		NETWORK_TYPE_WIFI = 2,
		/** 3: The network type is mobile 2G. */
		NETWORK_TYPE_MOBILE_2G = 3,
		/** 4: The network type is mobile 3G. */
		NETWORK_TYPE_MOBILE_3G = 4,
		/** 5: The network type is mobile 4G. */
		NETWORK_TYPE_MOBILE_4G = 5,
		/** 6: The network type is mobile 5G. */
		NETWORK_TYPE_MOBILE_5G = 6,
	};

	/** States of the last-mile network probe test. */
	enum LASTMILE_PROBE_RESULT_STATE {
		/** 1: The last-mile network probe test is complete. */
		LASTMILE_PROBE_RESULT_COMPLETE = 1,
		/** 2: The last-mile network probe test is incomplete and the bandwidth estimation is not available, probably due to limited test resources. */
		LASTMILE_PROBE_RESULT_INCOMPLETE_NO_BWE = 2,
		/** 3: The last-mile network probe test is not carried out, probably due to poor network conditions. */
		LASTMILE_PROBE_RESULT_UNAVAILABLE = 3
	};
	/** Audio output routing. */
	enum AUDIO_ROUTE_TYPE {
		/** Default.
		 */
		AUDIO_ROUTE_DEFAULT = -1,
		/** Headset.
		 */
		AUDIO_ROUTE_HEADSET = 0,
		/** Earpiece.
		 */
		AUDIO_ROUTE_EARPIECE = 1,
		/** Headset with no microphone.
		 */
		AUDIO_ROUTE_HEADSET_NO_MIC = 2,
		/** Speakerphone.
		 */
		AUDIO_ROUTE_SPEAKERPHONE = 3,
		/** Loudspeaker.
		 */
		AUDIO_ROUTE_LOUDSPEAKER = 4,
		/** Bluetooth headset.
		 */
		AUDIO_ROUTE_BLUETOOTH = 5
	};

#if (defined(__APPLE__) && TARGET_OS_IOS)
	/** Audio session restriction. */
	enum AUDIO_SESSION_OPERATION_RESTRICTION {
		/** No restriction, the SDK has full control of the audio session operations. */
		AUDIO_SESSION_OPERATION_RESTRICTION_NONE = 0,
		/** The SDK does not change the audio session category. */
		AUDIO_SESSION_OPERATION_RESTRICTION_SET_CATEGORY = 1,
		/** The SDK does not change any setting of the audio session (category, mode, categoryOptions). */
		AUDIO_SESSION_OPERATION_RESTRICTION_CONFIGURE_SESSION = 1 << 1,
		/** The SDK keeps the audio session active when leaving a channel. */
		AUDIO_SESSION_OPERATION_RESTRICTION_DEACTIVATE_SESSION = 1 << 2,
		/** The SDK does not configure the audio session anymore. */
		AUDIO_SESSION_OPERATION_RESTRICTION_ALL = 1 << 7,
	};
#endif

	/** The uplink or downlink last-mile network probe test result. */
	struct LastmileProbeOneWayResult {
		/** The packet loss rate (%). */
		unsigned int packetLossRate;
		/** The network jitter (ms). */
		unsigned int jitter;
		/* The estimated available bandwidth (Kbps). */
		unsigned int availableBandwidth;
	};

	/** The uplink and downlink last-mile network probe test result. */
	struct LastmileProbeResult {
		/** The state of the probe test. */
		LASTMILE_PROBE_RESULT_STATE state;
		/** The uplink last-mile network probe test result. */
		LastmileProbeOneWayResult uplinkReport;
		/** The downlink last-mile network probe test result. */
		LastmileProbeOneWayResult downlinkReport;
		/** The round-trip delay time (ms). */
		unsigned int rtt;
	};

	/** Configurations of the last-mile network probe test. */
	struct LastmileProbeConfig {
		/** Sets whether or not to test the uplink network. Some users, for example, the audience in a Live-broadcast channel, do not need such a test:
		- true: test.
		- false: do not test. */
		bool probeUplink;
		/** Sets whether or not to test the downlink network:
		- true: test.
		- false: do not test. */
		bool probeDownlink;
		/** The expected maximum sending bitrate (Kbps) of the local user. The value ranges between 100 and 5000. We recommend setting this parameter according to the bitrate value set by \ref IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration". */
		unsigned int expectedUplinkBitrate;
		/** The expected maximum receiving bitrate (Kbps) of the local user. The value ranges between 100 and 5000. */
		unsigned int expectedDownlinkBitrate;
	};

	/** Properties of the audio volume information.

	 An array containing the user ID and volume information for each speaker.
	 */
	struct AudioVolumeInfo
	{
		/**
	   User ID of the speaker. The uid of the local user is 0. The user ID may come from different RtcConnection.
	   */
		uid_t uid;
		/** The volume of the speaker. The volume ranges between 0 (lowest volume) and 255 (highest volume).
	 */
		unsigned int volume;
		/** Whether current signal contains human voice.
	 */
		unsigned int vad;
		/** The channel ID, which indicates which channel the speaker is in.
		 */
		const char * channelId;
	};

	/** Statistics of the channel.
	 */
	struct RtcStats
	{
		/**
		 Call duration (s), represented by an aggregate value.
		 */
		unsigned int duration;
		/**
		 Total number of bytes transmitted, represented by an aggregate value.
		 */
		unsigned int txBytes;
		/**
		 Total number of bytes received, represented by an aggregate value.
		 */
		unsigned int rxBytes;
		/** Total number of audio bytes sent (bytes), represented
		* by an aggregate value.
		*/
		unsigned int txAudioBytes;
		/** Total number of video bytes sent (bytes), represented
		 * by an aggregate value.
		 */
		unsigned int txVideoBytes;
		/** Total number of audio bytes received (bytes) before
		 * network countermeasures, represented by an aggregate value.
		 */
		unsigned int rxAudioBytes;
		/** Total number of video bytes received (bytes),
		 * represented by an aggregate value.
		 */
		unsigned int rxVideoBytes;

		/**
		 Transmission bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short txKBitRate;
		/**
		 Receive bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short rxKBitRate;
		/**
		 Audio receive bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short rxAudioKBitRate;
		/**
		 Audio transmission bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short txAudioKBitRate;
		/**
		 Video receive bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short rxVideoKBitRate;
		/**
		 Video transmission bitrate (Kbps), represented by an instantaneous value.
		 */
		unsigned short txVideoKBitRate;
		/** Client-server latency (ms)
		 */
		unsigned short lastmileDelay;
		/** The packet loss rate (%) from the local client to tang's edge server,
		 * before network countermeasures.
		 */
		unsigned short txPacketLossRate;
		/** The packet loss rate (%) from tang's edge server to the local client,
		 * before network countermeasures.
		 */
		unsigned short rxPacketLossRate;
		/** Number of users in the channel.

		 - Communication profile: The number of users in the channel.
		 - Live broadcast profile:

			 -  If the local user is an audience: The number of users in the channel = The number of hosts in the channel + 1.
			 -  If the user is a host: The number of users in the channel = The number of hosts in the channel.
		 */
		unsigned int userCount;
		/**
		 Application CPU usage (%).
		 */
		double cpuAppUsage;
		/**
		 System CPU usage (%).
		 */
		double cpuTotalUsage;
		/** gateway Rtt
		 */
		int gatewayRtt;
		/**
		 Application memory usage (%).
		 */
		double memoryAppUsageRatio;
		/**
		 System memory usage (%).
		 */
		double memoryTotalUsageRatio;
		/**
		 Application memory size (KB).
		 */
		int memoryAppUsageInKbytes;

		RtcStats()
			: duration(0)
			, txBytes(0)
			, rxBytes(0)
			, txAudioBytes(0)
			, txVideoBytes(0)
			, rxAudioBytes(0)
			, rxVideoBytes(0)
			, txKBitRate(0)
			, rxKBitRate(0)
			, rxAudioKBitRate(0)
			, txAudioKBitRate(0)
			, rxVideoKBitRate(0)
			, txVideoKBitRate(0)
			, lastmileDelay(0)
			, txPacketLossRate(0)
			, rxPacketLossRate(0)
			, userCount(0)
			, cpuAppUsage(0)
			, cpuTotalUsage(0)
			, gatewayRtt(0)
			, memoryAppUsageRatio(0)
			, memoryTotalUsageRatio(0)
			, memoryAppUsageInKbytes(0) {}
	};

	/** Quality change of the local video in terms of target frame rate and target bit rate since last count.
	  */
	enum QUALITY_ADAPT_INDICATION {
		/** The quality of the local video stays the same. */
		ADAPT_NONE = 0,
		/** The quality improves because the network bandwidth increases. */
		ADAPT_UP_BANDWIDTH = 1,
		/** The quality worsens because the network bandwidth decreases. */
		ADAPT_DOWN_BANDWIDTH = 2,
	};


	enum CHANNEL_MEDIA_RELAY_ERROR {
		/** 0: The state is normal.
		 */
		RELAY_OK = 0,
		/** 1: An error occurs in the server response.
		 */
		RELAY_ERROR_SERVER_ERROR_RESPONSE = 1,
		/** 2: No server response. You can call the
		 * \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method to
		 * leave the channel.
		 */
		RELAY_ERROR_SERVER_NO_RESPONSE = 2,
		/** 3: The SDK fails to access the service, probably due to limited
		 * resources of the server.
		 */
		RELAY_ERROR_NO_RESOURCE_AVAILABLE = 3,
		/** 4: The server fails to join the source channel.
		 */
		RELAY_ERROR_FAILED_JOIN_SRC = 4,
		/** 5: The server fails to join the destination channel.
		 */
		RELAY_ERROR_FAILED_JOIN_DEST = 5,
		/** 6: The server fails to receive the data from the source channel.
		 */
		RELAY_ERROR_FAILED_PACKET_RECEIVED_FROM_SRC = 6,
		/** 7: The source channel fails to transmit data.
		 */
		RELAY_ERROR_FAILED_PACKET_SENT_TO_DEST = 7,
		/** 8: The SDK disconnects from the server due to poor network
		 * connections. You can call the \ref tang::rtc::IRtcEngine::leaveChannel
		 * "leaveChannel" method to leave the channel.
		 */
		RELAY_ERROR_SERVER_CONNECTION_LOST = 8,
		/** 9: An internal error occurs in the server.
		 */
		RELAY_ERROR_INTERNAL_ERROR = 9,
		/** 10: The token of the source channel has expired.
		 */
		RELAY_ERROR_SRC_TOKEN_EXPIRED = 10,
		/** 11: The token of the destination channel has expired.
		 */
		RELAY_ERROR_DEST_TOKEN_EXPIRED = 11,
	};

	enum CHANNEL_MEDIA_RELAY_EVENT {
		/** 0: The user disconnects from the server due to poor network
		 * connections.
		 */
		RELAY_EVENT_NETWORK_DISCONNECTED = 0,
		/** 1: The network reconnects.
		 */
		RELAY_EVENT_NETWORK_CONNECTED = 1,
		/** 2: The user joins the source channel.
		 */
		RELAY_EVENT_PACKET_JOINED_SRC_CHANNEL = 2,
		/** 3: The user joins the destination channel.
		 */
		RELAY_EVENT_PACKET_JOINED_DEST_CHANNEL = 3,
		/** 4: The SDK starts relaying the media stream to the destination channel.
		 */
		RELAY_EVENT_PACKET_SENT_TO_DEST_CHANNEL = 4,
		/** 5: The server receives the video stream from the source channel.
		 */
		RELAY_EVENT_PACKET_RECEIVED_VIDEO_FROM_SRC = 5,
		/** 6: The server receives the audio stream from the source channel.
		 */
		RELAY_EVENT_PACKET_RECEIVED_AUDIO_FROM_SRC = 6,
		/** 7: The destination channel is updated.
		 */
		RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL = 7,
		/** 8: The destination channel update fails due to internal reasons.
		 */
		RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_REFUSED = 8,
		/** 9: The destination channel does not change, which means that the
		 * destination channel fails to be updated.
		 */
		RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_NOT_CHANGE = 9,
		/** 10: The destination channel name is NULL.
		 */
		RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_IS_NULL = 10,
		/** 11: The video profile is sent to the server.
		 */
		RELAY_EVENT_VIDEO_PROFILE_UPDATE = 11,
	};

	enum CHANNEL_MEDIA_RELAY_STATE {
		/** 0: The SDK is initializing.
		 */
		RELAY_STATE_IDLE = 0,
		/** 1: The SDK tries to relay the media stream to the destination channel.
		 */
		RELAY_STATE_CONNECTING = 1,
		/** 2: The SDK successfully relays the media stream to the destination
		 * channel.
		 */
		RELAY_STATE_RUNNING = 2,
		/** 3: A failure occurs. See the details in code.
		 */
		RELAY_STATE_FAILURE = 3,
	};

	/** Statistics of the local video stream.
	 */
	struct LocalVideoStats
	{
		/** Bitrate (Kbps) sent in the reported interval, which does not include
		 * the bitrate of the re-transmission video after packet loss.
		 */
		int sentBitrate;
		/** Frame rate (fps) sent in the reported interval, which does not include
		 * the frame rate of the re-transmission video after packet loss.
		 */
		int sentFrameRate;
		/** The encoder output frame rate (fps) of the local video.
		 */
		int encoderOutputFrameRate;
		/** The render output frame rate (fps) of the local video.
		 */
		int rendererOutputFrameRate;
		/** The target bitrate (Kbps) of the current encoder. This value is estimated by the SDK based on the current network conditions.
		  */
		int targetBitrate;
		/** The target frame rate (fps) of the current encoder.
		  */
		int targetFrameRate;
		/** Quality change of the local video in terms of target frame rate and
		 * target bit rate in this reported interval. See #QUALITY_ADAPT_INDICATION.
		 */
		QUALITY_ADAPT_INDICATION qualityAdaptIndication;
		/** The encoding bitrate (Kbps), which does not include the bitrate of the
		 * re-transmission video after packet loss.
		 */
		int encodedBitrate;
		/** The width of the encoding frame (px).
		 */
		int encodedFrameWidth;
		/** The height of the encoding frame (px).
		 */
		int encodedFrameHeight;
		/** The value of the sent frame rate, represented by an aggregate value.
		 */
		int encodedFrameCount;
		/** The codec type of the local video:
		 * - VIDEO_CODEC_VP8 = 1: VP8.
		 * - VIDEO_CODEC_H264 = 2: (Default) H.264.
		 */
		VIDEO_CODEC_TYPE codecType;

		/** The packet loss rate (%) from the local client to tang's edge server,
		 * before network countermeasures.
		*/
		unsigned short txPacketLossRate;
		/** The capture frame rate (fps) of the local video.
		 */
		int captureFrameRate;
		/** The PSNR point to show the quality of video, nomal level is in [20,40].
		*/
		int videoQualityPoint;
	};

	/** Statistics of the remote video stream.
	 */
	struct RemoteVideoStats
	{
		/**
	   User ID of the remote user sending the video streams.
	   */
		uid_t uid;
		/** **DEPRECATED** Time delay (ms).
	 */
		int delay;
		/**
		 Width (pixels) of the video stream.
		 */
		int width;
		/**
	   Height (pixels) of the video stream.
	   */
		int height;
		/**
	   Bitrate (Kbps) received since the last count.
	   */
		int receivedBitrate;
		/** The decoder output frame rate (fps) of the remote video.
		 */
		int decoderOutputFrameRate;
		/** The render output frame rate (fps) of the remote video.
		 */
		int rendererOutputFrameRate;
		/** Packet loss rate (%) of the remote video stream after network
		 * countermeasures.
		 */
		int packetLossRate;
		REMOTE_VIDEO_STREAM_TYPE rxStreamType;
		/**
		 The total freeze time (ms) of the remote video stream after the remote user joins the channel.
		 In a video session where the frame rate is set to no less than 5 fps, video freeze occurs when
		 the time interval between two adjacent renderable video frames is more than 500 ms.
		 */
		int totalFrozenTime;
		/**
		 The total video freeze time as a percentage (%) of the total time when the video is available.
		 */
		int frozenRate;
		/**
		 * The total active time (ms) of the remote video stream after the remote user joins the channel.
		 */
		int totalActiveTime;
		/**
		 * The total active time (ms) of the remote video stream after the remote user publish the video stream.
		 */
		int publishDuration;
	};

	/** Audio statistics of the local user */
	struct LocalAudioStats
	{
		/** The number of channels.
		 */
		int numChannels;
		/** The sample rate (Hz).
		 */
		int sentSampleRate;
		/** The average sending bitrate (Kbps).
		 */
		int sentBitrate;
		/** The packet loss rate (%) from the local client to tang's edge server,
		 * before network countermeasures.
		 */
		unsigned short txPacketLossRate;
	};

	/** Audio statistics of a remote user */
	struct RemoteAudioStats
	{
		/** User ID of the remote user sending the audio streams.
		 *
		 */
		uid_t uid;
		/** Audio quality received by the user: #QUALITY_TYPE.
		 */
		int quality;
		/** Network delay (ms) from the sender to the receiver.
		 */
		int networkTransportDelay;
		/** Network delay (ms) from the receiver to the jitter buffer.
		 */
		int jitterBufferDelay;
		/** Packet loss rate in the reported interval.
		 */
		int audioLossRate;
		/** The number of channels.
		 */
		int numChannels;
		/** The sample rate (Hz) of the received audio stream in the reported
		 * interval.
		 */
		int receivedSampleRate;
		/** The average bitrate (Kbps) of the received audio stream in the
		 * reported interval. */
		int receivedBitrate;
		/** The total freeze time (ms) of the remote audio stream after the remote user joins the channel. In a session, audio freeze occurs when the audio frame loss rate reaches 4%.
		 * tang uses 2 seconds as an audio piece unit to calculate the audio freeze time. The total audio freeze time = The audio freeze number &times; 2 seconds
		 */
		int totalFrozenTime;
		/** The total audio freeze time as a percentage (%) of the total time when the audio is available. */
		int frozenRate;
		/**
		 * The total active time (ms) of the remote audio stream after the remote user joins the channel.
		 */
		int totalActiveTime;
		/**
		 * The total active time (ms) of the remote audio stream after the remote user publish the audio stream.
		 */
		int publishDuration;
	};

	/**
	 * Video dimensions.
	 */
	struct VideoDimensions {
		/** Width (pixels) of the video. */
		int width;
		/** Height (pixels) of the video. */
		int height;
		VideoDimensions()
			: width(640), height(480)
		{}
		VideoDimensions(int w, int h)
			: width(w), height(h)
		{}
	};

	/** (Recommended) The standard bitrate set in the \ref IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration" method.

	 In this mode, the bitrates differ between the live broadcast and communication profiles:

	 - Communication profile: The video bitrate is the same as the base bitrate.
	 - Live broadcast profile: The video bitrate is twice the base bitrate.

	 */
	const int STANDARD_BITRATE = 0;

	/** The compatible bitrate set in the \ref IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration" method.

	 The bitrate remains the same regardless of the channel profile. If you choose this mode in the Live-broadcast profile, the video frame rate may be lower than the set value.
	 */
	const int COMPATIBLE_BITRATE = -1;

	/** Use the default minimum bitrate.
	 */
	const int DEFAULT_MIN_BITRATE = -1;

	/** Video encoder configurations.
	 */
	struct VideoEncoderConfiguration {
		/** The video frame dimensions (px) used to specify the video quality and measured by the total number of pixels along a frame's width and height: VideoDimensions. The default value is 640 x 360.
		*/
		VideoDimensions dimensions;
		/** The frame rate of the video: #FRAME_RATE. The default value is 15.

		 Note that we do not recommend setting this to a value greater than 30.
		*/
		FRAME_RATE frameRate;
		/** The minimum frame rate of the video. The default value is -1.
		 */
		int minFrameRate;
		/** The video encoding bitrate (Kbps).

		 Choose one of the following options:

		 - #STANDARD_BITRATE: (Recommended) The standard bitrate.
			- The Communication profile: the encoding bitrate equals the base bitrate.
			- The Live-broadcast profile: the encoding bitrate is twice the base bitrate.
		 - #COMPATIBLE_BITRATE: The compatible bitrate: the bitrate stays the same regardless of the profile.

		 The Communication profile prioritizes smoothness, while the Live-broadcast profile prioritizes video quality (requiring a higher bitrate). We recommend setting the bitrate mode as #STANDARD_BITRATE to address this difference.

		 The following table lists the recommended video encoder configurations, where the base bitrate applies to the Communication profile. Set your bitrate based on this table. If you set a bitrate beyond the proper range, the SDK automatically sets it to within the range.

		 | Resolution             | Frame Rate (fps) | Base Bitrate (Kbps, for Communication) | Live Bitrate (Kbps, for Live Broadcast)|
		 |------------------------|------------------|----------------------------------------|----------------------------------------|
		 | 160 &times; 120        | 15               | 65                                     | 130                                    |
		 | 120 &times; 120        | 15               | 50                                     | 100                                    |
		 | 320 &times; 180        | 15               | 140                                    | 280                                    |
		 | 180 &times; 180        | 15               | 100                                    | 200                                    |
		 | 240 &times; 180        | 15               | 120                                    | 240                                    |
		 | 320 &times; 240        | 15               | 200                                    | 400                                    |
		 | 240 &times; 240        | 15               | 140                                    | 280                                    |
		 | 424 &times; 240        | 15               | 220                                    | 440                                    |
		 | 640 &times; 360        | 15               | 400                                    | 800                                    |
		 | 360 &times; 360        | 15               | 260                                    | 520                                    |
		 | 640 &times; 360        | 30               | 600                                    | 1200                                   |
		 | 360 &times; 360        | 30               | 400                                    | 800                                    |
		 | 480 &times; 360        | 15               | 320                                    | 640                                    |
		 | 480 &times; 360        | 30               | 490                                    | 980                                    |
		 | 640 &times; 480        | 15               | 500                                    | 1000                                   |
		 | 480 &times; 480        | 15               | 400                                    | 800                                    |
		 | 640 &times; 480        | 30               | 750                                    | 1500                                   |
		 | 480 &times; 480        | 30               | 600                                    | 1200                                   |
		 | 848 &times; 480        | 15               | 610                                    | 1220                                   |
		 | 848 &times; 480        | 30               | 930                                    | 1860                                   |
		 | 640 &times; 480        | 10               | 400                                    | 800                                    |
		 | 1280 &times; 720       | 15               | 1130                                   | 2260                                   |
		 | 1280 &times; 720       | 30               | 1710                                   | 3420                                   |
		 | 960 &times; 720        | 15               | 910                                    | 1820                                   |
		 | 960 &times; 720        | 30               | 1380                                   | 2760                                   |
		 | 1920 &times; 1080      | 15               | 2080                                   | 4160                                   |
		 | 1920 &times; 1080      | 30               | 3150                                   | 6300                                   |
		 | 1920 &times; 1080      | 60               | 4780                                   | 6500                                   |
		 | 2560 &times; 1440      | 30               | 4850                                   | 6500                                   |
		 | 2560 &times; 1440      | 60               | 6500                                   | 6500                                   |
		 | 3840 &times; 2160      | 30               | 6500                                   | 6500                                   |
		 | 3840 &times; 2160      | 60               | 6500                                   | 6500                                   |

		 */
		int bitrate;
		/** The minimum encoding bitrate (Kbps).

		 The SDK automatically adjusts the encoding bitrate to adapt to the network conditions. Using a value greater than the default value forces the video encoder to output high-quality images but may cause more packet loss and hence sacrifice the smoothness of the video transmission. That said, unless you have special requirements for image quality, tang does not recommend changing this value.

		 @note This parameter applies only to the Live-broadcast profile.
		 */
		int minBitrate;
		/** The video orientation mode of the video: #ORIENTATION_MODE.
		*/
		ORIENTATION_MODE orientationMode;
		/** the video encoding degradation preference under limited bandwidth: #DEGRADATION_PREFERENCE.
		 */

		int rotation;	//rotation degrees;0---0 degree; 1---90 degree; 2---180 degree; 3---270 degree;
		DEGRADATION_PREFERENCE degradationPreference;
		/** Sets the mirror mode of the published local video stream. It only affects the video that the remote user sees. See #VIDEO_MIRROR_MODE_TYPE

		@note: The SDK disables the mirror mode by default.
		*/
		VIDEO_MIRROR_MODE_TYPE mirrorMode;
		VideoEncoderConfiguration(
			const VideoDimensions& d, FRAME_RATE f,
			int b, ORIENTATION_MODE m, VIDEO_MIRROR_MODE_TYPE mr = VIDEO_MIRROR_MODE_AUTO)
			: dimensions(d), frameRate(f), minFrameRate(-1), bitrate(b),
			minBitrate(DEFAULT_MIN_BITRATE), orientationMode(m), rotation(0),
			degradationPreference(MAINTAIN_QUALITY), mirrorMode(mr)
		{}
		VideoEncoderConfiguration(
			int width, int height, FRAME_RATE f,
			int b, ORIENTATION_MODE m, VIDEO_MIRROR_MODE_TYPE mr = VIDEO_MIRROR_MODE_AUTO)
			: dimensions(width, height), frameRate(f),
			minFrameRate(-1), bitrate(b),
			minBitrate(DEFAULT_MIN_BITRATE), orientationMode(m), rotation(0),
			degradationPreference(MAINTAIN_QUALITY), mirrorMode(mr)
		{}
		VideoEncoderConfiguration()
			: dimensions(640, 360)
			, frameRate(FRAME_RATE_FPS_15)
			, minFrameRate(-1)
			, bitrate(STANDARD_BITRATE)
			, minBitrate(DEFAULT_MIN_BITRATE)
			, orientationMode(ORIENTATION_MODE_ADAPTIVE)
			, rotation(0)
			, degradationPreference(MAINTAIN_QUALITY)
			, mirrorMode(VIDEO_MIRROR_MODE_AUTO)
		{}
	};

	/** The video properties of the user displaying the video in the CDN live. tang supports a maximum of 17 transcoding users in a CDN streaming channel.
	*/
	typedef struct TranscodingUser {
		/** User ID of the user displaying the video in the CDN live.
		*/
		uid_t uid;

		/** Horizontal position from the top left corner of the video frame.
		*/
		int x;
		/** Vertical position from the top left corner of the video frame.
		*/
		int y;
		/** Width of the video frame. The default value is 360.
		*/
		int width;
		/** Height of the video frame. The default value is 640.
		*/
		int height;

		/** Layer position of the video frame. The value ranges between 0 and 100.

		 - 0: (Default) Lowest
		 - 100: Highest

		 @note
		 - If zOrder is beyond this range, the SDK reports #ERR_INVALID_ARGUMENT.
		 - As of v2.3, the SDK supports zOrder = 0.
		 */
		int zOrder;
		/**  Transparency of the video frame in CDN live. The value ranges between 0 and 1.0:

		 - 0: Completely transparent
		 - 1.0: (Default) Opaque
		 */
		double alpha;
		/** The audio channel of the sound. The default value is 0:

		 - 0: (Default) Supports dual channels at most, depending on the upstream of the broadcaster.
		 - 1: The audio stream of the broadcaster uses the FL audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels are mixed into mono first.
		 - 2: The audio stream of the broadcaster uses the FC audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels are mixed into mono first.
		 - 3: The audio stream of the broadcaster uses the FR audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels are mixed into mono first.
		 - 4: The audio stream of the broadcaster uses the BL audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels are mixed into mono first.
		 - 5: The audio stream of the broadcaster uses the BR audio channel. If the upstream of the broadcaster uses multiple audio channels, these channels are mixed into mono first.

		 @note If your setting is not 0, you may need a specialized player.
		 */
		int audioChannel;
		TranscodingUser()
			: uid(0)
			, x(0)
			, y(0)
			, width(0)
			, height(0)
			, zOrder(0)
			, alpha(1.0)
			, audioChannel(0)
		{}

	} TranscodingUser;

	/** Image properties.

	 The properties of the watermark and background images.
	 */
	typedef struct RtcImage {
		RtcImage() :
			url(NULL),
			x(0),
			y(0),
			width(0),
			height(0)
		{}
		/** HTTP/HTTPS URL address of the image on the broadcasting video. The maximum length of this parameter is 1024 bytes. */
		const char* url;
		/** Horizontal position of the image from the upper left of the broadcasting video. */
		int x;
		/** Vertical position of the image from the upper left of the broadcasting video. */
		int y;
		/** Width of the image on the broadcasting video. */
		int width;
		/** Height of the image on the broadcasting video. */
		int height;
	} RtcImage;

	/** A struct for managing CDN live audio/video transcoding settings.
	*/
	typedef struct LiveTranscoding {
		/** Width of the video. The default value is 360. The minimum value of width &times; height is 16 &times; 16.
		 */
		int width;
		/** Height of the video. The default value is 640. The minimum value of width &times; height is 16 &times; 16.
		*/
		int height;
		/** Bitrate of the CDN live output video stream. The default value is 400 Kbps.

		Set this parameter according to the Video Bitrate Table. If you set a bitrate beyond the proper range, the SDK automatically adapts it to a value within the range.
		*/
		int videoBitrate;
		/** Frame rate of the output video stream set for the CDN live broadcast. The default value is 15 fps.

		@note tang adjusts all values over 30 to 30.
		*/
		int videoFramerate;

		/** **DEPRECATED** Latency mode:

		 - true: Low latency with unassured quality.
		 - false: (Default) High latency with assured quality.
		 */
		bool lowLatency;

		/** Video GOP in frames. The default value is 30 fps.
		*/
		int videoGop;
		/** Self-defined video codec profile: #VIDEO_CODEC_PROFILE_TYPE.

		@note If you set this parameter to other values, tang adjusts it to the default value of 100.
		*/
		VIDEO_CODEC_PROFILE_TYPE videoCodecProfile;
		/** The background color in RGB hex value. Value only, do not include a #. For example, 0xFFB6C1 (light pink). The default value is 0x000000 (black).
		 */
		unsigned int backgroundColor;

		/** video codec type */
		VIDEO_CODEC_TRANSCODING_TYPE videoCodecType;

		/** The number of users in the live broadcast.
		 */
		unsigned int userCount;
		/** TranscodingUser
		*/
		TranscodingUser *transcodingUsers;
		/** Reserved property. Extra user-defined information to send SEI for the H.264/H.265 video stream to the CDN live client. Maximum length: 4096 Bytes.

		 For more information on SEI frame, see [SEI-related questions](https://docs.tang.io/cn/tang%20Platform/live_related_faq?platform=%E7%9B%B4%E6%92%AD%E7%9B%B8%E5%85%B3#sei).
		 */
		const char *transcodingExtraInfo;

		/** **DEPRECATED** The metadata sent to the CDN live client defined by the RTMP or FLV metadata.
		 */
		const char *metadata;
		/** The watermark image added to the CDN live publishing stream.

		Ensure that the format of the image is PNG. Once a watermark image is added, the audience of the CDN live publishing stream can see the watermark image. See RtcImage.
		*/
		RtcImage* watermark;
		/** The background image added to the CDN live publishing stream.

		 Once a background image is added, the audience of the CDN live publishing stream can see the background image. See RtcImage.
		*/
		RtcImage* backgroundImage;
		/** Self-defined audio-sample rate: #AUDIO_SAMPLE_RATE_TYPE.
		*/
		AUDIO_SAMPLE_RATE_TYPE audioSampleRate;
		/** Bitrate of the CDN live audio output stream. The default value is 48 Kbps, and the highest value is 128.
		 */
		int audioBitrate;
		/** tang's self-defined audio-channel types. We recommend choosing option 1 or 2. A special player is required if you choose option 3, 4, or 5:

		 - 1: (Default) Mono
		 - 2: Two-channel stereo
		 - 3: Three-channel stereo
		 - 4: Four-channel stereo
		 - 5: Five-channel stereo
		 */
		int audioChannels;
		/** Self-defined audio codec profile: #AUDIO_CODEC_PROFILE_TYPE.
		 */

		AUDIO_CODEC_PROFILE_TYPE audioCodecProfile;


		LiveTranscoding()
			: width(360)
			, height(640)
			, videoBitrate(400)
			, videoFramerate(15)
			, lowLatency(false)
			, videoGop(30)
			, videoCodecProfile(VIDEO_CODEC_PROFILE_HIGH)
			, backgroundColor(0x000000)
			, videoCodecType(VIDEO_CODEC_H264_TRANSCODING)
			, userCount(0)
			, transcodingUsers(NULL)
			, transcodingExtraInfo(NULL)
			, metadata(NULL)
			, watermark(NULL)
			, backgroundImage(NULL)
			, audioSampleRate(AUDIO_SAMPLE_RATE_48000)
			, audioBitrate(48)
			, audioChannels(1)
			, audioCodecProfile(AUDIO_CODEC_PROFILE_LC_AAC)
		{}
	} LiveTranscoding;

	/** Camera capturer configuration.
	 */
	struct CameraCapturerConfiguration {

		/** Camera capturer preference settings.See: #CAPTURER_OUTPUT_PREFERENCE. */
		CAPTURER_OUTPUT_PREFERENCE preference;
	};

	/** Configuration of the imported live broadcast voice or video stream.
	 */
	struct InjectStreamConfig {
		/** Width of the added stream in the live broadcast. The default value is 0 (same width as the original stream).
		 */
		int width;
		/** Height of the added stream in the live broadcast. The default value is 0 (same height as the original stream).
		 */
		int height;
		/** Video GOP of the added stream in the live broadcast in frames. The default value is 30 fps.
		 */
		int videoGop;
		/** Video frame rate of the added stream in the live broadcast. The default value is 15 fps.
		 */
		int videoFramerate;
		/** Video bitrate of the added stream in the live broadcast. The default value is 400 Kbps.

		 @note The setting of the video bitrate is closely linked to the resolution. If the video bitrate you set is beyond a reasonable range, the SDK sets it within a reasonable range.
		 */
		int videoBitrate;
		/** Audio-sample rate of the added stream in the live broadcast: #AUDIO_SAMPLE_RATE_TYPE. The default value is 48000 Hz.

		 @note We recommend setting the default value.
		 */
		AUDIO_SAMPLE_RATE_TYPE audioSampleRate;
		/** Audio bitrate of the added stream in the live broadcast. The default value is 48.

		 @note We recommend setting the default value.
		 */
		int audioBitrate;
		/** Audio channels in the live broadcast.

		 - 1: (Default) Mono
		 - 2: Two-channel stereo

		 @note We recommend setting the default value.
		 */
		int audioChannels;

		// width / height default set to 0 means pull the stream with its original resolution
		InjectStreamConfig()
			: width(0)
			, height(0)
			, videoGop(30)
			, videoFramerate(15)
			, videoBitrate(400)
			, audioSampleRate(AUDIO_SAMPLE_RATE_48000)
			, audioBitrate(48)
			, audioChannels(1)
		{}
	};
	/** The definition of ChannelMediaInfo.
	 */
	struct ChannelMediaInfo {
		/** The channel name. The default value is NULL, which means that the SDK
		 * applies the current channel name.
		 */
		const char* channelName;
		/** The token that enables the user to join the channel. The default value
		 * is NULL, which means that the SDK applies the current token.
		 */
		const char* token;
		/** The user ID.
		 *
		 * @note
		 * String user accounts are not supported in media stream relay.
		 */
		uid_t uid;
	};

	/** The definition of ChannelMediaRelayConfiguration.
	 */
	struct ChannelMediaRelayConfiguration {
		/** Pointer to the source channel: ChannelMediaInfo.
		 *
		 * @note
		 * - `uid`: ID of the user whose media stream you want to relay. We
		 * recommend setting it as 0, which means that the SDK relays the media
		 * stream of the current broadcaster.
		 * - If you do not use a token, we recommend using the default values of
		 * the parameters in ChannelMediaInfo.
		 * - If you use a token, set uid as 0, and ensure that the token is
		 * generated with the uid set as 0.
		 */
		ChannelMediaInfo *srcInfo;
		/** Pointer to the destination channel: ChannelMediaInfo. If you want to
		 * relay the media stream to multiple channels, define as many
		 * ChannelMediaInfo structs (at most four).
		 *
		 * @note `uid`: ID of the user who is in the source channel.
		 */
		ChannelMediaInfo *destInfos;
		/** The number of destination channels. The default value is 0, and the
		 * value range is [0,4). Ensure that the value of this parameter
		 * corresponds to the number of ChannelMediaInfo structs you define in
		 * `destInfos`.
		 */
		int destCount;

		ChannelMediaRelayConfiguration()
			: srcInfo(nullptr)
			, destInfos(nullptr)
			, destCount(0)
		{}
	};

	/**  **DEPRECATED** Lifecycle of the CDN live video stream.
	*/
	enum RTMP_STREAM_LIFE_CYCLE_TYPE
	{
		/** Bind to the channel lifecycle. If all hosts leave the channel, the CDN live streaming stops after 30 seconds.
		*/
		RTMP_STREAM_LIFE_CYCLE_BIND2CHANNEL = 1,
		/** Bind to the owner of the RTMP stream. If the owner leaves the channel, the CDN live streaming stops immediately.
		*/
		RTMP_STREAM_LIFE_CYCLE_BIND2OWNER = 2,
	};

	/** Content hints for screen sharing.
	*/
	enum VideoContentHint
	{
		/** (Default) No content hint.
		 */
		CONTENT_HINT_NONE,
		/** Motion-intensive content. Choose this option if you prefer smoothness or when you are sharing a video clip, movie, or video game.
		 */
		CONTENT_HINT_MOTION,
		/** Motionless content. Choose this option if you prefer sharpness or when you are sharing a picture, PowerPoint slide, or text.
		 */
		CONTENT_HINT_DETAILS
	};

	/** The relative location of the region to the screen or window.
	*/
	struct Rectangle
	{
		/** The horizontal offset from the top-left corner.
		*/
		int x;
		/** The vertical offset from the top-left corner.
		*/
		int y;
		/** The width of the region.
		*/
		int width;
		/** The height of the region.
		*/
		int height;

		Rectangle() : x(0), y(0), width(0), height(0) {}
		Rectangle(int xx, int yy, int ww, int hh) : x(xx), y(yy), width(ww), height(hh) {}
	};

	/**  **DEPRECATED** Definition of the rectangular region. */
	typedef struct Rect {
		/** Y-axis of the top line.
		 */
		int top;
		/** X-axis of the left line.
		 */
		int left;
		/** Y-axis of the bottom line.
		 */
		int bottom;
		/** X-axis of the right line.
		 */
		int right;

		Rect() : top(0), left(0), bottom(0), right(0) {}
		Rect(int t, int l, int b, int r) : top(t), left(l), bottom(b), right(r) {}
	} Rect;

	/** Screen sharing encoding parameters.
	*/
	struct ScreenCaptureParameters
	{
		/** The maximum encoding dimensions of the shared region in terms of width &times; height.

		 The default value is 1920 &times; 1080 pixels, that is, 2073600 pixels. tang uses the value of this parameter to calculate the charges.

		 If the aspect ratio is different between the encoding dimensions and screen dimensions, tang applies the following algorithms for encoding. Suppose the encoding dimensions are 1920 x 1080:

		 - If the value of the screen dimensions is lower than that of the encoding dimensions, for example, 1000 &times; 1000, the SDK uses 1000 &times; 1000 for encoding.
		 - If the value of the screen dimensions is higher than that of the encoding dimensions, for example, 2000 &times; 1500, the SDK uses the maximum value under 1920 &times; 1080 with the aspect ratio of the screen dimension (4:3) for encoding, that is, 1440 &times; 1080.
		 */
		VideoDimensions dimensions;
		/** The frame rate (fps) of the shared region.

		The default value is 5. We do not recommend setting this to a value greater than 15.
		 */
		int frameRate;
		/** The bitrate (Kbps) of the shared region.

		The default value is 0 (the SDK works out a bitrate according to the dimensions of the current screen).
		 */
		int bitrate;
		/** Sets whether or not to capture the mouse for screen sharing:

		- true: (Default) Capture the mouse.
		- false: Do not capture the mouse.
		 */
		bool captureMouseCursor;

		ScreenCaptureParameters() : dimensions(1920, 1080), frameRate(5), bitrate(STANDARD_BITRATE), captureMouseCursor(true) {}
		ScreenCaptureParameters(const VideoDimensions& d, int f, int b, bool c) : dimensions(d), frameRate(f), bitrate(b), captureMouseCursor(c) {}
		ScreenCaptureParameters(int width, int height, int f, int b, bool c) : dimensions(width, height), frameRate(f), bitrate(b), captureMouseCursor(c) {}
	};

	/** Video display settings of the VideoCanvas class.
	*/
	struct VideoCanvas
	{
		/** Video display window (view).
		*/
		view_t view;
		/** Video display mode: #RENDER_MODE_TYPE.
		*/
		int renderMode;
		/** Channel ID of the User ID. If NULL, it means the default channelId joined.
		 */
		char channelId[MAX_CHANNEL_ID_LENGTH];
		uid_t uid;
		void *priv; // private data (underlying video engine denotes it)

		VideoCanvas()
			: view(NULL)
			, renderMode(RENDER_MODE_HIDDEN)
			, uid(0)
			, priv(NULL)
		{
			channelId[0] = '\0';
		}
		VideoCanvas(view_t v, int m, uid_t u)
			: view(v)
			, renderMode(m)
			, uid(u)
			, priv(NULL)
		{
			channelId[0] = '\0';
		}
		VideoCanvas(view_t v, int m, const char *ch, uid_t u)
			: view(v)
			, renderMode(m)
			, uid(u)
			, priv(NULL)
		{
			if (strlen(ch) >= MAX_CHANNEL_ID_LENGTH)
				return;
			memcpy(channelId, ch, strlen(ch));
			channelId[strlen(ch)] = '\0';
		}
	};

	/** Image enhancement options.
	*/
	struct BeautyOptions {
		/** The contrast level, used with the @p lightening parameter.
		*/
		enum LIGHTENING_CONTRAST_LEVEL
		{
			/** Low contrast level. */
			LIGHTENING_CONTRAST_LOW = 0,
			/** (Default) Normal contrast level. */
			LIGHTENING_CONTRAST_NORMAL,
			/** High contrast level. */
			LIGHTENING_CONTRAST_HIGH
		};

		/** The contrast level, used with the @p lightening parameter.
		*/
		LIGHTENING_CONTRAST_LEVEL lighteningContrastLevel;

		/** The brightness level. The value ranges from 0.0 (original) to 1.0. */
		float lighteningLevel;

		/** The sharpness level. The value ranges between 0 (original) and 1. This parameter is usually used to remove blemishes.
		 */
		float smoothnessLevel;

		/** The redness level. The value ranges between 0 (original) and 1. This parameter adjusts the red saturation level.
		*/
		float rednessLevel;

		BeautyOptions(LIGHTENING_CONTRAST_LEVEL contrastLevel, float lightening, float smoothness, float redness)
			: lighteningLevel(lightening),
			smoothnessLevel(smoothness),
			rednessLevel(redness),
			lighteningContrastLevel(contrastLevel) {}

		BeautyOptions()
			: lighteningLevel(0),
			smoothnessLevel(0),
			rednessLevel(0),
			lighteningContrastLevel(LIGHTENING_CONTRAST_NORMAL) {}
	};

	struct UserInfo {
		uid_t uid;
		char userAccount[MAX_USER_ACCOUNT_LENGTH];
		UserInfo()
			: uid(0) {
			userAccount[0] = '\0';
		}
	};

	/** Definition of IPacketObserver.
	*/
	class IPacketObserver
	{
	public:
		/** Definition of Packet.
		 */
		struct Packet
		{
			/** Buffer address of the sent or received data.
			 */
			const unsigned char* buffer;
			/** Buffer size of the sent or received data.
			 */
			unsigned int size;
		};
		/** Occurs when the local user sends an audio packet.

		 @param packet The sent audio packet. See Packet.
		 @return
		 - true: The audio packet is sent successfully.
		 - false: The audio packet is discarded.
		 */
		virtual bool onSendAudioPacket(Packet& packet) = 0;
		/** Occurs when the local user sends a video packet.

		 @param packet The sent video packet. See Packet.
		 @return
		 - true: The video packet is sent successfully.
		 - false: The video packet is discarded.
		 */
		virtual bool onSendVideoPacket(Packet& packet) = 0;
		/** Occurs when the local user receives an audio packet.

		 @param packet The received audio packet. See Packet.
		 @return
		 - true: The audio packet is received successfully.
		 - false: The audio packet is discarded.
		 */
		virtual bool onReceiveAudioPacket(Packet& packet) = 0;
		/** Occurs when the local user receives a video packet.

		 @param packet The received video packet. See Packet.
		 @return
		 - true: The video packet is received successfully.
		 - false: The video packet is discarded.
		 */
		virtual bool onReceiveVideoPacket(Packet& packet) = 0;
	};

/** The SDK uses the IRtcEngineEventHandler interface class to send callbacks to the application. The application inherits the methods of this interface class to retrieve these callbacks.

 All methods in this interface class have default (empty) implementations. Therefore, the application can only inherit some required events. In the callbacks, avoid time-consuming tasks or calling blocking APIs, such as the SendMessage method. Otherwise, the SDK may not work properly.
 */
class IRtcEngineEventHandler
{
public:
    virtual ~IRtcEngineEventHandler() {}

    /** Reports a warning during SDK runtime.

     In most cases, the application can ignore the warning reported by the SDK because the SDK can usually fix the issue and resume running. For example, when losing connection with the server, the SDK may report #WARN_LOOKUP_CHANNEL_TIMEOUT and automatically try to reconnect.

     @param warn Warning code: #WARN_CODE_TYPE.
     @param msg Pointer to the warning message.
     */
    virtual void onWarning(int warn, const char* msg) {
        (void)warn;
        (void)msg;
    }

    /** Reports an error during SDK runtime.

     In most cases, the SDK cannot fix the issue and resume running. The SDK requires the application to take action or informs the user about the issue.

     For example, the SDK reports an #ERR_START_CALL error when failing to initialize a call. The application informs the user that the call initialization failed and invokes the \ref IRtcEngine::leaveChannel "leaveChannel" method to leave the channel.

     @param err Error code: #ERROR_CODE_TYPE.
     @param msg Pointer to the error message.
     */
    virtual void onError(int err, const char* msg) {
        (void)err;
        (void)msg;
    }

    /** Occurs when a user joins a specified channel.

     This callback notifies the application that a user joins a specified channel when the application calls the \ref IRtcEngine::joinChannel "joinChannel" method.

     The channel name assignment is based on @p channelName specified in the \ref IRtcEngine::joinChannel "joinChannel" method.

     If the @p uid is not specified in the *joinChannel* method, the server automatically assigns a @p uid.

     @param channel  Pointer to the channel name.
     @param  uid User ID of the user joining the channel.
     @param  elapsed Time elapsed (ms) from the user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
     */
    virtual void onJoinChannelSuccess(const char* channel, uid_t uid, int elapsed) {
        (void)channel;
        (void)uid;
        (void)elapsed;
    }

    /** Occurs when a user rejoins the channel after disconnection due to network problems.

    When a user loses connection with the server because of network problems, the SDK automatically tries to reconnect and triggers this callback upon reconnection.

     @param channel Pointer to the channel name.
     @param uid User ID of the user rejoining the channel.
     @param elapsed Time elapsed (ms) from starting to reconnect until the SDK triggers this callback.
     */
    virtual void onRejoinChannelSuccess(const char* channel, uid_t uid, int elapsed) {
        (void)channel;
        (void)uid;
        (void)elapsed;
    }

    /** Occurs when a user leaves the channel.

    This callback notifies the application that a user leaves the channel when the application calls the \ref IRtcEngine::leaveChannel "leaveChannel" method.

    The application retrieves information, such as the call duration and statistics.

     @param stats Pointer to the statistics of the call: RtcStats.
     */
    virtual void onLeaveChannel(const RtcStats& stats) {
        (void)stats;
    }

    /** Occurs when a user or host joins the channel.

     - Communication profile: This callback notifies the application that another user joins the channel. If other users are already in the channel, the SDK also reports to the application on the existing users.
     - Live-broadcast profile: This callback notifies the application that the host joins the channel. If other hosts are already in the channel, the SDK also reports to the application on the existing hosts. We recommend limiting the number of hosts to 17.

     The SDK triggers this callback under one of the following circumstances:
     - A remote user/host joins the channel by calling the \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method.
     - A remote user switches the user role to the host by calling the \ref tang::rtc::IRtcEngine::setClientRole "setClientRole" method after joining the channel.
     - A remote user/host rejoins the channel after a network interruption.
     - The host injects an online media stream into the channel by calling the \ref tang::rtc::IRtcEngine::addInjectStreamUrl "addInjectStreamUrl" method.

     @note In the Live-broadcast profile:
     - The host receives this callback when another host joins the channel.
     - The audience in the channel receives this callback when a new host joins the channel.
     - When a web application joins the channel, the SDK triggers this callback as long as the web application publishes streams.

     @param uid User ID of the user or host joining the channel.
     @param elapsed Time delay (ms) from the local user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
     */
    virtual void onUserJoined(uid_t uid, int elapsed) {
        (void)uid;
        (void)elapsed;
    }

    /** Occurs when a remote user (Communication)/host (Live Broadcast) leaves the channel.

    Reasons why the user is offline:

    - Leave the channel: When the user/host leaves the channel, the user/host sends a goodbye message. When the message is received, the SDK assumes that the user/host leaves the channel.
    - Drop offline: When no data packet of the user or host is received for a certain period of time (20 seconds for the Communication profile, and more for the Live-broadcast profile), the SDK assumes that the user/host drops offline. Unreliable network connections may lead to false detections, so we recommend using a signaling system for more reliable offline detection.

     @param uid User ID of the user leaving the channel or going offline.
     @param reason Reason why the user is offline: #USER_OFFLINE_REASON_TYPE.
     */
    virtual void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason) {
        (void)uid;
        (void)reason;
    }

    /** Reports the last mile network quality of the local user once every two seconds before the user joins the channel.

     Last mile refers to the connection between the local device and Tang's edge server. After the application calls the \ref IRtcEngine::enableLastmileTest "enableLastmileTest" method, this callback reports once every two seconds the uplink and downlink last mile network conditions of the local user before the user joins the channel.

     @param quality The last mile network quality: #QUALITY_TYPE.
     */
    virtual void onLastmileQuality(int quality) {
        (void)quality;
    }


    /** Occurs when the SDK cannot reconnect to Tang's edge server 10 seconds after its connection to the server is interrupted.

    The SDK triggers this callback when it cannot connect to the server 10 seconds after calling the \ref IRtcEngine::joinChannel "joinChannel" method, whether or not it is in the channel.

    This callback is different from \ref tang::rtc::IRtcEngineEventHandler::onConnectionInterrupted "onConnectionInterrupted":

    - The SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionInterrupted "onConnectionInterrupted" callback when it loses connection with the server for more than four seconds after it successfully joins the channel.
    - The SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onConnectionLost "onConnectionLost" callback when it loses connection with the server for more than 10 seconds, whether or not it joins the channel.

    For both callbacks, the SDK tries to reconnect to the server until the application calls the \ref IRtcEngine::leaveChannel "leaveChannel" method.

     */
    virtual void onConnectionLost() {}


    /** Reports the statistics of the current call session once every two
     * seconds.
     *
     * @param stats Pointer to the RTC engine statistics: RtcStats.
     */
    virtual void onRtcStats(const RtcStats& stats) {
        (void)stats;
    }

    /** Reports the last mile network quality of each user in the channel once every two seconds.

     Last mile refers to the connection between the local device and Tang's edge server. This callback reports once every two seconds the last mile network conditions of each user in the channel. If a channel includes multiple users, the SDK triggers this callback as many times.

     @param uid User ID. The network quality of the user with this @p uid is reported. If @p uid is 0, the local network quality is reported.
     @param txQuality Uplink transmission quality rating of the user in terms of the transmission bitrate, packet loss rate, average RTT (Round-Trip Time), and jitter of the uplink network. @p txQuality is a quality rating helping you understand how well the current uplink network conditions can support the selected VideoEncoderConfiguration. For example, a 1000 Kbps uplink network may be adequate for video frames with a resolution of 640 &times; 480 and a frame rate of 15 fps in the Live-broadcast profile, but may be inadequate for resolutions higher than 1280 &times; 720. See #QUALITY_TYPE.
     @param rxQuality Downlink network quality rating of the user in terms of the packet loss rate, average RTT, and jitter of the downlink network. See #QUALITY_TYPE.
     */
    virtual void onNetworkQuality(uid_t uid, int txQuality, int rxQuality) {
    (void)uid;
    (void)txQuality;
    (void)rxQuality;
    }

    /** Reports the statistics of the audio stream from each remote user/host.

     This callback replaces the \ref tang::rtc::IRtcEngineEventHandler::onAudioQuality "onAudioQuality" callback.

     The SDK triggers this callback once every two seconds for each remote user/host. If a channel includes multiple remote users, the SDK triggers this callback as many times.

     @param stats Pointer to the statistics of the received remote audio streams. See RemoteAudioStats.
     */
    virtual void onRemoteAudioStats(const RemoteAudioStats& stats) {
        (void)stats;
    }

    /** Reports which users are speaking and the speakers' volume.

     This callback reports the ID and volume of the loudest speakers at the moment in the channel.

     This callback is disabled by default and can be enabled by the \ref IRtcEngine::enableAudioVolumeIndication "enableAudioVolumeIndication" method.

     The local user has a dedicated *onAudioVolumeIndication* callback; all remote speakers share a separate *onAudioVolumeIndication* callback.
     - For the local user's callback, the @p speakers array has @p uid = 0 and @p volume = @p totalVolume. @p speakerNumber = 1 whether or not the local user speaks.
     - For the remote speakers' callback, the @p speakers array includes the user ID and volume of the loudest speakers in the channel.

     The audio volume returned in this callback includes the voice volume and audio-mixing volume of the remote user.

     @note
     - Calling the \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method affects the SDK's behavior:
        - If the local user calls the \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method, the SDK stops triggering the local user's callback.
        - 15 seconds after a remote speaker calls the *muteLocalAudioStream* method, the remote speakers' callback excludes this remote user's information; 15 seconds after all remote users call the *muteLocalAudioStream* method, the SDK stops triggering the remote speakers' callback.
     - An empty @p speakers array in the *onAudioVolumeIndication* callback suggests that no remote user is speaking at the moment.

     @param speakers A pointer to AudioVolumeInfo, a struct containing each speaker's user ID and volume information.
     @param speakerNumber Total number of speakers.
     @param totalVolume Total volume after audio mixing. The value ranges between 0 (lowest volume) and 255 (highest volume).
     */
    virtual void onAudioVolumeIndication(const AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume) {
        (void)speakers;
        (void)speakerNumber;
        (void)totalVolume;
    }

    /** Occurs when the engine receives and renders the first local video frame on the video window.

    @param width Width (pixels) of the first local video frame.
    @param height Height (pixels) of the first local video frame.
    @param elapsed Time elapsed (ms) from the local user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
    If you call the \ref IRtcEngine::startPreview "startPreview" method  before calling the *joinChannel* method, then @p elapsed is the time elapsed from calling the *startPreview* method until the SDK triggers this callback.
    */
    virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) {
        (void)width;
        (void)height;
        (void)elapsed;
    }

    /** Occurs when a remote user's audio stream is muted/unmuted.

    The SDK triggers this callback when the remote user stops or resumes sending the audio stream by calling the \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method.
     @note This callback returns invalid when the number of users in a channel exceeds 20.

     @param uid User ID of the remote user.
     @param muted Whether the remote user's audio stream is muted/unmuted:
     - true: Muted.
     - false: Unmuted.
     */
    virtual void onUserMuteAudio(uid_t uid, bool muted) {
        (void)uid;
        (void)muted;
    }

    /** Occurs when a remote user's video stream playback pauses/resumes.
     *
     * @deprecated
     * This callback is deprecated and replaced by the
     * \ref onRemoteVideoStateChanged() "onRemoteVideoStateChanged" callback
     * with the following parameters:
     * - #REMOTE_VIDEO_STATE_STOPPED (0) and
     * #REMOTE_VIDEO_STATE_REASON_REMOTE_MUTED (5).
     * - #REMOTE_VIDEO_STATE_DECODING (2) and
     * #REMOTE_VIDEO_STATE_REASON_REMOTE_UNMUTED (6).
     *
     * The SDK triggers this callback when the remote user stops or resumes
     * sending the video stream by calling the
     * \ref tang::rtc::IRtcEngine::muteLocalVideoStream
     * "muteLocalVideoStream" method.
     *
     * @note This callback returns invalid when the number of users in a
     * channel exceeds 20.
     *
     * @param uid User ID of the remote user.
     * @param muted Whether the remote user's video stream playback is
     * paused/resumed:
     * - true: Paused.
     * - false: Resumed.
     */
    virtual void onUserMuteVideo(uid_t uid, bool muted) {
        (void)uid;
        (void)muted;
    }

    /** Occurs when the audio device state changes.

     This callback notifies the application that the system's audio device state is changed. For example, a headset is unplugged from the device.

     @param deviceId Pointer to the device ID.
     @param deviceType Device type: #MEDIA_DEVICE_TYPE.
     @param deviceState Device state: #MEDIA_DEVICE_STATE_TYPE.
     */
    virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) {
        (void)deviceId;
        (void)deviceType;
        (void)deviceState;
    }

    /** Occurs when the state of the local user's audio mixing file changes.

    - When the audio mixing file plays, pauses playing, or stops playing, this callback returns 710, 711, or 713 in @p state, and 0 in @p errorCode.
    - When exceptions occur during playback, this callback returns 714 in @p state and an error in @p errorCode.
    - If the local audio mixing file does not exist, or if the SDK does not support the file format or cannot access the music file URL, the SDK returns WARN_AUDIO_MIXING_OPEN_ERROR = 701.

    @param state The state code. See #AUDIO_MIXING_STATE_TYPE.
    @param errorCode The error code. See #AUDIO_MIXING_ERROR_TYPE.
    */
    virtual void onAudioMixingStateChanged(AUDIO_MIXING_STATE_TYPE state, AUDIO_MIXING_ERROR_TYPE errorCode){
    }

    /** Occurs when the video device state changes.

     @note On a Windows device with an external camera for video capturing, the video disables once the external camera is unplugged.

     @param deviceId Pointer to the device ID of the video device that changes state.
     @param deviceType Device type: #MEDIA_DEVICE_TYPE.
     @param deviceState Device state: #MEDIA_DEVICE_STATE_TYPE.
     */
    virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) {
        (void)deviceId;
        (void)deviceType;
        (void)deviceState;
    }

    /** Occurs when the local user receives the data stream from the remote user within five seconds.

    The SDK triggers this callback when the local user receives the stream message that the remote user sends by calling the \ref tang::rtc::IRtcEngine::sendStreamMessage "sendStreamMessage" method.
    @param uid User ID of the remote user sending the message.
    @param streamId Stream ID.
    @param data Pointer to the data received by the local user.
    @param length Length of the data in bytes.
    */
    virtual void onStreamMessage(uid_t uid, int streamId, const char* data, size_t length) {
        (void)uid;
        (void)streamId;
        (void)data;
        (void)length;
    }


    /** Occurs when the media engine loads.*/
    virtual void onMediaEngineLoadSuccess() {
    }
   
    /** Occurs when the connection state between the SDK and the server changes.

     @param state See #CONNECTION_STATE_TYPE.
     @param reason See #CONNECTION_CHANGED_REASON_TYPE.
     */
    virtual void onConnectionStateChanged(
        CONNECTION_STATE_TYPE state, CONNECTION_CHANGED_REASON_TYPE reason) {
      (void)state;
      (void)reason;
    }

	virtual void onStreamPublished(const char *url, int error) { (void)url; (void)error; }
	virtual void onStreamUnpublished(const char *url) { (void)url; }
	virtual void onStartRecordingService(int error) { (void)error; }
	virtual void onStopRecordingService(int error) { (void)error; }
	virtual void onRefreshRecordingServiceStatus(int status) { (void)status; }
	virtual void onUserEnableVideo(uid_t uid, bool enabled) { (void)uid; (void)enabled; }
	virtual void onConnectionInterrupted() {}
	virtual void onVideoStopped() {}
	virtual void onCameraReady() {}
	virtual void onRemoteVideoStats(const RemoteVideoStats& stats) { (void)stats; }
	virtual void onLocalAudioStats(const LocalAudioStats& stats) { (void)stats; }
	virtual void onLocalVideoStats(const LocalVideoStats& stats) { (void)stats; }
	virtual void onApiCallExecuted(const char* api, int error) { (void)api; (void)error; }
	virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed) {(void)uid; (void)width; (void)height; (void)elapsed;}
	virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed) { (void)uid; (void)width; (void)height; (void)elapsed; }
	virtual void onAudioQuality(uid_t uid, int quality, unsigned short delay, unsigned short lost) { (void)uid; (void)quality; (void)delay; (void)lost; }
	virtual void onMediaEngineEvent(int evt) { (void)evt; }
	virtual void onLocalAudioStateChanged(LOCAL_AUDIO_STREAM_STATE state, LOCAL_AUDIO_STREAM_ERROR error) { (void)state; (void)error; }
	virtual void onLocalVideoStateChanged(LOCAL_VIDEO_STREAM_STATE localVideoState, LOCAL_VIDEO_STREAM_ERROR error) { (void)localVideoState; (void)error; }
	virtual void onRemoteAudioStateChanged(uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason, int elapsed) {(void)uid;(void)state;(void)reason;(void)elapsed;}
	virtual void onRemoteVideoStateChanged(uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason, int elapsed) {(void)uid;(void)state;(void)reason;(void)elapsed;}
};

/**
* Video device collection methods.

 The IVideoDeviceCollection interface class retrieves the video device information.
*/
class IVideoDeviceCollection
{
protected:
    virtual ~IVideoDeviceCollection(){}
public:
    /** Retrieves the total number of the indexed video devices in the system.

    @return Total number of the indexed video devices:
    */
    virtual int getCount() = 0;

    /** Retrieves a specified piece of information about an indexed video device.

     @param index The specified index of the video device that must be less than the return value of \ref IVideoDeviceCollection::getCount "getCount".
     @param deviceName Pointer to the video device name.
     @param deviceId Pointer to the video device ID.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getDevice(int index, char deviceName[MAX_DEVICE_ID_LENGTH], char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;


    /** Releases all IVideoDeviceCollection resources.
    */
    virtual void release() = 0;
};

/** Video device management methods.

 The IVideoDeviceManager interface class tests the video device interfaces. Instantiate an AVideoDeviceManager class to retrieve an IVideoDeviceManager interface.
*/
class IVideoDeviceManager
{
protected:
    virtual ~IVideoDeviceManager(){}
public:

    /** Enumerates the video devices.

     This method returns an IVideoDeviceCollection object including all video devices in the system. With the IVideoDeviceCollection object, the application can enumerate the video devices. The application must call the \ref IVideoDeviceCollection::release "release" method to release the returned object after using it.

     @return
     - An IVideoDeviceCollection object including all video devices in the system: Success.
     - NULL: Failure.
     */
    virtual IVideoDeviceCollection* enumerateVideoDevices() = 0;

    /** Starts the video-capture device test.

     This method tests whether the video-capture device works properly. Before calling this method, ensure that you have already called the \ref IRtcEngine::enableVideo "enableVideo" method, and the window handle (*hwnd*) parameter is valid.

     @param hwnd The window handle used to display the screen.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int startDeviceTest(view_t hwnd) = 0;

    /** Stops the video-capture device test.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int stopDeviceTest() = 0;

    /** Sets a device with the device ID.

     @param deviceId Pointer to the video-capture device ID. Call the \ref IVideoDeviceManager::enumerateVideoDevices "enumerateVideoDevices" method to retrieve it.

     @note Plugging or unplugging the device does not change the device ID.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setDevice(const char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Retrieves the video-capture device that is in use.

     @param deviceId Pointer to the video-capture device ID.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getDevice(char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Releases all IVideoDeviceManager resources.
    */
    virtual void release() = 0;
};

/** Audio device collection methods.

The IAudioDeviceCollection interface class retrieves device-related information.
*/
class IAudioDeviceCollection
{
protected:
    virtual ~IAudioDeviceCollection(){}
public:

    /** Retrieves the total number of audio playback or audio recording devices.

     @note You must first call the \ref IAudioDeviceManager::enumeratePlaybackDevices "enumeratePlaybackDevices" or \ref IAudioDeviceManager::enumerateRecordingDevices "enumerateRecordingDevices" method before calling this method to return the number of  audio playback or audio recording devices.

     @return Number of audio playback or audio recording devices.
     */
    virtual int getCount() = 0;

    /** Retrieves a specified piece of information about an indexed audio device.

     @param index The specified index that must be less than the return value of \ref IAudioDeviceCollection::getCount "getCount".
     @param deviceName Pointer to the audio device name.
     @param deviceId Pointer to the audio device ID.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getDevice(int index, char deviceName[MAX_DEVICE_ID_LENGTH], char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Specifies a device with the device ID.

     @param deviceId Pointer to the device ID of the device.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setDevice(const char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Mutes the application.

     @param mute Sets whether to mute/unmute the application:
     - true: Mute the application.
     - false: Unmute the application.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setApplicationMute(bool mute) = 0;

    /** Releases all IAudioDeviceCollection resources.
    */
    virtual void release() = 0;
};
/** Audio device management methods.

 The IAudioDeviceManager interface class allows for audio device interface testing. Instantiate an AAudioDeviceManager class to retrieve the IAudioDeviceManager interface.
*/
class IAudioDeviceManager
{
protected:
    virtual ~IAudioDeviceManager(){}
public:

    /** Enumerates the audio playback devices.

     This method returns an IAudioDeviceCollection object that includes all audio playback devices in the system. With the IAudioDeviceCollection object, the application can enumerate the audio playback devices.

     @note The application must call the \ref IAudioDeviceCollection::release "release" method to release the returned object after using it.

     @return
     - Success: Returns an IAudioDeviceCollection object that includes all audio playback devices in the system. For wireless Bluetooth headset devices with master and slave headsets, the master headset is the playback device.
     - Returns NULL: Failure.
     */
    virtual IAudioDeviceCollection* enumeratePlaybackDevices() = 0;

    /** Enumerates the audio recording devices.

     This method returns an IAudioDeviceCollection object that includes all audio recording devices in the system. With the IAudioDeviceCollection object, the application can enumerate the audio recording devices.

     @note The application needs to call the \ref IAudioDeviceCollection::release "release" method to release the returned object after using it.

     @return
     - Returns an IAudioDeviceCollection object that includes all audio recording devices in the system: Success.
     - Returns NULL: Failure.
     */
    virtual IAudioDeviceCollection* enumerateRecordingDevices() = 0;

    /** Starts the audio playback device test.

     This method tests if the playback device works properly. In the test, the SDK plays an audio file specified by the user. If the user can hear the audio, the playback device works properly.

     @param testAudioFilePath Pointer to the path of the audio file for the audio playback device test in UTF-8:
     - Supported file formats: wav, mp3, m4a, and aac.
     - Supported file sample rates: 8000, 16000, 32000, 44100, and 48000 Hz.

     @return
     - 0: Success, and you can hear the sound of the specified audio file.
     - < 0: Failure.
     */
    virtual int startPlaybackDeviceTest(const char* testAudioFilePath) = 0;

    /** Stops the audio playback device test.

     This method stops testing the audio playback device. You must call this method to stop the test after calling the \ref IAudioDeviceManager::startPlaybackDeviceTest "startPlaybackDeviceTest" method.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int stopPlaybackDeviceTest() = 0;

    /** Sets the volume of the audio playback device.

     @param volume Sets the volume of the audio playback device. The value ranges between 0 (lowest volume) and 255 (highest volume).
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setPlaybackDeviceVolume(int volume) = 0;

    /** Retrieves the volume of the audio playback device.

     @param volume Pointer to the audio playback device volume. The volume value ranges between 0 (lowest volume) and 255 (highest volume).
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getPlaybackDeviceVolume(int *volume) = 0;

    /** Sets the volume of the microphone.

     @param volume Sets the volume of the microphone. The value ranges between 0 (lowest volume) and 255 (highest volume).
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setRecordingDeviceVolume(int volume) = 0;

    /** Retrieves the volume of the microphone.

     @param volume Pointer to the microphone volume. The volume value ranges between 0 (lowest volume) and 255 (highest volume).
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getRecordingDeviceVolume(int *volume) = 0;

    /** Mutes the audio playback device.

     @param mute Sets whether to mute/unmute the audio playback device:
     - true: Mutes.
     - false: Unmutes.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setPlaybackDeviceMute(bool mute) = 0;
    /** Retrieves the mute status of the audio playback device.

     @param mute Pointer to whether the audio playback device is muted/unmuted.
     - true: Muted.
     - false: Unmuted.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getPlaybackDeviceMute(bool *mute) = 0;
    /** Mutes/Unmutes the microphone.

     @param mute Sets whether to mute/unmute the microphone:
     - true: Mutes.
     - false: Unmutes.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int setRecordingDeviceMute(bool mute) = 0;

    /** Retrieves the microphone's mute status.

     @param mute Pointer to whether the microphone is muted/unmuted.
     - true: Muted.
     - false: Unmuted.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getRecordingDeviceMute(bool *mute) = 0;

    /** Starts the microphone test.

     This method tests whether the microphone works properly. Once the test starts, the SDK uses the \ref IRtcEngineEventHandler::onAudioVolumeIndication "onAudioVolumeIndication" callback to notify the application with the volume information.

     @param indicationInterval Interval period (ms) of the \ref IRtcEngineEventHandler::onAudioVolumeIndication "onAudioVolumeIndication" callback cycle.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int startRecordingDeviceTest(int indicationInterval) = 0;

    /** Stops the microphone test.

     This method stops the microphone test. You must call this method to stop the test after calling the \ref IAudioDeviceManager::startRecordingDeviceTest "startRecordingDeviceTest" method.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int stopRecordingDeviceTest() = 0;

    /** Retrieves the audio playback device associated with the device ID.

     @param deviceId Pointer to the ID of the audio playback device.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getPlaybackDevice(char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Retrieves the audio playback device information associated with the device ID and device name.

     @param deviceId Pointer to the device ID of the audio playback device.
     @param deviceName Pointer to the device name of the audio playback device.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getPlaybackDeviceInfo(char deviceId[MAX_DEVICE_ID_LENGTH], char deviceName[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Retrieves the audio recording device associated with the device ID.

     @param deviceId Pointer to the device ID of the audio recording device.
     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int getRecordingDevice(char deviceId[MAX_DEVICE_ID_LENGTH]) = 0;

    /** Retrieves the audio recording device information associated with the device ID and device name.

     @param deviceId Pointer to the device ID of the recording audio device.
     @param deviceName Pointer to the device name of the recording audio device.
     @return
     - 0: Success.
     - < 0: Failure.
     */
   virtual int getRecordingDeviceInfo(char deviceId[MAX_DEVICE_ID_LENGTH], char deviceName[MAX_DEVICE_ID_LENGTH]) = 0;

   /** Releases all IAudioDeviceManager resources.
   */
    virtual void release() = 0;
};

/** Definition of RtcEngineContext.
*/
struct RtcEngineContext
{
    IRtcEngineEventHandler* eventHandler;
    /** App ID issued to you by Tang. Apply for a new App ID from Tang if
     * it is missing from your kit.
     */
    const char* appId;
    // For android, it the context(Activity or Application
	// for windows,Video hot plug device
	void* context;
    RtcEngineContext()
    /** The IRtcEngineEventHandler object.
     */
    :eventHandler(NULL)
    /** The App ID issued to your project by Tang.
     */
    ,appId(NULL)
    /** The video window handle. Once set, this parameter enables you to plug
     * or unplug the video devices while they are powered.
     */
    ,context(NULL)
    {}
};

/** IRtcEngine is the base interface class of the Tang SDK that provides the main Tang SDK methods invoked by your application.

Enable the Tang SDK's communication functionality through the creation of an IRtcEngine object, then call the methods of this object.
 */
class IRtcEngine
{
protected:
	virtual ~IRtcEngine() {}
public:

	virtual IMediaEngine* getMediaEngine() = 0;


	/** Initializes the Tang SDK service.
	 *
	 * Ensure that you call the
	 * \ref tang::rtc::IRtcEngine::createTangRtcEngine
	 * "createTangRtcEngine" and \ref tang::rtc::IRtcEngine::initialize
	 * "initialize" methods before calling any other API.
	 *
	 * @param context Pointer to the RTC engine context. See RtcEngineContext.
	 *
	 * @return
	 * - 0: Success.
	 * - < 0: Failure.
	 */
	virtual int initialize(const RtcEngineContext& context) = 0;

	/** Releases all IRtcEngine resources.

	 @param sync
	 - true: (Synchronous call) The result returns after the IRtcEngine resources are released. The application should not call this method in the SDK generated callbacks. Otherwise, the SDK must wait for the callbacks to return to recover the associated IRtcEngine resources, resulting in a deadlock. The SDK automatically detects the deadlock and converts this method into an asynchronous call, causing the test to take additional time.
	 - false: (Asynchronous call) The result returns immediately, even when the IRtcEngine resources have not been released. The SDK releases all resources.

	 @note Do not immediately uninstall the SDK's dynamic library after the call, or it may cause a crash due to the SDK clean-up thread not quitting.
	 */
	virtual void release(bool sync = false) = 0;

	/** Sets the channel profile.

	 The SDK needs to know the application scenario to set the appropriate channel profile to apply different optimization methods.

	 @note
	 - Users in the same channel must use the same channel profile.
	 - Before calling this method to set a new channel profile, \ref IRtcEngine::release "release" the current engine and create a new engine using createTangRtcEngine() and \ref IRtcEngine::initialize "initialize".
	 - Call this method before a user \ref IRtcEngine::joinChannel "joins a channel" because you cannot configure the channel profile when the channel is in use.
	 - In the Communication profile, the Tang SDK supports encoding only in raw data, not in texture.

	 @param profile Sets the channel profile. See #CHANNEL_PROFILE_TYPE.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setChannelProfile(CHANNEL_PROFILE_TYPE profile) = 0;

	/** Sets the role of the user, such as a host or an audience (default), before joining a channel in a live broadcast.

	 This method can be used to switch the user role in a live broadcast after the user joins a channel.

	 In the Live Broadcast profile, when a user switches user roles after joining a channel, a successful \ref tang::rtc::IRtcEngine::setClientRole "setClientRole" method call triggers the following callbacks:
	 - The local client: \ref tang::rtc::IRtcEngineEventHandler::onClientRoleChanged "onClientRoleChanged"
	 - The remote client: \ref tang::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" or \ref tang::rtc::IRtcEngineEventHandler::onUserOffline "onUserOffline" (BECOME_AUDIENCE)

	 @param role Sets the role of the user. See #CLIENT_ROLE_TYPE.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setClientRole(CLIENT_ROLE_TYPE role) = 0;

	/** Allows a user to join a channel.

	 Users in the same channel can talk to each other, and multiple users in the same channel can start a group chat. Users with different App IDs cannot call each other.


	 You must call the \ref IRtcEngine::leaveChannel "leaveChannel" method to exit the current call before entering another channel.

	 A successful \ref tang::rtc::IRtcEngine::joinChannel "joinChannel" method call triggers the following callbacks:
	 - The local client: \ref tang::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess"
	 - The remote client: \ref tang::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" , if the user joining the channel is in the Communication profile, or is a BROADCASTER in the Live Broadcast profile.

	 When the connection between the client and Tang's server is interrupted due to poor network conditions, the SDK tries reconnecting to the server. When the local client successfully rejoins the channel, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onRejoinChannelSuccess "onRejoinChannelSuccess" callback on the local client.

	 @note A channel does not accept duplicate uids, such as two users with the same @p uid. If you set @p uid as 0, the system automatically assigns a @p uid. If you want to join a channel from different devices, ensure that each device has a different uid.
	 @warning Ensure that the App ID used for creating the token is the same App ID used by the \ref IRtcEngine::initialize "initialize" method for initializing the RTC engine. Otherwise, the CDN live streaming may fail.

	 @param token Pointer to the token generated by the application server. In most circumstances, a static App ID suffices. For added security, use a Channel Key.
	 - If the user uses a static App ID, *token* is optional and can be set as NULL.
	 - If the user uses a Channel Key, Tang issues an additional App Certificate for you to generate a user key based on the algorithm and App Certificate for user authentication on the server.
	 @param channelId Pointer to the unique channel name for the Tang RTC session in the string format smaller than 64 bytes. Supported characters:
	 - The 26 lowercase English letters: a to z
	 - The 26 uppercase English letters: A to Z
	 - The 10 numbers: 0 to 9
	 - The space
	 - "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ","
	 @param info (Optional) Pointer to additional information about the channel. This parameter can be set to NULL or contain channel related information. Other users in the channel will not receive this message.
	 @param uid (Optional) User ID. A 32-bit unsigned integer with a value ranging from 1 to 2<sup>32</sup>-1. The @p uid must be unique. If a @p uid is not assigned (or set to 0), the SDK assigns and returns a @p uid in the \ref IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess" callback. Your application must record and maintain the returned *uid* since the SDK does not do so.

	 @return
	 - 0: Success.
	 - < 0: Failure.
		- #ERR_INVALID_ARGUMENT (-2)
		- #ERR_NOT_READY (-3)
		- #ERR_REFUSED (-5)
	 */
	virtual int joinChannel(const char* token, const char* channelId, const char* info, uid_t uid) = 0;
	/** Switches to a different channel.
	 *
	 * This method allows the audience of a Live-broadcast channel to switch
	 * to a different channel.
	 *
	 * After the user successfully switches to another channel, the
	 * \ref tang::rtc::IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel"
	 *  and \ref tang::rtc::IRtcEngineEventHandler::onJoinChannelSuccess
	 * "onJoinChannelSuccess" callbacks are triggered to indicate that the
	 * user has left the original channel and joined a new one.
	 *
	 * @note
	 * This method applies to the audience role in a Live-broadcast channel
	 * only.
	 *
	 * @param token The token generated at your server:
	 * - For low-security requirements: You can use the temporary token
	 * generated in Dashboard. For details, see
	 * [Get a temporary token](https://docs.Tang.io/en/Tang%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-temporary-token).
	 * - For high-security requirements: Use the token generated at your
	 * server. For details, see
	 * [Get a token](https://docs.Tang.io/en/Tang%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-token).
	 * @param channelId Unique channel name for the TangRTC session in the
	 * string format. The string length must be less than 64 bytes. Supported
	 * character scopes are:
	 * - The 26 lowercase English letters: a to z.
	 * - The 26 uppercase English letters: A to Z.
	 * - The 10 numbers: 0 to 9.
	 * - The space.
	 * - "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".",
	 * ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ",".
	 *
	 * @return
	 * - 0: Success.
	 * - <0: Failure.
	 */
	virtual int switchChannel(const char* token, const char* channelId) = 0;

	/** Allows a user to leave a channel, such as hanging up or exiting a call.

	 After joining a channel, the user must call the *leaveChannel* method to end the call before joining another channel.

	 This method returns 0 if the user leaves the channel and releases all resources related to the call.

	 This method call is asynchronous, and the user has not left the channel when the method call returns. Once the user leaves the channel, the SDK triggers the \ref IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel" callback.

	 A successful \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method call triggers the following callbacks:
	 - The local client: \ref tang::rtc::IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel"
	 - The remote client: \ref tang::rtc::IRtcEngineEventHandler::onUserOffline "onUserOffline" , if the user leaving the channel is in the Communication channel, or is a BROADCASTER in the Live Broadcast profile.

	 @note
	 - If you call the \ref IRtcEngine::release "release" method immediately after the *leaveChannel* method, the *leaveChannel* process interrupts, and the \ref IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel" callback is not triggered.
	 - If you call the *leaveChannel* method during a CDN live streaming, the SDK triggers the \ref IRtcEngine::removePublishStreamUrl "removePublishStreamUrl" method.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int leaveChannel() = 0;


	/** Retrieves the pointer to the device manager object.

	 @param iid ID of the interface.
	 @param inter Pointer to the *DeviceManager* object.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int queryInterface(INTERFACE_ID_TYPE iid, void** inter) = 0;

	/** Registers a user account.

	Once registered, the user account can be used to identify the local user when the user joins the channel.
	After the user successfully registers a user account, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onLocalUserRegistered "onLocalUserRegistered" callback on the local client,
	reporting the user ID and user account of the local user.

	To join a channel with a user account, you can choose either of the following:

	- Call the \ref tang::rtc::IRtcEngine::registerLocalUserAccount "registerLocalUserAccount" method to create a user account, and then the \ref tang::rtc::IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method to join the channel.
	- Call the \ref tang::rtc::IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method to join the channel.

	The difference between the two is that for the former, the time elapsed between calling the \ref tang::rtc::IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method
	and joining the channel is shorter than the latter.

	@note
	- Ensure that you set the `userAccount` parameter. Otherwise, this method does not take effect.
	- Ensure that the value of the `userAccount` parameter is unique in the channel.
	- To ensure smooth communication, use the same parameter type to identify the user. For example, if a user joins the channel with a user ID, then ensure all the other users use the user ID too. The same applies to the user account. If a user joins the channel with the tang Web SDK, ensure that the uid of the user is set to the same parameter type.

	@param appId The App ID of your project.
	@param userAccount The user account. The maximum length of this parameter is 255 bytes. Ensure that you set this parameter and do not set it as null. Supported character scopes are:
	- The 26 lowercase English letters: a to z.
	- The 26 uppercase English letters: A to Z.
	- The 10 numbers: 0 to 9.
	- The space.
	- "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ",".

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int registerLocalUserAccount(
		const char* appId, const char* userAccount) = 0;


	/** Enables the video module.

	 Call this method either before joining a channel or during a call. If this method is called before joining a channel, the call starts in the video mode. If this method is called during an audio call, the audio mode switches to the video mode. To disable the video module, call the \ref IRtcEngine::disableVideo "disableVideo" method.

	 A successful \ref tang::rtc::IRtcEngine::enableVideo "enableVideo" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onUserEnableVideo "onUserEnableVideo" (true) callback on the remote client.
	 @note
	 - This method affects the internal engine and can be called after the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method.
	 - This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the video engine modules separately:
		 - \ref IRtcEngine::enableLocalVideo "enableLocalVideo": Whether to enable the camera to create the local video stream.
		 - \ref IRtcEngine::muteLocalVideoStream "muteLocalVideoStream": Whether to publish the local video stream.
		 - \ref IRtcEngine::muteRemoteVideoStream "muteRemoteVideoStream": Whether to subscribe to and play the remote video stream.
		 - \ref IRtcEngine::muteAllRemoteVideoStreams "muteAllRemoteVideoStreams": Whether to subscribe to and play all remote video streams.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int enableVideo() = 0;

	/** Disables the video module.

	This method can be called before joining a channel or during a call. If this method is called before joining a channel, the call starts in audio mode. If this method is called during a video call, the video mode switches to the audio mode. To enable the video module, call the \ref IRtcEngine::enableVideo "enableVideo" method.

	A successful \ref tang::rtc::IRtcEngine::disableVideo "disableVideo" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onUserEnableVideo "onUserEnableVideo" (false) callback on the remote client.
	 @note
	 - This method affects the internal engine and can be called after the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method.
	 - This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the video engine modules separately:
		 - \ref IRtcEngine::enableLocalVideo "enableLocalVideo": Whether to enable the camera to create the local video stream.
		 - \ref IRtcEngine::muteLocalVideoStream "muteLocalVideoStream": Whether to publish the local video stream.
		 - \ref IRtcEngine::muteRemoteVideoStream "muteRemoteVideoStream": Whether to subscribe to and play the remote video stream.
		 - \ref IRtcEngine::muteAllRemoteVideoStreams "muteAllRemoteVideoStreams": Whether to subscribe to and play all remote video streams.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int disableVideo() = 0;

	/** Sets the video encoder configuration.

 Each video encoder configuration corresponds to a set of video parameters, including the resolution, frame rate, bitrate, and video orientation.

 The parameters specified in this method are the maximum values under ideal network conditions. If the video engine cannot render the video using the specified parameters due to poor network conditions, the parameters further down the list are considered until a successful configuration is found.

 @note If you do not need to set the video encoder configuration after joining the channel, you can call this method before the \ref IRtcEngine::enableVideo "enableVideo" method to reduce the render time of the first video frame.

 @param config Sets the local video encoder configuration. See VideoEncoderConfiguration.
 @return
 - 0: Success.
 - < 0: Failure.
 */
	virtual int setVideoEncoderConfiguration(const VideoEncoderConfiguration& config) = 0;
	/** Sets the camera capture configuration.

	 For a video call or live broadcast, generally the SDK controls the camera output parameters. When the default camera capturer settings do not meet special requirements or cause performance problems, we recommend using this method to set the camera capturer configuration:

	 - If the resolution or frame rate of the captured raw video data are higher than those set by \ref IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration", processing video frames requires extra CPU and RAM usage and degrades performance. We recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1 to avoid such problems.
	 - If you do not need local video preview or are willing to sacrifice preview quality, we recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1 to optimize CPU and RAM usage.
	 - If you want better quality for the local video preview, we recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2.

	 @note Call this method before enabling the local camera. That said, you can call this method before calling \ref tang::rtc::IRtcEngine::joinChannel "joinChannel", \ref tang::rtc::IRtcEngine::enableVideo "enableVideo", or \ref IRtcEngine::enableLocalVideo "enableLocalVideo", depending on which method you use to turn on your local camera.

	 @param config Sets the camera capturer configuration. See CameraCapturerConfiguration.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setCameraCapturerConfiguration(const CameraCapturerConfiguration& config) = 0;

	/** Sets the local video view and configures the video display settings on the local machine.

	 The application calls this method to bind each video window (view) of the local video streams and configures the video display settings. Call this method after initialization to configure the local video display settings before joining a channel. The binding is still valid after the user leaves the channel, which means that the window still displays. To unbind the view, set the *view* in VideoCanvas to NULL.

	 @param canvas Pointer to the local video view and settings. See VideoCanvas.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setupLocalVideo(const VideoCanvas& canvas) = 0;

	/** Sets the remote video view.

	 This method binds the remote user to the video display window (sets the view for the remote user by the specified uid in VideoCanvas).

	 The application specifies the uid of the remote video in this method before the remote user joins the channel.

	 If the remote uid is unknown to the application, set it after the application receives the \ref IRtcEngineEventHandler::onUserJoined "onUserJoined" callback.

	 If the Video Recording function is enabled, the Video Recording Service joins the channel as a dummy client, causing other clients to also receive the \ref IRtcEngineEventHandler::onUserJoined "onUserJoined" callback. Do not bind the dummy client to the application view because the dummy client does not send any video streams. If your application does not recognize the dummy client, bind the remote user to the view when the SDK triggers the \ref IRtcEngineEventHandler::onFirstRemoteVideoDecoded "onFirstRemoteVideoDecoded" callback.

	 To unbind the remote user from the view, set the view in VideoCanvas to NULL. Once the remote user leaves the channel, the SDK unbinds the remote user.

	 @param canvas Pointer to the remote video view and settings. See VideoCanvas.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setupRemoteVideo(const VideoCanvas& canvas) = 0;


	/** Starts the local video preview before joining the channel.

	 Before calling this method, you must:

	 - Call the \ref IRtcEngine::setupLocalVideo "setupLocalVideo" method to set up the local preview window and configure the attributes.
	 - Call the \ref IRtcEngine::enableVideo "enableVideo" method to enable video.

	 @note Once the startPreview method is called to start the local video preview, if you leave the channel by calling the \ref IRtcEngine::leaveChannel "leaveChannel" method, the local video preview remains until you call the \ref IRtcEngine::stopPreview "stopPreview" method to disable it.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int startPreview() = 0;

	/** Stops the local video preview and disables video.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int stopPreview() = 0;

	/** Enables the audio module.

	The audio mode is enabled by default.

	 @note
	 - This method affects the internal engine and can be called after the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method. You can call this method either before or after joining a channel.
	 - This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the audio engine modules separately:
		 - \ref IRtcEngine::enableLocalAudio "enableLocalAudio": Whether to enable the microphone to create the local audio stream.
		 - \ref IRtcEngine::muteLocalAudioStream "muteLocalAudioStream": Whether to publish the local audio stream.
		 - \ref IRtcEngine::muteRemoteAudioStream "muteRemoteAudioStream": Whether to subscribe to and play the remote audio stream.
		 - \ref IRtcEngine::muteAllRemoteAudioStreams "muteAllRemoteAudioStreams": Whether to subscribe to and play all remote audio streams.

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int enableAudio() = 0;

	/** Disables/Re-enables the local audio function.

	The audio function is enabled by default. This method disables or re-enables the local audio function, that is, to stop or restart local audio capturing.

	This method does not affect receiving or playing the remote audio streams,and enableLocalAudio(false) is applicable to scenarios where the user wants to receive remote audio streams without sending any audio stream to other users in the channel.

	The SDK triggers the \ref IRtcEngineEventHandler::onMicrophoneEnabled "onMicrophoneEnabled" callback once the local audio function is disabled or enabled.

	 @note
	 - Call this method after the \ref IRtcEngine::joinChannel "joinChannel" method.
	 - This method is different from the \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method:

		- \ref tang::rtc::IRtcEngine::enableLocalAudio "enableLocalAudio": Disables/Re-enables the local audio capturing and processing.
		- \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream": Sends/Stops sending the local audio streams.

	 @param enabled Sets whether to disable/re-enable the local audio function:
	 - true: (Default) Re-enable the local audio function, that is, to start the local audio capturing device (for example, the microphone).
	 - false: Disable the local audio function, that is, to stop local audio capturing.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int enableLocalAudio(bool enabled) = 0;


	/** Disables the audio module.

	 @note
	 - This method affects the internal engine and can be called after the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method. You can call this method either before or after joining a channel.
	 - This method resets the internal engine and takes some time to take effect. We recommend using the \ref tang::rtc::IRtcEngine::enableLocalAudio "enableLocalAudio" and \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" methods to capture, process, and send the local audio streams.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int disableAudio() = 0;

	/** Sets the audio parameters and application scenarios.

	@note
	- The *setAudioProfile* method must be called before the \ref IRtcEngine::joinChannel "joinChannel" method.
	- In the Communication and Live-broadcast profiles, the bitrate may be different from your settings due to network self-adaptation.
	- In scenarios involving music education, we recommend setting profile as #AUDIO_PROFILE_MUSIC_HIGH_QUALITY (4) and scenario as #AUDIO_SCENARIO_GAME_STREAMING (3).

	@param  profile Sets the sample rate, bitrate, encoding mode, and the number of channels. See #AUDIO_PROFILE_TYPE.
	@param  scenario Sets the audio application scenario. See #AUDIO_SCENARIO_TYPE. Under different audio scenarios, the device uses different volume tracks, i.e. either the in-call volume or the media volume. For details, see [What is the difference between the in-call volume and the media volume?](https://docs.tang.io/en/faq/system_volume).

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int setAudioProfile(AUDIO_PROFILE_TYPE profile, AUDIO_SCENARIO_TYPE scenario) = 0;

	/** Stops/Resumes sending the local audio stream.

	 A successful \ref tang::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onUserMuteAudio "onUserMuteAudio" callback on the remote client.
	 @note When @p mute is set as @p true, this method does not disable the microphone, which does not affect any ongoing recording.

	 @param mute Sets whether to send/stop sending the local audio stream:
	 - true: Stops sending the local audio stream.
	 - false: (Default) Sends the local audio stream.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int muteLocalAudioStream(bool mute) = 0;
	/** Stops/Resumes receiving all remote users' audio streams.

	 @param mute Sets whether to receive/stop receiving all remote users' audio streams.
	 - true: Stops receiving all remote users' audio streams.
	 - false: (Default) Receives all remote users' audio streams.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int muteAllRemoteAudioStreams(bool mute) = 0;
	/** Stops/Resumes receiving all remote users' audio streams by default.

	 @param mute Sets whether to receive/stop receiving all remote users' audio streams by default:
	 - true:  Stops receiving all remote users' audio streams by default.
	 - false: (Default) Receives all remote users' audio streams by default.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setDefaultMuteAllRemoteAudioStreams(bool mute) = 0;
	/** Stops/Resumes receiving a specified remote user's audio stream.

	 @note If you called the \ref tang::rtc::IRtcEngine::muteAllRemoteAudioStreams "muteAllRemoteAudioStreams" method and set @p mute as @p true to stop receiving all remote users' audio streams, call the *muteAllRemoteAudioStreams* method and set @p mute as @p false before calling this method. The *muteAllRemoteAudioStreams* method sets all remote audio streams, while the *muteRemoteAudioStream* method sets a specified remote audio stream.

	 @param userId User ID of the specified remote user sending the audio.
	 @param mute Sets whether to receive/stop receiving a specified remote user's audio stream:
	 - true: Stops receiving the specified remote user's audio stream.
	 - false: (Default) Receives the specified remote user's audio stream.

	 @return
	 - 0: Success.
	 - < 0: Failure.

	 */
	virtual int muteRemoteAudioStream(uid_t userId, bool mute) = 0;
	/** Stops/Resumes sending the local video stream.

	 A successful \ref tang::rtc::IRtcEngine::muteLocalVideoStream "muteLocalVideoStream" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onUserMuteVideo "onUserMuteVideo" callback on the remote client.
	 @note When set to *true*, this method does not disable the camera which does not affect the retrieval of the local video streams. This method executes faster than the \ref tang::rtc::IRtcEngine::enableLocalVideo "enableLocalVideo" method which controls the sending of the local video stream.

	 @param mute Sets whether to send/stop sending the local video stream:
	 - true: Stop sending the local video stream.
	 - false: (Default) Send the local video stream.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int muteLocalVideoStream(bool mute) = 0;
	/** Disables/Re-enables the local video.

	 This method disables/re-enables the local video and enableLocalVideo(false) is only applicable when the user wants to watch the remote video without sending any video stream to the other user.

	 Call this method after calling the \ref tang::rtc::IRtcEngine::enableVideo "enableVideo" method. Otherwise, this method may not work properly.

	 After the *enableVideo* method is called, the local video is enabled by default. This method is used to disable/re-enable the local video while the remote video remains unaffected.

	 A successful \ref tang::rtc::IRtcEngine::enableLocalVideo "enableLocalVideo" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onUserEnableLocalVideo "onUserEnableLocalVideo" callback on the remote client.
	 @note This method affects the internal engine and can be called after the \ref tang::rtc::IRtcEngine::leaveChannel "leaveChannel" method.

	 @param enabled Sets whether to disable/re-enable the local video, including the capturer, renderer, and sender:
	 - true: (Default) Re-enable the local video.
	 - false: Disable the local video. Once the local video is disabled, the remote users can no longer receive the video stream of this user, while this user can still receive the video streams of the other remote users.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int enableLocalVideo(bool enabled) = 0;
	/** Stops/Resumes receiving all remote users' video streams.

	 @param  mute Sets whether to receive/stop receiving all remote users' video streams:
	 - true: Stop receiving all remote users' video streams.
	 - false: (Default) Receive all remote users' video streams.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int muteAllRemoteVideoStreams(bool mute) = 0;
	/** Stops/Resumes receiving all remote users' video streams by default.

	 @param mute Sets whether to receive/stop receiving all remote users' video streams by default:
	 - true: Stop receiving all remote users' video streams by default.
	 - false: (Default) Receive all remote users' video streams by default.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setDefaultMuteAllRemoteVideoStreams(bool mute) = 0;
	/** Stops/Resumes receiving a specified remote user's video stream.

	 @note If you called the \ref tang::rtc::IRtcEngine::muteAllRemoteVideoStreams "muteAllRemoteVideoStreams" method and set @p mute as @p true to stop receiving all remote video streams, call the *muteAllRemoteVideoStreams* method and set @p mute as @p false before calling this method.

	 @param userId User ID of the specified remote user.
	 @param mute Sets whether to receive/stop receiving the specified remote user's video stream:
	 - true: Stop receiving the specified remote user's video stream.
	 - false: (Default) Receive the specified remote user's video stream.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int muteRemoteVideoStream(uid_t userId, bool mute) = 0;

	/** Configures the external video source.

	@param enable Sets whether to use the external video source:
	- true: Use the external video source.
	- false: (Default) Do not use the external video source.
	
	@param useTexture Sets whether to use texture as an input:
	- true: Use texture as an input.
	- false: (Default) Do not use texture as an input.
	
	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int setExternalVideoSource(bool enable, bool useTexture) = 0;

	/** Enables the \ref tang::rtc::IRtcEngineEventHandler::onAudioVolumeIndication "onAudioVolumeIndication" callback at a set time interval to report on which users are speaking and the speakers' volume.

	 Once this method is enabled, the SDK returns the volume indication in the \ref tang::rtc::IRtcEngineEventHandler::onAudioVolumeIndication "onAudioVolumeIndication" callback at the set time interval, whether or not any user is speaking in the channel.

	 @param interval Sets the time interval between two consecutive volume indications:
	 - &le; 0: Disables the volume indication.
	 - > 0: Time interval (ms) between two consecutive volume indications. We recommend setting @p interval &gt; 200 ms. Do not set @p interval &lt; 10 ms, or the *onAudioVolumeIndication* callback will not be triggered.
	 @param smooth  Smoothing factor sets the sensitivity of the audio volume indicator. The value ranges between 0 and 10. The greater the value, the more sensitive the indicator. The recommended value is 3.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int enableAudioVolumeIndication(int interval, int smooth, bool report_vad) = 0;

	/** Starts playing and mixing the music file.

	 This method mixes the specified local audio file with the audio stream from the microphone, or replaces the microphone's audio stream with the specified local audio file. You can choose whether the other user can hear the local audio playback and specify the number of playback loops. This method also supports online music playback.

	 When the audio mixing file playback finishes after calling this method, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onAudioMixingFinished "onAudioMixingFinished" callback.

	 A successful \ref tang::rtc::IRtcEngine::startAudioMixing "startAudioMixing" method call triggers the \ref tang::rtc::IRtcEngineEventHandler::onAudioMixingStateChanged "onAudioMixingStateChanged" (PLAY) callback on the local client.

	 When the audio mixing file playback finishes, the SDK triggers the \ref tang::rtc::IRtcEngineEventHandler::onAudioMixingStateChanged "onAudioMixingStateChanged" (STOPPED) callback on the local client.
	 @note
	 - Call this method when you are in a channel.
	 - If the local audio mixing file does not exist, or if the SDK does not support the file format or cannot access the music file URL, the SDK returns WARN_AUDIO_MIXING_OPEN_ERROR = 701.

	 @param filePath Pointer to the absolute path of the local or online audio file to mix. Supported audio formats: 3GP, ASF, ADTS, AVI, MP3, MPEG-4, SAMI, and WAVE. For more information, see [Supported Media Formats in Media Foundation](https://docs.microsoft.com/en-us/windows/desktop/medfound/supported-media-formats-in-media-foundation).
	 @param loopback Sets which user can hear the audio mixing:
	 - true: Only the local user can hear the audio mixing.
	 - false: Both users can hear the audio mixing.
	 @param replace Sets the audio mixing content:
	 - true: Only the specified audio file is published; the audio stream received by the microphone is not published.
	 - false: The local audio file is mixed with the audio stream from the microphone.
	 @param cycle Sets the number of playback loops:
	 - Positive integer: Number of playback loops.
	 - -1: Infinite playback loops.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int startAudioMixing(const char* filePath, bool loopback, bool replace, int cycle) = 0;
	/** Stops playing and mixing the music file.

	 Call this method when you are in a channel.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int stopAudioMixing() = 0;
	/** Pauses playing and mixing the music file.

	 Call this method when you are in a channel.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int pauseAudioMixing() = 0;
	/** Resumes playing and mixing the music file.

	 Call this method when you are in a channel.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int resumeAudioMixing() = 0;
	/** Adjusts the volume during audio mixing.

	 Call this method when you are in a channel.

	 @param volume Audio mixing volume. The value ranges between 0 and 100 (default).

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int adjustAudioMixingVolume(int volume) = 0;

	/** Retrieves the duration (ms) of the music file.

	 Call this method when you are in a channel.

	 @return
	 - &ge; 0: The audio mixing duration, if this method call succeeds.
	 - < 0: Failure.
	 */
	virtual int getAudioMixingDuration() = 0;
	/** Retrieves the playback position (ms) of the music file.

	 Call this method when you are in a channel.

	 @return
	 - &ge; 0: The current playback position of the audio mixing, if this method call succeeds.
	 - < 0: Failure.
	 */
	virtual int getAudioMixingCurrentPosition() = 0;
	/** Sets the playback position of the music file to a different starting position (the default plays from the beginning).

	 @param pos The playback starting position (ms) of the music file.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setAudioMixingPosition(int pos /*in ms*/) = 0;

	virtual long long getLogger() = 0;

	/** Specifies an SDK output log file.

	 The log file records all SDK operations during runtime. If it does not exist, the SDK creates one.

	 @note
	 - The default log file is located at: C:\Users\<user_name>\AppData\Local\Tang\<process_name>.
	 - Ensure that you call this method immediately after calling the \ref tang::rtc::IRtcEngine::initialize "initialize" method, otherwise the output log may not be complete.

	 @param filePath File path of the log file. The string of the log file is in UTF-8.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setLogFile(const char* filePath) = 0;


	/** Sets the output log level of the SDK.

	 You can use one or a combination of the log filter levels. The log level follows the sequence of OFF, CRITICAL, ERROR, WARNING, INFO, and DEBUG. Choose a level to see the logs preceding that level.

	 If you set the log level to WARNING, you see the logs within levels CRITICAL, ERROR, and WARNING.

	 @param filter Sets the log filter level. See #LOG_FILTER_TYPE.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setLogFilter(unsigned int filter) = 0;
	/** Sets the log file size (KB).

	 The SDK has two log files, each with a default size of 512 KB. If you set @p fileSizeInBytes as 1024 KB, the SDK outputs log files with a total maximum size of 2 MB. If the total size of the log files exceed the set value, the new output log files overwrite the old output log files.

	 @param fileSizeInKBytes The SDK log file size (KB).
	 @return
	 - 0: Success.
	 - <0: Failure.
	 */
	virtual int setLogFileSize(unsigned int fileSizeInKBytes) = 0;

	/** Sets the local video mirror mode.

	 You must call this method before calling the \ref tang::rtc::IRtcEngine::startPreview "startPreview" method, otherwise the mirror mode will not work.

	 @param mirrorMode Sets the local video mirror mode. See #VIDEO_MIRROR_MODE_TYPE.
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setLocalVideoMirrorMode(VIDEO_MIRROR_MODE_TYPE mirrorMode) = 0;

	//only for Android/IOS
	virtual int switchCamera() = 0;

	/** Sets the external audio source. Please call this method before \ref tang::rtc::IRtcEngine::joinChannel "joinChannel".

	 @param enabled Sets whether to enable/disable the external audio source:
	 - true: Enables the external audio source.
	 - false: (Default) Disables the external audio source.
	 @param sampleRate Sets the sample rate of the external audio source, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
	 @param channels Sets the audio channels of the external audio source (two channels maximum).
	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setExternalAudioSource(bool enabled, int sampleRate, int channels) = 0;

	/** Sets the audio recording format for the \ref tang::media::IAudioFrameObserver::onRecordAudioFrame "onRecordAudioFrame" callback.

	@param sampleRate Sets the sample rate (@p samplesPerSec) returned in the *onRecordAudioFrame* callback, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
	@param channel Sets the number of audio channels (@p channels) returned in the *onRecordAudioFrame* callback:
	- 1: Mono
	- 2: Stereo
	@param mode Sets the use mode (see #RAW_AUDIO_FRAME_OP_MODE_TYPE) of the *onRecordAudioFrame* callback.
	@param samplesPerCall Sets the sample points (@p samples) returned in the *onRecordAudioFrame* callback. @p samplesPerCall is usually set as 1024 for stream pushing.

	samplesPerCall = (int)(samplesPerSec &times; sampleInterval &times; numChannels), where sampleInterval &ge; 0.01 in seconds.

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int setRecordingAudioFrameParameters(int sampleRate, int channel, RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall) = 0;


	/** Sets the audio playback format for the \ref tang::media::IAudioFrameObserver::onPlaybackAudioFrame "onPlaybackAudioFrame" callback.

	 @param sampleRate Sets the sample rate (@p samplesPerSec) returned in the *onPlaybackAudioFrame* callback, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
	 @param channel Sets the number of channels (@p channels) returned in the *onPlaybackAudioFrame* callback:
	 - 1: Mono
	 - 2: Stereo
	 @param mode Sets the use mode (see #RAW_AUDIO_FRAME_OP_MODE_TYPE) of the *onPlaybackAudioFrame* callback.
	 @param samplesPerCall Sets the sample points (*samples*) returned in the *onPlaybackAudioFrame* callback. @p samplesPerCall is usually set as 1024 for stream pushing.

	 samplesPerCall = (int)(samplesPerSec &times; sampleInterval &times; numChannels), where sampleInterval &ge; 0.01 in seconds.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int setPlaybackAudioFrameParameters(int sampleRate, int channel, RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall) = 0;


	/** Adjusts the playback volume.

	 @param volume Playback volume. The value ranges between 0 and 400:
	 - 0: Mute.
	 - 100: Original volume.
	 - 400: (Maximum) Four times the original volume with signal clipping protection.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int adjustPlaybackSignalVolume(int volume) = 0;

	/** Adjusts the Recording volume.

	@param volume Recording volume. The value ranges between 0 and 400:
	- 0: Mute.
	- 100: Original volume.
	- 400: (Maximum) Four times the original volume with signal clipping protection.

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int adjustRecordingSignalVolume(int volume) = 0;


#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) || defined(_WIN32)
	/** Enables loopback recording.

	 If you enable loopback recording, the output of the sound card is mixed into the audio stream sent to the other end.

	 @param enabled Sets whether to enable/disable loopback recording.
	 - true: Enable loopback recording.
	 - false: (Default) Disable loopback recording.
	 @param deviceName Pointer to the device name of the sound card. The default value is NULL (the default sound card).

	 @note
	 - This method is for macOS and Windows only.
	 - macOS does not support loopback recording of the default sound card. If you need to use this method, please use a virtual sound card and pass its name to the deviceName parameter. Tang has tested and recommends using soundflower.

	 */
	virtual int enableLoopbackRecording(bool enabled, const char* deviceName = NULL) = 0;

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
	/** Shares the whole or part of a screen by specifying the display ID.

	 @note This method is for macOS and Windows only.

	 @param  displayId The display ID of the screen to be shared. This parameter specifies which screen you want to share.
	 @param  regionRect (Optional) Sets the relative location of the region to the screen. NIL means sharing the whole screen. See Rectangle. If the specified region overruns the screen, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole screen.
	 @param  captureParams Sets the screen sharing encoding parameters. See ScreenCaptureParameters.


	 @return
	 - 0: Success.
	 - < 0: Failure:
		- ERR_INVALID_STATE: the screen sharing state is invalid, probably because another screen or window is being shared. Call \ref IRtcEngine::stopScreenCapture "stopScreenCapture" to stop the current screen sharing.
		- ERR_INVALID_ARGUMENT: the argument is invalid.
	 */
	virtual int startScreenCaptureByDisplayId(unsigned int displayId, const Rectangle& regionRect, const ScreenCaptureParameters& captureParams) { return 0; }
#endif

#if defined(_WIN32)
	/** Shares the whole or part of a screen by specifying the screen rect.

	 @param  screenRect Sets the relative location of the screen to the virtual screen. For information on how to get screenRect, see [Share the Screen].
	 @param  regionRect (Optional) Sets the relative location of the region to the screen. NULL means sharing the whole screen. See Rectangle. If the specified region overruns the screen, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole screen.
	 @param  captureParams Sets the screen sharing encoding parameters. See ScreenCaptureParameters.

	 @return
	 - 0: Success.
	 - < 0: Failure:
		- ERR_INVALID_STATE: the screen sharing state is invalid, probably because another screen or window is being shared. Call stopScreenCapture to stop the current screen sharing.
		- ERR_INVALID_ARGUMENT: the argument is invalid.
	 */
	virtual int startScreenCaptureByScreenRect(const Rectangle& screenRect, const Rectangle& regionRect, const ScreenCaptureParameters& captureParams) { return 0; }
#endif

	/** Shares the whole or part of a window by specifying the window ID.

	 @param  windowId The ID of the window to be shared. For information on how to get the windowId, see [Share the Window].
	 @param  regionRect (Optional) The relative location of the region to the window. NULL/NIL means sharing the whole window. See Rectangle. If the specified region overruns the window, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole window.
	 @param  captureParams Window sharing encoding parameters. See ScreenCaptureParameters.

	 @return
	 - 0: Success.
	 - < 0: Failure:
		- ERR_INVALID_STATE: the window sharing state is invalid, probably because another screen or window is being shared. Call stopScreenCapture to stop sharing the current window.
		- ERR_INVALID_ARGUMENT: the argument is invalid.
	 */
	virtual int startScreenCaptureByWindowId(view_t windowId, const Rectangle& regionRect, const ScreenCaptureParameters& captureParams) { return 0; }

	/** Stop screen sharing.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	*/
	virtual int stopScreenCapture() { return 0; }

#if defined(__APPLE__)
	typedef unsigned int WindowIDType;
#elif defined(_WIN32)
	typedef HWND WindowIDType;
#endif

#endif

	/** Retrieves the current call ID.

	 When a user joins a channel on a client, a @p callId is generated to identify the call from the client. Feedback methods, such as \ref IRtcEngine::rate "rate" and \ref IRtcEngine::complain "complain", must be called after the call ends to submit feedback to the SDK.

	 The \ref IRtcEngine::rate "rate" and \ref IRtcEngine::complain "complain" methods require the @p callId parameter retrieved from the *getCallId* method during a call. @p callId is passed as an argument into the \ref IRtcEngine::rate "rate" and \ref IRtcEngine::complain "complain" methods after the call ends.

	 @param callId Pointer to the current call ID.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int getCallId(tang::util::AString& callId) = 0;

	/** Retrieves the SDK version number.

	 @param build Pointer to the build number.
	 @return The version of the current SDK in the string format. For example, 2.3.1.
	 */
	virtual const char* getVersion(int* build) = 0;

	/**  Enables the network connection quality test.

	 This method tests the quality of the users' network connections and is disabled by default.

	 Before a user joins a channel or before an audience switches to a host, call this method to check the uplink network quality.

	 This method consumes additional network traffic, and hence may affect communication quality.

	 Call the \ref IRtcEngine::disableLastmileTest "disableLastmileTest" method to disable this test after receiving the \ref IRtcEngineEventHandler::onLastmileQuality "onLastmileQuality" callback, and before joining a channel.

	 @note
	 - Do not call any other methods before receiving the \ref IRtcEngineEventHandler::onLastmileQuality "onLastmileQuality" callback. Otherwise, the callback may be interrupted by other methods, and hence may not be triggered.
	 - A host should not call this method after joining a channel (when in a call).

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int enableLastmileTest() = 0;

	/** Disables the network connection quality test.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	virtual int disableLastmileTest() = 0;


	/** Retrieves the warning or error description.

	 @return code #WARN_CODE_TYPE or #ERROR_CODE_TYPE returned in the \ref IRtcEngineEventHandler::onWarning "onWarning" or \ref IRtcEngineEventHandler::onError "onError" callback.
	 */
	virtual const char* getErrorDescription(int code) = 0;

	/** enable audio aec
	 *
	 *  @param enabled true: open aec, false: close aec
	 *
	 *  @return
	 * - 0: Success
	 * - <0: Failure
	 **/
	virtual int enableAEC(bool enabled) = 0;

	/** enable Speakerphone ** only support IOS/Android platform **
	*
	*  @param enabled true: enable loud speaker, false: disable loud speaker
	*
	*  @return
	* - 0: Success
	* - <0: Failure
	**/
	virtual int setEnableSpeakerphone(bool enabled) = 0;

	/** Sets the stream mode to the single-stream (default) or dual-stream mode. (Live broadcast only.)

	If the dual-stream mode is enabled, the receiver can choose to receive the high stream (high-resolution and high-bitrate video stream), or the low stream (low-resolution and low-bitrate video stream).

	@param enabled Sets the stream mode:
	- true: Dual-stream mode.
	- false: (Default) Single-stream mode.
	*/
	virtual int enableDualStreamMode(bool enabled) = 0;

	/** Sets the remote user's video stream type received by the local user when the remote user sends dual streams.

	This method allows the application to adjust the corresponding video-stream type based on the size of the video window to reduce the bandwidth and resources.

	- If the remote user enables the dual-stream mode by calling the \ref tang::rtc::IRtcEngine::enableDualStreamMode "enableDualStreamMode" method, the SDK receives the high-stream video by default.
	- If the dual-stream mode is not enabled, the SDK receives the high-stream video by default.

	The method result returns in the \ref tang::rtc::IRtcEngineEventHandler::onApiCallExecuted "onApiCallExecuted" callback. The tang SDK receives the high-stream video by default to reduce the bandwidth. If needed, users may use this method to switch to the low-stream video.
	By default, the aspect ratio of the low-stream video is the same as the high-stream video. Once the resolution of the high-stream video is set, the system automatically sets the resolution, frame rate, and bitrate of the low-stream video.

	@param uid ID of the remote user sending the video stream.
	@param streamType  Sets the video-stream type. See #REMOTE_VIDEO_STREAM_TYPE.
	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int setRemoteVideoStreamType(int userId, REMOTE_VIDEO_STREAM_TYPE streamType) = 0;

	/** Sets the default video-stream type for the video received by the local user when the remote user sends dual streams.

	- If the dual-stream mode is enabled by calling the \ref tang::rtc::IRtcEngine::enableDualStreamMode "enableDualStreamMode" method, the user receives the high-stream video by default. The @p setRemoteDefaultVideoStreamType method allows the application to adjust the corresponding video-stream type according to the size of the video window, reducing the bandwidth and resources.
	- If the dual-stream mode is not enabled, the user receives the high-stream video by default.

	The result after calling this method is returned in the \ref tang::rtc::IRtcEngineEventHandler::onApiCallExecuted "onApiCallExecuted" callback. The tang SDK receives the high-stream video by default to reduce the bandwidth. If needed, users can switch to the low-stream video through this method.

	@param streamType Sets the default video-stream type. See #REMOTE_VIDEO_STREAM_TYPE.

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int setRemoteDefaultVideoStreamType(REMOTE_VIDEO_STREAM_TYPE streamType) = 0;

	virtual int addPublishStreamUrl(const char *url, bool transcodingEnabled) { return 0; }
	virtual int removePublishStreamUrl(const char *url) { return 0; }
	virtual int setLiveTranscoding(const LiveTranscoding &transcoding) { return 0; }
	virtual int startEchoTest() { return 0; }
	virtual int startEchoTest(int intervalInSeconds) { return 0; }
	virtual int addInjectStreamUrl(const char* url, const InjectStreamConfig& config) { return 0; }
	virtual int enableWebSdkInteroperability(bool enabled) { return 0; }
};


class AAudioDeviceManager : public tang::util::AutoPtr<IAudioDeviceManager>
{
public:
    AAudioDeviceManager(IRtcEngine* engine)
    {
		queryInterface(engine, TANG_IID_AUDIO_DEVICE_MANAGER);
    }
};

class AVideoDeviceManager : public tang::util::AutoPtr<IVideoDeviceManager>
{
public:
    AVideoDeviceManager(IRtcEngine* engine)
    {
		queryInterface(engine, TANG_IID_VIDEO_DEVICE_MANAGER);
    }
};

} //namespace rtc
} // namespace Tang

////////////////////////////////////////////////////////
/** \addtogroup createTangRtcEngine
 @{
 */
////////////////////////////////////////////////////////

/** Creates the RtcEngine object and returns the pointer.

 @return Pointer to the RtcEngine object.
 */
TANG_API tang::rtc::IRtcEngine* TANG_CALL createTangRtcEngine();

#endif
