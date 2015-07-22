//
//  Dianle.h
//  HBuilder-Hello
//
//  Created by noprom on 15/7/22.
//  Copyright (c) 2015年 DCloud. All rights reserved.
//

#include "PGPlugin.h"
#include "PGMethod.h"
#import "AppDelegate.h"

@interface Dianle : PGPlugin<JJSDKDelegate>

// 展示点乐的积分墙
- (void)shouDianle:(PGMethod*)command;

@end
