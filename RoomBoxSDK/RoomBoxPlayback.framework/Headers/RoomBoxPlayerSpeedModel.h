//
//  RoomBoxPlayerSpeedModel.h
//  RoomBoxPlayer
//
//  Created by 婉华孙 on 2019/12/3.
//  Copyright © 2019 RoomBox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RoomBoxPlayerSpeedModelType) {
    RoomBoxPlayerSpeedModelType075 = 1,
    RoomBoxPlayerSpeedModelType100 = 2,
    RoomBoxPlayerSpeedModelType125 = 3,
    RoomBoxPlayerSpeedModelType150 = 4,
    RoomBoxPlayerSpeedModelType200 = 5,
};

@interface RoomBoxPlayerSpeedModel : NSObject

@property (nonatomic, assign) RoomBoxPlayerSpeedModelType value;
@property (nonatomic, getter=isCurrentSelected) BOOL currentSelected;

- (CGFloat)speedValue;
- (NSString *)speedStringValue;

@end

NS_ASSUME_NONNULL_END
