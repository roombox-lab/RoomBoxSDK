//
//  RBBaseUIConfig.h
//  RoomBoxUtils
//
//  Created by liangyl on 2021/10/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern const NSString *rb_navBar_bar_color;
extern const NSString *rb_navBar_bottomLine_color;
extern const NSString *rb_navBar_titleText_color;

@interface RBBaseUIConfig : NSObject

+(void)setNavBarBarColor:(NSString *)rgbColorStr;

+(void)setNavBarBottomLineColor:(NSString *)rgbColorStr;

+(void)setNavBarTitleTextColor:(NSString *)rgbColorStr;

@end

NS_ASSUME_NONNULL_END
