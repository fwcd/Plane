//
//  PlaneAppHolder_protected.h
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneAppHolder_protected_h
#define PlaneAppHolder_protected_h

#import "PlaneAppHolder.h"
#import "../../shared-cpp/src/plane/core/PlaneApp.hpp"

using plane::PlaneApp;

@interface PlaneAppHolder ()

@property(nonatomic) PlaneApp app;

@end

#endif /* PlaneAppHolder_protected_h */
