/*
 * Screen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_API_ISCREEN_HPP_
#define SRC_API_ISCREEN_HPP_

#include <string>

#include "FontAttributes.hpp"
#include "KeyListener.hpp"
#include "MouseListener.hpp"

namespace plane {

class IScreen {
public:
	virtual ~IScreen() {}

	virtual void repaintSoon() = 0;

	virtual void drawRect(float x, float y, float w, float h) = 0;

	virtual void fillRect(float x, float y, float w, float h) = 0;

	virtual void drawOval(float x, float y, float w, float h) = 0;

	virtual void fillOval(float x, float y, float w, float h) = 0;

	virtual void drawString(std::string str, float x, float y, FontAttributes attribs) = 0;

	virtual void drawLine(float startX, float startY, float endX, float endY) = 0;

	virtual void addKeyListener(KeyListener keyListener) = 0;

	virtual void addMouseListener(MouseListener mouseListener) = 0;

	virtual void removeKeyListener(KeyListener keyListener) = 0;

	virtual void removeMouseListener(MouseListener mouseListener) = 0;
};

}

#endif /* SRC_API_ISCREEN_HPP_ */
