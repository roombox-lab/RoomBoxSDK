// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClsCrsware.proto

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

@class CrswareListGetS2C_CrswareInfo;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ClsCrswareRoot

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
@interface ClsCrswareRoot : GPBRootObject
@end

#pragma mark - CrswareListGetC2S

typedef GPB_ENUM(CrswareListGetC2S_FieldNumber) {
  CrswareListGetC2S_FieldNumber_Version = 1,
};

/**
 * 获取教材列表
 **/
@interface CrswareListGetC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - CrswareListGetS2C

typedef GPB_ENUM(CrswareListGetS2C_FieldNumber) {
  CrswareListGetS2C_FieldNumber_CrswareListArray = 1,
  CrswareListGetS2C_FieldNumber_Version = 2,
};

@interface CrswareListGetS2C : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<CrswareListGetS2C_CrswareInfo*> *crswareListArray;
/** The number of items in @c crswareListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger crswareListArray_Count;

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - CrswareListGetS2C_CrswareInfo

typedef GPB_ENUM(CrswareListGetS2C_CrswareInfo_FieldNumber) {
  CrswareListGetS2C_CrswareInfo_FieldNumber_Id_p = 1,
  CrswareListGetS2C_CrswareInfo_FieldNumber_Type = 2,
  CrswareListGetS2C_CrswareInfo_FieldNumber_Name = 3,
  CrswareListGetS2C_CrswareInfo_FieldNumber_URL = 4,
  CrswareListGetS2C_CrswareInfo_FieldNumber_FileMd5 = 5,
  CrswareListGetS2C_CrswareInfo_FieldNumber_FileSize = 6,
};

@interface CrswareListGetS2C_CrswareInfo : GPBMessage

@property(nonatomic, readwrite) uint32_t id_p;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite, copy, null_resettable) NSString *URL;

@property(nonatomic, readwrite, copy, null_resettable) NSString *fileMd5;

@property(nonatomic, readwrite) uint32_t fileSize;

@end

#pragma mark - CrswareListChangeNotify

typedef GPB_ENUM(CrswareListChangeNotify_FieldNumber) {
  CrswareListChangeNotify_FieldNumber_Version = 1,
};

@interface CrswareListChangeNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)