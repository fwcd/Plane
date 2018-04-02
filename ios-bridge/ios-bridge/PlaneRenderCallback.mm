//
//  PlaneRenderCallback.mm
//  ios-bridge
//
//  Created by Fredrik on 02.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PlaneRenderCallback.h"
#import "PlaneRenderCallback-protected.h"

@implementation PlaneRenderCallback

- (id) initWithScreen:(std::shared_ptr<PlaneCGScreen>)screen {
	[self setScreen:screen];
	return self;
}

- (void) onRender {
	[self screen]->onRender();
}

@end
