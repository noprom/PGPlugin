//
//  PublicCallList.h
//  YouMiSDK
//
//  Created by Layne on 12-01-05.
//  Copyright (c) 2012年 YouMi Mobile Co. Ltd. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "PublicCallConfig.h"
#import "PublicCallListAppModel.h"
#import "PublicCallPointsManager.h"
#import "publicHeader.h"

@interface PublicCallList : NSObject
/*! 启动有米积分墙
 */
+ (void)PublicCallMyEnable;

/*! 显示积分墙
 * \param rewarded 是不是有积分模式
 * \param didShowBlockIn 成功显示积分墙时执行的block
 * \param didDismissBlockIn 关闭积分墙后执行的block
 * \returns 是否显示积分墙成功，积分墙显示不成功并不会调用didShowBlockIn和didDismissBlockIn
 */
+ (BOOL)PublicCallShowOffers:(BOOL)PublicRewarded PublicCallDidShowBlock:(void (^)(void))PublicCallDidShowBlock PublicDidDismissBlock:(void (^)(void))PublicDidDismissBlockIn;


/*
 *关闭积分墙
 */
+ (void)PublicCallClose;


/*! 获取积分墙的App广告列表【源数据的接口】
 * \param rewarded 是不是有积分模式
 * \param page 请求的数据第几页
 * \param count 每页有多少个广告（比如设置的requestPage为1，adCountPage为3.那么数据就可以看成是每页3个应用的形式在服务器上，每次请求服务器就把对应页的3个应用返回）
 * \param recievedBlock 接收广告列表的block, 其中NSArray的内容是 @[PublicCallListAppModel, PublicCallListAppModel...]; 获取列表失败, 在NSError里有记录.
 */
+ (void)PublicRequestOffersOpenData:(BOOL)PublicCallRewarded PublicCallPage:(NSInteger)PublicCallRequestPage PublicCallCount:(NSInteger)PublicCallAdCountPage PublicCallRevievedBlock:(void (^)(NSArray*theApps, NSError *error))PublicCallRecievedBlock;

/*! 安装积分墙中的APP【源数据的接口】
 * \param app 通过requestOffersOpenData获得的APP
 */
+ (void)PublicCallUserInstallApp:(PublicCallListAppModel *)PublicCallApp;


/*! 获取积分墙的App广告列表-----有提审任务跟追加任务【源数据的接口】
 * \param rewarded 是不是有积分模式
 * \param page 请求的数据第几页
 * \param count 每页有多少个广告（比如设置的requestPage为1，adCountPage为3.那么数据就可以看成是每页3个应用的形式在服务器上，每次请求服务器就把对应页的3个应用返回）
 * \param recievedBlock 接收广告列表的block, 其中theNormalApps的内容是 @[PublicCallListAppModel, PublicCallListAppModel...]; 获取列表失败, 在NSError里有记录.
 * moreTaskApp是追加任务
 */
+ (void)PublicRequestOffersOpenDataMoreAD:(BOOL)PublicCallRewarded PublicCallPage:(NSInteger)PublicCallRequestPage PublicCallCount:(NSInteger)PublicCallAdCountPage PublicCallRevievedBlock:(void (^)(NSArray *theNormalApps,NSArray *moreTaskApp, NSError *error))PublicCallRecievedBlock;


// !!!:提审【源数据的接口】
/*
 status:0  提审成功，等待审核给分
 status:402 还没开始任务
 status:404 还没完成
*/
+ (void)PublicCallReview:(PublicCallListAppModel *)PublicCallApp PublicCallRecievedBlock:(void(^)(int status))callBack;

// !!!:开始追加任务【源数据的接口】
/*
 isSuccess:1  成功开始进行深度任务
 isSuccess:0  应用没安装，不能进行深度任务
 */
+ (void)PublicCallBeginMoreTask:(PublicCallListAppModel *)PublicCallApp PublicCallRecievedBlock:(void(^)(BOOL isSuccess))callBack;
@end


