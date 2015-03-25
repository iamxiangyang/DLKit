//
//  NSArray+DLExtension.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "NSArray+DLExtension.h"

@implementation NSArray (DLExtension)

- (id)safeObjectAtIndex:(NSUInteger)index {
    if ( index >= self.count )
        return nil;
    
    return [self objectAtIndex:index];
}

@end

@implementation NSMutableArray (DLExtension)

- (void)safeAddObject:(id)anObject {
    if (anObject) {
        [self addObject:anObject];
    }
}

-(bool)safeInsertObject:(id)anObject atIndex:(NSUInteger)index {
    if ( index >= self.count && index != 0) {
        return NO;
    }
    
    if (!anObject) {
        return NO;
    }
    
    [self insertObject:anObject atIndex:index];
    
    return YES;
}

-(bool)safeRemoveObjectAtIndex:(NSUInteger)index {
    if ( index >= self.count ) {
        return NO;
    }
    [self removeObjectAtIndex:index];
    return YES;
    
}

-(bool)safeReplaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
    if ( index >= self.count ) {
        return NO;
    }
    [self replaceObjectAtIndex:index withObject:anObject];
    return YES;
}

@end
