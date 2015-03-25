//
//  DLEnginPool.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLEnginPool.h"
#import "MKNetworkEngine.h"

static DLEnginPool * pool;
@implementation DLEnginPool

+ (instancetype)shareEngin {
    
    @synchronized(self)
    {
        if (!pool) {
            
            pool = [[DLEnginPool alloc] init];
            [pool initlizedEngin];
        }
        return pool;
    }
}

- (void)initlizedEngin {
    
    self.HttpEngin = [[MKNetworkEngine alloc] initWithHostName:DL_SERVER_HOSTNAMR];
    self.FileEngin = [[MKNetworkEngine alloc] initWithHostName:DL_SERVER_FILESERVER];
    self.socketEngin = [[MKNetworkEngine alloc] initWithHostName:DL_SERVER_SOCKET_IP portNumber:DL_SERVER_SOCKET_PORT apiPath:DL_SERVER_SOCKET_PATH customHeaderFields:nil];
}

+ (MKNetworkEngine *)newEngin: (NSString *)hostName {
    
    return [[MKNetworkEngine alloc] initWithHostName:hostName];
}

@end
