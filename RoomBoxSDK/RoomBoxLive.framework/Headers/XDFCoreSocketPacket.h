//
//  XDFCoreSocketPacket.h
//  RoomBoxSDK
//
//  Created by 吴云海 on 2019/7/9.
//  Copyright © 2019 XDF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ByteArray.h"
NS_ASSUME_NONNULL_BEGIN

@interface XDFCoreSocketPacket : NSObject

@property uint8_t headFlag;  //包头标志

@property uint8_t version;   //包版本号

@property uint8_t reserved;  //保留字段，默认为0

@property uint32_t  packetSize;     //包大小，最大16M

@property uint32_t  extheadSize;    //扩展包头大小

@property uint8_t offlineAct;       //信息即时类型： 0x00 - 即时信息（默认） 0x01 - 离线信息

/*
 * 包体数据加解密方式：
 * 0x00 - 不加密（调试使用）
 * 0x01 - 公钥加密1
 * 0x02 - 公钥加密2
 * 0x03 - 私钥加密
 */
@property uint8_t encryptType;

@property uint16_t pubKeyIndex;    //公钥序号（后续提供公钥列表）

@property uint8_t compressType;     //压缩类型：0x00 - 不压缩 0x01 - gzip压缩


/*
 *  协议Body数据的数据类型：
 *  0x00 - 私有二进制格式
 *  0x01 - PB二进制格式
 *  0x02 - PB Json格式
 */
@property uint8_t  dataType;

@property uint32_t commandID;       //协议命令字

@property uint32_t sequence;        //包序列号，服务端响应包的Sequence等于客户端请求包的Sequence

@property uint64_t target;          //目标ID，在不同业务协议上有不同的含义，比如：

/**
 *  PB Binary:map<int32, bytes>
 **/
@property ByteArray *  Exthead;

/**
 *  PB Binary  数据体
 **/
@property ByteArray * bodydata;


@end

NS_ASSUME_NONNULL_END
