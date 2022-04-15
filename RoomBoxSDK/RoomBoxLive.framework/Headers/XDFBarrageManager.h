//
//  XDFBarrageManager.h
//  XDFRoomLoginDemo
//
//  Created by 婉华孙 on 2020/5/12.
//  Copyright © 2020 刘冬冬. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import <BarrageRenderer/BarrageRenderer.h>
//@import BarrageRenderer;
@import RoomBoxUtils;
#import "XDFBarrageInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface XDFBarrageManager : NSObject

@property (nonatomic, strong) RBBarrageRenderer *firstBarrageRenderer;

- (void)receiveBarrageInfoWithModel:(XDFBarrageInfoModel *)model;

- (void)configBarrageInView:(UIView *)view edgeInSet:(UIEdgeInsets)edgeInset;
- (void)configBarrageViewEdgInset:(UIEdgeInsets)edgeInset;

- (void)startBarrage;
- (void)stopBarrage;
- (void)showBarrage;
- (void)hideBarrage;

@end

NS_ASSUME_NONNULL_END
