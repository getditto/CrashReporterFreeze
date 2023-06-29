//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITWriteTransactionPendingIDSpecificOperation.h>

@class _DITDocumentHandleWrapper;
@class DITDocumentID;
@class DITWriteTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface DITWriteTransactionPendingIDSpecificOperation ()

@property (nonatomic, readonly) DITDocumentID *docID;
@property (nonatomic, readonly) NSString *collectionName;
// This holds a `DittoHandleWrapper` reference, so we don't have to hold another reference explicity
// as we are already implicitly holding one here.
@property (nonatomic, readonly) DITWriteTransaction *baseTransaction;

- (instancetype)initWithDocID:(DITDocumentID *)docID
               collectionName:(NSString *)collectionName
              baseTransaction:(DITWriteTransaction *)baseTransaction;

// MARK: Other internal

- (void)updateUsingData:(NSData *)data;
- (nullable _DITDocumentHandleWrapper *)execReturningDocumentHandle;
@end

NS_ASSUME_NONNULL_END
