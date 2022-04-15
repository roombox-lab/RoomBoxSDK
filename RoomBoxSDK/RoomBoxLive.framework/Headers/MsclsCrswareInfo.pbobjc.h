// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsCrswareInfo.proto

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

#pragma mark - MsclsCrswareInfoRoot

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
@interface MsclsCrswareInfoRoot : GPBRootObject
@end

#pragma mark - MSClsCrswareInfo

typedef GPB_ENUM(MSClsCrswareInfo_FieldNumber) {
  MSClsCrswareInfo_FieldNumber_Id_p = 1,
  MSClsCrswareInfo_FieldNumber_Type = 2,
  MSClsCrswareInfo_FieldNumber_Name = 3,
  MSClsCrswareInfo_FieldNumber_URL = 4,
  MSClsCrswareInfo_FieldNumber_FileMd5 = 5,
  MSClsCrswareInfo_FieldNumber_FileSize = 6,
};

@interface MSClsCrswareInfo : GPBMessage

@property(nonatomic, readwrite) uint32_t id_p;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite, copy, null_resettable) NSString *URL;

@property(nonatomic, readwrite, copy, null_resettable) NSString *fileMd5;

@property(nonatomic, readwrite) uint32_t fileSize;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)