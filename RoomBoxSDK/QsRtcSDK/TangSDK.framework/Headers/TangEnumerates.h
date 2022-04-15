//
// TangEnumerates.h
// TangRtcEngineKit
//
// Copyright (c) 2018 Tang. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Warning code.

Warning codes occur when the SDK encounters an error that may be recovered automatically. These are only notifications, and can generally be ignored. For example, when the SDK loses connection to the server, the SDK reports the TangWarningCodeOpenChannelTimeout(106) warning and tries to reconnect automatically.
*/
typedef NS_ENUM(NSInteger, TangWarningCode) {
    /** 8: The specified view is invalid. Specify a view when using the video call function. */
    TangWarningCodeInvalidView = 8,
    /** 16: Failed to initialize the video function, possibly caused by a lack of resources. The users cannot see the video while the voice communication is not affected. */
    TangWarningCodeInitVideo = 16,
     /** 20: The request is pending, usually due to some module not being ready, and the SDK postpones processing the request. */
    TangWarningCodePending = 20,
    /** 103: No channel resources are available. Maybe because the server cannot allocate any channel resource. */
    TangWarningCodeNoAvailableChannel = 103,
    /** 104: A timeout occurs when looking up the channel. When joining a channel, the SDK looks up the specified channel. The warning usually occurs when the network condition is too poor for the SDK to connect to the server. */
    TangWarningCodeLookupChannelTimeout = 104,
    /** 105: The server rejects the request to look up the channel. The server cannot process this request or the request is illegal.
     <br></br><b>DEPRECATED</b> as of v2.4.1. Use TangConnectionChangedRejectedByServer(10) in the `reason` parameter of [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]).
     */
    TangWarningCodeLookupChannelRejected = 105,
    /** 106: The server rejects the request to look up the channel. The server cannot process this request or the request is illegal. */
    TangWarningCodeOpenChannelTimeout = 106,
    /** 107: The server rejects the request to open the channel. The server cannot process this request or the request is illegal. */
    TangWarningCodeOpenChannelRejected = 107,
    /** 111: A timeout occurs when switching to the live video. */
    TangWarningCodeSwitchLiveVideoTimeout = 111,
    /** 118: A timeout occurs when setting the client role in the live broadcast profile. */
    TangWarningCodeSetClientRoleTimeout = 118,
    /** 119: The client role is unauthorized. */
    TangWarningCodeSetClientRoleNotAuthorized = 119,
    /** 121: The ticket to open the channel is invalid. */
    TangWarningCodeOpenChannelInvalidTicket = 121,
    /** 122: Try connecting to another server. */
    TangWarningCodeOpenChannelTryNextVos = 122,
    /** 701: An error occurs in opening the audio mixing file. */
    TangWarningCodeAudioMixingOpenError = 701,
    /** 1014: Audio Device Module: a warning occurs in the playback device. */
    TangWarningCodeAdmRuntimePlayoutWarning = 1014,
    /** 1016: Audio Device Module: a warning occurs in the recording device. */
    TangWarningCodeAdmRuntimeRecordingWarning = 1016,
    /** 1019: Audio Device Module: no valid audio data is collected. */
    TangWarningCodeAdmRecordAudioSilence = 1019,
    /** 1020: Audio Device Module: a playback device fails. */
    TangWarningCodeAdmPlaybackMalfunction = 1020,
    /** 1021: Audio Device Module: a recording device fails. */
    TangWarningCodeAdmRecordMalfunction = 1021,
    /** 1025: The system interrupts the audio session, and the session is no longer active. */
    TangWarningCodeAdmInterruption = 1025,
    /** 1031: Audio Device Module: the recorded audio is too low. */
    TangWarningCodeAdmRecordAudioLowlevel = 1031,
    /** 1032: Audio Device Module: the playback audio is too low. */
    TangWarningCodeAdmPlayoutAudioLowlevel = 1032,
    /** 1051: Audio Device Module: howling is detected. */
    TangWarningCodeApmHowling = 1051,
    /** 1052: Audio Device Module: the device is in the glitch state. */
    TangWarningCodeAdmGlitchState = 1052,
    /** 1053: Audio Device Module: the underlying audio settings have changed. */
    TangWarningCodeAdmImproperSettings = 1053,
};

/** Error code.

Error codes occur when the SDK encounters an error that cannot be recovered automatically without any app intervention. For example, the SDK reports the TangErrorCodeStartCall = 1002 error if it fails to start a call, and reminds the user to call the [leaveChannel]([TangRtcEngineKit leaveChannel:]) method.
*/
typedef NS_ENUM(NSInteger, TangErrorCode) {
    /** 0: No error occurs. */
    TangErrorCodeNoError = 0,
    /** 1: A general error occurs (no specified reason). */
    TangErrorCodeFailed = 1,
    /** 2: An invalid parameter is used. For example, the specific channel name includes illegal characters. */
    TangErrorCodeInvalidArgument = 2,
    /** 3: The SDK module is not ready.
     <p>Possible solutions：
     <ul><li>Check the audio device.</li>
     <li>Check the completeness of the app.</li>
     <li>Re-initialize the SDK.</li></ul></p>
    */
    TangErrorCodeNotReady = 3,
    /** 4: The current state of the SDK does not support this function. */
    TangErrorCodeNotSupported = 4,
    /** 5: The request is rejected. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeRefused = 5,
    /** 6: The buffer size is not big enough to store the returned data. */
    TangErrorCodeBufferTooSmall = 6,
    /** 7: The SDK is not initialized before calling this method. */
    TangErrorCodeNotInitialized = 7,
    /** 9: No permission exists. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeNoPermission = 9,
    /** 10: An API method timeout occurs. Some API methods require the SDK to return the execution result, and this error occurs if the request takes too long (over 10 seconds) for the SDK to process. */
    TangErrorCodeTimedOut = 10,
    /** 11: The request is canceled. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeCanceled = 11,
    /** 12: The method is called too often. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeTooOften = 12,
    /** 13: The SDK fails to bind to the network socket. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeBindSocket = 13,
    /** 14: The network is unavailable. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeNetDown = 14,
    /** 15: No network buffers are available. This is for internal SDK use only, and is not returned to the app through any method or callback. */
    TangErrorCodeNoBufs = 15,
    /** 17: The request to join the channel is rejected.
     <p>Possible reasons are:
     <ul><li>The user is already in the channel, and still calls the API method to join the channel, for example, [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]).</li>
     <li>The user tries joining the channel during the echo test. Please join the channel after the echo test ends.</li></ul></p>
    */
    TangErrorCodeJoinChannelRejected = 17,
    /** 18: The request to leave the channel is rejected.
     <p>Possible reasons are:
     <ul><li>The user left the channel and still calls the API method to leave the channel, for example, [leaveChannel]([TangRtcEngineKit leaveChannel:]).</li>
     <li>The user has not joined the channel and calls the API method to leave the channel.</li></ul></p>
    */
    TangErrorCodeLeaveChannelRejected = 18,
    /** 19: The resources are occupied and cannot be used. */
    TangErrorCodeAlreadyInUse = 19,
    /** 20: The SDK gave up the request due to too many requests.  */
    TangErrorCodeAbort = 20,
    /** 21: In Windows, specific firewall settings cause the SDK to fail to initialize and crash. */
    TangErrorCodeInitNetEngine = 21,
    /** 22: The app uses too much of the system resources and the SDK fails to allocate the resources. */
    TangErrorCodeResourceLimited = 22,
    /** 101: The specified App ID is invalid. Please try to rejoin the channel with a valid App ID.*/
    TangErrorCodeInvalidAppId = 101,
    /** 102: The specified channel name is invalid. Please try to rejoin the channel with a valid channel name. */
    TangErrorCodeInvalidChannelId = 102,
    /** 109: The token expired.
     <br></br><b>DEPRECATED</b> as of v2.4.1. Use TangConnectionChangedTokenExpired(9) in the `reason` parameter of [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]).
     <p>Possible reasons are:
     <ul><li>Authorized Timestamp expired: The timestamp is represented by the number of seconds elapsed since 1/1/1970. The user can use the token to access the Tang service within five minutes after the token is generated. If the user does not access the Tang service after five minutes, this token is no longer valid.</li>
     <li>Call Expiration Timestamp expired: The timestamp is the exact time when a user can no longer use the Tang service (for example, when a user is forced to leave an ongoing call). When a value is set for the Call Expiration Timestamp, it does not mean that the token will expire, but that the user will be banned from the channel.</li></ul></p>
     */
    TangErrorCodeTokenExpired = 109,
    /** 110: The token is invalid.
<br></br><b>DEPRECATED</b> as of v2.4.1. Use TangConnectionChangedInvalidToken(8) in the `reason` parameter of [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]).
     <p>Possible reasons are:
     <ul><li>The App Certificate for the project is enabled in Dashboard, but the user is using the App ID. Once the App Certificate is enabled, the user must use a token.</li>
     <li>The uid is mandatory, and users must set the same uid as the one set in the [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]) method.</li></ul></p>
     */
    TangErrorCodeInvalidToken = 110,
    /** 111: The Internet connection is interrupted. This applies to the Tang Web SDK only. */
    TangErrorCodeConnectionInterrupted = 111,
    /** 112: The Internet connection is lost. This applies to the Tang Web SDK only. */
    TangErrorCodeConnectionLost = 112,
    /** 113: The user is not in the channel when calling the [sendStreamMessage]([TangRtcEngineKit sendStreamMessage:data:]) or [getUserInfoByUserAccount]([TangRtcEngineKit getUserInfoByUserAccount:withError:]) method. */
    TangErrorCodeNotInChannel = 113,
    /** 114: The size of the sent data is over 1024 bytes when the user calls the [sendStreamMessage]([TangRtcEngineKit sendStreamMessage:data:]) method. */
    TangErrorCodeSizeTooLarge = 114,
    /** 115: The bitrate of the sent data exceeds the limit of 6 Kbps when the user calls the [sendStreamMessage]([TangRtcEngineKit sendStreamMessage:data:]) method. */
    TangErrorCodeBitrateLimit = 115,
    /** 116: Too many data streams (over five streams) are created when the user calls the [createDataStream]([TangRtcEngineKit createDataStream:reliable:ordered:]) method. */
    TangErrorCodeTooManyDataStreams = 116,
    /** 120: Decryption fails. The user may have used a different encryption password to join the channel. Check your settings or try rejoining the channel. */
    TangErrorCodeDecryptionFailed = 120,
    /** 124: Incorrect watermark file parameter. */
    TangErrorCodeWatermarkParam = 124,
    /** 125: Incorrect watermark file path. */
    TangErrorCodeWatermarkPath = 125,
    /** 126: Incorrect watermark file format. */
    TangErrorCodeWatermarkPng = 126,
    /** 127: Incorrect watermark file information. */
    TangErrorCodeWatermarkInfo = 127,
    /** 128: Incorrect watermark file data format. */
    TangErrorCodeWatermarkAGRB = 128,
    /** 129: An error occurs in reading the watermark file. */
    TangErrorCodeWatermarkRead = 129,
    /** 130: The encrypted stream is not allowed to publish. */
    TangErrorCodeEncryptedStreamNotAllowedPublish = 130,
    /** 134: The user account is invalid. */
    TangErrorCodeInvalidUserAccount = 134,

    /** 151: CDN related errors. Remove the original URL address and add a new one by calling the [removePublishStreamUrl]([TangRtcEngineKit removePublishStreamUrl:]) and [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) methods. */
    TangErrorCodePublishStreamCDNError = 151,
    /** 152: The host publishes more than 10 URLs. Delete the unnecessary URLs before adding new ones. */
    TangErrorCodePublishStreamNumReachLimit = 152,
    /** 153: The host manipulates other hosts' URLs. Check your app logic. */
    TangErrorCodePublishStreamNotAuthorized = 153,
    /** 154: An error occurs in Tang's streaming server. Call the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method to publish the stream again. */
    TangErrorCodePublishStreamInternalServerError = 154,
    /** 155: The server fails to find the stream. */
    TangErrorCodePublishStreamNotFound = 155,
    /** 156: The format of the RTMP stream URL is not supported. Check whether the URL format is correct. */
    TangErrorCodePublishStreamFormatNotSuppported = 156,

    /** 1001: Fails to load the media engine. */
    TangErrorCodeLoadMediaEngine = 1001,
    /** 1002: Fails to start the call after enabling the media engine. */
    TangErrorCodeStartCall = 1002,
    /** 1003: Fails to start the camera.
     <br></br><b>DEPRECATED</b> as of v2.4.1. Use TangLocalVideoStreamErrorCaptureFailure(4) in the `error` parameter of [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]).
     */
    TangErrorCodeStartCamera = 1003,
    /** 1004: Fails to start the video rendering module. */
    TangErrorCodeStartVideoRender = 1004,
    /** 1005: A general error occurs in the Audio Device Module (the reason is not classified specifically). Check if the audio device is used by another app, or try rejoining the channel. */
    TangErrorCodeAdmGeneralError = 1005,
    /** 1006: Audio Device Module: An error occurs in using the Java resources. */
    TangErrorCodeAdmJavaResource = 1006,
    /** 1007: Audio Device Module: An error occurs in setting the sampling frequency. */
    TangErrorCodeAdmSampleRate = 1007,
    /** 1008: Audio Device Module: An error occurs in initializing the playback device. */
    TangErrorCodeAdmInitPlayout = 1008,
    /** 1009: Audio Device Module: An error occurs in starting the playback device. */
    TangErrorCodeAdmStartPlayout = 1009,
    /** 1010: Audio Device Module: An error occurs in stopping the playback device. */
    TangErrorCodeAdmStopPlayout = 1010,
    /** 1011: Audio Device Module: An error occurs in initializing the recording device. */
    TangErrorCodeAdmInitRecording = 1011,
    /** 1012: Audio Device Module: An error occurs in starting the recording device. */
    TangErrorCodeAdmStartRecording = 1012,
    /** 1013: Audio Device Module: An error occurs in stopping the recording device. */
    TangErrorCodeAdmStopRecording = 1013,
    /** 1015: Audio Device Module: A playback error occurs. Check your playback device, or try rejoining the channel. */
    TangErrorCodeAdmRuntimePlayoutError = 1015,
    /** 1017: Audio Device Module: A recording error occurs. */
    TangErrorCodeAdmRuntimeRecordingError = 1017,
    /** 1018: Audio Device Module: Fails to record. */
    TangErrorCodeAdmRecordAudioFailed = 1018,
    /** 1020: Audio Device Module: Abnormal audio playback frequency. */
    TangErrorCodeAdmPlayAbnormalFrequency = 1020,
    /** 1021: Audio Device Module: Abnormal audio recording frequency. */
    TangErrorCodeAdmRecordAbnormalFrequency = 1021,
    /** 1022: Audio Device Module: An error occurs in initializing the loopback device. */
    TangErrorCodeAdmInitLoopback  = 1022,
    /** 1023: Audio Device Module: An error occurs in starting the loopback device. */
    TangErrorCodeAdmStartLoopback = 1023,
    /** 1027: Audio Device Module: An error occurs in no recording Permission. */
    TangErrorCodeAdmNoPermission = 1027,
    /** 1359: No recording device exists. */
    TangErrorCodeAdmNoRecordingDevice = 1359,
    /** 1360: No playback device exists. */
    TangErrorCodeAdmNoPlayoutDevice = 1360,
    /** 1501: Video Device Module: The camera is unauthorized. */
    TangErrorCodeVdmCameraNotAuthorized = 1501,
    /** 1600: Video Device Module: An unknown error occurs. */
    TangErrorCodeVcmUnknownError = 1600,
    /** 1601: Video Device Module: An error occurs in initializing the video encoder. */
    TangErrorCodeVcmEncoderInitError = 1601,
    /** 1602: Video Device Module: An error occurs in video encoding. */
    TangErrorCodeVcmEncoderEncodeError = 1602,
    /** 1603: Video Device Module: An error occurs in setting the video encoder.
    <p><b>DEPRECATED</b></p>
    */
    TangErrorCodeVcmEncoderSetError = 1603,
};

/** The state of the audio mixing file. */
typedef NS_ENUM(NSInteger, TangAudioMixingStateCode){
    /** The audio mixing file is playing. */
    TangAudioMixingStatePlaying = 710,
    /** The audio mixing file pauses playing. */
    TangAudioMixingStatePaused = 711,
    /** The audio mixing file stops playing. */
    TangAudioMixingStateStopped = 713,
    /** An exception occurs when playing the audio mixing file. */
    TangAudioMixingStateFailed = 714,
};

/**  The error code of the audio mixing file. */
typedef NS_ENUM(NSInteger, TangAudioMixingErrorCode){
    /** The SDK cannot open the audio mixing file. */
   TangAudioMixingErrorCanNotOpen = 701,
   /** The SDK opens the audio mixing file too frequently. */
   TangAudioMixingErrorTooFrequentCall = 702,
   /** The opening of the audio mixing file is interrupted. */
   TangAudioMixingErrorInterruptedEOF = 703,
   /** No error. */
   TangAudioMixingErrorOK = 0,
};

/** Video profile.

**DEPRECATED**

Please use TangVideoEncoderConfiguration.

iPhones do not support resolutions above 720p.
*/
typedef NS_ENUM(NSInteger, TangVideoProfile) {
    /** Invalid profile. */
    TangVideoProfileInvalid = -1,
    /** Resolution 160 &times; 120, frame rate 15 fps, bitrate 65 Kbps. */
    TangVideoProfileLandscape120P = 0,
    /** (iOS only) Resolution 120 &times; 120, frame rate 15 fps, bitrate 50 Kbps. */
    TangVideoProfileLandscape120P_3 = 2,
    /** (iOS only) Resolution 320 &times; 180, frame rate 15 fps, bitrate 140 Kbps. */
    TangVideoProfileLandscape180P = 10,
    /** (iOS only) Resolution 180 &times; 180, frame rate 15 fps, bitrate 100 Kbps. */
    TangVideoProfileLandscape180P_3 = 12,
    /** Resolution 240 &times; 180, frame rate 15 fps, bitrate 120 Kbps. */
    TangVideoProfileLandscape180P_4 = 13,
    /** Resolution 320 &times; 240, frame rate 15 fps, bitrate 200 Kbps. */
    TangVideoProfileLandscape240P = 20,
    /** (iOS only) Resolution 240 &times; 240, frame rate 15 fps, bitrate 140 Kbps. */
    TangVideoProfileLandscape240P_3 = 22,
    /** Resolution 424 &times; 240, frame rate 15 fps, bitrate 220 Kbps. */
    TangVideoProfileLandscape240P_4 = 23,
    /** Resolution 640 &times; 360, frame rate 15 fps, bitrate 400 Kbps. */
    TangVideoProfileLandscape360P = 30,
    /** (iOS only) Resolution 360 &times; 360, frame rate 15 fps, bitrate 260 Kbps. */
    TangVideoProfileLandscape360P_3 = 32,
    /** Resolution 640 &times; 360, frame rate 30 fps, bitrate 600 Kbps. */
    TangVideoProfileLandscape360P_4 = 33,
    /** Resolution 360 &times; 360, frame rate 30 fps, bitrate 400 Kbps. */
    TangVideoProfileLandscape360P_6 = 35,
    /** Resolution 480 &times; 360, frame rate 15 fps, bitrate 320 Kbps. */
    TangVideoProfileLandscape360P_7 = 36,
    /** Resolution 480 &times; 360, frame rate 30 fps, bitrate 490 Kbps. */
    TangVideoProfileLandscape360P_8 = 37,
    /** Resolution 640 &times; 360, frame rate 15 fps, bitrate 800 Kbps.
    <br>
     <b>Note:</b> This profile applies to the live broadcast channel profile only.
     */
    TangVideoProfileLandscape360P_9 = 38,
    /** Resolution 640 &times; 360, frame rate 24 fps, bitrate 800 Kbps.
    <br>
     <b>Note:</b> This profile applies to the live broadcast channel profile only.
     */
    TangVideoProfileLandscape360P_10 = 39,
    /** Resolution 640 &times; 360, frame rate 24 fps, bitrate 1000 Kbps.
    <br>
     <b>Note:</b> This profile applies to the live broadcast channel profile only.
     */
    TangVideoProfileLandscape360P_11 = 100,
    /** Resolution 640 &times; 480, frame rate 15 fps, bitrate 500 Kbps. */
    TangVideoProfileLandscape480P = 40,
    /** (iOS only) Resolution 480 &times; 480, frame rate 15 fps, bitrate 400 Kbps. */
    TangVideoProfileLandscape480P_3 = 42,
    /** Resolution 640 &times; 480, frame rate 30 fps, bitrate 750 Kbps. */
    TangVideoProfileLandscape480P_4 = 43,
    /** Resolution 480 &times; 480, frame rate 30 fps, bitrate 600 Kbps. */
    TangVideoProfileLandscape480P_6 = 45,
    /** Resolution 848 &times; 480, frame rate 15 fps, bitrate 610 Kbps. */
    TangVideoProfileLandscape480P_8 = 47,
    /** Resolution 848 &times; 480, frame rate 30 fps, bitrate 930 Kbps. */
    TangVideoProfileLandscape480P_9 = 48,
    /** Resolution 640 &times; 480, frame rate 10 fps, bitrate 400 Kbps. */
    TangVideoProfileLandscape480P_10 = 49,
    /** Resolution 1280 &times; 720, frame rate 15 fps, bitrate 1130 Kbps. */
    TangVideoProfileLandscape720P = 50,
    /** Resolution 1280 &times; 720, frame rate 30 fps, bitrate 1710 Kbps. */
    TangVideoProfileLandscape720P_3 = 52,
    /** Resolution 960 &times; 720, frame rate 15 fps, bitrate 910 Kbps. */
    TangVideoProfileLandscape720P_5 = 54,
    /** Resolution 960 &times; 720, frame rate 30 fps, bitrate 1380 Kbps. */
    TangVideoProfileLandscape720P_6 = 55,
    /** (macOS only) Resolution 1920 &times; 1080, frame rate 15 fps, bitrate 2080 Kbps. */
    TangVideoProfileLandscape1080P = 60,
    /** (macOS only) Resolution 1920 &times; 1080, frame rate 30 fps, bitrate 3150 Kbps. */
    TangVideoProfileLandscape1080P_3 = 62,
    /** (macOS only) Resolution 1920 &times; 1080, frame rate 60 fps, bitrate 4780 Kbps. */
    TangVideoProfileLandscape1080P_5 = 64,
    /** (macOS only) Resolution 2560 &times; 1440, frame rate 30 fps, bitrate 4850 Kbps. */
    TangVideoProfileLandscape1440P = 66,
    /** (macOS only) Resolution 2560 &times; 1440, frame rate 60 fps, bitrate 6500 Kbps. */
    TangVideoProfileLandscape1440P_2 = 67,
    /** (macOS only) Resolution 3840 &times; 2160, frame rate 30 fps, bitrate 6500 Kbps. */
    TangVideoProfileLandscape4K = 70,
    /** (macOS only) Resolution 3840 &times; 2160, frame rate 60 fps, bitrate 6500 Kbps. */
    TangVideoProfileLandscape4K_3 = 72,

    /** Resolution 120 &times; 160, frame rate 15 fps, bitrate 65 Kbps. */
    TangVideoProfilePortrait120P = 1000,
    /** (iOS only) Resolution 120 &times; 120, frame rate 15 fps, bitrate 50 Kbps. */
    TangVideoProfilePortrait120P_3 = 1002,
    /** (iOS only) Resolution 180 &times; 320, frame rate 15 fps, bitrate 140 Kbps. */
    TangVideoProfilePortrait180P = 1010,
    /** (iOS only) Resolution 180 &times; 180, frame rate 15 fps, bitrate 100 Kbps. */
    TangVideoProfilePortrait180P_3 = 1012,
    /** Resolution 180 &times; 240, frame rate 15 fps, bitrate 120 Kbps. */
    TangVideoProfilePortrait180P_4 = 1013,
    /** Resolution 240 &times; 320, frame rate 15 fps, bitrate 200 Kbps. */
    TangVideoProfilePortrait240P = 1020,
    /** (iOS only) Resolution 240 &times; 240, frame rate 15 fps, bitrate 140 Kbps. */
    TangVideoProfilePortrait240P_3 = 1022,
    /** Resolution 240 &times; 424, frame rate 15 fps, bitrate 220 Kbps. */
    TangVideoProfilePortrait240P_4 = 1023,
    /** Resolution 360 &times; 640, frame rate 15 fps, bitrate 400 Kbps. */
    TangVideoProfilePortrait360P = 1030,
    /** (iOS only) Resolution 360 &times; 360, frame rate 15 fps, bitrate 260 Kbps. */
    TangVideoProfilePortrait360P_3 = 1032,
    /** Resolution 360 &times; 640, frame rate 30 fps, bitrate 600 Kbps. */
    TangVideoProfilePortrait360P_4 = 1033,
    /** Resolution 360 &times; 360, frame rate 30 fps, bitrate 400 Kbps. */
    TangVideoProfilePortrait360P_6 = 1035,
    /** Resolution 360 &times; 480, frame rate 15 fps, bitrate 320 Kbps. */
    TangVideoProfilePortrait360P_7 = 1036,
    /** Resolution 360 &times; 480, frame rate 30 fps, bitrate 490 Kbps. */
    TangVideoProfilePortrait360P_8 = 1037,
    /** Resolution 360 &times; 640, frame rate 15 fps, bitrate 600 Kbps. */
    TangVideoProfilePortrait360P_9 = 1038,
    /** Resolution 360 &times; 640, frame rate 24 fps, bitrate 800 Kbps. */
    TangVideoProfilePortrait360P_10 = 1039,
    /** Resolution 360 &times; 640, frame rate 24 fps, bitrate 800 Kbps. */
    TangVideoProfilePortrait360P_11 = 1100,
    /** Resolution 480 &times; 640, frame rate 15 fps, bitrate 500 Kbps. */
    TangVideoProfilePortrait480P = 1040,
    /** (iOS only) Resolution 480 &times; 480, frame rate 15 fps, bitrate 400 Kbps. */
    TangVideoProfilePortrait480P_3 = 1042,
    /** Resolution 480 &times; 640, frame rate 30 fps, bitrate 750 Kbps. */
    TangVideoProfilePortrait480P_4 = 1043,
    /** Resolution 480 &times; 480, frame rate 30 fps, bitrate 600 Kbps. */
    TangVideoProfilePortrait480P_6 = 1045,
    /** Resolution 480 &times; 848, frame rate 15 fps, bitrate 610 Kbps. */
    TangVideoProfilePortrait480P_8 = 1047,
    /** Resolution 480 &times; 848, frame rate 30 fps, bitrate 930 Kbps. */
    TangVideoProfilePortrait480P_9 = 1048,
    /** Resolution 480 &times; 640, frame rate 10 fps, bitrate 400 Kbps. */
    TangVideoProfilePortrait480P_10 = 1049,
    /** Resolution 720 &times; 1280, frame rate 15 fps, bitrate 1130 Kbps. */
    TangVideoProfilePortrait720P = 1050,
    /** Resolution 720 &times; 1280, frame rate 30 fps, bitrate 1710 Kbps. */
    TangVideoProfilePortrait720P_3 = 1052,
    /** Resolution 720 &times; 960, frame rate 15 fps, bitrate 910 Kbps. */
    TangVideoProfilePortrait720P_5 = 1054,
    /** Resolution 720 &times; 960, frame rate 30 fps, bitrate 1380 Kbps. */
    TangVideoProfilePortrait720P_6 = 1055,
    /** (macOS only) Resolution 1080 &times; 1920, frame rate 15 fps, bitrate 2080 Kbps. */
    TangVideoProfilePortrait1080P = 1060,
    /** (macOS only) Resolution 1080 &times; 1920, frame rate 30 fps, bitrate 3150 Kbps. */
    TangVideoProfilePortrait1080P_3 = 1062,
    /** (macOS only) Resolution 1080 &times; 1920, frame rate 60 fps, bitrate 4780 Kbps. */
    TangVideoProfilePortrait1080P_5 = 1064,
    /** (macOS only) Resolution 1440 &times; 2560, frame rate 30 fps, bitrate 4850 Kbps. */
    TangVideoProfilePortrait1440P = 1066,
    /** (macOS only) Resolution 1440 &times; 2560, frame rate 60 fps, bitrate 6500 Kbps. */
    TangVideoProfilePortrait1440P_2 = 1067,
    /** (macOS only) Resolution 2160 &times; 3840, frame rate 30 fps, bitrate 6500 Kbps. */
    TangVideoProfilePortrait4K = 1070,
    /** (macOS only) Resolution 2160 &times; 3840, frame rate 60 fps, bitrate 6500 Kbps. */
    TangVideoProfilePortrait4K_3 = 1072,
    /** (Default) Resolution 640 &times; 360, frame rate 15 fps, bitrate 400 Kbps. */
    TangVideoProfileDEFAULT = TangVideoProfileLandscape360P,
};

/** The camera capturer configuration. */
typedef NS_ENUM(NSInteger, TangCameraCaptureOutputPreference) {
    /** (default) Self-adapts the camera output parameters to the system performance and network conditions to balance CPU consumption and video preview quality. */
    TangCameraCaptureOutputPreferenceAuto = 0,
    /** Prioritizes the system performance. The SDK chooses the dimension and frame rate of the local camera capture closest to those set by [setVideoEncoderConfiguration]([TangRtcEngineKit setVideoEncoderConfiguration:]). */
    TangCameraCaptureOutputPreferencePerformance = 1,
    /** Prioritizes the local preview quality. The SDK chooses higher camera output parameters to improve the local video preview quality. This option requires extra CPU and RAM usage for video pre-processing. */
    TangCameraCaptureOutputPreferencePreview = 2,
    /** Internal use only */
    TangCameraCaptureOutputPreferenceUnkown = 3
};


/** Video frame rate */
typedef NS_ENUM(NSInteger, TangVideoFrameRate) {
    /** 1 fps. */
    TangVideoFrameRateFps1 = 1,
    /** 7 fps. */
    TangVideoFrameRateFps7 = 7,
    /** 10 fps. */
    TangVideoFrameRateFps10 = 10,
    /** 15 fps. */
    TangVideoFrameRateFps15 = 15,
    /** 24 fps. */
    TangVideoFrameRateFps24 = 24,
    /** 30 fps. */
    TangVideoFrameRateFps30 = 30,
    /** 60 fps (macOS only). */
    TangVideoFrameRateFps60 = 60,
};

/** Video output orientation mode.

  **Note:** When a custom video source is used, if you set TangVideoOutputOrientationMode as TangVideoOutputOrientationModeFixedLandscape(1) or TangVideoOutputOrientationModeFixedPortrait(2), when the rotated video image has a different orientation than the specified output orientation, the video encoder first crops it and then encodes it.
 */
typedef NS_ENUM(NSInteger, TangVideoOutputOrientationMode) {
    /** Adaptive mode (Default).
     <p>The video encoder adapts to the orientation mode of the video input device. When you use a custom video source, the output video from the encoder inherits the orientation of the original video.
     <ul><li>If the width of the captured video from the SDK is greater than the height, the encoder sends the video in landscape mode. The encoder also sends the rotational information of the video, and the receiver uses the rotational information to rotate the received video.</li>
     <li>If the original video is in portrait mode, the output video from the encoder is also in portrait mode. The encoder also sends the rotational information of the video to the receiver.</li></ul></p>
     */
    TangVideoOutputOrientationModeAdaptative = 0,
    /** Landscape mode.
     <p>The video encoder always sends the video in landscape mode. The video encoder rotates the original video before sending it and the rotational information is 0. This mode applies to scenarios involving CDN live streaming.</p>
     */
    TangVideoOutputOrientationModeFixedLandscape = 1,
     /** Portrait mode.
      <p>The video encoder always sends the video in portrait mode. The video encoder rotates the original video before sending it and the rotational information is 0. This mode applies to scenarios involving CDN live streaming.</p>
      */
    TangVideoOutputOrientationModeFixedPortrait = 2,
    
    TangVideoOutputOrientationModeFixedLandscape_EXT = 3,
};

/** Channel profile. */
typedef NS_ENUM(NSInteger, TangChannelProfile) {
    /** Communication (default).
     <p>This is used in one-on-one or group calls, where all users in the channel can talk freely.</p>
     */
    TangChannelProfileCommunication = 0,
    /** Live Broadcast.
     <p>Host and audience roles that can be set by calling the [setClientRole]([TangRtcEngineKit setClientRole:]) method. The host sends and receives voice/video, while the audience can only receive voice/video.</p>
     */
    TangChannelProfileLiveBroadcasting = 1,
    /** Gaming.
     <p>This mode is for the Tang Gaming SDK only.</p>
     <p>Any user in the channel can talk freely. This mode uses the codec with low-power consumption and low bitrate by default. </p>
     */
    TangChannelProfileGame = 2,
};

/** Client role in a live broadcast. */
typedef NS_ENUM(NSInteger, TangClientRole) {
    /** Host. */
    TangClientRoleBroadcaster = 1,
    /** Audience. */
    TangClientRoleAudience = 2,
};


/** Media type. */
typedef NS_ENUM(NSInteger, TangMediaType) {
    /** No audio and video. */
    TangMediaTypeNone = 0,
    /** Audio only. */
    TangMediaTypeAudioOnly = 1,
    /** Video only. */
    TangMediaTypeVideoOnly = 2,
    /** Audio and video. */
    TangMediaTypeAudioAndVideo = 3,
};

/** Encryption mode */
typedef NS_ENUM(NSInteger, TangEncryptionMode) {
    /** When encryptionMode is set as NULL, the encryption mode is set as "aes-128-xts" by default. */
    TangEncryptionModeNone = 0,
    /** (Default) 128-bit AES encryption, XTS mode. */
    TangEncryptionModeAES128XTS = 1,
    /** 256-bit AES encryption, XTS mode. */
    TangEncryptionModeAES256XTS = 2,
    /** 128-bit AES encryption, ECB mode. */
    TangEncryptionModeAES128ECB = 3,
};

/** Reason for the user being offline. */
typedef NS_ENUM(NSUInteger, TangUserOfflineReason) {
    /** The user left the current channel. */
    TangUserOfflineReasonQuit = 0,
    /** The SDK timed out and the user dropped offline because no data packet is received within a certain period of time. If a user quits the call and the message is not passed to the SDK (due to an unreliable channel), the SDK assumes the user dropped offline. */
    TangUserOfflineReasonDropped = 1,
    /** (Live broadcast only.) The client role switched from the host to the audience. */
    TangUserOfflineReasonBecomeAudience = 2,
};

/** The RTMP streaming state. */
typedef NS_ENUM(NSUInteger, TangRtmpStreamingState) {
  /** The RTMP streaming has not started or has ended. This state is also triggered after you remove an RTMP address from the CDN by calling removePublishStreamUrl.*/
  TangRtmpStreamingStateIdle = 0,
  /** The SDK is connecting to Tang's streaming server and the RTMP server. This state is triggered after you call the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method. */
  TangRtmpStreamingStateConnecting = 1,
  /** The RTMP streaming is being published. The SDK successfully publishes the RTMP streaming and returns this state. */
  TangRtmpStreamingStateRunning = 2,
  /** The RTMP streaming is recovering. When exceptions occur to the CDN, or the streaming is interrupted, the SDK attempts to resume RTMP streaming and returns this state.
<li> If the SDK successfully resumes the streaming, TangRtmpStreamingStateRunning(2) returns.
<li> If the streaming does not resume within 60 seconds or server errors occur, TangRtmpStreamingStateFailure(4) returns. You can also reconnect to the server by calling the [removePublishStreamUrl]([TangRtcEngineKit removePublishStreamUrl:]) and [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) methods. */
  TangRtmpStreamingStateRecovering = 3,
  /** The RTMP streaming fails. See the errorCode parameter for the detailed error information. You can also call the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method to publish the RTMP streaming again. */
  TangRtmpStreamingStateFailure = 4,
};


enum RTMP_STREAM_PUBLISH_ERROR
{
  RTMP_STREAM_PUBLISH_ERROR_OK = 0,
  RTMP_STREAM_PUBLISH_ERROR_INVALID_ARGUMENT = 1,
  RTMP_STREAM_PUBLISH_ERROR_ENCRYPTED_STREAM_NOT_ALLOWED = 2,
  RTMP_STREAM_PUBLISH_ERROR_CONNECTION_TIMEOUT = 3,
  RTMP_STREAM_PUBLISH_ERROR_INTERNAL_SERVER_ERROR = 4,
  RTMP_STREAM_PUBLISH_ERROR_RTMP_SERVER_ERROR = 5,
  RTMP_STREAM_PUBLISH_ERROR_TOO_OFTEN = 6,
  RTMP_STREAM_PUBLISH_ERROR_REACH_LIMIT = 7,
  RTMP_STREAM_PUBLISH_ERROR_NOT_AUTHORIZED = 8,
  RTMP_STREAM_PUBLISH_ERROR_STREAM_NOT_FOUND = 9,
  RTMP_STREAM_PUBLISH_ERROR_FORMAT_NOT_SUPPORTED = 10,
};

/** The detailed error information for streaming. */
typedef NS_ENUM(NSUInteger, TangRtmpStreamingErrorCode) {
  /** The RTMP streaming publishes successfully. */
  TangRtmpStreamingErrorCodeOK = 0,
  /** Invalid argument used. If, for example, you do not call the [setLiveTranscoding]([TangRtcEngineKit setLiveTranscoding:]) method to configure the LiveTranscoding parameters before calling the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method, the SDK returns this error. Check whether you set the parameters in the setLiveTranscoding method properly. */
  TangRtmpStreamingErrorCodeInvalidParameters = 1,
  /** The RTMP streaming is encrypted and cannot be published. */
  TangRtmpStreamingErrorCodeEncryptedStreamNotAllowed = 2,
  /** Timeout for the RTMP streaming. Call the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method to publish the streaming again. */
  TangRtmpStreamingErrorCodeConnectionTimeout = 3,
  /** An error occurs in Tang's streaming server. Call the [addPublishStreamUrl]([TangRtcEngineKit addPublishStreamUrl:transcodingEnabled:]) method to publish the streaming again. */
  TangRtmpStreamingErrorCodeInternalServerError = 4,
  /** An error occurs in the RTMP server. */
  TangRtmpStreamingErrorCodeRtmpServerError = 5,
  /** The RTMP streaming publishes too frequently. */
  TangRtmpStreamingErrorCodeTooOften = 6,
  /** The host publishes more than 10 URLs. Delete the unnecessary URLs before adding new ones. */
  TangRtmpStreamingErrorCodeReachLimit = 7,
  /** The host manipulates other hosts' URLs. Check your app logic. */
  TangRtmpStreamingErrorCodeNotAuthorized = 8,
  /** Tang's server fails to find the RTMP streaming. */
  TangRtmpStreamingErrorCodeStreamNotFound = 9,
  /** The format of the RTMP streaming URL is not supported. Check whether the URL format is correct. */
  TangRtmpStreamingErrorCodeFormatNotSupported = 10,
};

/** State of importing an external video stream in a live broadcast. */
typedef NS_ENUM(NSUInteger, TangInjectStreamStatus) {
    /** The external video stream imported successfully. */
    TangInjectStreamStatusStartSuccess = 0,
    /** The external video stream already exists. */
    TangInjectStreamStatusStartAlreadyExists = 1,
    /** The external video stream import is unauthorized. */
    TangInjectStreamStatusStartUnauthorized = 2,
    /** Import external video stream timeout. */
    TangInjectStreamStatusStartTimedout = 3,
    /** The external video stream failed to import. */
    TangInjectStreamStatusStartFailed = 4,
    /** The external video stream imports successfully. */
    TangInjectStreamStatusStopSuccess = 5,
    /** No external video stream is found. */
    TangInjectStreamStatusStopNotFound = 6,
    /** The external video stream is stopped from being unauthorized. */
    TangInjectStreamStatusStopUnauthorized = 7,
    /** Importing the external video stream timeout. */
    TangInjectStreamStatusStopTimedout = 8,
    /** Importing the external video stream failed. */
    TangInjectStreamStatusStopFailed = 9,
    /** The external video stream import is interrupted. */
    TangInjectStreamStatusBroken = 10,
};

/** Output log filter level. */
typedef NS_ENUM(NSUInteger, TangLogFilter) {
    /** Do not output any log information. */
    TangLogFilterOff = 0,
    /** Output all log information. Set your log filter as debug if you want to get the most complete log file. */
    TangLogFilterDebug = 0x080f,
    /** Output CRITICAL, ERROR, WARNING, and INFO level log information. We recommend setting your log filter as this level. */
    TangLogFilterInfo = 0x000f,
    /** Outputs CRITICAL, ERROR, and WARNING level log information. */
    TangLogFilterWarning = 0x000e,
    /** Outputs CRITICAL and ERROR level log information. */
    TangLogFilterError = 0x000c,
    /** Outputs CRITICAL level log information. */
    TangLogFilterCritical = 0x0008,
};

/** Audio recording quality. */
typedef NS_ENUM(NSInteger, TangAudioRecordingQuality) {
   /** Low quality: The sample rate is 32 KHz, and the file size is around 1.2 MB after 10 minutes of recording. */
    TangAudioRecordingQualityLow = 0,
    /** Medium quality: The sample rate is 32 KHz, and the file size is around 2 MB after 10 minutes of recording. */
    TangAudioRecordingQualityMedium = 1,
    /** High quality: The sample rate is 32 KHz, and the file size is around 3.75 MB after 10 minutes of recording. */
    TangAudioRecordingQualityHigh = 2
};

/** Audio recording position. */
typedef NS_ENUM(NSInteger, TangAudioRecordingPosition) {
   /** Mixed recoding and playback: The SDK will record the voices of all users in the channel. */
    TangAudioRecordingPositionMixedRecordingAndPlayback = 0,
    /** Only recording: The SDK will record the voice of the local user. */
    TangAudioRecordingPositionRecording = 1,
    /** Only mixed playback: The SDK will record the voices of remote users. */
    TangAudioRecordingPositionMixedPlayback = 2
};


/** Lifecycle of the CDN live video stream.

**DEPRECATED**
*/
typedef NS_ENUM(NSInteger, TangRtmpStreamLifeCycle) {
    /** Bound to the channel lifecycle. If all hosts leave the channel, the CDN live streaming stops after 30 seconds. */
    TangRtmpStreamLifeCycleBindToChannel = 1,
    /** Bound to the owner of the RTMP stream. If the owner leaves the channel, the CDN live streaming stops immediately. */
    TangRtmpStreamLifeCycleBindToOwnner = 2,
};

/** Network quality. */
typedef NS_ENUM(NSUInteger, TangNetworkQuality) {
    /** The network quality is unknown. */
    TangNetworkQualityUnknown = 0,
    /**  The network quality is excellent. */
    TangNetworkQualityExcellent = 1,
    /** The network quality is quite good, but the bitrate may be slightly lower than excellent. */
    TangNetworkQualityGood = 2,
    /** Users can feel the communication slightly impaired. */
    TangNetworkQualityPoor = 3,
    /** Users can communicate only not very smoothly. */
    TangNetworkQualityBad = 4,
     /** The network quality is so bad that users can hardly communicate. */
    TangNetworkQualityVBad = 5,
     /** The network is disconnected and users cannot communicate at all. */
    TangNetworkQualityDown = 6,
     /** Users cannot detect the network quality. (Not in use.) */
    TangNetworkQualityUnsupported = 7,
     /** Detecting the network quality. */
    TangNetworkQualityDetecting = 8,
};

/** Video stream type. */
typedef NS_ENUM(NSInteger, TangVideoStreamType) {
    /** High-bitrate, high-resolution video stream. */
    TangVideoStreamTypeHigh = 0,
    /** Low-bitrate, low-resolution video stream. */
    TangVideoStreamTypeLow = 1,
};

/** The priority of the remote user. */
typedef NS_ENUM(NSInteger, TangUserPriority) {
  /** The user's priority is high. */
  TangUserPriorityHigh = 50,
  /** (Default) The user's priority is normal. */
  TangUserPriorityNormal = 100,
};

/**  Quality change of the local video in terms of target frame rate and target bit rate since last count. */
typedef NS_ENUM(NSInteger, TangVideoQualityAdaptIndication) {
  /** The quality of the local video stays the same. */
  TangVideoQualityAdaptNone = 0,
  /** The quality improves because the network bandwidth increases. */
  TangVideoQualityAdaptUpBandwidth = 1,
  /** The quality worsens because the network bandwidth decreases. */
  TangVideoQualityAdaptDownBandwidth = 2,
};

/** Video display mode. */
typedef NS_ENUM(NSUInteger, TangVideoRenderMode) {
    /** Hidden(1): Uniformly scale the video until it fills the visible boundaries (cropped). One dimension of the video may have clipped contents. */
    TangVideoRenderModeHidden = 1,

    /** Fit(2): Uniformly scale the video until one of its dimension fits the boundary (zoomed to fit). Areas that are not filled due to the disparity in the aspect ratio are filled with black. */
    TangVideoRenderModeFit = 2,

    /**
     Adaptive(3)：This mode is deprecated.
     */
    TangVideoRenderModeAdaptive __deprecated_enum_msg("TangVideoRenderModeAdaptive is deprecated.") = 3,
};

/** Self-defined video codec profile. */
typedef NS_ENUM(NSInteger, TangVideoCodecProfileType) {
    /** 66: Baseline video codec profile. Generally used in video calls on mobile phones. */
    TangVideoCodecProfileTypeBaseLine = 66,
    /** 77: Main video codec profile. Generally used in mainstream electronics, such as MP4 players, portable video players, PSP, and iPads. */
    TangVideoCodecProfileTypeMain = 77,
    /** 100: (Default) High video codec profile. Generally used in high-resolution broadcasts or television. */
    TangVideoCodecProfileTypeHigh = 100
};

/** Video codec types. */
typedef NS_ENUM(NSInteger, TangVideoCodecType) {
    /** Standard VP8. */
    TangVideoCodecTypeVP8 = 1,
    /** Standard H264. */
    TangVideoCodecTypeH264 = 2,
    /** Enhanced VP8. */
    TangVideoCodecTypeEVP = 3,
    /** Enhanced H264. */
    TangVideoCodecTypeE264 = 4,
};

/** Self-defined video codec type */
typedef NS_ENUM(NSInteger, TangVideoCodecTranscodingType) {
    /** 1: (Default value)H264 */
    TangVideoCodecTranscodingTypeH264 = 1,
    /** 2: H265 */
    TangVideoCodecTranscodingTypeH265 = 2,
};

/** Video mirror mode. */
typedef NS_ENUM(NSUInteger, TangVideoMirrorMode) {
    /** The SDK determines the default mirror mode. */
    TangVideoMirrorModeAuto = 0,
    /** Enables mirror mode. */
    TangVideoMirrorModeEnabled = 1,
    /** Disables mirror mode. */
    TangVideoMirrorModeDisabled = 2,
};

/** Stream publish mode. */
typedef NS_ENUM(NSUInteger, TangStreamPublishState) {
    TangStreamPublishIdle = 0,
    TangStreamPublishNoPublished = 1,
    TangStreamPublishPublishing = 2,
    TangStreamPublishPublished = 3,
};

/** Stream subscribe mode. */
typedef NS_ENUM(NSUInteger, TangStreamSubscribeState) {
    TangStreamSubscribeIdle = 0,
    TangStreamSubscribeNoSubscribed = 1,
    TangStreamSubscribeSubscribing = 2,
    TangStreamSubscribeSubscribed = 3,
};

/** The content hint for screen sharing. */
typedef NS_ENUM(NSUInteger, TangVideoContentHint) {
    /** (Default) No content hint. */
    TangVideoContentHintNone = 0,
    /** Motion-intensive content. Choose this option if you prefer smoothness or when you are sharing a video clip, movie, or video game. */
    TangVideoContentHintMotion = 1,
    /** Motionless content. Choose this option if you prefer sharpness or when you are sharing a picture, PowerPoint slide, or text. */
    TangVideoContentHintDetails = 2,
};

/** The state of the remote video. */
typedef NS_ENUM(NSUInteger, TangVideoRemoteState) {
    /** 0: The remote video is in the default state, probably due to TangVideoRemoteStateReasonLocalMuted(3), TangVideoRemoteStateReasonRemoteMuted(5), or TangVideoRemoteStateReasonRemoteOffline(7).
     */
    TangVideoRemoteStateStopped = 0,
    /** 1: The first remote video packet is received.
     */
    TangVideoRemoteStateStarting = 1,
    /** 2: The remote video stream is decoded and plays normally, probably due to TangVideoRemoteStateReasonNetworkRecovery(2), TangVideoRemoteStateReasonLocalUnmuted(4), TangVideoRemoteStateReasonRemoteUnmuted(6), or TangVideoRemoteStateReasonAudioFallbackRecovery(9).
     */
    TangVideoRemoteStateDecoding = 2,
    /** 3: The remote video is frozen, probably due to TangVideoRemoteStateReasonNetworkCongestion(1) or TangVideoRemoteStateReasonAudioFallback(8).
     */
    TangVideoRemoteStateFrozen = 3,
    /** 4: The remote video fails to start, probably due to TangVideoRemoteStateReasonInternal(0).
     */
    TangVideoRemoteStateFailed = 4,
};

/** The reason of the remote video state change. */
typedef NS_ENUM(NSUInteger, TangVideoRemoteStateReason) {
    /** 0: Internal reasons. */
    TangVideoRemoteStateReasonInternal = 0,
    /** 1: Network congestion. */
    TangVideoRemoteStateReasonNetworkCongestion = 1,
    /** 2: Network recovery. */
    TangVideoRemoteStateReasonNetworkRecovery = 2,
    /** 3: The local user stops receiving the remote video stream or disables the video module. */
    TangVideoRemoteStateReasonLocalMuted = 3,
    /** 4: The local user resumes receiving the remote video stream or enables the video module. */
    TangVideoRemoteStateReasonLocalUnmuted = 4,
    /** 5: The remote user stops sending the video stream or disables the video module. */
    TangVideoRemoteStateReasonRemoteMuted = 5,
    /** 6: The remote user resumes sending the video stream or enables the video module. */
    TangVideoRemoteStateReasonRemoteUnmuted = 6,
    /** 7: The remote user leaves the channel. */
    TangVideoRemoteStateReasonRemoteOffline = 7,
    /** 8: The remote media stream falls back to the audio-only stream due to poor network conditions. */
    TangVideoRemoteStateReasonAudioFallback = 8,
    /** 9: The remote media stream switches back to the video stream after the network conditions improve. */
    TangVideoRemoteStateReasonAudioFallbackRecovery = 9,
};

/** Stream fallback option. */
typedef NS_ENUM(NSInteger, TangStreamFallbackOptions) {
    /** No fallback behavior for the local/remote video stream when the uplink/downlink network condition is unreliable. The quality of the stream is not guaranteed. */
    TangStreamFallbackOptionDisabled = 0,
    /** Under unreliable downlink network conditions, the remote video stream falls back to the low-stream (low resolution and low bitrate) video. You can only set this option in the [setRemoteSubscribeFallbackOption]([TangRtcEngineKit setRemoteSubscribeFallbackOption:]) method. Nothing happens when you set this in the [setLocalPublishFallbackOption]([TangRtcEngineKit setLocalPublishFallbackOption:]) method. */
    TangStreamFallbackOptionVideoStreamLow = 1,
    /**
     <li> Under unreliable uplink network conditions, the published video stream falls back to audio only.
     <li> Under unreliable downlink network conditions, the remote video stream first falls back to the low-stream (low resolution and low bitrate) video; and then to an audio-only stream if the network condition deteriorates. */
    TangStreamFallbackOptionAudioOnly = 2,
};

/** Audio sample rate. */
typedef NS_ENUM(NSInteger, TangAudioSampleRateType) {
    /** 32 kHz. */
    TangAudioSampleRateType32000 = 32000,
    /** 44.1 kHz. */
    TangAudioSampleRateType44100 = 44100,
    /** 48 kHz. */
    TangAudioSampleRateType48000 = 48000,
};

/** Audio profile. */
typedef NS_ENUM(NSInteger, TangAudioProfile) {
    /** Default audio profile. In the communication profile, the default value is TangAudioProfileSpeechStandard; in the live-broadcast profile, the default value is TangAudioProfileMusicStandard. */
    TangAudioProfileDefault = 0,
    /** A sample rate of 32 kHz, audio encoding, mono, and a bitrate of up to 18 Kbps. */
    TangAudioProfileSpeechStandard = 1,
    /** A sample rate of 48 kHz, music encoding, mono, and a bitrate of up to 48 Kbps. */
    TangAudioProfileMusicStandard = 2,
    /** A sample rate of 48 kHz, music encoding, stereo, and a bitrate of up to 56 Kbps. */
    TangAudioProfileMusicStandardStereo = 3,
    /** A sample rate of 48 kHz, music encoding, mono, and a bitrate of up to 128 Kbps. */
    TangAudioProfileMusicHighQuality = 4,
    /** A sample rate of 48 kHz, music encoding, stereo, and a bitrate of up to 192 Kbps. */
    TangAudioProfileMusicHighQualityStereo = 5,
};

/** Audio scenario. */
typedef NS_ENUM(NSInteger, TangAudioScenario) {
    /** Default. */
    TangAudioScenarioDefault = 0,
    /** Entertainment scenario, supporting voice during gameplay. */
    TangAudioScenarioChatRoomEntertainment = 1,
    /** Education scenario, prioritizing fluency and stability. */
    TangAudioScenarioEducation = 2,
    /** Live gaming scenario, enabling the gaming audio effects in the speaker mode in a live broadcast scenario. Choose this scenario for high-fidelity music playback.*/
    TangAudioScenarioGameStreaming = 3,
    /** Showroom scenario, optimizing the audio quality with external professional equipment. */
    TangAudioScenarioShowRoom = 4,
    /** Gaming scenario. */
    TangAudioScenarioChatRoomGaming = 5
};

/** Audio output routing. */
typedef NS_ENUM(NSInteger, TangAudioOutputRouting) {
    /** Default. */
    TangAudioOutputRoutingDefault = -1,
    /** Headset.*/
    TangAudioOutputRoutingHeadset = 0,
    /** Earpiece. */
    TangAudioOutputRoutingEarpiece = 1,
    /** Headset with no microphone. */
    TangAudioOutputRoutingHeadsetNoMic = 2,
    /** Speakerphone. */
    TangAudioOutputRoutingSpeakerphone = 3,
    /** Loudspeaker. */
    TangAudioOutputRoutingLoudspeaker = 4,
    /** Bluetooth headset. */
    TangAudioOutputRoutingHeadsetBluetooth = 5
};

/** Use mode of the onRecordAudioFrame callback. */
typedef NS_ENUM(NSInteger, TangAudioRawFrameOperationMode) {
    /** Read-only mode: Users only read the AudioFrame data without modifying anything. For example, when users acquire data with the Tang SDK then push the RTMP streams. */
    TangAudioRawFrameOperationModeReadOnly = 0,
    /** Write-only mode: Users replace the AudioFrame data with their own data and pass them to the SDK for encoding. For example, when users acquire data. */
    TangAudioRawFrameOperationModeWriteOnly = 1,
    /** Read and write mode: Users read the data from AudioFrame, modify it, and then play it. For example, when users have their own sound-effect processing module and perform some voice pre-processing such as a voice change. */
    TangAudioRawFrameOperationModeReadWrite = 2,
};

/** Audio equalization band frequency. */
typedef NS_ENUM(NSInteger, TangAudioEqualizationBandFrequency) {
    /** 31 Hz. */
    TangAudioEqualizationBand31 = 0,
    /** 62 Hz. */
    TangAudioEqualizationBand62 = 1,
    /** 125 Hz. */
    TangAudioEqualizationBand125 = 2,
    /** 250 Hz. */
    TangAudioEqualizationBand250 = 3,
    /** 500 Hz */
    TangAudioEqualizationBand500 = 4,
    /** 1 kHz. */
    TangAudioEqualizationBand1K = 5,
    /** 2 kHz. */
    TangAudioEqualizationBand2K = 6,
    /** 4 kHz. */
    TangAudioEqualizationBand4K = 7,
    /** 8 kHz. */
    TangAudioEqualizationBand8K = 8,
    /** 16 kHz. */
    TangAudioEqualizationBand16K = 9,
};

/** Audio reverberation type. */
typedef NS_ENUM(NSInteger, TangAudioReverbType) {
    /** The level of the dry signal (dB). The value ranges between -20 and 10. */
    TangAudioReverbDryLevel = 0,
    /** The level of the early reflection signal (wet signal) in dB. The value ranges between -20 and 10. */
    TangAudioReverbWetLevel = 1,
    /** The room size of the reverberation. A larger room size means a stronger reverberation. The value ranges between 0 and 100. */
    TangAudioReverbRoomSize = 2,
    /** The length of the initial delay of the wet signal (ms). The value ranges between 0 and 200. */
    TangAudioReverbWetDelay = 3,
     /** The reverberation strength. The value ranges between 0 and 100. */
    TangAudioReverbStrength = 4,
};

/** The preset audio voice configuration used to change the voice effect. */
typedef NS_ENUM(NSInteger, TangAudioVoiceChanger) {
    /** The original voice (no local voice change). */
    TangAudioVoiceChangerOff = 0,
    /** An old man's voice. */
    TangAudioVoiceChangerOldMan = 1,
    /** A little boy's voice. */
    TangAudioVoiceChangerBabyBoy = 2,
    /** A little girl's voice. */
    TangAudioVoiceChangerBabyGirl = 3,
    /** TBD */
    TangAudioVoiceChangerZhuBaJie = 4,
    /** Ethereal vocal effects. */
    TangAudioVoiceChangerEthereal = 5,
    /** Hulk's voice. */
    TangAudioVoiceChangerHulk = 6
};

/** The preset local voice reverberation option. */
typedef NS_ENUM(NSInteger, TangAudioReverbPreset) {
    /** The original voice (no local voice reverberation). */
    TangAudioReverbPresetOff = 0,
    /** Pop music */
    TangAudioReverbPresetPopular = 1,
    /** R&B */
    TangAudioReverbPresetRnB = 2,
    /** Rock music */
    TangAudioReverbPresetRock = 3,
    /** Hip-hop music */
    TangAudioReverbPresetHipHop = 4,
    /** Pop concert */
    TangAudioReverbPresetVocalConcert = 5,
    /** Karaoke */
    TangAudioReverbPresetKTV = 6,
    /** Recording studio */
    TangAudioReverbPresetStudio = 7
};

/** Audio session restriction. */
typedef NS_OPTIONS(NSUInteger, TangAudioSessionOperationRestriction) {
    /** No restriction, the SDK has full control of the audio session operations. */
    TangAudioSessionOperationRestrictionNone              = 0,
    /** The SDK does not change the audio session category. */
    TangAudioSessionOperationRestrictionSetCategory       = 1,
    /** The SDK does not change any setting of the audio session (category, mode, categoryOptions). */
    TangAudioSessionOperationRestrictionConfigureSession  = 1 << 1,
    /** The SDK keeps the audio session active when leaving a channel. */
    TangAudioSessionOperationRestrictionDeactivateSession = 1 << 2,
    /** The SDK does not configure the audio session anymore. */
    TangAudioSessionOperationRestrictionAll               = 1 << 7
};

/** Audio codec profile. */
typedef NS_ENUM(NSInteger, TangAudioCodecProfileType) {
    /** (Default) LC-AAC, the low-complexity audio codec profile. */
  TangAudioCodecProfileLCAAC = 0,
  /** HE-AAC, the high-efficiency audio codec profile. */
  TangAudioCodecProfileHEAAC = 1
};

/** The state of the remote audio. */
typedef NS_ENUM(NSUInteger, TangAudioRemoteState) {
    /** 0: The remote audio is in the default state, probably due to TangAudioRemoteReasonLocalMuted(3), TangAudioRemoteReasonRemoteMuted(5), or TangAudioRemoteReasonRemoteOffline(7). */
    TangAudioRemoteStateStopped = 0,
    /** 1: The first remote audio packet is received. */
    TangAudioRemoteStateStarting = 1,
    /** 2: The remote audio stream is decoded and plays normally, probably due to TangAudioRemoteReasonNetworkRecovery(2), TangAudioRemoteReasonLocalUnmuted(4), or TangAudioRemoteReasonRemoteUnmuted(6). */
    TangAudioRemoteStateDecoding = 2,
    /** 3: The remote audio is frozen, probably due to TangAudioRemoteReasonNetworkCongestion(1). */
    TangAudioRemoteStateFrozen = 3,
    /** 4: The remote audio fails to start, probably due to TangAudioRemoteReasonInternal(0). */
    TangAudioRemoteStateFailed = 4,
};

/** The reason of the remote audio state change. */
typedef NS_ENUM(NSUInteger, TangAudioRemoteStateReason) {
    /** 0: Internal reasons. */
    TangAudioRemoteReasonInternal = 0,
    /** 1: Network congestion. */
    TangAudioRemoteReasonNetworkCongestion = 1,
    /** 2: Network recovery. */
    TangAudioRemoteReasonNetworkRecovery = 2,
    /** 3: The local user stops receiving the remote audio stream or disables the audio module. */
    TangAudioRemoteReasonLocalMuted = 3,
    /** 4: The local user resumes receiving the remote audio stream or enables the audio module. */
    TangAudioRemoteReasonLocalUnmuted = 4,
    /** 5: The remote user stops sending the audio stream or disables the audio module. */
    TangAudioRemoteReasonRemoteMuted = 5,
    /** 6: The remote user resumes sending the audio stream or enables the audio module. */
    TangAudioRemoteReasonRemoteUnmuted = 6,
    /** 7: The remote user leaves the channel. */
    TangAudioRemoteReasonRemoteOffline = 7,
};

/** The state of the local audio. */
typedef NS_ENUM(NSUInteger, TangAudioLocalState) {
    /** 0: The local audio is in the initial state. */
    TangAudioLocalStateStopped = 0,
    /** 1: The recording device starts successfully.  */
    TangAudioLocalStateRecording = 1,
    /** 2: The first audio frame encodes successfully. */
    TangAudioLocalStateEncoding = 2,
    /** 3: The local audio fails to start. */
    TangAudioLocalStateFailed = 3,
};

/** The error information of the local audio. */
typedef NS_ENUM(NSUInteger, TangAudioLocalError) {
    /** 0: The local audio is normal. */
    TangAudioLocalErrorOk = 0,
    /** 1: No specified reason for the local audio failure. */
    TangAudioLocalErrorFailure = 1,
    /** 2: No permission to use the local audio device. */
    TangAudioLocalErrorDeviceNoPermission = 2,
    /** 3: The microphone is in use. */
    TangAudioLocalErrorDeviceBusy = 3,
    /** 4: The local audio recording fails. Check whether the recording device is working properly. */
    TangAudioLocalErrorRecordFailure = 4,
    /** 5: The local audio encoding fails. */
    TangAudioLocalErrorEncodeFailure = 5,
};

/** Media device type. */
typedef NS_ENUM(NSInteger, TangMediaDeviceType) {
    /** Unknown device. */
    TangMediaDeviceTypeAudioUnknown = -1,
    /** Audio playback device. */
    TangMediaDeviceTypeAudioPlayout = 0,
    /** Audio recording device. */
    TangMediaDeviceTypeAudioRecording = 1,
    /** Video render device. */
    TangMediaDeviceTypeVideoRender = 2,
    /** Video capture device. */
    TangMediaDeviceTypeVideoCapture = 3,
};

/** Connection states. */
typedef NS_ENUM(NSInteger, TangConnectionStateType) {
    /** <p>1: The SDK is disconnected from Tang's edge server.</p>
This is the initial state before [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]).<br>
The SDK also enters this state when the app calls [leaveChannel]([TangRtcEngineKit leaveChannel:]).
    */
    TangConnectionStateDisconnected = 1,
    /** <p>2: The SDK is connecting to Tang's edge server.</p>
When the app calls [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]), the SDK starts to establish a connection to the specified channel, triggers the [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]) callback, and switches to the `TangConnectionStateConnecting` state.<br>
<br>
When the SDK successfully joins the channel, the SDK triggers the [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]) callback and switches to the `TangConnectionStateConnected` state.<br>
<br>
After the SDK joins the channel and when it finishes initializing the media engine, the SDK triggers the [didJoinChannel]([TangRtcEngineDelegate rtcEngine:didJoinChannel:withUid:elapsed:]) callback.
*/
    TangConnectionStateConnecting = 2,
    /** <p>3: The SDK is connected to Tang's edge server and joins a channel. You can now publish or subscribe to a media stream in the channel.</p>
If the connection to the channel is lost because, for example, the network is down or switched, the SDK automatically tries to reconnect and triggers:
<li> The [rtcEngineConnectionDidInterrupted]([TangRtcEngineDelegate rtcEngineConnectionDidInterrupted:])(deprecated) callback
<li> The [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]) callback, and switches to the `TangConnectionStateReconnecting` state.
    */
    TangConnectionStateConnected = 3,
    /** <p>4: The SDK keeps rejoining the channel after being disconnected from a joined channel because of network issues.</p>
<li>If the SDK cannot rejoin the channel within 10 seconds after being disconnected from Tang's edge server, the SDK triggers the [rtcEngineConnectionDidLost]([TangRtcEngineDelegate rtcEngineConnectionDidLost:]) callback, stays in the `TangConnectionStateReconnecting` state, and keeps rejoining the channel.
<li>If the SDK fails to rejoin the channel 20 minutes after being disconnected from Tang's edge server, the SDK triggers the [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]) callback, switches to the `TangConnectionStateFailed` state, and stops rejoining the channel.
    */
    TangConnectionStateReconnecting = 4,
    /** <p>5: The SDK fails to connect to Tang's edge server or join the channel.</p>
You must call [leaveChannel]([TangRtcEngineKit leaveChannel:]) to leave this state, and call [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]) again to rejoin the channel.<br>
<br>
If the SDK is banned from joining the channel by Tang's edge server (through the RESTful API), the SDK triggers the [rtcEngineConnectionDidBanned]([TangRtcEngineDelegate rtcEngineConnectionDidBanned:])(deprecated) and [connectionChangedToState]([TangRtcEngineDelegate rtcEngine:connectionChangedToState:reason:]) callbacks.
    */
    TangConnectionStateFailed = 5,
};

/** Reasons for the connection state change. */
typedef NS_ENUM(NSUInteger, TangConnectionChangedReason) {
    /** 0: The SDK is connecting to Tang's edge server. */
    TangConnectionChangedConnecting = 0,
    /** 1: The SDK has joined the channel successfully. */
    TangConnectionChangedJoinSuccess = 1,
    /** 2: The connection between the SDK and Tang's edge server is interrupted.  */
    TangConnectionChangedInterrupted = 2,
    /** 3: The connection between the SDK and Tang's edge server is banned by Tang's edge server. */
    TangConnectionChangedBannedByServer = 3,
    /** 4: The SDK fails to join the channel for more than 20 minutes and stops reconnecting to the channel. */
    TangConnectionChangedJoinFailed = 4,
    /** 5: The SDK has left the channel. */
    TangConnectionChangedLeaveChannel = 5,
    /** 6: The specified App ID is invalid. Try to rejoin the channel with a valid App ID. */
    TangConnectionChangedInvalidAppId = 6,
    /** 7: The specified channel name is invalid. Try to rejoin the channel with a valid channel name. */
    TangConnectionChangedInvalidChannelName = 7,
    /** 8: The generated token is invalid probably due to the following reasons:
<li>The App Certificate for the project is enabled in Dashboard, but you do not use Token when joining the channel. If you enable the App Certificate, you must use a token to join the channel.
<li>The uid that you specify in the [joinChannelByToken]([TangRtcEngineKit joinChannelByToken:channelId:info:uid:joinSuccess:]) method is different from the uid that you pass for generating the token. */
    TangConnectionChangedInvalidToken = 8,
    /** 9: The token has expired. Generate a new token from your server. */
    TangConnectionChangedTokenExpired = 9,
    /** 10: The user is banned by the server. */
    TangConnectionChangedRejectedByServer = 10,
    /** 11: The SDK tries to reconnect after setting a proxy server. */
    TangConnectionChangedSettingProxyServer = 11,
    /** 12: The token renews. */
    TangConnectionChangedRenewToken = 12,
    /** 13: The client IP address has changed, probably due to a change of the network type, IP address, or network port. */
    TangConnectionChangedClientIpAddressChanged = 13,
    /** 14: Timeout for the keep-alive of the connection between the SDK and Tang's edge server. The connection state changes to TangConnectionStateReconnecting(4). */
    TangConnectionChangedKeepAliveTimeout = 14,
};

/** The state code in TangChannelMediaRelayState.
 */
typedef NS_ENUM(NSInteger, TangChannelMediaRelayState) {
    /** 0: The SDK is initializing.
     */
    TangChannelMediaRelayStateIdle = 0,
    /** 1: The SDK tries to relay the media stream to the destination channel.
     */
    TangChannelMediaRelayStateConnecting = 1,
    /** 2: The SDK successfully relays the media stream to the destination channel.
     */
    TangChannelMediaRelayStateRunning = 2,
    /** 3: A failure occurs. See the details in `error`.
     */
    TangChannelMediaRelayStateFailure = 3,
};

/** The event code in TangChannelMediaRelayEvent.
 */
typedef NS_ENUM(NSInteger, TangChannelMediaRelayEvent) {
    /** 0: The user disconnects from the server due to poor network connections.
     */
    TangChannelMediaRelayEventDisconnect = 0,
    /** 1: The network reconnects.
     */
    TangChannelMediaRelayEventConnected = 1,
    /** 2: The user joins the source channel.
     */
    TangChannelMediaRelayEventJoinedSourceChannel = 2,
    /** 3: The user joins the destination channel.
     */
    TangChannelMediaRelayEventJoinedDestinationChannel = 3,
    /** 4: The SDK starts relaying the media stream to the destination channel.
     */
    TangChannelMediaRelayEventSentToDestinationChannel = 4,
    /** 5: The server receives the video stream from the source channel.
     */
    TangChannelMediaRelayEventReceivedVideoPacketFromSource = 5,
    /** 6: The server receives the audio stream from the source channel.
     */
    TangChannelMediaRelayEventReceivedAudioPacketFromSource = 6,
    /** 7: The destination channel is updated.
     */
    TangChannelMediaRelayEventUpdateDestinationChannel = 7,
    /** 8: The destination channel update fails due to internal reasons.
     */
    TangChannelMediaRelayEventUpdateDestinationChannelRefused = 8,
    /** 9: The destination channel does not change, which means that the destination channel fails to be updated.
     */
    TangChannelMediaRelayEventUpdateDestinationChannelNotChange = 9,
    /** 10: The destination channel name is NULL.
     */
    TangChannelMediaRelayEventUpdateDestinationChannelIsNil = 10,
    /** 11: The video profile is sent to the server.
     */
    TangChannelMediaRelayEventVideoProfileUpdate = 11,
};

/** The error code in TangChannelMediaRelayError.
 */
typedef NS_ENUM(NSInteger, TangChannelMediaRelayError) {
    /** 0: The state is normal.
     */
    TangChannelMediaRelayErrorNone = 0,
    /** 1: An error occurs in the server response.
     */
    TangChannelMediaRelayErrorServerErrorResponse = 1,
    /** 2: No server response. You can call the [leaveChannel]([TangRtcEngineKit leaveChannel:]) method to leave the channel.
     */
    TangChannelMediaRelayErrorServerNoResponse = 2,
    /** 3: The SDK fails to access the service, probably due to limited resources of the server.
     */
    TangChannelMediaRelayErrorNoResourceAvailable = 3,
    /** 4: The server fails to join the source channel.
     */
    TangChannelMediaRelayErrorFailedJoinSourceChannel = 4,
    /** 5: The server fails to join the destination channel.
     */
    TangChannelMediaRelayErrorFailedJoinDestinationChannel = 5,
    /** 6: The server fails to receive the data from the source channel.
     */
    TangChannelMediaRelayErrorFailedPacketReceivedFromSource = 6,
    /** 7: The source channel fails to transmit data.
     */
    TangChannelMediaRelayErrorFailedPacketSentToDestination = 7,
    /** 8: The SDK disconnects from the server due to poor network connections. You can call the [leaveChannel]([TangRtcEngineKit leaveChannel:]) method to leave the channel.
     */
    TangChannelMediaRelayErrorServerConnectionLost = 8,
    /** 9: An internal error occurs in the server.
     */
    TangChannelMediaRelayErrorInternalError = 9,
    /** 10: The token of the source channel has expired.    
     */
    TangChannelMediaRelayErrorSourceTokenExpired = 10,
    /** 11: The token of the destination channel has expired.
     */
    TangChannelMediaRelayErrorDestinationTokenExpired = 11,
};

/** Network type. */
typedef NS_ENUM(NSInteger, TangNetworkType) {
  /** -1: The network type is unknown. */
  TangNetworkTypeUnknown = -1,
  /** 0: The SDK disconnects from the network. */
  TangNetworkTypeDisconnected = 0,
  /** 1: The network type is LAN. */
  TangNetworkTypeLAN = 1,
  /** 2: The network type is Wi-Fi (including hotspots). */
  TangNetworkTypeWIFI = 2,
  /** 3: The network type is mobile 2G. */
  TangNetworkTypeMobile2G = 3,
  /** 4: The network type is mobile 3G. */
  TangNetworkTypeMobile3G = 4,
  /** 5: The network type is mobile 4G. */
  TangNetworkTypeMobile4G = 5,
};

/** The video encoding degradation preference under limited bandwidth. */
typedef NS_ENUM(NSInteger, TangDegradationPreference) {
    /** (Default) Degrades the frame rate to guarantee the video quality. */
    TangDegradationMaintainQuality = 0,
    /** Degrades the video quality to guarantee the frame rate. */
    TangDegradationMaintainFramerate = 1,
    /** Reserved for future use. */
    TangDegradationBalanced = 2,
};
/** The lightening contrast level. */
typedef NS_ENUM(NSUInteger, TangLighteningContrastLevel) {
    /** Low contrast level. */
    TangLighteningContrastLow = 0,
    /** (Default) Normal contrast level. */
    TangLighteningContrastNormal = 1,
    /** High contrast level. */
    TangLighteningContrastHigh = 2,
};

/** The state of the probe test result. */
typedef NS_ENUM(NSUInteger, TangLastmileProbeResultState) {
  /** 1: the last-mile network probe test is complete. */
  TangLastmileProbeResultComplete = 1,
  /** 2: the last-mile network probe test is incomplete and the bandwidth estimation is not available, probably due to limited test resources. */
  TangLastmileProbeResultIncompleteNoBwe = 2,
  /** 3: the last-mile network probe test is not carried out, probably due to poor network conditions. */
  TangLastmileProbeResultUnavailable = 3,
};

/** The state of the local video stream. */
typedef NS_ENUM(NSInteger, TangLocalVideoStreamState) {
  /** 0: the local video is in the initial state. */
  TangLocalVideoStreamStateStopped = 0,
  /** 1: the local video capturer starts successfully. */
  TangLocalVideoStreamStateCapturing = 1,
  /** 2: the first local video frame encodes successfully. */
  TangLocalVideoStreamStateEncoding = 2,
  /** 3: the local video fails to start. */
  TangLocalVideoStreamStateFailed = 3,
};

/** The detailed error information of the local video. */
typedef NS_ENUM(NSInteger, TangLocalVideoStreamError) {
  /** 0: the local video is normal. */
  TangLocalVideoStreamErrorOK = 0,
  /** 1: no specified reason for the local video failure. */
  TangLocalVideoStreamErrorFailure = 1,
  /** 2: no permission to use the local video device. */
  TangLocalVideoStreamErrorDeviceNoPermission = 2,
  /** 3: the local video capturer is in use. */
  TangLocalVideoStreamErrorDeviceBusy = 3,
  /** 4: the local video capture fails. Check whether the capturer is working properly. */
  TangLocalVideoStreamErrorCaptureFailure = 4,
  /** 5: the local video encoding fails. */
  TangLocalVideoStreamErrorEncodeFailure = 5,
};