//
//  RoomBoxPlayerUtil.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RoomBoxPlayerImage.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef RoomBoxPlayerUtil_MACRO
#define RoomBoxPlayerUtil_MACRO
#define UIColorFromHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define UIColorFromHexA(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]
#define RoomBoxPlayerImage(imageName) [RoomBoxPlayerImage playerImageNamed:imageName]
#endif

@interface RoomBoxPlayerUtil : NSObject

+ (BOOL)isIphoneX;
+ (BOOL)isSmallIphone;
+ (UIEdgeInsets)iPhoneXSafeArea;
+ (NSString *)formattedTimeString:(NSTimeInterval)time;
+ (BOOL)isRoomBoxMainApp;
@end

NS_ASSUME_NONNULL_END
