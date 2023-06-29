//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPeerToPeer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITPeerToPeer () {
    @protected
    DITBluetoothLEConfig *_bluetoothLe;
    @protected
    DITLANConfig *_lan;
    @protected
    DITAWDLConfig *_awdl;
}

- (instancetype)initWithBluetoothLe:(DITBluetoothLEConfig *)bluetoothLe
                                lan:(DITLANConfig *)lan
                               awdl:(DITAWDLConfig *)awdl
                               copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
