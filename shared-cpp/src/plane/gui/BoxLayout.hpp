/*
 * BoxLayout.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_BOXLAYOUT_HPP_
#define SRC_PLANE_GUI_BOXLAYOUT_HPP_

#include <algorithm>
#include <memory>
#include <vector>

#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "Container.hpp"
#include "Layout.hpp"
#include "Widget.hpp"

namespace plane {

enum BoxLayoutMode {
	HORIZONTAL_BOXLAYOUT,
	VERTICAL_BOXLAYOUT
};

/**
 * A basic layout manager that arranges widgets
 * along one axis.
 */
class BoxLayout : public Layout {
public:
	BoxLayout(BoxLayoutMode mode) {
		this->mode = mode;
	}

	virtual ~BoxLayout() {}

	virtual void add(std::shared_ptr<Widget> widget, Container& container) {
		const std::vector<std::shared_ptr<Widget>>& others = container.getChilds();
		float pad = widget->getPadding();
		float x = pad;
		float y = pad;

		for (std::shared_ptr<Widget> other : others) {
			Rect2<float> bb = other->getBoundingBox();

			switch (mode) {
			case HORIZONTAL_BOXLAYOUT:
				x = std::max(x, bb.getTopLeft().getX() + bb.getWidth() + other->getPadding());
				break;
			case VERTICAL_BOXLAYOUT:
				y = std::max(y, bb.getTopLeft().getY() + bb.getHeight() + other->getPadding());
				break;
			}
		}

		container.add(widget, Vec2<float>(x, y));
	}

	virtual void relayout(Container& container) {
		float x = 0;
		float y = 0;
		const std::vector<std::shared_ptr<Widget>>& widgets = container.getChilds();
		for (std::shared_ptr<Widget> widget : widgets) {
			float pad = widget->getPadding();
			if (x == 0 && y == 0) {
				x = pad;
				y = pad;
			}

			widget->setPos(Vec2<float>(x, y));

			Rect2<float> bb = widget->getBoundingBox();
			switch (mode) {
			case HORIZONTAL_BOXLAYOUT:
				x += bb.getWidth() + pad;
				break;
			case VERTICAL_BOXLAYOUT:
				y += bb.getWidth() + pad;
				break;
			}
		}
	}
private:
	BoxLayoutMode mode;
};

}

#endif /* SRC_PLANE_GUI_BOXLAYOUT_HPP_ */
