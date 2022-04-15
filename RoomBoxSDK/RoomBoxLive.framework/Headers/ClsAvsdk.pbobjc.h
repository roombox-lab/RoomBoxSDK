// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClsAVSDK.proto

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

#pragma mark - ClsAvsdkRoot

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
@interface ClsAvsdkRoot : GPBRootObject
@end

#pragma mark - GetAVSDKListC2S

typedef GPB_ENUM(GetAVSDKListC2S_FieldNumber) {
  GetAVSDKListC2S_FieldNumber_CliVer = 1,
};

/**
 * 0x00130117
 **/
@interface GetAVSDKListC2S : GPBMessage

/** 客户端本地的音视频SDK（列表）版本号 */
@property(nonatomic, readwrite) uint32_t cliVer;

@end

#pragma mark - GetAVSDKListS2C

typedef GPB_ENUM(GetAVSDKListS2C_FieldNumber) {
  GetAVSDKListS2C_FieldNumber_RspCode = 1,
  GetAVSDKListS2C_FieldNumber_CliVer = 2,
  GetAVSDKListS2C_FieldNumber_Version = 3,
  GetAVSDKListS2C_FieldNumber_UsingSdk = 4,
  GetAVSDKListS2C_FieldNumber_VecSdkArray = 5,
};

/**
 * 0x00130118
 **/
@interface GetAVSDKListS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

/** 客户端本地的音视频SDK（列表）版本号 */
@property(nonatomic, readwrite) uint32_t cliVer;

/** 服务端的音视频SDK（列表）版本号 */
@property(nonatomic, readwrite) uint32_t version;

/** 当前使用的音视频SDK */
@property(nonatomic, readwrite) uint32_t usingSdk;

/** 当前教室可以使用的音视频SDK列表 */
@property(nonatomic, readwrite, strong, null_resettable) GPBUInt32Array *vecSdkArray;
/** The number of items in @c vecSdkArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecSdkArray_Count;

@end

#pragma mark - AVSDKListNotify

typedef GPB_ENUM(AVSDKListNotify_FieldNumber) {
  AVSDKListNotify_FieldNumber_Version = 1,
  AVSDKListNotify_FieldNumber_UsingSdk = 2,
  AVSDKListNotify_FieldNumber_VecSdkArray = 3,
};

/**
 * 0x00130119
 **/
@interface AVSDKListNotify : GPBMessage

/** 服务端的音视频SDK（列表）版本号 */
@property(nonatomic, readwrite) uint32_t version;

/** 当前使用的音视频SDK */
@property(nonatomic, readwrite) uint32_t usingSdk;

/** 当前教室可以使用的音视频SDK列表 */
@property(nonatomic, readwrite, strong, null_resettable) GPBUInt32Array *vecSdkArray;
/** The number of items in @c vecSdkArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecSdkArray_Count;

@end

#pragma mark - SwitchUsingAVSDKC2S

typedef GPB_ENUM(SwitchUsingAVSDKC2S_FieldNumber) {
  SwitchUsingAVSDKC2S_FieldNumber_NewSdk = 1,
};

/**
 * 0x0013011A
 **/
@interface SwitchUsingAVSDKC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t newSdk;

@end

#pragma mark - SwitchUsingAVSDKS2C

typedef GPB_ENUM(SwitchUsingAVSDKS2C_FieldNumber) {
  SwitchUsingAVSDKS2C_FieldNumber_RspCode = 1,
  SwitchUsingAVSDKS2C_FieldNumber_NewSdk = 2,
};

/**
 * 0x0013011B
 **/
@interface SwitchUsingAVSDKS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t newSdk;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
