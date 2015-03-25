//
//  DLDefaults.m
//  DLKit
//
//  Created by XueYulun on 15/3/25.
//  Copyright (c) 2015年 X. All rights reserved.
//

#import "DLDefaults.h"

@implementation DLDefaults

- (instancetype)initWithkey: (NSString *)key {
    
    self = [super init];
    if (self) {
        
        self.storeKey = key;
    }
    return self;
}

- (id)objectForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] objectForKey:[self getRealDefaultName:defaultName ]];
}

- (void)setObject:(id)value forKey:(NSString *)defaultName {
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:[self getRealDefaultName:defaultName ]];
    [[NSUserDefaults standardUserDefaults]  synchronize];
}

- (void)removeObjectForKey:(NSString *)defaultName {
    [[NSUserDefaults standardUserDefaults]removeObjectForKey:[self getRealDefaultName:defaultName ]];
}

- (NSString *)stringForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults]stringForKey:[self getRealDefaultName:defaultName ]];
}

- (NSArray *)arrayForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults]arrayForKey:[self getRealDefaultName:defaultName ]];
}

- (NSDictionary *)dictionaryForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] dictionaryForKey:[self getRealDefaultName:defaultName ]];
}

- (NSData *)dataForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] dataForKey:[self getRealDefaultName:defaultName ]];
}

- (NSArray *)stringArrayForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] stringArrayForKey:[self getRealDefaultName:defaultName ]];
}

- (NSInteger)integerForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] integerForKey:[self getRealDefaultName:defaultName ]];
}

- (float)floatForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] floatForKey:[self getRealDefaultName:defaultName ]];
}

- (double)doubleForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] doubleForKey:[self getRealDefaultName:defaultName ]];
}

- (BOOL)boolForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] boolForKey:[self getRealDefaultName:defaultName ]];
}

- (NSURL *)URLForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] URLForKey:[self getRealDefaultName:defaultName ]];
}

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] setInteger:value forKey:[self getRealDefaultName:defaultName ]];
}

- (void)setFloat:(float)value forKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] setFloat:value forKey:[self getRealDefaultName:defaultName ]];
}

- (void)setDouble:(double)value forKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] setDouble:value forKey:[self getRealDefaultName:defaultName ]];
}

- (void)setBool:(BOOL)value forKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] setBool:value forKey:[self getRealDefaultName:defaultName ]];
}

- (void)setURL:(NSURL *)url forKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] setURL:url forKey:[self getRealDefaultName:defaultName ]];
}

-(NSString*)getRealDefaultName:(NSString*)name {
    /* your custom string */
    return [NSString stringWithFormat:@">_<%@", _storeKey];
}

@end
