// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsAddTbBlankPageC2S.proto

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

#pragma mark - MsclsAddTbBlankPageC2SRoot

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
@interface MsclsAddTbBlankPageC2SRoot : GPBRootObject
@end

#pragma mark - MSClsAddTbBlankPageC2S

typedef GPB_ENUM(MSClsAddTbBlankPageC2S_FieldNumber) {
  MSClsAddTbBlankPageC2S_FieldNumber_TextbookId = 1,
  MSClsAddTbBlankPageC2S_FieldNumber_Page = 2,
  MSClsAddTbBlankPageC2S_FieldNumber_Num = 3,
};

/**
 * 添加课件空白页
 * 0x00400063
 **/
@interface MSClsAddTbBlankPageC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite) uint32_t num;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
