//
//  NSGNetCommonDefine.h
//  GNetTangSDK
//
//  Created by xiaoyu on 2020/4/15.
//  Copyright © 2020 Loren Zhai. All rights reserved.
//

#ifndef NSGNetCommonDefine_h
#define NSGNetCommonDefine_h
#include "GNetPropertiesDefine.h"

typedef const void* GNetViewHandle;

typedef enum  {
    nsvt_empty = 0,       //!< 类型未定义
    nsvt_bool = 1,        //!< BOOL类型
    nsvt_int = 2,         //!< NSInteger 类型
    nsvt_uint = 3,        //!< NSUInteger 类型
    nsvt_float = 6,       //!< float 类型
    nsvt_double = 7,      //!< double 类型
    nsvt_str = 8,         //!NSString< 类型
    nsvt_arr = 9          //!NSArray<类型
} NSVariantType;

/**
 * @enum PixelFormat
 * @brief 像素格式
 */
typedef enum
{
    pixel_unknow = 0,
    pixel_rgba_8888 = 1,
    pixel_rgb_565 = 2,
    pixel_yuv420 = 3,
    pixel_bgra_8888 = 4,
}NSPixFormat;

typedef enum
{
    userID = 11,
    toolType = 12,
    penColor = 13,
    penWidth = 14,
    savePage = 15,
    addPage = 16,
    addGraphic = 17,
    addGraphics = 18,
    removeGraphic = 19,
    clearGraphic = 20,
    updateLaserPointer = 21,
    enableWatermark = 22,
    watermarkParams = 23,
    watermarkContent = 24,
    mouseCursorsInfo = 25
}NSGraphicType;


typedef struct
{
    NSInteger    m_x;
    NSInteger    m_y;
}NSGNetPoint;

typedef struct
{
    NSUInteger        m_uCodec;            /* 编解码算法*/
    NSUInteger        m_uBPS;                /* 码率*/
    NSUInteger        m_uFrame;            /* 40(ms) 音频包时长*/
    NSUInteger        m_uSampling;        /* 8000; 音频采样率*/
    NSUInteger        m_uPacSize;            /* 音频包分包大小*/
}NSAudioParam;

typedef struct
{
    NSUInteger        m_uId;                     /* id*/
    char*             m_strName;                /* 名称*/
    char*             m_strPhoneNumber;       /* 电话号码*/
}PhoneInfo;

#endif /* NSGNetCommonDefine_h */
