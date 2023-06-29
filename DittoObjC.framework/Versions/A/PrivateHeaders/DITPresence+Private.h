//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPresence.h>

@class _DITWeakWrapper;
@class _DITPresenceObserver;
@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

// NOTE: we expose this otherwise private function here to assist with tests.
DITPresenceGraph *DITPresenceGraphFromJSONString(NSString *presenceGraphJSONString);

@interface DITPresence ()

@property (nonatomic, readonly) NSData *graphCBOR;
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) dispatch_queue_t observerQueue;
@property (nonatomic, readonly) NSMutableArray<_DITWeakWrapper *> *weakPresenceObservers;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
    NS_DESIGNATED_INITIALIZER;

// IMPORTANT: DittoSwift defines the presence graph as native Swift structs and
// therefore needs to decode the presence graph from CBOR itself before it's
// passed to the observers.  Because we don't want to replicate the Presence
// class in Swift but reuse this ObjC version, we have to provide an _efficient_
// hook for processing the CBOR we receive from the FFI and pass it to the
// observers in the appropriate format.
//
// We solve this by allowing to pass an optional
// `NSValueTransformerName` per individual observer, which is then used to
// transform the presence graph from CBOR format to whatever the value
// transfomer gives us. This is done efficiently only once per value
// transfomer used and then dispatched to all observers requesting the
// corresponding transformation.
//
// For ObjC, we expose the public `observe:` method which delegates to this
// method by specifying the internal `DITPresenceGraphFromCBORTransformer`.
// DittoSwift, on the other hand, can provide it's own transformer. We could
// also expose this API publicly in the future and allow client code to use
// a custom transformer (or get access to the underlying CBOR directly).
- (id<DITObserver>)observeWithTransformerNamed:(nullable NSValueTransformerName)valueTransformerName
                              didChangeHandler:
                                  (void (^)(id presenceGraphCBOROrTransformed))didChangeHandler;

- (void)stopPresenceObserver:(_DITPresenceObserver *)presenceObserver;
- (void)presenceGraphDidChange:(NSData *)presenceGraphCBOR;

@end

NS_ASSUME_NONNULL_END
