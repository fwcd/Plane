//
//  ObjCBox.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef ObjCBox_h
#define ObjCBox_h

@interface ObjCBox : NSObject

@property(nonatomic) float x;
@property(nonatomic) float y;
@property(nonatomic) float w;
@property(nonatomic) float h;
@property(nonatomic) bool filled;

- (id) initAtX:(float)x x:(float)y withWidth:(float)w andHeight:(float)h filled:(bool)filled;

@end

#endif /* ObjCBox_h */
