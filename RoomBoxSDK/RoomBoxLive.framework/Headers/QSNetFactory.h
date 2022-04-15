//
//  QSNetFactory.h
//  XDFRoomBox
//
//  Created by Joey on 2021/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QSNetFactory : NSObject
+ (NSString *)getChannelIDWithUid:(UInt64)uid;
- (NSString *)requestChannelIDWithUid:(UInt64)uid;
@end

NS_ASSUME_NONNULL_END
