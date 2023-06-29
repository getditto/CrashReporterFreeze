//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <DittoTransportsObjC/dittoffi.h>

#import <DittoTransportsObjC/DITAWDLServerAdvertiserDelegate.h>

#import <Foundation/Foundation.h>

@class DITAWDLServerNetServicePeer;
@class DITTransportHandleWrapper;

@protocol DITAWDLServerAdvertiser;
@protocol DITAWDLServerPeer;

NS_ASSUME_NONNULL_BEGIN

/**
 Provides AWDL discovery and communication to Rust.
 */
@interface DITAWDLServerPlatform : NSObject <DITAWDLServerAdvertiserDelegate>

@property(nonatomic, assign, readonly) void *dittoHandle;
@property(nonatomic, strong, readonly) NSThread *transportsThread;
@property(nonatomic, strong, readonly) NSRunLoop *transportsRunLoop;
@property(nonatomic, strong, nullable) DITTransportHandleWrapper *handleWrapper;
@property(nonatomic, strong, readonly) dispatch_queue_t queue;
@property(nonatomic, strong) NSMutableDictionary<NSNumber *, NSObject<DITAWDLServerPeer> *> *peers;
@property(nonatomic, copy) NSString *prefix;
@property(nonatomic, copy) NSString *announce;
@property(nonatomic, strong, nullable) NSObject<DITAWDLServerAdvertiser> *advertiser;
@property(nonatomic, assign) OnlineState_t advertising;
@property(nonatomic, copy, readonly, nullable) NSString* serviceName;

+ (AwdlServerCallbacks_t)callbacks;

- (instancetype)init NS_UNAVAILABLE;

/// Must be called on a thread with a *running* run-loop. For regular apps on apple platforms, this is the
/// main thread. For environments that already have some kind of event loop, such as Node, you'll have to
/// create a dedicated thread, run its run loop, and make sure to call the initializer from that thread.
- (instancetype)initWithDittoHandle:(void *)dittoHandle NS_DESIGNATED_INITIALIZER;

- (void)shutdown;

- (void)startAdvertising:(NSString *)announce hashedAppName:(NSString *)hashedAppName;
- (void)stopAdvertising;

@end

NS_ASSUME_NONNULL_END
