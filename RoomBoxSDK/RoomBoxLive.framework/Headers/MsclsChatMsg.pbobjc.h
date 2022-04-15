// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsChatMsg.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#import <Protobuf/GPBProtocolBuffers.h>

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class MSClsChatMsg;
@class MSClsUserInfo;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MsclsChatMsgRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface MsclsChatMsgRoot : GPBRootObject
@end

#pragma mark - MSClsSendChatMsgC2S

typedef GPB_ENUM(MSClsSendChatMsgC2S_FieldNumber) {
  MSClsSendChatMsgC2S_FieldNumber_CliSeq = 1,
  MSClsSendChatMsgC2S_FieldNumber_SendTm = 2,
  MSClsSendChatMsgC2S_FieldNumber_Type = 3,
  MSClsSendChatMsgC2S_FieldNumber_Option = 4,
  MSClsSendChatMsgC2S_FieldNumber_Content = 5,
};

@interface MSClsSendChatMsgC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t cliSeq;

@property(nonatomic, readwrite) uint64_t sendTm;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *option;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsSendChatMsgC2SAck

typedef GPB_ENUM(MSClsSendChatMsgC2SAck_FieldNumber) {
  MSClsSendChatMsgC2SAck_FieldNumber_RspCode = 1,
  MSClsSendChatMsgC2SAck_FieldNumber_CliSeq = 2,
  MSClsSendChatMsgC2SAck_FieldNumber_MsgId = 3,
  MSClsSendChatMsgC2SAck_FieldNumber_SendTm = 4,
};

@interface MSClsSendChatMsgC2SAck : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t cliSeq;

@property(nonatomic, readwrite) uint64_t msgId;

@property(nonatomic, readwrite) uint64_t sendTm;

@end

#pragma mark - MSClsSendChatMsgS2C

typedef GPB_ENUM(MSClsSendChatMsgS2C_FieldNumber) {
  MSClsSendChatMsgS2C_FieldNumber_MsgId = 1,
  MSClsSendChatMsgS2C_FieldNumber_UserInfo = 2,
  MSClsSendChatMsgS2C_FieldNumber_SendTm = 3,
  MSClsSendChatMsgS2C_FieldNumber_Type = 4,
  MSClsSendChatMsgS2C_FieldNumber_Option = 5,
  MSClsSendChatMsgS2C_FieldNumber_Content = 6,
};

@interface MSClsSendChatMsgS2C : GPBMessage

@property(nonatomic, readwrite) uint64_t msgId;

@property(nonatomic, readwrite, strong, null_resettable) MSClsUserInfo *userInfo;
/** Test to see if @c userInfo has been set. */
@property(nonatomic, readwrite) BOOL hasUserInfo;

@property(nonatomic, readwrite) uint64_t sendTm;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *option;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsSendChatMsgS2CAck

typedef GPB_ENUM(MSClsSendChatMsgS2CAck_FieldNumber) {
  MSClsSendChatMsgS2CAck_FieldNumber_MsgId = 1,
};

@interface MSClsSendChatMsgS2CAck : GPBMessage

@property(nonatomic, readwrite) uint64_t msgId;

@end

#pragma mark - MSClsPullChatMsgC2S

typedef GPB_ENUM(MSClsPullChatMsgC2S_FieldNumber) {
  MSClsPullChatMsgC2S_FieldNumber_LowMsgId = 1,
  MSClsPullChatMsgC2S_FieldNumber_HighMsgId = 2,
};

@interface MSClsPullChatMsgC2S : GPBMessage

@property(nonatomic, readwrite) uint64_t lowMsgId;

@property(nonatomic, readwrite) uint64_t highMsgId;

@end

#pragma mark - MSClsChatMsg

typedef GPB_ENUM(MSClsChatMsg_FieldNumber) {
  MSClsChatMsg_FieldNumber_MsgId = 1,
  MSClsChatMsg_FieldNumber_UserInfo = 2,
  MSClsChatMsg_FieldNumber_SendTm = 3,
  MSClsChatMsg_FieldNumber_Type = 4,
  MSClsChatMsg_FieldNumber_Option = 5,
  MSClsChatMsg_FieldNumber_Content = 6,
};

@interface MSClsChatMsg : GPBMessage

@property(nonatomic, readwrite) uint64_t msgId;

@property(nonatomic, readwrite, strong, null_resettable) MSClsUserInfo *userInfo;
/** Test to see if @c userInfo has been set. */
@property(nonatomic, readwrite) BOOL hasUserInfo;

@property(nonatomic, readwrite) uint64_t sendTm;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *option;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsPullChatMsgS2C

typedef GPB_ENUM(MSClsPullChatMsgS2C_FieldNumber) {
  MSClsPullChatMsgS2C_FieldNumber_RspCode = 1,
  MSClsPullChatMsgS2C_FieldNumber_MinMsgId = 2,
  MSClsPullChatMsgS2C_FieldNumber_MaxMsgId = 3,
  MSClsPullChatMsgS2C_FieldNumber_MsgListArray = 4,
};

@interface MSClsPullChatMsgS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint64_t minMsgId;

@property(nonatomic, readwrite) uint64_t maxMsgId;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MSClsChatMsg*> *msgListArray;
/** The number of items in @c msgListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger msgListArray_Count;

@end

#pragma mark - MSClsLatestChatMsgNoitfy

typedef GPB_ENUM(MSClsLatestChatMsgNoitfy_FieldNumber) {
  MSClsLatestChatMsgNoitfy_FieldNumber_MsgListArray = 1,
};

@interface MSClsLatestChatMsgNoitfy : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MSClsChatMsg*> *msgListArray;
/** The number of items in @c msgListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger msgListArray_Count;

@end

#pragma mark - MSClsChatMsgMediaOkC2S

typedef GPB_ENUM(MSClsChatMsgMediaOkC2S_FieldNumber) {
  MSClsChatMsgMediaOkC2S_FieldNumber_MsgId = 1,
  MSClsChatMsgMediaOkC2S_FieldNumber_VecDataArray = 2,
};

@interface MSClsChatMsgMediaOkC2S : GPBMessage

@property(nonatomic, readwrite) uint64_t msgId;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecDataArray;
/** The number of items in @c vecDataArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecDataArray_Count;

@end

#pragma mark - MSClsChatMsgMediaOkS2C

typedef GPB_ENUM(MSClsChatMsgMediaOkS2C_FieldNumber) {
  MSClsChatMsgMediaOkS2C_FieldNumber_RspCode = 1,
  MSClsChatMsgMediaOkS2C_FieldNumber_MsgId = 2,
};

@interface MSClsChatMsgMediaOkS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint64_t msgId;

@end

#pragma mark - MSClsChatMsgMediaOkNotify

typedef GPB_ENUM(MSClsChatMsgMediaOkNotify_FieldNumber) {
  MSClsChatMsgMediaOkNotify_FieldNumber_MsgId = 1,
  MSClsChatMsgMediaOkNotify_FieldNumber_VecDataArray = 2,
};

@interface MSClsChatMsgMediaOkNotify : GPBMessage

@property(nonatomic, readwrite) uint64_t msgId;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecDataArray;
/** The number of items in @c vecDataArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecDataArray_Count;

@end

#pragma mark - MSClsSendCommNoticeC2S

typedef GPB_ENUM(MSClsSendCommNoticeC2S_FieldNumber) {
  MSClsSendCommNoticeC2S_FieldNumber_Content = 1,
};

/**
 * /notice
 **/
@interface MSClsSendCommNoticeC2S : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsSendCommNoticeS2C

typedef GPB_ENUM(MSClsSendCommNoticeS2C_FieldNumber) {
  MSClsSendCommNoticeS2C_FieldNumber_RspCode = 1,
  MSClsSendCommNoticeS2C_FieldNumber_Content = 2,
};

@interface MSClsSendCommNoticeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsSendCommNoticeNotify

typedef GPB_ENUM(MSClsSendCommNoticeNotify_FieldNumber) {
  MSClsSendCommNoticeNotify_FieldNumber_UserInfo = 1,
  MSClsSendCommNoticeNotify_FieldNumber_Content = 2,
};

@interface MSClsSendCommNoticeNotify : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) MSClsUserInfo *userInfo;
/** Test to see if @c userInfo has been set. */
@property(nonatomic, readwrite) BOOL hasUserInfo;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)