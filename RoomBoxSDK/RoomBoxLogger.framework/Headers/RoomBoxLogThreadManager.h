//
//  RoomBoxLogThreadManager.h
//  XDFLog
//
//  Created by 吴云海 on 2021/2/2.
//  Copyright © 2021 xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AliyunLogProducer/AliyunLogProducer.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoomBoxLogThreadManager : NSObject

+(RoomBoxLogThreadManager *)instance;

-(void)sendCurrentLog:(Log *)log isFlush:(NSString *)flush uploadClient:(LogProducerClient *)client;
@end

NS_ASSUME_NONNULL_END
