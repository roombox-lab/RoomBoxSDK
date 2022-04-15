//
//  RBTextAttribute.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 14/10/26.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum Define

/// The attribute type
typedef NS_OPTIONS(NSInteger, RBTextAttributeType) {
    RBTextAttributeTypeNone     = 0,
    RBTextAttributeTypeUIKit    = 1 << 0, ///< UIKit attributes, such as UILabel/UITextField/drawInRect.
    RBTextAttributeTypeCoreText = 1 << 1, ///< CoreText attributes, used by CoreText.
    RBTextAttributeTypeYYText   = 1 << 2, ///< YYText attributes, used by YYText.
};

/// Get the attribute type from an attribute name.
extern RBTextAttributeType RBTextAttributeGetType(NSString *attributeName);

/**
 Line style in YYText (similar to NSUnderlineStyle).
 */
typedef NS_OPTIONS (NSInteger, RBTextLineStyle) {
    // basic style (bitmask:0xFF)
    RBTextLineStyleNone       = 0x00, ///< (        ) Do not draw a line (Default).
    RBTextLineStyleSingle     = 0x01, ///< (──────) Draw a single line.
    RBTextLineStyleThick      = 0x02, ///< (━━━━━━━) Draw a thick line.
    RBTextLineStyleDouble     = 0x09, ///< (══════) Draw a double line.
    
    // style pattern (bitmask:0xF00)
    RBTextLineStylePatternSolid      = 0x000, ///< (────────) Draw a solid line (Default).
    RBTextLineStylePatternDot        = 0x100, ///< (‑ ‑ ‑ ‑ ‑ ‑) Draw a line of dots.
    RBTextLineStylePatternDash       = 0x200, ///< (— — — —) Draw a line of dashes.
    RBTextLineStylePatternDashDot    = 0x300, ///< (— ‑ — ‑ — ‑) Draw a line of alternating dashes and dots.
    RBTextLineStylePatternDashDotDot = 0x400, ///< (— ‑ ‑ — ‑ ‑) Draw a line of alternating dashes and two dots.
    RBTextLineStylePatternCircleDot  = 0x900, ///< (••••••••••••) Draw a line of small circle dots.
};

/**
 Text vertical alignment.
 */
typedef NS_ENUM(NSInteger, RBTextVerticalAlignment) {
    RBTextVerticalAlignmentTop =    0, ///< Top alignment.
    RBTextVerticalAlignmentCenter = 1, ///< Center alignment.
    RBTextVerticalAlignmentBottom = 2, ///< Bottom alignment.
};

/**
 The direction define in YYText.
 */
typedef NS_OPTIONS(NSUInteger, RBTextDirection) {
    RBTextDirectionNone   = 0,
    RBTextDirectionTop    = 1 << 0,
    RBTextDirectionRight  = 1 << 1,
    RBTextDirectionBottom = 1 << 2,
    RBTextDirectionLeft   = 1 << 3,
};

/**
 The trunction type, tells the truncation engine which type of truncation is being requested.
 */
typedef NS_ENUM (NSUInteger, RBTextTruncationType) {
    /// No truncate.
    RBTextTruncationTypeNone   = 0,
    
    /// Truncate at the beginning of the line, leaving the end portion visible.
    RBTextTruncationTypeStart  = 1,
    
    /// Truncate at the end of the line, leaving the start portion visible.
    RBTextTruncationTypeEnd    = 2,
    
    /// Truncate in the middle of the line, leaving both the start and the end portions visible.
    RBTextTruncationTypeMiddle = 3,
};



#pragma mark - Attribute Name Defined in YYText

/// The value of this attribute is a `YYTextBackedString` object.
/// Use this attribute to store the original plain text if it is replaced by something else (such as attachment).
UIKIT_EXTERN NSString *const RBTextBackedStringAttributeName;

/// The value of this attribute is a `YYTextBinding` object.
/// Use this attribute to bind a range of text together, as if it was a single charactor.
UIKIT_EXTERN NSString *const RBTextBindingAttributeName;

/// The value of this attribute is a `YYTextShadow` object.
/// Use this attribute to add shadow to a range of text.
/// Shadow will be drawn below text glyphs. Use YYTextShadow.subShadow to add multi-shadow.
UIKIT_EXTERN NSString *const RBTextShadowAttributeName;

/// The value of this attribute is a `YYTextShadow` object.
/// Use this attribute to add inner shadow to a range of text.
/// Inner shadow will be drawn above text glyphs. Use YYTextShadow.subShadow to add multi-shadow.
UIKIT_EXTERN NSString *const RBTextInnerShadowAttributeName;

/// The value of this attribute is a `YYTextDecoration` object.
/// Use this attribute to add underline to a range of text.
/// The underline will be drawn below text glyphs.
UIKIT_EXTERN NSString *const RBTextUnderlineAttributeName;

/// The value of this attribute is a `YYTextDecoration` object.
/// Use this attribute to add strikethrough (delete line) to a range of text.
/// The strikethrough will be drawn above text glyphs.
UIKIT_EXTERN NSString *const RBTextStrikethroughAttributeName;

/// The value of this attribute is a `YYTextBorder` object.
/// Use this attribute to add cover border or cover color to a range of text.
/// The border will be drawn above the text glyphs.
UIKIT_EXTERN NSString *const RBTextBorderAttributeName;

/// The value of this attribute is a `YYTextBorder` object.
/// Use this attribute to add background border or background color to a range of text.
/// The border will be drawn below the text glyphs.
UIKIT_EXTERN NSString *const RBTextBackgroundBorderAttributeName;

/// The value of this attribute is a `YYTextBorder` object.
/// Use this attribute to add a code block border to one or more line of text.
/// The border will be drawn below the text glyphs.
UIKIT_EXTERN NSString *const RBTextBlockBorderAttributeName;

/// The value of this attribute is a `YYTextAttachment` object.
/// Use this attribute to add attachment to text.
/// It should be used in conjunction with a CTRunDelegate.
UIKIT_EXTERN NSString *const RBTextAttachmentAttributeName;

/// The value of this attribute is a `YYTextHighlight` object.
/// Use this attribute to add a touchable highlight state to a range of text.
UIKIT_EXTERN NSString *const RBTextHighlightAttributeName;

/// The value of this attribute is a `NSValue` object stores CGAffineTransform.
/// Use this attribute to add transform to each glyph in a range of text.
UIKIT_EXTERN NSString *const RBTextGlyphTransformAttributeName;



#pragma mark - String Token Define

UIKIT_EXTERN NSString *const RBTextAttachmentToken; ///< Object replacement character (U+FFFC), used for text attachment.
UIKIT_EXTERN NSString *const RBTextTruncationToken; ///< Horizontal ellipsis (U+2026), used for text truncation  "…".



#pragma mark - Attribute Value Define

/**
 The tap/long press action callback defined in YYText.
 
 @param containerView The text container view (such as YYLabel/RBTextView).
 @param text          The whole text.
 @param range         The text range in `text` (if no range, the range.location is NSNotFound).
 @param rect          The text frame in `containerView` (if no data, the rect is CGRectNull).
 */
typedef void(^RBTextAction)(UIView *containerView, NSAttributedString *text, NSRange range, CGRect rect);


/**
 YYTextBackedString objects are used by the NSAttributedString class cluster
 as the values for text backed string attributes (stored in the attributed 
 string under the key named YYTextBackedStringAttributeName).
 
 It may used for copy/paste plain text from attributed string.
 Example: If :) is replace by a custom emoji (such as😊), the backed string can be set to @":)".
 */
@interface RBTextBackedString : NSObject <NSCoding, NSCopying>
+ (instancetype)stringWithString:(nullable NSString *)string;
@property (nullable, nonatomic, copy) NSString *string; ///< backed string
@end


/**
 YYTextBinding objects are used by the NSAttributedString class cluster
 as the values for shadow attributes (stored in the attributed string under
 the key named YYTextBindingAttributeName).
 
 Add this to a range of text will make the specified characters 'binding together'.
 RBTextView will treat the range of text as a single character during text 
 selection and edit.
 */
@interface RBTextBinding : NSObject <NSCoding, NSCopying>
+ (instancetype)bindingWithDeleteConfirm:(BOOL)deleteConfirm;
@property (nonatomic) BOOL deleteConfirm; ///< confirm the range when delete in RBTextView
@end


/**
 YYTextShadow objects are used by the NSAttributedString class cluster
 as the values for shadow attributes (stored in the attributed string under
 the key named YYTextShadowAttributeName or YYTextInnerShadowAttributeName).
 
 It's similar to `NSShadow`, but offers more options.
 */
@interface RBTextShadow : NSObject <NSCoding, NSCopying>
+ (instancetype)shadowWithColor:(nullable UIColor *)color offset:(CGSize)offset radius:(CGFloat)radius;

@property (nullable, nonatomic, strong) UIColor *color; ///< shadow color
@property (nonatomic) CGSize offset;                    ///< shadow offset
@property (nonatomic) CGFloat radius;                   ///< shadow blur radius
@property (nonatomic) CGBlendMode blendMode;            ///< shadow blend mode
@property (nullable, nonatomic, strong) RBTextShadow *subShadow;  ///< a sub shadow which will be added above the parent shadow

+ (instancetype)shadowWithNSShadow:(NSShadow *)nsShadow; ///< convert NSShadow to YYTextShadow
- (NSShadow *)nsShadow; ///< convert YYTextShadow to NSShadow
@end


/**
 YYTextDecorationLine objects are used by the NSAttributedString class cluster
 as the values for decoration line attributes (stored in the attributed string under
 the key named YYTextUnderlineAttributeName or YYTextStrikethroughAttributeName).
 
 When it's used as underline, the line is drawn below text glyphs;
 when it's used as strikethrough, the line is drawn above text glyphs.
 */
@interface RBTextDecoration : NSObject <NSCoding, NSCopying>
+ (instancetype)decorationWithStyle:(RBTextLineStyle)style;
+ (instancetype)decorationWithStyle:(RBTextLineStyle)style width:(nullable NSNumber *)width color:(nullable UIColor *)color;
@property (nonatomic) RBTextLineStyle style;                   ///< line style
@property (nullable, nonatomic, strong) NSNumber *width;       ///< line width (nil means automatic width)
@property (nullable, nonatomic, strong) UIColor *color;        ///< line color (nil means automatic color)
@property (nullable, nonatomic, strong) RBTextShadow *shadow;  ///< line shadow
@end


/**
 YYTextBorder objects are used by the NSAttributedString class cluster
 as the values for border attributes (stored in the attributed string under
 the key named YYTextBorderAttributeName or YYTextBackgroundBorderAttributeName).
 
 It can be used to draw a border around a range of text, or draw a background
 to a range of text.
 
 Example:
    ╭──────╮
    │ Text │
    ╰──────╯
 */
@interface RBTextBorder : NSObject <NSCoding, NSCopying>
+ (instancetype)borderWithLineStyle:(RBTextLineStyle)lineStyle lineWidth:(CGFloat)width strokeColor:(nullable UIColor *)color;
+ (instancetype)borderWithFillColor:(nullable UIColor *)color cornerRadius:(CGFloat)cornerRadius;
@property (nonatomic) RBTextLineStyle lineStyle;              ///< border line style
@property (nonatomic) CGFloat strokeWidth;                    ///< border line width
@property (nullable, nonatomic, strong) UIColor *strokeColor; ///< border line color
@property (nonatomic) CGLineJoin lineJoin;                    ///< border line join
@property (nonatomic) UIEdgeInsets insets;                    ///< border insets for text bounds
@property (nonatomic) CGFloat cornerRadius;                   ///< border corder radius
@property (nullable, nonatomic, strong) RBTextShadow *shadow; ///< border shadow
@property (nullable, nonatomic, strong) UIColor *fillColor;   ///< inner fill color
@end


/**
 YYTextAttachment objects are used by the NSAttributedString class cluster 
 as the values for attachment attributes (stored in the attributed string under 
 the key named YYTextAttachmentAttributeName).
 
 When display an attributed string which contains `YYTextAttachment` object,
 the content will be placed in text metric. If the content is `UIImage`, 
 then it will be drawn to CGContext; if the content is `UIView` or `CALayer`, 
 then it will be added to the text container's view or layer.
 */
@interface RBTextAttachment : NSObject<NSCoding, NSCopying>
+ (instancetype)attachmentWithContent:(nullable id)content;
@property (nullable, nonatomic, strong) id content;             ///< Supported type: UIImage, UIView, CALayer
@property (nonatomic) UIViewContentMode contentMode;            ///< Content display mode.
@property (nonatomic) UIEdgeInsets contentInsets;               ///< The insets when drawing content.
@property (nullable, nonatomic, strong) NSDictionary *userInfo; ///< The user information dictionary.
@end


/**
 YYTextHighlight objects are used by the NSAttributedString class cluster
 as the values for touchable highlight attributes (stored in the attributed string
 under the key named YYTextHighlightAttributeName).
 
 When display an attributed string in `YYLabel` or `RBTextView`, the range of 
 highlight text can be toucheds down by users. If a range of text is turned into 
 highlighted state, the `attributes` in `YYTextHighlight` will be used to modify 
 (set or remove) the original attributes in the range for display.
 */
@interface RBTextHighlight : NSObject <NSCoding, NSCopying>

/**
 Attributes that you can apply to text in an attributed string when highlight.
 Key:   Same as CoreText/YYText Attribute Name.
 Value: Modify attribute value when highlight (NSNull for remove attribute).
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, id> *attributes;

/**
 Creates a highlight object with specified attributes.
 
 @param attributes The attributes which will replace original attributes when highlight,
        If the value is NSNull, it will removed when highlight.
 */
+ (instancetype)highlightWithAttributes:(nullable NSDictionary<NSString *, id> *)attributes;

/**
 Convenience methods to create a default highlight with the specifeid background color.
 
 @param color The background border color.
 */
+ (instancetype)highlightWithBackgroundColor:(nullable UIColor *)color;

// Convenience methods below to set the `attributes`.
- (void)setFont:(nullable UIFont *)font;
- (void)setColor:(nullable UIColor *)color;
- (void)setStrokeWidth:(nullable NSNumber *)width;
- (void)setStrokeColor:(nullable UIColor *)color;
- (void)setShadow:(nullable RBTextShadow *)shadow;
- (void)setInnerShadow:(nullable RBTextShadow *)shadow;
- (void)setUnderline:(nullable RBTextDecoration *)underline;
- (void)setStrikethrough:(nullable RBTextDecoration *)strikethrough;
- (void)setBackgroundBorder:(nullable RBTextBorder *)border;
- (void)setBorder:(nullable RBTextBorder *)border;
- (void)setAttachment:(nullable RBTextAttachment *)attachment;

/**
 The user information dictionary, default is nil.
 */
@property (nullable, nonatomic, copy) NSDictionary *userInfo;

/**
 Tap action when user tap the highlight, default is nil.
 If the value is nil, RBTextView or YYLabel will ask it's delegate to handle the tap action.
 */
@property (nullable, nonatomic, copy) RBTextAction tapAction;

/**
 Long press action when user long press the highlight, default is nil.
 If the value is nil, RBTextView or YYLabel will ask it's delegate to handle the long press action.
 */
@property (nullable, nonatomic, copy) RBTextAction longPressAction;

@end

NS_ASSUME_NONNULL_END
