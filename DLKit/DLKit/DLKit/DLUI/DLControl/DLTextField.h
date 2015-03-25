//
//  DLTextField.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DLTextField : UITextField

// placeholder color
@property (nonatomic, retain) UIColor *placeholderTextColor;
// placeholder font
@property (nonatomic, retain) UIFont *placeholderFont;
// text padding
@property (nonatomic, assign) UIEdgeInsets textInsets;

@end
