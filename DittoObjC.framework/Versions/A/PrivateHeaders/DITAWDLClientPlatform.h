//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <DittoTransportsObjC/dittoffi.h>
#import <Foundation/Foundation.h>

/*
 This is the platform implementation for peer-to-peer Wifi, or AWDL.
 We use the platform APIs: NetService and NetServiceBrowser to
 initiate the discovery and connection. This is the same high-level
 API from the platform that is used with mDNS as well. We have a
 duplicate implementation because the underlying socket from AWDL
 uses a private socket option called SO_RECV_ANYIF and is defined
 in sys/socket.h on Darwin as 0x1104 (but unavailable in iOS).
 Instead, the only way to get access to the socket is from high-
 level APIs, specifically getInputStream(_:outputStream:) from
 NetService or NWBrowser and NWConnection in the Network Framework,
 (available >=iOS 12).

 We confirmed with Apple DTS that it is ok to run two NetService
 instances:

 "Nothing sticks out to me here as being an issue besides the
 technical overhead of managing the two sets of services and
 browsers."
 */

@class DITTransportHandleWrapper;
@class DITAWDLClientPeer;

NS_ASSUME_NONNULL_BEGIN

@interface DITAWDLClientPlatform : NSObject <NSNetServiceBrowserDelegate, NSNetServiceDelegate>

@property(nonatomic, assign, readonly) void *dittoHandle;
@property(nonatomic, strong, readonly) NSThread *transportsThread;
@property(nonatomic, strong, readonly) NSRunLoop *transportsRunLoop;
@property(nonatomic, strong, nullable) DITTransportHandleWrapper *handleWrapper;
@property(nonatomic, strong, readonly) dispatch_queue_t peersQueue;
@property(nonatomic, strong, nullable) NSNetServiceBrowser *browser;
@property(nonatomic, strong) NSMutableDictionary<NSString *, DITAWDLClientPeer *> *peers;
@property(nonatomic, copy) NSString *prefix;
@property(nonatomic, copy) NSString *announce;
@property(nonatomic, assign) OnlineState_t searching;

// For DITClientPlatformProtocol
@property (nonatomic, assign) bool isWifiEnabled;
@property (nonatomic, strong, nullable) NSTimer *wifiCheckTimer;

+ (AwdlClientCallbacks_t)callbacks;

- (instancetype)init NS_UNAVAILABLE;

/// Must be called on a thread with a *running* run-loop. For regular apps on apple platforms, this is the
/// main thread. For environments that already have some kind of event loop, such as Node, you'll have to
/// create a dedicated thread, run its run loop, and make sure to call the initializer from that thread.
- (instancetype)initWithDittoHandle:(void *)dittoHandle NS_DESIGNATED_INITIALIZER;

- (void)shutdown;

- (void)startSearching:(NSString *)announce hashedAppName:(NSString *)hashedAppName;
- (void)stopSearching;

@end

NS_ASSUME_NONNULL_END
