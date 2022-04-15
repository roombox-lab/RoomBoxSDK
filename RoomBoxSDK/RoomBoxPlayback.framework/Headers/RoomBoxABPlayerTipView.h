//
//  RoomBoxABPlayerTipView.h
//  RoomBoxPlayback
//
//  Created by hekun on 2021/8/31.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxABPlayerTipView : UIView

@property (nonatomic, copy) void (^tipButtonTapped)(void);
@property (nonatomic, copy) NSString *title;

- (void) showBtn:(BOOL)bShow;
@end

NS_ASSUME_NONNULL_END
