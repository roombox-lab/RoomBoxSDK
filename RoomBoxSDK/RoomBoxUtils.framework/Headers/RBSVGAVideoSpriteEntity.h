//
//  RBSVGAVideoSpriteEntity.h
//  RBSVGAPlayer
//
//  Created by 崔明辉 on 2017/2/20.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SVGAVideoSpriteFrameEntity, RBSVGAContentLayer;
@class SVGAProtoSpriteEntity;

@interface RBSVGAVideoSpriteEntity : NSObject

@property (nonatomic, readonly) NSString *imageKey;
@property (nonatomic, readonly) NSArray<SVGAVideoSpriteFrameEntity *> *frames;
@property (nonatomic, readonly) NSString *matteKey;

- (instancetype)initWithJSONObject:(NSDictionary *)JSONObject;
- (instancetype)initWithProtoObject:(SVGAProtoSpriteEntity *)protoObject;

- (RBSVGAContentLayer *)requestLayerWithBitmap:(UIImage *)bitmap;

@end
