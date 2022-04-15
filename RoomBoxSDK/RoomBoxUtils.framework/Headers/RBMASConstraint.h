//
//  RBMASConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RBMASUtilities.h"

/**
 *	Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (RBMASViewConstraint) 
 *  or a group of NSLayoutConstraints (RBMASComposisteConstraint)
 */
@interface RBMASConstraint : NSObject

// Chaining Support

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (RBMASConstraint * (^)(RBMASEdgeInsets insets))insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (RBMASConstraint * (^)(CGFloat inset))inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (RBMASConstraint * (^)(CGSize offset))sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (RBMASConstraint * (^)(CGPoint offset))centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (RBMASConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
- (RBMASConstraint * (^)(NSValue *value))valueOffset;

/**
 *	Sets the NSLayoutConstraint multiplier property
 */
- (RBMASConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *	Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
- (RBMASConstraint * (^)(CGFloat divider))dividedBy;

/**
 *	Sets the NSLayoutConstraint priority to a float or RBMASLayoutPriority
 */
- (RBMASConstraint * (^)(RBMASLayoutPriority priority))priority;

/**
 *	Sets the NSLayoutConstraint priority to RBMASLayoutPriorityLow
 */
- (RBMASConstraint * (^)(void))priorityLow;

/**
 *	Sets the NSLayoutConstraint priority to RBMASLayoutPriorityMedium
 */
- (RBMASConstraint * (^)(void))priorityMedium;

/**
 *	Sets the NSLayoutConstraint priority to RBMASLayoutPriorityHigh
 */
- (RBMASConstraint * (^)(void))priorityHigh;

/**
 *	Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    RBMASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (RBMASConstraint * (^)(id attr))equalTo;

/**
 *	Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    RBMASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (RBMASConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *	Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    RBMASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (RBMASConstraint * (^)(id attr))lessThanOrEqualTo;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (RBMASConstraint *)with;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (RBMASConstraint *)and;

/**
 *	Creates a new RBMASCompositeConstraint with the called attribute and reciever
 */
- (RBMASConstraint *)left;
- (RBMASConstraint *)top;
- (RBMASConstraint *)right;
- (RBMASConstraint *)bottom;
- (RBMASConstraint *)leading;
- (RBMASConstraint *)trailing;
- (RBMASConstraint *)width;
- (RBMASConstraint *)height;
- (RBMASConstraint *)centerX;
- (RBMASConstraint *)centerY;
- (RBMASConstraint *)baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

- (RBMASConstraint *)firstBaseline;
- (RBMASConstraint *)lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

- (RBMASConstraint *)leftMargin;
- (RBMASConstraint *)rightMargin;
- (RBMASConstraint *)topMargin;
- (RBMASConstraint *)bottomMargin;
- (RBMASConstraint *)leadingMargin;
- (RBMASConstraint *)trailingMargin;
- (RBMASConstraint *)centerXWithinMargins;
- (RBMASConstraint *)centerYWithinMargins;

#endif


/**
 *	Sets the constraint debug name
 */
- (RBMASConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of mas_updateConstraints/mas_makeConstraints blocks

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(RBMASEdgeInsets)insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInset:(CGFloat)inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects RBMASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;


// NSLayoutConstraint Installation support

#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)
/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
@property (nonatomic, copy, readonly) RBMASConstraint *animator;
#endif

/**
 *  Activates an NSLayoutConstraint if it's supported by an OS. 
 *  Invokes install otherwise.
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
- (void)deactivate;

/**
 *	Creates a NSLayoutConstraint and adds it to the appropriate view.
 */
- (void)install;

/**
 *	Removes previously installed NSLayoutConstraint
 */
- (void)uninstall;

@end


/**
 *  Convenience auto-boxing macros for RBMASConstraint methods.
 *
 *  Defining RBMAS_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will appear in global scope.
 */
#define mas_equalTo(...)                 equalTo(RBMASBoxValue((__VA_ARGS__)))
#define mas_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(RBMASBoxValue((__VA_ARGS__)))
#define mas_lessThanOrEqualTo(...)       lessThanOrEqualTo(RBMASBoxValue((__VA_ARGS__)))

#define mas_offset(...)                  valueOffset(RBMASBoxValue((__VA_ARGS__)))


#ifdef RBMAS_SHORTHAND_GLOBALS

#define equalTo(...)                     mas_equalTo(__VA_ARGS__)
#define greaterThanOrEqualTo(...)        mas_greaterThanOrEqualTo(__VA_ARGS__)
#define lessThanOrEqualTo(...)           mas_lessThanOrEqualTo(__VA_ARGS__)

#define offset(...)                      mas_offset(__VA_ARGS__)

#endif


@interface RBMASConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
- (RBMASConstraint * (^)(id attr))mas_equalTo;
- (RBMASConstraint * (^)(id attr))mas_greaterThanOrEqualTo;
- (RBMASConstraint * (^)(id attr))mas_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
- (RBMASConstraint * (^)(id offset))mas_offset;

@end
