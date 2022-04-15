//
//  RoomBoxPlayerProgressView.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxSliderView.h"
#import "RoomBoxPlayerAirplayBaseManager.h"
#import "RoomBoxPlayerProgressBar.h"
#import "RoomBoxPlayerSurfingBar.h"
@import RoomBoxUtils;
@class RoomBoxPlayerLogUtil;

@protocol RoomBoxPlayerProgressViewDelegate <NSObject>

@optional
- (void)playerProgressViewOnTapped;
- (void)playerProgressViewOnPlayOrPause;
- (void)playerProgressViewOnSeekForward;
- (void)playerProgressViewOnSeekBackward;
- (void)playerProgressViewSliderSeekToTime:(double)time;
- (void)playerProgressViewSliderTouchEnded;
- (void)playerProgressViewSliderTapped;
- (void)playerProgressViewSlidersTouchBegan;

- (void)playerProgressViewOnChangeSpeed;
- (void)playerProgressViewOnOpenKnowledge;
- (void)playerProgressViewOnOpenChat:(id)sender;
- (void)playerProgressViewOnExitSurfing;

- (void)playerProgressViewOnSelectKnowledges:(NSArray *)dataArray selectedIndex:(NSInteger)selectedIndex targetView:(UIView *)targetView;
- (void)playerProgressViewOnUpdatePlayProgress:(CGFloat)progress;
- (void)playerProgressViewOnUpdatePlayRecord:(NSArray *)records;

@end

typedef void(^VoidBlock)(void);

@interface RoomBoxPlayerProgressView : UIView

@property (nonatomic, weak) id<RBZFPlayerMediaPlayback> player;
@property (nonatomic, weak) id<RoomBoxPlayerProgressViewDelegate> delegate;
@property (nonatomic, weak) RoomBoxPlayerLogUtil *logger;
@property (nonatomic, strong, readonly) UIButton *playButton;
@property (nonatomic, strong, readonly) UILabel *currentTimeLabel;
@property (nonatomic, strong, readonly) UILabel *totalTimeLabel;
@property (nonatomic, strong, readonly) RoomBoxSliderView *slider;
@property (nonatomic, strong, readonly) RoomBoxPlayerProgressBar *sliderBar;
@property (nonatomic, strong, readonly) RoomBoxPlayerSurfingBar *surfingBar;

@property (nonatomic, strong, readonly) UIButton *speedButton;
@property (nonatomic, strong, readonly) UIButton *knowledgeButton;
@property (nonatomic, strong, readonly) UIButton *chatButton;

@property (nonatomic, weak) RoomBoxPlayerAirplayBaseManager *airplayMgr;
//回退5s
@property (nonatomic, copy) VoidBlock backwardBlock;

+ (CGFloat)defaultHeight;
- (void)resetView;
- (void)updateSpeedValue:(NSString *)speedValue;
- (void)updateSliderValue:(float)value;
- (void)sliderSelectStatusChange:(BOOL)select;

- (void)updateAirplayStatus:(BOOL)airplay;
- (void)updateSurfingStatus:(BOOL)surfing;
- (void)updateSurfingContents:(NSString *)content;

- (void)updateRecordHistory:(NSArray<NSArray *> *)records;

- (void)updateUIWithNewNoteExist;

@end
