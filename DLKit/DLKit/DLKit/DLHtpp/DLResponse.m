//
//  DLResponse.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLResponse.h"

@implementation DLResponse

+ (instancetype)data: (NSData *)responseData {
    
    return [[DLResponse alloc] initWithData:responseData];
}

- (instancetype)initWithData: (NSData *)responseData {
    
    self = [super init];
    if (self) {
        
        /* Add your custom operate here for response result */
        
        NSError * error = nil;
        _responseDict = [NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingMutableContainers error:&error];
        if (error) {
            [DLError Error:error];
        }
        
        _object = _responseDict ? _responseDict : nil;
        
        _responseString = [[NSString alloc] initWithData:responseData encoding:NSUTF8StringEncoding];
        
        _responseData = responseData;
    }
    
    return self;
}

@end
