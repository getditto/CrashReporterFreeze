//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITBluetoothLEConfig.h>
#import <DittoObjC/DITLANConfig.h>
#import <DittoObjC/DITAWDLConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutablePeerToPeer;

/**
 Configuration of peer-to-peer transports, which are able to discover and connect to peers on their
 own.

 For more information refer to the documentation for DITTransportConfig.
 */
@interface DITPeerToPeer : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)peerToPeer;

@property (nonatomic, readonly) DITBluetoothLEConfig *bluetoothLe;
@property (nonatomic, readonly) DITLANConfig *lan;
@property (nonatomic, readonly) DITAWDLConfig *awdl;

- (instancetype)initWithDITPeerToPeer:(DITPeerToPeer *)peerToPeer;
- (instancetype)initWithBluetoothLe:(DITBluetoothLEConfig *)bluetoothLe
                                lan:(DITLANConfig *)lan
                               awdl:(DITAWDLConfig *)awdl;

@end

// MARK: -

@interface DITPeerToPeer (DITTypeCorrections)

- (DITPeerToPeer *)copy;
- (DITMutablePeerToPeer *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
