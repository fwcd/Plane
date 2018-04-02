//
//  PlaneRenderCallback-protected.h
//  ios-bridge
//
//  Created by Fredrik on 02.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneRenderCallback_protected_h
#define PlaneRenderCallback_protected_h

#import <memory>

#import "PlaneCGScreen.h"
#import "PlaneRenderCallback.h"

@interface PlaneRenderCallback ()

@property(nonatomic) std::shared_ptr<PlaneCGScreen> screen;

- (id) initWithScreen:(std::shared_ptr<PlaneCGScreen>)screen;

@end

#endif /* PlaneRenderCallback_protected_h */
