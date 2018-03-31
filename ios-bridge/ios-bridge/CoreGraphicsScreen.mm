//
//  CoreGraphicsScreen.mm
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreGraphicsScreen.h"
#import "ObjCBox.h"

CoreGraphicsScreen::CoreGraphicsScreen(CoreGraphicsUIView* view) {
    this->view = view;
}

CoreGraphicsScreen::~CoreGraphicsScreen() {
    
}

void CoreGraphicsScreen::repaintSoon() {
    [view drawRect:[view bounds]];
}

UIColor* CoreGraphicsScreen::toUIColor(Color color) {
    CGFloat r = color.getRed() / 255.0;
    CGFloat g = color.getGreen() / 255.0;
    CGFloat b = color.getBlue() / 255.0;
    CGFloat a = color.getAlpha() / 255.0;
    
    return [UIColor colorWithRed:r green:g blue:b alpha:a];
}

Color fromUIColor(UIColor* color) {
    CGFloat r = 0;
    CGFloat g = 0;
    CGFloat b = 0;
    CGFloat a = 0;
    [color getRed:&r green:&g blue:&b alpha:&a];
    
    return Color((int) (r * 255.0), (int) (g * 255.0), (int) (b * 255.0), (int) (a * 255.0));
}

void CoreGraphicsScreen::setBackground(Color color) {
    [view setBackgroundColor:toUIColor(color)];
}

Color CoreGraphicsScreen::getBackground() {
    return fromUIColor([view backgroundColor]);
}

void CoreGraphicsScreen::setColor(Color color) {
    currentColor = color;
}

Color CoreGraphicsScreen::getColor() {
    return currentColor;
}

float CoreGraphicsScreen::getWidth() {
    return [view bounds].size.width;
}

float CoreGraphicsScreen::getHeight() {
    return [view bounds].size.height;
}

void CoreGraphicsScreen::drawRect(float x, float y, float w, float h) {
    // TODO: Potential memory leak?
    ObjCBox* rect = [[ObjCBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:false];
    [[view rectPaintQueue] insertObject:rect atIndex:0];
}

void CoreGraphicsScreen::fillRect(float x, float y, float w, float h) {
    // TODO: Potential memory leak?
    ObjCBox* rect = [[ObjCBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:true];
    [[view rectPaintQueue] insertObject:rect atIndex:0];
}

void CoreGraphicsScreen::drawOval(float x, float y, float w, float h) {
    ObjCBox* oval = [[ObjCBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:false];
    [[view ovalPaintQueue] insertObject:oval atIndex:0];
}

void CoreGraphicsScreen::fillOval(float x, float y, float w, float h) {
    ObjCBox* oval = [[ObjCBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:true];
    [[view ovalPaintQueue] insertObject:oval atIndex:0];
}

void CoreGraphicsScreen::drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH) {
    
}

void CoreGraphicsScreen::drawImageSized(std::string filePath, float x, float y, float w, float h) {
    
}

void CoreGraphicsScreen::drawString(std::string str, float x, float y, FontAttributes attribs) {
    
}

float CoreGraphicsScreen::getStringWidth(std::string str, FontAttributes attribs) {
    
}

float CoreGraphicsScreen::getStringHeight(std::string str, FontAttributes attribs) {
    
}

void CoreGraphicsScreen::drawLine(float startX, float startY, float endX, float endY) {
    
}

void CoreGraphicsScreen::addOnTop(std::shared_ptr<IPaintable> paintable) {
    
}

void CoreGraphicsScreen::addOnBottom(std::shared_ptr<IPaintable> paintable) {
    
}

void CoreGraphicsScreen::remove(std::shared_ptr<IPaintable> paintable) {
    
}

void CoreGraphicsScreen::addKeyListener(std::shared_ptr<KeyListener> keyListener) {
    
}

void CoreGraphicsScreen::addMouseListener(std::shared_ptr<MouseListener> mouseListener) {
    
}

void CoreGraphicsScreen::removeKeyListener(std::shared_ptr<KeyListener> keyListener) {
    
}

void CoreGraphicsScreen::removeMouseListener(std::shared_ptr<MouseListener> mouseListener) {
    
}
