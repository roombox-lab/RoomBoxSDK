//
//  XDFCoreSocketDataAdapter.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2019/7/9.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GPBProtocolBuffers.h"
#import "ByteArray.h"

NS_ASSUME_NONNULL_BEGIN

@interface XDFCoreSocketDataAdapter : NSObject

/**
 userID 即发包时的sourceID
 */
@property uint64_t uid;
@property (nonatomic, assign) uint64_t cid;

@property NSRecursiveLock * lock;
/**
 * 接收到的数据流
 * */
@property ByteArray *responsedataBytes;

/**
 * 包序列
 * */
@property uint32_t sequence;

+(XDFCoreSocketDataAdapter *)instance;


/**
 * 从源数据流中读取len个字节的数据，追加到responsedataBytes尾部
 * */
-(void)pushResponseData:(NSData *)inputstream;

/**
 封装包数据
 */
-(ByteArray* )makePackageUsePBData:(NSData*)bodyData exhead:(NSData*)headex roomid:(uint64_t)cid commandid:(uint32_t)cmdid;

-(ByteArray* )makePackageUsePBData:(NSData*)bodyData exhead:(NSData*)headex roomid:(uint64_t)cid commandid:(uint32_t)cmdid sequence:(uint32_t)seq;


@end

NS_ASSUME_NONNULL_END
