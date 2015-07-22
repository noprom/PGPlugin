//
//  JJSDK.h
//  JJSDK
//
//  Created by Noodles Wang on 10/11/13.
//  Copyright (c) 2013 Noodles Wang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - JJSDKDelegate protocol

@protocol JJSDKDelegate <NSObject>

@optional
/**
 *  减分成功
 *
 *  @param JJPointsAmounts 最新余额
 *  @param currencyName      分数类型
 */
- (void)spendJJPointsSuccess:(int)JJPointsAmounts currency:(NSString *)currencyName;
/**
 *  减分失败
 *
 *  @param error 失败原因描述
 */
- (void)spendJJPointsFail:(NSError *)error;
/**
 *  加分成功
 *
 *  @param JJPointsAmounts 最新余额
 *  @param currencyName      分数类型
 */
- (void)awardJJPointsSuccess:(int)JJPointsAmounts currency:(NSString *)currencyName;
/**
 *  加分失败
 *
 *  @param error 失败原因描述
 */
- (void)awardJJPointsFail:(NSError *)error;
/**
 *  获取用户当前分数成功
 *
 *  @param JJPointsAmounts 最新余额
 *  @param currencyName      分数类型
 */
- (void)getUserJJPointsSuccess:(int)JJPointsAmounts currency:(NSString *)currencyName;
/**
 *  获取用户当前分数失败
 *
 *  @param error 失败原因描述
 */
- (void)getUserJJPointsFail:(NSError *)error;
/**
 *  取回开发者自定义参数成功
 *
 *  @param param 参数值
 */
- (void)fetchParameterDefineByDeveloperSuccess:(NSString *)param;
/**
 *  取回开发者自定义参数失败
 *
 *  @param error 失败原因描述
 */
- (void)fetchParameterDefineByDeveloperFail:(NSError *)error;
@end

#pragma mark - JJSDK class
/**
 *  JJ SDK 核心类，向开发者提供JJ可用的类方法和协议方法
 */
@interface JJSDK : NSObject
/**
 *  应用的ID
 */
@property (nonatomic, strong) NSString *appID;
/**
 *  开发者自定义的用户ID，用于追踪用户行为。
 */
@property (nonatomic, strong) NSString *userID;

+ (id)sharedJJSDK;

/**
 *  通知服务器app开始运行，一般加载app启动方法中。
 *
 *  @param appID  应用ID
 *  @param userID 用户ID
 */
+ (void)requestJJSession:(NSString*)appID withUserID:(NSString*)userID;

#pragma mark - 方法用于积分墙操作

+ (void)setDelegate:(id<JJSDKDelegate>)delegate;

+ (void)spendJJPoints:(int)points;

+ (void)awardJJPoints:(int)points;

+ (void)getUserJJPoints;

+ (void)fetchParameterDefineByDeveloper:(NSString*)key;

#pragma mark - 打开Diamond
//+ (UIView *)showDiamond; TODO in next version
/**
 *  显示积分墙，直接显示在view堆栈的最前端。diamond加载成功或失败，将以两个notification形式通知
 *
 *  @param vController 成为JJWebViewController的parentviewcontroller
 */
+ (void)showJJDiamondWithViewController:(UIViewController *)vController;
@end
