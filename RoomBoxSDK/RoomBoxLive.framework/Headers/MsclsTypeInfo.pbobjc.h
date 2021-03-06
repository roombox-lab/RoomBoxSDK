// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsTypeInfo.proto

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

#pragma mark - MsclsTypeInfoRoot

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
@interface MsclsTypeInfoRoot : GPBRootObject
@end

#pragma mark - MSClsGetClassTypeS2C

typedef GPB_ENUM(MSClsGetClassTypeS2C_FieldNumber) {
  MSClsGetClassTypeS2C_FieldNumber_RspCode = 1,
  MSClsGetClassTypeS2C_FieldNumber_Type = 2,
  MSClsGetClassTypeS2C_FieldNumber_Mcid = 3,
  MSClsGetClassTypeS2C_FieldNumber_Scid = 4,
};

@interface MSClsGetClassTypeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite) uint64_t mcid;

@property(nonatomic, readwrite) uint64_t scid;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
