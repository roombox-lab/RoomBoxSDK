//
//  RBSVGAExporter.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 2017/3/7.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RBSVGAVideoEntity;

@interface RBSVGAExporter : NSObject

@property (nonatomic, strong) RBSVGAVideoEntity *videoItem;

- (NSArray<UIImage *> *)toImages;

- (void)saveImages:(NSString *)toPath filePrefix:(NSString *)filePrefix;

@end
