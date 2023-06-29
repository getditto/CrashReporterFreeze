//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Disabling clang format for the num because the NS_SWIFT_NAME()
// annotation bemuses clang-format.
// clang-format off

/**
 The type of `DITConnection` between two `DITPeer`s signaling what
 transport is being used for it.
 */
typedef NS_ENUM(NSUInteger, DITConnectionType) {
    DITConnectionTypeBluetooth = 1,
    DITConnectionTypeAccessPoint,
    DITConnectionTypeP2PWiFi NS_SWIFT_NAME(p2pWiFi),
    DITConnectionTypeWebSocket
};

// clang-format on

/** Returns a dictionary of all types by their names. */
NSDictionary *DITConnectionTypeAllCasesByName(void);

/** Returns a dictionary of all names by their types. */
NSDictionary *DITConnectionTypeAllNamesByCase(void);

/**
 Returns an array containing all possible cases of the `DITConnectionType`
 enum.
 */
NSArray<NSNumber *> *DITConnectionTypeAllCases(void);

/**
 Returns an array containing the names for all possible cases of the
 `DITConnectionType` enum.
 */
NSArray<NSString *> *DITConnectionTypeAllCaseNames(void);

/** Returns the name for a particular case of the `DITConnectionType` enum. */
NSString *DITConnectionTypeName(DITConnectionType connectionType);

/**
 Returns the case for the name of a particular case of the
 `DITConnectionType` enum.
 */
DITConnectionType DITConnectionTypeForName(NSString *name);

NS_ASSUME_NONNULL_END
