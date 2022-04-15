/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "RBWebImageCompat.h"

typedef NSString * _Nullable(^RBWebImageCacheKeyFilterBlock)(NSURL * _Nonnull url);

/**
 This is the protocol for cache key filter.
 We can use a block to specify the cache key filter. But Using protocol can make this extensible, and allow Swift user to use it easily instead of using `@convention(block)` to store a block into context options.
 */
@protocol RBWebImageCacheKeyFilter <NSObject>

- (nullable NSString *)cacheKeyForURL:(nonnull NSURL *)url;

@end

/**
 A cache key filter class with block.
 */
@interface RBWebImageCacheKeyFilter : NSObject <RBWebImageCacheKeyFilter>

- (nonnull instancetype)initWithBlock:(nonnull RBWebImageCacheKeyFilterBlock)block;
+ (nonnull instancetype)cacheKeyFilterWithBlock:(nonnull RBWebImageCacheKeyFilterBlock)block;

@end
