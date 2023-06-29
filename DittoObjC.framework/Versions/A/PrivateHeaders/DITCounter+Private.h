//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITCounter.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITCounter () {
    @protected
    double _value;
}

- (instancetype)initWithValue:(double)value NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
