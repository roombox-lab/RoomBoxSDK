//
//  RBMASCompositeConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 21/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RBMASConstraint.h"
#import "RBMASUtilities.h"

/**
 *	A group of RBMASConstraint objects
 */
@interface RBMASCompositeConstraint : RBMASConstraint

/**
 *	Creates a composite with a predefined array of children
 *
 *	@param	children	child RBMASConstraints
 *
 *	@return	a composite constraint
 */
- (id)initWithChildren:(NSArray *)children;

@end
