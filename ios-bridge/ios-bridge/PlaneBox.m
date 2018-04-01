//
//  PlaneBox.m
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlaneBox.h"

@implementation PlaneBox

- (id) initAtX:(float)x y:(float)y withWidth:(float)w andHeight:(float)h filled:(bool)filled {
    [self setX:x];
    [self setY:y];
    [self setW:w];
    [self setH:h];
    [self setFilled:filled];
    return self;
}

@end
