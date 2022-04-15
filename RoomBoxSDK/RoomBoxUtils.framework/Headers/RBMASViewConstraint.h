//
//  RBMASViewConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RBMASViewAttribute.h"
#import "RBMASConstraint.h"
#import "RBMASLayoutConstraint.h"
#import "RBMASUtilities.h"

/**
 *  A single constraint.
 *  Contains the attributes neccessary for creating a NSLayoutConstraint and adding it to the appropriate view
 */
@interface RBMASViewConstraint : RBMASConstraint <NSCopying>

/**
 *	First item/view and first attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) RBMASViewAttribute *firstViewAttribute;

/**
 *	Second item/view and second attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) RBMASViewAttribute *secondViewAttribute;

/**
 *	initialises the RBMASViewConstraint with the first part of the equation
 *
 *	@param	firstViewAttribute	view.mas_left, view.mas_width etc.
 *
 *	@return	a new view constraint
 */
- (id)initWithFirstViewAttribute:(RBMASViewAttribute *)firstViewAttribute;

/**
 *  Returns all RBMASViewConstraints installed with this view as a first item.
 *
 *  @param  view  A view to retrieve constraints for.
 *
 *  @return An array of RBMASViewConstraints.
 */
+ (NSArray *)installedConstraintsForView:(RBMAS_VIEW *)view;

@end
