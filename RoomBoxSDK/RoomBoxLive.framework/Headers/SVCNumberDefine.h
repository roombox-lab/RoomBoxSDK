//  SVC使用的相关整形数据的定义
//  SVCNumberDefine.h
//  sss
//
//  Created by www.xdf.cn on 2018/1/29.
//  Copyright © 2018年 SSdk. All rights reserved.
//

#import <Foundation/Foundation.h>
#define SVC_c  @"Int8Value"//int8
#define SVC_C  @"UInt8Value"//uint8
#define SVC_s  @"Int16Value"//int16
#define SVC_S  @"UInt16Value"//uint16
#define SVC_i  @"Int32Value"//int32
#define SVC_I  @"UInt32Value"//uint32
#define SVC_l  @"Int64Value"//int64
#define SVC_L  @"UInt64Value"//uint64
#define SVC_str @"StringValue"//string
#define SVC_arr @"NSMutableArray"//string

@interface StringValue:NSObject
@property NSString * value;
-(instancetype)initWithN:(NSString *)_n;
@end

@interface Int8Value:NSObject
@property int8_t value;
-(instancetype)initWithN:(int8_t)_n;
@end

@interface Int16Value:NSObject
@property int16_t value;
-(instancetype)initWithN:(int16_t)_n;
@end

@interface Int32Value:NSObject
@property int32_t value;
-(instancetype)initWithN:(int32_t)_n;
@end

@interface Int64Value:NSObject
@property int64_t value;
-(instancetype)initWithN:(int64_t)_n;
@end

@interface UInt8Value:NSObject
@property uint8_t value;
-(instancetype)initWithN:(uint8_t)_n;
@end

@interface UInt16Value:NSObject
@property uint16_t value;
-(instancetype)initWithN:(uint16_t)_n;
@end

@interface UInt32Value:NSObject
@property uint32_t value;
-(instancetype)initWithN:(uint32_t)_n;
@end

@interface UInt64Value:NSObject
@property uint64_t value;
-(instancetype)initWithN:(uint64_t)_n;
@end

#pragma mark - 操作函数定义 ----------
int8_t _c(Int8Value* val);
uint8_t _C(UInt8Value* val);
int16_t _s(Int16Value* val);
uint16_t _S(UInt16Value* val);
int32_t _i(Int32Value* val);
uint32_t _I(UInt32Value* val);
int64_t _l(Int64Value* val);
uint64_t _L(UInt64Value* val);

Int8Value* c_(int8_t val);

UInt8Value* C_(uint8_t val);

Int16Value* s_(int16_t val);

UInt16Value* S_(uint16_t val);

Int32Value* i_(int32_t val);

UInt32Value* I_(uint32_t val);

Int64Value* l_(int64_t val);

UInt64Value* L_(uint64_t val);


