/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RBModuleLevel)
{
    RBModuleBasic  = 0,
    RBModuleNormal = 1
};

typedef NS_ENUM(NSInteger, RBModuleEventType)
{
    RBMSetupEvent = 0,
    RBMInitEvent,
    RBMTearDownEvent,
    RBMSplashEvent,
    RBMQuickActionEvent,
    RBMWillResignActiveEvent,
    RBMDidEnterBackgroundEvent,
    RBMWillEnterForegroundEvent,
    RBMDidBecomeActiveEvent,
    RBMWillTerminateEvent,
    RBMUnmountEvent,
    RBMOpenURLEvent,
    RBMDidReceiveMemoryWarningEvent,
    RBMDidFailToRegisterForRemoteNotificationsEvent,
    RBMDidRegisterForRemoteNotificationsEvent,
    RBMDidReceiveRemoteNotificationEvent,
    RBMDidReceiveLocalNotificationEvent,
    RBMWillPresentNotificationEvent,
    RBMDidReceiveNotificationResponseEvent,
    RBMWillContinueUserActivityEvent,
    RBMContinueUserActivityEvent,
    RBMDidFailToContinueUserActivityEvent,
    RBMDidUpdateUserActivityEvent,
    RBMHandleWatchKitExtensionRequestEvent,
    RBMDidCustomEvent = 1000
    
};


@class RBModule;

@interface RBModuleManager : NSObject

+ (instancetype)sharedManager;

// If you do not comply with set Level protocol, the default Normal
- (void)registerDynamicModule:(Class)moduleClass;

- (void)registerDynamicModule:(Class)moduleClass
       shouldTriggerInitEvent:(BOOL)shouldTriggerInitEvent;

- (void)unRegisterDynamicModule:(Class)moduleClass;

- (void)loadLocalModules;

- (void)registedAllModules;

- (void)registerCustomEvent:(NSInteger)eventType
         withModuleInstance:(id)moduleInstance
             andSelectorStr:(NSString *)selectorStr;

- (void)triggerEvent:(NSInteger)eventType;

- (void)triggerEvent:(NSInteger)eventType
     withCustomParam:(NSDictionary *)customParam;



@end

