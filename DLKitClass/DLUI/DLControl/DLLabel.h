//
//  DLLabel.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DLLabel : UILabel

// label inset
@property (nonatomic, assign) UIEdgeInsets contentInsets;

- (id)initWithText:(NSString *)text
              font:(UIFont *)font
         textColor:(UIColor *)color;

- (id)initWithText:(NSString *)text
              font:(UIFont *)font
         textColor:(UIColor *)color
   backgroundColor:(UIColor *)backgroundColor;


@end
