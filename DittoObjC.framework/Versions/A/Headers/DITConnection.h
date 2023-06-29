//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITConnectionType.h>
#import <Foundation/Foundation.h>

@class DITAddress;

NS_ASSUME_NONNULL_BEGIN

/** Represents a connection between two peers on the Ditto mesh network. */
@interface DITConnection : NSObject <NSCopying>

/** Unique identifier for the connection. */
@property (nonatomic, readonly, copy) NSString *id;

/** Type of transport enabling this connection. */
@property (nonatomic, readonly) DITConnectionType type;

/** The address of the peer at one end of the connection. */
@property (nonatomic, readonly, copy) DITAddress *peer1;

/** The address of the peer at one end of the connection. */
@property (nonatomic, readonly, copy) DITAddress *peer2;

/*
 Gets an estimate of distance to the remote peer. This value is inaccurate.
 The environment, hardware, and several other factors can greatly affect
 this value. It is currently derived from RSSI.
 */
@property (nonatomic, readonly, nullable, copy) NSNumber *approximateDistanceInMeters;

- (instancetype)init NS_UNAVAILABLE;

/** Initializes the connection with a dictionary representation. */
- (instancetype)initWithDictionaryRepresentation:(NSDictionary *)dictionaryRepresentation;

/** Initializes the connection with all possible parameters. */
- (instancetype)initWithID:(NSString *)ID
                           type:(DITConnectionType)type
                          peer1:(DITAddress *)peer1
                          peer2:(DITAddress *)peer2
    approximateDistanceInMeters:(nullable NSNumber *)approximateDistanceInMeters
    NS_DESIGNATED_INITIALIZER;

- (NSUInteger)hash;

- (BOOL)isEqual:(nullable id)object;
- (BOOL)isEqualToConnection:(DITConnection *)connection;

- (DITConnection *)copy;
- (DITConnection *)copyWithZone:(nullable NSZone *)zone;

- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
