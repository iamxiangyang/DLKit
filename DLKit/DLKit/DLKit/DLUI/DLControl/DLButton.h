//
//  DLButton.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLButton : NSObject

/**
 *  Button
 *
 *  @param type           button type
 *  @param frame          button frame
 *  @param title          button title
 *  @param color          title color
 *  @param BGImage        background image
 *  @param highLightImage highloght image
 *  @param object         target object
 *  @param sec            action
 *  @param buttonEvent    for events
 */
+ (UIButton *)buttonType: (UIButtonType)type frame: (CGRect)frame title: (NSString *)title titleColor: (UIColor *)color backGroundImage: (UIImage *)BGImage highLightImage: (UIImage *)highLightImage target: (id)object Selector: (SEL)sec selectorState: (UIControlEvents)buttonEvent;

@end
