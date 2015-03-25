//
//  NSData+DLExtension.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (DLExtension)

- (NSData *)MD5;
- (NSString *)MD5String;
- (NSString *)UTF8String;

+ (NSData *)dataFromBase64String:(NSString *)base64String;
- (id)initWithBase64String:(NSString *)base64String;
- (NSString *)base64EncodedString;

@end
