//
//  RoomBoxPlayerKnowledgeModel.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/10.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RoomBoxPlayerKnowledgeDataModel;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    RoomBoxPlayerKnowledgeTypeNormal, //普通的知识点
    RoomBoxPlayerKnowledgeTypeKey, //重点标记
    RoomBoxPlayerKnowledgeTypeDifficulty, //难点标记
} RoomBoxPlayerKnowledgeType;

typedef enum : NSUInteger {
    RoomBoxPlayerKnowledgeRoleTypeStu, //学生知识点
    RoomBoxPlayerKnowledgeRoleTypeTea, //老师知识点
} RoomBoxPlayerKnowledgeRoleType;


@interface RoomBoxPlayerKnowledgeModel : NSObject

@property(nonatomic, copy) NSString *noteId; //知识点id
@property(nonatomic, assign) RoomBoxPlayerKnowledgeType type; //知识点类型
@property(nonatomic, assign) RoomBoxPlayerKnowledgeRoleType roleType; //区分老师和学生知识点
@property(nonatomic, assign) NSTimeInterval beginTime; //开始的时间（s）
@property(nonatomic, assign) NSTimeInterval endTime; //结束的时间 (s)
@property(nonatomic, assign) BOOL deleteAble; //是否可以删除
@property(nonatomic, copy) NSString *content; //知识点内容

@property(nonatomic, assign) BOOL isDeleting; //正在删除

- (NSString *)timeStringValue;
- (NSString *)timestampIdentifier:(BOOL)begin;

+ (NSArray<RoomBoxPlayerKnowledgeModel *> *)transformFromNoteList:(NSArray<RoomBoxPlayerKnowledgeDataModel *> *)array;


@end

//接口中返回的知识点模型
@interface RoomBoxPlayerKnowledgeDataModel: NSObject

@property(nonatomic, copy) NSString *noteId; //知识点id
@property(nonatomic, copy) NSString *note; //知识点内容
@property(nonatomic, assign) NSTimeInterval startTime; //开始的时间（s）
@property(nonatomic, assign) NSTimeInterval endTime; //结束的时间 (s)
@property(nonatomic, assign) NSInteger type; //知识点类型 知识点1  备注2
@property(nonatomic, assign) NSInteger remarkType; //type为2时，1划重点，2有点难

//转换成自定义的知识点模型
- (RoomBoxPlayerKnowledgeModel *)transformToKnowledgeModel;

+ (NSArray<RoomBoxPlayerKnowledgeDataModel *> *)noteListTransformFromJsonArray:(NSArray *)array;
+ (RoomBoxPlayerKnowledgeDataModel *)noteTransformFromDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
