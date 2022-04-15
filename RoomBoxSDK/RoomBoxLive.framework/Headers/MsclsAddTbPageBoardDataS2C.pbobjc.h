// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSClsAddTbPageBoardDataS2C.proto

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

@class MSClsAddTbPageBoardDataS2C_GraphicData;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MsclsAddTbPageBoardDataS2CRoot

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
@interface MsclsAddTbPageBoardDataS2CRoot : GPBRootObject
@end

#pragma mark - MSClsAddTbPageBoardDataS2C

typedef GPB_ENUM(MSClsAddTbPageBoardDataS2C_FieldNumber) {
  MSClsAddTbPageBoardDataS2C_FieldNumber_RspCode = 1,
  MSClsAddTbPageBoardDataS2C_FieldNumber_TextbookId = 2,
  MSClsAddTbPageBoardDataS2C_FieldNumber_Page = 3,
  MSClsAddTbPageBoardDataS2C_FieldNumber_VecGraphicArray = 4,
};

/**
 * 添加课件页板书数据
 * 0x00400074
 **/
@interface MSClsAddTbPageBoardDataS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t textbookId;

@property(nonatomic, readwrite) uint32_t page;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MSClsAddTbPageBoardDataS2C_GraphicData*> *vecGraphicArray;
/** The number of items in @c vecGraphicArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecGraphicArray_Count;

@end

#pragma mark - MSClsAddTbPageBoardDataS2C_GraphicData

typedef GPB_ENUM(MSClsAddTbPageBoardDataS2C_GraphicData_FieldNumber) {
  MSClsAddTbPageBoardDataS2C_GraphicData_FieldNumber_CliSeq = 1,
  MSClsAddTbPageBoardDataS2C_GraphicData_FieldNumber_Seq = 2,
  MSClsAddTbPageBoardDataS2C_GraphicData_FieldNumber_Time = 3,
};

@interface MSClsAddTbPageBoardDataS2C_GraphicData : GPBMessage

@property(nonatomic, readwrite) uint32_t cliSeq;

@property(nonatomic, readwrite) uint32_t seq;

@property(nonatomic, readwrite) uint64_t time;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
