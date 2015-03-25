//
//  DLBaseModel.h
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLBaseModel : NSObject

// Total page count
@property (nonatomic, assign, getter=totalPageCount) NSUInteger totalCount;

// Page item number
@property (nonatomic, assign) NSUInteger pageSize;

// current page number
@property (nonatomic, assign) NSUInteger currentPage;

// begin number
@property (nonatomic, assign) NSUInteger startPage;

// has next or more data
- (BOOL)hasNext;
- (BOOL)hasPrev;

// appoint page
- (void)goFirstPage;
- (void)goPage: (NSUInteger)pageNum;

// Append or prepend current data
- (void)mergeNextPage;
- (void)mergePrevPage;

// replace current data
- (void)goNextPage;
- (void)goPrevPage;

@end
