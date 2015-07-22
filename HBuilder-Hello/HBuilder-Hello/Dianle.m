//
//  Dianle.m
//  HBuilder-Hello
//
//  Created by noprom on 15/7/22.
//  Copyright (c) 2015年 DCloud. All rights reserved.
//

#import "Dianle.h"

@implementation Dianle


/**
 *  展示点乐积分墙
 *
 *  @param commands <#commands description#>
 */
- (void)shouDianle:(PGMethod *)commands
{
    if ( commands ) {
        
        // CallBackid 异步方法的回调id，H5+ 会根据回调ID通知JS层运行结果成功或者失败
        NSString* cbId = [commands.arguments objectAtIndex:0];
        
        // 用户的参数会在第二个参数传回
        NSString* pArgument1 = [commands.arguments objectAtIndex:1];
        NSString* pArgument2 = [commands.arguments objectAtIndex:2];
        NSString* pArgument3 = [commands.arguments objectAtIndex:3];
        NSString* pArgument4 = [commands.arguments objectAtIndex:4];
        
        // 如果使用Array方式传递参数
        NSArray* pResultString = [NSArray arrayWithObjects:pArgument1, pArgument2, pArgument3, pArgument4, nil];
        
        // ========= 貌似要在这里面写代码么 ========= //
        
        // 实现点乐SDK代理
        [JJSDK setDelegate:self];
        
        // 展示点乐积分墙
        [JJSDK showJJDiamondWithViewController:self];
        
        // ========= 貌似要在这里面写代码么 ========= //
        
        // 运行Native代码结果和预期相同，调用回调通知JS层运行成功并返回结果
        PDRPluginResult *result = [PDRPluginResult resultWithStatus:PDRCommandStatusOK messageAsArray: pResultString];
        
        // 如果Native代码运行结果和预期不同，需要通过回调通知JS层出现错误，并返回错误提示
        //PDRPluginResult *result = [PDRPluginResult resultWithStatus:PDRCommandStatusError messageAsString:@"惨了! 出错了！ 咋(wu)整(liao)"];
        
        // 通知JS层Native层运行正确结果
        [self toCallback:cbId withReslut:[result toJSONString]];
    }
}

@end
