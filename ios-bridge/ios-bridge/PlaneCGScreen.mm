//
//  PlaneCGScreen.mm
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlaneCGScreen.h"
#import "PlaneBox.h"

PlaneCGScreen::PlaneCGScreen(PlaneCGView* view) {
    this->view = view;
}

PlaneCGScreen::~PlaneCGScreen() {
    
}

void PlaneCGScreen::repaintSoon() {
    [view repaint];
}

UIColor* PlaneCGScreen::toUIColor(Color color) {
    CGFloat r = color.getRed() / 255.0;
    CGFloat g = color.getGreen() / 255.0;
    CGFloat b = color.getBlue() / 255.0;
    CGFloat a = color.getAlpha() / 255.0;
    
    return [UIColor colorWithRed:r green:g blue:b alpha:a];
}

Color PlaneCGScreen::fromUIColor(UIColor* color) {
    CGFloat r = 0;
    CGFloat g = 0;
    CGFloat b = 0;
    CGFloat a = 0;
    [color getRed:&r green:&g blue:&b alpha:&a];
    
    return Color((int) (r * 255.0), (int) (g * 255.0), (int) (b * 255.0), (int) (a * 255.0));
}

void PlaneCGScreen::setBackground(Color color) {
    [view setBackgroundColor:toUIColor(color)];
}

Color PlaneCGScreen::getBackground() {
    return fromUIColor([view backgroundColor]);
}

float PlaneCGScreen::getWidth() {
    return [view bounds].size.width;
}

float PlaneCGScreen::getHeight() {
    return [view bounds].size.height;
}

void PlaneCGScreen::drawRect(float x, float y, float w, float h, Stroke stroke) {
    [view enqueueRect:[[PlaneBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:false]];
}

void PlaneCGScreen::fillRect(float x, float y, float w, float h, Fill fill) {
    [view enqueueRect:[[PlaneBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:true]];
}

void PlaneCGScreen::drawOval(float x, float y, float w, float h, Stroke stroke) {
    [view enqueueOval:[[PlaneBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:false]];
}

void PlaneCGScreen::fillOval(float x, float y, float w, float h, Fill fill) {
    [view enqueueOval:[[PlaneBox alloc] initAtX:x y:y withWidth:w andHeight:h filled:true]];
}

void PlaneCGScreen::drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH) {
    // TODO
}

void PlaneCGScreen::drawImageSized(std::string filePath, float x, float y, float w, float h) {
    // TODO
}

void PlaneCGScreen::drawString(std::string str, float x, float y, FontAttributes attribs) {
    // TODO
}

float PlaneCGScreen::getStringWidth(std::string str, FontAttributes attribs) {
    throw plane::PlaneException("TODO"); // TODO
}

float PlaneCGScreen::getStringHeight(std::string str, FontAttributes attribs) {
    throw plane::PlaneException("TODO"); // TODO
}

void PlaneCGScreen::drawLine(float startX, float startY, float endX, float endY, Stroke stroke) {
	// TODO
}

void PlaneCGScreen::addOnTop(std::shared_ptr<IPaintable> paintable) {
    // TODO
}

void PlaneCGScreen::addOnBottom(std::shared_ptr<IPaintable> paintable) {
    // TODO
}

void PlaneCGScreen::remove(std::shared_ptr<IPaintable> paintable) {
    // TODO
}

void PlaneCGScreen::addKeyListener(std::shared_ptr<KeyListener> keyListener) {
    // TODO
}

void PlaneCGScreen::addMouseListener(std::shared_ptr<MouseListener> mouseListener) {
    // TODO
}

void PlaneCGScreen::removeKeyListener(std::shared_ptr<KeyListener> keyListener) {
    // TODO
}

void PlaneCGScreen::removeMouseListener(std::shared_ptr<MouseListener> mouseListener) {
    // TODO
}
