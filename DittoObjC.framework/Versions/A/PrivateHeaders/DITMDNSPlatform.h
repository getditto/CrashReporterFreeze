//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <DittoTransportsObjC/dittoffi.h>
#import <Foundation/Foundation.h>

@class DITTransportHandleWrapper;
@class DITServiceCache;

NS_ASSUME_NONNULL_BEGIN

@interface DITMDNSPlatform : NSObject <NSNetServiceBrowserDelegate, NSNetServiceDelegate>

@property(nonatomic, assign, readonly) void *dittoHandle;
@property(nonatomic, strong, readonly) NSThread *transportsThread;
@property(nonatomic, strong, readonly) NSRunLoop *transportsRunLoop;

@property(nonatomic, strong, nullable) DITTransportHandleWrapper *clientHandleWrapper;
@property(nonatomic, strong, nullable) DITTransportHandleWrapper *serverHandleWrapper;

@property(nonatomic, strong, nullable) NSNetService *service;
@property(nonatomic, strong, nullable) NSNetServiceBrowser *browser;
@property(nonatomic, strong) DITServiceCache *services;
@property(nonatomic, assign) OnlineState_t searching;
@property(nonatomic, assign) OnlineState_t advertising;
@property(nonatomic, copy) NSString *announce;
// These prefixes should be the same but search/advertise can operate independently - see crash #1827
@property(nonatomic, copy) NSString *searchingPrefix;
@property(nonatomic, copy) NSString *advertisingPrefix;
@property(nonatomic, assign) int32_t port;

// For DITClientPlatformProtocol
@property (nonatomic, assign) bool isWifiEnabled;
@property (nonatomic, strong, nullable) NSTimer *wifiCheckTimer;

+ (MdnsServerCallbacks_t)serverCallbacks;
+ (MdnsClientCallbacks_t)clientCallbacks;
+ (NSString *)serviceNameForPrefix:(NSString *)prefix announce:(NSString *)announce;

- (instancetype)init NS_UNAVAILABLE;

/// Must be called on a thread with a *running* run-loop. For regular apps on apple platforms, this is the
/// main thread. For environments that already have some kind of event loop, such as Node, you'll have to
/// create a dedicated thread, run its run loop, and make sure to call the initializer from that thread.
- (instancetype)initWithDittoHandle:(void *)dittoHandle NS_DESIGNATED_INITIALIZER;

- (void)shutdown;

@end

NS_ASSUME_NONNULL_END
