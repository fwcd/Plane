/*
 * BaseWidget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_BASEWIDGET_HPP_
#define SRC_PLANE_GUI_BASEWIDGET_HPP_

#include "GUI.hpp"
#include "IWidget.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"

namespace plane {

class BaseWidget : public IWidget {
public:
	virtual ~BaseWidget() {}

	virtual void setGUI(std::shared_ptr<GUI> ptr) {
		gui = ptr;
	}

	virtual void moveBy(const Vec2<float>& delta) {
		boundingBox.moveBy(delta);
	}

	virtual void setPos(Vec2<float> pos) {
		boundingBox.setTopLeft(pos);
	}

	virtual Vec2<float> getPos() { return boundingBox.getTopLeft(); }

	virtual Rect2<float> getBoundingBox() { return boundingBox; }

	virtual void setPadding(float padding) { this->padding = padding; }

	virtual float getPadding() { return padding; }
protected:
	Rect2<float>& getBBReference() {
		return boundingBox;
	}

	std::shared_ptr<GUI> getGUI() {
		return gui;
	}
private:
	Rect2<float> boundingBox;
	std::shared_ptr<GUI> gui;
	float padding = 10;
};

}

#endif /* SRC_PLANE_GUI_BASEWIDGET_HPP_ */
