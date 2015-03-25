//
//  DLEnginPool.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DL_SERVER_HOSTNAMR      @"xx-nb.cn"
#define DL_SERVER_FILESERVER    @"xx-nb.im/upload"

#define DL_SERVER_SOCKET_IP     @"216.12.21.14"
#define DL_SERVER_SOCKET_PORT   8899
#define DL_SERVER_SOCKET_PATH   @"api/app/server"

@class MKNetworkEngine;
@interface DLEnginPool : NSObject

+ (instancetype)shareEngin;

// Global http engin and file engin
@property (nonatomic, strong) MKNetworkEngine * HttpEngin;
@property (nonatomic, strong) MKNetworkEngine * FileEngin;

// Get new Engin
+ (MKNetworkEngine *)newEngin: (NSString *)hostName;

// Global socket engin
@property (nonatomic, strong) MKNetworkEngine * socketEngin;

@end
