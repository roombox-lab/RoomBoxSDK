/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "RBImageIOAnimatedCoder.h"

/**
 Built in coder using ImageIO that supports APNG encoding/decoding
 */
@interface RBImageAPNGCoder : RBImageIOAnimatedCoder <RBProgressiveImageCoder, RBAnimatedImageCoder>

@property (nonatomic, class, readonly, nonnull) RBImageAPNGCoder *sharedCoder;

@end
