//  二进制数据，读写类
//  ByteArray.h
//  AC_project
//
//  Created by guominglong on 15-1-5.
//  Copyright (c) 2015年 guominglong. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface ByteArray : NSObject
{
    uint64_t _gposition;
}

/**
 数据容器
 */
@property NSMutableData * mudata;

/**
 剩余的可读数据
 */
@property uint64_t bytesAvailable;

-(void)setLength:(NSInteger)_length;
-(NSInteger)length;

/**
 当前读取的数据位置
 */
-(uint32_t)gposition;
-(void)setGposition:(uint32_t)gp;

-(BOOL)readBoolean;
-(int8_t)readByte;
-(void *)readBytes:(uint32_t)_position len:(uint32_t)_len;
-(uint8_t)readUnsignedByte;
-(int32_t)readInt;
-(uint32_t)readUnsignedInt;
-(int16_t)readShort;
-(uint16_t)readUnsignedShort;
-(NSString *)readUTFString;
-(int64_t)readInt64;
-(uint64_t)readUnsignedInt64;


-(void)writeByte:(int8_t)byte;
-(void)writeUnsignedByte:(uint8_t)byte;
-(void)writeBytes:(const void *)_bytes len:(uint32_t)_len;
-(void)writeInt:(int32_t)_value;
-(void)writeUnsignedInt:(uint32_t)_value;
-(void)writeShort:(int16_t)_value;
-(void)writeUnsignedShort:(uint16_t)_value;
-(void)writeUTF8String:(NSString *)_value;
-(void)writeInt64:(int64_t)_value;
-(void)writeUnsignedInt64:(uint64_t)_value;
/**
 清空字节流
 */
-(void)clear;
@end


