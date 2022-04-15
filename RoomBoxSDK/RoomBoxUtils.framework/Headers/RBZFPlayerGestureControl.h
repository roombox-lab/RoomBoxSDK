//
//  RBZFPlayerGestureControl.h
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

typedef NS_ENUM(NSUInteger, RBZFPlayerGestureType) {
    RBZFPlayerGestureTypeUnknown,
    RBZFPlayerGestureTypeSingleTap,
    RBZFPlayerGestureTypeDoubleTap,
    RBZFPlayerGestureTypePan,
    RBZFPlayerGestureTypePinch
};

typedef NS_ENUM(NSUInteger, RBZFPanDirection) {
    RBZFPanDirectionUnknown,
    RBZFPanDirectionV,
    RBZFPanDirectionH,
};

typedef NS_ENUM(NSUInteger, RBZFPanLocation) {
    RBZFPanLocationUnknown,
    RBZFPanLocationLeft,
    RBZFPanLocationRight,
};

typedef NS_ENUM(NSUInteger, RBZFPanMovingDirection) {
    RBZFPanMovingDirectionUnkown,
    RBZFPanMovingDirectionTop,
    RBZFPanMovingDirectionLeft,
    RBZFPanMovingDirectionBottom,
    RBZFPanMovingDirectionRight,
};

/// This enumeration lists some of the gesture types that the player has by default.
typedef NS_OPTIONS(NSUInteger, RBZFPlayerDisableGestureTypes) {
    RBZFPlayerDisableGestureTypesNone         = 0,
    RBZFPlayerDisableGestureTypesSingleTap    = 1 << 0,
    RBZFPlayerDisableGestureTypesDoubleTap    = 1 << 1,
    RBZFPlayerDisableGestureTypesPan          = 1 << 2,
    RBZFPlayerDisableGestureTypesPinch        = 1 << 3,
    RBZFPlayerDisableGestureTypesAll          = (RBZFPlayerDisableGestureTypesSingleTap | RBZFPlayerDisableGestureTypesDoubleTap | RBZFPlayerDisableGestureTypesPan | RBZFPlayerDisableGestureTypesPinch)
};

/// This enumeration lists some of the pan gesture moving direction that the player not support.
typedef NS_OPTIONS(NSUInteger, RBZFPlayerDisablePanMovingDirection) {
    RBZFPlayerDisablePanMovingDirectionNone         = 0,       /// Not disable pan moving direction.
    RBZFPlayerDisablePanMovingDirectionVertical     = 1 << 0,  /// Disable pan moving vertical direction.
    RBZFPlayerDisablePanMovingDirectionHorizontal   = 1 << 1,  /// Disable pan moving horizontal direction.
    RBZFPlayerDisablePanMovingDirectionAll          = (RBZFPlayerDisablePanMovingDirectionVertical | RBZFPlayerDisablePanMovingDirectionHorizontal)  /// Disable pan moving all direction.
};

@interface RBZFPlayerGestureControl : NSObject

/// Gesture condition callback.
@property (nonatomic, copy, nullable) BOOL(^triggerCondition)(RBZFPlayerGestureControl *control, RBZFPlayerGestureType type, UIGestureRecognizer *gesture, UITouch *touch);

/// Single tap gesture callback.
@property (nonatomic, copy, nullable) void(^singleTapped)(RBZFPlayerGestureControl *control);

/// Double tap gesture callback.
@property (nonatomic, copy, nullable) void(^doubleTapped)(RBZFPlayerGestureControl *control);

/// Begin pan gesture callback.
@property (nonatomic, copy, nullable) void(^beganPan)(RBZFPlayerGestureControl *control, RBZFPanDirection direction, RBZFPanLocation location);

/// Pan gesture changing callback.
@property (nonatomic, copy, nullable) void(^changedPan)(RBZFPlayerGestureControl *control, RBZFPanDirection direction, RBZFPanLocation location, CGPoint velocity);

/// End the Pan gesture callback.
@property (nonatomic, copy, nullable) void(^endedPan)(RBZFPlayerGestureControl *control, RBZFPanDirection direction, RBZFPanLocation location);

/// Pinch gesture callback.
@property (nonatomic, copy, nullable) void(^pinched)(RBZFPlayerGestureControl *control, float scale);

/// The single tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *singleTap;

/// The double tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *doubleTap;

/// The pan tap gesture.
@property (nonatomic, strong, readonly) UIPanGestureRecognizer *panGR;

/// The pinch tap gesture.
@property (nonatomic, strong, readonly) UIPinchGestureRecognizer *pinchGR;

/// The pan gesture direction.
@property (nonatomic, readonly) RBZFPanDirection panDirection;

@property (nonatomic, readonly) RBZFPanLocation panLocation;

@property (nonatomic, readonly) RBZFPanMovingDirection panMovingDirection;

/// The gesture types that the player not support.
@property (nonatomic) RBZFPlayerDisableGestureTypes disableTypes;

/// The pan gesture moving direction that the player not support.
@property (nonatomic) RBZFPlayerDisablePanMovingDirection disablePanMovingDirection;

/**
 Add gestures to the view.
 */
- (void)addGestureToView:(UIView *)view;

/**
 Remove gestures form the view.
 */
- (void)removeGestureToView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
