//
//  UIViewController+RBMASAdditions.h
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "RBMASUtilities.h"
#import "RBMASConstraintMaker.h"
#import "RBMASViewAttribute.h"

#ifdef RBMAS_VIEW_CONTROLLER

@interface RBMAS_VIEW_CONTROLLER (RBMASAdditions)

/**
 *	following properties return a new RBMASViewAttribute with appropriate UILayoutGuide and NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_topLayoutGuide;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_bottomLayoutGuide;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_topLayoutGuideTop;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_topLayoutGuideBottom;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_bottomLayoutGuideTop;
@property (nonatomic, strong, readonly) RBMASViewAttribute *mas_bottomLayoutGuideBottom;


@end

#endif
