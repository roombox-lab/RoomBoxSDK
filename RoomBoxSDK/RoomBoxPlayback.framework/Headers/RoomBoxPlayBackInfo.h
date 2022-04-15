//
//  RoomBoxPlayBackInfo.h
//  RoomBoxPlayBack
//
//  Created by 刘冬冬 on 2021/5/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayBackInfo : NSObject
@property (nonatomic, strong) NSString *classId;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *nickName;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *bizCode;
@property (nonatomic, strong) NSString *baseInfo;

@end

NS_ASSUME_NONNULL_END
