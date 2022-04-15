//
//  XDFRoomNetCheckManager.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2019/9/11.
//  Copyright © 2019 XDF. All rights reserved.
//  网络情况监听

#import <Foundation/Foundation.h>

// 监听下载的速度
extern NSString *const XDFDownloadNetworkSpeedNotificationKey;
// 监听上传的速度
extern NSString *const XDFUploadNetworkSpeedNotificationKey;

NS_ASSUME_NONNULL_BEGIN

@interface XDFRoomNetCheckManager : NSObject

// 下载速度
@property (nonatomic, copy, readonly) NSString *downloadNetworkSpeed;
//  上传速度
@property (nonatomic, copy, readonly) NSString *uploadNetworkSpeed;

+ (instancetype)shareNetworkSpeed;
    
- (void)startCheckNet;
- (void)stopCheckNet;
    
@end

NS_ASSUME_NONNULL_END
