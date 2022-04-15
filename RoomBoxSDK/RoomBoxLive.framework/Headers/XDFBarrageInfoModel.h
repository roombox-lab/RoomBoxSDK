//
//  XDFBarrageInfoModel.h
//  XDFRoomLoginDemo
//
//  Created by 婉华孙 on 2020/5/11.
//  Copyright © 2020 刘冬冬. All rights reserved.
//

#import <Foundation/Foundation.h>
@import XDFRoomCommonBussiness;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XDFBarrageRoleType) {
    XDFBarrageTeacher,      //老师
    XDFBarrageAssistant,    //助教
    XDFBarrageStudent,      //学生
    XDFBarrageUser,         //当前用户
    XDFBarrageSystem,       //系统
    XDFBarrageNone
};

@interface XDFBarrageInfoModel : NSObject

@property (nonatomic, assign) XDFBarrageRoleType barrageRoleType;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *content;

//非外界传入，由barrage module层根据具体的业务自己处理，然后再传给manager
//@property (nonatomic, copy) XDFThemeAttributeStringPicker *themeAttributeString;
//@property (nonatomic, copy) XDFThemeImagePicker *themeImage;
@property (nonatomic, strong) UIImage *backImage;
@property (nonatomic, copy) NSAttributedString *attributedString;

//
@property (nonatomic, copy) NSString *contentColor;
//头图片 位置
@property (nonatomic, assign) int hImageWidth;
@property (nonatomic, assign) int tImageWidth;
@property (nonatomic, assign) int cImageHeight;


//头图片 位置
@property (nonatomic, copy) NSString *hImageUrl;
@property (nonatomic, copy) NSString *cImageUrl;
@property (nonatomic, copy) NSString *tImageUrl;

@end

NS_ASSUME_NONNULL_END
