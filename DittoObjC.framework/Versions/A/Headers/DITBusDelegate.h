//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITAddress;
@class DITBus;
@class DITBusMessage;
@class DITBusStream;

/**
 Callbacks relating to Ditto Bus for both receiving single messages and accepting incoming streams.
 */
@protocol DITBusDelegate <NSObject>
@optional

/**
 A bus message has been received from another peer in the mesh.
 */
- (void)ditBus:(DITBus *)bus didReceiveSingleMessage:(DITBusMessage *)message;

/**
 Another peer has opened a stream to this device. Set its delegate immediately.
 */
- (void)ditBus:(DITBus *)bus
    didReceiveIncomingStream:(DITBusStream *)busStream
                    fromPeer:(DITAddress *)peer;

@end
