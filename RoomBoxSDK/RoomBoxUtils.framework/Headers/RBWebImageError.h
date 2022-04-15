/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Jamie Pinkham
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "RBWebImageCompat.h"

FOUNDATION_EXPORT NSErrorDomain const _Nonnull RBWebImageErrorDomain;

/// The HTTP status code for invalid download response (NSNumber *)
FOUNDATION_EXPORT NSErrorUserInfoKey const _Nonnull RBWebImageErrorDownloadStatusCodeKey;

/// SDWebImage error domain and codes
typedef NS_ERROR_ENUM(RBWebImageErrorDomain, RBWebImageError) {
    RBWebImageErrorInvalidURL = 1000, // The URL is invalid, such as nil URL or corrupted URL
    RBWebImageErrorBadImageData = 1001, // The image data can not be decoded to image, or the image data is empty
    RBWebImageErrorCacheNotModified = 1002, // The remote location specify that the cached image is not modified, such as the HTTP response 304 code. It's useful for `SDWebImageRefreshCached`
    RBWebImageErrorBlackListed = 1003, // The URL is blacklisted because of unrecoverable failure marked by downloader (such as 404), you can use `.retryFailed` option to avoid this
    RBWebImageErrorInvalidDownloadOperation = 2000, // The image download operation is invalid, such as nil operation or unexpected error occur when operation initialized
    RBWebImageErrorInvalidDownloadStatusCode = 2001, // The image download response a invalid status code. You can check the status code in error's userInfo under `SDWebImageErrorDownloadStatusCodeKey`
    RBWebImageErrorCancelled = 2002, // The image loading operation is cancelled before finished, during either async disk cache query, or waiting before actual network request. For actual network request error, check `NSURLErrorDomain` error domain and code.
    RBWebImageErrorInvalidDownloadResponse = 2003, // When using response modifier, the modified download response is nil and marked as failed.
};
