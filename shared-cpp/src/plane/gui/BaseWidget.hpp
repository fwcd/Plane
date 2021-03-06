/*
 * BaseWidget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_BASEWIDGET_HPP_
#define SRC_PLANE_GUI_BASEWIDGET_HPP_

#include <memory>

#include "../core/KeyEvent.hpp"
#include "../core/MouseEvent.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Logger.hpp"
#include "GUI.hpp"
#include "Widget.hpp"

namespace plane {

/**
 * A skeletal implementation of Widget that provides basic
 * functionality, including a bounding box and event hooks.
 */
class BaseWidget : public Widget {
public:
	virtual ~BaseWidget() {}

	virtual void setGUI(std::shared_ptr<GUI> ptr) {
		gui = ptr;
		LOG.trace("Received a new GUI, now relayouting...");
		ptr->relayout();
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

	virtual void onMouseClick(MouseEvent event) {}

	virtual void onMouseDrag(MouseEvent event) {}

	virtual void onMouseRelease(MouseEvent event) {}

	virtual void onKeyPress(KeyEvent event) {}

	virtual void onKeyRelease(KeyEvent event) {}
protected:
	/**
	 * Returns a mutable reference to the bounding box
	 * of this widget.
	 *
	 * IF THE BOUNDING BOX IS MUTATED/REASSIGNED, ALWAYS CALL relayout()!!
	 */
	Rect2<float>& getBBReference() {
		return boundingBox;
	}

	std::shared_ptr<GUI> getGUI() {
		return gui;
	}

	/**
	 * Convenience method for relayouting the GUI. Should
	 * always be called when bounding boxes change internally.
	 */
	void relayout() {
		if (gui != nullptr) {
			LOG.trace("Relayouting GUI from widget.");
			gui->relayout();
		} else {
			LOG.trace("Could not relayout GUI directly from widget.");
		}
	}
private:
	Rect2<float> boundingBox;
	std::shared_ptr<GUI> gui;
	float padding = 10;
};

}

#endif /* SRC_PLANE_GUI_BASEWIDGET_HPP_ */
