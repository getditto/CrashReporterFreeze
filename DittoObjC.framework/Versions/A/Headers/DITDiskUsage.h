//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITDitto;
@class DITDiskUsageItem;
@class DITDiskUsageObserverHandle;

NS_ASSUME_NONNULL_BEGIN

/// Entrypoint for accessing information about the amount of disk storage used by Ditto.
/// This class can't be instantiated. You can access an instance through the `ditto.diskUsage` API.
@interface DITDiskUsage : NSObject

- (instancetype)init NS_UNAVAILABLE;

/// Returns a single `DiskUsageItem` representing a tree of directories with file size
/// information. Use the `observe()` method to access the same information with callbacks as
/// the size of files change over time.
/// - Returns: DiskUsageItem
@property (nonatomic, readonly, copy) DITDiskUsageItem *exec;

/// Starts filesystem observation. Disk usage details will be passed to the given closure as
/// files in the Ditto directory change size over time.
/// - Parameter eventHandler: A closure that will be invoked regularly with `DiskUsageItem`
/// instances.
/// - Returns: A `DiskUsageObserverHandle` which should be held in scope to continue observation.
/// Invoke the `stop()` method on the handle to terminate callbacks.
- (DITDiskUsageObserverHandle *)observe:(void (^)(DITDiskUsageItem *DiskUsageItem))eventHandler;

@end

NS_ASSUME_NONNULL_END
