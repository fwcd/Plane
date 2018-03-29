/*
 * Screen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_API_ISCREEN_HPP_
#define SRC_API_ISCREEN_HPP_

#include <memory>
#include <string>

#include "FontAttributes.hpp"

namespace plane {
class Color;
class IPaintable;
class KeyListener;
class MouseListener;
} /* namespace plane */

namespace plane {

class IScreen {
public:
	virtual ~IScreen() {}

	virtual void repaintSoon() = 0;

	virtual void setColor(Color color) = 0;

	virtual Color getColor() = 0;

	virtual float getWidth() = 0;

	virtual float getHeight() = 0;

	virtual void drawRect(float x, float y, float w, float h) = 0;

	virtual void fillRect(float x, float y, float w, float h) = 0;

	virtual void drawOval(float x, float y, float w, float h) = 0;

	virtual void fillOval(float x, float y, float w, float h) = 0;

	virtual void drawString(std::string str, float x, float y, FontAttributes attribs) = 0;

	virtual void drawLine(float startX, float startY, float endX, float endY) = 0;

	virtual void add(std::shared_ptr<IPaintable> paintable) = 0;

	virtual void remove(std::shared_ptr<IPaintable> paintable) = 0;

	virtual void addKeyListener(std::shared_ptr<KeyListener> keyListener) = 0;

	virtual void addMouseListener(std::shared_ptr<MouseListener> mouseListener) = 0;

	virtual void removeKeyListener(std::shared_ptr<KeyListener> keyListener) = 0;

	virtual void removeMouseListener(std::shared_ptr<MouseListener> mouseListener) = 0;
};

}

#endif /* SRC_API_ISCREEN_HPP_ */
