//
//  RBMASConstraintMaker.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RBMASConstraint.h"
#import "RBMASUtilities.h"

typedef NS_OPTIONS(NSInteger, RBMASAttribute) {
    RBMASAttributeLeft = 1 << NSLayoutAttributeLeft,
    RBMASAttributeRight = 1 << NSLayoutAttributeRight,
    RBMASAttributeTop = 1 << NSLayoutAttributeTop,
    RBMASAttributeBottom = 1 << NSLayoutAttributeBottom,
    RBMASAttributeLeading = 1 << NSLayoutAttributeLeading,
    RBMASAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    RBMASAttributeWidth = 1 << NSLayoutAttributeWidth,
    RBMASAttributeHeight = 1 << NSLayoutAttributeHeight,
    RBMASAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    RBMASAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    RBMASAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    
    RBMASAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    RBMASAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#endif
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)
    
    RBMASAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    RBMASAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    RBMASAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    RBMASAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    RBMASAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    RBMASAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    RBMASAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    RBMASAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating RBMASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface RBMASConstraintMaker : NSObject

/**
 *	The following properties return a new RBMASViewConstraint
 *  with the first item set to the makers associated view and the appropriate RBMASViewAttribute
 */
@property (nonatomic, strong, readonly) RBMASConstraint *left;
@property (nonatomic, strong, readonly) RBMASConstraint *top;
@property (nonatomic, strong, readonly) RBMASConstraint *right;
@property (nonatomic, strong, readonly) RBMASConstraint *bottom;
@property (nonatomic, strong, readonly) RBMASConstraint *leading;
@property (nonatomic, strong, readonly) RBMASConstraint *trailing;
@property (nonatomic, strong, readonly) RBMASConstraint *width;
@property (nonatomic, strong, readonly) RBMASConstraint *height;
@property (nonatomic, strong, readonly) RBMASConstraint *centerX;
@property (nonatomic, strong, readonly) RBMASConstraint *centerY;
@property (nonatomic, strong, readonly) RBMASConstraint *baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) RBMASConstraint *firstBaseline;
@property (nonatomic, strong, readonly) RBMASConstraint *lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) RBMASConstraint *leftMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *rightMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *topMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *bottomMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *leadingMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *trailingMargin;
@property (nonatomic, strong, readonly) RBMASConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) RBMASConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new RBMASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  RBMASAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) RBMASConstraint *(^attributes)(RBMASAttribute attrs);

/**
 *	Creates a RBMASCompositeConstraint with type RBMASCompositeConstraintTypeEdges
 *  which generates the appropriate RBMASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RBMASConstraint *edges;

/**
 *	Creates a RBMASCompositeConstraint with type RBMASCompositeConstraintTypeSize
 *  which generates the appropriate RBMASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RBMASConstraint *size;

/**
 *	Creates a RBMASCompositeConstraint with type RBMASCompositeConstraintTypeCenter
 *  which generates the appropriate RBMASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RBMASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any RBMASConstraint are created with this view as the first item
 *
 *	@return	a new RBMASConstraintMaker
 */
- (id)initWithView:(RBMAS_VIEW *)view;

/**
 *	Calls install method on any RBMASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed RBMASConstraints
 */
- (NSArray *)install;

- (RBMASConstraint * (^)(dispatch_block_t))group;

@end
