//
//  YYTextLine.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 15/3/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

#import "RBTextAttribute.h"


@class RBTextRunGlyphRange;

NS_ASSUME_NONNULL_BEGIN

/**
 A text line object wrapped `CTLineRef`, see `YYTextLayout` for more.
 */
@interface RBTextLine : NSObject

+ (instancetype)lineWithCTLine:(CTLineRef)CTLine position:(CGPoint)position vertical:(BOOL)isVertical;

@property (nonatomic) NSUInteger index;     ///< line index
@property (nonatomic) NSUInteger row;       ///< line row
@property (nullable, nonatomic, strong) NSArray<NSArray<RBTextRunGlyphRange *> *> *verticalRotateRange; ///< Run rotate range

@property (nonatomic, readonly) CTLineRef CTLine;   ///< CoreText line
@property (nonatomic, readonly) NSRange range;      ///< string range
@property (nonatomic, readonly) BOOL vertical;      ///< vertical form

@property (nonatomic, readonly) CGRect bounds;      ///< bounds (ascent + descent)
@property (nonatomic, readonly) CGSize size;        ///< bounds.size
@property (nonatomic, readonly) CGFloat width;      ///< bounds.size.width
@property (nonatomic, readonly) CGFloat height;     ///< bounds.size.height
@property (nonatomic, readonly) CGFloat top;        ///< bounds.origin.y
@property (nonatomic, readonly) CGFloat bottom;     ///< bounds.origin.y + bounds.size.height
@property (nonatomic, readonly) CGFloat left;       ///< bounds.origin.x
@property (nonatomic, readonly) CGFloat right;      ///< bounds.origin.x + bounds.size.width

@property (nonatomic)   CGPoint position;   ///< baseline position
@property (nonatomic, readonly) CGFloat ascent;     ///< line ascent
@property (nonatomic, readonly) CGFloat descent;    ///< line descent
@property (nonatomic, readonly) CGFloat leading;    ///< line leading
@property (nonatomic, readonly) CGFloat lineWidth;  ///< line width
@property (nonatomic, readonly) CGFloat trailingWhitespaceWidth;

@property (nullable, nonatomic, readonly) NSArray<RBTextAttachment *> *attachments; ///< YYTextAttachment
@property (nullable, nonatomic, readonly) NSArray<NSValue *> *attachmentRanges;     ///< NSRange(NSValue)
@property (nullable, nonatomic, readonly) NSArray<NSValue *> *attachmentRects;      ///< CGRect(NSValue)

@end


typedef NS_ENUM(NSUInteger, RBTextRunGlyphDrawMode) {
    /// No rotate.
    RBTextRunGlyphDrawModeHorizontal = 0,
    
    /// Rotate vertical for single glyph.
    RBTextRunGlyphDrawModeVerticalRotate = 1,
    
    /// Rotate vertical for single glyph, and move the glyph to a better position,
    /// such as fullwidth punctuation.
    RBTextRunGlyphDrawModeVerticalRotateMove = 2,
};

/**
 A range in CTRun, used for vertical form.
 */
@interface RBTextRunGlyphRange : NSObject
@property (nonatomic) NSRange glyphRangeInRun;
@property (nonatomic) RBTextRunGlyphDrawMode drawMode;
+ (instancetype)rangeWithRange:(NSRange)range drawMode:(RBTextRunGlyphDrawMode)mode;
@end

NS_ASSUME_NONNULL_END
