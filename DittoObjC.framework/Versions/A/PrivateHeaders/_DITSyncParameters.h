//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITIdentity;
@class DITTransportConfig;

@interface _DITSyncParameters : NSObject <NSCopying>

@property (nonatomic, readonly, getter=isSyncActive) BOOL syncActive;
@property (nonatomic, readonly, getter=isX509Valid) BOOL x509Valid;
@property (nonatomic, readonly, getter=isWebValid) BOOL webValid;

@property (nonatomic, readonly) DITIdentity *identity;
@property (nonatomic, readonly, copy) DITTransportConfig *transportConfig;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSyncActive:(BOOL)isSyncActive
                         x509Valid:(BOOL)isX509Valid
                          webValid:(BOOL)isWebValid
                          identity:(DITIdentity *)identity
                   transportConfig:(DITTransportConfig *)transportConfig NS_DESIGNATED_INITIALIZER;

@end

@interface _DITSyncParameters (DittoTypeCorrections)

- (_DITSyncParameters *)copy;

@end

NS_ASSUME_NONNULL_END
