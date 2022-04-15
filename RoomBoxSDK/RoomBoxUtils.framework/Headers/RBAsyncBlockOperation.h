/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "RBWebImageCompat.h"

@class RBAsyncBlockOperation;
typedef void (^RBAsyncBlock)(RBAsyncBlockOperation * __nonnull asyncOperation);

/// A async block operation, success after you call `completer` (not like `NSBlockOperation` which is for sync block, success on return)
@interface RBAsyncBlockOperation : NSOperation

- (nonnull instancetype)initWithBlock:(nonnull RBAsyncBlock)block;
+ (nonnull instancetype)blockOperationWithBlock:(nonnull RBAsyncBlock)block;
- (void)complete;

@end
