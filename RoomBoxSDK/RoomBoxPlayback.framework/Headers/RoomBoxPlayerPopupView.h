//
//  RoomBoxPlayerPopupView.h
//  RoomBoxPlayer
//
//  Created by 陈浩浩 on 2020/11/13.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    RoomBoxPlayerPopupViewDirectionTop,
    RoomBoxPlayerPopupViewDirectionBottom,
} RoomBoxPlayerPopupViewDirection;



@interface RoomBoxPlayerPopupView : UIView

@property (nonatomic, assign) CGSize contentSize;
@property (nonatomic, assign) CGFloat padding;

- (instancetype)initWithContentSize:(CGSize)size;

- (void)popupWithDirection:(RoomBoxPlayerPopupViewDirection)direction
                targetView:(UIView *)targetView
             containerView:(UIView *)containerView;

@end

NS_ASSUME_NONNULL_END
