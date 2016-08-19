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

@class UAJSONValueMatcher;

/**
 * Matcher for a JSON payload.
 */
@interface UAJSONMatcher : NSObject

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
 * Factory method to create a JSON matcher.
 *
 * @param valueMatcher Matcher to apply to the value.
 * @return A JSON matcher.
 */
+ (instancetype)matcherWithValueMatcher:(UAJSONValueMatcher *)valueMatcher;

/**
 * Factory method to create a JSON matcher.
 *
 * @param valueMatcher Matcher to apply to the value.
 * @param key Used to path into the object before evaluating the value.
 * @return A JSON matcher.
 */
+ (instancetype)matcherWithValueMatcher:(UAJSONValueMatcher *)valueMatcher key:(NSString *)key;

/**
 * Factory method to create a JSON matcher.
 *
 * @param valueMatcher Matcher to apply to the value.
 * @param key Used to path into the object before evaluating the value.
 * @param scope Used to path into the object before evaluating the value. Key is applied
 * after the scope.
 * @return A JSON matcher.
 */
+ (instancetype)matcherWithValueMatcher:(UAJSONValueMatcher *)valueMatcher key:(NSString *)key scope:(NSArray<NSString *>*)scope;

/**
 * Factory method to create a matcher from a JSON payload.
 *
 * @param json The JSON payload.
 * @return A value matcher, or `nil` if the JSON is invalid.
 */
+ (nullable instancetype)matcherWithJSON:(id)json;

@end

NS_ASSUME_NONNULL_END
