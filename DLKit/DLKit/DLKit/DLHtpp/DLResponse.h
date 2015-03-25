//
//  DLResponse.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLResponse : NSObject

@property (nonatomic, strong) NSDictionary * responseDict;
@property (nonatomic, strong) id object;
@property (nonatomic, strong) NSString  * responseString;
@property (nonatomic, strong) NSData    * responseData;

+ (instancetype)data: (NSData *)responseData;
- (instancetype)initWithData: (NSData *)responseData;

/* Add your custom properties here for response */

@end
