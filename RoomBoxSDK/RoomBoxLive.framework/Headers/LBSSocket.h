//  lbs Socket连接器
//  LBSSocket.h
//  AC_project
//
//  Created by guominglong on 15-1-10.
//  Copyright (c) 2015年 guominglong. All rights reserved.
//

#import "BaseSocket.h"

@interface LBSSocket : BaseSocket
{
    /**
     已经循环重链的次数
     */
    int currentConnectCount;
    
    /**
     断线重连计时器
     */
    NSTimer * nt;
    
    /**
     时间间隔
     */
    NSTimeInterval time;
}

+(LBSSocket *)instance;
@end
