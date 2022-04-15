//
//  RBCustomNavigationBar.h
//  RBBaseFoundation
//
//  Created by 婉华孙 on 2020/9/2.
//  Copyright © 2020 RB.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RBCustomNavigationBar : UIView

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIColor *titleTextColor;
@property (nonatomic, strong) UIFont *titleTextFont;
@property (nonatomic, strong) UIColor *barBackgroundColor;
@property (nonatomic, strong) UIImage *barBackgroundImage;
@property (nonatomic, copy,setter=setMoreLeftButtons:) NSArray <UIButton *> *moreLeftButtons; // 多个左按钮
@property (nonatomic, copy,setter=setMoreRightButtons:) NSArray <UIButton *> *moreRightButtons;
@property (nonatomic, assign) CGFloat offsetY; // 纵坐标偏移
@property (nonatomic, strong) UIButton *defaultLeftButton;
@property (nonatomic, strong) UIView *bottomLine;

+ (instancetype)customNavigationInstance;

- (void)setClearStyle;
- (void)setDefaultStyle;
- (void)setDefaultLeftButtonHidden:(BOOL)hidden;
- (void)setBottomLineHidden:(BOOL)hidden;
- (void)setBackgroundAlpha:(CGFloat)alpha;
- (void)setTintColor:(UIColor *)color;
- (void)setNavigationCustomLeftButton:(UIButton*)button; // 自定义导航左边按钮
- (void)setNavigationCustomRightButton:(UIButton*)button; // 自定义导航右边按钮
//- (void)setMoreLeftButtons:(NSArray<UIButton *> *)moreLeftButtons;
//- (void)setMoreRightButtons:(NSArray<UIButton *> *)moreRightButtons;
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;
@end

NS_ASSUME_NONNULL_END
