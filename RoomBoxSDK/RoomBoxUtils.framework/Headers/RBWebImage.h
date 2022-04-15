/*
 * This file is part of the RBWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Florent Vilmart
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <RoomBoxUtils/RBWebImageCompat.h>

//! Project version number for RBWebImage.
FOUNDATION_EXPORT double RBWebImageVersionNumber;

//! Project version string for RBWebImage.
FOUNDATION_EXPORT const unsigned char RBWebImageVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <RoomBoxUtils/PublicHeader.h>

#import <RoomBoxUtils/RBWebImageManager.h>
#import <RoomBoxUtils/RBWebImageCacheKeyFilter.h>
#import <RoomBoxUtils/RBWebImageCacheSerializer.h>
#import <RoomBoxUtils/RBImageCacheConfig.h>
#import <RoomBoxUtils/RBImageCache.h>
#import <RoomBoxUtils/RBMemoryCache.h>
#import <RoomBoxUtils/RBDiskCache.h>
#import <RoomBoxUtils/RBImageCacheDefine.h>
#import <RoomBoxUtils/RBImageCachesManager.h>
#import <RoomBoxUtils/UIView+RBWebCache.h>
#import <RoomBoxUtils/UIImageView+RBWebCache.h>
#import <RoomBoxUtils/UIImageView+RBHighlightedWebCache.h>
#import <RoomBoxUtils/RBWebImageDownloaderConfig.h>
#import <RoomBoxUtils/RBWebImageDownloaderOperation.h>
#import <RoomBoxUtils/RBWebImageDownloaderRequestModifier.h>
#import <RoomBoxUtils/RBWebImageDownloaderResponseModifier.h>
#import <RoomBoxUtils/RBWebImageDownloaderDecryptor.h>
#import <RoomBoxUtils/RBImageLoader.h>
#import <RoomBoxUtils/RBImageLoadersManager.h>
#import <RoomBoxUtils/UIButton+RBWebCache.h>
#import <RoomBoxUtils/RBWebImagePrefetcher.h>
#import <RoomBoxUtils/UIView+RBWebCacheOperation.h>
#import <RoomBoxUtils/UIImage+RBMetadata.h>
#import <RoomBoxUtils/UIImage+RBMultiFormat.h>
#import <RoomBoxUtils/UIImage+RBMemoryCacheCost.h>
#import <RoomBoxUtils/UIImage+RBExtendedCacheData.h>
#import <RoomBoxUtils/RBWebImageOperation.h>
#import <RoomBoxUtils/RBWebImageDownloader.h>
#import <RoomBoxUtils/RBWebImageTransition.h>
#import <RoomBoxUtils/RBWebImageIndicator.h>
#import <RoomBoxUtils/RBImageTransformer.h>
#import <RoomBoxUtils/UIImage+RBTransform.h>
#import <RoomBoxUtils/RBAnimatedImage.h>
#import <RoomBoxUtils/RBAnimatedImageView.h>
#import <RoomBoxUtils/RBAnimatedImageView+WebCache.h>
#import <RoomBoxUtils/RBAnimatedImagePlayer.h>
#import <RoomBoxUtils/RBImageCodersManager.h>
#import <RoomBoxUtils/RBImageCoder.h>
#import <RoomBoxUtils/RBImageAPNGCoder.h>
#import <RoomBoxUtils/RBImageGIFCoder.h>
#import <RoomBoxUtils/RBImageIOCoder.h>
#import <RoomBoxUtils/RBImageFrame.h>
#import <RoomBoxUtils/RBImageCoderHelper.h>
#import <RoomBoxUtils/RBImageGraphics.h>
#import <RoomBoxUtils/RBGraphicsImageRenderer.h>
#import <RoomBoxUtils/UIImage+RBGIF.h>
#import <RoomBoxUtils/UIImage+RBForceDecode.h>
#import <RoomBoxUtils/NSData+RBImageContentType.h>
#import <RoomBoxUtils/RBWebImageDefine.h>
#import <RoomBoxUtils/RBWebImageError.h>
#import <RoomBoxUtils/RBWebImageOptionsProcessor.h>
#import <RoomBoxUtils/RBImageIOAnimatedCoder.h>
#import <RoomBoxUtils/RBImageHEICCoder.h>
#import <RoomBoxUtils/RBImageAWebPCoder.h>

// Mac
#if __has_include(<RBWebImage/NSImage+RBCompatibility.h>)
#import <RoomBoxUtils/NSImage+RBCompatibility.h>
#endif
#if __has_include(<RBWebImage/NSButton+RBWebCache.h>)
#import <RoomBoxUtils/NSButton+RBWebCache.h>
#endif
#if __has_include(<RBWebImage/RBAnimatedImageRep.h>)
#import <RoomBoxUtils/RBAnimatedImageRep.h>
#endif

// MapKit
#if __has_include(<RBWebImage/MKAnnotationView+WebCache.h>)
#import <RoomBoxUtils/MKAnnotationView+WebCache.h>
#endif
