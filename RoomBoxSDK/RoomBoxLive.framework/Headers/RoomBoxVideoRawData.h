//
//  RoomBoxVideoRawData.h
//  RoomBoxLive
//
//  Created by 逯常松 on 2021/6/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^imageBlock)(UIImage *image);

@interface RoomBoxVideoRawData : NSObject

@property (nonatomic, assign) int type;
@property (nonatomic, assign) int width;  //width of video frame
@property (nonatomic, assign) int height;  //height of video frame
@property (nonatomic, assign) int yStride;  //stride of Y data buffer
@property (nonatomic, assign) int uStride;  //stride of U data buffer
@property (nonatomic, assign) int vStride;  //stride of V data buffer
@property (nonatomic, assign) int rotation; // rotation of this frame (0, 90, 180, 270)
@property (nonatomic, assign) int64_t renderTimeMs; // timestamp
@property (nonatomic, assign) char* yBuffer;  //Y data buffer
@property (nonatomic, assign) char* uBuffer;  //U data buffer
@property (nonatomic, assign) char* vBuffer;  //V data buffer

@property (nonatomic, copy) imageBlock imageBlock;

- (void)yuvToUIImageWithVideoRawData:(RoomBoxVideoRawData *)data;

@end


NS_ASSUME_NONNULL_END
