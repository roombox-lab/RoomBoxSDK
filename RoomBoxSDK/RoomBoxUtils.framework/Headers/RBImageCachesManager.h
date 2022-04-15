/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "RBImageCacheDefine.h"

/// Policy for cache operation
typedef NS_ENUM(NSUInteger, RBImageCachesManagerOperationPolicy) {
    RBImageCachesManagerOperationPolicySerial, // process all caches serially (from the highest priority to the lowest priority cache by order)
    RBImageCachesManagerOperationPolicyConcurrent, // process all caches concurrently
    RBImageCachesManagerOperationPolicyHighestOnly, // process the highest priority cache only
    RBImageCachesManagerOperationPolicyLowestOnly // process the lowest priority cache only
};

/**
 A caches manager to manage multiple caches.
 */
@interface RBImageCachesManager : NSObject <RBImageCache>

/**
 Returns the global shared caches manager instance. By default we will set [`SDImageCache.sharedImageCache`] into the caches array.
 */
@property (nonatomic, class, readonly, nonnull) RBImageCachesManager *sharedManager;

// These are op policy for cache manager.

/**
 Operation policy for query op.
 Defaults to `Serial`, means query all caches serially (one completion called then next begin) until one cache query success (`image` != nil).
 */
@property (nonatomic, assign) RBImageCachesManagerOperationPolicy queryOperationPolicy;

/**
 Operation policy for store op.
 Defaults to `HighestOnly`, means store to the highest priority cache only.
 */
@property (nonatomic, assign) RBImageCachesManagerOperationPolicy storeOperationPolicy;

/**
 Operation policy for remove op.
 Defaults to `Concurrent`, means remove all caches concurrently.
 */
@property (nonatomic, assign) RBImageCachesManagerOperationPolicy removeOperationPolicy;

/**
 Operation policy for contains op.
 Defaults to `Serial`, means check all caches serially (one completion called then next begin) until one cache check success (`containsCacheType` != None).
 */
@property (nonatomic, assign) RBImageCachesManagerOperationPolicy containsOperationPolicy;

/**
 Operation policy for clear op.
 Defaults to `Concurrent`, means clear all caches concurrently.
 */
@property (nonatomic, assign) RBImageCachesManagerOperationPolicy clearOperationPolicy;

/**
 All caches in caches manager. The caches array is a priority queue, which means the later added cache will have the highest priority
 */
@property (nonatomic, copy, nullable) NSArray<id<RBImageCache>> *caches;

/**
 Add a new cache to the end of caches array. Which has the highest priority.
 
 @param cache cache
 */
- (void)addCache:(nonnull id<RBImageCache>)cache;

/**
 Remove a cache in the caches array.
 
 @param cache cache
 */
- (void)removeCache:(nonnull id<RBImageCache>)cache;

@end
