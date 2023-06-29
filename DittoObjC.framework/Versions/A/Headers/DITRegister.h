//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a CRDT register that can be upserted as part of a document or
 assigned to a property during an update of a document.
 */
@interface DITRegister : NSObject

/**
 The value in the register.
 */
@property (nonatomic, readonly) id value;

- (instancetype)init NS_UNAVAILABLE;

/**
 Initializes a new register with the provided value that can be used as part of
 a document's content.
 */
- (instancetype)initWithValue:(id)value NS_DESIGNATED_INITIALIZER;

/**
 Returns `YES` if passed in register has the same value, otherwise returns
 `NO`.
 */
- (BOOL)isEqualToRegister:(DITRegister *)ditRegister;

/**
 Returns the register's value as an `NSString` if possible, otherwise the return value will be
 `nil`.
 */
@property (nonatomic, readonly, nullable) NSString *string;

/**
 Returns the register's value as an `NSString`. If the key was invalid the return value will be an
 empty string.
 */
@property (nonatomic, readonly) NSString *stringValue;

/**
 Returns the register's value as a `BOOL`. If the key was invalid the return value will be
 `false`.
 */
@property (nonatomic, readonly) BOOL booleanValue;

/**
 Returns the register's value as an `NSInteger` if possible, otherwise the return value will be
 0.
 */
@property (nonatomic, readonly) NSInteger integerValue;

/**
 Returns the register's value as an `NSNumber` if possible, otherwise the return value will be
 `nil`.
 */
@property (nonatomic, readonly, nullable) NSNumber *number;

/**
 Returns the register's value as an `NSNumber`. If the key was invalid the return value will be
 an `NSNumber` with a value of 0.
 */
@property (nonatomic, readonly) NSNumber *numberValue;

/**
 Returns the register's value as an `NSArray` if possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSArray *array;

/**
 Returns the register's value as an `NSArray`. If the key was invalid the return value will be an
 empty array.
 */
@property (nonatomic, readonly) NSArray *arrayValue;

/**
 Returns the register's value as an `NSDictionary` if possible, otherwise the return value will be
 `nil`.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *dictionary;

/**
 Returns the register's value as an `NSDictionary`. If the key was invalid the return value will be
 an empty dictionary.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> *dictionaryValue;

@end

NS_ASSUME_NONNULL_END
