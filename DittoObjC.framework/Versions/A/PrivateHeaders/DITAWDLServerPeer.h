//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An active incoming connection to our AWDL listener.
 */
@protocol DITAWDLServerPeer <NSObject>

- (int)sendDataDirect:(NSData *)data;
- (int)readDataDirect:(uint8_t *)buffer maxLength:(NSUInteger)len;

@end

NS_ASSUME_NONNULL_END
