//
//  RoomBoxPlayerSacQuizModel.h
//  RoomBoxPlayback
//
//  Created by 逯常松 on 2021/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerSacQuizModel : NSObject

@property(nonatomic, assign) NSTimeInterval sendTime; //开始的时间（s）

@property (nonatomic, copy) NSString *quizSeq; // 答题卡系列号

@property (nonatomic, copy) NSString *quizId; // 答题卡id

@property (nonatomic, copy) NSString *cid; // 教室cid

+ (NSArray<RoomBoxPlayerSacQuizModel *> *)sacQuizListTransformFromJsonArray:(NSArray *)array;
+ (RoomBoxPlayerSacQuizModel *)sacQuizTransformFromDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
