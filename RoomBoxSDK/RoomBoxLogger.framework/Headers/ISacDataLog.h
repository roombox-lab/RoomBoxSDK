//
//  ISacDataLog.h
//  LogSend
//
//  Created by 吴云海 on 2019/6/21.
//  Copyright © 2019 吴云海. All rights reserved.
//  对外公开接口

#import <Foundation/Foundation.h>
#import "ISacDataConfig.h"

NS_ASSUME_NONNULL_BEGIN


@interface ISacDataLog : NSObject

- (void)setCurrentActionUrlString:(NSString *)string;
- (void)setCurrentReportUrlString:(NSString *)string;
- (void)setCurrentUrlString:(NSString *)string;
- (void)setCurrentHeadLog:(NSString *)string;
- (void)setCurrentUserId:(NSString *)userId;

- (void)destroyInstance;

- (void)sendLogToServer:(UInt64)sendTime send:(NSData *)sendStr;
- (void)sendWebLogToServer:(UInt64)sendTime send:(NSString *)sendStr;
- (void)sendReportLogToServer:(UInt64)sendTime send:(NSData *)sendStr;

- (void)sendActionLogToServer:(UInt64)sendTime dictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
