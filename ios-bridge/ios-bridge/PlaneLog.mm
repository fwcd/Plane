//
//  PlaneLog.mm
//  ios-bridge
//
//  Created by Fredrik on 03.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import "PlaneLog.h"
#import "../../shared-cpp/src/plane/utils/Logger.hpp"

#import <string>

const plane::Logger planeLogger = plane::Logger();

// TODO: Fix Linker error with this logger

const char* toCStr(NSString* msg) {
	return [msg cStringUsingEncoding:NSUTF8StringEncoding];
}

void pLogError(NSString* msg) {
	planeLogger.error(toCStr(msg));
}

void pLogWarn(NSString* msg) {
	planeLogger.warn(toCStr(msg));
}

void pLogInfo(NSString* msg) {
	planeLogger.info(toCStr(msg));
}

void pLogDebug(NSString* msg) {
	planeLogger.debug(toCStr(msg));
}

void pLogTrace(NSString* msg) {
	planeLogger.trace(toCStr(msg));
}

void pLogDeepTrace(NSString* msg) {
	planeLogger.deepTrace(toCStr(msg));
}

void pLogVeryDeepTrace(NSString* msg) {
	planeLogger.veryDeepTrace(toCStr(msg));
}
