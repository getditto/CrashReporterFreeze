//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>

@class DITTransportHandleWrapper;
@protocol DITL2CAPConnectionDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface DITL2CAPConnection : NSObject <NSStreamDelegate>

- (instancetype)initWithChannel:(CBL2CAPChannel *)channel handle:(DITTransportHandleWrapper *)handle isServer:(BOOL)isServer uuid:(NSUUID *)uuid runLoop:(NSRunLoop *)runLoop;
- (int)sendDataDirect:(NSData *)data;
- (int)readDataDirect:(uint8_t *)buffer maxLength:(NSUInteger)length;

- (void)close;

@property (nonatomic, weak) id<DITL2CAPConnectionDelegate> delegate;
@property (nonatomic, readonly) NSRunLoop *runLoop;
@property (nonatomic, readonly) CBL2CAPChannel *channel;
@property (nonatomic, readonly, weak) DITTransportHandleWrapper *handle;
@property (nonatomic, copy, readonly) NSUUID *uuid;

@property (nonatomic, readonly) BOOL isServer;
@property (nonatomic, readonly) BOOL isFailed;

@end

NS_ASSUME_NONNULL_END
