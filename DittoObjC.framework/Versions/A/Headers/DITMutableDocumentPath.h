//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITAttachmentToken;
@class DITMutableCounter;
@class DITMutableRegister;
@class DITRGA;

NS_ASSUME_NONNULL_BEGIN

/**
 Provides an interface to specify a path to a key in a document that you can then call various
 update functions on. You obtain a `DITMutableDocumentPath` by subscripting a
 `DITMutableDocument` and you can then further subscript a `DITMutbaleDocumentPath` to further
 specify the key of the document that you want to update.
 */
@interface DITMutableDocumentPath : NSObject

/**
 Used to specify a path to a key in the document that you can subscript further to access a
 nested key in the document and eventually perform an update operation on.

 @param key The next part of the path needed to get to the key in the document you wish to
 update.

 @return A `DITMutableDocumentPath` with the provided key incorporated into the path.
 */
- (DITMutableDocumentPath *)objectForKeyedSubscript:(NSString *)key;

/**
 Used to specify an index in the array at the preceding key-path specified through the
 subscripting defined previously. You can subscript the return value further to access a further
 nested key in the document and eventually perform an update operation.

 @param index The index of the array that you wish to access in the key previously specified with
 the preceding subscripting.

 @return A `DITMutableDocumentPath` with the provided index incorporated into the path.
 */
- (DITMutableDocumentPath *)objectAtIndexedSubscript:(NSUInteger)index;

/**
 Returns the value at the previously specified key in the document as an `NSObject` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) id value;

/**
 Returns the value at the previously specified key in the document as an `NSString` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSString *string;

/**
 Returns the value at the previously specified key in the document as an `NSString`. If the key
 was invalid the return value will be an empty string.
 */
@property (nonatomic, readonly) NSString *stringValue;

/**
 Returns the value at the previously specified key in the document as a `BOOL`. If the key was
 invalid the return value will be `false`.
 */
@property (nonatomic, readonly) BOOL booleanValue;

/**
 Returns the value at the previously specified key in the document as an `NSInteger` if possible,
 otherwise the return value will be 0.
 */
@property (nonatomic, readonly) NSInteger integerValue;

/**
 Returns the value at the previously specified key in the document as an `NSNumber` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSNumber *number;

/**
 Returns the value at the previously specified key in the document as an `NSNumber`. If the key
 was invalid the return value will be an `NSNumber` with a value of 0.
 */
@property (nonatomic, readonly) NSNumber *numberValue;

/**
 Returns the value at the previously specified key in the document as an `NSArray` if possible,
 otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSArray *array;

/**
 Returns the value at the previously specified key in the document as an `NSArray`. If the key
 was invalid the return value will be an empty array.
 */
@property (nonatomic, readonly) NSArray *arrayValue;

/**
 Returns the value at the previously specified key in the document as an `NSDictionary` if
 possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *dictionary;

/**
 Returns the value at the previously specified key in the document as an `NSDictionary`. If the
 key was invalid the return value will be an empty dictionary.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> *dictionaryValue;

/**
 Returns the value at the previously specified key in the document as a `DITAttachmentToken` if
 possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) DITAttachmentToken *attachmentToken;

/**
 Returns the value at the previously specified key in the document as a `DITMutableCounter` if
 possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) DITMutableCounter *counter;

/**
 Returns the value at the previously specified key in the document as a `DITMutableRegister` if
 possible, otherwise the return value will be `nil`.
 */
@property (nonatomic, readonly, nullable) DITMutableRegister *lwwRegister;

/**
 Returns the value at the previously specified key in the document as a `DITRGA` if possible,
 otherwise the return value will be `nil`.

 Note that the returned type, `DITRGA`, is deprecated and does not allow any mutation. RGAs cannot
 be created or mutated with this version of the SDK; they can only be read and this is for backwards
 compatibility reasons.

 @deprecated `DITRGA` usage should be replaced. Use arrays inside `DITRegister`s instead.
 */
@property (nonatomic, readonly, nullable) DITRGA *rga __deprecated_msg(
    "`DITRGA` usage should be replaced. Use arrays inside `DITRegister`s instead.");

/**
 Set a value at the document's key defined by the preceding subscripting.

 @param value The value to set at the subscripting-defined document key.
 @param isDefault Represents whether or not the value should be set as a default value. Set this to
 `true` if you want to set a default value that you expect to be overwritten by other devices in the
 network. The default value is `false`.
 */
- (void)set:(id)value isDefault:(BOOL)isDefault;

/**
 Set a value at the document's key defined by the preceding subscripting.

 @param value The value to set at the subscripting-defined document key.
 */
- (void)set:(id)value;

/**
 Remove a value at the document's key defined by the preceding subscripting. If
 removing an index from an array, any subsequent indexes will be shifted left to
 fill the gap.
 */
- (void)remove;

@end

NS_ASSUME_NONNULL_END
