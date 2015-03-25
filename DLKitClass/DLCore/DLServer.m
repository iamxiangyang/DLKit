//
//  DLServer.m
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLServer.h"
#import "MKNetworkEngine.h"

@implementation DLServer

+ (void)Login: (NSString *)userName pass: (NSString *)pass completeBlock: (void (^)(DLResponse * response))complete {
    
    DLRequest * request = [[DLRequest alloc] initWithURLString:@"your api path" params:@{} httpMethod:@"your type"];
    [request addCompletionHandler:^(MKNetworkOperation *completedOperation) {
       
        complete([DLResponse data:[completedOperation responseData]]);
    } errorHandler:^(MKNetworkOperation *completedOperation, NSError *error) {
        [DLError Error:error];
    }];
    [[DLEnginPool shareEngin].HttpEngin enqueueOperation:request];
}

+ (void)GET:  (NSString *)path completeBlock: (void (^)(DLResponse * response))complete {

    DLRequest * request = (DLRequest *)[[DLEnginPool shareEngin].HttpEngin operationWithPath:path params:nil httpMethod:@"GET"];
    [request addCompletionHandler:^(MKNetworkOperation *completedOperation) {
        
        complete([DLResponse data:[completedOperation responseData]]);
    } errorHandler:^(MKNetworkOperation *completedOperation, NSError *error) {
        
        [DLError Error:error];
    }];
    [[DLEnginPool shareEngin].HttpEngin enqueueOperation:request];
}

+ (void)POST: (NSString *)path param: (NSDictionary *)param file: (NSDictionary *)file completeBlock: (void (^)(DLResponse * response))complete progressBlock:(void (^)(double progress))currentProgress {
    
    DLRequest * request = (DLRequest *)[[DLEnginPool shareEngin].HttpEngin operationWithPath:path params:param httpMethod:@"POST"];
    if (file != nil && file.count > 0) {
        
        for (NSString * key in file.allKeys) {
            
            [request addFile:file[key] forKey:key];
        }
        
        [request onUploadProgressChanged:^(double progress) {
           
            if (currentProgress) {
                currentProgress(progress);
            }
        }];
    }
    [request addCompletionHandler:^(MKNetworkOperation *completedOperation) {
       
        complete([DLResponse data:[completedOperation responseData]]);
    } errorHandler:^(MKNetworkOperation *completedOperation, NSError *error) {
        
        [DLError Error:error];
    }];
    [[DLEnginPool shareEngin].HttpEngin enqueueOperation:request];
}

@end
