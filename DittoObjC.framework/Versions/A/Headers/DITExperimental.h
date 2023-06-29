//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITConnectionPriority.h>
#import <DittoObjC/DITBus.h>

NS_ASSUME_NONNULL_BEGIN

@class DITDitto;

/**
 Upcoming SDK features made available for prototyping.

 @warning Experimental functionality should not be used in production
 applications as it may be changed or removed at any time, and may not
 have the same security features.
 */
@interface DITExperimental : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 Access the Ditto Bus preview using a given Ditto instance.

 This may be used for sending messages or opening arbitrary data streams
 with other peers in the mesh.
 */
+ (DITBus *)busFor:(DITDitto *)ditto;

/**
 Set a Query Overlap Group for the local Ditto instance. Query Overlap Groups
 are an optional feature that can be used to group peers based on their
 anticipated queries, and set relative connection priorities amongst these groups.

 The numeric value for a query overlap group is entirely use-case specific
 and apps are free to use whichever values they like - provided all peers agree
 on the meaning of the values. All peers belong to query overlap group `0`
 initially and will connect with normal priority until specified otherwise.
 The number that represents the query group doesn't mean that the group has
 higher priority. The number is just an enum to represent the group. To
 assign priority, see `[DITExperimental +setQueryOverlapGroup:ditto:]`.

 ### Why Are Query Overlap Groups Needed?

 Ditto LiveQueries will replicate only documents that match a query between
 peers. In some cases, two peers with the same query might be separated by
 others who do not share the same query. Consider a simple example of three peers
 connected in a line (A - B - C). If A and C share the same query but B
 does not, data will not replicate from A to C as B is not interested in
 the data - and therefore doesn't possess it to replicate onwards.

 If your app's use-case includes non-overlapping queries like this example,
 query overlap groups are designed to help. You can use Query Overlap Groups
 to tell Ditto that peers A and C are likely to have queries that overlap. This
 extra information enables Ditto to take measures to ensure realtime sync
 occurs, even creating an encrypted tunnel for A - C via B.
 Not all apps will require this functionality. In many apps, all peers share
 much the same queries. These apps are better served by the automatic mesh
 that Ditto will create for you. If used, Query Overlap Groups should be set
 before starting Ditto sync.

 ### Use Cases

 #### High Priority Between Same Group Members

 Ensuring that peers with the same query can fully replicate with each other,
 even if they are separated by other peers that don't have the same queries.

 For example, perhaps your use case has administrative apps which should replicate
 all data amongst each other, and regular apps which query only a subset of the
 data. You can assign all administrative apps to one query overlap group (e.g. `2`).
 You can then configure peers with the query overlap group "2" to treat other peers
 in group "2" as a high-priority connection target. For all peers in a high-priority
 Query Overlap Group, Ditto will prioritize these connections, and set up end-to-end
 encrypted multihop connections if direct connections aren't available. In doing so,
 our example administrative apps can be sure that their data will remain in sync,
 even if they're separated by other regular apps in the local mesh.

 #### High Priority Between Different Group Members

 Ensure replication between peers in one Query Overlap Group with peers in a different
 Query Overlap Group - perhaps due to the role or function which those peers perform
 in the mesh.

 For example, consider a fast-food ordering app in which customers query their
 order (and only their own) working together with staff who must receive everyone's
 orders. We want to express that customers should replicate with the staff with
 high priority, whereas there's little to be gained from customers replicating
 amongst each other since each of their orders are private. All customer apps can
 be assigned to one Query Overlap Group (e.g. `1`) and all staff to another (e.g.
 `2`). Customer apps would configure a high-priority connection preference for
 staff. In doing so, customer apps would establish a direct connection to staff
 if possible, and otherwise establish an end-to-end encrypted connection hopping
 via other customers if needed. The end-to-end encrypted connection guarantees
 customer-to-staff replication without personal information being readable by other
 customers along the way.

 #### Low Priority Between Different Group Members

 Ensure connections aren't established with certain Query Overlap Groups if
 the connection would be wasteful.

 Query Overlap Groups can also be used to prevent peers from connecting
 if you know the connection would be wasteful. Perhaps you know that different
 types of peers or apps don't share any data in common. In this case, peers can
 be assigned to the relevant Query Overlap Group, and the priority can be set
 to the lowest value of "don't connect". The peers will then save their available
 connection capacity for other, potentially more useful connections.

 @warning Query Overlap Groups are not a security mechanism. A peer may change
 its Query Overlap Group at runtime for any reason.

 @param queryOverlapGroup The Query Overlap Group value for this peer. Must be
 between 0 and 63 (inclusive). Defaults to `0` if not set.
 @param ditto The `Ditto` instance should inherit the Query Overlap Group.
 */
+ (void)setQueryOverlapGroup:(uint8_t)queryOverlapGroup ditto:(DITDitto *)ditto;

/**
 Configure the priority with which Ditto should connect to any peers in the
 given Query Overlap Group. If the priority is set to high, an end-to-end encrypted
 multihop connection will be established wherever it is not possible to establish
 a direct connection.

 Connections can be established in either direction, so the remote peers
 might attempt connections to this Ditto with different priorities unless
 they are similarly configured.

 @warning Query Overlap Groups are not a security mechanism. A peer may change
 its Query Overlap Group at runtime for any reason.

 @param priority The priority with which outgoing connections should be attempted.
 @param queryOverlapGroup The Query Overlap Group to which the priority should
  apply.
 @param ditto The local `Ditto` instance to configure.
 */
+ (void)setPriority:(DITConnectionPriority)priority
    forQueryOverlapGroup:(uint8_t)queryOverlapGroup
                   ditto:(DITDitto *)ditto;

/** Transcodes CBOR to a JSON string. */
+ (nullable NSData *)JSONDataByTranscodingCBORData:(NSData *)cbor
                                             error:(NSError *_Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
