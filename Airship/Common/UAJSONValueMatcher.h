/*
 Copyright 2009-2016 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines a JSON value matcher.
 */
@interface UAJSONValueMatcher : NSObject

/**
 * The matcher's JSON payload.
 */
@property(nonatomic, readonly) NSDictionary *payload;

/**
 * Evaluates the object with the matcher.
 *
 * @param object The object to evaluate.
 * @return `YES` if the matcher matches the object, otherwise `NO`.
 */
- (BOOL)evaluateObject:(nullable id)object;

/**
 * Factory method to create a matcher for a number that is
 * at least the specified number.
 *
 * @param number The lower bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)number;

/**
 * Factory method to create a matcher for a number between
 * the lowerNumber and higherNumber.
 *
 * @param lowerNumber The lower bound for the number.
 * @param higherNumber The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)lowerNumber atMost:(NSNumber *)higherNumber;

/**
 * Factory method to create a matcher for a number that is
 * at most the specified number.
 *
 * @param number The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtMost:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact number.
 *
 * @param number The expected number value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberEquals:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact string.
 *
 * @param string The expected string value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereStringEquals:(NSString *)string;

/**
 * Factory method to create a matcher for the presence of a value.
 *
 * @param present `YES` if the value must be present, otherwise `NO`.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereValueIsPresent:(BOOL)present;

/**
 * Factory method to create a matcher from a JSON payload.
 *
 * @param json The JSON payload.
 * @return A value matcher, or `nil` if the JSON is invalid.
 */
+ (nullable instancetype)matcherWithJSON:(id)json;

@end

NS_ASSUME_NONNULL_END
