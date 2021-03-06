//
//  RBSVGAPlayer.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 16/6/17.
//  Copyright © 2016年 UED Center. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RBSVGAVideoEntity, RBSVGAPlayer;

@protocol RBSVGAPlayerDelegate <NSObject>

@optional
- (void)svgaPlayerDidFinishedAnimation:(RBSVGAPlayer *)player;
- (void)svgaPlayerDidAnimatedToFrame:(NSInteger)frame;
- (void)svgaPlayerDidAnimatedToPercentage:(CGFloat)percentage;

@end

typedef void(^RBSVGAPlayerDynamicDrawingBlock)(CALayer *contentLayer, NSInteger frameIndex);

@interface RBSVGAPlayer : UIView

@property (nonatomic, weak) id<RBSVGAPlayerDelegate> delegate;
@property (nonatomic, strong) RBSVGAVideoEntity *videoItem;
@property (nonatomic, assign) IBInspectable int loops;
@property (nonatomic, assign) IBInspectable BOOL clearsAfterStop;
@property (nonatomic, copy) NSString *fillMode;
@property (nonatomic, copy) NSRunLoopMode mainRunLoopMode;

- (void)startAnimation;
- (void)startAnimationWithRange:(NSRange)range reverse:(BOOL)reverse;
- (void)pauseAnimation;
- (void)stopAnimation;
- (void)clear;
- (void)stepToFrame:(NSInteger)frame andPlay:(BOOL)andPlay;
- (void)stepToPercentage:(CGFloat)percentage andPlay:(BOOL)andPlay;

#pragma mark - Dynamic Object

- (void)setImage:(UIImage *)image forKey:(NSString *)aKey;
- (void)setImageWithURL:(NSURL *)URL forKey:(NSString *)aKey;
- (void)setImage:(UIImage *)image forKey:(NSString *)aKey referenceLayer:(CALayer *)referenceLayer; // deprecated from 2.0.1
- (void)setAttributedText:(NSAttributedString *)attributedText forKey:(NSString *)aKey;
- (void)setDrawingBlock:(RBSVGAPlayerDynamicDrawingBlock)drawingBlock forKey:(NSString *)aKey;
- (void)setHidden:(BOOL)hidden forKey:(NSString *)aKey;
- (void)clearDynamicObjects;

@end
