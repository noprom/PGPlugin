//
//  YouMiFeaturedAppModel.h
//  YouMiSDK
//
//  Created by Layne on 12-01-05.
//  Copyright (c) 2012年 YouMi Mobile Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "publicHeader.h"

@interface PublicCallListAppModel : NSObject<NSCopying>

// 该应用的id（可以作为跟其他广告的区分）。
@property(nonatomic, retain, readonly)    NSString    *PublicCallstoreID;
// 应用名称
@property(nonatomic, retain, readonly)    NSString    *PublicCallname;
// 应用的小图标
@property(nonatomic, retain, readonly)    NSString    *PublicCallsmallIconURL;
// 简短广告词
@property(nonatomic, retain, readonly)    NSString    *PublicCalladText;
//较为详细步骤提示
@property(nonatomic, retain, readonly)     NSString   *PublicCalltask_brief;
//简短步骤提示
@property(nonatomic, retain, readonly)     NSString   *PublicCalltask_steps;
// 过期时间
@property(nonatomic, retain, readonly)    NSDate      *PublicCallexpiredDate;
// 积分值[该值对有积分应用有效，无积分应用默认为0]。。已经完成的任务，points也会为0
@property(nonatomic, assign, readonly)    NSInteger   PublicCallpoints;
//用于应用内打开（不建议使用，应用内打开appStore经常出现空白页）appStoreID
@property(nonatomic, assign, readonly)     NSInteger    PublicCallappStoreID;
//应用在appStore的下载链接
@property(nonatomic, retain, readonly)     NSString    *PublicCalllinkURL;
//应用包名bundleID
@property(nonatomic, retain, readonly)     NSString    *PublicCallidentifier;
//判断这个广告是否需要提审
@property(nonatomic, assign, readonly)     BOOL        PublicCallIsNeedReview;


//深度任务描述（如果此广告不是深度任务广告，则PublicCallMoreTask为nil，注意判断）
/*
 {
 at: 16,  //开发者不用理这个参数
 adtext: "第二天 再次打开试用3分钟",   //追加任务广告语
 points: 2800,                     //追加任务积分
 etm: "60", //开发者不用理这个参数
 status: 0                         //0表示任务还没开始，1表示任务正在进行，2表示任务已经过期
 }
 */
@property(nonatomic, retain, readonly)     NSArray      *PublicCallMoreTasks;

//应用大小
@property(nonatomic, retain, readonly)     NSString     *PublicCallsize;
@end
