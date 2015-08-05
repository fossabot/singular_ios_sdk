//
//  Singular.h
//  Singular
//
//  Created by Daniel Shein on 1/1/15.
//  Copyright (c) 2015 Singular Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKPaymentTransaction;

@interface Singular : NSObject

/**
 * Initializes Singular's context. must be called before any other call to the api.
 * Should be called in your UIApplicationDelegate's didFinishLaunchingWithOptions:
 * @param apiKey - your Singular API key
 * @param appId - you Singular App ID
 * @param sandboxModeEnabled - boolean that specifies whether to enable sandbox mode
 */
+(void)initializeSingularWithApiKey:(NSString *)apiKey andAppId:(NSString *)appId;
+(void)initializeSingularWithApiKey:(NSString *)apiKey andAppId:(NSString *)appId andSandboxModeEnabled:(BOOL)sandboxModeEnabled;


/**
 * The users unique Singular ID
 */
+(NSString *)singularId;

/**
 * Tell Singular that a particular event has happened.
 *
 * @param eventType The Event type, e.g: 'purchase', 'level-up'
 * @param eventProperties An optional NSDictionary containing the callback parameters.
 */
+(void)trackEvent:(NSString *)eventType withProperties:(NSDictionary *)eventProperties;



/**
 * Tell Singular that a particular event has happened.
 *
 * @param eventType The Event type, e.g: 'purchase', 'level-up'
 */
+(void)trackEvent:(NSString *)eventType;


/**
 * Tell Singular that a particular event has happened.
 *
 * @param eventType The Event type, e.g: 'purchase', 'level-up'
 * @param attribute1 An additional attribute to break-down statistics by
 */
+(void)trackEvent:(NSString *)eventType withAttribute:(NSString *)attribute;


/**
 * Tell Singular that a particular event has happened.
 *
 * @param eventType The Event type, e.g: 'purchase', 'level-up'
 * @param attributes nil-terminated attributes list. Only the first 5 attributes are accepeted, the rest are ignored
 */
+(void)trackEvent:(NSString *)eventType withAttributes:(NSString *)firstAttribute, ... NS_REQUIRES_NIL_TERMINATION;



/**
 * Tell Singular that a user generated some revenue.
 * Uses the default currency as the currency for this event
 *
 * @param price The price in cents (example: 1.5 means one and a half cents)
 */
+(void)trackRevenue:(double)price;



/**
 * Tell Singular that a user generated some revenue.
 *
 * @param price The price in cents (example: 1.5 means one and a half cents)
 * @param currency The currency to measure the revenue. While the currency is an NSString it should belong to the kSingularCurrency* constants 
 * available in SingularCurrency.h
 */
+(void)trackRevenue:(double)price withCurrency:(NSString *)currency;



/**
 * Tell Singular that a user generated some revenue.
 * Uses the default currency as the currency for this event
 *
 * @param price The price in cents (example: 1.5 means one and a half cents)
 * @param transaction The StoreKit transaction item from the purchase.
 */
+(void)trackRevenue:(double)price withStoreKitTransaction:(SKPaymentTransaction *)transaction;


/**
 * Tell Singular that a user generated some revenue.
 *
 * @param price The price in cents (example: 1.5 means one and a half cents)
 * @param currency The currency to measure the revenue. While the currency is an NSString it should belong to the kSingularCurrency* constants
 * available in SingularCurrency.h
 * @param transaction The StoreKit transaction item from the purchase. 
 */
+(void)trackRevenue:(double)price withCurrency:(NSString *)currency withStoreKitTransaction:(SKPaymentTransaction *)transaction;



/**
 * Tell Singular that a user generated some revenue.
 * Uses the default currency as the currency for this event
 *
 * @param productId An optional identifier differentiating between the different products available
 * @param quantity How many units were bought
 * @param price The price in cents (example: 1.5 means one and a half cents)
 */
+(void)trackRevenue:(double)price withProductId:(NSString *)productId withQuantity:(int)quantity;


/**
 * Tell Singular that a user generated some revenue.
 *
 * @param productId An optional identifier differentiating between the different products available
 * @param quantity How many units were bought
 * @param price The price in cents (example: 1.5 means one and a half cents)
 * @param currency The currency to measure the revenue in. While the currency is an NSString it should belong to the kSingularCurrency* constants
 * available in SingularCurrency.h
 */
+(void)trackRevenue:(double)price withProductId:(NSString *)productId withQuantity:(int)quantity currency:(NSString *)currency;


/**
 * Tell Singular that a user generated some revenue.
 *
 * @param productId An optional identifier differentiating between the different products available
 * @param quantity How many units were bought
 * @param price The price in cents (example: 1.5 means one and a half cents)
 * @param currency The currency to measure the revenue in. While the currency is an NSString it should belong to the kSingularCurrency* constants
 * available in SingularCurrency.h
 * @param transaction The StoreKit transaction item from the purchase.
 */
+(void)trackRevenue:(double)price withProductId:(NSString *)productId withQuantity:(int)quantity currency:(NSString *)currency storeKitTransaction:(SKPaymentTransaction *)transaction;

/**
 * Tracks app launches resulting from deep link. This method should be called from UIApplicationDelegate's application:openUrl and passed the same arguments.
 * @param url the URL used to open the app
 * @param sourceApplication which application opened the link
 * @param annotation
 */
+(void)trackOpenUrl:(NSURL*)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 * Sets the Facebook id of the user
 * @param id a unique identifier received from Facebook
 */
+(void)setFacebookId:(NSString *)facebookId;


/**
 * Un-sets a previously set Facebook id
 */
+(void)unsetFacebookId;



/**
 * Sets the Google id of the user
 * @param id a unique identifier received from Google
 */
+(void)setGoogleId:(NSString *)googleId;



/**
 * Un-sets a previously set Google id
 */
+(void)unsetGoogleId;


/**
 * Sets the Twitter id of the user
 * @param id a unique identifier received from Twitter
 */
+(void)setTwitterId:(NSString *)twitterId;


/**
 * Un-sets a previously set Twitter id
 */
+(void)unsetTwitterId;


/**
 * Sets a custom identifier for the user
 * @param id a unique identifier
 */
+(void)setCustomUserId:(NSString *)userId;



/**
 * Un-sets a previously set custom id
 */
+(void)unsetCustomUserId;


/**
 * Un-sets all previously set user identifiers (facebook, google, twitter and custom ids)
 */
+(void)unsetAllUserIds;


/**
 * Sets the default currency for future trackRevenue calls. The SDK default is kSingularCurrencyUSD
 * @param currency - The currency to measure the revenue in. While the currency is an NSString it should belong to the kSingularCurrency* constants.
 */
+(void)setDefaultCurrency:(NSString *)currency;

/**
 * Gets the default currency
 */
+(NSString *)defaultCurrency;

/**
 * disables tracking for this device (for example, in case the user opts-out)
 */
+(void)disableDeviceTracking;

/**
 * enables tracking for this device
 */
+(void)enableDeviceTracking;


/**
 * enables sandbox mode for tests against singular servers
 */
+(void)enableSandboxMode;

@end
