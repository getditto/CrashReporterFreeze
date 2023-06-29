//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITSubscription.h>

#import <DittoObjC/dittoffi.h>

@class _DITDittoHandleWrapper;
@class _DITOrderBy;

NS_ASSUME_NONNULL_BEGIN

@interface DITSubscription ()

@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly, nullable) NSData *queryArgsData;
@property (nonatomic, readwrite) int limit;
@property (nonatomic, readwrite) uint offset;
@property (nonatomic, readwrite) _DITOrderBy *orderBy;
@property (nonatomic, readwrite) uint orderByCount;

- (instancetype)initWithQuery:(NSString *)query
                queryArgsData:(nullable NSData *)queryArgsData
                      orderBy:(_DITOrderBy *)orderBy
                        limit:(int)limit
                       offset:(uint)offset
               collectionName:(NSString *)collectionName
           dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;
@end

NS_ASSUME_NONNULL_END
