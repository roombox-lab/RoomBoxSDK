//
//  NSGNetView.h
//  GNetTangSDK
//
//  Created by xiaoyu on 2021/1/19.
//  Copyright © 2021 Loren Zhai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "GNetPropertiesDefine.h"

typedef void(^BackgroundSizeChangedBlock)(NSUInteger uWidth,NSUInteger uHeight);
typedef void(^BackgroundFrameChangedBlock)(CGRect rect);

@interface NSGNetView : GLKView

@property (nonatomic,assign)CGFloat transitionFactor; //平移系数 用来调节平移的快慢程度
@property (nonatomic,assign)NSWhiteBoardHandleMode handleMode; //默认观看模式

@property(nonatomic,copy)BackgroundSizeChangedBlock backgroundSizeChangedBlock;
@property(nonatomic,copy)BackgroundFrameChangedBlock backgroundFrameChangedBlock;

//重写初始化方法，renderEnable：是否初始化openGL
-(id)initWithRenderViewFrame:(CGRect)frame renderEnable:(BOOL)renderEnable;

- (id)initWithIndependentRenderViewFrame:(CGRect)frame;

-(void)setPluginRenderMgr:(void*)renderMgr;

-(void)activePage:(NSUInteger)uPageID;

-(void)setCurrentMode:(NSWhiteBoardHandleMode)handleMode;

-(void)RefreshViewSize;//刷新view 宽高

-(void)SetStretchMode:(NSStretchMode)type;

-(void)ScaleView:(NSUInteger)nFocusX nFocusY:(NSUInteger)nFocusY fScale:(float)fScale;

-(void)SetBackgroundColor:(NSUInteger)uBgColor;

-(void)SetBackgroundColor:(NSUInteger)uBgColor refreshWhenRender:(BOOL)refreshWhenRender;

-(void)TransitionWithXValue:(NSUInteger)nDx andYValue:(NSUInteger)nDy;

-(void) IndependentRenderBackgroud:(const uint8_t *)pBuffer uBufSize:(uint32_t)uBufSize uWidth:(uint32_t)uWidth uHeight:(uint32_t)uHeight;
@end
