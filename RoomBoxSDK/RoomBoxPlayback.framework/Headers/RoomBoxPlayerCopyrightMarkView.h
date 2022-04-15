//
//  RoomBoxPlayerCopyrightMarkView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/10/15.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerCopyrightMarkView : UIView

- (void)configMarkText:(NSString *)markText;

- (void)onActive;
- (void)onDestory;

@end

NS_ASSUME_NONNULL_END
