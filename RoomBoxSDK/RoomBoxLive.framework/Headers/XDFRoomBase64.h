//
//  XDFRoomBase64.h
//  RoomBoxSDK
//
//  Created by 刘冬冬 on 2019/8/2.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XDFRoomBase64 : NSObject
+ (NSString *)base64EncodedString:(NSString *)from;
+ (NSString *)base64DecodedString:(NSString *)from;
@end

NS_ASSUME_NONNULL_END
