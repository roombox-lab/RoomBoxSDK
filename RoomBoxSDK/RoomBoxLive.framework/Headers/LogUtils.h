//
//  LogUtils.h
//  XDFIOSDemo
//
//  Created by xiaoyu on 2021/1/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LogUtils : NSObject
+(NSString*)sdkLogPath;
+(NSString*)sdkChangedLogPath:(NSUInteger)classNum;
@end

NS_ASSUME_NONNULL_END
