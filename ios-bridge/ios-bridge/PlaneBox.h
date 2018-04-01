//
//  PlaneBox.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneBox_h
#define PlaneBox_h

#import <Foundation/Foundation.h>

@interface PlaneBox : NSObject

@property(nonatomic) float x;
@property(nonatomic) float y;
@property(nonatomic) float w;
@property(nonatomic) float h;
@property(nonatomic) bool filled;

// TODO: Colors

- (id) initAtX:(float)x y:(float)y withWidth:(float)w andHeight:(float)h filled:(bool)filled;

@end

#endif /* PlaneBox_h */
