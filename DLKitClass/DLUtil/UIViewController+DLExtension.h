//
//  UIViewController+DLExtension.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (DLExtension)

- (void)showToolbar:(BOOL)animated;
- (void)hideToolbar:(BOOL)animated;
- (void)moveToolbar:(CGFloat)deltaY animated:(BOOL)animated;
- (void)setToolbarOriginY:(CGFloat)y animated:(BOOL)animated;

- (void)showTabBar:(BOOL)animated;
- (void)hideTabBar:(BOOL)animated;
- (void)moveTabBar:(CGFloat)deltaY animated:(BOOL)animated;
- (void)setTabBarOriginY:(CGFloat)y animated:(BOOL)animated;

- (void)setLeftBarItem:(UIView*) view;
- (void)setRightBarItem:(UIView*) view;
- (void)setTitleView:(UIView*)view;
- (void)setBackButton;
- (void)setBackToRootButtonNotPressedStyle;
- (void)setBackButtonNotPressedStyle;
- (void)setBackButtonNotPressedStyle:(SEL)selecor;

@end
