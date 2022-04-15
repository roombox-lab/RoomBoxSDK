// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsClearTbPageBoardDataS2C.proto

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

#pragma mark - MsclsClearTbPageBoardDataS2CRoot

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
@interface MsclsClearTbPageBoardDataS2CRoot : GPBRootObject
@end

#pragma mark - MSClsClearTbPageBoardDataS2C

typedef GPB_ENUM(MSClsClearTbPageBoardDataS2C_FieldNumber) {
  MSClsClearTbPageBoardDataS2C_FieldNumber_RspCode = 1,
  MSClsClearTbPageBoardDataS2C_FieldNumber_TextbookId = 2,
  MSClsClearTbPageBoardDataS2C_FieldNumber_Page = 3,
};

/**
 * 清空课件页板书数据
 * 0x0040007A
 **/
@interface MSClsClearTbPageBoardDataS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)