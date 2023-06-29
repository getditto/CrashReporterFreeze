//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class _DITSyncParameters;
@class DITTransportConfig;

@interface _DITSyncState : NSObject <NSCopying>

@property (nonatomic, readonly, copy) _DITSyncParameters *underlyingSyncParameters;
@property (nonatomic, readonly, copy) DITTransportConfig *effectiveTransportConfig;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithUnderlyingSyncParameters:(_DITSyncParameters *)underlyingSyncParameters
                        effectiveTransportConfig:(DITTransportConfig *)transportConfig
    NS_DESIGNATED_INITIALIZER;

@end

@interface _DITSyncState (DittoTypeCorrections)

- (_DITSyncState *)copy;

@end

NS_ASSUME_NONNULL_END
