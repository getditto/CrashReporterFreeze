//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITMutableDocument.h>
#import <DittoObjC/dittoffi.h>

@class DITUpdateResult;

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableDocument ()
// This will be freed as part of the update process that uses these `DITMutableDocument`s
@property (nonatomic, readonly, unsafe_unretained) CDocument_t *documentHandle;
@property (nonatomic, readonly) NSMutableArray<DITUpdateResult *> *results;

- (instancetype)initWithDocumentHandle:(CDocument_t *)documentHandle;
@end

NS_ASSUME_NONNULL_END
