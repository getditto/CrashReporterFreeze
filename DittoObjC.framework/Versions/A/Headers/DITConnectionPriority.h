//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#ifndef DITConnectionPriority_h
#define DITConnectionPriority_h

#import <Foundation/Foundation.h>

/**
 The priority with which the local device should reach out to
 particular remote peers in the Ditto mesh.

 For most use-cases, this API is not required as Ditto will automatically
 create an optimal P2P mesh. Certain use-cases, however, might require
 more manual control over how the mesh is formed.
 */
typedef NS_ENUM(NSUInteger, DITConnectionPriority) {
    /**
     Do not attempt to connect. Note that connections can be established
     by either peer, so the remote peer might still connect to this Ditto
     unless they are similarly configured.
     */
    DITConnectionPriorityDontConnect = 0,

    /**
     Connect with normal priority. This is also the default case unless
     specified otherwise.
     */
    DITConnectionPriorityNormal = 1,

    /**
     Connect with high priority. Remote peers which are assigned this
     connection priority will be preferred over normal priority peers.

     This priority will only have a meaningful effect once there are more
     nearby peers than the local Ditto instance is able to simultaneously
     connect to.
     */
    DITConnectionPriorityHigh = 2,
};

#endif /* DITConnectionPriority_h */
