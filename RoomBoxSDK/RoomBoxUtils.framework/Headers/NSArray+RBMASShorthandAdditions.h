//
//  NSArray+RBMASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "NSArray+RBMASAdditions.h"

#ifdef RBMAS_SHORTHAND

/**
 *	Shorthand array additions without the 'mas_' prefixes,
 *  only enabled if RBMAS_SHORTHAND is defined
 */
@interface NSArray (RBMASShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(RBMASConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(RBMASConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(RBMASConstraintMaker *make))block;

@end

@implementation NSArray (RBMASShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(RBMASConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(^)(RBMASConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(^)(RBMASConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
