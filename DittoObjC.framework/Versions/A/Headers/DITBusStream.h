//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITBusReliability.h>
#import <DittoObjC/DITBusStreamDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A message-based communication channel to another peer in the mesh.

 When a DittoBusStream is received by any means, you must immediately set a delegate. This provides
 the notifications of incoming messages and other events.

 Outgoing messages can be enqueued using `enqueueMessage`. You must wait for the delegate method
 indicating that the enqueue was successful before calling this method again. This process provides
 backpressure so that your app does not send data more quickly than the network can deliver.
 */
@interface DITBusStream : NSObject

/**
 An ID unique to the local device that can be used to track this individual stream.
 */
@property (readonly, nonatomic) uint64_t streamID;

/**
 The reliability mode under which this stream is operating.
 */
@property (readonly, nonatomic) DITBusReliability reliability;

/**
 YES if `enqueueMessage` may be called at this time and NO if there is a send pending.

 Consider using `DITBusStreamDelegate` to be informed when the enqueue operation has completed.
 */
@property (readonly, nonatomic) BOOL isReady;

/**
 Delegate for events relating to this stream.

 This must be set to a non-nil value as soon as you obtain this stream, whether by opening a stream
 or by having an incoming stream arrive.
 */
@property (nonatomic, nullable, weak) id<DITBusStreamDelegate> delegate;

/**
 Enqueue a message to be sent to the other peer.

 You must wait for the delegate method indicating that enqueuing was successful before calling this
 again.
 */
- (void)enqueueMessage:(NSData *)data;

/**
 Close this stream in both directions.

 It is recommended to call this when finished with the stream. Alternatively if the instance is
 deallocated then it will be closed automatically.
 */
- (void)close;

@end

NS_ASSUME_NONNULL_END
