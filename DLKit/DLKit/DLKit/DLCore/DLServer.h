//
//  DLServer.h
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

// Default request time out
#define DL_TIMEOUT_SECOND               15.0f
// notification when request failed
#define DLServerAPIFailedNotification   @"DLServerAPIFailedNotification"
// NSError Domain
#define DLServerAPIErrorDomain          @"com.dl.serverapi"

// API Access status, DLServer.state
typedef enum {

    DL_PROCESS_CREATED = 1,
    DL_PROCESS_LOADING,
    DL_PROCESS_SUCCEED,
    DL_PROCESS_FAILED,
    DL_PROCESS_CANCELED
}DLProcessState;

typedef enum {

    DLERROR_SUCCEED,            // Succeed
    DLERROR_NETWORK_ERROR,      // Network Excepte
    DLERROR_DATAFORMAT_ERROR,   // Empty Data or Json format error...
    DLERROR_SERVER_ERROR        // Server Abnormal
}DLErrorEnum;

@class DLServer, DLEnginPool, DLResponse;

// Server block api
typedef void (^DLServerAPICompletionBlock)(DLResponse *response);

@interface DLServer : NSObject

// login api sample -> build subclass for custom handle
+ (void)Login: (NSString *)userName pass: (NSString *)pass completeBlock: (void (^)(DLResponse * response))complete;

/**********************************************************/
+ (void)GET:  (NSString *)path completeBlock: (void (^)(DLResponse * response))complete;
+ (void)POST: (NSString *)path param: (NSDictionary *)param file: (NSDictionary *)file completeBlock: (void (^)(DLResponse * response))complete progressBlock: (void (^)(double progress))currentProgress;

@end
