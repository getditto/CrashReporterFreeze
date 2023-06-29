//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDiskUsageObserverHandle.h>

@class DITDiskUsageItem;
@class _DITDittoHandleWrapper;

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITDiskUsageObserverHandle ()

@property (nonatomic, copy) void (^eventHandler)(DITDiskUsageItem *DiskUsageItem);

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
                              eventHandler:(void (^)(DITDiskUsageItem *DiskUsageItem))block;

@end

NS_ASSUME_NONNULL_END
