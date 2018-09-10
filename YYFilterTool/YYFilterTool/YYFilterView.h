//
//  YYFilterView.h
//  MyCoinRisk
//
//  Created by yuyou on 2018/7/28.
//  Copyright © 2018年 hengtiansoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FilterSelectIndexModel.h"

typedef NS_ENUM(NSUInteger, YYFilterViewType) {
    YYFilterViewTypeSingleLevel = 1,
    YYFilterViewTypeDoubleLevel = 2,
};

@interface YYFilterView : UIView

/** 筛选层级，一层还是两层，目前支持两层，以后有需求可以拓展到三层 */
@property (nonatomic, assign) YYFilterViewType levelType;

/** 表示上方是否展示已经选择的条件 */
@property (nonatomic, assign) BOOL topConditionEnable;

/** 是否支持多选 */
@property (nonatomic, assign) BOOL multiSelectionEnable;

/** 第一层元素数组 */
@property (nonatomic, strong) NSArray *firstLevelElements;

/** 第二层元素数组 */
@property (nonatomic, strong) NSArray *secondLevelElements;

/* 当前选择的所有条件 */
@property (nonatomic, strong) NSMutableArray<FilterSelectIndexModel *> *currentConditions;

/* 表示钩框亮色按钮名字 */
@property (nonatomic, copy) NSString *selectedBtnHighlightedName;

/* 表示钩框暗色按钮名字 */
@property (nonatomic, copy) NSString *selectedBtnNormalName;

/** 点击筛选后的回调 */
@property (nonatomic, copy) void(^filterComplete)(NSArray *filters);


/** 开始动画，弹出筛选视图，startY表示筛选视图相对于window的Y值是多少，即从Y轴的哪个位置开始 */
- (void)popFilterViewWithStartY:(CGFloat)startY completion:(void(^)(void))completion;



/** 关闭筛选视图 */
- (void)closeFilterViewCompletion:(void(^)(void))completion;

- (BOOL)getIfPoping;

@end