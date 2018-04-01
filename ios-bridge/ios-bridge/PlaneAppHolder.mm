//
//  PlaneAppHolder.mm
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlaneAppHolder.h"
#import "PlaneAppHolder_protected.h"

using plane::PlaneApp;

@implementation PlaneAppHolder

- (id) initWithNewApp {
    [self setApp:PlaneApp()];
    return self;
}

@end
