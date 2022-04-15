/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

@interface RBTimeProfiler : NSObject

#pragma mark - Open API

#define kTimeProfilerResultNotificationName @"RBTimeProfilerResult"
#define kNotificationUserInfoKey            @"logArray"

+ (RBTimeProfiler *)sharedTimeProfiler;

- (instancetype)initTimeProfilerWithMainKey:(NSString *)mainKey;
- (void)recordEventTime:(NSString *)eventName;

- (void)printOutTimeProfileResult;
- (void)saveTimeProfileDataIntoFile:(NSString *)filePath;
- (void)postTimeProfileResultNotification;

@end
