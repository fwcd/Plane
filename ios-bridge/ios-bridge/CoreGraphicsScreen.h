//
//  CoreGraphicsScreen.h
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

#ifndef CoreGraphicsScreen_h
#define CoreGraphicsScreen_h

#include "../../shared-cpp/src/plane/core/IScreen.hpp"
#include "../../shared-cpp/src/plane/utils/Color.hpp"
#import "CoreGraphicsUIView.h"
#import <UIKit/UIColor.h>

using plane::IScreen;
using plane::Color;
using plane::FontAttributes;
using plane::IPaintable;
using plane::KeyListener;
using plane::MouseListener;

class CoreGraphicsScreen : public IScreen {
public:
    CoreGraphicsScreen(CoreGraphicsUIView* view);
    
    virtual ~CoreGraphicsScreen();
    
    virtual void repaintSoon();
    
    virtual void setBackground(Color color);
    
    virtual Color getBackground();
    
    virtual void setColor(Color color);
    
    virtual Color getColor();
    
    virtual float getWidth();
    
    virtual float getHeight();
    
    virtual void drawRect(float x, float y, float w, float h);
    
    virtual void fillRect(float x, float y, float w, float h);
    
    virtual void drawOval(float x, float y, float w, float h);
    
    virtual void fillOval(float x, float y, float w, float h);
    
    virtual void drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH);
    
    virtual void drawImageSized(std::string filePath, float x, float y, float w, float h);
    
    virtual void drawString(std::string str, float x, float y, FontAttributes attribs);
    
    virtual float getStringWidth(std::string str, FontAttributes attribs);
    
    virtual float getStringHeight(std::string str, FontAttributes attribs);
    
    virtual void drawLine(float startX, float startY, float endX, float endY);
    
    virtual void addOnTop(std::shared_ptr<IPaintable> paintable);
    
    virtual void addOnBottom(std::shared_ptr<IPaintable> paintable);
    
    virtual void remove(std::shared_ptr<IPaintable> paintable);
    
    virtual void addKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void addMouseListener(std::shared_ptr<MouseListener> mouseListener);
    
    virtual void removeKeyListener(std::shared_ptr<KeyListener> keyListener);
    
    virtual void removeMouseListener(std::shared_ptr<MouseListener> mouseListener);
private:
    CoreGraphicsUIView* view;
    Color currentColor = plane::COLOR_BLACK;
    
    UIColor* toUIColor(Color color);
    
    Color fromUIColor(UIColor* color);
};

#endif /* CoreGraphicsScreen_h */
