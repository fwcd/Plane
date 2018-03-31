//
//  CoreGraphicsUIView.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef CoreGraphicsUIView_h
#define CoreGraphicsUIView_h

#import <UIKit/UIView.h>

@interface CoreGraphicsUIView : UIView

@property(nonatomic) NSMutableArray* rectPaintQueue;
@property(nonatomic) NSMutableArray* ovalPaintQueue;
// TODO: More paint queues

// Override
- (void) drawRect:(CGRect)rect;

@end

#endif /* CoreGraphicsUIView_h */
