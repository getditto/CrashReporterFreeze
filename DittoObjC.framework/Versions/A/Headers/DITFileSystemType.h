//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type of file represented by a `DiskUsageItem`.
 */
typedef NS_ENUM(NSInteger, DITFileSystemType) {
    DITFileSystemTypeDirectory = 0,
    DITFileSystemTypeFile,
    DITFileSystemTypeSymLink
};

/** Returns a dictionary of all types by their names. */
NSDictionary *DITFileSystemTypeAllCasesByName(void);

/** Returns a dictionary of all names by their types. */
NSDictionary *DITFileSystemTypeAllNamesByCase(void);

/**
 Returns an array containing all possible cases of the `DITFileSystemType`
 enum.
 */
NSArray<NSNumber *> *DITFileSystemTypeAllCases(void);

/**
 Returns an array containing the names for all possible cases of the
 `DITFileSystemType` enum.
 */
NSArray<NSString *> *DITFileSystemTypeAllCaseNames(void);

/** Returns the name for a particular case of the `DITFileSystemType` enum. */
NSString *DITFileSystemTypeName(DITFileSystemType connectionType);

/**
 Returns the case for the name of a particular case of the
 `DITFileSystemType` enum.
 */
DITFileSystemType DITFileSystemTypeForName(NSString *name);

NS_ASSUME_NONNULL_END
