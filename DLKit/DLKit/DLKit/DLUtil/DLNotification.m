//
//  DLNotification.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLNotification.h"

static DLNotification * notification;
@implementation DLNotification

+ (instancetype)shareNotification {
    
    @synchronized(self)
    {
        if (!notification) {
            
            notification = [[DLNotification alloc] init];
            [notification initlized];
        }
        return notification;
    }
}

- (void)initlized {
    
    _CoreNotification = [NSNotificationCenter defaultCenter];
}

- (void)Post: (NSString *)name object: (id)obj {
    
    [_CoreNotification postNotificationName:name object:obj];
}

- (void)Post: (NSNotification *)notification {
    
    [_CoreNotification postNotification:notification];
}

- (void)Add: (id)server selector: (SEL)method name: (NSString *)name object: (id)obj {
    
    [_CoreNotification addObserver:server selector:method name:name object:obj];
}

- (void)Rem: (id)server name: (NSString *)name object: (id)obj {
    
    [_CoreNotification removeObserver:server name:name object:obj];
}

+ (NSString *)MakeNotificationName: (NSString *)KeyWord {
    
    return [NSString stringWithFormat:@"DLNotification_Generate_%@", KeyWord];
}

@end
