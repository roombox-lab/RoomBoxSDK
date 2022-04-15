//
//  RBBaseViewController.h
//  RBBaseFoundation
//
//  Created by 刘冬冬 on 2019/10/18.
//  Copyright © 2019 RB.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RBCustomNavigationBar.h"
#import "RBBaseUIConfig.h"


NS_ASSUME_NONNULL_BEGIN

@interface RBBaseViewController : UIViewController

@property (nonatomic, strong) RBCustomNavigationBar *customNavigationBar;

/// 是否要展示 弹窗《放弃》《继续编辑》
/// 默认 NO
//@property (nonatomic, assign) BOOL canShowAlert;
- (void)clickLeftAction;
- (void)removeDefaultButtonTargetAction;
- (BOOL)rbEnableInteractivePopGestureRecognizer;
@end

NS_ASSUME_NONNULL_END
