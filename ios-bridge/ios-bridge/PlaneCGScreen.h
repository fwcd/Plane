//
//  PlaneCGScreen.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef PlaneCGScreen_h
#define PlaneCGScreen_h

#import "../../shared-cpp/src/plane/core/IScreen.hpp"
#import "../../shared-cpp/src/plane/utils/Color.hpp"

#import <UIKit/UIKit.h>
#import "ios_bridge-Swift.h"

using plane::IScreen;
using plane::Color;
using plane::FontAttributes;
using plane::IPaintable;
using plane::KeyListener;
using plane::MouseListener;
using plane::Fill;
using plane::Stroke;

class PlaneCGScreen : public IScreen {
public:
    PlaneCGScreen(PlaneCGView* view);
    
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
    
    virtual void addOnTop(std::shared_ptr<IPaintable> paintable);
    
    virtual void addOnBottom(std::shared_ptr<IPaintable> paintable);
    
    virtual void remove(std::shared_ptr<IPaintable> paintable);
    
    virtual void addKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void addMouseListener(std::shared_ptr<MouseListener> mouseListener);
    
    virtual void removeKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void removeMouseListener(std::shared_ptr<MouseListener> mouseListener);
private:
    PlaneCGView* view;
    
    UIColor* toUIColor(Color color);
    
    Color fromUIColor(UIColor* color);
};

#endif /* PlaneCGScreen_h */
