// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClsStar.proto

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

@class ClsAddUserStarNotify_StarUser;
@class ClsAddUserStarReq_UserStarItem;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ClsStarRoot

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
@interface ClsStarRoot : GPBRootObject
@end

#pragma mark - ClsAddUserStarReq

typedef GPB_ENUM(ClsAddUserStarReq_FieldNumber) {
  ClsAddUserStarReq_FieldNumber_VecItemArray = 1,
  ClsAddUserStarReq_FieldNumber_StrData = 2,
  ClsAddUserStarReq_FieldNumber_Source = 3,
};

/**
 * 0x00130066
 **/
@interface ClsAddUserStarReq : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ClsAddUserStarReq_UserStarItem*> *vecItemArray;
/** The number of items in @c vecItemArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecItemArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *strData;

@property(nonatomic, readwrite) int32_t source;

@end

#pragma mark - ClsAddUserStarReq_UserStarItem

typedef GPB_ENUM(ClsAddUserStarReq_UserStarItem_FieldNumber) {
  ClsAddUserStarReq_UserStarItem_FieldNumber_Uid = 1,
  ClsAddUserStarReq_UserStarItem_FieldNumber_StarNum = 2,
};

@interface ClsAddUserStarReq_UserStarItem : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) int32_t starNum;

@end

#pragma mark - ClsAddUserStarRsp

typedef GPB_ENUM(ClsAddUserStarRsp_FieldNumber) {
  ClsAddUserStarRsp_FieldNumber_RspCode = 1,
};

/**
 * 0x00130067
 **/
@interface ClsAddUserStarRsp : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@end

#pragma mark - ClsAddUserStarNotify

typedef GPB_ENUM(ClsAddUserStarNotify_FieldNumber) {
  ClsAddUserStarNotify_FieldNumber_Source = 1,
  ClsAddUserStarNotify_FieldNumber_OpUser = 2,
  ClsAddUserStarNotify_FieldNumber_AddUsersArray = 3,
};

/**
 * 0x00420050
 **/
@interface ClsAddUserStarNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t source;

@property(nonatomic, readwrite, strong, null_resettable) ClsAddUserStarNotify_StarUser *opUser;
/** Test to see if @c opUser has been set. */
@property(nonatomic, readwrite) BOOL hasOpUser;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ClsAddUserStarNotify_StarUser*> *addUsersArray;
/** The number of items in @c addUsersArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger addUsersArray_Count;

@end

#pragma mark - ClsAddUserStarNotify_StarUser

typedef GPB_ENUM(ClsAddUserStarNotify_StarUser_FieldNumber) {
  ClsAddUserStarNotify_StarUser_FieldNumber_Uid = 1,
  ClsAddUserStarNotify_StarUser_FieldNumber_Name = 2,
  ClsAddUserStarNotify_StarUser_FieldNumber_RoleId = 3,
  ClsAddUserStarNotify_StarUser_FieldNumber_Avatar = 4,
  ClsAddUserStarNotify_StarUser_FieldNumber_AddStarNum = 5,
  ClsAddUserStarNotify_StarUser_FieldNumber_TotalStarNum = 6,
};

@interface ClsAddUserStarNotify_StarUser : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite) uint32_t roleId;

@property(nonatomic, readwrite, copy, null_resettable) NSString *avatar;

@property(nonatomic, readwrite) uint32_t addStarNum;

@property(nonatomic, readwrite) uint32_t totalStarNum;

@end
NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
