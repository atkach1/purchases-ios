//
//  RCPurchaserInfo.h
//  Purchases
//
//  Created by Jacob Eiting on 9/30/17.
//  Copyright © 2017 RevenueCat, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 A container for the most recent purchaser info returned from `RCPurchases`. These objects are non-mutable and do not update automatically.
 */
@interface RCPurchaserInfo : NSObject

/// All *subscription* product identifiers with expiration dates in the future.
@property (readonly) NSSet<NSString *> *activeSubscriptions;

/// All product identifiers purchases by the user regardless of expriration.
@property (readonly) NSSet<NSString *> *allPurchasedProductIdentifiers;

/// Returns the latest expiration date of all products, nil if there are none
@property (readonly) NSDate * _Nullable latestExpirationDate;

/**
 Get the expiration date for a given product identifier.

 @param productIdentifier Product identifier for subscription product

 @return The expiration date for `productIdentifier`, `nil` if product never purchased
 */
- (NSDate * _Nullable)expirationDateForProductIdentifier:(NSString *)productIdentifier;

@end

NS_ASSUME_NONNULL_END
