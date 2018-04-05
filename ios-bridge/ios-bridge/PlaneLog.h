//
//  PlaneLog.h
//  ios-bridge
//
//  Created by Fredrik on 04.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneLog_h
#define PlaneLog_h

#import <Foundation/Foundation.h>

@interface PlaneLog : NSObject

+ (void) error:(NSString*)msg;

+ (void) warn:(NSString*)msg;

+ (void) info:(NSString*)msg;

+ (void) debug:(NSString*)msg;

+ (void) trace:(NSString*)msg;

+ (void) deepTrace:(NSString*)msg;

+ (void) veryDeepTrace:(NSString*)msg;

@end

#endif /* PlaneLog_h */
