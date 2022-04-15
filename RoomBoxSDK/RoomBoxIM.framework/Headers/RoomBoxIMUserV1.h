// FILENAME: RoomBoxIMUserV1.h
//
//  Created by 赵亮 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import "UserV1Tcp.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxIMUserV1 : NSObject


// 校验token信息
+ (void)postAuthTokenSend:(UserV1PostAuthTokenRequest *)request andBlock:(void (^)(UserV1PostAuthTokenReply * _Nullable reply))block;


// 获取用户信息
+ (void)postInfoSend:(UserV1PostInfoRequest *)request andBlock:(void (^)(UserV1PostInfoReply * _Nullable reply))block;


@end

NS_ASSUME_NONNULL_END
