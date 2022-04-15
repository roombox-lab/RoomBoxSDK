//
//  RBZFPlayerMediaControl.h
//  RBZFPlayer
//
// Copyright (c) 2016年 任子丰 ( http://github.com/renzifeng )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "RBZFPlayerMediaPlayback.h"
#import "RBZFOrientationObserver.h"
#import "RBZFPlayerGestureControl.h"
#import "RBZFReachabilityManager.h"
@class RBZFPlayerController;

NS_ASSUME_NONNULL_BEGIN

@protocol RBZFPlayerMediaControl <NSObject>

@required
/// Current playerController
@property (nonatomic, weak) RBZFPlayerController *player;

@optional

#pragma mark - Playback state

/// When the player prepare to play the video.
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer prepareToPlay:(NSURL *)assetURL;

/// When th player playback state changed.
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer playStateChanged:(RBZFPlayerPlaybackState)state;

/// When th player loading state changed.
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer loadStateChanged:(RBZFPlayerLoadState)state;

#pragma mark - progress

/**
 When the playback changed.
 
 @param videoPlayer the player.
 @param currentTime the current play time.
 @param totalTime the video total time.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer
        currentTime:(NSTimeInterval)currentTime
          totalTime:(NSTimeInterval)totalTime;

/**
 When buffer progress changed.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer
         bufferTime:(NSTimeInterval)bufferTime;

/**
 When you are dragging to change the video progress.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer
       draggingTime:(NSTimeInterval)seekTime
          totalTime:(NSTimeInterval)totalTime;

/**
 When play end.
 */
- (void)videoPlayerPlayEnd:(RBZFPlayerController *)videoPlayer;

/**
 When play failed.
 */
- (void)videoPlayerPlayFailed:(RBZFPlayerController *)videoPlayer error:(id)error;

#pragma mark - lock screen

/**
 When set `videoPlayer.lockedScreen`.
 */
- (void)lockedVideoPlayer:(RBZFPlayerController *)videoPlayer lockedScreen:(BOOL)locked;

#pragma mark - Screen rotation

/**
 When the fullScreen maode will changed.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer orientationWillChange:(RBZFOrientationObserver *)observer;

/**
 When the fullScreen maode did changed.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer orientationDidChanged:(RBZFOrientationObserver *)observer;

#pragma mark - The network changed

/**
 When the network changed
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer reachabilityChanged:(RBZFReachabilityStatus)status;

#pragma mark - The video size changed

/**
 When the video size changed
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer presentationSizeChanged:(CGSize)size;

#pragma mark - Gesture

/**
 When the gesture condition
 */
- (BOOL)gestureTriggerCondition:(RBZFPlayerGestureControl *)gestureControl
                    gestureType:(RBZFPlayerGestureType)gestureType
              gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
                          touch:(UITouch *)touch;

/**
 When the gesture single tapped
 */
- (void)gestureSingleTapped:(RBZFPlayerGestureControl *)gestureControl;

/**
 When the gesture double tapped
 */
- (void)gestureDoubleTapped:(RBZFPlayerGestureControl *)gestureControl;

/**
 When the gesture begin panGesture
 */
- (void)gestureBeganPan:(RBZFPlayerGestureControl *)gestureControl
           panDirection:(RBZFPanDirection)direction
            panLocation:(RBZFPanLocation)location;

/**
 When the gesture paning
 */
- (void)gestureChangedPan:(RBZFPlayerGestureControl *)gestureControl
             panDirection:(RBZFPanDirection)direction
              panLocation:(RBZFPanLocation)location
             withVelocity:(CGPoint)velocity;

/**
 When the end panGesture
 */
- (void)gestureEndedPan:(RBZFPlayerGestureControl *)gestureControl
           panDirection:(RBZFPanDirection)direction
            panLocation:(RBZFPanLocation)location;

/**
 When the pinchGesture changed
 */
- (void)gesturePinched:(RBZFPlayerGestureControl *)gestureControl
                 scale:(float)scale;

#pragma mark - scrollview

/**
 When the player will appear in scrollView.
 */
- (void)playerWillAppearInScrollView:(RBZFPlayerController *)videoPlayer;

/**
 When the player did appear in scrollView.
 */
- (void)playerDidAppearInScrollView:(RBZFPlayerController *)videoPlayer;

/**
 When the player will disappear in scrollView.
 */
- (void)playerWillDisappearInScrollView:(RBZFPlayerController *)videoPlayer;

/**
 When the player did disappear in scrollView.
 */
- (void)playerDidDisappearInScrollView:(RBZFPlayerController *)videoPlayer;

/**
 When the player appearing in scrollView.
 */
- (void)playerAppearingInScrollView:(RBZFPlayerController *)videoPlayer playerApperaPercent:(CGFloat)playerApperaPercent;

/**
 When the player disappearing in scrollView.
 */
- (void)playerDisappearingInScrollView:(RBZFPlayerController *)videoPlayer playerDisapperaPercent:(CGFloat)playerDisapperaPercent;

/**
 When the small float view show.
 */
- (void)videoPlayer:(RBZFPlayerController *)videoPlayer floatViewShow:(BOOL)show;

@end

NS_ASSUME_NONNULL_END

