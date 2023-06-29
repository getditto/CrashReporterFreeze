//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITCollection.h>
#import <DittoObjC/dittoffi.h>

@class DITDocumentID;
@class _DITDittoHandleWrapper;

struct Ditto_WriteTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface DITCollection ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
                                      name:(NSString *)name;

- (nullable DITDocumentID *)upsert:(NSDictionary<NSString *, id> *)content
                            withID:(nullable DITDocumentID *)id
                     writeStrategy:(DITWriteStrategy)writeStrategy
                          writeTxn:(nullable CWriteTransaction_t *)writeTxn
                             error:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(upsert(_:withID:writeStrategy:writeTxn:));

- (nullable DITDocumentID *)upsertCBORData:(NSData *)data
                                    withID:(nullable DITDocumentID *)id
                             writeStrategy:(DITWriteStrategy)writeStrategy
                                   logHint:(NSString *)logHint
                                  writeTxn:(nullable CWriteTransaction_t *)writeTxn
    NS_SWIFT_NAME(upsertCBORData(_:withID:writeStrategy:logHint:writeTxn:));

- (nullable DITDocumentID *)upsertCBORData:(NSData *)data
                                    withID:(nullable DITDocumentID *)id
                             writeStrategy:(DITWriteStrategy)writeStrategy
                                   logHint:(NSString *)logHint
                                     error:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(upsertCBORData(_:withID:writeStrategy:logHint:));

- (DITPendingCursorOperation *)find:(NSString *)query withArgsData:(nullable NSData *)queryArgsData;

@end

NS_ASSUME_NONNULL_END
