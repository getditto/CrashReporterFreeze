//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITFileSystemType.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A directory or file in the Ditto working directory. Directories can be traversed by accessing
/// the `childItems` property. Files won't have any children.
@interface DITDiskUsageItem : NSObject <NSCopying>

/// Type of file.
@property (assign, readonly) DITFileSystemType type;

/// Path to the file relative to the Ditto working directory.
@property (nonatomic, readonly) NSString *path;

/// Size of the file. In the case of a directory, this is the sum of all file sizes beneath it.
@property (nonatomic, readonly) NSInteger sizeInBytes;

/// An array of child items. Empty for regular files. Only directories may contain children.
@property (nonatomic, readonly, nullable) NSArray<DITDiskUsageItem *> *childItems;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (NSUInteger)hash;

- (BOOL)isEqual:(nullable id)object;
- (BOOL)isEqualToDiskUsageItem:(DITDiskUsageItem *)diskUsageItem;

- (DITDiskUsageItem *)copy;
- (DITDiskUsageItem *)copyWithZone:(nullable NSZone *)zone;

@end

NS_ASSUME_NONNULL_END
