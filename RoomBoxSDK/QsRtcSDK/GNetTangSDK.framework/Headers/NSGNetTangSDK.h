//
//  NSGNetTangSDK.h
//  TMC
//
//  Created by Loren Zhai on 11/12/15.
//  Copyright (c) 2015 quanshi. All rights reserved.
//

#ifndef TMC_NSGNetTangSDK_h
#define TMC_NSGNetTangSDK_h

#import <Foundation/Foundation.h>
#import "GNetPropertiesDefine.h"
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>
#include "NSGNetInternalCommonDefine.h"
#import <GLKit/GLKit.h>
#import "NSGNetView.h"
/**************************IGNetVariant*****************************************/
@protocol IGNetVariant

-(NSVariantType) vt;
-(BOOL)            boolVar;
-(NSInteger)       intVar;
-(NSUInteger)      unintVar;
-(float)           floatVar;
-(double)          doubleVar;
-(NSString*)       strVar;
-(NSArray*)        arrVar;

@end


@interface NSUpdateInfo : NSObject

@property(nonatomic,copy)     NSString*  propertyName;
@property(nonatomic,strong)   id<IGNetVariant> pOldValue;
@property(nonatomic,strong)   id<IGNetVariant> pNewValue;

@end


typedef void(^BackgroundSizeChangedBlock)(NSUInteger uWidth,NSUInteger uHeight);
typedef void(^BackgroundFrameChangedBlock)(CGRect rect);

typedef void(^ScalChangedBlock)(NSInteger nFocusX,NSInteger nFocusY,double fScale);


/**************************IGNetCommentEvent*****************************************/
/**
 * @class ICommentEvent
 * @brief 批注相关的事件接口
 */
@protocol IGNetCommentEvent
/**
 * @brief 添加批注页面的通知
 * @param uStatus
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @param nGroupID 批注在服务器上的资源ID
 * @param uPagegID 新添加的页ID
 * @param uPageWidth 新添加的页的宽度
 * @param uPageHeight 新添加的页的高度
 * @return void
 */
-(void)OnAddPageResult:(NSUInteger)uStatus uOperatorID:(NSUInteger)uOperatorID nGroupID:(NSUInteger)nGroupID uPagegID:(NSUInteger)uPagegID uPageWidth:(NSUInteger)uPageWidth uPageHeight:(NSUInteger)uPageHeight;

/**
 * @brief 删除批注页面的通知
 * @param uStatus
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @param nGroupID 批注在服务器上的资源ID
 * @param uPagegID 被删除的页ID
 * @return void
 */
-(void)OnDeletePageResult:(NSUInteger)uStatus uOperatorID:(NSUInteger)uOperatorID nGroupID:(NSUInteger)nGroupID uPagegID:(NSUInteger)uPagegID;

/**
 * @brief 切换批注页面的通知
 * @param uStatus
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @param nGroupID 批注在服务器上的资源ID
 * @param uPagegID 当前应该显示的页的ID号
 * @return void
 */
-(void)OnSwitchPageResult:(NSUInteger)uStatus uOperatorID:(NSUInteger)uOperatorID nGroupID:(NSUInteger)nGroupID uPagegID:(NSUInteger)uPagegID;


/**
  * @brief 白板数据更新
  * @param uResult
  * - == 0 操作成功
  * - != 0 出错代码
  * @param ulReqShapeID 发起本次更新的请求ID
  * @param ulShapeID 服务端生成的标识本条数据的唯一ID
  * @param usPageID 本条数据的所在页
  * @param ulOperatorID 本次事件被触发的操作者ID
  * @param strShapeInfo 更新的数据内容json串
  * @return void
  */

-(void)OnShapeInfoUpdated:(NSUInteger)ulReqShapeID andShapeId:(NSUInteger)ulShapeID andPageId:(NSUInteger)usPageID andOperator:(NSUInteger)ulOperatorID andShapeInfo:(NSString*)strShapeInfo;

@end

/**************************IGNetComment*****************************************/

/**
 * @class IGNetComment
 * @brief 批注接口
 * @details 提供批准相关功能
 */

@protocol IGNetComment

/**
 * @brief 当前批注在服务器上的资源ID号
 * @return 资源ID
 */
-(NSUInteger) GroupID;

/**
 * @brief 开启批注的用户ID号
 * @return 用户ID
 */
-(NSUInteger) ProviderID;

/**
* @brief 开启批注的关联号，纯白板为0，桌面批注为桌面groupid
* @return 用户ID
*/

-(NSUInteger) AssociateID;


/**
 * @brief 从服务器上更新指定页的图元
 * @param uPageID 如果uPageID为0，则下载所有页面的图元
 * @return void
 */
-(void) PullGraphics:(NSUInteger)uPageID;

/**
 * @brief 添加页
 * @param uPageWidth 页宽度, 如果传0, 使用当前默认的宽度
 * @param uPageHeight 页高度, 如果传0, 使用当前默认的高度
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL) AddPage:(NSUInteger)uPageWidth uPageHeight:(NSUInteger)uPageHeight;

/**
 * @brief 删除页
 * @param uPagegID 页号
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL) DeletePage:(NSUInteger)uPagegID;

/**
 * @brief 切换页
 * @param uPagegID 页号
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL) SwitchPage:(NSUInteger)uPagegID;

/**
 * @brief 删除线条
 * @param uGraphicID 线条的图元ID号
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL) RemoveGraphic:(NSUInteger) uGraphicID;

/**
 * @brief 清除指定页上所有图元
 * @param uPagegID 页号
 * @param uClearType
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL) ClearPage:(NSUInteger)uPageID uClearType:(NSClearType)uClearType;

/**
 * @brief 获取页数量
 * @return 白板的页数量
 */
-(NSUInteger) PageCount;

/**
 * @brief 获取当前页
 * @return 当前页ID
 */

-(NSUInteger) CurrentPage;


/**
 * @brief 更新激光笔位置
 * @param x 激光笔的横坐标
 * @param y 激光笔的纵坐标
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)UpdateLaserPointer:(double)x y:(double)y;
@end


/**************************IGNetPageInfo*****************************************/
/**
 * @class IGNetPageInfo
 * @brief 页面接口
 */
@protocol IGNetPageInfo
-(NSUInteger) pageId;
-(NSUInteger) pageWidth;
-(NSUInteger) pageHeight;
-(NSUInteger) pagePadding;
-(NSUInteger) pageIndex;

@end

/**************************IGNetDesktopMgrEvent*****************************************/
/**
 * @class IGNetDesktopMgrEvent
 * @brief 桌面管理器的事件接口
 * @details 所有事件都在主线程中被抛出
 */

@protocol IGNetDesktopMgrEvent

/**
 * @brief 新添加一个桌面实例
 * @param pVideoInstance 被添加的桌面实例的接口
 * @return void
 */

-(void)OnDesktopStreamAdded:(NSUInteger)uGroupID;

/**
* @brief 桌面实例将被移除
* @param uGroupID 待被移除的桌面的资源ID
* @return void
* @warning 该事件函数返回后，桌面实例将不在可见
*/
-(void)OnDesktopStreamRemoved:(NSUInteger)uGroupID;

/**
 * @brief 桌面共享是否成功
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @param uGroupID 共享的桌面在服务器上的资源ID，仅仅在桌面共享成功的情况下有效
 * @return void
 */
-(void)OnDesktopSharerStarteResult:(NSUInteger)uResult operatorID:(NSUInteger)uOperatorID groupID:(NSUInteger)uGroupID;

/**
 * @brief 桌面共享被停止
 * @param uGroupID 被停止的桌面共享在服务器上的资源ID号
 * @return void
 */
-(void)OnDesktopSharerStoped:(NSUInteger)uGroupID;

/**
 * @brief 桌面观看是否成功
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @return void
 */
-(void)OnDesktopViewerStarteResult:(NSUInteger)uResult operatorID:(NSUInteger)uOperatorID;

/**
 * @brief 桌面观看被停止
 * @return void
 */
-(void)OnDesktopViewerStopped;

/**
 * @brief 桌面批注开始是否成功
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @param uOperatorID 本次事件被触发的操作者ID
 * @param pComment 批注接口
 * @return void
 * @warning pComment接口的生存周期有SDK自动控制，在OnDesktopCommentClosed回调被触发前一直有效
 */
-(void)OnDesktopCommentOpenResult:(NSUInteger)uResult operatorID:(NSUInteger)uOperatorID comment:(id<IGNetComment>)pComment;

/**
 * @brief 桌面批注被关闭
 * @return void
 */
-(void)OnDesktopCommentClosed;

/**
 * @brief 桌面模块属性发生变化
 * @param propName 属性名称
 * @param oldValue 属性的旧值
 * @param newValue 属性的新值
 * @return void
 */
-(void)OnPropertyChanged:(NSString*)propName oldValue:(id<IGNetVariant>)oldValue newValue:(id<IGNetVariant>)newValue;

/**
* @beif 桌面模块失败处理
* @param operation 失败的操作名称
* @param errorCode 失败的错误码
* @param description 失败情况描述
* @return void
*/
-(void)OnDesktopErrorHandler:(NSString*)operation errorCode:(NSUInteger)errorCode description:(NSString*)description;


/**
* @beif 桌面流状态
* @param isLiveStream 桌面流开关
* @return void
*/

-(void)onDesktopLiveStreamStatus:(BOOL )isLiveStream;

@end

/**************************IGNetDesktopMgr*****************************************/
@protocol IGNetDesktopMgr

-(void)setApplicationGroupIdentifier:(NSString *)identifier;

/**
 * @brief 设置桌面管理器的事件接口
 * @return void
 * @warning
 * - 本方法必须在主线程环境调用，
 * - 桌面管理器有且只有一个事件接口，后设置的事件接口将替换先前设置的接口
 * - 在事件接口失效之前，必须先通过SetEvent(nullptr)来通知桌面管理器
 */
-(void)SetEvent:(id<IGNetDesktopMgrEvent>)pEvent;

/**
 * @brief 共享屏幕
 * @param uScreenID 当前待共享的屏幕的ID号
 * @param uAppGroupId

 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)StartShareScreen:(NSUInteger)uScreenID;

/**
 * @brief 停止屏幕
 * @param uGroupID 需要停止的桌面实例ID
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)StopShare:(NSUInteger)uGroupID;

/**
 * @brief 开启桌面批注
 * @param pRender 批注的渲染接口
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)OpenComment:(GNetViewHandle)pWindow;

/**
 * @brief 关闭桌面批注
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)CloseComment;

/**
 * @brief 更新桌面批注的背景
 * @return
 * - == true 更新成功
 * - == false 更新失败
 * @warnging 此处只是发出请求，具体的批注背景将通过IMemeoryRender更新
 */
-(BOOL)UpdateCommentBanckground;

/**
 * @brief 当前是否有桌面共享实例存在
 * @return
 * - == true 当前已经有桌面共享存在
 * - == false 当前没有桌面共享存在
 */
-(BOOL)HasDesktopShared;

/**
 * @brief 获取当前共享的桌面的ID号
 * @return 当前共享的桌面的ID号，如果当前没有桌面共享存在，返回0
 */
-(NSUInteger)GetDesktopID;

/**
 * @brief 获取当前桌面共享是有谁提供的
 * @return 当前桌面共享提供者的用户ID号，如果当前没有桌面共享存在，返回0
 */
-(NSUInteger)GetProviderID;

/**
 * @brief 开启观看远端桌面
 * @param uGroupID 远端桌面的实例ID
 * @param pRender 远端桌面的渲染接口
 * @return
* - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)StartView:(NSUInteger)uGroupID pWindow:(NSGNetView*)pWindow;

/**
 * @brief 停止观看远端桌面
 * @param uGroupID 远端桌面的实例ID
 * @return
* - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)StopView:(NSUInteger)uGroupID;

/**
 * @brief 当前是否开启了水印效果
 * @return
 * - true 开启
 * - false 关闭
 */
-(BOOL)IsWatermarkOn;

/**
 * @brief 开启水印效果
 * @return
 * - true 开启成功
 * - false 开启失败
 */
-(BOOL)OpenWatermark;

/**
 * @brief 设置水印内容
 * @param pContent 水印中显示的文本
 * @return
 * - true 设置成功
 * - false 设置失败
 */
-(BOOL)SetWaterMarkContext:(NSString*)pContent;

/**
 * @brief 设置水印显示配置
 * @param pFontName 字体名称(默认：宋体)
 * @param uFontSize 字体大小(默认：16)
 * @param uTextColor 文本颜色(RGB格式，默认0xFFFFFF)
 * @param fAngle 文本的倾斜角度(默认：30°)
 * @param uColumnSpace 列间距(单位：像素，默认：10)
 * @param uLineSpace 行间距(单位：像素，默认：10)
 * @return
 * - true 设置成功
 * - false 设置失败
 */
-(BOOL)SetWaterMarkParams:(NSString*)pFontName fontSize:(NSUInteger)uFontSize textColor:(NSUInteger)uTextColor angle:(CGFloat)fAngle columnSpace:(NSUInteger)uColumnSpace lineSpace:(NSUInteger)uLineSpace;

/**
 * @brief 关闭水印效果
 * @return
 * - true 关闭成功
 * - false 关闭失败
 */
-(BOOL)CloseWatermark;

/**
 * @brief 获取桌面模块的属性值
 * @param propName 属性名称
 * @param propValue 保存获取到的属性值
 * @return
 * - == true 获取成功
 * - == false 获取失败
 */
-(id<IGNetVariant>)GetPropertyValue:(NSString*)propName;


/// 设置是否不释放 VariantValue
/// @param enable true   不释放；false 释放    (默认释放)
-(void)setRetainGnetVariantValue:(bool)enable;


@end

/**************************IGNetUserPropertiesEvent*****************************************/
/**
* @class IUserPropertiesEvent
* @brief 用户属性批量更新事件接口
* @details 用于一次性提供一个用户的多个属性的更新
*/
@protocol IGNetUserPropertiesEvent

/**
 * @brief 当前更新的属性的数量
 * @return 返回的更新的属性的数量
 */
-(NSUInteger)Count;

/**
 * @brief 获取指定的属性的更新信息
 * @param uIndex 属性在管理器中的位置(（0 ~ Count函数的返回值))
 * @return 属性的更新信息
 */
-(NSUpdateInfo*)GetAt:(NSUInteger)uIndex;

@end



/**
 * @class IGNetUser
 * @brief 用户接口
 * @details 保存用户属性，以及针对用户有关的操作
 */

@protocol IGNetUser
/**
 * @brief 获取用户ID号
 * @return 返回用户ID
 */
-(NSUInteger)ID;

/**
 * @brief 获取用户类型
 * @return 返回用户类型
 */
-(NSUInteger)Type;

/**
 * @brief 获取用户名称
 * @return 返回的当前用户的名称
 */
-(NSString*)Name;

/**
 * @brief 获取用户名称
 * @return 返回的当前用户的名称
 */
-(NSString*)Email;

/**
 * @brief 获取用户名称
 * @return 返回的当前用户的名称
 */
-(NSString*)Phone;

/**
 * @brief 获取用户名称
 * @return 返回的当前用户的名称
 */

-(NSUInteger)Roles;

/**
 * @brief 用户使用的客户端的版本号
 * @return 客户端的版本号
 */
-(NSUInteger)ClientVersion;

/**
 * @brief 获取用户的属性值
 * @param propName 属性名称
 * - "clientType" 客户端类型
 * - "umsUserID" UMS上的用户编号
 * - "userName" 用户名称
 * - "email" 电子邮件
 * - "mobile" 电话号码
 * - "status" 用户状态, 详见枚举 UserStatus
 * - "userRoles" 用户角色
 * - "userCustomizedRoles" 用户权限
 * - "isSpeaking" 是否在发言(0: 未讲话 1：讲话)
 * - "phoneNum" 电话语音使用的电话号码
 * - "videoShareStatus" 视频共享状态(0: 未共享， 1：共享)
 * - "imagePath" 头像
 * - "groupName" 用户分组
 * @param propValue 保存获取到的属性值
 */
-(id<IGNetVariant>)GetPropertyValue:(NSString*)propName;

/// 设置是否不释放 VariantValue
/// @param enable true   不释放；false 释放    (默认释放)
-(void)setRetainGnetVariantValue:(bool)enable;

@end


@protocol IGNetPhoneInfoList
/**
 * @brief 获取当前列表中电话用户信息数量
 * @return 电话用户信息的数量
 */
-(NSUInteger)Count;

/**
 * @brief 电话用户所属的数据用户的ID号
 * @param uIndex 电话用户信息在列表中的位置
 * @return
 * - = 电话用户当前没有所属的数据用户
 * - == 其他 电话用户所属的数据用户的ID
 * @warning 如果电话用户所属的数据用户的ID不为零，则当外呼成功后，该电话用户将于数据用户绑定
 */
-(NSUInteger)ID:(NSUInteger)uIndex;

/**
 * @brief 获取当前列表中电话用户的电话号码信息
 * @param uIndex 电话用户信息在列表中的位置
 * @return 电话用户信息中的电话号码
 * @warning 该字段不能为空
 */
-(NSString *)PhoneNumber:(NSUInteger)uIndex;

/**
 * @brief 获取当前列表中电话用户信息中的名字信息
 * @param uIndex 电话用户信息在列表中的位置
 * @return 电话用户信息中的用户名字
 * @warning 该字段可以为空。
 */
-(NSString *)UserName:(NSUInteger)uIndex;

@end


@interface NSPhoneInfoModel : NSObject //内部属性

@property (nonatomic, copy) NSString *strUserName;
@property (nonatomic, copy) NSString *strPhoneNumber;
@property (nonatomic, assign) NSInteger iPhoneId;

@end



/**************************IGNetIVideoInstance*****************************************/
@protocol IGNetIVideoInstance
/**
 * @brief 获取视频的资源ID
 * @return 资源ID
 */
-(NSUInteger) GroupID;

/**
 * @brief 获取视频的提供者的ID号
 * @return 提供者的ID号
 */
-(NSUInteger) ProviderID;

/**
 * @brief 获取视频使用的设备的ID号
 * @return 设备的ID号
 */
-(NSString *) DeviceID;

/**
 * @brief 销毁当前接口
 */
-(void) Desotry;
@end


/**************************IGNetIVideoInstanceSet*****************************************/
@protocol IGNetIVideoInstanceSet
/**
 * @brief 返回当前列表中视频实例的数量
 * @return 视频实例的数量
 */
-(NSUInteger) Count;

/**
 * @brief 获取指定视频实例接口
 * @param uIndex 视频实例接口在集合中的位置
 * @return 视频实例的接口
 * @warning 从视频实例集合(IVideoInstanceSet)中获取的视频实例接口(IVideoInstance)不用手动销毁
 */
-(id<IGNetIVideoInstance>)At:(NSUInteger)uIndex;

/**
 * @brief 销毁当前接口
 * @warning 在视频实例集合(IVideoInstanceSet)被销毁的时候，其所拥有的所有视频实例将自动被释放
 */
-(void) Desotry;
@end


/**************************IGNetChatMessage*****************************************/
/**
 * @class IChatMessage
 * @brief 文本消息接口
 */
@protocol IGNetChatMessage <NSObject>

/**
 * @brief 文本信息发送的时间
 * @return 发送时间
 */
-(NSString *)Stamp;

/**
 * @brief 文本信息发送者的ID号
 * @return 发送者的ID号
 */
-(NSUInteger)SenderID;

/**
 * @brief 文本信息发送者的名字
 * @return 发送者的名字
 */
-(NSString *)SenderName;

/**
 * @brief 文本信息接收者的ID号
 * @return 接收者的ID号，如果该ID号为0，标识这是一个公共频道的信息，发给所有人
 */
-(NSUInteger)ReciverID;

/**
 * @brief 文本信息接收者的名字
 * @return 接收者的名字
 */
-(NSString *)ReciverName;

/**
 * @brief 文本信息内容
 * @return 信息内容
 */
-(NSString *)Content;

@end


@interface NSGNetChatMessageImpl : NSObject <IGNetChatMessage>
{
}

@property(nonatomic,copy) NSString*Stamp;
@property(nonatomic,assign) NSUInteger SenderID;
@property(nonatomic,copy) NSString*SenderName;
@property(nonatomic,assign) NSUInteger ReciverID;
@property(nonatomic,copy) NSString*ReciverName;
@property(nonatomic,copy) NSString*Content;

@end


/**************************IGNetChatMgrEvent*****************************************/
@protocol IGNetChatMgrEvent <NSObject>
/**
 * @class IChatMessage
 * @brief 文本消息接口
 */
/**
 * @brief 收到一条文本消息
 * @param pMessage 文本消息的接口
 * @return void
 * @warning pMessage接口在回调函数返回后，不再有效。
 */
-(void)OnRecvChatMessage:(id<IGNetChatMessage>)pMessage;

-(void)OnRecvCustomChatMessage:(id<IGNetChatMessage>)pMessage;

@end

/**************************IGNetChatMgr*****************************************/
@protocol IGNetChatMgr <NSObject>
/**
 * @class IChatMgr
 * @brief 聊天管理器接口
 * @details 提供文本聊天的相关功能
 */

/**
 * @brief 设置聊天管理器的事件接口
 * @return void
 * @warning
 * - 本方法必须在主线程环境调用，
 * - 聊天管理器有且只有一个事件接口，后设置的事件接口将替换先前设置的接口
 * - 在事件接口失效之前，必须先通过SetEvent(nullptr)来通知聊天管理器
 */
-(void)SetEvent:(id<IGNetChatMgrEvent>)pEvent;

/**
 * @brief 发送消息
 * @param pDestUsers 消息接收者
 * - == "0" 公共频道
 * - == "100;101;102" 以';'分隔的多个UserID，只有这些用户能收到消息
 * @param pMessage 消息接口
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)SendMessage:(NSString *)pDestUsers pMessage:(NSString *)pMessage;

/**
 * @brief 保存消息到文件
 * @param pPathFile 文件路径
 * @param uUserID 筛选消息的用户ID，仅保持公共频道或和uUserID有关联(接收者或发送者为uUserID)的消息。
 * @return
 * - == true 保存成功
 * - == false 保存失败
 */
-(BOOL)SaveMessages:(NSString *)pPathFile uUserID:(NSUInteger)uUserID;


-(BOOL)SendCustomMessage:(NSString*)pDestUsers message:(NSString*)pMessage;


@end

/**************************IGNetMeetingEvent*****************************************/
/**
* @class IGNetMeetingEvent
* @brief 云会议接口的事件接口
* @details 所有的事件都确保在主线程中抛出
*/
@protocol IGNetMeetingEvent<NSObject>

/**
     * @brief 会议属性发生变动
     * @param propName 发生变动的属性名称
     * @param oldPropValue 属性的旧值
     * @param newPropValue 属性的新值
     * @return void
     */
-(void) OnPropertyChanged:(NSString*)propName oldProp:(id<IGNetVariant>)oldPropValue newProp:(id<IGNetVariant>)newPropValue;

/**
 * @brief 收到一条自定义消息
 * @param uFromID 消息来源
 * @param pMessage 消息内容
 * @return void
 */
-(void)OnReciveCustomMessage:(NSUInteger)uFromID message:(NSString*)pMessage;

/**
 * @brief 会议的配置项发生改变
 * @param uKey 发生改变的配置项的键
 * @param pOldValue 配置项的旧值
 * @param pNewValue 配置项的新值
 * @return void
 */
-(void)OnConfigDataItemChanged:(NSUInteger)uKey oldValue:(NSString*)pOldValue newValue:(NSString*)pNewValue;

/**
 * @brief 开启录制的服务器应答通知
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @return void
 */
-(void)OnStartRecordResult:(NSUInteger)uResult;

/**
 * @brief 关闭录制的服务器应答通知
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @return void
 */
-(void)OnStopRecordResult:(NSUInteger)uResult;

/**
 * @brief 呼叫MCU的服务器应答通知
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @param pAddress MCU的地址信息
 * @param pConf MCU的配置信息
 * @return void
 */
-(void)OnCallMCUResult:(NSUInteger)uResult address:(NSString*)pAddress conf:(NSString*)pConf;

/**
 * @brief 挂断MCU的服务器应答通知
 * @param uResult
 * - = 操作成功
 * - ! 出错代码
 * @param pAddress MCU的地址信息
 * @param pConf MCU的配置信息
 * @return void
 */
-(void)OnHungupMCUResult:(NSUInteger)uResult address:(NSString*)pAddress conf:(NSString*)pConf;

/**
 * @brief 服务器询问会议是否继续的推送消息
 * @return void
 * @warning 当收到服务器的询问，并且不想会议自动结束，客户端需要调用IMeeting接口的
 * 方法SetConferenceContinued通知服务器会议继续
 */
-(void)OnQueryConferenceContinued;

/**
 * @brief 网络状态较差时，通知上层
 * @return void
 */
-(void)OnNetWorkWarning;

/**
 * @brief 准备退出会议，释放会议资源之前触发
 * @return void
 */
-(void)OnBeforeQuit;


/**
 * @brief 当前已经从会议中退出
 * @param eReason 退出的原因
 * @return void
 */
//-(void)OnQuit:(tangsdk::QuitReason)eReason;
-(void)OnQuit:(QSQuitReason)eReason;

/**
* @brief 会议配置发生改变
* @param uUserID 更改配置的用户
* @param pChangedSetting 更改的配置项
* @return void
*/
-(void)OnSettingChanged:(NSUInteger)uUserID andChangedSetting:(NSString*)pChangedSetting;

@end

/**************************IGNetMeeting*****************************************/
/**
* @class NSMeeting
* @brief 云会议接口
* @details 提供会议中各种功能的容器接口
*/
@protocol IGNetMeeting
/**
* @brief 设置会议接口的事件接口
* @param pMeetingEvent 会议接口的事件接口，用于处理服务器端的推送消息
* @return void
* @warning 事件接口一旦被设置后，如果没有被取消必须保证其的生存。
*/
-(void)SetEventListener:(id<IGNetMeetingEvent>)event;

/**
 * @brief 获取会议ID
 * @return 用户ID
 */
-(NSUInteger)ID;

/**
 * @brief 锁定会议
 * @return
 * - true 锁定会议的请求发送成功
 * - false 锁定会议的请求发送失败
 */
-(BOOL)Lock;

/**
 * @brief 解锁会议
 * @return
 * - true 解锁会议的请求发送成功
 * - false 解锁会议的请求发送失败
 */
-(BOOL)Unlock;

/**
* @brief 发送自定义消息
* @param pUsers 消息的接收者列表
*  - == nullptr 当前会议中所有用户都能收到该消息
*  - != nullptr 仅仅在接受者列表中的用户才能收到该消息
* @param uUserNum 数组pUsers中的用户ID的数量
* @param pMessage 消息内容
* @return
*  - true 自定义消息发送成功
*  - false 自定义消息发送失败
*/

-(BOOL)SendCustomMessage:(NSArray*)pUsers message:(NSString*)pMessage;
                               
/**
* @brief 设置会议配置项
* @param uKey 配置项的键值
* @param pValue 配置项的值
* @return
*  - true 自定义消息发送成功
*  - false 自定义消息发送失败
*/
-(BOOL)SetConfigDataItem:(NSUInteger)uKey value:(NSString*)pValue;
                               
/**
 * @brief 获取会议配置项
 * @param uKey 配置项的键值
 * @return 配置项的值
 */
-(NSString*)GetConfigDataItem:(NSUInteger)uKey;

/**
 * @brief 开启录制
 * @return
 *  - true 开启录制的请求发送成功
 *  - false 开启录制的请求发送失败
 */
-(BOOL)StartRecord;

/**
 * @brief 停止录制
 * @return
 *  - true 停止录制的请求发送成功
 *  - false 停止录制的请求发送失败
 */
-(BOOL)StopRecord;

/**
 * @brief 查询录制时间
 * @return
 *  - true 查询录制时间的请求发送成功
 *  - false 查询录制时间的请求发送失败
 */
-(BOOL)QueryRecordTime;

/**
 * @brief 设置录制密码
 * @param password 待设置的录制密码（密码不能为空，并且不大于32个字节)
 * @return
 *  - true 设置录制密码的请求发送成功
 *  - false 设置录制密码的请求发送失败
 */
-(BOOL)SetRecordPassword:(NSString*)password;

/**
 * @brief 呼叫MCU
 * @param pEndPoints MCU的标识符
 * @return
 *  - true 呼叫MCU的请求发送成功
 *  - false 呼叫MCU的请求发送失败
 */
-(BOOL)CallMCU:(NSString*)pEndPoints;

/**
 * @brief 挂断MCU
 * @param pEndPoints MCU的标识符
 * @return
 *  - true 挂断MCU的请求发送成功
 *  - false 挂断MCU的请求发送失败
 */
-(BOOL)HungupMCU:(NSString*)pEndPoints;

-(void)SetIsCommentConfigOpen:(BOOL)bIsOpen;

-(BOOL)GetIsCommentConfigOpen;

/**
 * @brief 设置会议是否继续
 * @param bContinued
 * - == true 会议继续
 * - == false 会议可以结束
 * @return
 *  - true 设置的请求发送成功
 *  - false 设置的请求发送失败
 */
-(BOOL)SetConferenceContinued:(BOOL)bContinued;

/**
 * @brief 获取会议的属性值
 * @param propName 属性名称
 * - "confLocked" 会议是否被锁定
 * - "confTitle" 会议标题
 * - "networkConnectStatus" 网络状态
 * @param propValue 保存获取到的属性值
 * @return
 */
-(id<IGNetVariant>)GetPropertyValue:(NSString*)propName;

/// 设置是否不释放 VariantValue
/// @param enable true   不释放；false 释放    (默认释放)
-(void)setRetainGnetVariantValue:(bool)enable;
/**
 * @brief 获取用户管理器接口
 * @return 用户管理器接口
 */

/**
 * @brief 获取聊天管理器接口
 * @return 聊天管理器接口
 * @warning 如果当前终端不支持聊天业务，本方法返回nullptr
 */
-(id<IGNetChatMgr>)GetChatMgr;

/**
 * @brief 断线重连接口
  * @return
 * - == true 断线重连请求成功，真正的断线重连成功由OnMeetingReady来通知
 * - == false 断线重连失败
 */
-(BOOL)Reconnect;

/**
 * @brief 退出当前会议
 * @return
 *  - true 退会的请求发送成功
 *  - false 退会的请求发送失败
 * @warning
 * - 退出会议仅影响当前用户，会议本身还存在，其他在会议中的人依旧可以继续会议
 * - 退出会议是个异步操作，需要等到OnQuit事件被触发才说明真实的退出会议
 */
-(BOOL)Quit;

//退出会议，与Quit的区别是将glog打日志做了优化，防止手动杀死APP导致打日志崩溃
-(BOOL)Release;

/**
 * @brief 结束会议
 * @return
 *  - true 结束会议的请求发送成功
 *  - false 结束会议的请求发送失败
 * @warning
 * - 结束会议会导致会议在服务器端被移除，所有还在会议中的人都将被踢掉
 * - 结束会议会是个异步操作，需要等到OnTerminate事件被触发才说明会议被真正结束
 */
-(BOOL)Terminate;

/**
* @brief 更新用户属性中的CustomStr字段
* @param pCustomStr json格式字符串
* @return
*  - true 成功
*  - false 失败
*/
-(BOOL)UpdateUserCustomStr:(NSString*)pCustomStr;

/**
* @brief 获取会议的设置
* @return 当前会议的设置信息
*/
-(NSString*)GetSetting;

/**
* @brief 更新会议的设置
* @param pFullSetting 更新后的会议的全部设置
* @param pChangedSetting 本次更新的会议设置
* @return
*  - true 成功
*  - false 失败
*/
-(BOOL)UpdateSetting:(NSString*)pFullSetting changedSetting:(NSString*)pChangedSetting;

@end

/**************************IGNetMicrophoneDeviceMgrEvent*****************************************/
@protocol IGNetMicrophoneDeviceMgrEvent
/**
 * @class IMicrophoneDeviceMgrEvent
 * @brief 麦克风设备列表
 * @details 提供麦克风热插拔通知和实时音量汇报的功能
 */
/**
* @brief 汇报默认麦克风的实时音量
* @param uVolume 麦克风实时音量，取值范围为0~100，0为静音，100为音量最大值
* @return void
*/
-(void) OnRealtimeVolumeReport:(NSUInteger)uVolume;

/**
 * @brief 有新麦克风设备被插入
 * @param pDeviceID 新插入设备的ID号
 * @return void
 */
-(void) OnDeviceAdded:(NSString *)pDeviceID;

/**
 * @brief 现有麦克风设备被拔出
 * @param pDeviceID 被拔出设备的ID号
 * @return void
 */
-(void) OnDeviceRemoved:(NSString *)pDeviceID;

/**
 * @brief 汇报默认麦克风的音量变化
 * @param uVolume 麦克风实时音量，取值范围为0~100，0为静音，100为音量最大值
 * @return void
 */
-(void) OnVolumeReport:(NSUInteger)uVolume;

@end

/**************************IGNetMicrophoneDeviceMgr*****************************************/
@protocol IGNetMicrophoneDeviceMgr
/**
 * @class IMicrophoneDeviceMgr
 * @brief 麦克风管理器接口
 * @details 提供对当前系统中所有麦克风设备的管理
 */
/**
* @brief 设置麦克风管理器的事件接口
* @param pEvent 麦克风管理器的事件接口
* @return void
* @warning
* - 本方法必须在主线程环境调用，
* - 麦克风管理器有且只有一个事件接口，后设置的事件接口将替换先前设置的接口
* - 在事件接口失效之前，必须先通过SetEvent(nullptr)来通知麦克风管理器
*/
-(void) SetEvent:(id<IGNetMicrophoneDeviceMgrEvent>)pEvent;

/**
 * @brief 获取当前系统中麦克风设备的数量
 * @return 麦克风数量
 */
-(NSUInteger) Count;

/**
 * @brief 获取指定麦克风设备的接口
 * @param nIndex 设备在管理器中的位置（0 ~ Count函数的返回值)
 * @return 返回指定设备的接口
 */
-(NSString *) GetDeviceID:(NSUInteger)nIndex;

/**
 * @brief 查询是否存在设备ID
 * @param pDeviceID 待查找的麦克风设备的ID号
 * @return
 * - == true  存在
 * - == false 不存在
 */
-(BOOL) FindDevice:(NSString *)pDeviceID;

/**
 * @brief 获取麦克风的显示名称
 * @return 返回麦克风的显示名称
 */
-(NSString *) GetDeviceName:(NSString *)pDeviceID;

/**
 * @brief 麦克风是否被占用
 * @return
 * - true 麦克风被占用
 * - false 麦克风未被占用
 */
-(BOOL) IsOccupied:(NSString *)pDeviceID;

/**
 * @brief 获取麦克风的音量
 * @return 返回麦克风的音量，取值范围为0~100，0为静音，100为音量最大值, -1:设备错误
 */
-(NSInteger) GetVolume:(NSString *)pDeviceID;

/**
 * @brief 设置麦克风的音量
 * @param uVolume 麦克风的音量，取值范围为0~100，0为静音，100为音量最大值
 * @return
 * - == true 设置成功
 * - == false 设置失败
 */
-(BOOL) SetVolume:(NSString *)pDeviceID uVolume:(NSUInteger)uVolume;

/**
 * @brief 重置麦克风设备
 * @return
 */
-(BOOL) ResetDefaultDevice;

/**
 * @brief 设置默认麦克风设备
 * @param pDeviceID 待设置的麦克风设备的ID号
 * @return
 * - == true 设置成功
 * - == false 设置失败
 */
-(BOOL) SetDefaultDevice:(NSString *)pDeviceID;

/**
 * @brief 获取默认的麦克风设备
 * @return
 * - == nullptr 没有默认的麦克风设备，一般指当前系统中无麦克风设备
 * - != nullptr 默认麦克风的ID号
 */
-(NSString *) GetCurrentDevice;

/**
 * @brief 开启麦克风的音量变化检测
 * @return
 * - == true 开启成功
 * - == false 开启失败
 * @warning
 * - 此处检测麦克风为默认麦克风
 */
-(BOOL) StartVolumeReport;

/**
 * @brief 关闭麦克风的音量变化检测
 * @return void
 */
-(void) StopVolumeReport;

/**
 * @brief 销毁麦克风管理器接口
 * @warning
 * - 调用该方法会导致，当前所有麦克风设备的接口都将无效。
 * - 调用该方法后，调用接口将不再有效，必须被置为nullptr
 */
-(void) Destory;

@end

/**************************IGNetSpeakerDeviceMgrEvent*****************************************/
@protocol IGNetSpeakerDeviceMgrEvent
/**
 * @class ISpeakerDeviceMgrEvent
 * @brief 扬声器管理器的事件接口
 * @details 提供扬声器热插拔通知和实时音量汇报的功能
 */
/**
* @brief 汇报默认扬声器的实时音量
* @param uVolume 扬声器实时音量，取值范围为0~100，0为静音，100为音量最大值
* @return void
*/
-(void) OnRealtimeVolumeReport:(NSUInteger)uVolume;

/**
 * @brief 有新扬声器设备被插入
 * @param pDeviceID 新插入设备的ID号
 * @param pDisplayName 设备的现实名称
 * @return void
 */
-(void) OnDeviceAdded:(NSString *)pDeviceID;

/**
 * @brief 现有扬声器设备被拔出
 * @param pDeviceID 被拔出设备的ID号
 * @return void
 */
-(void) OnDeviceRemoved:(NSString *)pDeviceID;

/**
 * @brief 汇报默认扬声器的音量变化
 * @param uVolume 扬声器实时音量，取值范围为0~100，0为静音，100为音量最大值
 * @return void
 */
-(void) OnVolumeReport:(NSUInteger)uVolume;

@end

/**************************IGNetSpeakerDeviceMgr*****************************************/
@protocol IGNetSpeakerDeviceMgr
/**
 * @brief 设置扬声器管理器的事件接口
 * @param pEvent 扬声器管理器的事件接口
 * @return void
 * @warning
 * - 本方法必须在主线程环境调用，
 * - 扬声器管理器有且只有一个事件接口，后设置的事件接口将替换先前设置的接口
 * - 在事件接口失效之前，必须先通过SetEvent(nullptr)来通知扬声器管理器
 */
-(void) SetEvent:(id<IGNetSpeakerDeviceMgrEvent>)pEvent;

/**
 * @brief 获取当前系统中扬声器设备的数量
 * @return 扬声器数量
 */
-(NSUInteger) Count;

/**
 * @brief 获取指定扬声器设备的接口
 * @param nIndex 设备在管理器中的位置（0 ~ Count函数的返回值)
 * @return 返回指定设备的接口
 */
-(NSString *) GetDeviceID:(NSUInteger)nIndex;

/**
 * @brief 查询是否存在设备ID
 * @param pDeviceID 待查找的扬声器设备的ID号
 * @return
 * - == true  存在
 * - == false 不存在
 */
-(BOOL) FindDevice:(NSString *)pDeviceID;

/**
 * @brief 获取扬声器的显示名称
 * @return 返回扬声器的显示名称
 */
-(NSString *) GetDeviceName:(NSString *)pDeviceID;

/**
 * @brief 扬声器是否被占用
 * @return
 * - true 扬声器被占用
 * - false 扬声器未被占用
 */
-(BOOL) IsOccupied:(NSString *)pDeviceID;

/**
 * @brief 获取扬声器的音量
 * @return 返回扬声器的音量，取值范围为0~100，0为静音，100为音量最大值
 */
-(NSInteger) GetVolume:(NSString *)pDeviceID;

/**
 * @brief 设置扬声器的音量
 * @param uVolume 扬声器的音量，取值范围为0~100，0为静音，100为音量最大值
 * @return
 * - == true 设置成功
 * - == false 设置失败
 */
-(BOOL) SetVolume:(NSString *)pDeviceID uVolume:(NSUInteger)uVolume;

/**
 * @brief 重置麦克风设备
 * @return
 */
-(BOOL) ResetDefaultDevice;

/**
 * @brief 设置默认扬声器设备
 * @param pDeviceID 待设置的扬声器设备的ID号
 * @return
 * - == true 设置成功
 * - == false 设置失败
 */
-(BOOL) SetDefaultDevice:(NSString *)pDeviceID;

/**
 * @brief 获取默认的扬声器设备
 * @return
 * - == nullptr 没有默认的扬声器设备，一般指当前系统中无扬声器设备
 * - != nullptr 默认扬声器的ID号
 */
-(NSString *) GetCurrentDevice;

/**
 * @brief 开启扬声器的音量变化检测
 * @return
 * - == true 开启成功
 * - == false 开启失败
 * @warning
 * - 此处检测扬声器为默认扬声器
 */
-(BOOL) StartVolumeReport;

/**
 * @brief 关闭扬声器的音量变化检测
 * @return void
 */
-(void) StopVolumeReport;

/**
 * @brief 销毁扬声器管理器接口
 * @warning
 * - 调用该方法会导致，当前所有扬声器设备的接口都将无效。
 * - 调用该方法后，调用接口将不再有效，必须被置为nullptr
 */
-(void) Destory;
@end

/**************************IVideoDevice*****************************************/
@protocol IGNetVideoDevice
/**
 * @class IVideoDevice
 * @brief 视频设备接口
 */
/**
* @brief 获取视频设备的ID号
* @return 返回视频设备的ID号
*/
-(NSString *) DeviceID;

/**
 * @brief 获取视频设备的显示名称
 * @return 返回视频设备的显示名称
 */
-(NSString *) DisplayName;

/**
 * @brief 视频设备是否被占用
 * @return
 * - true 视频设备被占用
 * - false 视频设备未被占用
 */
-(BOOL) IsOccupied;

/**
 * @brief 分辨率的数量
 * @return 分辨率的数量
 */
-(NSUInteger) ResolutionCount;

/**
 * @brief 获取指定的分辨率
 * @param uWidth 分辨率的宽度
 * @param uHeight 分辨率的高度
 * @param uIndex 分辨率在列表中的偏移值（该值总是应该大于等于0. 小于从函数ResolutionCount()返回的值
 * @return
 * - == true 获取成功
 * - == false 获取失败
 */
-(BOOL) GetResolution:(NSUInteger)uWidth uHeight:(NSUInteger)uHeight uIndex:(NSUInteger)uIndex;


@end


/**************************IGNetVideoDeviceMgrEvent*****************************************/
@protocol IGNetVideoDeviceMgrEvent
/**
 * @class IVideoDeviceMgrEvent
 * @brief 视频设备管理器的事件接口
 * @details 提供视频设备热插拔通知的功能
 */
/**
* @brief 有视频设备被插入
* @param pDeviceID 新插入设备的ID号
* @return void
*/
-(void) OnDeviceAdded:(NSString *)pDeviceID;

/**
 * @brief 现有视频设备被拔出
 * @param pDeviceID 被拔出设备的ID号
 * @return void
 */
-(void) OnDeviceRemoved:(NSString *)pDeviceID;

@end

/**************************IGNetVideoDeviceMgr*****************************************/
@protocol IGNetVideoDeviceMgr
/**
 * @class IVideoDeviceMgr
 * @brief 视频设备管理器接口
 * @details 提供对当前系统中所有视频设备的管理
 */
/**
* @brief 设置视频设备管理器的事件接口
* @param pEvent 视频设备管理器的事件接口
* @return void
* @warning
* - 本方法必须在主线程环境调用，
* - 扬声器管理器有且只有一个事件接口，后设置的事件接口将替换先前设置的接口
* - 在事件接口失效之前，必须先通过SetEvent(nullptr)来通知扬声器管理器
*/
-(void) SetEvent:(id<IGNetVideoDeviceMgrEvent>)pEvent;

/**
 * @brief 获取当前系统中视频设备的数量
 * @return 视频设备数量
 */
-(NSUInteger) Count;

/**
 * @brief 获取指定视频设备的接口
 * @param nIndex 设备在管理器中的位置（0 ~ Count函数的返回值)
 * @return 返回指定设备的接口
 */
-(id<IGNetVideoDevice>)GetDevice:(NSUInteger)nIndex;

/**
 * @brief 依据设备ID获取设备的接口
 * @param pDeviceID 待查找的视频设备的ID号
 * @return
 * - == nullptr 指定视频设备不存在
 * - != nullptr 返回查找到设备的接口
 */
-(id<IGNetVideoDevice>)FindDevice:(NSString *)pDeviceID;

/**
 * @brief 设置默认视频设备
 * @param pDeviceID 待设置的视频设备的ID号
 * @return
 * - == true 设置成功
 * - == false 设置失败
 */
-(BOOL) SetDefaultDevice:(NSString *)pDeviceID;

/**
 * @brief 获取默认的视频设备
 * @return
 * - == nullptr 没有默认的视频设备，一般指当前系统中无视频设备
 * - != nullptr 默认视频的ID号
 */
-(NSString *) GetCurrentDevice;

/**
 * @brief 当前应用是否有使用摄像头设备的权限
 * @return
 * - true 有使用摄像头设备的权限
 * - false 无使用摄像头设备的权限
 */
-(BOOL) GetCameraPermission;

/**
 * @brief 销毁视频设备管理器接口
 * @warning
 * - 调用该方法会导致，当前所有视频设备的接口都将无效。
 * - 调用该方法后，调用接口将不再有效，必须被置为nullptr
 */
-(void) Destory;

@end


/**************************IGNetVideoEngine*****************************************/

@protocol IGNetVideoEngine
/**
 * @class IVideoEngine
 * @brief 视频引擎对象
 */
-(BOOL) Startup:(NSString *)strLogPath uLogLevel:(NSUInteger)uLogLevel;
-(void) Shutdown;
-(BOOL) IsShartup;
-(id<IGNetVideoDeviceMgr>)DeviceMgr;

-(BOOL) StartPreview:(NSString *)strDeviceID pWindow:(GNetViewHandle)pWindow nScaledMode:(NSUInteger)nScaledMode;//(const std::string &strDeviceID, IMemeoryRender *pRender, VideoEngineConf &vec, int32_t nScaledMode);
-(BOOL) StopPreview:(NSString *)strDeviceID;
-(BOOL) TransformPreview:(NSString *)strDeviceID nRotation:(NSUInteger)nRotation nMirrorUpdown:(NSUInteger)nMirrorUpdown nMirrorLeftRight:(NSUInteger)nMirrorLeftRight;
-(BOOL) MirrorPreviewRender:(NSString *)strDeviceID bMirrorUpdown:(BOOL)bMirrorUpdown  bMirrorLeftRight:(BOOL) bMirrorLeftRight;
-(BOOL) PauseVideo:(NSString *)strDeviceID;
-(BOOL) ResumeVideo:(NSString *)strDeviceID;

-(BOOL)  ChangeShareDevice:(NSString *)strOldDevice strNewDevice:(NSString *)strNewDevice;
-(BOOL)  ResetDevice:(NSString *)strDeviceID uWidth:(NSUInteger)uWidth uHeight:(NSUInteger)uHeight;
-(BOOL)  ResetRenderWindow:(NSString *)strDeviceID pWindow:(GNetViewHandle)pWindow nScaledMode:(NSUInteger)nScaledMode;
-(BOOL)  CameraOrientationChangeNotify:(NSString *)strDeviceID nOrientation:(NSInteger)nOrientation;

-(BOOL)  StartShare:(NSString *)strDeviceID;//(const std::string &strDeviceID, VideoEngineConf &vec);
-(BOOL)  StopShare:(NSString *)strDeviceID;
-(BOOL)  SetShareCodec:(NSString *)strDeviceID;//(const std::string &strDeviceID, VideoEngineConf &vec);

-(BOOL)  StartView:(NSUInteger)uGroupID pWindow:(GNetViewHandle)pWindow nScaledMode:(NSUInteger)nScaledMode;;// VideoEngineConf &vec, IMemeoryRender *pRender, int32_t nScaledMode);
-(BOOL)  StopView:(NSUInteger)uGroupID;
-(BOOL)  SetViewCodec:(NSUInteger)uGroupID;//(uint32_t uGroupID, VideoEngineConf &vec);
-(BOOL)  PlayVideo:(NSUInteger)uGroupID pData:(const uint8_t*)pData uDataLen:(NSUInteger)uDataLen;
-(BOOL)  ResetRenderWindowGroup:(NSUInteger)uGroupID pWindow:(GNetViewHandle)pWindow nScaledMode:(NSUInteger)nScaledMode;
-(void)  Destroy;

@end

/**************************IGNetAudioEngine*****************************************/

@protocol IGNetAudioEngine
/**
 * @class IAudioEngine
 * @brief 音频引擎对象
 */

-(BOOL) Startup:(NSString *)strLogPath;
-(void) Shutdown;
-(BOOL) IsShartup;
-(id<IGNetMicrophoneDeviceMgr>)MicrophoneDeviceMgr;
-(id<IGNetSpeakerDeviceMgr>)SpeakerDeviceMgr;
-(NSString *)GetAudioInputDevice;
-(BOOL) SetAudioInputDevice:(NSString *)pDeviceID;

//-(BOOL) StartShare:(AudioParam)param  const AudioSendFun &sendFun);
-(BOOL) StopShare;
-(void) SetMicrophoneMute:(BOOL)bMute;
-(BOOL) IsMicrophoneMute;
-(BOOL) OpenNS:(BOOL)bOpenNS;
-(BOOL) OpenAGC:(BOOL )bOpenAGC;
-(BOOL) OpenAEC:(BOOL )bOpenAEC;
-(BOOL) OpenVADandDTX:(BOOL )bOpenDTX;

-(NSString *) GetAudioOutputDevice;
-(BOOL) SetAudioOutputDevice:(NSString *)pDeviceID;
-(void)SetSpeakerMute:(BOOL)mute;
-(BOOL) IsSpeakerMute;
-(BOOL) StartAudioPlay;
-(BOOL) StopAudioPlay;
-(BOOL) PlayAudio:(const uint8_t *)pData uDataSize:(NSUInteger)uDataSize;
-(BOOL) StartMicroRealtimeVolumeReport:(id<IGNetMicrophoneDeviceMgrEvent> *)pEvent;
-(void) StopMicroRealtimeVolumeReport;
-(BOOL) StartSpeakerRealtimeVolumeReport:(id<IGNetSpeakerDeviceMgrEvent>*)pEvent;
-(void) StopSpeakerRealtimeVolumeReport;
-(BOOL) StartPlaySoundVolumeReport:(id<IGNetSpeakerDeviceMgrEvent>*)pEvent;
-(void) StopPlaySoundVolumeReport;
-(BOOL) StartPlaySound:(NSString* )pSoundPath bLoop:(BOOL)bLoop;
-(void) StopPlaySound;
-(BOOL) SetLoudspeakerStatus:(BOOL)bLoudSpeaker;
-(BOOL) GetLoudspeakerStatus;
-(void) Destroy;
-(BOOL) SetIDspMediaProcess:(void *)pProcess;
-(void) RemoveIDspMediaProcess:(void *)pProcess;

@end


/**************************IGNetLogger*****************************************/
/**
* @class NSLogger
* @brief 日记接口
* @details 提供一个和底层SDK公用的日记系统的接口
*/
@protocol IGNetLogger
/**
 * @brief 打印一行调试用的日记
 * @param pLogText 日记记录的文本信息
 * @return void
 * @warning 该日记仅在Debug版本下会被记录到日记文件中，在正式发行的版本中不记录
 */
-(void)Debug:(NSString*)pLogText;

/**
 * @brief 打印一行日记（正常级别）
 * @param pLogText 日记记录的文本信息
 * @return void
 */
-(void)Info:(NSString*)pLogText;

/**
 * @brief 打印一行日记（警告级别）
 * @param pLogText 日记记录的文本信息
 * @return void
 */
-(void)Warning:(NSString*)pLogText;

/**
 * @brief 打印一行日记（错误级别）
 * @param pLogText 日记记录的文本信息
 * @return void
 */
-(void)Error:(NSString*)pLogText;
@end

/**************************IGNetDeviceServiceEvent*****************************************/
@protocol IGNetDeviceServiceEvent
// microphone

/**
 回调麦克风音量
 @param volume 音量
 */
-(void)OnMicrophoneVolumeReport:(NSUInteger)volume;

-(void)OnMicrophoneRealtimeVolumeReport:(NSUInteger)volume;

/**
 加入麦克风设备
 @param deviceId 设备id
 */
-(void)OnMicrophoneAdded:(NSString *)deviceId;
/**
 移除麦克风设备
 @param deviceId 设备id
 */
-(void)OnMicrophoneRemoved:(NSString *)deviceId;

// speaker
/**
 扬声器音量回调
 @param volume 音量
 */
-(void)OnSpeakerVolumeReport:(NSUInteger)volume;

/**
 系统音量改变回调
 @param volume 音量
 */
-(void)OnSpeakerRealtimeVolumeReport:(NSUInteger)volume;

/**
 加入扬声器设备
 @param deviceId 设备id
 */
-(void)OnSpeakerAdded:(NSString *)deviceId;

/**
 移除扬声器设备
 @param deviceId 设备id
 */
-(void)OnSpeakerRemoved:(NSString *)deviceId;

// camera
/**
 加入摄像头设备
 @param deviceId 设备id
 */
-(void)OnCameraAdded:(NSString *)deviceId;

/**
 移除摄像头设备
 @param deviceId 设备id
 */
-(void)OnCameraRemoved:(NSString *)deviceId;

-(void)OnCameraPreviewStarted:(NSString *)deviceId;

@end

/**************************IGNetDeviceService*****************************************/


@protocol IGNetDeviceInfo

-(NSDeviceType) GetDeviceType;
-(NSString *)  GetDeviceId;
-(NSString *)  GetName;
-(BOOL)  IsDefault;
-(BOOL)  IsAvailable;

@end

@protocol IGNetMicrophoneInfo <IGNetDeviceInfo>
//-(NSUInteger)  GetVolume;
//-(BOOL)SetVolume:(NSUInteger)volume;
//-(NSString*)GetTopologyId;

@end

@protocol IGNetSpeakerInfo<IGNetDeviceInfo>
//-(NSUInteger)  GetVolume;
//-(BOOL)  SetVolume:(NSUInteger)volume;
//-(NSString*)GetTopologyId;
@end

@protocol IGNetCameraInfo<IGNetDeviceInfo>
//-(BOOL)IsMirrorUpDown;
//-(BOOL)IsMirrorLeftRight;
//-(NSInteger)GetRotation;

@end

@protocol IGNetDeviceService

// event
-(void)SetDeviceEvent:(id<IGNetDeviceServiceEvent>)event;

// microphone
/**
 加载麦克风设备列表
 @return 列表
 */
-(NSArray<id<IGNetMicrophoneInfo>>*)LoadMicrophoneList;
/**
 获取默认麦克风设备
 @return 设备id
 */
-(NSString *)GetDefaultMicrophone;

/**
 重置麦克风配置
 @param deviceId 设备id
 @return 成功or失败
 */
-(BOOL)SetDefaultMicrophone:(NSString *)deviceId;

/**
 重置麦克风
 @return 成功or失败
 */
-(BOOL)ResetDefaultMicrophone;

/**
 设置麦克风音量
 @param deviceId 设备id
 @param volume 音量大小
 @return 成功or失败
 */
-(BOOL)SetMicrophoneVolume:(NSString *)deviceId volume:(NSUInteger)volume;

/**
 获取设备音量
 @param deviceId 设备id
 @return 音量大小
 */
-(NSUInteger)GetMicrophoneVolume:(NSString *)deviceId;

/**
 开始上报设备的实时音量
 @return 成功or失败
 */
-(BOOL)StartMicrophoneRealtimeVolumeReport;

/**
 停止上报设备的实时音量
 @return 成功or失败
 */
-(BOOL)StopMicrophoneRealtimeVolumeReport;


/**
 获取当前AGC使能状态
 @return 使能、关闭
 */
-(BOOL)IsAGCEnable;

/**
 设置当前AGC使能状态

 @param enable 使能、关闭
 */
-(BOOL)EnableAGC:(BOOL)enable;


// speaker
/**
 加载扬声器设备列表
 @return 列表
 */
-(NSArray<id<IGNetSpeakerInfo>>*)LoadSpeakerList;
/**
 获取默认扬声器设备
 @return 设备id
 */
-(NSString *)GetDefaultSpeaker;

/**
 重置扬声器配置
 @param deviceId 设备id
 @return 成功or失败
 */
-(BOOL)SetDefaultSpeaker:(NSString *)deviceId;

/**
 重置扬声器配置
 @return  成功or失败
 */
-(BOOL)ResetDefaultSpeaker;

/**
 获取扬声器音量
 @param deviceId 设备id
 @return 成功or失败
 */
-(NSUInteger)GetSpeakerVolume:(NSString *)deviceId;

/**
 设置音量

 @param deviceId 设备id
 @param volume 音量
 @return 成功or失败
 */
-(BOOL)SetSpeakerVolume:(NSUInteger)volume deviceId:(NSString *)deviceId;
/**
 开始上报扬声器的实时音量
 @return 成功or失败
 */
-(BOOL)StartSpeakerRealtimeVolumeReport;
/**
 停止上报扬声器的实时音量
 @return 成功or失败
 */
-(BOOL)StopSpeakerRealtimeVolumeReport;

/**
 开始上报音频的实时音量
 @return 成功or失败
 */
-(BOOL)StartPlaySoundVolumeReport;
/**
 停止上报音频的实时音量
 @return 成功or失败
 */
-(BOOL)StopPlaySoundVolumeReport;

/**
 开始播放音频
 @param deviceId 设备id
 @param blLoop 是否循环播放
 @return 成功or失败
 */
-(BOOL)StartPlaySound:(NSString *)deviceId blLoop:(BOOL)blLoop;

/**
 停止播放
 @return 成功or失败
 */
-(BOOL)StopPlaySound;

/**
扬声器与听筒切换
@return 成功or失败
*/
-(BOOL) SetLoudspeakerStatus:(BOOL)bLoudSpeaker;

/**
获取当前是扬声器还是听筒状态
@return YES为扬声器 NO为听筒
*/

-(BOOL) GetLoudspeakerStatus;
// Camera
/**
 加载摄像头设备列表
 @return 列表
 */
-(NSArray<id<IGNetCameraInfo>>*)LoadCameraList;

/**
 获取默认摄像头id
 @return 设备id
 */
-(NSString *)GetDefaultCamera;

/**
 重置设备
 @param deviceId 设备id
 @return 成功or失败
 */
-(BOOL)SetDefaultCamera:(NSString *)deviceId;


/**
 开始预览画面
 @param deviceId 设备id
 @param pWindow 预览view
 @param iWidth 宽度
 @param iHeight 高度
 @param scaleMode 缩放比例 0是不保持比例，直接拉伸或缩放 1是按比例缩放 2应该是裁剪，切边
 @return 成功or失败
 */
-(BOOL)StartPreviewWithDeviceId:(NSString *)deviceId pWindow:(NSGNetView*)pWindow iWidth:(int)iWidth iHeight:(int)iHeight scaleMode:(NSInteger)scaleMode;


/**
 停止预览
 @param deviceId 设备id
 @return 成功or失败
 */
-(BOOL)StopPreviewWithDeviceId:(NSString *)deviceId;

/**
 画面上下翻转
 @param deviceId 设备id
 @param blMirrorUpdown 是否翻转
 @return 成功or失败
 */
-(BOOL)MirrorPreviewUpDownWithDeviceId:(NSString *)deviceId blMirrorUpdown:(BOOL)blMirrorUpdown andSyncShare:(BOOL)syncShare;

/**
 预览画面左右翻转
 @param deviceId 设备id
 @param blMirrorLeftRight 是否翻转
 @return 成功or失败
 */
-(BOOL)MirrorPreviewLeftRightWithDeviceId:(NSString *)deviceId blMirrorLeftRight:(BOOL)blMirrorLeftRight andSyncShare:(BOOL)syncShare;

/**
 预览画面旋转
 @param deviceId 设备id
 @param iRotation 旋转角度
 @return 成功or失败
 */
-(BOOL)RotationWithDeviceId:(NSString *)deviceId iRotation:(NSInteger)iRotation;

/**
 获取当前设备是否上下翻转
 @param deviceId 设备id
 @return 翻转or未翻转
 */
-(BOOL)IsMirrorUpDown:(NSString *)deviceId;

/**
 获取设备是否左右翻转
 @param deviceId 设备id
 @return 翻转or未翻转
 */
-(BOOL)IsMirrorLeftRight:(NSString *)deviceId;

 //Display
-(NSString *)LoadDisplayList;

-(BOOL) ChangePreviewDeviceId:(NSString *)oldDeviceId deviceId:(NSString *)newDeviceId;


//支持虚拟背景
-(int) EnablePortraitSegmentation:(BOOL)enable deviceId:(NSString *)deviceId;

-(int) GetEnablePortraitSegmentationState:(NSString *)deviceId;

// path: bundle file path, type: 0°™Segment 1°™Face, Default 0
-(int) SetBackGroundFile:(NSString *)path type:(int)type deviceId:(NSString *)deviceId;

// type: 0°™yuv420p 1°™rgb24
-(int) SetBackGroundData:(NSString *)path width:(int)width height:(int)height type:(int)type deviceId:(NSString *)deviceId;

-(int) SetBackGroundRotatioWithMode:(int)mode deviceId:(NSString *)deviceId;

-(int)CreatePortraitSegmentation:(NSString *)deviceId;

-(int)DestoryPortraitSegmentation:(NSString *)deviceId;

@end


@protocol IGNetStreamInfo
-(NSStreamType)GetType;
-(NSUInteger)GetStreamId;
-(NSUInteger)GetSourceId;
@end

@protocol IGNetVideoStreamInfo <IGNetStreamInfo>
-(NSString *)GetDeviceId;
@end

@protocol IGNetDektopStreamInfo <IGNetStreamInfo>
-(BOOL)IsCommentOn;
-(BOOL)IsWatermarkOn;
-(id<IGNetComment>)GetDesktopComment;

@end

@protocol IGNetWhiteboardStreamInfo <IGNetStreamInfo>
-(NSUInteger)GetPageCount;
-(id<IGNetComment>)GetWhiteBoardComment;

@end

@protocol IGNetResultInfo
-(NSUInteger)statusCode;
-(NSUInteger)returnValue;

@end


/**************************IGNetStreamServiceEvent*****************************************/
@protocol IGNetStreamServiceEvent
// streamEvent
-(void)OnStreamAdded:(NSStreamType)type andStreamId:(NSUInteger)streamId;
-(void)OnStreamRemoved:(NSStreamType)type andStreamId:(NSUInteger)streamId;

@end

@protocol IGNetVideoStreamServiceEvent

//VideoStreamEvent
-(void)OnVideoShareStarted:(NSString *)pDeviceID uGroupID:(NSUInteger)uGroupID bSucceed:(BOOL)bSucceed;
-(void)OnVideoShareStopped:(NSUInteger)uGroupId bSucceed:(BOOL)bSucceed;
-(void)OnViewResolutionChangedResult:(NSUInteger)uGroupId bSucceed:(BOOL)bSucceed;
-(void)OnVideoViewStarted:(NSUInteger)uGroupId bSucceed:(BOOL)bSucceed;

@end

@protocol IGNetAudioStreamServiceEvent

//voice
-(void)OnCallSuccess:(NSString *)pPhoneNumber;
-(void)OnCallFailed:(NSString *)pPhoneNumber uErrCode:(NSUInteger)uErrCode;
-(void)OnEnableHearInMuteResult:(NSUInteger)uErrCode bEnable:(BOOL)bEnable;
-(void)OnEnableBroadcastToneResult:(NSUInteger)uErrCode bEnable:(BOOL)bEnable;

@end

@protocol IGNetDesktopStreamServiceEvent

//DesktopStreamEvent
-(void)OnDesktopShareStarted:(NSUInteger)uResult uOperatorId:(NSUInteger)uOperatorId uGroupId:(NSUInteger)uGroupId;
-(void)OnDesktopShareStopped:(NSUInteger)uGroupId;

-(void)OnDesktopCommentOpened:(NSUInteger)uResult uGroupId:(NSUInteger)uGroupId uOperatorId:(NSUInteger)uOperatorId;
-(void)OnDesktopCommentClosed:(NSUInteger)uGroupId;
-(void)OnDesktopDeviceStatus:(NSUInteger)status andGroupId:(NSUInteger)uGroupId;
-(void)OnDesktopShareRect:(NSUInteger)streamId andRect:(CGRect)rect;
-(void)onDesktopLiveStreamStatus:(BOOL )isLiveStream;

-(void)OnAddFigure:(uint32_t)streamId addGraphics:(NSString*)addGraphicsData;
-(void)OnClear:(uint32_t)streamId pageIndex:(uint32_t)pageIndex;
-(void)OnDelFigure:(uint32_t)streamId removeGraphics:(NSString*)removedGraphicsStr;
-(void)OnDeleteLaserPointer:(uint32_t)streamId userID:(uint32_t)uUserID;
-(void)OnUpdateLaserPointer:(uint32_t)streamId userID:(uint32_t)uUserID xValue:(uint16_t)x yValue:(uint16_t)y;
-(void)OnResize:(uint32_t)streamId andPageId:(uint16_t)pageID andWidth:(uint16_t)width andHeight:(uint16_t)height andStreamType:(NSStreamType)type;

@end

@protocol IGNetWhiteBoardStreamServiceEvent

//WhiteboardStreamEvent
-(void)OnWhiteboardInstanceAdded:(uint32_t)streamId providerId:(uint32_t)providerId pageCount:(uint32_t)pageCount associateId:(uint32_t)associateId currentPage:(uint32_t)currentPage pageWidth:(uint32_t)pageWidth pageHeight:(uint32_t)pageHeight pages:(NSArray<id <IGNetPageInfo>>*)pages;
-(void)OnWhiteboardInstanceRemoved:(uint32_t)streamId;

-(void)OnAddFigure:(uint32_t)streamId addGraphics:(NSString*)addGraphicsData;
-(void)OnClear:(uint32_t)streamId pageIndex:(uint32_t)pageIndex;
-(void)OnDelFigure:(uint32_t)streamId removeGraphics:(NSString*)removedGraphicsStr;
-(void)OnDeleteLaserPointer:(uint32_t)streamId userID:(uint32_t)uUserID;
-(void)OnUpdateLaserPointer:(uint32_t)streamId userID:(uint32_t)uUserID xValue:(uint16_t)x yValue:(uint16_t)y;

-(void)OnPageAdd:(NSUInteger)uStatus uOperatorId:(NSUInteger)uOperatorId nGroupId:(NSUInteger)nGroupId uPageId:(NSUInteger)uPageId uPageWidth:(NSUInteger)uPageWidth uPageHeight:(NSUInteger)uPageHeight;
-(void)OnPageRemove:(NSUInteger)uStatus uOperatorId:(NSUInteger)uOperatorId nGroupId:(NSUInteger)nGroupId uPageId:(NSUInteger)uPageId;
-(void)OnTurnToPage:(uint32_t)uStatus operatorID:(uint32_t)uOperatorID groupId:(uint32_t)nGroupID pageId:(uint16_t)uPageID;
-(void)OnResize:(uint32_t)streamId andPageId:(uint16_t)pageID andWidth:(uint16_t)width andHeight:(uint16_t)height andStreamType:(NSStreamType)type;

@end

@protocol IGNetShareServiceEvent

//ShareEvent
-(void)OnRobShareStatus:(NSUInteger)result;

@end


/**************************IGNetStreamService*****************************************/
typedef NS_ENUM(NSInteger, StreamFilterMode) {
    TOTAL_MODE  = 0,  //不做筛选
    SPEECH_MODE = 1, //只筛选共享+主讲人视频
    SHARE_MODE = 2, // 只筛选共享
    VIDEO_MODE = 3 //只筛选视频
};

@protocol IGNetStreamService

-(void)setApplicationGroupIdentifier:(NSString *)identifier;

// event
-(void)RegisterStreamEvent:(id<IGNetStreamServiceEvent>)event;
-(void)UnRegisterStreamEvent;

-(void)RegisterAudioStreamEvent:(id<IGNetAudioStreamServiceEvent>)event;
-(void)UnregisterAudioStreamEvent;

-(void)RegisterVideoStreamEvent:(id<IGNetVideoStreamServiceEvent>)event;
-(void)UnregisterVideoStreamEvent;

-(void)RegisterDesktopStreamEvent:(id<IGNetDesktopStreamServiceEvent>)event;
-(void)UnregisterDesktopStreamEvent;

-(void)RegisterWhiteboardStreamEvent:(id<IGNetWhiteBoardStreamServiceEvent>)event;
-(void)UnregisterWhiteboardStreamEvent;

-(void)RegisterShareEvent:(id<IGNetShareServiceEvent>)event;
-(void)UnregisterShareEvent;

-(void)setStreamFilterMode:(StreamFilterMode)mode;


// StreamService

//Delay 自用

/// 主动检测当前视频流是否已在缓存队列中
/// @param streamId 流id
-(void)CheckDelayVideoStatus:(NSUInteger)streamId;
////延迟阻塞
-(BOOL)DelayStopVideoViewWithStreamId:(NSUInteger)streamId;
////延迟阻塞
-(BOOL)DelayStartVideoViewWithStreamId:(NSUInteger)streamId pWindow:(NSGNetView*)pWindow clientType:(GNETClientType)clientType resolutionType:(VideoResolutionType)resolutionType;
///对延迟的视频，立即播放
-(void)startAllDelayVideo;

-(void)setVideoResolutionType:(VideoResolutionType)resolutionType;


-(NSArray<id <IGNetStreamInfo>> *)LoadStreamList;

-(BOOL)StartVideoViewWithStreamId:(NSUInteger)streamId pWindow:(NSGNetView*)pWindow;
-(BOOL)StopVideoViewWithStreamId:(NSUInteger)streamId;

-(BOOL)StartDesktopViewWithStreamId:(NSUInteger)streamId pWindow:(NSGNetView*)pWindow;
-(BOOL)StopDesktopViewWithStreamId:(NSUInteger)streamId;

// VoiceService
-(BOOL)StartVoip;
-(BOOL)StopVoip;
-(BOOL)KeepAlive:(BOOL)bAlive;;
-(BOOL)Call:(NSArray<NSPhoneInfoModel*> *)phoneList;
-(BOOL)Hangup:(NSArray<NSPhoneInfoModel*> *)phoneList bDisconnect:(BOOL)bDisconnect;

-(BOOL)EnableBroadcastTone:(BOOL)bEnable;
-(BOOL)EnableHearInMute:(BOOL)bEnable;
-(BOOL)BindPhoneToUser:(NSUInteger)userId phoneUserId:(NSUInteger)phoneUserId;
-(BOOL)UpdatePhoneUserName:(NSString *)phoneUserName phoneUserId:(NSUInteger)phoneUserId;
-(id<IGNetVariant>)GetVoiceInfo:(NSString *)propName;
-(BOOL)MuteAll;
-(BOOL)UnmuteAll;
-(BOOL)MuteUser:(NSArray *)pUserIDArray;
-(BOOL)UnmuteUser:(NSArray *)pUserIDArray;
-(BOOL)EnablePhoneUserHandUpSupport:(BOOL)on_off;
-(BOOL)IncomingPhoneCallStatusChanged:(NSUInteger)state;

// VideoStream

-(BOOL) StartVideoShareWithDeviceId:(NSString *)deviceId;
-(BOOL) StopVideoShareWithStreamId:(NSUInteger)streamId;
-(BOOL) UpdateRecordingVideo:(NSArray*)groupIDs;
-(BOOL) ChangeVideoViewResolutionWithStreamId:(NSUInteger)streamId width:(NSUInteger)width height:(NSUInteger)height;
-(BOOL) SetVideoQualityLevelSupport:(NSUInteger)videoQualityLevel;
-(id<IGNetVideoStreamInfo>) GetVideoStreamInfo:(NSUInteger)streamId;
-(BOOL) SetHDVideo:(BOOL)enable;
-(BOOL) ChangeVideoShareDeviceWithStreamId:(NSUInteger)streamId deviceId:(NSString *)deviceId;

// DesktopStream
-(BOOL) StartDesktopShareWithDeviceId:(NSUInteger)deviceId;
-(BOOL) StopDesktopShare;
-(id<IGNetDektopStreamInfo>) GetDesktopStreamInfo:(NSUInteger)streamId;
-(BOOL) EnableWatermark:(BOOL)enable;
-(BOOL) SetWatermarkParams:(NSString *)fontName fontSize:(NSUInteger)fontSize textColor:(NSUInteger)textColor angle:(double)angle colSpace:(NSUInteger)colSpace rowSpace:(NSUInteger)rowSpace;
-(BOOL) SetWatermarkContent:(NSString *)content;

// WhiteboardStream
-(BOOL) StartWhiteboardShare:(NSUInteger)pageCount pageWidth:(NSUInteger)pageWidth pageHeight:(NSUInteger)pageHeight;
-(BOOL) StopWhiteboardShareWithStreamId:(NSUInteger)streamId;

-(BOOL) TurnToPageWithStreamId:(NSUInteger)ulStreamId usPageId:(NSUInteger)usPageId;
-(BOOL) AddPageWithStreamId:(NSUInteger)ulStreamId usPageWidth:(NSUInteger)usPageWidth usPageHeight:(NSUInteger)usPageHeight;
-(BOOL) RemovePageWithStreamId:(NSUInteger)ulStreamId usPageId:(NSUInteger)usPageId;
-(NSInteger) GetPageCountWithStreamId:(NSUInteger)ulStreamId;
-(BOOL) ClearPageWithStreamId:(NSUInteger)ulStreamId usPageId:(NSUInteger)usPageId usCleanType:(NSClearType)usCleanType;
-(NSInteger) GetCurrentPageIndexWithStreamId:(NSUInteger)ulStreamId;

-(id<IGNetWhiteboardStreamInfo>)GetWhiteboardStreamInfo:(NSUInteger)streamId;

-(BOOL)OpenCommentWithStreamId:(NSUInteger)ulStreamId andType:(NSStreamType)type;

//StreamComment
//points里面是NSArray
-(void)AddGraffitiWithGraphicID:(NSUInteger)uGraphicID andStreamId:(NSUInteger)ulStreamId andColor:(NSUInteger)uColor andStyle:(NSUInteger)uStyle andPenWidth:(NSUInteger)uPenWidth andPoints:(NSArray*)points andType:(NSStreamType)type;

-(void)UpdateArrowLaserInfoWithStreamId:(NSUInteger)ulStreamId WithGraphicID:(NSUInteger)uGraphicID
                               dataInfo:(NSString*)dataInfo andType:(NSStreamType)type;

-(void)RemoveArrowLaserInfoWithStreamId:(NSUInteger)ulStreamId WithGraphicID:(NSUInteger)uGraphicID andType:(NSStreamType)type;

-(void)UpdateShapeInfoWithStreamId:(NSUInteger)ulStreamId WithGraphicID:(NSUInteger)uGraphicID dataInfo:(NSString*)dataInfo andType:(NSStreamType)type;

-(void)AddFigureWithStreamId:(NSUInteger)ulStreamId graphicID:(NSUInteger)uGraphicID dataInfo:(NSString*)dataInfo andType:(NSStreamType)type;

-(void)DelFigureWithStreamId:(NSUInteger)ulStreamId graphicID:(NSUInteger)uGraphicID andType:(NSStreamType)type;

-(void)PullFigureWithStreamId:(NSUInteger)ulStreamId pageID:(NSUInteger)uPageID andType:(NSStreamType)type;

-(NSInteger)GetNextSerial;

-(id<IGNetPageInfo>)GetPageInfoByPageId:(NSUInteger)pageId andStreamId:(NSUInteger)streamId andStreamType:(NSStreamType)streamType;

-(id<IGNetPageInfo>)GetPageInfoByPageIndex:(NSUInteger)pageIndex andStreamId:(NSUInteger)streamId;

-(BOOL)UpdateLaserPointerWithStreamId:(NSUInteger)ulStreamId withXValue:(CGFloat)x withYValue:(CGFloat)y andType:(NSStreamType)type;

-(BOOL)DelLaserPointerWithStreamId:(NSUInteger)ulStreamId andType:(NSStreamType)type;

//Share
-(id<IGNetResultInfo>) CheckShare;

//支持虚拟背景
-(int) EnablePortraitSegmentation:(BOOL)enable deviceId:(NSString *)deviceId;

-(int) GetEnablePortraitSegmentationState:(NSString *)deviceId;

// path: bundle file path, type: 0°™Segment 1°™Face, Default 0
-(int) SetBackGroundFile:(NSString *)path type:(int)type deviceId:(NSString *)deviceId;

// type: 0°™yuv420p 1°™rgb24
-(int) SetBackGroundData:(NSString *)path width:(int)width height:(int)height type:(int)type deviceId:(NSString *)deviceId;

-(int) SetBackGroundRotatioWithMode:(int)mode;

@end


/**************************IGNetMeetingGroupEvent*****************************************/
@protocol IGNetMeetingGroupEvent<NSObject>

/**
 * @brief 加入会议成功
 * @param pTangMeeting 加入的会议接口
 * @return void
 */
-(void) OnJoinMeetingSucceed:(id<IGNetMeeting>)meeting;

/**
 * @brief 加入会议失败
 * @param uMeetingID 加入失败的会议ID
 * @param uErrCode 出错代码
 * @param pErrMsg 出错描述
 * @return void
 */
-(void) OnJoinMeetingFailed:(NSInteger)statusCode;

-(void)OnNetworkReport:(bool)result upLossRate:(unsigned char)upLossRate downLossRate:(unsigned char)downLossRate rtt:(unsigned short)rtt jitter:(int)jitter;

@end


/**************************IGNetUserServiceEvent****************************************/
@protocol IGNetUserServiceEvent<NSObject>

/**
 * @brief 会议中新添加多个用户
 * @param pUsersID 待添加的用户ID的数组
 * @param uCount 用户ID数组中用户的数量
 * @return void
 */
-(void)OnUsersAdded:(NSArray*)pUsersID count:(NSUInteger)uCount;;

/**
 * @brief 多个用户离开会议
 * @param pUsersID 待删除的用户ID的数组
 * @param uCount 用户ID数组中用户的数量
 * @return void
 */
-(void)OnUsersRemoved:(NSArray*)pUsersID count:(NSUInteger)uCount;;

/**
 * @brief 用户属性发生变化
 * @param uUserID 用户ID
 * @param pPropertiesEvent 发生改变的属性的更新信息
 * @return void
 */
-(void)OnUserPropertiesChanged:(NSUInteger)uUserID userPropertiesEvent:(id<IGNetUserPropertiesEvent>)pPropertiesEvent;

-(void)OnSwitchRoleFailed:(NSUInteger)errorID srcUserId:(NSUInteger)uSrcUser destUserId:(NSUInteger)uDestUser andRoles:(NSArray<NSNumber*>*)pRoles;

-(void)OnRecoverRoleFailed:(NSUInteger)errorID fromUserId:(NSUInteger)uFromUser andRoles:(NSArray<NSNumber*>*)pRoles;

/**
 * @brief 角色被剥夺
 * @param uOperatorID 角色剥夺动作的发起者
 * @param pRoles 被剥夺的角色
 * @param uRoleCount 被剥夺的角pRoles中的角色数量
 * @return void
 */
-(void)OnRoleLost:(NSUInteger)uOperatorID andRoles:(NSArray<NSNumber*>*)pRoles uRoleCount:(NSUInteger)uRoleCount;

@end

/**************************IGNetUserService****************************************/
@protocol IGNetUserService
-(void)setEvent:(id<IGNetUserServiceEvent>)event;
/**
 * @brief 获取在线用户数量
 * @return 返回的当前在线用户的数量
 */
-(NSUInteger)OnlineUserCount;

/**
 * @brief 获取电话用户数量（纯电话用户与使用PSTN语音用户的数量）
 * @return 返回的当前电话用户的数量
 */
-(NSUInteger)PhoneUserCount;

/**
* @brief 获取在线用户
* @return 返回的当前在线用户数组
*/
-(NSArray<id<IGNetUser>>*)GetOnlineUsers;

/**
 * @brief 当前用户
 * @return 当前用户的接口
 */
-(id<IGNetUser>)Self;

/**
 * @brief 查找用户
 * @param uUserID 待查找的用户ID
 * @return 当前用户的接口
 */
-(id<IGNetUser>)Find:(NSUInteger)uUserID;

/**
 * @brief 为指定用户设置角色列表
 * @param uUserID 添加角色的用户
 * @param pRoles 待添加的角色列表
 * @param uCount pRoles列表中的角色数量
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)SetPowers:(NSUInteger)uUserID powers:(NSArray*)pPowers;

/**
 * @brief 为指定用户添加角色列表
 * @param pUsers 添加角色的用户集合
 * @param pRoles 待添加的角色列表
 * @param uCount pRoles列表中的角色数量
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)AddPower:(NSArray *)pUsers powers:(NSArray*)pPowers;

/**
 * @brief 为指定用户移除角色列表
 * @param vecUserID 移除角色的用户集合
 * @param pRoles 待移除的角色列表
 * @param uCount pRoles列表中的角色数量
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)RemovePower:(NSArray *)pUsers powers:(NSArray*)pPowers;

/**
 * @brief 在两个用户之间转移指定角色
 * @param uSrcUserID 转出用户
 * @param uDestUserID 转入用户
 * @param uSwitchedRole 待转移的角色
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)SwitchUserPower:(NSUInteger)uSrcUserID destUserID:(NSUInteger)uDestUserID switchedPower:(NSUInteger)uSwitchedPower;

/**
 * @brief 从指定用户回收指定能力
 * @param fromUserId 从该用户身上回收
 * @param power 待回收的能力
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)RecoverUserPower:(NSUInteger)fromUserId  switchedPower:(NSUInteger)uSwitchedPower;

/**
 * @brief 踢掉指定用户
 * @param uUserID 待被踢掉的用户ID
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)Kickout:(NSUInteger)uUserID;

/**
 * @brief 修改数据用户的名称
 * @param dataUserId 数据用户的ID
 * @param dataUserNam 数据用户的新名称
 * @return
 * - == true 请求投递成功
 * - == false 请求投递失败
 */
-(BOOL)UpdateUserRawData:(NSUInteger)dataUserId dataUserNam:(NSString *)dataUserName;



@end


/**************************IGNetMeetingGroup*****************************************/

@protocol IGNetMeetingGroup

/**
* @brief 设置endpoint的事件接口
* @return void
* @warning
*/
-(void)setEvent:(id<IGNetMeetingGroupEvent>)event;

/**
 * @brief 获取日记接口
 * @return 日记接口的指针
 * @warning 日记为一个单体
 */
-(id<IGNetLogger>)GetLogger;

/**
 * @brief 获取视频引擎接口
 * @return 视频引擎接口的指针
 * @warning 视频引擎为一个单体
 */
-(id<IGNetVideoEngine>)GetVideoEngine;

/**
 * @brief 获取音频引擎接口
 * @return 音频引擎接口的指针
 * @warning 音频引擎为一个单体
 */
-(id<IGNetAudioEngine>)GetAudioEngine;

/**
 * @brief 获取会议配置文件的版本
 * @param
 * @return
 */
-(NSUInteger)GetMeetingModuleConfigFileVersion;

/**
* @brief 更新会议模块配置文件
* @param  jsonStr json字符串
* @return
*/
-(void)UpdateMeetingModuleConfigFile:(NSString*)jsonStr;

/**
 * @brief 获取SDK的版本号
 * @return 标识版本号的字符串
 */
-(NSString*) GetVersion;

/**
 * @brief 加入会议
 * @param pJoinKey 进入会议的吊起串
 * @param uMeetingID 返回从吊起串中解析出的会议ID
 * @return
 * - true 加入会议的请求已经成功发出去，但会议是否真实被创建成功，将从IEndpointEvent接口的事件 OnCreateMeetingSucceed 与 OnCreateMeetingFailed 返回
 * - false 加入会议的请求未成功发布，加入会议失败
 */
-(NSUInteger)JoinMeeting:(NSString*)pJoinKey;

/**
 * @brief 依据会议ID查找会议接口
 * @param uMeetingID 会议ID
 * @return
 * - == nullptr 指定的会议不存在
 * - != nullptr 返回查找到的会议接口
 */
-(id<IGNetMeeting>)FindMeeting:(NSUInteger)uMeetingID;

/**
 * @brief 取消指定的会议，一般用在joinMeeing后还没有入会的情况
 * @param uMeetingID 会议ID
 * @return
 * - true 操作成功，OnJoinMeetingFailed 返回
 * - false 操作失败，会议id不存在
 */
-(BOOL)CancelMeeting:(NSUInteger)uMeetingID;

/**
 * @brief 销毁终端接口
 * @warning
 * - 调用该方法会导致，当前终端加入的所有会议都被退出。
 * - 调用该方法后，调用接口将不再有效，必须被置为nullptr
 */
-(void)Destory;

-(BOOL)isInMeeting;

// room 接口
-(id <IGNetDeviceService>)GetDeviceService;

-(id <IGNetStreamService>)GetStreamService;

-(id<IGNetUserService>)GetUserService;

-(void)OnQuitMeeting:(NSUInteger)uMeetingId;

@end

@interface NSGNetService : NSObject

+(NSGNetService*)getInstance;

- (id<IGNetLogger>)GetLogger;

-(NSString*) GetVersion;

-(NSUInteger)GetMeetingModuleConfigFileVersion;

-(void)UpdateMeetingModuleConfigFile:(NSString*)jsonStr;

-(void)joinMeeting:(NSString*)pConfigPath joinKey:(NSString*)joinKey event:(id<IGNetMeetingGroupEvent>)event;

-(void)destroy;

// room 接口
-(id <IGNetDeviceService>)GetDeviceService;

-(id <IGNetStreamService>)GetStreamService;

-(id<IGNetUserService>)GetUserService;

-(BOOL)cancelMeeting;

-(BOOL)isInMeeting;

@end



#endif
