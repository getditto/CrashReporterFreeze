//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *__nonnull const DITDomain;

// clang-format off
// Taken from https://gist.github.com/bdash/bf29e26c429b78cc155f1a2e1d851f8b
#if __has_attribute(ns_error_domain)
#define DIT_ERROR_ENUM(type, name, domain) \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wignored-attributes\"") \
    NS_ENUM(type, __attribute__((ns_error_domain(domain))) name) \
    _Pragma("clang diagnostic pop")
#else
#define DIT_ERROR_ENUM(type, name, domain) NS_ENUM(type, name)
#endif
// clang-format on

/**
 All of the error code values for `NSError`'s with the `DITDomain` domain.
 */
typedef DIT_ERROR_ENUM(NSInteger, DITErrorCode, DITDomain){
    /**
     An error occurred with the storage backend.
     */
    DITStorageInteralError = 10,

    /**
     The document could not be found.
    */
    DITDocumentNotFoundError = 11,

    /**
     The provided document content failed to be encoded.
    */
    DITDocumentContentEncodingFailed = 12,

    /**
     The request to get transport diagnostics failed.
    */
    DITTransportDiagnosticsUnavailable = 13,

    /**
     Decoding of transport diagnostics data failed.
    */
    DITTransportDiagnosticsDecodingFailed = 14,

    /**
     The attachment's data could not be retrieved.
     */
    DITAttachmentDataRetrievalError = 15,

    /**
     The attachment file failed to be copied.
     */
    DITAttachmentFileCopyError = 16,

    /**
     There was an error with a query.
     */
    DITQueryError = 17,

    /**
     The Ditto instance has not yet been activated, which is achieved via a successful call to
     `setLicenseToken`.
     */
    DITNotActivatedError = 18,

    /**
     The provided license token has expired.
     */
    DITLicenseTokenExpiredError = 19,

    /**
     Verification of the provided license token failed.
     */
    DITLicenseTokenVerificationFailedError = 20,

    /**
     The provided license token is in an unsupported future format.
     */
    DITLicenseTokenUnsupportedFutureVersionError = 21,

    /**
     Failed to authenticate with remote server.
     */
    DITFailedToAuthenticateError = 22,

    /**
     Sent a bus message with the same destination/reliability before the previous send completed.
     */
    DITBusSendBeforeCompletion = 23,

    /**
     Failed to send bus message.
     */
    DITBusSendFailed = 24,

    /**
     Failed to open a stream to the requested peer.
     */
    DITBusOpenStreamFailed = 25,

    /**
     The remote peer closed this BusStream.
     */
    DITBusStreamClosedByRemote = 26,

    /**
     The local peer closed this BusStream.
     */
    DITBusStreamClosedByLocal = 27,

    /**
     This BusStream closed due to a communication failure.
     */
    DITBusStreamFailed = 28,

    /**
     Bus message cannot be sent as the payload is too large (max 1 MB)
     */
    DITBusReliablePayloadTooLarge = 29,

    /**
     Bus message cannot be sent as the payload is too large (max 128 kB)
     */
    DITBusUnreliablePayloadTooLarge = 30,

    /**
     Bus message cannot be sent as the queue is full.
     */
    DITBusQueueFull = 31,

    /**
     Disabling sync with v2 peers failed.
     */
    DITDisableSyncWithV2Failed = 32,
};
