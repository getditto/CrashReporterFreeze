//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides an interface to specify a path to a key in a document ID that you can then call a function
 on to get the value at the specified key as a specific type. You obtain a `DITDocumentIDPath` by
 subscripting a `DITDocumentID` and you can then further subscript a `DITDocumentIDPath` to further
 specify the key of the document ID that you want to get the value of. This is only really useful if
 you're working with a document ID whose underlying value is a dictionary or an array.
 */
@interface DITDocumentIDPath : NSObject

/**
 Used to specify a path to a key in the document ID that you can subscript further to access a
 nested key in the document ID.

 @param key The next part of the path needed to get to the key in the document ID you wish to get
 the value of.

 @return The same `DITDocumentIDPath` object with the provided key incorporated into the document ID
 path.
 */
- (DITDocumentIDPath *)objectForKeyedSubscript:(NSString *)key;

/**
 Used to specify an index in the array at the preceding key-path specified through the
 subscripting defined previously. You can subscript the return value further to access a further
 nested key in the document ID.

 @param index The index of the array that you wish to access in the key previously specified with
 the preceding subscripting.

 @return The same `DITDocumentIDPath` object with the provided index incorporated into the document
 ID path.
 */
- (DITDocumentIDPath *)objectAtIndexedSubscript:(NSUInteger)index;

/**
 Returns the value at the previously specified key in the document ID as an `NSObject` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) id value;

/**
 Returns the value at the previously specified key in the document ID as an `NSString` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSString *string;

/**
 Returns the value at the previously specified key in the document ID as an `NSString`. If the key
 was invalid the return value will be an empty string.
 */
@property (nonatomic, readonly) NSString *stringValue;

/**
 Returns the value at the previously specified key in the document ID as a `BOOL`. If the key was
 invalid the return value will be `false`.
 */
@property (nonatomic, readonly) BOOL booleanValue;

/**
 Returns the value at the previously specified key in the document ID as an `NSInteger` if possible,
 otherwise the return value will be 0.
 */
@property (nonatomic, readonly) NSInteger integerValue;

/**
 Returns the value at the previously specified key in the document ID as an `NSNumber` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSNumber *number;

/**
 Returns the value at the previously specified key in the document ID as an `NSNumber`. If the key
 was invalid the return value will be an `NSNumber` with a value of 0.
 */
@property (nonatomic, readonly) NSNumber *numberValue;

/**
 Returns the value at the previously specified key in the document ID as an `NSArray` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSArray *array;

/**
 Returns the value at the previously specified key in the document ID as an `NSArray`. If the key
 was invalid the return value will be an empty array.
 */
@property (nonatomic, readonly) NSArray *arrayValue;

/**
 Returns the value at the previously specified key in the document ID as an `NSDictionary` if
 possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *dictionary;

/**
 Returns the value at the previously specified key in the document ID as an `NSDictionary`. If the
 key was invalid the return value will be an empty dictionary.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> *dictionaryValue;

@end

NS_ASSUME_NONNULL_END
