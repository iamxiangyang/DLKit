# DLKit
DLKit is a collection of useful classes to develop Apps faster

- DLHttp
    - DLEnginPool
    - DLResponse
    - DLRequest
- DLUtil
    - b64
    - DLError
    - DLNotification
    - UIImage+DLExtension
    - UIView+DLExtension
    - UIColor+DLExtension
    - UIViewcontroller+DLExtension
    - NSArray / NSMutableArray + DLExtension
    - NSDictionary / NSMutableDictionary + DLExtension
    - NSObject+DLExtension
    - DLTouchID
- DLCore
    - DLBaseModel
    - DLServer
    - DLCache
    - DLDefaults
- DLThird
    - UIDeviceUtil
    - UIView+Toast
    - EGOCache
    - MKNetworkKit
- DLUI
    - DLControl
        - DLAlert
        - DLButton
        - DLPageControl
        - DLImageView
        - DLTextField
        - DLLabel
        - DLTipView
    - DLAnimation
        - DLAnimation
- DLKit.h

---

DLHttp

- DLEnginPool

```
+ (instancetype)shareEngin;

// Global http engin and file engin
@property (nonatomic, strong) MKNetworkEngine * HttpEngin;
@property (nonatomic, strong) MKNetworkEngine * FileEngin;

// Get new Engin
+ (MKNetworkEngine *)newEngin: (NSString *)hostName;

// Global socket engin
@property (nonatomic, strong) MKNetworkEngine * socketEngin;
```

- DLResponse

```
@property (nonatomic, strong) NSDictionary * responseDict;
@property (nonatomic, strong) id object;
@property (nonatomic, strong) NSString  * responseString;
@property (nonatomic, strong) NSData    * responseData;

+ (instancetype)data: (NSData *)responseData;
- (instancetype)initWithData: (NSData *)responseData;

/* Add your custom properties here for response */
```

- DLRequest

```
@property (nonatomic, assign) NSInteger errorCode;

/* Add your custom properties here for request */
```

DLUtil

- b64

```
NSData * b64_encode( NSData * data );
NSData * b64_decode( NSData * data );
void decodeblock( unsigned char in[4], unsigned char out[3] );
```

- DLError

```
// log with string
+ (void)ErrorMessage: (NSString *)message;

// log with error
+ (void)Error: (NSError *)error;

// throw exception immediately! or you use @try @catch
+ (void)ThrowException: (NSException *)exception;

// catch your restraint
+ (void)Assert: (NSInteger)condition desc: (NSString *)descript;

// create exception and throw it
+ (void)throwExceptionWithName:(NSString *)name reason:(NSString *)reason userInfo:(NSDictionary *)userInfo;

@property (nonatomic, strong) NSString * errorMessage;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, strong) NSDictionary * errorInfo;

// DLError
+ (DLError *)errorWithInfo: (NSDictionary *)info Code: (NSInteger)code;
+ (DLError *)errorWithMessage: (NSString *)message Code: (NSInteger)code;

// show error message alert
- (void)showErrorAlert;

// Error description
- (NSString *)descriptions;
```

- DLNotifications

```

+ (instancetype)shareNotification;

@property (nonatomic, strong) NSNotificationCenter * CoreNotification;

- (void)Post: (NSString *)name object: (id)obj;
- (void)Post: (NSNotification *)notification;

- (void)Add: (id)server selector: (SEL)method name: (NSString *)name object: (id)obj;
- (void)Rem: (id)server name: (NSString *)name object: (id)obj;

/* Net   Notification Center */

/* Error Notification Center */

/* Play Notification Name */
+ (NSString *)MakeNotificationName: (NSString *)KeyWord;

/* Create subclass for Net notification and Error Notification */
```

- Extensions /* UIImage, UIView, UIColor, UIImageView...  */
- Extensions /* NSArray, NSMutableArray, NSDictionary.. */
- TouchID (BFKit_TouchID)

```
+ (void)showTouchIDAuthenticationWithReason:(NSString *)reason completion:(void (^)(TouchIDResult result))completion;
```

DLCore

- DLBaseModel

```
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
```

- DLServer

```
+ (void)GET:  (NSString *)path completeBlock: (void (^)(DLResponse * response))complete;
+ (void)POST: (NSString *)path param: (NSDictionary *)param file: (NSDictionary *)file completeBlock: (void (^)(DLResponse * response))complete progressBlock: (void (^)(double progress))currentProgress;
```

- DLCache
- DLDefaults

```
- (instancetype)initWithkey: (NSString *)key;

- (id)objectForKey:(NSString *)defaultName;
- (void)setObject:(id)value forKey:(NSString *)defaultName;
- (void)removeObjectForKey:(NSString *)defaultName;

- (NSString *)stringForKey:(NSString *)defaultName;
- (NSArray *)arrayForKey:(NSString *)defaultName;
- (NSDictionary *)dictionaryForKey:(NSString *)defaultName;
- (NSData *)dataForKey:(NSString *)defaultName;
- (NSArray *)stringArrayForKey:(NSString *)defaultName;
- (NSInteger)integerForKey:(NSString *)defaultName;
- (float)floatForKey:(NSString *)defaultName;
- (double)doubleForKey:(NSString *)defaultName;
- (BOOL)boolForKey:(NSString *)defaultName;
- (NSURL *)URLForKey:(NSString *)defaultName;

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName;
- (void)setFloat:(float)value forKey:(NSString *)defaultName;
- (void)setDouble:(double)value forKey:(NSString *)defaultName;
- (void)setBool:(BOOL)value forKey:(NSString *)defaultName;
- (void)setURL:(NSURL *)url forKey:(NSString *)defaultName;
```

DLThird

- UIDeviceUtil

```
/** This method retruns the hardware type */
+ (NSString*)hardwareString;

/** This method returns the Hardware enum depending upon harware string */
+ (Hardware)hardware;

/** This method returns the readable description of hardware string */
+ (NSString*)hardwareDescription;

/** This method returns the readable simple description of hardware string */
+ (NSString*)hardwareSimpleDescription;

/**
 This method returns the hardware number not actual but logically.
 e.g. if the hardware string is 5,1 then hardware number would be 5.1
 */
+ (float)hardwareNumber:(Hardware)hardware;

/** This method returns the resolution for still image that can be received
 from back camera of the current device. Resolution returned for image oriented landscape right. **/
+ (CGSize)backCameraStillImageResolutionInPixels;

```

- UIView+Toast

```
// each makeToast method creates a view and displays it as toast
- (void)makeToast:(NSString *)message;
- (void)makeToast:(NSString *)message duration:(NSTimeInterval)interval position:(id)position;
- (void)makeToast:(NSString *)message duration:(NSTimeInterval)interval position:(id)position image:(UIImage *)image;
- (void)makeToast:(NSString *)message duration:(NSTimeInterval)interval position:(id)position title:(NSString *)title;
- (void)makeToast:(NSString *)message duration:(NSTimeInterval)interval position:(id)position title:(NSString *)title image:(UIImage *)image;

// displays toast with an activity spinner
- (void)makeToastActivity;
- (void)makeToastActivity:(id)position;
- (void)hideToastActivity;

// the showToast methods display any view as toast
- (void)showToast:(UIView *)toast;
- (void)showToast:(UIView *)toast duration:(NSTimeInterval)interval position:(id)point;
- (void)showToast:(UIView *)toast duration:(NSTimeInterval)interval position:(id)point
      tapCallback:(void(^)(void))tapCallback;
```

- EGOCache
- MKNetworkKit

DLUI

- DLALert

```
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
```

- DLButton

```
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
```

- DLPageControl

```

@property (nonatomic, strong) UIImage *imagePageStateNormal;
@property (nonatomic, strong) UIImage *imagePageStateHighlighted;

/**
 *  set PageControl indicator sepration distance
 */
@property (nonatomic, assign) NSInteger pageIndicatorSpacing;

/**
 *  set PageControl page counts
 *
 *  @param totalPageNumber    total count
 *  @param currentPageNumber  current page_num
 */
- (void)setTotalAndCurrentPageNumber:(NSInteger)totalPageNumber
                   currentPageNumber:(NSInteger)currentPageNumber;

/**
 *  set PageControl images
 *
 *  @param normalImage          normal image
 *  @param highlightedImage     highlight image
 */
- (void)setImageOfPageNormalAndHighlighted:(UIImage *)normalImage
                          highlightedImage:(UIImage *)highlightedImage;

/**
 *  set PageControl
 *
 *  @param normalImage          normal color
 *  @param highlightedImage     highlight image
 */
- (void)setColorOfBackgroundAndCurrentPageIndicator:(UIColor *)colorOfBackground
                        colorOfCurrentPageIndicator:(UIColor *)colorOfCurrentPageIndicator;

```

- DLImageView

```

// The full-color image
@property (nonatomic, retain) UIImage *image;

// From 0.0 to 1.0
@property (nonatomic, assign) CGFloat progress;

// Default is bottom to top
@property (nonatomic, assign) DLColorizedProgressViewDirection direction;

// The duration of the progress bar animation, in seconds, to go from 0% to 100% uninterrupted.
// The update animation speed is based on this value. Default is 1 second.
@property (nonatomic, assign) CGFloat totalAnimationDuration;

// When animating, there is a delay between when the target progress is set and
// when the actual progress catches up. This block will be invoked when the progress bar
// has completed animating. It returns the current progress.
@property (nonatomic, copy) DLColorizedCompletionBlock completionBlock;

// Initialize with an image and set the bounds to the image's size
- (id)initWithImage:(UIImage *)image;

// Set the progress with an animation
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

// Cancels a running animation
- (void)stopAnimation;

// Adjusts the frame to fit the image
- (void)sizeToFit;

```

- DLTextField

```
// placeholder color
@property (nonatomic, retain) UIColor *placeholderTextColor;
// placeholder font
@property (nonatomic, retain) UIFont *placeholderFont;
// text padding
@property (nonatomic, assign) UIEdgeInsets textInsets;
```

- DLLabel

```
- (id)initWithText:(NSString *)text
              font:(UIFont *)font
         textColor:(UIColor *)color;

- (id)initWithText:(NSString *)text
              font:(UIFont *)font
         textColor:(UIColor *)color
   backgroundColor:(UIColor *)backgroundColor;
```

- DLTipView

```

/**
 * @param rect frame
 * @param text text
 * @param textFont text font
 * @param arrowMargin boult position
 * @param orientation boult direction
 */
- (id)initWithRect:(CGRect)rect
              text:(NSString *)text
          textFont:(UIFont *)textFont
       arrowMargin:(CGFloat)margin
  arrowOrientation:(DLTipArrowOrientation)orientation;

/**
 * @param rightIcon right image icon
 */
- (id)initWithRect:(CGRect)rect
         textArray:(NSArray *)textArray
          textFont:(UIFont *)textFont
       arrowMargin:(CGFloat)margin
  arrowOrientation:(DLTipArrowOrientation)orientation
         rightIcon:(NSString*)rightIcon;

/**
 * @param textLabelOrigin label position
 */
- (id)initWithRect:(CGRect)rect
         textArray:(NSArray *)textArray
          textFont:(UIFont *)textFont
       arrowMargin:(CGFloat)margin
  arrowOrientation:(DLTipArrowOrientation)orientation
         rightIcon:(NSString *)rightIcon
   textLabelOrigin:(CGPoint)textOrigin;

/**
 *  Dismiss
 */
- (void)dismissTip;

```

- DLAnimations

```
// 根据视图出现的动画类型返回相应动画
+ (CAAnimation *)animationWithActionType:(DLAnimationActionType)type;

// 根据视图出现的动画类型返回相应动画
+ (CAAnimation *)animationWithAppearType:(DLAnimationAppearType)type;

// 根据视图出现的动画类型返回相应动画
+ (CAAnimation *)animationWithDisappearType:(DLAnimationDisappearType)type;

// 根据视图出现的动画类型返回相应动画
+ (CAAnimation *)animationWithCellType:(DLAnimationCellType)type;


+ (CAAnimation *)fadeInWithDuration:(NSTimeInterval)duration;
+ (CAAnimation *)fadeOutWithDuration:(NSTimeInterval)duration;
+ (CAAnimation *)rotateWithDuration:(NSTimeInterval)duration;
+ (CAAnimation *)wiggleWithDuration:(NSTimeInterval)duration repeatCount:(NSUInteger)count;
+ (CAAnimation *)shakeWithDuration:(NSTimeInterval)duration repeatCount:(NSUInteger)count;
+ (CAAnimation *)rippleWithDuration:(NSTimeInterval)duration repeatCount:(NSUInteger)count;
+ (CAAnimation *)stretchWithDuration:(NSTimeInterval)duration repeatCount:(NSUInteger)count;
+ (CAAnimation *)popWithDuration:(NSTimeInterval)duration;
+ (CAAnimation *)popDisappearWithDuration:(NSTimeInterval)duration;

```

DLKit.h

```
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

```

---

/  *CopyRight @ 2015 Wild Dylan*  /
MIT Objective-c