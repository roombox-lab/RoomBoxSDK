// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsTbPageBoardDataNotify.proto

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

@class MSClsTbPageBoardDataNotify_GraphicData;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MsclsTbPageBoardDataNotifyRoot

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
@interface MsclsTbPageBoardDataNotifyRoot : GPBRootObject
@end

#pragma mark - MSClsTbPageBoardDataNotify

typedef GPB_ENUM(MSClsTbPageBoardDataNotify_FieldNumber) {
  MSClsTbPageBoardDataNotify_FieldNumber_TextbookId = 1,
  MSClsTbPageBoardDataNotify_FieldNumber_Page = 2,
  MSClsTbPageBoardDataNotify_FieldNumber_Operate = 3,
  MSClsTbPageBoardDataNotify_FieldNumber_VecGraphicArray = 4,
};

/**
 * 下发课件页的板书数据通知
 * 0x00400070
 **/
@interface MSClsTbPageBoardDataNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite) uint32_t operate;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MSClsTbPageBoardDataNotify_GraphicData*> *vecGraphicArray;
/** The number of items in @c vecGraphicArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecGraphicArray_Count;

@end

#pragma mark - MSClsTbPageBoardDataNotify_GraphicData

typedef GPB_ENUM(MSClsTbPageBoardDataNotify_GraphicData_FieldNumber) {
  MSClsTbPageBoardDataNotify_GraphicData_FieldNumber_Seq = 1,
  MSClsTbPageBoardDataNotify_GraphicData_FieldNumber_Uid = 2,
  MSClsTbPageBoardDataNotify_GraphicData_FieldNumber_Time = 3,
  MSClsTbPageBoardDataNotify_GraphicData_FieldNumber_StrData = 4,
  MSClsTbPageBoardDataNotify_GraphicData_FieldNumber_ByteData = 5,
};

@interface MSClsTbPageBoardDataNotify_GraphicData : GPBMessage

@property(nonatomic, readwrite) uint32_t seq;

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) uint64_t time;

@property(nonatomic, readwrite, copy, null_resettable) NSString *strData;

@property(nonatomic, readwrite, copy, null_resettable) NSData *byteData;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)