//
//  UIImage+RoomBox.h
//  RoomBoxUtils
//
//  Created by 赵亮 on 2021/1/29.
//  Copyright © 2021 xdf.cn. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (RoomBox)

- (nullable UIImage *)rbImageByBlurRadius:(CGFloat)blurRadius
                              tintColor:(nullable UIColor *)tintColor
                               tintMode:(CGBlendMode)tintBlendMode
                             saturation:(CGFloat)saturation
                              maskImage:(nullable UIImage *)maskImage;

@end

NS_ASSUME_NONNULL_END
