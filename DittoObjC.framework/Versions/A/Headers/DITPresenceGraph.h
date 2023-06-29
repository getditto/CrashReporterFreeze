//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITPeer;
@class DITConnection;

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the Ditto mesh network of peers and their connections between each
 other. The `localPeer` is the entry point, all others are remote peers known
 by the local peer (either directly or via other remote peers).
 */
@interface DITPresenceGraph : NSObject <NSCopying>

/**
 Returns the local peer (usually the peer that is represented by the
 currently running Ditto instance). The `localPeer` is the entry point, all
 others are remote peers known by the local peer (either directly or via other
 remote peers).
 */
@property (nonatomic, copy, readonly) DITPeer *localPeer;

/**
 Returns all remote peers known by the `localPeer`, either directly or via other
 remote peers.
 */
@property (nonatomic, copy, readonly) NSArray<DITPeer *> *remotePeers;

/**
 Decodes passed in CBOR and initializes the presence
 graph with the resulting dictionary representation. Raises an
 `NSInvalidArgumentException` if CBOR couldn't be decoded or the dictionary
 representation is not a valid presence graph representation.
 */
// NOTE: exception instead of `NSError` here on purpose, passing an invalid CBOR is considered a
// programming error.
- (instancetype)initWithCBOR:(NSData *)cbor;

/**
 Initializes the presence graph with the passed in
 dictionary representation. Raises an `NSInvalidArgumentException` if the
 dictionary representation is not a valid presence graph.
 */
// NOTE: exception instead of `NSError` here on purpose, passing an invalid dictionary
// representation is considered a programming error.
- (instancetype)initWithDictionaryRepresentation:(NSDictionary *)dictionaryRepresentation;

/**
 Initializes the presence graph with the passed in `localPeer` and an
 array of all remote peers.
 */
- (instancetype)initWithLocalPeer:(DITPeer *)localPeer
                      remotePeers:(NSArray<DITPeer *> *)remotePeers NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/**
 Returns a dictionary with all connections found in this graph by their IDs.
 */
- (NSDictionary<NSString *, DITConnection *> *)allConnectionsByID;

- (NSUInteger)hash;

- (BOOL)isEqual:(nullable id)object;
- (BOOL)isEqualToPresenceGraph:(DITPresenceGraph *)presenceGraph;

- (DITPeer *)copy;
- (DITPeer *)copyWithZone:(nullable NSZone *)zone;

@end

NS_ASSUME_NONNULL_END
