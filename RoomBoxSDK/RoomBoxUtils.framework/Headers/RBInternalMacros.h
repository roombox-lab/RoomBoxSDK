/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import <os/lock.h>
#import <libkern/OSAtomic.h>
#import "RBmetamacros.h"

#define RB_USE_OS_UNFAIR_LOCK TARGET_OS_MACCATALYST ||\
    (__IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_10_0) ||\
    (__MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_12) ||\
    (__TV_OS_VERSION_MIN_REQUIRED >= __TVOS_10_0) ||\
    (__WATCH_OS_VERSION_MIN_REQUIRED >= __WATCHOS_3_0)

#ifndef RB_LOCK_DECLARE
#if RB_USE_OS_UNFAIR_LOCK
#define RB_LOCK_DECLARE(lock) os_unfair_lock lock
#else
#define RB_LOCK_DECLARE(lock) os_unfair_lock lock API_AVAILABLE(ios(10.0), tvos(10), watchos(3), macos(10.12)); \
OSSpinLock lock##_deprecated;
#endif
#endif

#ifndef RB_LOCK_INIT
#if RB_USE_OS_UNFAIR_LOCK
#define RB_LOCK_INIT(lock) lock = OS_UNFAIR_LOCK_INIT
#else
#define RB_LOCK_INIT(lock) if (@available(iOS 10, tvOS 10, watchOS 3, macOS 10.12, *)) lock = OS_UNFAIR_LOCK_INIT; \
else lock##_deprecated = OS_SPINLOCK_INIT;
#endif
#endif

#ifndef RB_LOCK
#if RB_USE_OS_UNFAIR_LOCK
#define RB_LOCK(lock) os_unfair_lock_lock(&lock)
#else
#define RB_LOCK(lock) if (@available(iOS 10, tvOS 10, watchOS 3, macOS 10.12, *)) os_unfair_lock_lock(&lock); \
else OSSpinLockLock(&lock##_deprecated);
#endif
#endif

#ifndef RB_UNLOCK
#if RB_USE_OS_UNFAIR_LOCK
#define RB_UNLOCK(lock) os_unfair_lock_unlock(&lock)
#else
#define RB_UNLOCK(lock) if (@available(iOS 10, tvOS 10, watchOS 3, macOS 10.12, *)) os_unfair_lock_unlock(&lock); \
else OSSpinLockUnlock(&lock##_deprecated);
#endif
#endif

#ifndef RB_OPTIONS_CONTAINS
#define RB_OPTIONS_CONTAINS(options, value) (((options) & (value)) == (value))
#endif

#ifndef RB_CSTRING
#define RB_CSTRING(str) #str
#endif

#ifndef RB_NSSTRING
#define RB_NSSTRING(str) @(RB_CSTRING(str))
#endif

#ifndef RB_SEL_SPI
#define RB_SEL_SPI(name) NSSelectorFromString([NSString stringWithFormat:@"_%@", RB_NSSTRING(name)])
#endif

#ifndef weakify
#define weakify(...) \
rb_keywordify \
metamacro_foreach_cxt(rb_weakify_,, __weak, __VA_ARGS__)
#endif

#ifndef strongify
#define strongify(...) \
rb_keywordify \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
metamacro_foreach(rb_strongify_,, __VA_ARGS__) \
_Pragma("clang diagnostic pop")
#endif

#define rb_weakify_(INDEX, CONTEXT, VAR) \
CONTEXT __typeof__(VAR) metamacro_concat(VAR, _weak_) = (VAR);

#define rb_strongify_(INDEX, VAR) \
__strong __typeof__(VAR) VAR = metamacro_concat(VAR, _weak_);

#if DEBUG
#define rb_keywordify autoreleasepool {}
#else
#define rb_keywordify try {} @catch (...) {}
#endif

#ifndef onExit
#define onExit \
rb_keywordify \
__strong rb_cleanupBlock_t metamacro_concat(rb_exitBlock_, __LINE__) __attribute__((cleanup(rb_executeCleanupBlock), unused)) = ^
#endif

typedef void (^rb_cleanupBlock_t)(void);

#if defined(__cplusplus)
extern "C" {
#endif
    void rb_executeCleanupBlock (__strong rb_cleanupBlock_t *block);
#if defined(__cplusplus)
}
#endif
