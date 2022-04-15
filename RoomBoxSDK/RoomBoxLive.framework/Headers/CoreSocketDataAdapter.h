//  数据包封装，解析工具
//  CoreSocketDataAdapter.h
//  AC_project
//
//  Created by guominglong on 15-1-4.
//  Copyright (c) 2015年 guominglong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ISocketData.h"
#import "ByteArray.h"
#import "SVCModels.h"
#import "GPBProtocolBuffers.h"


@interface CoreSocketDataAdapter : NSObject
{
    
}

/**
 userID 即发包时的sourceID
 */
@property uint64_t uid;

@property NSRecursiveLock * lock;
/**
 * 接收到的数据流
 * */
@property ByteArray *responsedataBytes;

/**
 * 包序列
 * */
@property uint32_t sequence;

+(CoreSocketDataAdapter *)instance;

/**
 封装包数据
 */
-(ByteArray *)packPackage:(ISocketData *)_protocalObj commandID:(uint32_t)_commandID;

/**
 新白板pb 格式协议封包
 */
-(ByteArray* )makePackageUsePBData:(NSData*)bodyData exhead:(NSData*)headex  sequence:(uint32_t)seq roomid:(uint64_t)cid commandid:(uint32_t)cmdid;
/**
 * 从源数据流中读取len个字节的数据，追加到responsedataBytes尾部
 * */
-(void)pushResponseData:(NSData *)_inputstream;



/**
 * 通过AES算法解密二进制流
 * */
-(ByteArray *)decode:(Byte *)_bytes len:(uint32_t)_len;

/**
 * 通过AES算法加密二进制流
 * */
-(NSData *)encode:(Byte *)_bytes len:(uint32_t)_len;


@end
