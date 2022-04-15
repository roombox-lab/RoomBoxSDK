//
//  RoomBoxPlayerVideoConfigModel.h
//  RoomBoxPlayer
//
//  Created by wangwenlong on 2020/11/25.
//  Copyright © 2020 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerVideoConfigModel : NSObject

@property (nonatomic, assign) BOOL isValid;
@property (nonatomic, assign) BOOL isAward;
@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, assign) NSInteger starNum;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
