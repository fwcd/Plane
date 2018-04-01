/*
 * Screen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_CORE_ISCREEN_HPP_
#define SRC_PLANE_CORE_ISCREEN_HPP_

#include <memory>
#include <string>

#include "FontAttributes.hpp"
#include "KeyListener.hpp"
#include "MouseListener.hpp"
#include "IPaintable.hpp"
#include "../utils/Color.hpp"
#include "Fill.hpp"
#include "Stroke.hpp"

namespace plane {

/**
 * The entire graphics interface that needs to be adopted platform-specifically.
 * It contains methods for rendering and event handling.
 */
class IScreen {
public:
	virtual ~IScreen() {}

	virtual void repaintSoon() = 0;

	virtual void setBackground(Color color) = 0;

	virtual Color getBackground() = 0;

	virtual float getWidth() = 0;

	virtual float getHeight() = 0;

	virtual void drawRect(float x, float y, float w, float h, Stroke stroke) = 0;

	virtual void fillRect(float x, float y, float w, float h, Fill fill) = 0;

	virtual void drawOval(float x, float y, float w, float h, Stroke stroke) = 0;

	virtual void fillOval(float x, float y, float w, float h, Fill fill) = 0;

	virtual void drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH) = 0;

	virtual void drawImageSized(std::string filePath, float x, float y, float w, float h) = 0;

	virtual void drawString(std::string str, float x, float y, FontAttributes attribs) = 0;

	virtual float getStringWidth(std::string str, FontAttributes attribs) = 0;

	virtual float getStringHeight(std::string str, FontAttributes attribs) = 0;

	virtual void drawLine(float startX, float startY, float endX, float endY, Stroke stroke) = 0;

	virtual void addOnTop(std::shared_ptr<IPaintable> paintable) = 0;

	virtual void addOnBottom(std::shared_ptr<IPaintable> paintable) = 0;

	virtual void remove(std::shared_ptr<IPaintable> paintable) = 0;

	virtual void addKeyListener(std::shared_ptr<KeyListener> keyListener) = 0;

	virtual void addMouseListener(std::shared_ptr<MouseListener> mouseListener) = 0;

	virtual void removeKeyListener(std::shared_ptr<KeyListener> keyListener) = 0;

	virtual void removeMouseListener(std::shared_ptr<MouseListener> mouseListener) = 0;
};

}

#endif /* SRC_PLANE_CORE_ISCREEN_HPP_ */
