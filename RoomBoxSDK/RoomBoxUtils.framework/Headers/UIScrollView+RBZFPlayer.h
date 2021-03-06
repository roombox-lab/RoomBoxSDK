//
//  UIScrollView+RBZFPlayer.h
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

/*
 * The scroll direction of scrollView.
 */
typedef NS_ENUM(NSUInteger, RBZFPlayerScrollDirection) {
    RBZFPlayerScrollDirectionNone,
    RBZFPlayerScrollDirectionUp,         // Scroll up
    RBZFPlayerScrollDirectionDown,       // Scroll Down
    RBZFPlayerScrollDirectionLeft,       // Scroll left
    RBZFPlayerScrollDirectionRight       // Scroll right
};

/*
 * The scrollView direction.
 */
typedef NS_ENUM(NSInteger, RBZFPlayerScrollViewDirection) {
    RBZFPlayerScrollViewDirectionVertical,
    RBZFPlayerScrollViewDirectionHorizontal
};

/*
 * The player container type
 */
typedef NS_ENUM(NSInteger, RBZFPlayerContainerType) {
    RBZFPlayerContainerTypeCell,
    RBZFPlayerContainerTypeView
};

@interface UIScrollView (RBZFPlayer)

/// When the RBZFPlayerScrollViewDirection is RBZFPlayerScrollViewDirectionVertical,the property has value.
@property (nonatomic, readonly) CGFloat zf_lastOffsetY;

/// When the RBZFPlayerScrollViewDirection is RBZFPlayerScrollViewDirectionHorizontal,the property has value.
@property (nonatomic, readonly) CGFloat zf_lastOffsetX;

/// The indexPath is playing.
@property (nonatomic, nullable) NSIndexPath *zf_playingIndexPath;

/// The indexPath that should play, the one that lights up.
@property (nonatomic, nullable) NSIndexPath *zf_shouldPlayIndexPath;

/// WWANA networks play automatically,default NO.
@property (nonatomic, getter=zf_isWWANAutoPlay) BOOL zf_WWANAutoPlay;

/// The player should auto player,default is YES.
@property (nonatomic) BOOL zf_shouldAutoPlay;

/// The view tag that the player display in scrollView.
@property (nonatomic) NSInteger zf_containerViewTag;

/// The scrollView scroll direction, default is RBZFPlayerScrollViewDirectionVertical.
@property (nonatomic) RBZFPlayerScrollViewDirection zf_scrollViewDirection;

/// The scroll direction of scrollView while scrolling.
/// When the RBZFPlayerScrollViewDirection is RBZFPlayerScrollViewDirectionVertical，this value can only be RBZFPlayerScrollDirectionUp or RBZFPlayerScrollDirectionDown.
/// When the RBZFPlayerScrollViewDirection is RBZFPlayerScrollViewDirectionVertical，this value can only be RBZFPlayerScrollDirectionLeft or RBZFPlayerScrollDirectionRight.
@property (nonatomic, readonly) RBZFPlayerScrollDirection zf_scrollDirection;

/// The video contrainerView type.
@property (nonatomic, assign) RBZFPlayerContainerType zf_containerType;

/// The video contrainerView in normal model.
@property (nonatomic, strong) UIView *zf_containerView;

/// The currently playing cell stop playing when the cell has out off the screen，defalut is YES.
@property (nonatomic, assign) BOOL zf_stopWhileNotVisible;

/// Has stopped playing
@property (nonatomic, assign) BOOL zf_stopPlay;

/// The block invoked When the player did stop scroll.
@property (nonatomic, copy, nullable) void(^zf_scrollViewDidStopScrollCallback)(NSIndexPath *indexPath);

/// The block invoked When the player should play.
@property (nonatomic, copy, nullable) void(^zf_shouldPlayIndexPathCallback)(NSIndexPath *indexPath);

/// Filter the cell that should be played when the scroll is stopped (to play when the scroll is stopped).
- (void)zf_filterShouldPlayCellWhileScrolled:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Filter the cell that should be played while scrolling (you can use this to filter the highlighted cell).
- (void)zf_filterShouldPlayCellWhileScrolling:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Get the cell according to indexPath.
- (UIView *)zf_getCellForIndexPath:(NSIndexPath *)indexPath;

/// Scroll to indexPath with animations.
- (void)zf_scrollToRowAtIndexPath:(NSIndexPath *)indexPath completionHandler:(void (^ __nullable)(void))completionHandler;

/// add in 3.2.4 version.
/// Scroll to indexPath with animations.
- (void)zf_scrollToRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated completionHandler:(void (^ __nullable)(void))completionHandler;

/// add in 3.2.8 version.
/// Scroll to indexPath with animations duration.
- (void)zf_scrollToRowAtIndexPath:(NSIndexPath *)indexPath animateWithDuration:(NSTimeInterval)duration completionHandler:(void (^ __nullable)(void))completionHandler;

///------------------------------------
/// The following method must be implemented in UIScrollViewDelegate.
///------------------------------------

- (void)zf_scrollViewDidEndDecelerating;

- (void)zf_scrollViewDidEndDraggingWillDecelerate:(BOOL)decelerate;

- (void)zf_scrollViewDidScrollToTop;

- (void)zf_scrollViewDidScroll;

- (void)zf_scrollViewWillBeginDragging;

///------------------------------------
/// end
///------------------------------------


@end

@interface UIScrollView (RBZFPlayerCannotCalled)

/// The block invoked When the player appearing.
@property (nonatomic, copy, nullable) void(^zf_playerAppearingInScrollView)(NSIndexPath *indexPath, CGFloat playerApperaPercent);

/// The block invoked When the player disappearing.
@property (nonatomic, copy, nullable) void(^zf_playerDisappearingInScrollView)(NSIndexPath *indexPath, CGFloat playerDisapperaPercent);

/// The block invoked When the player will appeared.
@property (nonatomic, copy, nullable) void(^zf_playerWillAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did appeared.
@property (nonatomic, copy, nullable) void(^zf_playerDidAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player will disappear.
@property (nonatomic, copy, nullable) void(^zf_playerWillDisappearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did disappeared.
@property (nonatomic, copy, nullable) void(^zf_playerDidDisappearInScrollView)(NSIndexPath *indexPath);

/// The current player scroll slides off the screen percent.
/// the property used when the `stopWhileNotVisible` is YES, stop the current playing player.
/// the property used when the `stopWhileNotVisible` is NO, the current playing player add to small container view.
/// 0.0~1.0, defalut is 0.5.
/// 0.0 is the player will disappear.
/// 1.0 is the player did disappear.
@property (nonatomic) CGFloat zf_playerDisapperaPercent;

/// The current player scroll to the screen percent to play the video.
/// 0.0~1.0, defalut is 0.0.
/// 0.0 is the player will appear.
/// 1.0 is the player did appear.
@property (nonatomic) CGFloat zf_playerApperaPercent;

/// The current player controller is disappear, not dealloc
@property (nonatomic) BOOL zf_viewControllerDisappear;

@end

NS_ASSUME_NONNULL_END
