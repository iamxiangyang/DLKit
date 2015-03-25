//
//  NSDictionary+DLExtension.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "NSDictionary+DLExtension.h"

@implementation NSDictionary (DLExtension)

-(NSData*)data {
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:self];
    return data;
}

@end

@implementation NSMutableDictionary (DLExtension)

- (void)safeSetObject:(id)anObject forKey:(id < NSCopying >)aKey {
    if (!anObject || !aKey) {
        return ;
    }
    
    [self setObject:anObject forKey:aKey];
}

- (void)safeRemoveObjectForKey:(id)aKey {
    if(!aKey)
        return;
    
    [self removeObjectForKey:aKey];
}


@end