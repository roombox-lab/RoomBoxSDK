/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "RBWebImageCompat.h"

#if RB_MAC

#import "RBWebImageManager.h"

/**
 * Integrates SDWebImage async downloading and caching of remote images with NSButton.
 */
@interface NSButton (RBWebCache)

#pragma mark - Image

/**
 * Get the current image URL.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *rb_currentImageURL;

/**
 * Set the button `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url NS_REFINED_FOR_SWIFT;

/**
 * Set the button `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see sd_setImageWithURL:placeholderImage:options:
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder NS_REFINED_FOR_SWIFT;

/**
 * Set the button `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see RBWebImageOptions for the possible values.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                   options:(RBWebImageOptions)options NS_REFINED_FOR_SWIFT;

/**
 * Set the button `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see RBWebImageOptions for the possible values.
 * @param context     A context contains different options to perform specify changes or processes, see `RBWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                   options:(RBWebImageOptions)options
                   context:(nullable RBWebImageContext *)context;

/**
 * Set the button `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
                 completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                 completed:(nullable RBExternalCompletionBlock)completedBlock NS_REFINED_FOR_SWIFT;

/**
 * Set the button `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see RBWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                   options:(RBWebImageOptions)options
                 completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see RBWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                   options:(RBWebImageOptions)options
                  progress:(nullable RBImageLoaderProgressBlock)progressBlock
                 completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see RBWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `RBWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)rb_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                   options:(RBWebImageOptions)options
                   context:(nullable RBWebImageContext *)context
                  progress:(nullable RBImageLoaderProgressBlock)progressBlock
                 completed:(nullable RBExternalCompletionBlock)completedBlock;

#pragma mark - Alternate Image

/**
 * Get the current alternateImage URL.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *rb_currentAlternateImageURL;

/**
 * Set the button `alternateImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the alternateImage.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url NS_REFINED_FOR_SWIFT;

/**
 * Set the button `alternateImage` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the alternateImage.
 * @param placeholder The alternateImage to be set initially, until the alternateImage request finishes.
 * @see sd_setAlternateImageWithURL:placeholderImage:options:
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder NS_REFINED_FOR_SWIFT;

/**
 * Set the button `alternateImage` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the alternateImage.
 * @param placeholder The alternateImage to be set initially, until the alternateImage request finishes.
 * @param options     The options to use when downloading the alternateImage. @see RBWebImageOptions for the possible values.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                            options:(RBWebImageOptions)options NS_REFINED_FOR_SWIFT;

/**
 * Set the button `alternateImage` with an `url`, placeholder, custom options and context.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the alternateImage.
 * @param placeholder The alternateImage to be set initially, until the alternateImage request finishes.
 * @param options     The options to use when downloading the alternateImage. @see RBWebImageOptions for the possible values.
 * @param context     A context contains different options to perform specify changes or processes, see `RBWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                            options:(RBWebImageOptions)options
                            context:(nullable RBWebImageContext *)context;

/**
 * Set the button `alternateImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the alternateImage.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the alternateImage parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the alternateImage was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original alternateImage url.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                          completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `alternateImage` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the alternateImage.
 * @param placeholder    The alternateImage to be set initially, until the alternateImage request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the alternateImage parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the alternateImage was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original alternateImage url.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                          completed:(nullable RBExternalCompletionBlock)completedBlock NS_REFINED_FOR_SWIFT;

/**
 * Set the button `alternateImage` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the alternateImage.
 * @param placeholder    The alternateImage to be set initially, until the alternateImage request finishes.
 * @param options        The options to use when downloading the alternateImage. @see RBWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the alternateImage parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the alternateImage was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original alternateImage url.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                            options:(RBWebImageOptions)options
                          completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `alternateImage` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the alternateImage.
 * @param placeholder    The alternateImage to be set initially, until the alternateImage request finishes.
 * @param options        The options to use when downloading the alternateImage. @see RBWebImageOptions for the possible values.
 * @param progressBlock  A block called while alternateImage is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the alternateImage parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the alternateImage was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original alternateImage url.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                            options:(RBWebImageOptions)options
                           progress:(nullable RBImageLoaderProgressBlock)progressBlock
                          completed:(nullable RBExternalCompletionBlock)completedBlock;

/**
 * Set the button `alternateImage` with an `url`, placeholder, custom options and context.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the alternateImage.
 * @param placeholder    The alternateImage to be set initially, until the alternateImage request finishes.
 * @param options        The options to use when downloading the alternateImage. @see RBWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `RBWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while alternateImage is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the alternateImage parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the alternateImage was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original alternateImage url.
 */
- (void)rb_setAlternateImageWithURL:(nullable NSURL *)url
                   placeholderImage:(nullable UIImage *)placeholder
                            options:(RBWebImageOptions)options
                            context:(nullable RBWebImageContext *)context
                           progress:(nullable RBImageLoaderProgressBlock)progressBlock
                          completed:(nullable RBExternalCompletionBlock)completedBlock;

#pragma mark - Cancel

/**
 * Cancel the current image download
 */
- (void)rb_cancelCurrentImageLoad;

/**
 * Cancel the current alternateImage download
 */
- (void)rb_cancelCurrentAlternateImageLoad;

@end

#endif
