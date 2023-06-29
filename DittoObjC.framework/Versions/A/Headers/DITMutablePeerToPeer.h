//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPeerToPeer.h>

#import <DittoObjC/DITMutableAWDLConfig.h>
#import <DittoObjC/DITMutableBluetoothLEConfig.h>
#import <DittoObjC/DITMutableLANConfig.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutablePeerToPeer : DITPeerToPeer

@property (nonatomic, readonly, copy) DITMutableBluetoothLEConfig *bluetoothLe;
@property (nonatomic, readonly, copy) DITMutableLANConfig *lan;
@property (nonatomic, readonly, copy) DITMutableAWDLConfig *awdl;

- (void)setBluetoothLe:(DITBluetoothLEConfig *)bluetoothLe;
- (void)setLan:(DITLANConfig *)lan;
- (void)setAwdl:(DITAWDLConfig *)awdl;

@end

NS_ASSUME_NONNULL_END
