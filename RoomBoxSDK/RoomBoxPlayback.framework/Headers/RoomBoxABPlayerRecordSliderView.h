//
//  RoomBoxABPlayerPlayRecordProgressBar.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/20.
//

#import <UIKit/UIKit.h>
#import "ABPlayerControlViewSourceProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxABPlayerRecordSliderView : UIView <ABPlayerControlViewSourceProtocol>

@property (nonatomic, strong) UIColor *recordColor;

@end

NS_ASSUME_NONNULL_END
