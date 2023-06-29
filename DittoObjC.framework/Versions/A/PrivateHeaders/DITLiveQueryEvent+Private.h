//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITLiveQueryEvent.h>

@class DITDocument;
@class DITLiveQueryMove;

NS_ASSUME_NONNULL_BEGIN

@interface DITLiveQueryEvent ()

- (instancetype)initWithOldDocuments:(NSArray<DITDocument *> *)oldDocs
                          insertions:(NSArray<NSNumber *> *)insertions
                           deletions:(NSArray<NSNumber *> *)deletions
                             updates:(NSArray<NSNumber *> *)updates
                               moves:(NSArray<DITLiveQueryMove *> *)moves;

- (instancetype)initInitial;

@end

NS_ASSUME_NONNULL_END
