//
//  ISacDataConfig.h
//  LogSend
//
//  Created by 吴云海 on 2019/6/21.
//  Copyright © 2019 吴云海. All rights reserved.
//

//#ifndef ISacDataConfig_h
//#define ISacDataConfig_h



typedef NS_ENUM(NSUInteger, EHeaderDef) {
    emUid = 1,
    emRole = 2,
    emDevice_name = 3,
    emOs = 4,
    emLanguage = 5,
    emClient_version = 6,
    emIp = 7,
    emSid = 9,
    emUser_name = 10,
    emClassroom_id = 11,
    emMac = 12,
    emDataHost = 100,
    emDataPort = 101
} ;

typedef NS_ENUM(NSUInteger, EPIPCCOMMAND) {
    emEnumStartTag = 1,
    emStartInstall = 2,
    emEndInstall = 3,
    emStartUninstall = 4,
    emEndUninstall = 5,
    emStartUpgrade = 6,
    emEndUpgrade = 7,
    emNavigationEvent = 8,
    emEnterClassroom = 9,
    emExitClassroom = 10,
    emDownload = 11,
    emCrash = 12,
    emDeviceOnOffOp = 13,
    emChatMessage = 14,
    emSysMessage = 15,
    emBanChatAuthOp = 16,
    emHandsUp = 17,
    emListenToOp = 18,
    emOnWallOp = 19,
    emWbAuthOp = 20,
    emSendStar = 21,
    emWhiteboardOp = 22,
    emDeviceMalfunction = 23,
    emReplay = 24,
    emDeviceCheckReport = 25,
    emRtcNetworkMalfunction = 26,
    emRtcAudioQuality = 27,
    emRtcStats = 28,
    emRtcNetworkQuality = 29,
    emRtcLocalVideoStats = 30,
    emRtcRemoteVideoStats = 31,
    emRtcRemoteAudioTransportStats = 32,
    emRtcRemoteVideoTransportStats = 33,
    emEndClassData = 34,
    emEnumEndTag = 35
} ;

//#endif /* ISacDataConfig_h */
