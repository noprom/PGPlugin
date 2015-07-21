//
//  PublicCallConfig.h
//  YouMiSDK
//
//  Created by Layne on 12-5-2.
//  Copyright (c) 2012年 YouMi Mobile Co. Ltd. All rights reserved.
//
//  sdk version 5.2.5


#import <UIKit/UIKit.h>
#import "publicHeader.h"

@interface PublicCallConfig : NSObject

// 应用ID
//
// 详解:
//      前往有米主页:http://www.youmi.net/ 注册一个开发者帐户，同时注册一个应用，获取对应应用的ID与秘钥
//
+ (void)PublicCallLaunchWithAppID:(NSString *)PublicCallAppid PublicCallAppSecret:(NSString *)PublicCallAecret;


/*! 设置全屏广告显示在的window [建议设置]
 *
 *! 使用原生ObjectiveC代码的APP, 可以在[AppDelegate application:didFinishLaunchingWithOptions:]里[self.window makeKeyAndVisible];后设置[YouMiConfi setFullScreenWindow:self.window];
 *
 *! Unity3D的window代码比较隐藏得比较深，可以不设置
 *
 *! Cocos2d-x 可以在[AppController application:didFinishLaunchingWithOptions:]里[window makeKeyAndVisible];后设置[YouMiConfi setFullScreenWindow:window];
 *
 * \params window APP的主window，一般情况下每个APP有且只有一个window，在APP启动完成后生成，覆盖整个屏幕，所有视图都放在它里面.
 */
+ (void)PublicCallSetFullScreenWindow:(UIWindow *)PublicCallWindow;

// 设置UserID
//
// 详解:
//      可用于服务器对接获取积分
//      详情请看：http://wiki.youmi.net/%E5%AF%B9%E5%BC%80%E5%8F%91%E8%80%85%E7%9A%84%E7%A7%AF%E5%88%86%E5%8F%8D%E9%A6%88%E6%8E%A5%E5%8F%A3
//
+ (void)PublicCallSetUserID:(NSString *)PublicCallUserID;
+ (NSString *)PublicCallUserID;
@end
