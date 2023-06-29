//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITObserver.h>

#import <Foundation/Foundation.h>

@class DITPresenceGraph;
@class DITPresence;

NS_ASSUME_NONNULL_BEGIN

@interface _DITPresenceObserver : NSObject <DITObserver>

@property (nonatomic, readonly, nullable) DITPresence *presence;
@property (nonatomic, readonly, nullable) NSValueTransformerName transformedBy;
@property (nonatomic, readonly, copy) void (^block)(id presenceGraphOrCBOR);

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPresence:(DITPresence *)presence
                   transformedBy:(nullable NSValueTransformerName)transformerNameOrNil
                           block:(void (^)(id presenceGraphOrCBOR))block NS_DESIGNATED_INITIALIZER;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
