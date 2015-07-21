//
//  AppDelegate.m
//  Pandora
//
//  Created by Mac Pro_C on 12-12-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"
#import "PDRCore.h"
#import "PDRCommonString.h"
#import "PublicCallList.h"   //有米,AppDelegate.m文件中初始化PublicCallSDK
#import "PublicCallConfig.h" //有米,AppDelegate.m文件中初始化PublicCallSDK

@implementation AppDelegate

@synthesize window = _window;

#pragma mark -
#pragma mark app lifecycle



/*
 * @Summary:程序启动时收到push消息
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [PDRCore Instance].launchOptions = launchOptions;
    [[PDRCore Instance] load];

    // *** 以下代码为初始化有米SDK *** //
    
    [PublicCallConfig PublicCallSetUserID:@"000e4b1fca15c80a"];// [可选]
    
    // 例如开发者的应用是有登录功能的，则可以使用登录后的用户账号来替代有米为每台机器提供的标识（有米会为每台设备生成的唯一标识符）。
    [PublicCallConfig PublicCallLaunchWithAppID:@"000e4b1fca15c80a" PublicCallAppSecret:@"27b23746f4756bc3"];
    
    [self.window makeKeyAndVisible];
    // 设置显示全屏广告的window
    [PublicCallConfig PublicCallSetFullScreenWindow:self.window];
    
    // 初始化积分墙
    [PublicCallList PublicCallMyEnable];
    
        
    // *** 以上代码为初始化有米SDK *** //

    
    return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventEnterBackground withObject:nil];
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventEnterForeGround withObject:nil];
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}


- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [[PDRCore Instance] unLoad];
}

#pragma mark -
#pragma mark URL

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {
    [self application:application handleOpenURL:url];
    return YES;
}

/*
 * @Summary:程序被第三方调用，传入参数启动
 *
 */
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventOpenURL withObject:url];
    return YES;
}


#pragma mark -
#pragma mark APNS
/*
 * @Summary:远程push注册成功收到DeviceToken回调
 *
 */
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventRevDeviceToken withObject:deviceToken];
}

/*
 * @Summary: 远程push注册失败
 */
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventRegRemoteNotificationsError withObject:error];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventRevRemoteNotification withObject:userInfo];
}

/*
 * @Summary:程序收到本地消息
 */
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    [[PDRCore Instance] handleSysEvent:PDRCoreSysEventRevLocalNotification withObject:notification];
}

- (void)dealloc
{
    [super dealloc];
}

@end
