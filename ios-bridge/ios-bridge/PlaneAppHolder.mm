//
//  PlaneAppHolder.mm
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import "ios_bridge-Swift.h"

#import "APP-INFO.h"
#import APP_CLASS_HEADER

#import "PlaneAppHolder.h"
#import "PlaneCGScreen.h"
#import "PlaneRenderCallback.h"
#import "PlaneRenderCallback-protected.h"

#import <vector>
#import "../../shared-cpp/src/plane/math/Vec2.hpp"
#import "../../shared-cpp/src/plane/core/MouseEvent.hpp"

using plane::PlaneApp;
using plane::Vec2;
using plane::MouseEvent;

/**
 * The bridge extension that holds the application C++ object
 * that is inaccessible to Swift/ObjC code.
 */
@interface PlaneAppHolder ()

@property(nonatomic) PlaneCGView* view; // Swift
@property(nonatomic) std::shared_ptr<PlaneCGScreen> screen; // ObjC++
@property(nonatomic) APP_CLASS_NAME app; // C++

@end

/**
 * The app holder implementation that connects the code.
 */
@implementation PlaneAppHolder

- (id) initWithView:(id)view {
	[self setApp:APP_CLASS_NAME()];
	[self setView:view];
	[self setScreen:std::shared_ptr<PlaneCGScreen>(new PlaneCGScreen((PlaneCGView*) view))];
    return self;
}

- (bool) showsStatusBar {
	return [self app].doesShowMobileStatusBar();
}

- (void) startApp {
	[[self view] injectPaintableRenderer:[[PlaneRenderCallback alloc] initWithScreen:[self screen]]];
	[self app].initialize([self screen]);
}

- (Vec2<float>) toVec:(CGPoint)point {
	return Vec2<float>((float) point.x, (float) point.y);
}

- (MouseEvent) toEvent:(NSSet<UITouch*>*)touches {
	std::vector<Vec2<float>> lastPositions;
	std::vector<Vec2<float>> positions;
	
	for (UITouch* touch in touches) {
		CGPoint lastPoint = [touch previousLocationInView:[self view]];
		CGPoint point = [touch locationInView:[self view]];
		lastPositions.push_back([self toVec:lastPoint]);
		positions.push_back([self toVec:point]);
	}
	
	return MouseEvent(lastPositions, positions);
}

- (void) onTouchDown:(NSSet<UITouch*>*)touches {
	[self screen]->onTouchDown([self toEvent:touches]);
}

- (void) onTouchMove:(NSSet<UITouch*>*)touches {
	[self screen]->onTouchMove([self toEvent:touches]);
}

- (void) onTouchUp:(NSSet<UITouch*>*)touches {
	[self screen]->onTouchUp([self toEvent:touches]);
}

@end
