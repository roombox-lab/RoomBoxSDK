// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsSetTbPageScrollbarPosC2S.proto

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

#pragma mark - MsclsSetTbPageScrollbarPosC2SRoot

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
@interface MsclsSetTbPageScrollbarPosC2SRoot : GPBRootObject
@end

#pragma mark - MSClsSetTbPageScrollbarPosC2S

typedef GPB_ENUM(MSClsSetTbPageScrollbarPosC2S_FieldNumber) {
  MSClsSetTbPageScrollbarPosC2S_FieldNumber_TextbookId = 1,
  MSClsSetTbPageScrollbarPosC2S_FieldNumber_Page = 2,
  MSClsSetTbPageScrollbarPosC2S_FieldNumber_PosX = 3,
  MSClsSetTbPageScrollbarPosC2S_FieldNumber_PosY = 4,
};

/**
 * 设置课件页的滚动条位置
 * 0x00400069
 **/
@interface MSClsSetTbPageScrollbarPosC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite, copy, null_resettable) NSString *posX;

@property(nonatomic, readwrite, copy, null_resettable) NSString *posY;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
