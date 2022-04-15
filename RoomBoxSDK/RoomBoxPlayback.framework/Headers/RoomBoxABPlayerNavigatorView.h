//
//  RoomBoxABPlayerNavigatorView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RoomBoxABPlayerNavigatorViewDelegate <NSObject>

@optional
- (void)playerNavigatorViewOnTapped;
- (void)playerNavigatorViewOnBack;
- (void)playerNavigatorViewMoreButtonTapped;
- (void)playerNavigatorViewOnAirplaySelect;
- (void)playerNavigatorViewOnAirplayDisconnect;

@end

@interface RoomBoxABPlayerNavigatorView : UIView

@property (nonatomic, weak) id<RoomBoxABPlayerNavigatorViewDelegate> delegate;

@property (nonatomic, strong, readonly) UILabel *titleLabel;

+ (CGFloat)defaultHeight;

@end
