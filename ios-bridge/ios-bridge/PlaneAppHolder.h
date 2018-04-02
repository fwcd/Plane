//
//  PlaneAppHolder.h
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneAppHolder_h
#define PlaneAppHolder_h

#import <Foundation/Foundation.h>
#import <UIKit/UITouch.h>

/** 
 * The pure Objective-C/Swift interface for
 * accessing the application. A wrapper class
 * around PlaneApp.
 */
@interface PlaneAppHolder : NSObject

- (id) initWithView:(id)view;

- (bool) showsStatusBar;

- (void) startApp;

- (void) onTouchDown:(NSSet<UITouch*>*)touches;

- (void) onTouchMove:(NSSet<UITouch*>*)touches;

- (void) onTouchUp:(NSSet<UITouch*>*)touches;

@end

#endif /* PlaneAppHolder_h */
