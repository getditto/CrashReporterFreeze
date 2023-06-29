//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITAuthenticationSuccess : NSObject

@property (nonatomic, nullable, readwrite) NSString *userID;
@property (nonatomic, readwrite) NSMutableDictionary<NSString *, NSString *> *userInfo;
@property (nonatomic, readwrite) NSDate *accessExpires;
@property (nonatomic, nullable, readwrite) NSDate *offerRefreshUntil;
@property (nonatomic, readwrite) NSMutableArray<NSString *> *audiences;
@property (nonatomic, readwrite) BOOL readEverythingPermission;
@property (nonatomic, readwrite) BOOL writeEverythingPermission;

@property (nonatomic, nullable, readwrite)
    NSMutableDictionary<NSString *, NSMutableArray<NSString *> *> *readPermissions;
@property (nonatomic, nullable, readwrite)
    NSMutableDictionary<NSString *, NSMutableArray<NSString *> *> *writePermissions;

- (void)addReadPermissionForCollection:(NSString *)coll queryString:(NSString *)query;
- (void)addWritePermissionForCollection:(NSString *)coll queryString:(NSString *)query;

@end

NS_ASSUME_NONNULL_END
