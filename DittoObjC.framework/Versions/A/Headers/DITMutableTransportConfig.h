//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITMutableConnect.h>
#import <DittoObjC/DITMutableGlobalConfig.h>
#import <DittoObjC/DITMutableListen.h>
#import <DittoObjC/DITMutablePeerToPeer.h>
#import <DittoObjC/DITTransportConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A configuration object specifying which network transports Ditto should use to sync data.

 A DITDitto object comes with a default transport configuration where all available peer-to-peer
 transports are enabled. You can customize this by initializing a DITMutableTransportConfig,
 adjusting its properties, and supplying it to setTransportConfig: on DITDitto.

 When you initialize a DITMutableTransportConfig yourself it starts with all transports disabled.
 You must enable each one directly.

 Peer-to-peer transports will automatically discover peers in the vicinity and create connections
 without any configuration. These are configured inside the peerToPeer property. To turn each
 one on, set its enabled property to YES.

 To connect to a peer at a known location, such as a Ditto Big Peer, add its address inside
 the connect configuration. These are either "host:port" strings for raw TCP sync, or a "wss://…"
 URL for websockets.

 The listen configurations are for specific less common data sync scenarios. Please read the
 documentation on the Ditto website for examples. Incorrect use of listen can result in
 insecure configurations.
 */
@interface DITMutableTransportConfig : DITTransportConfig

@property (nonatomic, readonly, copy) DITMutablePeerToPeer *peerToPeer;
@property (nonatomic, readonly, copy) DITMutableConnect *connect;
@property (nonatomic, readonly, copy) DITMutableListen *listen;
@property (nonatomic, readonly, copy) DITMutableGlobalConfig *global;

- (void)setPeerToPeer:(DITPeerToPeer *)peerToPeer;
- (void)setConnect:(DITConnect *)connect;
- (void)setListen:(DITListen *)listen;
- (void)setGlobal:(DITGlobalConfig *)global;

/**
 Enable all supported peer-to-peer modes for this platform
 */
- (void)enableAllPeerToPeer;

@end

NS_ASSUME_NONNULL_END
