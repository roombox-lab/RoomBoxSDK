//
//  RBLogEncryptTool.h
//  RBLog
//
//  Created by wangwenlong on 2019/9/27.
//  Copyright © 2019 RB.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RBLogEncryptTool : NSObject

+ (NSString *)hmacSha1:(NSString *)key data:(NSString *)data;
+ (NSString *)encryptPwdSha1:(NSString *)password;

@end
