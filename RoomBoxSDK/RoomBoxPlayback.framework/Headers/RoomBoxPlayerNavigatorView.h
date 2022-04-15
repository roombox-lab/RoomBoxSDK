//
//  RoomBoxPlayerNavigatorView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RoomBoxPlayerNavigatorViewDelegate <NSObject>

@optional
- (void)playerNavigatorViewOnTapped;
- (void)playerNavigatorViewOnBack;
- (void)playerNavigatorViewOnAirplaySelect;
- (void)playerNavigatorViewOnAirplayDisconnect;

@end

@interface RoomBoxPlayerNavigatorView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerNavigatorViewDelegate> delegate;

@property (nonatomic, strong, readonly) UILabel *titleLabel;

@property (nonatomic, strong) UIButton *airplayButton;

+ (CGFloat)defaultHeight;

- (void)updateAirplayStatus:(BOOL)airplay;

@end
