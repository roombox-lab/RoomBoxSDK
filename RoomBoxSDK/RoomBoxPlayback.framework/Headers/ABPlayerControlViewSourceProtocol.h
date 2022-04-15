//
//  ABPlayerControlViewSourceProtocol.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/14.
//

#import <Foundation/Foundation.h>
#import "ABPlayerControlViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 单个播放记录
@protocol ABPlayerControlViewSinglePlayRecord <NSObject>
@property (nonatomic, assign) double startPersent;
@property (nonatomic, assign) double endPersent;
@end

/// 播放器进度条 播放记录协议
@protocol ABPlayerControlViewSourceProtocol <ABPlayerControlViewProtocol>

/// 更新播放记录展示 内部会重新绘制UI
/// @param playRecord 播放记录
- (void)updateControlViewWithPlayRecords:(NSArray <id<ABPlayerControlViewSinglePlayRecord>> *)playRecords;

@end

NS_ASSUME_NONNULL_END
