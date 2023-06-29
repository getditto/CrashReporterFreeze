//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITGlobalConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITGlobalConfig () {
    @protected
    uint32_t _syncGroup;
}

- (instancetype)initWithSyncGroup:(uint32_t)syncGroup copy:(BOOL)copy;

- (instancetype)initWithSyncGroup:(uint32_t)syncGroup
                      routingHint:(uint32_t)routingHint
                             copy:(BOOL)copy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
