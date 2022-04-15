//
//  XDFIJKPlayerManager.h
//  RoomBoxPlayer
//
//  Created by 婉华孙 on 2019/9/4.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XDFIJKMediaFramework/XDFIJKMediaFramework.h>
#import "RoomBoxPlayerEventProtocol.h"
@import RoomBoxUtils;

NS_ASSUME_NONNULL_BEGIN

@interface XDFIJKPlayerManager : NSObject <RBZFPlayerMediaPlayback>

@property (nonatomic, strong, readonly) XDFIJKFFMoviePlayerController *player;

@property (nonatomic, strong, readonly) XDFIJKFFOptions *options;

@property (nonatomic, assign) NSTimeInterval timeRefreshInterval;

@property (nonatomic, assign) NSTimeInterval seekBeginTime;

@property (nonatomic, weak) id<RoomBoxPlayerEventProtocol> eventObserver;

@end

NS_ASSUME_NONNULL_END
