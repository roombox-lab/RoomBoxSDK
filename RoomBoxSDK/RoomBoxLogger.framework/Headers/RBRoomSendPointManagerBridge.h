//
//  RBRoomSendPointManagerBridge.h
//  XDFRoomCommonBussiness
//
//  Created by 刘冬冬 on 2021/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RBRoomSendPointManagerBridge : NSObject
+(void)sendPlayer:(NSTimeInterval )ts withUrl:(NSString *)link;
@end

NS_ASSUME_NONNULL_END
