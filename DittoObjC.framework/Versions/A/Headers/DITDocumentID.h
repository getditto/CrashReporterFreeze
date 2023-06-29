//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITDocumentIDPath;

NS_ASSUME_NONNULL_BEGIN

/**
 An identifier for a `DITDocument`.

 Each `DITDocumentID` represents a unique identifier for a document.
 */
@interface DITDocumentID : NSObject <NSCopying>

/**
 Initializes a new `DITDocumentID`.

 A document ID can be created from any of the following:

 * string
 * integer
 * boolean
 * null
 * byte array
 * array (containing any of the items in this list)
 * map (where the keys must be strings and the values can be made up of any of
   the items in this list)

 Note that you cannot use floats or other custom types to create a document ID.

 Document IDs are also limited in size, based on their serialized
 representation, to 256 bytes. You will receive an error if you try to create a
 document ID that exceeds the size limit.

 @param idValue The value that represents the document identifier.
 */
- (instancetype)initWithValue:(id)idValue;

/**
 The underlying value of the document identifier as a native type.
 */
@property (nonatomic, readonly) id value;

/**
 Returns a stringified representation of a document identifier.

 The returned string can be used directly in queries that you use with other
 Ditto functions. For example you could create a query that was like this:

 ```
 [myCollection find:[NSString stringWithFormat:@"_id == %@", [docID toString]];
 ```

 @return An `NSString` representation of the document identifier.
 */
- (NSString *)toString;

/**
 Compares two documents and determines whether or not they are equal.

 @param documentID The other document identifier that you want to test equality
 with.

 @return A `BOOL` representing whether or not the document identifiers are
 equal.
 */
- (BOOL)isEqualToDITDocumentID:(DITDocumentID *)documentID;

/**
 Compares two documents and determines their relative ordering.

 @param documentID The other document identifier that you want to comapre
 against.

 @return An `NSComparisonResult` representing the ordering of the document
 identifiers when compared.
 */
- (NSComparisonResult)compare:(DITDocumentID *)documentID;

/**
 Used to specify a path to a key in the document ID that you can subscript further to access a
 nested key in the document ID, if necessary.

 @param key The initial part of the path needed to get to the key in the document ID you wish to get
 the value of.

 @return A `DITDocumentIDPath` object with the provided key incorporated into the document ID path.
 */
- (DITDocumentIDPath *)objectForKeyedSubscript:(NSString *)key;

/**
 Used to specify an index in the array that represents the document ID. You can subscript the return
 value further to access a further nested key in the document ID, if necessary.

 @param index The index of the array representing the document ID that you wish to access.

 @return A `DITDocumentIDPath` object with the provided index incorporated into the document ID
 path.
 */
- (DITDocumentIDPath *)objectAtIndexedSubscript:(NSUInteger)index;

/**
 Returns the document ID as an `NSString` if possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSString *string;

/**
 Returns the document ID as an `NSString`. If the document ID is not represented by a string the
 return value will be an empty string.
 */
@property (nonatomic, readonly) NSString *stringValue;

/**
 Returns the document ID as a `BOOL`. If the document ID is not represented by a boolean the
 return value will be `false`.
 */
@property (nonatomic, readonly) BOOL booleanValue;

/**
 Returns the document ID as an `NSInteger` if possible, otherwise the return value will be 0.
 */
@property (nonatomic, readonly) NSInteger integerValue;

/**
 Returns the document ID as an `NSNumber` if possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSNumber *number;

/**
 Returns the document ID as an `NSNumber`. If the document ID is not represented by a number
 the return value will be an `NSNumber` with a value of 0.
 */
@property (nonatomic, readonly) NSNumber *numberValue;

/**
 Returns the document ID as an `NSArray` if possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSArray *array;

/**
 Returns the document ID as an `NSArray`. If the document ID is not represented by an array the
 return value will be an empty array.
 */
@property (nonatomic, readonly) NSArray *arrayValue;

/**
 Returns the document ID as an `NSDictionary` if possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *dictionary;

/**
 Returns the document ID as an `NSDictionary`. If the document ID is not represented by a
 dictionary the return value will be an empty dictionary.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> *dictionaryValue;

@end

NS_ASSUME_NONNULL_END
