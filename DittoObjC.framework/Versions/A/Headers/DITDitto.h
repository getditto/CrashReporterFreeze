//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDittoDelegate.h>
#import <DittoObjC/DITTransportConfig.h>
#import <DittoObjC/DITLogLevel.h>
#import <DittoObjC/DITObserver.h>

#import <Foundation/Foundation.h>

@class DITAuthenticator;
@class DITIdentity;
@class DITPeersObserver;
@class DITPeersObserverV2;
@class DITDiskUsage;
@class DITPresence;
@class DITRemotePeer;
@class DITStore;
@class DITTransportDiagnostics;
@class DITPresenceGraph;

NS_ASSUME_NONNULL_BEGIN

/**
 The entrypoint to the Ditto SDK.

 For a `DITDitto` instance to continue to connect to other devices it must be kept in scope.
 */
@interface DITDitto : NSObject

/**
 Configure a custom identifier for the current device.

 When using `observePeers`, each remote peer is represented by a short UTF-8 "device name".

 By default this will be a truncated version of the device's hostname. It does not need to be unique
 among peers.

 Configure the device name before calling `startSync:`. If it is too long it may be truncated.
 */
@property (nonatomic) NSString *deviceName;

/**
 Persistence directory used to persist Ditto data.
 */
@property (nonatomic) NSURL *persistenceDirectory;

/**
 The Ditto application ID.
 */
@property (nonatomic, readonly) NSString *appID;

/**
 Provides access to the SDK's store functionality.
 */
@property (atomic, readonly) DITStore *store;

/**
 Provides visibility into the local disk usage for Ditto.
 */
@property (atomic, readonly) DITDiskUsage *diskUsage;

/**
 Provides access to authentication information and methods for logging on to
 Ditto Cloud.
 */
@property (nonatomic, nullable, readonly) DITAuthenticator *auth;

/**
 Provides access to the SDK's presence functionality.
 */
@property (nonatomic, readonly) DITPresence *presence;

/**
 Provides access to the instance's identity information.
 */
@property (nonatomic, readonly) DITIdentity *identity;

/**
 A flag indicating whether or not the SDK has been activated with a valid
 license token.
 */
@property (nonatomic, readonly, getter=isActivated) BOOL activated;

/**
 A flag indicating whether or not sync is active. Use `startSync:` to activate
 sync and `stopSync` to deactivate sync.
 */
@property (nonatomic, readonly, getter=isSyncActive) BOOL syncActive;

/**
 Assign a new transports configuration. By default peer-to-peer transports (Bluetooth, WiFi and
 AWDL) are enabled.

 You may use this method to alter the configuration at any time. Sync will not begin until
 `startSync` is called.
 */
@property (nonatomic, copy) DITTransportConfig *transportConfig;

/**
 The site ID that the instance of `DITDitto` is using as part of its identity.
 */
@property (nonatomic, readonly) uint64_t siteID;

/**
 An optional delegate that will be called with SDK lifecycle information if defined.
 */
@property (nonatomic, weak) id<DITDittoDelegate> delegate;

/**
 The dispatch queue that will be used to deliver delegate events. Defaults to the main queue.
 */
@property (nonatomic) dispatch_queue_t delegateEventQueue;

/**
Indicates whether history tracking is enabled or not.

@warning History Tracking is **experimental** and shouldn't be used in production.
*/
@property (nonatomic, readonly, getter=isHistoryTrackingEnabled) BOOL historyTrackingEnabled;

/**
 Initializes a new `DITDitto`.
 This will initialize an instance of `DITDitto` with the default configuration.
 */
- (instancetype)init;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 @param historyTrackingEnabled Whether or not you want history tracking enabled.

 @warning History Tracking is **experimental** and shouldn't be used in production.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity
          historyTrackingEnabled:(BOOL)historyTrackingEnabled;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 @param directory The directory that will be used to persist Ditto data.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity
            persistenceDirectory:(nullable NSURL *)directory;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 @param historyTrackingEnabled Whether or not you want history tracking enabled.
 @param directory The directory that will be used to persist Ditto data.

 @warning History Tracking is **experimental** and shouldn't be used in production.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity
          historyTrackingEnabled:(BOOL)historyTrackingEnabled
            persistenceDirectory:(nullable NSURL *)directory;

/**
 Starts the network transports. Ditto will connect to other devices and sync with them where
 appropriate.

 By default Ditto will enable all peer-to-peer transport types. On iOS this means Bluetooth,
 WiFi and AWDL. The network configuration can be customized using the `setTransportConfig`
 method.

 You must have activated Ditto with a successful call to `setLicenseToken` before starting sync.

 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return `YES` if sync was successfully started. `NO` otherwise.
 */
- (BOOL)startSync:(NSError *_Nullable __autoreleasing *)error;

/**
 Stops all network transports.

 You may continue to use the database locally but no data will sync to or from other devices.
 */
- (void)stopSync;

/**
 Convenience method to update the current transport config of the receiver.

 Invokes the block with a mutable copy of the current transport config which you
 can alter to your liking. The updated transport config is then set on the
 receiver.

 You may use this method to alter the configuration at any time. Sync
 will not begin until `startSync` is invoked.
 */
- (void)updateTransportConfig:(void (^)(DITMutableTransportConfig *transportConfig))block;

/**
 Activate an offline `DITDitto` instance by setting a license token. You cannot sync data across
 instances using an offline (Development, OfflinePlayground, Manual or SharedKey) `DITDitto`
 instance before you have activated it.

 @param licenseToken The license token to activate the `DITDitto` instance with, which you can find
 on the Ditto portal (https://portal.ditto.live).
 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return `YES` if the license token was successfully set and the `DITDitto` instance is now
 activated for sync. `NO` otherwise.
 */
- (BOOL)setOfflineOnlyLicenseToken:(NSString *)licenseToken
                             error:(NSError *_Nullable __autoreleasing *)error;

/**
 Request bulk status information about the transports.

 This is mostly intended for statistical or debugging purposes.

 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return An instance of `DITTransportDiagnostics` or `nil` if there was an error.
 */
- (nullable DITTransportDiagnostics *)transportDiagnostics:(NSError **)error;

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are required. A newly
 registered observer will have a peers update delivered to it immediately. From then on it will be
 invoked repeatedly when Ditto devices come and go, or the active connections to them change.

 @deprecated use `[self.presence observe:]` instead.
 */
- (id<DITObserver>)observePeers:(void (^)(NSArray<DITRemotePeer *> *))callback
    __deprecated_msg("Use `[self.presence observe:]` instead.");

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are required. A newly
 registered observer will have a peers update delivered to it immediately. From then on it will be
 invoked repeatedly when Ditto devices come and go, or the active connections to them change.

 @deprecated use `[self.presence observe:]` instead.
 */
- (id<DITObserver>)observePeersV2:(void (^)(NSString *))callback
    __deprecated_msg("Use `[self.presence observe:]` instead.");

/**
 Returns a string identifying the version of the Ditto SDK.
 */
- (NSString *)sdkVersion;

/**
 The default location of Ditto data files when no persistence directory is specified.
 */
+ (NSURL *)defaultDittoDirectory:(NSFileManager *)fileManager;

/**
 Removes all sync metadata for any remote peers which aren't currently connected. This
 method shouldn't usually be called. Manually running garbage collection often will
 result in slower sync times. Ditto automatically runs a garbage a collection process
 in the background at optimal times.

 Manually running garbage collection is typically only useful during testing if large
 amounts of data are being generated. Alternatively, if an entire data set is to be
 evicted and it's clear that maintaining this metadata isn't necessary, then garbage
 collection could be run after evicting the old data.
 */
- (void)runGarbageCollection;

/**
  Explicitly opt-in to disabling the ability to sync with Ditto peers running
  any version of the SDK in the v2 series of releases.

  Assuming this succeeds then this peer will only be able to sync with other
  peers using SDKs in the v3 series of releases. Note that this disabling of
  sync spreads to peers that sync with a peer that has disabled, or has
  (transitively) had disabled, syncing with v2 SDK peers.

  @param error On input, a pointer to an error object. If an error occurs, this
  pointer is set to an actual error object containing the error information. You
  may specify nil for this parameter if you do not want the error information.
  @return `YES` if the operation was successful. `NO` otherwise.
 */
- (BOOL)disableSyncWithV2:(NSError *_Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
