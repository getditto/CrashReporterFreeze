//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides information about a given transport at a point in time.
 */
@interface DITTransportSnapshot : NSObject
/**
 The type of connection that exists between the peers.
 */
@property (nonatomic, readonly) NSString *connectionType;

/**
 A list of the site IDs that are in a connecting state for the transport.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *connecting;

/**
 A list of the site IDs that are in a connected state for the transport.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *connected;

/**
 A list of the site IDs that are in a disconnecting state for the transport.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *disconnecting;

/**
 A list of the site IDs that are in a disconnected state for the transport.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *disconnected;
@end

NS_ASSUME_NONNULL_END
