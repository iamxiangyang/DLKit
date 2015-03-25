//
//  DLCache.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLCache.h"

@implementation DLCache

+ (DLCache *)getCacheQueue {
    
    return [DLCache globalCache];
}

@end
