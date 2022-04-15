//
//  RBSVGAVectorLayer.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 2017/2/20.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

@class RBSVGAVideoSpriteFrameEntity;

@interface RBSVGAVectorLayer : CALayer

- (instancetype)initWithFrames:(NSArray<RBSVGAVideoSpriteFrameEntity *> *)frames;

- (void)stepToFrame:(NSInteger)frame;

@end
