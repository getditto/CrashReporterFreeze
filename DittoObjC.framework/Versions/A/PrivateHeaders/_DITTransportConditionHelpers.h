//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITTransportCondition.h>

#import <DittoObjC/dittoffi.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DITTransportConditionHelpers : NSObject

+ (enum DITTransportCondition)DITTransportConditionFromTransportCondition:
    (TransportCondition_t)transportCondition;
+ (NSString *)transportConditionDescription:(enum DITTransportCondition)DITTransportCondition;
+ (enum DITConditionSource)DITConditionSourceFromConditionSource:(ConditionSource_t)conditionSource;
+ (NSString *)conditionSourceDescription:(enum DITConditionSource)conditionSource;

@end

NS_ASSUME_NONNULL_END
