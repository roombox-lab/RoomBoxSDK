//
//  RoomBoxPlayerImage.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerImage : NSObject

+ (UIImage *)playerImageNamed:(NSString *)imageName;
+ (NSBundle *)roomboxBundle;
@end

NS_ASSUME_NONNULL_END
