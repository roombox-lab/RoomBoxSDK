/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
#import <UserNotifications/UserNotifications.h>
#endif


@interface RBAppDelegate : UIResponder <UIApplicationDelegate>

@end

typedef void (^RBNotificationResultHandler)(UIBackgroundFetchResult);
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
typedef void (^RBNotificationPresentationOptionsHandler)(UNNotificationPresentationOptions options);
typedef void (^RBNotificationCompletionHandler)();
#endif

@interface RBNotificationsItem : NSObject

@property (nonatomic, strong) NSError *notificationsError;
@property (nonatomic, strong) NSData *deviceToken;
@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, copy) RBNotificationResultHandler notificationResultHander;
@property (nonatomic, strong) UILocalNotification *localNotification;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
@property (nonatomic, strong) UNNotification *notification;
@property (nonatomic, strong) UNNotificationResponse *notificationResponse;
@property (nonatomic, copy) RBNotificationPresentationOptionsHandler notificationPresentationOptionsHandler;
@property (nonatomic, copy) RBNotificationCompletionHandler notificationCompletionHandler;
@property (nonatomic, strong) UNUserNotificationCenter *center;
#endif

@end

@interface RBOpenURLItem : NSObject

@property (nonatomic, strong) NSURL *openURL;
@property (nonatomic, copy) NSString *sourceApplication;
@property (nonatomic, strong) id annotation;
@property (nonatomic, strong) NSDictionary *options;

@end

typedef void (^RBShortcutCompletionHandler)(BOOL);

@interface RBShortcutItem : NSObject

#if __IPHONE_OS_VERSION_MAX_ALLOWED > 80400
@property(nonatomic, strong) UIApplicationShortcutItem *shortcutItem;
@property(nonatomic, copy) RBShortcutCompletionHandler scompletionHandler;
#endif

@end


typedef void (^RBUserActivityRestorationHandler)(NSArray *);

@interface RBUserActivityItem : NSObject

@property (nonatomic, copy) NSString *userActivityType;
@property (nonatomic, strong) NSUserActivity *userActivity;
@property (nonatomic, strong) NSError *userActivityError;
@property (nonatomic, copy) RBUserActivityRestorationHandler restorationHandler;

@end

typedef void (^RBWatchReplyHandler)(NSDictionary *replyInfo);

@interface RBWatchItem : NSObject

@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, copy) RBWatchReplyHandler replyHandler;

@end


