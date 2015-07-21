//
//  PublicCallPointsManager.h
//  YouMiSDK
//
//  Created by ENZO YANG on 13-4-25.
//  Copyright (c) 2013年 YouMi Mobile Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "publicHeader.h"

// !!!！重要!!!! Important !!!!
// [自动积分管理]及[手动积分管理]的概念请查看文档

// [自动积分管理][手动积分管理]通用
// 获得积分通知, userInfo 格式如下, 建议收到积分通知后打印userInfo观察一下里面的结构。
// @{ PublicCallKPointsManagerFreshPointsKey: @210,
//    PublicCallKPointsManagerPointInfosKey: @[
//      @{
//          PublicCallKPointsManagerPointUserIDKey: @"user10086",
//          PublicCallKPointsManagerPointAmountKey: @100,
//          PublicCallKPointsManagerPointProductNameKey: @"WY新闻"
//      },
//      ...
//    ]
// }
extern NSString *PublicCallKPointsManagerRecivedPointsNotification;


// 使用下面这个 key 从 Notification userInfo 中获得积分 [适用于自动积分管理]
// 不要消耗从这个Key获取到的积分，如果使用自动积分管理请使用[PublicCallPointsManager spendPoints:]来消耗积分
extern NSString *PublicCallKPointsManagerFreshPointsKey;

// 获得每一份积分的相关信息的列表 [适用于手动积分管理]
extern NSString *PublicCallKPointsManagerPointInfosKey;

// 获得获得积分的用户，对应[PublicCallConfig setUserID:]
extern NSString *PublicCallKPointsManagerPointUserIDKey;

// 获得这一份积分的数量
extern NSString *PublicCallKPointsManagerPointAmountKey;

// 获得积分来源，比如下载安装了 WY新闻 则这份积分来自 WY新闻
extern NSString *PublicCallKPointsManagerPointProductNameKey;

@interface PublicCallPointsManager : NSObject

/////////////// 自动积分管理 ///////////////

// 开启自动积分管理
// YouMiSDK从服务器接收到积分后会把积分存起来，开发者需要使用[PublicCallPointsManager spendPoints:]来消耗积分，还有自动积分管理相关参数
+ (void)PublicCallEnable;

// [自动积分管理]使用积分, 积分不足时返回NO 
+ (BOOL)PublicCallDescreesePoints:(NSUInteger)PublicCallPoints;

// [自动积分管理]奖励积分, 不会发送 Notification, 如果整型越界则返回NO 
+ (BOOL)PublicCallAddPoints:(NSUInteger)PublicCallPoints;

// [自动积分管理]剩余积分
///调用了这个函数后记得free()一下返回值的指针
+ (int *)PublicCallPointsRemained;


/////////////// 手动积分管理 ///////////////

// 开启手动积分管理。
+ (void)PublicCallEnableManually;

//[手动查询积分] 查询积分。使用手动查询积分依然需要监听PublicCallKPointsManagerRecivedPointsNotification，在这个nitification中拿积分
+ (void)PublicCallCheckPoints;

//如果要手动查询积分，传YES。
//自动查询积分，传NO。
//不设置，默认是自动查询积分
+ (void)PublicCallSetManualCheck:(BOOL)PublicCallManualCheck;
@end
