//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocumentPath.h>

@class DITDocumentID;

@class _DITDocumentHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocumentPath ()
@property (nonatomic, readonly) _DITDocumentHandleWrapper *documentHandleWrapper;
@property (nonatomic, readonly) DITDocumentID *docID;
@property (nonatomic, copy) NSString *path;

- (instancetype)initWithDocumentHandleWrapper:(_DITDocumentHandleWrapper *)documentHandleWrapper
                                   documentID:(DITDocumentID *)docID
                                         path:(NSString *)path;

+ (instancetype)documentPathWithDocumentHandleWrapper:
                    (_DITDocumentHandleWrapper *)documentHandleWrapper
                                           documentID:(DITDocumentID *)documentID
                                          initialPath:(NSString *)initialPath;

+ (instancetype)documentPathFrom:(DITDocumentPath *)path appendingComponent:(NSString *)component;

@end

NS_ASSUME_NONNULL_END
