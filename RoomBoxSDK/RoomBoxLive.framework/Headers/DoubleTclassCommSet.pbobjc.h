// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DoubleTClassCommSet.proto

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

NS_ASSUME_NONNULL_BEGIN

#pragma mark - DoubleTclassCommSetRoot

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
@interface DoubleTclassCommSetRoot : GPBRootObject
@end

#pragma mark - SetLectureModeC2S

typedef GPB_ENUM(SetLectureModeC2S_FieldNumber) {
  SetLectureModeC2S_FieldNumber_Mode = 1,
};

/**
 * 0x0043003F
 **/
@interface SetLectureModeC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t mode;

@end

#pragma mark - SetLectureModeS2C

typedef GPB_ENUM(SetLectureModeS2C_FieldNumber) {
  SetLectureModeS2C_FieldNumber_RspCode = 1,
  SetLectureModeS2C_FieldNumber_Mode = 2,
  SetLectureModeS2C_FieldNumber_Version = 3,
};

/**
 * 0x00430040
 **/
@interface SetLectureModeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - GetLectureModeC2S

typedef GPB_ENUM(GetLectureModeC2S_FieldNumber) {
  GetLectureModeC2S_FieldNumber_Version = 1,
};

/**
 * 0x00430041,0x00440041,0x00450041
 **/
@interface GetLectureModeC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - GetLectureModeS2C

typedef GPB_ENUM(GetLectureModeS2C_FieldNumber) {
  GetLectureModeS2C_FieldNumber_RspCode = 1,
  GetLectureModeS2C_FieldNumber_Mode = 2,
  GetLectureModeS2C_FieldNumber_Version = 3,
};

/**
 * 0x00430042,0x00440042,0x00450042
 **/
@interface GetLectureModeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - LectureModeNotify

typedef GPB_ENUM(LectureModeNotify_FieldNumber) {
  LectureModeNotify_FieldNumber_Mode = 1,
  LectureModeNotify_FieldNumber_Version = 2,
};

/**
 * 0x00430043,0x00440043,0x00450043
 **/
@interface LectureModeNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t mode;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - OTClsSetNotify

typedef GPB_ENUM(OTClsSetNotify_FieldNumber) {
  OTClsSetNotify_FieldNumber_Tset = 1,
  OTClsSetNotify_FieldNumber_Version = 2,
};

/**
 * 0x00430044
 **/
@interface OTClsSetNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t tset;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - OTClsGetClsSetC2S

typedef GPB_ENUM(OTClsGetClsSetC2S_FieldNumber) {
  OTClsGetClsSetC2S_FieldNumber_Version = 1,
};

/**
 * 0x00430045
 **/
@interface OTClsGetClsSetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - OTClsGetClsSetS2C

typedef GPB_ENUM(OTClsGetClsSetS2C_FieldNumber) {
  OTClsGetClsSetS2C_FieldNumber_RspCode = 1,
  OTClsGetClsSetS2C_FieldNumber_Tset = 2,
  OTClsGetClsSetS2C_FieldNumber_Version = 3,
};

/**
 * 0x00430046
 **/
@interface OTClsGetClsSetS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t tset;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - OTClsSetClsCommSetC2S

typedef GPB_ENUM(OTClsSetClsCommSetC2S_FieldNumber) {
  OTClsSetClsCommSetC2S_FieldNumber_OpType = 1,
  OTClsSetClsCommSetC2S_FieldNumber_Offset = 2,
  OTClsSetClsCommSetC2S_FieldNumber_Tset = 3,
};

/**
 * 0x00430047
 **/
@interface OTClsSetClsCommSetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t opType;

@property(nonatomic, readwrite) uint32_t offset;

@property(nonatomic, readwrite) uint32_t tset;

@end

#pragma mark - OTClsSetClsCommSetS2C

typedef GPB_ENUM(OTClsSetClsCommSetS2C_FieldNumber) {
  OTClsSetClsCommSetS2C_FieldNumber_RspCode = 1,
  OTClsSetClsCommSetS2C_FieldNumber_OpType = 2,
  OTClsSetClsCommSetS2C_FieldNumber_Offset = 3,
  OTClsSetClsCommSetS2C_FieldNumber_Tset = 4,
  OTClsSetClsCommSetS2C_FieldNumber_Version = 5,
};

/**
 * 0x00430048
 **/
@interface OTClsSetClsCommSetS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t opType;

@property(nonatomic, readwrite) uint32_t offset;

@property(nonatomic, readwrite) uint32_t tset;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - ClsSetNotify

typedef GPB_ENUM(ClsSetNotify_FieldNumber) {
  ClsSetNotify_FieldNumber_Tset = 1,
  ClsSetNotify_FieldNumber_Aset = 2,
  ClsSetNotify_FieldNumber_Version = 3,
};

/**
 * 0x00440044,0x00450044
 **/
@interface ClsSetNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t tset;

@property(nonatomic, readwrite) uint32_t aset;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - GetClsSetC2S

typedef GPB_ENUM(GetClsSetC2S_FieldNumber) {
  GetClsSetC2S_FieldNumber_Version = 1,
};

/**
 * 0x00440045,0x00450045
 **/
@interface GetClsSetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - GetClsSetS2C

typedef GPB_ENUM(GetClsSetS2C_FieldNumber) {
  GetClsSetS2C_FieldNumber_RspCode = 1,
  GetClsSetS2C_FieldNumber_Tset = 2,
  GetClsSetS2C_FieldNumber_Aset = 3,
  GetClsSetS2C_FieldNumber_Version = 4,
};

/**
 * 0x00440046,0x00450046
 **/
@interface GetClsSetS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t tset;

@property(nonatomic, readwrite) uint32_t aset;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - OAClsSetClsCommSetC2S

typedef GPB_ENUM(OAClsSetClsCommSetC2S_FieldNumber) {
  OAClsSetClsCommSetC2S_FieldNumber_OpType = 1,
  OAClsSetClsCommSetC2S_FieldNumber_Offset = 2,
  OAClsSetClsCommSetC2S_FieldNumber_Aset = 3,
};

/**
 * 0x00440047
 **/
@interface OAClsSetClsCommSetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t opType;

@property(nonatomic, readwrite) uint32_t offset;

@property(nonatomic, readwrite) uint32_t aset;

@end

#pragma mark - OAClsSetClsCommSetS2C

typedef GPB_ENUM(OAClsSetClsCommSetS2C_FieldNumber) {
  OAClsSetClsCommSetS2C_FieldNumber_RspCode = 1,
  OAClsSetClsCommSetS2C_FieldNumber_OpType = 2,
  OAClsSetClsCommSetS2C_FieldNumber_Offset = 3,
  OAClsSetClsCommSetS2C_FieldNumber_Aset = 4,
  OAClsSetClsCommSetS2C_FieldNumber_Version = 5,
};

/**
 * 0x00440048
 **/
@interface OAClsSetClsCommSetS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t opType;

@property(nonatomic, readwrite) uint32_t offset;

@property(nonatomic, readwrite) uint32_t aset;

@property(nonatomic, readwrite) uint32_t version;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)