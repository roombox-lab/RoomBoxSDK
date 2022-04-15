//
//  XDFRoomPingServer.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2019/9/11.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "XDFSimplePing.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, XDFPingStatus) {
    XDFPingStatusDidStart,
    XDFPingStatusDidFailToSendPacket,
    XDFPingStatusDidReceivePacket,
    XDFPingStatusDidReceiveUnexpectedPacket,
    XDFPingStatusDidTimeout,
    XDFPingStatusError,
    XDFPingStatusFinished,
};

@interface XDFPingItem : NSObject
    
@property(nonatomic) NSString *originalAddress;
@property(nonatomic, copy) NSString *IPAddress;

@property(nonatomic) NSUInteger dateBytesLength;
@property(nonatomic) double     timeMilliseconds;
@property(nonatomic) NSInteger  timeToLive;
@property(nonatomic) NSInteger  ICMPSequence;

@property(nonatomic) XDFPingStatus status;
    
+ (NSString *)statisticsWithPingItems:(NSArray *)pingItems;

- (NSString *)getPingDescription;
@end


@interface XDFRoomPingServer : NSObject

/// 超时时间, default 500ms
@property(nonatomic) double timeoutMilliseconds;
    
+ (XDFRoomPingServer *)startPingAddress:(NSString *)address
                      callbackHandler:(void(^)(XDFPingItem *pingItem))handler;
    
@property(nonatomic) NSInteger  maximumPingTimes;
- (void)startPing;
- (void)cancel;
- (void)reping;
@end

NS_ASSUME_NONNULL_END
