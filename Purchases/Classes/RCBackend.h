//
//  RCBackend.h
//  Purchases
//
//  Created by Jacob Eiting on 9/30/17.
//  Copyright © 2017 RevenueCat, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RCPurchaserInfo, RCHTTPClient;

FOUNDATION_EXPORT NSErrorDomain const RCBackendErrorDomain;
NS_ERROR_ENUM(RCBackendErrorDomain) {
    RCUnexpectedBackendResponse = 0,
    RCBackendError,
    RCErrorParsingPurchaserInfo
};

typedef void(^RCBackendResponseHandler)(RCPurchaserInfo * _Nullable,
                                         NSError * _Nullable);

@interface RCBackend : NSObject

- (instancetype _Nullable)initWithSharedSecret:(NSString *)sharedSecret;

- (instancetype _Nullable)initWithHTTPClient:(RCHTTPClient *)client
                                sharedSecret:(NSString *)sharedSecret;

- (void)postReceiptData:(NSData *)data
              appUserID:(NSString *)appUserID
             completion:(RCBackendResponseHandler)completion;

- (void)getSubscriberDataWithAppUserID:(NSString *)appUserID
                            completion:(RCBackendResponseHandler)completion;

@property (nonatomic, readonly) BOOL purchasing;

@end

NS_ASSUME_NONNULL_END
