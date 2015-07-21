//
//  PGPluginTest.h
//  HBuilder-Hello
//
//  Created by noprom on 15/7/21.
//  Copyright (c) 2015年 DCloud. All rights reserved.
//

#include "PGPlugin.h"
#include "PGMethod.h"
#import <Foundation/Foundation.h>

@interface PGPluginTest : PGPlugin


- (void)PluginTestFunction:(PGMethod*)command;
- (void)PluginTestFunctionArrayArgu:(PGMethod*)command;

- (NSData*)PluginTestFunctionSync:(PGMethod*)command;
- (NSData*)PluginTestFunctionSyncArrayArgu:(PGMethod*)command;
@end