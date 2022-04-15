//
//  RoomBoxABPlayerControlView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxABPlayerProgressView.h"
#import "RoomBoxABPlayerNavigatorView.h"
#import "ABPlayerControlViewSourceProtocol.h"
@import RoomBoxUtils;
@class RoomBoxPlayerLogUtil;
@class RoomBoxPlayerKnowledgeModel;
@class RoomBoxPlayerVideoConfigModel;
@protocol ABPlayerCoreProtocol;

@interface RoomBoxABPlayerControlView : UIView <ABPlayerControlViewSourceProtocol>

@property (nonatomic, copy) dispatch_block_t onBackBlock;
@property (nonatomic, copy) dispatch_block_t onScreenshotBlock;
@property (nonatomic, copy) void(^onPlayProgressDidUpdateBlock)(CGFloat progress);
@property (nonatomic, assign) BOOL hiddenNavi;
@property (nonatomic, weak) id <ABPlayerCoreProtocol> corePlayer;

- (void)updateAssetTitle:(NSString *)title;
- (void)hideProgressBar:(BOOL)bHidden;
@end
 
