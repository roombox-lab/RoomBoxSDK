/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import "RBAnnotation.h"
@class RBContext;
@class BeeHive;

#define RB_EXPORT_MODULE(isAsync) \
+ (void)load { [RBBeeHive registerDynamicModule:[self class]]; } \
-(BOOL)async { return [[NSString stringWithUTF8String:#isAsync] boolValue];}


@protocol RBModuleProtocol <NSObject>


@optional

//如果不去设置Level默认是Normal
//basicModuleLevel不去实现默认Normal
- (void)basicModuleLevel;
//越大越优先
- (NSInteger)modulePriority;

- (BOOL)async;

- (void)modSetUp:(RBContext *)context;

- (void)modInit:(RBContext *)context;

- (void)modSplash:(RBContext *)context;

- (void)modQuickAction:(RBContext *)context;

- (void)modTearDown:(RBContext *)context;

- (void)modWillResignActive:(RBContext *)context;

- (void)modDidEnterBackground:(RBContext *)context;

- (void)modWillEnterForeground:(RBContext *)context;

- (void)modDidBecomeActive:(RBContext *)context;

- (void)modWillTerminate:(RBContext *)context;

- (void)modUnmount:(RBContext *)context;

- (void)modOpenURL:(RBContext *)context;

- (void)modDidReceiveMemoryWaring:(RBContext *)context;

- (void)modDidFailToRegisterForRemoteNotifications:(RBContext *)context;

- (void)modDidRegisterForRemoteNotifications:(RBContext *)context;

- (void)modDidReceiveRemoteNotification:(RBContext *)context;

- (void)modDidReceiveLocalNotification:(RBContext *)context;

- (void)modWillPresentNotification:(RBContext *)context;

- (void)modDidReceiveNotificationResponse:(RBContext *)context;

- (void)modWillContinueUserActivity:(RBContext *)context;

- (void)modContinueUserActivity:(RBContext *)context;

- (void)modDidFailToContinueUserActivity:(RBContext *)context;

- (void)modDidUpdateContinueUserActivity:(RBContext *)context;

- (void)modHandleWatchKitExtensionRequest:(RBContext *)context;

- (void)modDidCustomEvent:(RBContext *)context;
@end
