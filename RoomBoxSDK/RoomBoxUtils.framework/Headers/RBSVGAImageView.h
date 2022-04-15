//
//  RBSVGAImageView.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 2017/10/17.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import "RBSVGAPlayer.h"

@interface RBSVGAImageView : RBSVGAPlayer

@property (nonatomic, assign) IBInspectable BOOL autoPlay;
@property (nonatomic, strong) IBInspectable NSString *imageName;

@end
