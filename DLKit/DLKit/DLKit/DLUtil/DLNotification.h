//
//  DLNotification.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLNotification : NSObject

+ (instancetype)shareNotification;

@property (nonatomic, strong) NSNotificationCenter * CoreNotification;

- (void)Post: (NSString *)name object: (id)obj;
- (void)Post: (NSNotification *)notification;

- (void)Add: (id)server selector: (SEL)method name: (NSString *)name object: (id)obj;
- (void)Rem: (id)server name: (NSString *)name object: (id)obj;

/* Net   Notification Center */

/* Error Notification Center */

/* Play Notification Name */
+ (NSString *)MakeNotificationName: (NSString *)KeyWord;

/* Create subclass for Net notification and Error Notification */

@end