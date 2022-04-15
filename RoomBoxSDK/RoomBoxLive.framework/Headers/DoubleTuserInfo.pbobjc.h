// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DoubleTUserInfo.proto

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

#pragma mark - DoubleTuserInfoRoot

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
@interface DoubleTuserInfoRoot : GPBRootObject
@end
#pragma mark - DoubleTUserInfo_UserSkin

typedef GPB_ENUM(DoubleTUserInfo_UserSkin_FieldNumber) {
  DoubleTUserInfo_UserSkin_FieldNumber_Id_p = 1,
  DoubleTUserInfo_UserSkin_FieldNumber_CategoryId = 2,
  DoubleTUserInfo_UserSkin_FieldNumber_ItemId = 3,
  DoubleTUserInfo_UserSkin_FieldNumber_ExpireTs = 4,
  DoubleTUserInfo_UserSkin_FieldNumber_Status = 5,
  DoubleTUserInfo_UserSkin_FieldNumber_CreateTime = 6,
  DoubleTUserInfo_UserSkin_FieldNumber_UpdateTime = 7,
};

@interface DoubleTUserInfo_UserSkin : GPBMessage

@property(nonatomic, readwrite) uint64_t id_p;

@property(nonatomic, readwrite) uint32_t categoryId;

@property(nonatomic, readwrite) uint32_t itemId;

@property(nonatomic, readwrite) uint64_t expireTs;

@property(nonatomic, readwrite) uint32_t status;

@property(nonatomic, readwrite, copy, null_resettable) NSString *createTime;

@property(nonatomic, readwrite, copy, null_resettable) NSString *updateTime;

@end

#pragma mark - DoubleTUserInfo

typedef GPB_ENUM(DoubleTUserInfo_FieldNumber) {
  DoubleTUserInfo_FieldNumber_Uid = 1,
  DoubleTUserInfo_FieldNumber_Identity = 2,
  DoubleTUserInfo_FieldNumber_Right = 3,
  DoubleTUserInfo_FieldNumber_OnlineStat = 4,
  DoubleTUserInfo_FieldNumber_Name = 5,
  DoubleTUserInfo_FieldNumber_Avatar = 6,
  DoubleTUserInfo_FieldNumber_CusData = 7,
  DoubleTUserInfo_FieldNumber_Cid = 8,
  DoubleTUserInfo_FieldNumber_Ctype = 9,
  DoubleTUserInfo_FieldNumber_RowNum = 10,
  DoubleTUserInfo_FieldNumber_ColNum = 11,
  DoubleTUserInfo_FieldNumber_Switch_p = 12,
  DoubleTUserInfo_FieldNumber_ClassCName = 13,
  DoubleTUserInfo_FieldNumber_ClassEname = 14,
  DoubleTUserInfo_FieldNumber_StarNum = 15,
  DoubleTUserInfo_FieldNumber_RealName = 16,
  DoubleTUserInfo_FieldNumber_UserSkinArray = 17,
};

@interface DoubleTUserInfo : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) uint32_t identity;

@property(nonatomic, readwrite) uint32_t right;

@property(nonatomic, readwrite) uint32_t onlineStat;

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite, copy, null_resettable) NSString *avatar;

@property(nonatomic, readwrite, copy, null_resettable) NSString *cusData;

@property(nonatomic, readwrite) uint64_t cid;

@property(nonatomic, readwrite) uint32_t ctype;

@property(nonatomic, readwrite) uint32_t rowNum;

@property(nonatomic, readwrite) uint32_t colNum;

@property(nonatomic, readwrite) uint32_t switch_p;

@property(nonatomic, readwrite, copy, null_resettable) NSString *classCName;

@property(nonatomic, readwrite, copy, null_resettable) NSString *classEname;

@property(nonatomic, readwrite) int32_t starNum;

@property(nonatomic, readwrite, copy, null_resettable) NSString *realName;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<DoubleTUserInfo_UserSkin*> *userSkinArray;
/** The number of items in @c userSkinArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger userSkinArray_Count;

@end


NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)