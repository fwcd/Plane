//
//  TestAppHolder.mm
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "../../shared-cpp/test/TestApp.hpp"
#import "PlaneAppHolder_protected.h"
#import "TestAppHolder.h"

using plane::TestApp;

@implementation TestAppHolder

// Override
- (id) initWithNewApp {
    [self setApp:TestApp()];
    return self;
}

@end
