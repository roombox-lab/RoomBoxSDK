// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CommonCrsWareInfo.proto

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

@class GetCrsWareInfoV2Rsp_Item;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - CommonCrsWareInfoRoot

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
@interface CommonCrsWareInfoRoot : GPBRootObject
@end

#pragma mark - GetCrsWareInfoV2Req

typedef GPB_ENUM(GetCrsWareInfoV2Req_FieldNumber) {
  GetCrsWareInfoV2Req_FieldNumber_VecCrswareIdArray = 1,
};

/**
 * 0x001A0025
 **/
@interface GetCrsWareInfoV2Req : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) GPBUInt64Array *vecCrswareIdArray;
/** The number of items in @c vecCrswareIdArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecCrswareIdArray_Count;

@end

#pragma mark - GetCrsWareInfoV2Rsp

typedef GPB_ENUM(GetCrsWareInfoV2Rsp_FieldNumber) {
  GetCrsWareInfoV2Rsp_FieldNumber_RspCode = 1,
  GetCrsWareInfoV2Rsp_FieldNumber_CrswareListArray = 2,
};

/**
 * 0x001A0026
 **/
@interface GetCrsWareInfoV2Rsp : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<GetCrsWareInfoV2Rsp_Item*> *crswareListArray;
/** The number of items in @c crswareListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger crswareListArray_Count;

@end

#pragma mark - GetCrsWareInfoV2Rsp_Item

typedef GPB_ENUM(GetCrsWareInfoV2Rsp_Item_FieldNumber) {
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Id_p = 1,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Name = 2,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Size = 3,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Type = 4,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_SubType = 5,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Md5 = 6,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_Etag = 7,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_ThumbURL = 8,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_UpdateTime = 9,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_TransProgress = 10,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_TrdPartId = 11,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_OriginalId = 12,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_URL = 13,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_ZipURL = 14,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_URLLstArray = 15,
  GetCrsWareInfoV2Rsp_Item_FieldNumber_ZipURLLstArray = 16,
};

@interface GetCrsWareInfoV2Rsp_Item : GPBMessage

@property(nonatomic, readwrite) uint64_t id_p;

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite) uint32_t size;

@property(nonatomic, readwrite) uint32_t type;

@property(nonatomic, readwrite) uint32_t subType;

@property(nonatomic, readwrite, copy, null_resettable) NSString *md5;

@property(nonatomic, readwrite, copy, null_resettable) NSString *etag;

@property(nonatomic, readwrite, copy, null_resettable) NSString *thumbURL;

@property(nonatomic, readwrite) uint64_t updateTime;

@property(nonatomic, readwrite) uint32_t transProgress;

@property(nonatomic, readwrite) uint64_t trdPartId;

@property(nonatomic, readwrite) uint32_t originalId;

@property(nonatomic, readwrite, copy, null_resettable) NSString *URL;

@property(nonatomic, readwrite, copy, null_resettable) NSString *zipURL;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *URLLstArray;
/** The number of items in @c URLLstArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger URLLstArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *zipURLLstArray;
/** The number of items in @c zipURLLstArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger zipURLLstArray_Count;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
