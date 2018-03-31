//
//  CoreGraphicsUIView.m
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreGraphicsUIView.h"
#import <UIKit/UIGraphics.h>

@implementation CoreGraphicsUIView

- (void) drawRect:(CGRect)rect {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    
}

@end
