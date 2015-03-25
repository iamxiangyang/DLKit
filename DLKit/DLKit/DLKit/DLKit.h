//
//  DLKit.h
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#ifndef DLKit_DLKit_h
#define DLKit_DLKit_h

#import "DLBaseModel.h"
#import "DLServer.h"
#import "DLCache.h"

#import "DLEnginPool.h"
#import "DLResponse.h"
#import "DLRequest.h"

#import "DLError.h"
#import "DLDefaults.h"
#import "DLNotification.h"

#import "DLButton.h"
#import "DLAlert.h"
#import "DLPageControl.h"
#import "DLImageView.h"
#import "DLTextField.h"
#import "DLLabel.h"
#import "DLTipView.h"

#import "UIImage+DLExtension.h"
#import "UIView+DLExtension.h"
#import "UIColor+DLExtension.h"
#import "UIViewController+DLExtension.h"
#import "NSArray+DLExtension.h"
#import "NSDictionary+DLExtension.h"
#import "NSObject+DLExtension.h"

#import "UIView+Toast.h"
#import "UIDeviceUtil.h"

#import "DLTouchID.h"

#define _XLOG 1

#ifdef  _XLOG

#define	XLogOut(format,...);      NSLog(format, ##__VA_ARGS__);
#define XLogOutMethodFun          NSLog( @"[%@] %@", NSStringFromClass([self class]), NSStringFromSelector(_cmd) );
#define XLogError(format,...);    NSLog(@"[error][%s][%d]" format,__func__,__LINE__,##__VA_ARGS__);
#define XLogWaring(format,...);   NSLog(@"[waring][%s][%d]" format,__func__,__LINE__,##__VA_ARGS__);
#define	XLogTeym(format,...);     {}

#else

#define XLogOut(format,...);      {}
#define XLogOutMethodFun          {}
#define XLogError(format,...);    {}
#define XLogWaring(format,...);   {}
#define	XLogTeym(format,...);     {}

#endif

#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

#endif
