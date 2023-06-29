//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDitto.h>

@class _DITDittoHandleWrapper;
@class _DITValidityListener;
@class _DITPresenceManagerV1;
@class _DITPresenceManagerV2;
@class DITPresence;

@class DITTransportHandleWrapper;
@class DITAWDLClientPlatform;
@class DITAWDLServerPlatform;
@class DITBluetoothPlatform;
@class DITMDNSPlatform;
@class DITBus;

@class DITBluetoothLEConfig;
@class DITLANConfig;
@class DITAWDLConfig;
@class DITTCPListenConfig;
@class DITHTTPListenConfig;
@class DITGlobalConfig;

@class _DITSync;
@class _DITStatus;
@class _DITHistory;

NS_ASSUME_NONNULL_BEGIN

@interface DITDitto ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;

@property (nonatomic, readonly)
    _DITPresenceManagerV1 *presenceV1 __deprecated_msg("Replaced by `presence`.");
@property (nonatomic, readonly)
    _DITPresenceManagerV2 *presenceV2 __deprecated_msg("Replaced by `presence`.");

@property (nonatomic) BOOL transportConditionCallbackRegistered;

@property (nonatomic) _DITStatus *status;
@property (nonatomic) DITBus *bus;

@property (nonatomic, readonly) _DITValidityListener *validityListener;

/// We can start WebSocket client transports
@property (nonatomic) BOOL webIdentityValid;
/// We can start TCP and P2P transports
@property (nonatomic) BOOL x509IdentityValid;

@property (nonatomic, readonly) _DITSync *sync;
@property (nonatomic, readonly) _DITHistory *history;

- (void)initSdkVersion;

- (void)validityUpdatedWithWebValid:(BOOL)webValid x509Valid:(BOOL)x509Valid;

@end

NS_ASSUME_NONNULL_END
