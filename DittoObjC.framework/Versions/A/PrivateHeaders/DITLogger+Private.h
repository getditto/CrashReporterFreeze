//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITLogger.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITLogger ()
/**
 Initializes the logging runtime, if it hasn't been initialized already.

 Note that calling this is rarely necessary, since instantiating a `Ditto` instance does this
 automatically.
 */
+ (void)__start;

/**
 * Only used in tests, mainly for swift to have access to emitting some form of log message.
 */
+ (void)__logError:(NSString *)msg;

@end

NS_ASSUME_NONNULL_END
