//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjCUtil/dittoffi.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define DITLogError(args...) DITLog(C_LOG_LEVEL_ERROR, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DITLogWarning(args...) DITLog(C_LOG_LEVEL_WARNING, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DITLogInfo(args...) DITLog(C_LOG_LEVEL_INFO, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DITLogDebug(args...) DITLog(C_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DITLogVerbose(args...) DITLog(C_LOG_LEVEL_VERBOSE, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);

void DITLog(CLogLevel_t logLevel, const char *file, int lineNumber, const char *funcName, NSString *format, ...) NS_FORMAT_FUNCTION(5,6);

NS_ASSUME_NONNULL_END
