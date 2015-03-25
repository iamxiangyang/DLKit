//
//  NSArray+DLExtension.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (DLExtension)

- (id)safeObjectAtIndex:(NSUInteger)index;

@end

@interface NSMutableArray (DLExtension)

// safe Actions
- (void)safeAddObject:(id)anObject;
-(bool)safeInsertObject:(id)anObject atIndex:(NSUInteger)index;
-(bool)safeRemoveObjectAtIndex:(NSUInteger)index;
-(bool)safeReplaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

@end