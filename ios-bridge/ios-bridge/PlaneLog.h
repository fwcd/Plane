//
//  PlaneLog.h
//  ios-bridge
//
//  Created by Fredrik on 03.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneLog_h
#define PlaneLog_h

#import <Foundation/Foundation.h>

void pLogError(NSString* msg);

void pLogWarn(NSString* msg);

void pLogInfo(NSString* msg);

void pLogDebug(NSString* msg);

void pLogTrace(NSString* msg);

void pLogDeepTrace(NSString* msg);

void pLogVeryDeepTrace(NSString* msg);

#endif /* PlaneLog_h */
