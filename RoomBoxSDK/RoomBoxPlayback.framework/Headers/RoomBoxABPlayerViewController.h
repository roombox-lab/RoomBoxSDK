//
//  RoomBoxABPlyerViewController.h
//  RoomBoxPlayback-RoomBoxPlayback
//
//  Created by hourui on 2021/7/11.
//

#import <UIKit/UIKit.h>
@import RoomBoxUtils;
@protocol RoomBoxPlaybackDelegate;

NS_ASSUME_NONNULL_BEGIN



@interface RoomBoxABPlayerViewController : RBBaseViewController
@property (nonatomic, assign) UIDeviceOrientation preOrientation;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *userToken;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSString* cid;
@property (nonatomic, copy) NSString* uid;
@property (nonatomic, assign) BOOL playerLoaded;

+ (void) InitEnvironmentType:(int)envType;
@end

NS_ASSUME_NONNULL_END
