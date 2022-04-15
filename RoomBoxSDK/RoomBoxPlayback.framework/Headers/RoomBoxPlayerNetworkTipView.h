//
//  RoomBoxPlayerNetworkTipView.h
//  Alamofire
//
//  Created by wangwenlong on 2019/9/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RoomBoxPlayerNetworkTipViewDelagate <NSObject>

@optional
- (void)playerNetworkTipViewDidSelectBackward;
- (void)playerNetworkTipViewDidSelectPlayViaCelluar;
- (void)playerNetworkTipViewDidSelectReconnect;

@end

@interface RoomBoxPlayerNetworkTipView : UIView

@property (nonatomic, weak) id<RoomBoxPlayerNetworkTipViewDelagate> delegate;

- (void)updateWithWifi;
- (void)updateWithCelluar;
- (void)updateWithDisconnect;
- (void)updateWithFailed;
- (void)updateWithLoading;

@end

NS_ASSUME_NONNULL_END
