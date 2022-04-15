//
//  AgoraVideoRawData.h
//  RoomBoxLive
//
//  Created by 逯常松 on 2021/6/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^imageBlock)(UIImage *image);

@interface AgoraVideoRawData : NSObject

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
@property (nonatomic, assign) char* uvBuffer;  //UV data buffer

@property (nonatomic, copy) imageBlock imageBlock;

- (void)yuvToUIImageWithVideoRawData:(AgoraVideoRawData *)data;

@end



NS_ASSUME_NONNULL_END
