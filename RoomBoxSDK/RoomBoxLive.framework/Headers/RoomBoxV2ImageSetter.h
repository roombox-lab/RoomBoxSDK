//
//  RoomBoxV2ImageSetter.h
//  RoomBoxSDK
//
//  Created by Joey on 2021/7/1.
//  Copyright © 2021 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxV2ImageSetter : NSObject

// 修改图片饱和度
+ (UIImage *)changeImageSaturation:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
