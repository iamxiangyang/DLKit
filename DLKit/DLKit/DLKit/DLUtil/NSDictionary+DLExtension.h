//
//  NSDictionary+DLExtension.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (DLExtension)

-(NSData*)data;

/* your custom handle here */

@end

@interface NSMutableDictionary (DLExtension)

- (void)safeSetObject:(id)anObject forKey:(id<NSCopying>)aKey;
- (void)safeRemoveObjectForKey:(id)aKey;

/* your custom handle here */

@end