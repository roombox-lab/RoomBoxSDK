//
//  RoomBoxPlayerViewController.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2019/9/2.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoomBoxPlayerInvalidView.h"

@import RoomBoxUtils;
@protocol RoomBoxPlaybackDelegate;

NS_ASSUME_NONNULL_BEGIN

extern NSString *RoomBoxPlayerViewControllerDidDisappearNotification;

typedef NS_ENUM(NSInteger, RoomBoxPlayerCoreType) {
    RoomBoxPlayerCoreTypeAVPlayer = 0,
    RoomBoxPlayerCoreTypeIJKPlayer = 1,
};

@interface RoomBoxPlayerViewController : RBBaseViewController
@property(nonatomic, weak) id<RoomBoxPlaybackDelegate> delegateManager;
// 播放器内核类型
@property (nonatomic, assign) RoomBoxPlayerCoreType coreType;
@property (nonatomic, assign) UIDeviceOrientation preOrientation;
@property (nonatomic, strong) RoomBoxPlayerInvalidView *invalidPlayView;

- (void)setInvalidView:(BOOL)isHidden;
- (void)setInvalidViewText:(NSString *)text;
- (void)updateAssetTitle:(NSString *)title;

- (void)updateAssetUrl:(NSString *)url;

- (void)updateAssetRemoteUrl:(NSString *)remoteUrl;

- (void)updateCopyright:(NSString *)copyright;

- (void)updateCid:(NSString *)cid;

- (void)updateUid:(NSString *)uid;

- (void)updateToken:(NSString *)token;

- (void)updateIsExistNewNote:(BOOL *)isExist;

- (void)loadData;


@end

NS_ASSUME_NONNULL_END
