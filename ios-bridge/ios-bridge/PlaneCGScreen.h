//
//  PlaneCGScreen.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneCGScreen_h
#define PlaneCGScreen_h

#import "../../shared-cpp/src/plane/core/Screen.hpp"
#import "../../shared-cpp/src/plane/utils/Color.hpp"

#import <vector>

#import <UIKit/UIKit.h>
#import "ios_bridge-Swift.h"

using plane::Screen;
using plane::Color;
using plane::FontAttributes;
using plane::Paintable;
using plane::KeyListener;
using plane::MouseListener;
using plane::MouseEvent;
using plane::Fill;
using plane::Stroke;

/**
 * The C++ screen implementation that allows Plane-based
 * applications to interface with UIKit and CoreGraphics.
 */
class PlaneCGScreen : public Screen {
public:
    PlaneCGScreen(PlaneCGView* view);
    
    PlaneCGScreen(const PlaneCGScreen& screen);
    
    virtual ~PlaneCGScreen();
    
    virtual void repaintSoon();
    
    virtual void setBackground(Color color);
    
    virtual Color getBackground();
    
    virtual float getWidth();
    
    virtual float getHeight();
    
    virtual void drawRect(float x, float y, float w, float h, Stroke stroke);
    
    virtual void fillRect(float x, float y, float w, float h, Fill fill);
    
    virtual void drawOval(float x, float y, float w, float h, Stroke stroke);
    
    virtual void fillOval(float x, float y, float w, float h, Fill fill);
    
    virtual void drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH);
    
    virtual void drawImageSized(std::string filePath, float x, float y, float w, float h);
    
    virtual void drawString(std::string str, float x, float y, FontAttributes attribs);
    
    virtual float getStringWidth(std::string str, FontAttributes attribs);
    
    virtual float getStringHeight(std::string str, FontAttributes attribs);
    
    virtual void drawLine(float startX, float startY, float endX, float endY, Stroke stroke);
    
    virtual void addOnTop(std::shared_ptr<Paintable> paintable);
    
    virtual void addOnBottom(std::shared_ptr<Paintable> paintable);
    
    virtual void remove(std::shared_ptr<Paintable> paintable);
    
    virtual void addKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void addMouseListener(std::shared_ptr<MouseListener> mouseListener);
    
    virtual void removeKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void removeMouseListener(std::shared_ptr<MouseListener> mouseListener);
    
    virtual void onRender();
    
    virtual void onTouchDown(MouseEvent event);
    
    virtual void onTouchMove(MouseEvent event);
    
    virtual void onTouchUp(MouseEvent event);
private:
    PlaneCGView* view;
    std::vector<std::shared_ptr<Paintable>> paintables;
    std::vector<std::shared_ptr<MouseListener>> mouseListeners;
    std::vector<std::shared_ptr<KeyListener>> keyListeners;
    
    UIColor* toUIColor(Color color);
    
    Color fromUIColor(UIColor* color);
    
    NSString* toNSString(std::string str);
    
    UIFont* toUIFont(FontAttributes attribs);
};

#endif /* PlaneCGScreen_h */
