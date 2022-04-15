//  基础socket封装
//  BaseSocket.h
//  sss
//
//  Created by guominglong on 2018/1/23.
//  Copyright © 2018年 SSdk. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "GCDAsyncSocket.h"
#import "ByteArray.h"
#import "SVCModels.h"
#import "SVCDefine.h"
#import "CoreSocketDataAdapter.h"
#import "AsyncSocket.h"
#import "CoreSocketPackage.h"

@interface BaseSocket : NSObject<AsyncSocketDelegate>

@property (nonatomic,strong) NSError * err;
/**
 socket连接器
 */
//@property (nonatomic,strong) GCDAsyncSocket * sock;
@property (nonatomic,strong) AsyncSocket * sock;

/**
 socket的本地默认超时时间
 */
@property (nonatomic,assign) NSTimeInterval sockOutTime;

/**
 待处理的数据包集合
 */
@property (nonatomic,strong) NSMutableArray<ByteArray *> * waitPackArr;
/**
 待处理的pb数据包集合
 */
@property (nonatomic,strong) NSMutableArray<ByteArray *> * waitPbPackArr;

/**
 连接Socket
 */
-(void)contect:(NSString *)_host port:(UInt16)_port;

/**
 关闭Socket
 */
-(void)close;

/**
 向socket发送数据
 */
-(void)sendSocketData:(ISocketData *)obj commandId:(uint32_t)_commandId sequence:(uint32_t)_sequence;

/**
 * pb socket
 */
-(void)sendPbSocketData:(NSData *)obj headex:(NSData *)hex commandId:(uint32_t)cmdid roomid:(uint64_t)cid;


-(void)sendPbSocketData:(NSData*)obj headex:(NSData*)hex commandId:(uint32_t)cmdid roomid:(uint64_t)cid sequence:(uint32_t)seq;


/**
 是否连接成功
 */
-(BOOL)isConnected;
-(void)setIsConnected;
@end
