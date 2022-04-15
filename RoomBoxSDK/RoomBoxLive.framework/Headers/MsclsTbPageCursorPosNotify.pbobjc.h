// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsTbPageCursorPosNotify.proto

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

#pragma mark - MsclsTbPageCursorPosNotifyRoot

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
@interface MsclsTbPageCursorPosNotifyRoot : GPBRootObject
@end

#pragma mark - MSClsTbPageCursorPosNotify

typedef GPB_ENUM(MSClsTbPageCursorPosNotify_FieldNumber) {
  MSClsTbPageCursorPosNotify_FieldNumber_TextbookId = 1,
  MSClsTbPageCursorPosNotify_FieldNumber_Page = 2,
  MSClsTbPageCursorPosNotify_FieldNumber_PosX = 3,
  MSClsTbPageCursorPosNotify_FieldNumber_PosY = 4,
  MSClsTbPageCursorPosNotify_FieldNumber_Uid = 5,
};

/**
 * 下发教材页的鼠标位置通知
 * 0x0040006E
 **/
@interface MSClsTbPageCursorPosNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite, copy, null_resettable) NSString *posX;

@property(nonatomic, readwrite, copy, null_resettable) NSString *posY;

@property(nonatomic, readwrite) uint64_t uid;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)