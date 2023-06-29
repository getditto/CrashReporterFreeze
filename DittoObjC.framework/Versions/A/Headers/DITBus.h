//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITBusDelegate.h>
#import <DittoObjC/DITBusReliability.h>
#import <DittoObjC/DITBusStreamDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class _DITDittoHandleWrapper;
@class DITAddress;
@class DITBusStream;

/**
 Send and receive messages with remote Ditto peers in the mesh.

 Ditto Bus is separate from the replicated document database. It is used to send one-off messages or
 create continuous channels with other peers in the mesh, without any persistence. Messages are
 treated as opaque binary by Ditto and must be created and interpreted by your app.

 Possible uses include:
 * Remote control systems
 * Tunnelling other protocols
 * Gaming
 * Voice and video

 Ditto Bus communications are always between two distinct peers, 1-to-1, and are offered with
 various delivery guarantees.

 For simple use cases there is a single-message API. These are received on the other peer via
 `DITBusDelegate`.

 In advanced situations with requirements such as multiple overlapping streams, notification of
 stream start and end, and backpressure, individual streams can be opened using the `openStream`
 function. Once opened, these are symmetric/bidirectional message-oriented communication channels.
 The remote peer will receive their stream via `DITBusDelegate`.
 */
@interface DITBus : NSObject

/**
 Delegate for global bus events
 */
@property (nonatomic, nullable, weak) id<DITBusDelegate> delegate;

/**
 The dispatch queue on which Bus and BusStream events will be delivered.

 By default this is a separate serial queue. A custom queue may be provided.
 */
@property (nonatomic) dispatch_queue_t delegateEventQueue;

- (instancetype)init NS_UNAVAILABLE;

/**
 Send a single bus message to another peer, with no guarantees on delivery.

 A completion closure may be provided which will provide feedback about whether this message was
 transmitted (but not necessarily received.)
 */
- (void)sendSingleUnreliableMessage:(NSData *)data
                          toAddress:(DITAddress *)address
                         completion:(void (^__nullable)(NSError *__nullable))completion;

/**
 Send a single bus message to another peer, taking care that the message is delivered in full, if
 connectivity permits it.

 A completion closure may be provided which will provide feedback about whether this message was
 transmitted (but not necessarily received.)
 */
- (void)sendSingleReliableMessage:(NSData *)data
                        toAddress:(DITAddress *)address
                       completion:(void (^__nullable)(NSError *__nullable))completion;

/**
 Open a dedicated stream handle to a remote peer at the nominated reliability level.

 The completion closure will provide either the successfully-connected stream or an error.

 Make sure to set the `delegate` property on the new stream immediately when it is received in the
 completion closure. This ensures that no callbacks will be missed.
 */
- (void)openStreamToAddress:(DITAddress *)address
                reliability:(DITBusReliability)reliability
                 completion:(void (^)(DITBusStream *__nullable, NSError *__nullable))completion;

@end

NS_ASSUME_NONNULL_END
