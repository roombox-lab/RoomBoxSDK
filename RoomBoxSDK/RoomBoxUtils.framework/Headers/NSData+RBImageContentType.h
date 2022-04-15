/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "RBWebImageCompat.h"

/**
 You can use switch case like normal enum. It's also recommended to add a default case. You should not assume anything about the raw value.
 For custom coder plugin, it can also extern the enum for supported format. See `SDImageCoder` for more detailed information.
 */
typedef NSInteger RBImageFormat NS_TYPED_EXTENSIBLE_ENUM;
static const RBImageFormat RBImageFormatUndefined = -1;
static const RBImageFormat RBImageFormatJPEG      = 0;
static const RBImageFormat RBImageFormatPNG       = 1;
static const RBImageFormat RBImageFormatGIF       = 2;
static const RBImageFormat RBImageFormatTIFF      = 3;
static const RBImageFormat RBImageFormatWebP      = 4;
static const RBImageFormat RBImageFormatHEIC      = 5;
static const RBImageFormat RBImageFormatHEIF      = 6;
static const RBImageFormat RBImageFormatPDF       = 7;
static const RBImageFormat RBImageFormatSVG       = 8;

/**
 NSData category about the image content type and UTI.
 */
@interface NSData (RBImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `SDImageFormat` (enum)
 */
+ (RBImageFormat)rb_imageFormatForImageData:(nullable NSData *)data;

/**
 *  Convert SDImageFormat to UTType
 *
 *  @param format Format as SDImageFormat
 *  @return The UTType as CFStringRef
 *  @note For unknown format, `kUTTypeImage` abstract type will return
 */
+ (nonnull CFStringRef)rb_UTTypeFromImageFormat:(RBImageFormat)format CF_RETURNS_NOT_RETAINED NS_SWIFT_NAME(sd_UTType(from:));

/**
 *  Convert UTType to SDImageFormat
 *
 *  @param uttype The UTType as CFStringRef
 *  @return The Format as SDImageFormat
 *  @note For unknown type, `SDImageFormatUndefined` will return
 */
+ (RBImageFormat)rb_imageFormatFromUTType:(nonnull CFStringRef)uttype;

@end
