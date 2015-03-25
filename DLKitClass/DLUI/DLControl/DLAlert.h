//
//  DLAlert.h
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ClickAtIndex)(NSInteger index);

@interface DLAlert : NSObject <UIAlertViewDelegate>

/**
 *  Alert View
 *
 *  @param title             Alert title
 *  @param message           Alert Message
 *  @param cancelButtonTitle cancel button
 *  @param otherButtonTitle  another button
 *  @param indexBlock        blocks
 */
+ (UIAlertView *)initWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitle:(NSString *)otherButtonTitle clickBlock: (ClickAtIndex)indexBlock;

@end
