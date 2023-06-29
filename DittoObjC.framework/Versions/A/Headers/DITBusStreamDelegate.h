//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITAddress;
@class DITBus;
@class DITBusStream;

/**
 Callbacks required to use the Ditto Bus API with explicit stream handles.
 */
@protocol DITBusStreamDelegate <NSObject>

/**
 The operation to enqueue outgoing data on a stream has completed. More data may now be enqueued.

 The message sequence number may be used to track when the remote side has fully acknowledged
 receipt.

 `error` will be non-nil if the operation failed.
 */
- (void)ditBusStream:(DITBusStream *)busStream
    didEnqueueDataWithMessageSequence:(uint64_t)messageSequence
                                error:(NSError *)error;

/**
 The stream has closed. This can be triggered by calling `close()` or by the remote peer doing the
 same.
 */
- (void)ditBusStream:(DITBusStream *)busStream didClose:(NSError *)error;

/**
 A new message has been received from the specified stream.
 */
- (void)ditBusStream:(DITBusStream *)busStream didReceiveMessage:(NSData *)message;

/**
 The remote peer has acknowledged receipt of all messages up to the given sequence number.
 */
- (void)ditBusStream:(DITBusStream *)busStream didAcknowledgeReceipt:(uint64_t)messageSequence;

@end
