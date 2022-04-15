//
//  CHttpUtil.h
//
//  Created by quanshi on 15/5/14.
//  Copyright (c) 2015年 quanshi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CHttpUtil : NSObject

+ (CHttpUtil *)getInstance;


- (NSDictionary*)webAPICreateConference:(NSString*)siteURL appID:(NSString*)appID arguments:(NSDictionary*)arguInfo;
- (NSDictionary*)webAPIJoinConference:(NSString*)siteURL appID:(NSString*)appID arguments:(NSDictionary*)arguInfo;
- (void)webAPIDeleteConference:(NSString*)siteURL appID:(NSString*)appID arguments:(NSDictionary*)arguInfo;


- (NSDictionary*) webAPICloudMeetingGetMeetingToken:(NSString*)siteURL arguments:(NSDictionary *)arguInfo;

@end
