// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsSetMode.proto

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

@class UserRight;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MsclsSetModeRoot

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
@interface MsclsSetModeRoot : GPBRootObject
@end

#pragma mark - MSClsSyncSetModeC2S

typedef GPB_ENUM(MSClsSyncSetModeC2S_FieldNumber) {
  MSClsSyncSetModeC2S_FieldNumber_LectureModeVer = 1,
  MSClsSyncSetModeC2S_FieldNumber_UintSetVer = 2,
};

@interface MSClsSyncSetModeC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t lectureModeVer;

@property(nonatomic, readwrite) uint32_t uintSetVer;

@end

#pragma mark - MSClsSwitchLectureModeC2S

typedef GPB_ENUM(MSClsSwitchLectureModeC2S_FieldNumber) {
  MSClsSwitchLectureModeC2S_FieldNumber_Mode = 1,
  MSClsSwitchLectureModeC2S_FieldNumber_Status = 2,
};

@interface MSClsSwitchLectureModeC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t status;

@end

#pragma mark - MSClsSwitchLectureModeS2C

typedef GPB_ENUM(MSClsSwitchLectureModeS2C_FieldNumber) {
  MSClsSwitchLectureModeS2C_FieldNumber_RspCode = 1,
  MSClsSwitchLectureModeS2C_FieldNumber_Mode = 2,
  MSClsSwitchLectureModeS2C_FieldNumber_Status = 3,
  MSClsSwitchLectureModeS2C_FieldNumber_Version = 4,
  MSClsSwitchLectureModeS2C_FieldNumber_BeginTime = 5,
};

@interface MSClsSwitchLectureModeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t status;

@property(nonatomic, readwrite) uint32_t version;

@property(nonatomic, readwrite) uint64_t beginTime;

@end

#pragma mark - MSClsLectureModeNotify

typedef GPB_ENUM(MSClsLectureModeNotify_FieldNumber) {
  MSClsLectureModeNotify_FieldNumber_Mode = 1,
  MSClsLectureModeNotify_FieldNumber_Status = 2,
  MSClsLectureModeNotify_FieldNumber_Version = 3,
  MSClsLectureModeNotify_FieldNumber_BeginTime = 4,
};

@interface MSClsLectureModeNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t status;

@property(nonatomic, readwrite) uint32_t version;

@property(nonatomic, readwrite) uint64_t beginTime;

@end

#pragma mark - MSClsSetUintSetC2S

typedef GPB_ENUM(MSClsSetUintSetC2S_FieldNumber) {
  MSClsSetUintSetC2S_FieldNumber_Set = 1,
};

@interface MSClsSetUintSetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t set;

@end

#pragma mark - MSClsSetUintSetS2C

typedef GPB_ENUM(MSClsSetUintSetS2C_FieldNumber) {
  MSClsSetUintSetS2C_FieldNumber_RspCode = 1,
  MSClsSetUintSetS2C_FieldNumber_Set = 2,
  MSClsSetUintSetS2C_FieldNumber_Version = 3,
};

@interface MSClsSetUintSetS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t set;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - MSClsUintSetNotify

typedef GPB_ENUM(MSClsUintSetNotify_FieldNumber) {
  MSClsUintSetNotify_FieldNumber_Set = 1,
  MSClsUintSetNotify_FieldNumber_Version = 2,
  MSClsUintSetNotify_FieldNumber_Uid = 3,
};

@interface MSClsUintSetNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t set;

@property(nonatomic, readwrite) uint32_t version;

@property(nonatomic, readwrite) uint64_t uid;

@end

#pragma mark - UserRight

typedef GPB_ENUM(UserRight_FieldNumber) {
  UserRight_FieldNumber_Uid = 1,
  UserRight_FieldNumber_UserRight = 2,
};

@interface UserRight : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) uint32_t userRight;

@end

#pragma mark - MSClsSetUserRightsC2S

typedef GPB_ENUM(MSClsSetUserRightsC2S_FieldNumber) {
  MSClsSetUserRightsC2S_FieldNumber_UserRightArray = 1,
};

@interface MSClsSetUserRightsC2S : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<UserRight*> *userRightArray;
/** The number of items in @c userRightArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger userRightArray_Count;

@end

#pragma mark - MSClsSetUserRightsS2C

typedef GPB_ENUM(MSClsSetUserRightsS2C_FieldNumber) {
  MSClsSetUserRightsS2C_FieldNumber_RspCode = 1,
  MSClsSetUserRightsS2C_FieldNumber_UserRightArray = 2,
};

@interface MSClsSetUserRightsS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<UserRight*> *userRightArray;
/** The number of items in @c userRightArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger userRightArray_Count;

@end

#pragma mark - MSClsUserRightsNotify

typedef GPB_ENUM(MSClsUserRightsNotify_FieldNumber) {
  MSClsUserRightsNotify_FieldNumber_TeaUid = 1,
  MSClsUserRightsNotify_FieldNumber_UserRightArray = 2,
};

@interface MSClsUserRightsNotify : GPBMessage

@property(nonatomic, readwrite) uint64_t teaUid;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<UserRight*> *userRightArray;
/** The number of items in @c userRightArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger userRightArray_Count;

@end

#pragma mark - MSClsMsgRemindingC2S

typedef GPB_ENUM(MSClsMsgRemindingC2S_FieldNumber) {
  MSClsMsgRemindingC2S_FieldNumber_Type = 1,
  MSClsMsgRemindingC2S_FieldNumber_VecUidArray = 2,
  MSClsMsgRemindingC2S_FieldNumber_Content = 3,
};

@interface MSClsMsgRemindingC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, strong, null_resettable) GPBUInt64Array *vecUidArray;
/** The number of items in @c vecUidArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecUidArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsMsgRemindingS2C

typedef GPB_ENUM(MSClsMsgRemindingS2C_FieldNumber) {
  MSClsMsgRemindingS2C_FieldNumber_RspCode = 1,
  MSClsMsgRemindingS2C_FieldNumber_Type = 2,
  MSClsMsgRemindingS2C_FieldNumber_VecUidArray = 3,
  MSClsMsgRemindingS2C_FieldNumber_Content = 4,
};

@interface MSClsMsgRemindingS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, strong, null_resettable) GPBUInt64Array *vecUidArray;
/** The number of items in @c vecUidArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecUidArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

#pragma mark - MSClsMsgRemindingNotify

typedef GPB_ENUM(MSClsMsgRemindingNotify_FieldNumber) {
  MSClsMsgRemindingNotify_FieldNumber_Type = 1,
  MSClsMsgRemindingNotify_FieldNumber_Content = 2,
};

@interface MSClsMsgRemindingNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
