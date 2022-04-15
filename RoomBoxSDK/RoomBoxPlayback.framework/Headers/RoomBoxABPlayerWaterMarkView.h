//
//  RoomBoxABPlayerWaterMarkView.h
//  RoomBoxABPlayer
//
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxABPlayerWaterMarkView : UIView

- (void)configMarkText:(NSString *)markText;

- (void)onActive;
- (void)onDestory;

@end

NS_ASSUME_NONNULL_END
