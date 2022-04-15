//
//  AmazingBox.h
//  AmazingBox
//
//  Created by hourui on 2021/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmazingBox : NSObject

//初始化ABPlayer环境，默认线上 0:线上，1:debug
+ (void)InitAmazingBoxEnv:(int)type;

+ (void)EnterAmazingBoxFromVC:(UIViewController *)vc WithType:(int)type uid:(NSString*)uid userToken:(NSString*)userToken cid:(NSString*)cid nickName:(NSString *)nickName;

@end

NS_ASSUME_NONNULL_END
