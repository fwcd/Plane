//
//  PlaneLine.m
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PlaneLine.h"

@implementation PlaneLine

- (id) initFromX:(float)startX y:(float)startY toX:(float)endX y:(float)endY {
	[self setStartX:startX];
	[self setStartY:startY];
	[self setEndX:endX];
	[self setEndY:endY];
	return self;
}

- (CGPoint) getStart {
	return CGPointMake([self startX], [self startY]);
}

- (CGPoint) getEnd {
	return CGPointMake([self endX], [self endY]);
}

@end
