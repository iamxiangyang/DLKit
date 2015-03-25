//
//  DLError.h
//  DLKit
//
//  Created by XueYulun on 15/3/24.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLError : NSObject

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

@end
