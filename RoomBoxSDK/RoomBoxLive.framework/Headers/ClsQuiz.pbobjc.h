// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClsQuiz.proto

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

@class ClsQuizOption;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ClsQuizRoot

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
@interface ClsQuizRoot : GPBRootObject
@end

#pragma mark - ClsQuizOption

typedef GPB_ENUM(ClsQuizOption_FieldNumber) {
  ClsQuizOption_FieldNumber_Id_p = 1,
  ClsQuizOption_FieldNumber_Text = 2,
};

@interface ClsQuizOption : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *id_p;

@property(nonatomic, readwrite, copy, null_resettable) NSString *text;

@end

#pragma mark - ClsStartQuizC2S

typedef GPB_ENUM(ClsStartQuizC2S_FieldNumber) {
  ClsStartQuizC2S_FieldNumber_QuizSeq = 1,
  ClsStartQuizC2S_FieldNumber_Content = 2,
  ClsStartQuizC2S_FieldNumber_VecOptionArray = 3,
  ClsStartQuizC2S_FieldNumber_VecAnwserArray = 4,
  ClsStartQuizC2S_FieldNumber_AwardCoins = 5,
};

/**
 * 0x001300E0 开始答题  请求
 **/
@interface ClsStartQuizC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t quizSeq;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

/** ClsQuizOption */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ClsQuizOption*> *vecOptionArray;
/** The number of items in @c vecOptionArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecOptionArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecAnwserArray;
/** The number of items in @c vecAnwserArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecAnwserArray_Count;

@property(nonatomic, readwrite) int32_t awardCoins;

@end

#pragma mark - ClsStartQuizS2C

typedef GPB_ENUM(ClsStartQuizS2C_FieldNumber) {
  ClsStartQuizS2C_FieldNumber_RspCode = 1,
  ClsStartQuizS2C_FieldNumber_QuizSeq = 2,
  ClsStartQuizS2C_FieldNumber_QuizId = 3,
  ClsStartQuizS2C_FieldNumber_UserNum = 4,
  ClsStartQuizS2C_FieldNumber_StartStamp = 5,
};

/**
 * 0x001300E1 开始答题响应
 **/
@interface ClsStartQuizS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t quizSeq;

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite) uint32_t userNum;

@property(nonatomic, readwrite) int64_t startStamp;

@end

#pragma mark - ClsStartQuizNotify

typedef GPB_ENUM(ClsStartQuizNotify_FieldNumber) {
  ClsStartQuizNotify_FieldNumber_QuizId = 1,
  ClsStartQuizNotify_FieldNumber_Content = 2,
  ClsStartQuizNotify_FieldNumber_VecOptionArray = 3,
  ClsStartQuizNotify_FieldNumber_VecAnwserArray = 4,
  ClsStartQuizNotify_FieldNumber_AwardCoins = 5,
  ClsStartQuizNotify_FieldNumber_Uid = 6,
  ClsStartQuizNotify_FieldNumber_StartStamp = 7,
};

/**
 * 0x001300E2 开始答题通知
 **/
@interface ClsStartQuizNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ClsQuizOption*> *vecOptionArray;
/** The number of items in @c vecOptionArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecOptionArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecAnwserArray;
/** The number of items in @c vecAnwserArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecAnwserArray_Count;

@property(nonatomic, readwrite) int32_t awardCoins;

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) int64_t startStamp;

@end

#pragma mark - ClsStopQuizC2S

typedef GPB_ENUM(ClsStopQuizC2S_FieldNumber) {
  ClsStopQuizC2S_FieldNumber_QuizId = 1,
};

/**
 * 0x001300E3  结束答题请求
 **/
@interface ClsStopQuizC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@end

#pragma mark - ClsStopQuizS2C

typedef GPB_ENUM(ClsStopQuizS2C_FieldNumber) {
  ClsStopQuizS2C_FieldNumber_RspCode = 1,
  ClsStopQuizS2C_FieldNumber_QuizId = 2,
};

/**
 * 0x001300E4 结束答题响应
 **/
@interface ClsStopQuizS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t quizId;

@end

#pragma mark - ClsStopQuizNotify

typedef GPB_ENUM(ClsStopQuizNotify_FieldNumber) {
  ClsStopQuizNotify_FieldNumber_QuizId = 1,
  ClsStopQuizNotify_FieldNumber_Uid = 2,
};

/**
 * 0x001300E5 结束答题通知
 **/
@interface ClsStopQuizNotify : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite) uint64_t uid;

@end

#pragma mark - ClsSubmitQuizAnswerC2S

typedef GPB_ENUM(ClsSubmitQuizAnswerC2S_FieldNumber) {
  ClsSubmitQuizAnswerC2S_FieldNumber_QuizId = 1,
  ClsSubmitQuizAnswerC2S_FieldNumber_VecAnwserArray = 2,
};

/**
 * 0x001300E6 提交答案请求
 **/
@interface ClsSubmitQuizAnswerC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecAnwserArray;
/** The number of items in @c vecAnwserArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecAnwserArray_Count;

@end

#pragma mark - ClsSubmitQuizAnswerS2C

typedef GPB_ENUM(ClsSubmitQuizAnswerS2C_FieldNumber) {
  ClsSubmitQuizAnswerS2C_FieldNumber_RspCode = 1,
  ClsSubmitQuizAnswerS2C_FieldNumber_QuizId = 2,
  ClsSubmitQuizAnswerS2C_FieldNumber_SubmitStamp = 3,
  ClsSubmitQuizAnswerS2C_FieldNumber_AwardCoins = 4,
  ClsSubmitQuizAnswerS2C_FieldNumber_TotalCoins = 5,
};

/**
 * 0x001300E7 提交答案应答
 **/
@interface ClsSubmitQuizAnswerS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite) int64_t submitStamp;

@property(nonatomic, readwrite) int32_t awardCoins;

@property(nonatomic, readwrite) int32_t totalCoins;

@end

#pragma mark - ClsQuizAnswerNotify

typedef GPB_ENUM(ClsQuizAnswerNotify_FieldNumber) {
  ClsQuizAnswerNotify_FieldNumber_Uid = 1,
  ClsQuizAnswerNotify_FieldNumber_VecAnwserArray = 2,
  ClsQuizAnswerNotify_FieldNumber_SubmitStamp = 3,
};

/**
 * 0x001300E8 提交答案通知
 **/
@interface ClsQuizAnswerNotify : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *vecAnwserArray;
/** The number of items in @c vecAnwserArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger vecAnwserArray_Count;

@property(nonatomic, readwrite) int64_t submitStamp;

@end

#pragma mark - ClsGiveALikeC2S

typedef GPB_ENUM(ClsGiveALikeC2S_FieldNumber) {
  ClsGiveALikeC2S_FieldNumber_QuizId = 1,
  ClsGiveALikeC2S_FieldNumber_Uid = 2,
};

/**
 * 0x001300E9 答题点赞请求
 **/
@interface ClsGiveALikeC2S : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@property(nonatomic, readwrite) uint64_t uid;

@end

#pragma mark - ClsGiveALikeS2C

typedef GPB_ENUM(ClsGiveALikeS2C_FieldNumber) {
  ClsGiveALikeS2C_FieldNumber_RspCode = 1,
  ClsGiveALikeS2C_FieldNumber_Uid = 2,
  ClsGiveALikeS2C_FieldNumber_QuizId = 3,
};

/**
 * 0x001300EA  答题点赞响应
 **/
@interface ClsGiveALikeS2C : GPBMessage

@property(nonatomic, readwrite) uint32_t rspCode;

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) uint32_t quizId;

@end

#pragma mark - ClsGiveALikeNotify

typedef GPB_ENUM(ClsGiveALikeNotify_FieldNumber) {
  ClsGiveALikeNotify_FieldNumber_TeaUid = 1,
  ClsGiveALikeNotify_FieldNumber_StuUid = 2,
  ClsGiveALikeNotify_FieldNumber_QuizId = 3,
};

/**
 * 0x001300EB 答题点赞通知
 **/
@interface ClsGiveALikeNotify : GPBMessage

@property(nonatomic, readwrite) uint64_t teaUid;

@property(nonatomic, readwrite) uint64_t stuUid;

@property(nonatomic, readwrite) uint32_t quizId;

@end

#pragma mark - ClsRecvQuizACK

typedef GPB_ENUM(ClsRecvQuizACK_FieldNumber) {
  ClsRecvQuizACK_FieldNumber_QuizId = 1,
};

/**
 * 0x001300EC 答题卡收到确认
 **/
@interface ClsRecvQuizACK : GPBMessage

@property(nonatomic, readwrite) uint32_t quizId;

@end

#pragma mark - ClsGiveUpQuizNotify

typedef GPB_ENUM(ClsGiveUpQuizNotify_FieldNumber) {
  ClsGiveUpQuizNotify_FieldNumber_Uid = 1,
  ClsGiveUpQuizNotify_FieldNumber_QuizId = 2,
};

/**
 * 0x001300ED 放弃答题通知 服务端广播 客户端只需要收通知处理就行
 **/
@interface ClsGiveUpQuizNotify : GPBMessage

@property(nonatomic, readwrite) uint64_t uid;

@property(nonatomic, readwrite) uint32_t quizId;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
