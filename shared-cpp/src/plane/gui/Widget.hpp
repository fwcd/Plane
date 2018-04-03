/*
 * Widget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_WIDGET_HPP_
#define SRC_PLANE_GUI_WIDGET_HPP_

#include <memory>

#include "../core/Paintable.hpp"
#include "../math/Vec2.hpp"
#include "BoxBounded.hpp"
#include "GUI.hpp"

namespace plane {

class GUI;

/**
 * A paintable, box-bounded item that usually provides some
 * GUI functionality (e.g. a button/a label)
 */
class Widget : public Paintable, public BoxBounded { // Interface
public:
	virtual ~Widget() {}

	virtual void setGUI(std::shared_ptr<GUI> ptr) = 0;

	virtual void moveBy(const Vec2<float>& delta) = 0;

	virtual void setPos(Vec2<float> pos) = 0;

	virtual Vec2<float> getPos() = 0;

	virtual float getPadding() = 0;

	virtual void setPadding(float padding) = 0;

	virtual void onMouseClick(MouseEvent event) = 0;

	virtual void onMouseDrag(MouseEvent event) = 0;

	virtual void onMouseRelease(MouseEvent event) = 0;

	virtual void onKeyPress(KeyEvent event) = 0;

	virtual void onKeyRelease(KeyEvent event) = 0;
};

}

#endif /* SRC_PLANE_GUI_WIDGET_HPP_ */
