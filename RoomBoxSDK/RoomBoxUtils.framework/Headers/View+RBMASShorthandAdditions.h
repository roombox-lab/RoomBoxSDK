//
//  UIView+RBMASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "View+RBMASAdditions.h"

#ifdef RBMAS_SHORTHAND

/**
 *	Shorthand view additions without the 'mas_' prefixes,
 *  only enabled if RBMAS_SHORTHAND is defined
 */
@interface RBMAS_VIEW (RBMASShorthandAdditions)

@property (nonatomic, strong, readonly) RBMASViewAttribute *left;
@property (nonatomic, strong, readonly) RBMASViewAttribute *top;
@property (nonatomic, strong, readonly) RBMASViewAttribute *right;
@property (nonatomic, strong, readonly) RBMASViewAttribute *bottom;
@property (nonatomic, strong, readonly) RBMASViewAttribute *leading;
@property (nonatomic, strong, readonly) RBMASViewAttribute *trailing;
@property (nonatomic, strong, readonly) RBMASViewAttribute *width;
@property (nonatomic, strong, readonly) RBMASViewAttribute *height;
@property (nonatomic, strong, readonly) RBMASViewAttribute *centerX;
@property (nonatomic, strong, readonly) RBMASViewAttribute *centerY;
@property (nonatomic, strong, readonly) RBMASViewAttribute *baseline;
@property (nonatomic, strong, readonly) RBMASViewAttribute *(^attribute)(NSLayoutAttribute attr);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) RBMASViewAttribute *firstBaseline;
@property (nonatomic, strong, readonly) RBMASViewAttribute *lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) RBMASViewAttribute *leftMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *rightMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *topMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *bottomMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *leadingMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *trailingMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *centerXWithinMargins;
@property (nonatomic, strong, readonly) RBMASViewAttribute *centerYWithinMargins;

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

@property (nonatomic, strong, readonly) RBMASViewAttribute *safeAreaLayoutGuideTop API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *safeAreaLayoutGuideBottom API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *safeAreaLayoutGuideLeft API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *safeAreaLayoutGuideRight API_AVAILABLE(ios(11.0),tvos(11.0));

#endif

- (NSArray *)makeConstraints:(void(^)(RBMASConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(RBMASConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(RBMASConstraintMaker *make))block;

@end

#define RBMAS_ATTR_FORWARD(attr)  \
- (RBMASViewAttribute *)attr {    \
    return [self mas_##attr];   \
}

@implementation RBMAS_VIEW (RBMASShorthandAdditions)

RBMAS_ATTR_FORWARD(top);
RBMAS_ATTR_FORWARD(left);
RBMAS_ATTR_FORWARD(bottom);
RBMAS_ATTR_FORWARD(right);
RBMAS_ATTR_FORWARD(leading);
RBMAS_ATTR_FORWARD(trailing);
RBMAS_ATTR_FORWARD(width);
RBMAS_ATTR_FORWARD(height);
RBMAS_ATTR_FORWARD(centerX);
RBMAS_ATTR_FORWARD(centerY);
RBMAS_ATTR_FORWARD(baseline);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

RBMAS_ATTR_FORWARD(firstBaseline);
RBMAS_ATTR_FORWARD(lastBaseline);

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

RBMAS_ATTR_FORWARD(leftMargin);
RBMAS_ATTR_FORWARD(rightMargin);
RBMAS_ATTR_FORWARD(topMargin);
RBMAS_ATTR_FORWARD(bottomMargin);
RBMAS_ATTR_FORWARD(leadingMargin);
RBMAS_ATTR_FORWARD(trailingMargin);
RBMAS_ATTR_FORWARD(centerXWithinMargins);
RBMAS_ATTR_FORWARD(centerYWithinMargins);

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

RBMAS_ATTR_FORWARD(safeAreaLayoutGuideTop);
RBMAS_ATTR_FORWARD(safeAreaLayoutGuideBottom);
RBMAS_ATTR_FORWARD(safeAreaLayoutGuideLeft);
RBMAS_ATTR_FORWARD(safeAreaLayoutGuideRight);

#endif

- (RBMASViewAttribute *(^)(NSLayoutAttribute))attribute {
    return [self mas_attribute];
}

- (NSArray *)makeConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
