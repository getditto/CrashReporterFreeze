//
//  Copyright © 2021 Ditto. All rights reserved.
//

@class DITDocument;
@class DITLiveQueryMove;

NS_ASSUME_NONNULL_BEGIN

@interface DITCollectionsEvent ()

- (instancetype)initWithCollections:(NSArray<DITCollection *> *)collections
                     oldCollections:(NSArray<DITCollection *> *)oldCollections
                         insertions:(NSArray<NSNumber *> *)insertions
                          deletions:(NSArray<NSNumber *> *)deletions
                            updates:(NSArray<NSNumber *> *)updates
                              moves:(NSArray<DITLiveQueryMove *> *)moves;

- (instancetype)initInitialWithCollections:(NSArray<DITCollection *> *)collections;

@end

NS_ASSUME_NONNULL_END
