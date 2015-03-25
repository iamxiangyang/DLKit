//
//  DLAlert.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLAlert.h"

static ClickAtIndex staticBlock;
@implementation DLAlert

+ (UIAlertView *)initWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitle:(NSString *)otherButtonTitle clickBlock: (ClickAtIndex)indexBlock {
    
    staticBlock = indexBlock;
    return [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitle, nil];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    if (staticBlock) {
        staticBlock(buttonIndex);
    }
}

- (void)alertViewCancel:(UIAlertView *)alertView{
    
}

@end
