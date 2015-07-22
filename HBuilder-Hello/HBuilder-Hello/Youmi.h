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


#import <UIKit/UIKit.h>
#import "PublicCallConfig.h"
#import "PublicCallList.h"
#import "PublicCallPointsManager.h"
#import "PublicCallListAppModel.h"
#import "PublicCallPointsManager.h" //(用于查询积分)

@interface Youmi : PGPlugin


- (void)PluginTestFunction:(PGMethod*)command;
- (void)PluginTestFunctionArrayArgu:(PGMethod*)command;

- (NSData*)PluginTestFunctionSync:(PGMethod*)command;
- (NSData*)PluginTestFunctionSyncArrayArgu:(PGMethod*)command;
@end