//
//  RBZFOrentationObserver.h
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

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Full screen mode
typedef NS_ENUM(NSUInteger, RBZFFullScreenMode) {
    RBZFFullScreenModeAutomatic,  // Determine full screen mode automatically
    RBZFFullScreenModeLandscape,  // Landscape full screen mode
    RBZFFullScreenModePortrait    // Portrait full screen Model
};

/// Full screen mode on the view
typedef NS_ENUM(NSUInteger, RBZFRotateType) {
    RBZFRotateTypeNormal,         // Normal
    RBZFRotateTypeCell,           // Cell
    RBZFRotateTypeCellOther       // Cell mode add to other view
};

/**
 Rotation of support direction
 */
typedef NS_OPTIONS(NSUInteger, RBZFInterfaceOrientationMask) {
    RBZFInterfaceOrientationMaskPortrait = (1 << 0),
    RBZFInterfaceOrientationMaskLandscapeLeft = (1 << 1),
    RBZFInterfaceOrientationMaskLandscapeRight = (1 << 2),
    RBZFInterfaceOrientationMaskPortraitUpsideDown = (1 << 3),
    RBZFInterfaceOrientationMaskLandscape = (RBZFInterfaceOrientationMaskLandscapeLeft | RBZFInterfaceOrientationMaskLandscapeRight),
    RBZFInterfaceOrientationMaskAll = (RBZFInterfaceOrientationMaskPortrait | RBZFInterfaceOrientationMaskLandscapeLeft | RBZFInterfaceOrientationMaskLandscapeRight | RBZFInterfaceOrientationMaskPortraitUpsideDown),
    RBZFInterfaceOrientationMaskAllButUpsideDown = (RBZFInterfaceOrientationMaskPortrait | RBZFInterfaceOrientationMaskLandscapeLeft | RBZFInterfaceOrientationMaskLandscapeRight),
};

@interface RBZFOrientationObserver : NSObject

- (void)updateRotateView:(UIView *)rotateView
           containerView:(UIView *)containerView;

/// list play
- (void)cellModelRotateView:(UIView *)rotateView
           rotateViewAtCell:(UIView *)cell
              playerViewTag:(NSInteger)playerViewTag;

/// cell other view rotation
- (void)cellOtherModelRotateView:(UIView *)rotateView
                   containerView:(UIView *)containerView;

/// Container view of a full screen state player.
@property (nonatomic, strong) UIView *fullScreenContainerView;

/// Container view of a small screen state player.
@property (nonatomic, weak) UIView *containerView;

/// If the full screen.
@property (nonatomic, readonly, getter=isFullScreen) BOOL fullScreen;

/// Use device orientation, default NO.
@property (nonatomic, assign) BOOL forceDeviceOrientation;

/// Lock screen orientation
@property (nonatomic, getter=isLockedScreen) BOOL lockedScreen;

/// The block invoked When player will rotate.
@property (nonatomic, copy, nullable) void(^orientationWillChange)(RBZFOrientationObserver *observer, BOOL isFullScreen);

/// The block invoked when player rotated.
@property (nonatomic, copy, nullable) void(^orientationDidChanged)(RBZFOrientationObserver *observer, BOOL isFullScreen);

/// Full screen mode, the default landscape into full screen
@property (nonatomic) RBZFFullScreenMode fullScreenMode;

/// rotate duration, default is 0.30
@property (nonatomic) float duration;

/// The statusbar hidden.
@property (nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden;

/// The current orientation of the player.
/// Default is UIInterfaceOrientationPortrait.
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;

/// Whether allow the video orientation rotate.
/// default is YES.
@property (nonatomic) BOOL allowOrentitaionRotation;

/// The support Interface Orientation,default is RBZFInterfaceOrientationMaskAllButUpsideDown
@property (nonatomic, assign) RBZFInterfaceOrientationMask supportInterfaceOrientation;

/// Add the device orientation observer.
- (void)addDeviceOrientationObserver;

/// Remove the device orientation observer.
- (void)removeDeviceOrientationObserver;

/// Enter the fullScreen while the RBZFFullScreenMode is RBZFFullScreenModeLandscape.
- (void)enterLandscapeFullScreen:(UIInterfaceOrientation)orientation animated:(BOOL)animated;

/// Enter the fullScreen while the RBZFFullScreenMode is RBZFFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

- (void)exitFullScreenWithAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END


