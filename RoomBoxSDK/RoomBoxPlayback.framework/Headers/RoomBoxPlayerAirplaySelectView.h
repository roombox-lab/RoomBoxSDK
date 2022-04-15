//
//  RoomBoxPlayerAirplaySelectView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/9/4.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerAirplaySelectViewDelegate <NSObject>

@optional
- (void)airplaySelectViewOnClose;
- (void)airplaySelectViewOnSelectService:(id)service;

@end

@interface RoomBoxPlayerAirplaySelectView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerAirplaySelectViewDelegate> delegate;

- (void)loadServices:(NSArray *)services;

@end

NS_ASSUME_NONNULL_END
