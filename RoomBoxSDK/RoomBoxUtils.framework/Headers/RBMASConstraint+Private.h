//
//  RBMASConstraint+Private.h
//  Masonry
//
//  Created by Nick Tymchenko on 29/04/14.
//  Copyright (c) 2014 cloudling. All rights reserved.
//

#import "RBMASConstraint.h"

@protocol RBMASConstraintDelegate;


@interface RBMASConstraint ()

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	Usually RBMASConstraintMaker but could be a parent RBMASConstraint
 */
@property (nonatomic, weak) id<RBMASConstraintDelegate> delegate;

/**
 *  Based on a provided value type, is equal to calling:
 *  NSNumber - setOffset:
 *  NSValue with CGPoint - setPointOffset:
 *  NSValue with CGSize - setSizeOffset:
 *  NSValue with RBMASEdgeInsets - setInsets:
 */
- (void)setLayoutConstantWithValue:(NSValue *)value;

@end


@interface RBMASConstraint (Abstract)

/**
 *	Sets the constraint relation to given NSLayoutRelation
 *  returns a block which accepts one of the following:
 *    RBMASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (RBMASConstraint * (^)(id, NSLayoutRelation))equalToWithRelation;

/**
 *	Override to set a custom chaining behaviour
 */
- (RBMASConstraint *)addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end


@protocol RBMASConstraintDelegate <NSObject>

/**
 *	Notifies the delegate when the constraint needs to be replaced with another constraint. For example
 *  A RBMASViewConstraint may turn into a RBMASCompositeConstraint when an array is passed to one of the equality blocks
 */
- (void)constraint:(RBMASConstraint *)constraint shouldBeReplacedWithConstraint:(RBMASConstraint *)replacementConstraint;

- (RBMASConstraint *)constraint:(RBMASConstraint *)constraint addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end
