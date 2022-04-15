//
//  TangLogWriter.h
//  TangRtcEngineKit
//
//  Copyright © 2020 Tang. All rights reserved.
//

#ifndef TangLogWriter_h
#define TangLogWriter_h

/** The definition of TangLogWriterDelegate

@note  Implement the callback in this protocol in the critical thread. We recommend avoiding any time-consuming operation in the critical thread.
*/
@protocol TangLogWriterDelegate <NSObject>
@required

/** user defined log Write function

@param message log message of Tangsdk,encrypted by xxtea

@param length length of message

@return
 - 0: success

 - <0: failure
 */
- (NSInteger)writeLog:(const NSData *)message Length:(unsigned short)length;

@end


#endif /* TangLogWriter_h */
