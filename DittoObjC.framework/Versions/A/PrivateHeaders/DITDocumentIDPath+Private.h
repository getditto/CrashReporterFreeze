//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocumentIDPath.h>

#import <DittoObjC/DITDocumentID.h>

@class DITDocumentIDPath;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocumentIDPath ()
@property (nonatomic, readonly) DITDocumentID *docID;
@property (nonatomic, copy) NSString *path;

+ (instancetype)documentIDPathFrom:(DITDocumentIDPath *)docIDPath
                appendingComponent:(NSString *)component;
+ (instancetype)documentIDPathWith:(DITDocumentID *)docID initialPath:(NSString *)initialPath;

- (instancetype)initWithDocumentID:(DITDocumentID *)docID path:(NSString *)path;
@end

NS_ASSUME_NONNULL_END
