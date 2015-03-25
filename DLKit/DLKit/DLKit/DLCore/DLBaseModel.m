//
//  DLBaseModel.m
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLBaseModel.h"

@implementation DLBaseModel

// - - - - - - - subclass needs reload - - - - - - - //

// has next or more data
- (BOOL)hasNext {
    return NO;
}
- (BOOL)hasPrev {
    return NO;
}

// appoint page
- (void)goFirstPage {
    
}
- (void)goPage: (NSUInteger)pageNum {
    
}

// Append or prepend current data
- (void)mergeNextPage {
    
}
- (void)mergePrevPage {
    
}

// replace current data
- (void)goNextPage {
    
}
- (void)goPrevPage {
    
}

@end
