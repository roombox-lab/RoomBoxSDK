//
//  UIDevice+RoomBox.h
//  XDFLog
//
//  Created by 吴云海 on 2021/1/29.
//  Copyright © 2021 xdf.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (RoomBox)

@property (nonatomic, readonly) int64_t rb_diskSpaceFree;

@end

NS_ASSUME_NONNULL_END
