//
//  RBSVGAParser.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 16/6/17.
//  Copyright © 2016年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RBSVGAVideoEntity;

@interface RBSVGAParser : NSObject

@property (nonatomic, assign) BOOL enabledMemoryCache;

- (void)parseWithURL:(nonnull NSURL *)URL
     completionBlock:(void ( ^ _Nonnull )(RBSVGAVideoEntity * _Nullable videoItem))completionBlock
        failureBlock:(void ( ^ _Nullable)(NSError * _Nullable error))failureBlock;

- (void)parseWithURLRequest:(nonnull NSURLRequest *)URLRequest
            completionBlock:(void ( ^ _Nonnull )(RBSVGAVideoEntity * _Nullable videoItem))completionBlock
               failureBlock:(void ( ^ _Nullable)(NSError * _Nullable error))failureBlock;

- (void)parseWithData:(nonnull NSData *)data
             cacheKey:(nonnull NSString *)cacheKey
      completionBlock:(void ( ^ _Nullable)(RBSVGAVideoEntity * _Nonnull videoItem))completionBlock
         failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;

- (void)parseWithNamed:(nonnull NSString *)named
              inBundle:(nullable NSBundle *)inBundle
       completionBlock:(void ( ^ _Nullable)(RBSVGAVideoEntity * _Nonnull videoItem))completionBlock
          failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;

@end
