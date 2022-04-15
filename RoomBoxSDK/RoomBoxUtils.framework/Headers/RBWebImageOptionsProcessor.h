/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "RBWebImageCompat.h"
#import "RBWebImageDefine.h"

@class RBWebImageOptionsResult;

typedef RBWebImageOptionsResult * _Nullable(^RBWebImageOptionsProcessorBlock)(NSURL * _Nullable url, RBWebImageOptions options, RBWebImageContext * _Nullable context);

/**
 The options result contains both options and context.
 */
@interface RBWebImageOptionsResult : NSObject

/**
 WebCache options.
 */
@property (nonatomic, assign, readonly) RBWebImageOptions options;

/**
 Context options.
 */
@property (nonatomic, copy, readonly, nullable) RBWebImageContext *context;

/**
 Create a new options result.

 @param options options
 @param context context
 @return The options result contains both options and context.
 */
- (nonnull instancetype)initWithOptions:(RBWebImageOptions)options context:(nullable RBWebImageContext *)context;

@end

/**
 This is the protocol for options processor.
 Options processor can be used, to control the final result for individual image request's `RBWebImageOptions` and `RBWebImageContext`
 Implements the protocol to have a global control for each indivadual image request's option.
 */
@protocol RBWebImageOptionsProcessor <NSObject>

/**
 Return the processed options result for specify image URL, with its options and context

 @param url The URL to the image
 @param options A mask to specify options to use for this request
 @param context A context contains different options to perform specify changes or processes, see `RBWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 @return The processed result, contains both options and context
 */
- (nullable RBWebImageOptionsResult *)processedResultForURL:(nullable NSURL *)url
                                                    options:(RBWebImageOptions)options
                                                    context:(nullable RBWebImageContext *)context;

@end

/**
 A options processor class with block.
 */
@interface RBWebImageOptionsProcessor : NSObject<RBWebImageOptionsProcessor>

- (nonnull instancetype)initWithBlock:(nonnull RBWebImageOptionsProcessorBlock)block;
+ (nonnull instancetype)optionsProcessorWithBlock:(nonnull RBWebImageOptionsProcessorBlock)block;

@end
