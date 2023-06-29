//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITRegister.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a mutable CRDT register that can be updated while updating a
 document.

 This class can't be instantiated directly. It's returned automatically for
 any register property within an update block.

 See also the `register` property of `DITMutableDocumentPath`.
 */
@interface DITMutableRegister : DITRegister

- (instancetype)init NS_UNAVAILABLE;

/**
 Set the register's value to a new value.

 @param value the new value for the register.
 */
- (void)setValue:(id)value;

@end

NS_ASSUME_NONNULL_END
