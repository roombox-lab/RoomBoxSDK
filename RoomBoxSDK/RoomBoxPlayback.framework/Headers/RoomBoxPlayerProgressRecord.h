//
//  RoomBoxPlayerProgressRecord.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/16.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerProgressRecordDelegate <NSObject>

@optional
- (void)drawablePathDidUpdate;
- (void)playProgressDidUpdate:(CGFloat)progress;
- (void)playRecordDidUpdate:(NSArray *)records;

@end

@interface RoomBoxPlayerProgressRecord : NSObject

@property (nonatomic, weak) id<RoomBoxPlayerProgressRecordDelegate> delegate;

@property (nonatomic, assign) NSTimeInterval totalTime;
@property (nonatomic, assign) CGFloat barWidth;

@property (nonatomic, strong, readonly) NSMutableDictionary *timeDict;
@property (nonatomic, strong, readonly) NSMutableDictionary *pixelPathDict;

@property (nonatomic, copy) NSString *cid;

- (void)reloadDrawablePathWithTime:(NSTimeInterval)time;
- (void)reloadAllDrawablePaths;
- (void)recordBySecond:(NSInteger)second;
// isHistory代表是否是从服务端下发的历史记录 历史记录是不写到上报数据的
- (void)recordBySecond:(NSInteger)second isHistory:(BOOL)isHistory;

- (NSInteger)totalSeconds;
- (CGFloat)totalProgress;

- (void)uploadImmediately;
- (void)onDestory;

@end

NS_ASSUME_NONNULL_END
