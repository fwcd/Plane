/*
 * BaseWidget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_GUI_BASEWIDGET_HPP_
#define SRC_GUI_BASEWIDGET_HPP_

#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "GUI.hpp"
#include "IWidget.hpp"

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

	virtual Vec2<float> getPos() {
		return boundingBox.getTopLeft();
	}

	virtual void setBoundingBox(Rect2<float> bb) {
		boundingBox = bb;
	}

	virtual Rect2<float> getBoundingBox() {
		return boundingBox;
	}
protected:
	const Rect2<float>& getBBReference() {
		return boundingBox;
	}

	std::shared_ptr<GUI> getGUI() {
		return gui;
	}
private:
	Rect2<float> boundingBox;
	std::shared_ptr<GUI> gui;
};

}

#endif /* SRC_GUI_BASEWIDGET_HPP_ */
