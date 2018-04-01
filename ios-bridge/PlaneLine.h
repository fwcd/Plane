//
//  PlaneLine.h
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneLine_h
#define PlaneLine_h

#include <CoreGraphics/CGGeometry.h>

@interface PlaneLine : NSObject

@property(nonatomic) float startX;
@property(nonatomic) float startY;
@property(nonatomic) float endX;
@property(nonatomic) float endY;

// TODO: Colors and stroke attributes

- (id) initFromX:(float)startX y:(float)startY toX:(float)endX y:(float)endY;

- (CGPoint) getStart;

- (CGPoint) getEnd;

@end

#endif /* PlaneLine_h */
