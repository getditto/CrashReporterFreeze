//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

/**
 Reliability modes for bus streams.
 */
typedef NS_ENUM(NSUInteger, DITBusReliability) {
    DITBusUnreliable = 1,
    // DITBusUnreliableSequenced = 2, // reserved for future use
    DITBusReliable = 3,
};
