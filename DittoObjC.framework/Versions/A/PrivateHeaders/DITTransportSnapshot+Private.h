//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITTransportSnapshot.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITTransportSnapshot ()
- (instancetype)initWithConnectionType:(NSString *)connectionType
                            connecting:(NSArray<NSNumber *> *)connecting
                             connected:(NSArray<NSNumber *> *)connected
                         disconnecting:(NSArray<NSNumber *> *)disconnecting
                          disconnected:(NSArray<NSNumber *> *)disconnected;
@end

NS_ASSUME_NONNULL_END
