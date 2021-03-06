#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "AgoraVideoFrameObserver.h"
#import "AgoraVideoRawData.h"
#import "AudioController.h"
#import "AudioOptions.h"
#import "XDFAudioDataHandler.h"
#import "XDFExternalAudio.h"
#import "XDFRoomNetCheckManager.h"
#import "XDFRoomPingServer.h"
#import "XDFSimplePing.h"
#import "XDFRoomSDKContolManager.h"
#import "XDFBarrageInfoModel.h"
#import "XDFBarrageManager.h"
#import "XDFCommonBarrageView.h"
#import "CDVWKProcessPoolFactory.h"
#import "NSURLProtocol+WebKitSupport.h"
#import "XDFRoomBase64.h"
#import "AVAudioSession+XDF.h"
#import "NSObject+ToDictTool.h"
#import "RoomBoxV2ImageSetter.h"
#import "CHttpUtil.h"
#import "LogUtils.h"
#import "QSNetFactory.h"
#import "QsVideoFrameObserver.h"
#import "RoomBoxRtcCallBackFactory.h"
#import "RoomBoxRtcChannelCallBackFactory.h"
#import "RoomBoxRtcManagerFactory.h"
#import "RoomBoxRtcManagerInterface.h"
#import "RoomBoxVideoRawData.h"
#import "RoomBoxXDFVideoFrameObserver.h"
#import "CommonCrsWareInfo.pbobjc.h"
#import "DoubleTbroadcastMsg.pbobjc.h"
#import "DoubleTclassCommSet.pbobjc.h"
#import "DoubleTclsBoard.pbobjc.h"
#import "DoubleTclsChat.pbobjc.h"
#import "DoubleTclsClose.pbobjc.h"
#import "DoubleTclsInfo.pbobjc.h"
#import "DoubleTclsQuiz.pbobjc.h"
#import "DoubleTclsStorage.pbobjc.h"
#import "DoubleTclsTextbook.pbobjc.h"
#import "DoubleTdataVersion.pbobjc.h"
#import "DoubleTmicQueue.pbobjc.h"
#import "DoubleToacls.pbobjc.h"
#import "DoubleToscls.pbobjc.h"
#import "DoubleTotcls.pbobjc.h"
#import "DoubleTstarNum.pbobjc.h"
#import "DoubleTuserInfo.pbobjc.h"
#import "DoubleTuserList.pbobjc.h"
#import "MsclsQuiz.pbobjc.h"
#import "MsclsAddTbBlankPageC2S.pbobjc.h"
#import "MsclsAddTbBlankPageS2C.pbobjc.h"
#import "MsclsAddTbPageBoardDataC2S.pbobjc.h"
#import "MsclsAddTbPageBoardDataS2C.pbobjc.h"
#import "MsclsClearTbPageBoardDataC2S.pbobjc.h"
#import "MsclsClearTbPageBoardDataS2C.pbobjc.h"
#import "MsclsCurTbPageNotify.pbobjc.h"
#import "MsclsDelTbBlankPageC2S.pbobjc.h"
#import "MsclsDelTbBlankPageS2C.pbobjc.h"
#import "MsclsDelTbPageBoardDataC2S.pbobjc.h"
#import "MsclsDelTbPageBoardDataS2C.pbobjc.h"
#import "MsclsEditTbPageBoardDataC2S.pbobjc.h"
#import "MsclsEditTbPageBoardDataS2C.pbobjc.h"
#import "MsclsGetTbPageBoardDataC2S.pbobjc.h"
#import "MsclsReqSyncCurTbPageSetC2S.pbobjc.h"
#import "MsclsSetCurTbPageC2S.pbobjc.h"
#import "MsclsSetCurTbPageS2C.pbobjc.h"
#import "MsclsSetTbPageCursorPosC2S.pbobjc.h"
#import "MsclsSetTbPageCursorPosS2C.pbobjc.h"
#import "MsclsSetTbPageScrollbarPosC2S.pbobjc.h"
#import "MsclsSetTbPageScrollbarPosS2C.pbobjc.h"
#import "MsclsStorage.pbobjc.h"
#import "MsclsTbBoardNotify.pbobjc.h"
#import "MsclsTbPageBoardDataNotify.pbobjc.h"
#import "MsclsTbPageCursorPosNotify.pbobjc.h"
#import "MsclsTbPageListChangeNotify.pbobjc.h"
#import "MsclsTbPageScrollbarPosNotify.pbobjc.h"
#import "MsclsChatMsg.pbobjc.h"
#import "MclsClassInfo.pbobjc.h"
#import "MsclsClassInfo.pbobjc.h"
#import "MsclsCrswareInfo.pbobjc.h"
#import "MsclsSetMode.pbobjc.h"
#import "MsclsTypeInfo.pbobjc.h"
#import "MsclsUserInfo.pbobjc.h"
#import "SclsClassInfo.pbobjc.h"
#import "PacketExtHead.pbobjc.h"
#import "MsclsMic.pbobjc.h"
#import "ClsBoard.pbobjc.h"
#import "ClsCrsware.pbobjc.h"
#import "ClsQuiz.pbobjc.h"
#import "ClsSite.pbobjc.h"
#import "ClsStar.pbobjc.h"
#import "ClsTextbook.pbobjc.h"
#import "ClsAvsdk.pbobjc.h"
#import "SVCSDK.h"
#import "ByteArray.h"
#import "CoreSocketDataAdapter.h"
#import "ProtocalAdapter.h"
#import "SVCDefine.h"
#import "Svc_CmdId.h"
#import "XDFSvcDoubleTCmdId.h"
#import "XDFCoreSocketDataAdapter.h"
#import "XDFCoreSocketPacket.h"
#import "XDFProtoBufAdapter.h"
#import "AESTool.h"
#import "BaseSocket.h"
#import "LBSSocket.h"
#import "SvcSocket.h"
#import "CoreSocketPackage.h"
#import "ISocketData.h"
#import "SVCModels.h"
#import "SVCNumberDefine.h"
#import "AsyncSocket.h"
#import "AsyncUdpSocket.h"

FOUNDATION_EXPORT double RoomBoxLiveVersionNumber;
FOUNDATION_EXPORT const unsigned char RoomBoxLiveVersionString[];

