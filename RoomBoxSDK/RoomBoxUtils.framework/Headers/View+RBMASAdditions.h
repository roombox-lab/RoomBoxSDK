//
//  UIView+RBMASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RBMASUtilities.h"
#import "RBMASConstraintMaker.h"
#import "RBMASViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating RBMASViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface RBMAS_VIEW (RBMASAdditions)

/**
 *	following properties return a new RBMASViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_left;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_top;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_right;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_bottom;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_leading;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_trailing;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_width;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_height;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_centerX;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_centerY;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_baseline;
@property (nonatomic, strong, readonly) RBMASViewAttribute *(^mas_attribute)(NSLayoutAttribute attr);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_firstBaseline;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_leftMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_rightMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_topMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_bottomMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_leadingMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_trailingMargin;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_centerXWithinMargins;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_centerYWithinMargins;

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_safeAreaLayoutGuide API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_safeAreaLayoutGuideTop API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_safeAreaLayoutGuideBottom API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_safeAreaLayoutGuideLeft API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_safeAreaLayoutGuideRight API_AVAILABLE(ios(11.0),tvos(11.0));

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)mas_closestCommonSuperview:(RBMAS_VIEW *)view;

/**
 *  Creates a RBMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created RBMASConstraints
 */
- (NSArray *)mas_makeConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *make))block;

/**
 *  Creates a RBMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated RBMASConstraints
 */
- (NSArray *)mas_updateConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *make))block;

/**
 *  Creates a RBMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated RBMASConstraints
 */
- (NSArray *)mas_remakeConstraints:(void(NS_NOESCAPE ^)(RBMASConstraintMaker *make))block;

@end
