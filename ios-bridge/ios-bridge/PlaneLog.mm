//
//  PlaneLog.mm
//  ios-bridge
//
//  Created by Fredrik on 04.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PlaneLog.h"
#import "../../shared-cpp/src/plane/utils/Logger.hpp"

const plane::Logger logger = plane::Logger();

const char* cStrOf(NSString* str) {
	return [str cStringUsingEncoding:NSUTF8StringEncoding];
}

@implementation PlaneLog

+ (void) error:(NSString*)msg {
	logger.error(cStrOf(msg));
}

+ (void) warn:(NSString*)msg {
	logger.warn(cStrOf(msg));
}

+ (void) info:(NSString*)msg {
	logger.info(cStrOf(msg));
}

+ (void) debug:(NSString*)msg {
	logger.debug(cStrOf(msg));
}

+ (void) trace:(NSString*)msg {
	logger.trace(cStrOf(msg));
}

+ (void) deepTrace:(NSString*)msg {
	logger.deepTrace(cStrOf(msg));
}

+ (void) veryDeepTrace:(NSString*)msg {
	logger.veryDeepTrace(cStrOf(msg));
}

@end
