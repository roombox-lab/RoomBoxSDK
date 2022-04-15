//
//  RoomBoxPlayerSacQuizButton.h
//  RoomBoxPlayback
//
//  Created by 逯常松 on 2021/8/19.
//

#import "RoomBoxPlayerButton.h"
#import "RoomBoxPlayerSacQuizModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxPlayerSacQuizButton : RoomBoxPlayerButton

@property (nonatomic, weak) RoomBoxPlayerSacQuizModel *model;

- (void)configUI:(BOOL)viewed;

@end

NS_ASSUME_NONNULL_END
