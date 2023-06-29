//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/_DITSync.h>
#import <DittoTransportsObjC/DittoTransportsApple.h>

NS_ASSUME_NONNULL_BEGIN

@class DITTransportConfig;
@class DITGlobalConfig;
@class DITIdentityProvider;

@class _DITSyncState;
@class _DITDittoHandleWrapper;

_DITSyncState *_DITSyncStateFromParameters(_DITSyncParameters *syncParameters);
NSString *_DITSyncDefaultDittoCloudURL(NSString *appID);

@interface _DITSync ()

@property (nonatomic, readonly, copy) _DITSyncState *state;
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, nullable) DITIdentityProvider *identityProvider;

@property (nonatomic, assign, nullable) CDittoTransportsBLE_t *cDittoTransportsBLE;
@property (nonatomic, assign, nullable) CDittoTransportsAWDL_t *cDittoTransportsAWDL;
@property (nonatomic, assign, nullable) CDittoTransportsLAN_t *cDittoTransportsLAN;

@property (nonatomic, strong) NSMutableDictionary *staticTCPClientsByAddress;
@property (nonatomic, strong) NSMutableDictionary *websocketClientsByURL;

- (void)updatePeerToPeerBluetoothLEWithStateOld:(_DITSyncState *)stateOld
                                       stateNew:(_DITSyncState *)stateNew;
- (void)updatePeerToPeerAWDLWithStateOld:(_DITSyncState *)stateOld
                                stateNew:(_DITSyncState *)stateNew;
- (void)updatePeerToPeerLANWithStateOld:(_DITSyncState *)stateOld
                               stateNew:(_DITSyncState *)stateNew;
- (void)updateListenTCPWithStateOld:(_DITSyncState *)stateOld stateNew:(_DITSyncState *)stateNew;
- (void)updateListenHTTPWithStateOld:(_DITSyncState *)stateOld stateNew:(_DITSyncState *)stateNew;
- (void)updateConnectTCPServersWithStateOld:(_DITSyncState *)stateOld
                                   stateNew:(_DITSyncState *)stateNew;
- (void)updateConnectWebsocketURLsWithStateOld:(_DITSyncState *)stateOld
                                      stateNew:(_DITSyncState *)stateNew;
- (void)updateGlobalWithStateOld:(_DITSyncState *)stateOld stateNew:(_DITSyncState *)stateNew;

@end

NS_ASSUME_NONNULL_END
