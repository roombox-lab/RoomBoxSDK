//
//  RoomBoxRecordKnowledgeModel.h
//  RoomBoxPlayback
//
//  Created by 逯常松 on 2021/7/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxRecordKnowledgeModel : NSObject

@property(nonatomic, assign) NSTimeInterval startTime; //开始的时间（s）
@property(nonatomic, copy) NSString *questionURL; //知识点地址
@property(nonatomic, copy) NSString *studyUrl; //知识点地址


+ (NSArray<RoomBoxRecordKnowledgeModel *> *)noteListTransformFromJsonArray:(NSArray *)array;
+ (RoomBoxRecordKnowledgeModel *)noteTransformFromDic:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END
