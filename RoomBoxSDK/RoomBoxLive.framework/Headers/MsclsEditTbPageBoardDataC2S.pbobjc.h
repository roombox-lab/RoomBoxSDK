// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsEditTbPageBoardDataC2S.proto

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

@class MSClsEditTbPageBoardDataC2S_GraphicData;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MsclsEditTbPageBoardDataC2SRoot

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
@interface MsclsEditTbPageBoardDataC2SRoot : GPBRootObject
@end

#pragma mark - MSClsEditTbPageBoardDataC2S

typedef GPB_ENUM(MSClsEditTbPageBoardDataC2S_FieldNumber) {
  MSClsEditTbPageBoardDataC2S_FieldNumber_TextbookId = 1,
  MSClsEditTbPageBoardDataC2S_FieldNumber_Page = 2,
  MSClsEditTbPageBoardDataC2S_FieldNumber_VecGraphicArray = 3,
};

/**
 * 编辑课件页板书数据
 * 0x00400077
 **/
@interface MSClsEditTbPageBoardDataC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MSClsEditTbPageBoardDataC2S_GraphicData*> *vecGraphicArray;
/** The number of items in @c vecGraphicArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecGraphicArray_Count;

@end

#pragma mark - MSClsEditTbPageBoardDataC2S_GraphicData

typedef GPB_ENUM(MSClsEditTbPageBoardDataC2S_GraphicData_FieldNumber) {
  MSClsEditTbPageBoardDataC2S_GraphicData_FieldNumber_Seq = 1,
  MSClsEditTbPageBoardDataC2S_GraphicData_FieldNumber_StrData = 2,
  MSClsEditTbPageBoardDataC2S_GraphicData_FieldNumber_ByteData = 3,
};

@interface MSClsEditTbPageBoardDataC2S_GraphicData : GPBMessage

@property(nonatomic, readwrite) uint32_t seq;

@property(nonatomic, readwrite, copy, null_resettable) NSString *strData;

@property(nonatomic, readwrite, copy, null_resettable) NSData *byteData;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
