//
//  RoomBoxABPlayerErrorView.h
//  RoomBoxPlayback
//
//  Created by hourui on 2021/7/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxABPlayerErrorView : UIView

@property (nonatomic, copy) void (^errorButtonTapped)(void);
@property (nonatomic, copy) NSString *title;

- (void) showBtn:(BOOL)bShow;
@end

NS_ASSUME_NONNULL_END
