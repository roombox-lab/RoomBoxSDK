//
//  RBSVGAAudioLayer.h
//  RBSVGAPlayer
//
//  Created by PonyCui on 2018/10/18.
//  Copyright © 2018年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class RBSVGAAudioEntity, RBSVGAVideoEntity;

@interface RBSVGAAudioLayer : NSObject

@property (nonatomic, readonly) AVAudioPlayer *audioPlayer;
@property (nonatomic, readonly) RBSVGAAudioEntity *audioItem;
@property (nonatomic, assign) BOOL audioPlaying;


- (instancetype)initWithAudioItem:(RBSVGAAudioEntity *)audioItem videoItem:(RBSVGAVideoEntity *)videoItem;

@end
