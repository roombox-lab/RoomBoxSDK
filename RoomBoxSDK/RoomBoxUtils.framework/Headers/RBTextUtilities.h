//
//  RBTextUtilities.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 15/4/6.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreText/CoreText.h>


#ifndef RBTEXT_CLAMP // return the clamped value
#define RBTEXT_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

#ifndef RBTEXT_SWAP // swap two value
#define RBTEXT_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 Whether the character is 'line break char':
 U+000D (\\r or CR)
 U+2028 (Unicode line separator)
 U+000A (\\n or LF)
 U+2029 (Unicode paragraph separator)
 
 @param c  A character
 @return YES or NO.
 */
static inline BOOL RBTextIsLinebreakChar(unichar c) {
    switch (c) {
        case 0x000D:
        case 0x2028:
        case 0x000A:
        case 0x2029:
            return YES;
        default:
            return NO;
    }
}

/**
 Whether the string is a 'line break':
 U+000D (\\r or CR)
 U+2028 (Unicode line separator)
 U+000A (\\n or LF)
 U+2029 (Unicode paragraph separator)
 \\r\\n, in that order (also known as CRLF)
 
 @param str A string
 @return YES or NO.
 */
static inline BOOL RBTextIsLinebreakString(NSString * _Nullable str) {
    if (str.length > 2 || str.length == 0) return NO;
    if (str.length == 1) {
        unichar c = [str characterAtIndex:0];
        return RBTextIsLinebreakChar(c);
    } else {
        return ([str characterAtIndex:0] == '\r') && ([str characterAtIndex:1] == '\n');
    }
}

/**
 If the string has a 'line break' suffix, return the 'line break' length.
 
 @param str  A string.
 @return The length of the tail line break: 0, 1 or 2.
 */
static inline NSUInteger RBTextLinebreakTailLength(NSString * _Nullable str) {
    if (str.length >= 2) {
        unichar c2 = [str characterAtIndex:str.length - 1];
        if (RBTextIsLinebreakChar(c2)) {
            unichar c1 = [str characterAtIndex:str.length - 2];
            if (c1 == '\r' && c2 == '\n') return 2;
            else return 1;
        } else {
            return 0;
        }
    } else if (str.length == 1) {
        return RBTextIsLinebreakChar([str characterAtIndex:0]) ? 1 : 0;
    } else {
        return 0;
    }
}

/**
 Convert `UIDataDetectorTypes` to `NSTextCheckingType`.
 
 @param types  The `UIDataDetectorTypes` type.
 @return The `NSTextCheckingType` type.
 */
static inline NSTextCheckingType RBTextNSTextCheckingTypeFromUIDataDetectorType(UIDataDetectorTypes types) {
    NSTextCheckingType t = 0;
    if (types & UIDataDetectorTypePhoneNumber) t |= NSTextCheckingTypePhoneNumber;
    if (types & UIDataDetectorTypeLink) t |= NSTextCheckingTypeLink;
    if (types & UIDataDetectorTypeAddress) t |= NSTextCheckingTypeAddress;
    if (types & UIDataDetectorTypeCalendarEvent) t |= NSTextCheckingTypeDate;
    return t;
}

/**
 Whether the font is `AppleColorEmoji` font.
 
 @param font  A font.
 @return YES: the font is Emoji, NO: the font is not Emoji.
 */
static inline BOOL RBTextUIFontIsEmoji(UIFont *font) {
    return [font.fontName isEqualToString:@"AppleColorEmoji"];
}

/**
 Whether the font is `AppleColorEmoji` font.
 
 @param font  A font.
 @return YES: the font is Emoji, NO: the font is not Emoji.
 */
static inline BOOL RBTextCTFontIsEmoji(CTFontRef font) {
    BOOL isEmoji = NO;
    CFStringRef name = CTFontCopyPostScriptName(font);
    if (name && CFEqual(CFSTR("AppleColorEmoji"), name)) isEmoji = YES;
    if (name) CFRelease(name);
    return isEmoji;
}

/**
 Whether the font is `AppleColorEmoji` font.
 
 @param font  A font.
 @return YES: the font is Emoji, NO: the font is not Emoji.
 */
static inline BOOL RBTextCGFontIsEmoji(CGFontRef font) {
    BOOL isEmoji = NO;
    CFStringRef name = CGFontCopyPostScriptName(font);
    if (name && CFEqual(CFSTR("AppleColorEmoji"), name)) isEmoji = YES;
    if (name) CFRelease(name);
    return isEmoji;
}

/**
 Whether the font contains color bitmap glyphs.
 
 @discussion Only `AppleColorEmoji` contains color bitmap glyphs in iOS system fonts.
 @param font  A font.
 @return YES: the font contains color bitmap glyphs, NO: the font has no color bitmap glyph.
 */
static inline BOOL RBTextCTFontContainsColorBitmapGlyphs(CTFontRef font) {
    return  (CTFontGetSymbolicTraits(font) & kCTFontTraitColorGlyphs) != 0;
}

/**
 Whether the glyph is bitmap.
 
 @param font  The glyph's font.
 @param glyph The glyph which is created from the specified font.
 @return YES: the glyph is bitmap, NO: the glyph is vector.
 */
static inline BOOL RBTextCGGlyphIsBitmap(CTFontRef font, CGGlyph glyph) {
    if (!font && !glyph) return NO;
    if (!RBTextCTFontContainsColorBitmapGlyphs(font)) return NO;
    CGPathRef path = CTFontCreatePathForGlyph(font, glyph, NULL);
    if (path) {
        CFRelease(path);
        return NO;
    }
    return YES;
}

/**
 Get the `AppleColorEmoji` font's ascent with a specified font size.
 It may used to create custom emoji.
 
 @param fontSize  The specified font size.
 @return The font ascent.
 */
static inline CGFloat RBTextEmojiGetAscentWithFontSize(CGFloat fontSize) {
    if (fontSize < 16) {
        return 1.25 * fontSize;
    } else if (16 <= fontSize && fontSize <= 24) {
        return 0.5 * fontSize + 12;
    } else {
        return fontSize;
    }
}

/**
 Get the `AppleColorEmoji` font's descent with a specified font size.
 It may used to create custom emoji.
 
 @param fontSize  The specified font size.
 @return The font descent.
 */
static inline CGFloat RBTextEmojiGetDescentWithFontSize(CGFloat fontSize) {
    if (fontSize < 16) {
        return 0.390625 * fontSize;
    } else if (16 <= fontSize && fontSize <= 24) {
        return 0.15625 * fontSize + 3.75;
    } else {
        return 0.3125 * fontSize;
    }
    return 0;
}

/**
 Get the `AppleColorEmoji` font's glyph bounding rect with a specified font size.
 It may used to create custom emoji.
 
 @param fontSize  The specified font size.
 @return The font glyph bounding rect.
 */
static inline CGRect RBTextEmojiGetGlyphBoundingRectWithFontSize(CGFloat fontSize) {
    CGRect rect;
    rect.origin.x = 0.75;
    rect.size.width = rect.size.height = RBTextEmojiGetAscentWithFontSize(fontSize);
    if (fontSize < 16) {
        rect.origin.y = -0.2525 * fontSize;
    } else if (16 <= fontSize && fontSize <= 24) {
        rect.origin.y = 0.1225 * fontSize -6;
    } else {
        rect.origin.y = -0.1275 * fontSize;
    }
    return rect;
}


/**
 Get the character set which should rotate in vertical form.
 @return The shared character set.
 */
NSCharacterSet *RBTextVerticalFormRotateCharacterSet();

/**
 Get the character set which should rotate and move in vertical form.
 @return The shared character set.
 */
NSCharacterSet *RBTextVerticalFormRotateAndMoveCharacterSet();



/// Convert degrees to radians.
static inline CGFloat RBTextDegreesToRadians(CGFloat degrees) {
    return degrees * M_PI / 180;
}

/// Convert radians to degrees.
static inline CGFloat RBTextRadiansToDegrees(CGFloat radians) {
    return radians * 180 / M_PI;
}



/// Get the transform rotation.
/// @return the rotation in radians [-PI,PI] ([-180°,180°])
static inline CGFloat RBTextCGAffineTransformGetRotation(CGAffineTransform transform) {
    return atan2(transform.b, transform.a);
}

/// Get the transform's scale.x
static inline CGFloat RBTextCGAffineTransformGetScaleX(CGAffineTransform transform) {
    return  sqrt(transform.a * transform.a + transform.c * transform.c);
}

/// Get the transform's scale.y
static inline CGFloat RBTextCGAffineTransformGetScaleY(CGAffineTransform transform) {
    return sqrt(transform.b * transform.b + transform.d * transform.d);
}

/// Get the transform's translate.x
static inline CGFloat RBTextCGAffineTransformGetTranslateX(CGAffineTransform transform) {
    return transform.tx;
}

/// Get the transform's translate.y
static inline CGFloat RBTextCGAffineTransformGetTranslateY(CGAffineTransform transform) {
    return transform.ty;
}

/**
 If you have 3 pair of points transformed by a same CGAffineTransform:
 p1 (transform->) q1
 p2 (transform->) q2
 p3 (transform->) q3
 This method returns the original transform matrix from these 3 pair of points.
 
 @see http://stackoverflow.com/questions/13291796/calculate-values-for-a-cgaffinetransform-from-three-points-in-each-of-two-uiview
 */
CGAffineTransform RBTextCGAffineTransformGetFromPoints(CGPoint before[_Nullable 3], CGPoint after[_Nullable 3]);

/// Get the transform which can converts a point from the coordinate system of a given view to another.
CGAffineTransform RBTextCGAffineTransformGetFromViews(UIView *from, UIView *to);

/// Create a skew transform.
static inline CGAffineTransform RBTextCGAffineTransformMakeSkew(CGFloat x, CGFloat y){
    CGAffineTransform transform = CGAffineTransformIdentity;
    transform.c = -x;
    transform.b = y;
    return transform;
}

/// Negates/inverts a UIEdgeInsets.
static inline UIEdgeInsets RBTextUIEdgeInsetsInvert(UIEdgeInsets insets) {
    return UIEdgeInsetsMake(-insets.top, -insets.left, -insets.bottom, -insets.right);
}

/// Convert CALayer's gravity string to UIViewContentMode.
UIViewContentMode RBTextCAGravityToUIViewContentMode(NSString *gravity);

/// Convert UIViewContentMode to CALayer's gravity string.
NSString *RBTextUIViewContentModeToCAGravity(UIViewContentMode contentMode);



/**
 Returns a rectangle to fit the `rect` with specified content mode.
 
 @param rect The constrant rect
 @param size The content size
 @param mode The content mode
 @return A rectangle for the given content mode.
 @discussion UIViewContentModeRedraw is same as UIViewContentModeScaleToFill.
 */
CGRect RBTextCGRectFitWithContentMode(CGRect rect, CGSize size, UIViewContentMode mode);

/// Returns the center for the rectangle.
static inline CGPoint RBTextCGRectGetCenter(CGRect rect) {
    return CGPointMake(CGRectGetMidX(rect), CGRectGetMidY(rect));
}

/// Returns the area of the rectangle.
static inline CGFloat RBTextCGRectGetArea(CGRect rect) {
    if (CGRectIsNull(rect)) return 0;
    rect = CGRectStandardize(rect);
    return rect.size.width * rect.size.height;
}

/// Returns the distance between two points.
static inline CGFloat RBTextCGPointGetDistanceToPoint(CGPoint p1, CGPoint p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

/// Returns the minmium distance between a point to a rectangle.
static inline CGFloat RBTextCGPointGetDistanceToRect(CGPoint p, CGRect r) {
    r = CGRectStandardize(r);
    if (CGRectContainsPoint(r, p)) return 0;
    CGFloat distV, distH;
    if (CGRectGetMinY(r) <= p.y && p.y <= CGRectGetMaxY(r)) {
        distV = 0;
    } else {
        distV = p.y < CGRectGetMinY(r) ? CGRectGetMinY(r) - p.y : p.y - CGRectGetMaxY(r);
    }
    if (CGRectGetMinX(r) <= p.x && p.x <= CGRectGetMaxX(r)) {
        distH = 0;
    } else {
        distH = p.x < CGRectGetMinX(r) ? CGRectGetMinX(r) - p.x : p.x - CGRectGetMaxX(r);
    }
    return MAX(distV, distH);
}


/// Get main screen's scale.
CGFloat RBTextScreenScale();

/// Get main screen's size. Height is always larger than width.
CGSize RBTextScreenSize();

/// Convert point to pixel.
static inline CGFloat RBTextCGFloatToPixel(CGFloat value) {
    return value * RBTextScreenScale();
}

/// Convert pixel to point.
static inline CGFloat RBTextCGFloatFromPixel(CGFloat value) {
    return value / RBTextScreenScale();
}

/// floor point value for pixel-aligned
static inline CGFloat RBTextCGFloatPixelFloor(CGFloat value) {
    CGFloat scale = RBTextScreenScale();
    return floor(value * scale) / scale;
}

/// round point value for pixel-aligned
static inline CGFloat RBTextCGFloatPixelRound(CGFloat value) {
    CGFloat scale = RBTextScreenScale();
    return round(value * scale) / scale;
}

/// ceil point value for pixel-aligned
static inline CGFloat RBTextCGFloatPixelCeil(CGFloat value) {
    CGFloat scale = RBTextScreenScale();
    return ceil(value * scale) / scale;
}

/// round point value to .5 pixel for path stroke (odd pixel line width pixel-aligned)
static inline CGFloat RBTextCGFloatPixelHalf(CGFloat value) {
    CGFloat scale = RBTextScreenScale();
    return (floor(value * scale) + 0.5) / scale;
}

/// floor point value for pixel-aligned
static inline CGPoint RBTextCGPointPixelFloor(CGPoint point) {
    CGFloat scale = RBTextScreenScale();
    return CGPointMake(floor(point.x * scale) / scale,
                       floor(point.y * scale) / scale);
}

/// round point value for pixel-aligned
static inline CGPoint RBTextCGPointPixelRound(CGPoint point) {
    CGFloat scale = RBTextScreenScale();
    return CGPointMake(round(point.x * scale) / scale,
                       round(point.y * scale) / scale);
}

/// ceil point value for pixel-aligned
static inline CGPoint RBTextCGPointPixelCeil(CGPoint point) {
    CGFloat scale = RBTextScreenScale();
    return CGPointMake(ceil(point.x * scale) / scale,
                       ceil(point.y * scale) / scale);
}

/// round point value to .5 pixel for path stroke (odd pixel line width pixel-aligned)
static inline CGPoint RBTextCGPointPixelHalf(CGPoint point) {
    CGFloat scale = RBTextScreenScale();
    return CGPointMake((floor(point.x * scale) + 0.5) / scale,
                       (floor(point.y * scale) + 0.5) / scale);
}



/// floor point value for pixel-aligned
static inline CGSize RBTextCGSizePixelFloor(CGSize size) {
    CGFloat scale = RBTextScreenScale();
    return CGSizeMake(floor(size.width * scale) / scale,
                      floor(size.height * scale) / scale);
}

/// round point value for pixel-aligned
static inline CGSize RBTextCGSizePixelRound(CGSize size) {
    CGFloat scale = RBTextScreenScale();
    return CGSizeMake(round(size.width * scale) / scale,
                      round(size.height * scale) / scale);
}

/// ceil point value for pixel-aligned
static inline CGSize RBTextCGSizePixelCeil(CGSize size) {
    CGFloat scale = RBTextScreenScale();
    return CGSizeMake(ceil(size.width * scale) / scale,
                      ceil(size.height * scale) / scale);
}

/// round point value to .5 pixel for path stroke (odd pixel line width pixel-aligned)
static inline CGSize RBTextCGSizePixelHalf(CGSize size) {
    CGFloat scale = RBTextScreenScale();
    return CGSizeMake((floor(size.width * scale) + 0.5) / scale,
                      (floor(size.height * scale) + 0.5) / scale);
}



/// floor point value for pixel-aligned
static inline CGRect RBTextCGRectPixelFloor(CGRect rect) {
    CGPoint origin = RBTextCGPointPixelCeil(rect.origin);
    CGPoint corner = RBTextCGPointPixelFloor(CGPointMake(rect.origin.x + rect.size.width,
                                                     rect.origin.y + rect.size.height));
    CGRect ret = CGRectMake(origin.x, origin.y, corner.x - origin.x, corner.y - origin.y);
    if (ret.size.width < 0) ret.size.width = 0;
    if (ret.size.height < 0) ret.size.height = 0;
    return ret;
}

/// round point value for pixel-aligned
static inline CGRect RBTextCGRectPixelRound(CGRect rect) {
    CGPoint origin = RBTextCGPointPixelRound(rect.origin);
    CGPoint corner = RBTextCGPointPixelRound(CGPointMake(rect.origin.x + rect.size.width,
                                                     rect.origin.y + rect.size.height));
    return CGRectMake(origin.x, origin.y, corner.x - origin.x, corner.y - origin.y);
}

/// ceil point value for pixel-aligned
static inline CGRect RBTextCGRectPixelCeil(CGRect rect) {
    CGPoint origin = RBTextCGPointPixelFloor(rect.origin);
    CGPoint corner = RBTextCGPointPixelCeil(CGPointMake(rect.origin.x + rect.size.width,
                                                    rect.origin.y + rect.size.height));
    return CGRectMake(origin.x, origin.y, corner.x - origin.x, corner.y - origin.y);
}

/// round point value to .5 pixel for path stroke (odd pixel line width pixel-aligned)
static inline CGRect RBTextCGRectPixelHalf(CGRect rect) {
    CGPoint origin = RBTextCGPointPixelHalf(rect.origin);
    CGPoint corner = RBTextCGPointPixelHalf(CGPointMake(rect.origin.x + rect.size.width,
                                                    rect.origin.y + rect.size.height));
    return CGRectMake(origin.x, origin.y, corner.x - origin.x, corner.y - origin.y);
}



/// floor UIEdgeInset for pixel-aligned
static inline UIEdgeInsets RBTextUIEdgeInsetPixelFloor(UIEdgeInsets insets) {
    insets.top = RBTextCGFloatPixelFloor(insets.top);
    insets.left = RBTextCGFloatPixelFloor(insets.left);
    insets.bottom = RBTextCGFloatPixelFloor(insets.bottom);
    insets.right = RBTextCGFloatPixelFloor(insets.right);
    return insets;
}

/// ceil UIEdgeInset for pixel-aligned
static inline UIEdgeInsets RBTextUIEdgeInsetPixelCeil(UIEdgeInsets insets) {
    insets.top = RBTextCGFloatPixelCeil(insets.top);
    insets.left = RBTextCGFloatPixelCeil(insets.left);
    insets.bottom = RBTextCGFloatPixelCeil(insets.bottom);
    insets.right = RBTextCGFloatPixelCeil(insets.right);
    return insets;
}



static inline UIFont * _Nullable RBTextFontWithBold(UIFont *font) {
    if (![font respondsToSelector:@selector(fontDescriptor)]) return font;
    return [UIFont fontWithDescriptor:[font.fontDescriptor fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitBold] size:font.pointSize];
}

static inline UIFont * _Nullable RBTextFontWithItalic(UIFont *font) {
    if (![font respondsToSelector:@selector(fontDescriptor)]) return font;
    return [UIFont fontWithDescriptor:[font.fontDescriptor fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitItalic] size:font.pointSize];
}

static inline UIFont * _Nullable RBTextFontWithBoldItalic(UIFont *font) {
    if (![font respondsToSelector:@selector(fontDescriptor)]) return font;
    return [UIFont fontWithDescriptor:[font.fontDescriptor fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitBold | UIFontDescriptorTraitItalic] size:font.pointSize];
}



/**
 Convert CFRange to NSRange
 @param range CFRange @return NSRange
 */
static inline NSRange RBTextNSRangeFromCFRange(CFRange range) {
    return NSMakeRange(range.location, range.length);
}

/**
 Convert NSRange to CFRange
 @param range NSRange @return CFRange
 */
static inline CFRange RBTextCFRangeFromNSRange(NSRange range) {
    return CFRangeMake(range.location, range.length);
}


/// Returns YES in App Extension.
BOOL RBTextIsAppExtension();

/// Returns nil in App Extension.
UIApplication * _Nullable RBTextSharedApplication();

NS_ASSUME_NONNULL_END
