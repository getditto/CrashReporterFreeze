//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDiskUsage.h>

@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITDiskUsage ()

@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;

- (instancetype)initWithDitto:(DITDitto *)ditto;
- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

@end

NS_ASSUME_NONNULL_END
