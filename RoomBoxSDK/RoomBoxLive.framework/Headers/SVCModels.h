//  数据实体类定义
//  SVCModels.h
//  
//
//  Created by www.xdf.cn on 2018/1/23.
//  Copyright © 2018年 www.xdf.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ByteArray.h"
@interface SVCModels : NSObject

@end


#pragma mark - SVC_Config -----------svc服务sdk配置
@interface SVC_Config :NSObject
{
    NSArray<NSString *> * _lbsArr;
}

/**
 默认给0
 */
@property (nonatomic,assign) uint8_t clientOSFlag;

/**
 客户端标识 如  MAC
 */
@property (nonatomic,strong) NSString * clientFlag;
/**
 客户端版本号
 */
@property (nonatomic,strong) NSString * clientVersion;

/**
 sdk的日志地址
 */
@property (nonatomic,strong) NSString * svcLogDic;
/**
 客户端类型
 */
@property (nonatomic,assign) int32_t clientType;
/**
 acc轮询地址数组
 */
@property NSArray<NSString *> * accArr;

/**
 http服务器地址数组
 */
@property NSArray<NSString *> * httpArr;

/**
 lbs轮询地址数组
 */
-(NSArray<NSString *> *)lbsArr;
-(void)setLbsArr:(NSArray<NSString *> *)arr;
@end

@interface PBPackageDataStruct : NSObject

/**
 * 包头标识
 * */
@property uint16_t headFlag;


/**
 * 完整包的长度
 * */
@property uint32_t size;

/**
 *  扩展包头长度
 **/
@property uint32_t  handExSize;

/**
 *  信息即时类型：
 0x00 - 即时信息（默认）
 0x01 - 离线信息
 **/

/**
 *  包体数据加解密方式：
 0x00 - 不加密（调试使用）
 0x01 - 公钥加密1
 0x02 - 公钥加密2
 0x03 - 私钥加密
 **/
@property uint8_t OfflineAct_And_EncryptType;

/**
 *  公钥序号（后续提供公钥列表）
 **/
@property uint16_t  PubKeyIndex;

/**
 *  压缩类型：
 0x00 - 不压缩
 0x01 - gzip压缩
 **/
/**
 *  协议Body数据的数据类型：
 0x00 - 私有二进制格式
 0x01 - PB二进制格式
 0x02 - PB Json格式
 **/
@property uint8_t CompressType_and_DataType;

/**
 *  协议命令字
 **/
@property uint32_t CommandID;

/**
 *  包序列号，服务端响应包的Sequence等于客户端请求包的Sequence
 **/
@property uint32_t Sequence;

/**
 *  目标ID，在不同业务协议上有不同的含义，比如：
 1对1用户会话 服务标识对方用户的UID
 房间服务标识房间ID
 **/
@property uint64_t Target;

/**
 *  PB Binary:map<int32, bytes>
 **/
@property ByteArray *  Exthead;

/**
 *  PB Binary  数据体
 **/
@property ByteArray * bodydata;

@end
