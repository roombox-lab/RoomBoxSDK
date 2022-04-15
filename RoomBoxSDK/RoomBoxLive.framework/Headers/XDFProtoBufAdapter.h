//
//  XDFProtoBufAdapter.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2019/7/9.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ByteArray.h"
#import "GPBProtocolBuffers.h"

NS_ASSUME_NONNULL_BEGIN

@interface XDFProtoBufAdapter : NSObject
/**
 单例
 */
+(XDFProtoBufAdapter *)instance;


/**
 封装protoBuf对象为用于传输的流
 */
-(NSData *)encodeProto:(GPBMessage *)protoObj commandID:(uint32_t)commandID;


/**
 解析数据流，读取其中的属性，封装到GPBMessage中
 */
-(GPBMessage *)decodeProto:(ByteArray *)byts commandID:(uint32_t)commandID;



@end

NS_ASSUME_NONNULL_END
