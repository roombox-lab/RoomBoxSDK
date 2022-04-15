//
//  RBSVGAContentLayer.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 2017/2/22.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RBSVGAPlayer.h"

@class RBSVGABitmapLayer, RBSVGAVectorLayer, RBSVGAVideoSpriteFrameEntity;

@interface RBSVGAContentLayer : CALayer

@property (nonatomic, strong) NSString *imageKey;
@property (nonatomic, assign) BOOL dynamicHidden;
@property (nonatomic, copy) RBSVGAPlayerDynamicDrawingBlock dynamicDrawingBlock;
@property (nonatomic, strong) RBSVGABitmapLayer *bitmapLayer;
@property (nonatomic, strong) RBSVGAVectorLayer *vectorLayer;
@property (nonatomic, strong) CATextLayer *textLayer;

- (instancetype)initWithFrames:(NSArray<RBSVGAVideoSpriteFrameEntity *> *)frames;

- (void)stepToFrame:(NSInteger)frame;
- (void)resetTextLayerProperties:(NSAttributedString *)attributedString;

@end
