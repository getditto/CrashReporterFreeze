//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoTransportsObjC/DITAWDLServerAdvertiserDelegate.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A running AWDL advertiser implementation, using some API or another. Dealloc to stop.
 */
@protocol DITAWDLServerAdvertiser <NSObject>

@property (nonatomic, weak) NSObject<DITAWDLServerAdvertiserDelegate> *delegate;

- (void)shutdown;

@end

NS_ASSUME_NONNULL_END
