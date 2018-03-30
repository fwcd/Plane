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
#include "IContainer.hpp"
#include "ILayout.hpp"
#include "IWidget.hpp"

namespace plane {

enum BoxLayoutMode {
	HORIZONTAL_BOXLAYOUT,
	VERTICAL_BOXLAYOUT
};

class BoxLayout : public ILayout {
public:
	BoxLayout(BoxLayoutMode mode) {
		this->mode = mode;
	}

	virtual ~BoxLayout() {}

	virtual void add(std::shared_ptr<IWidget> widget, IContainer& container) {
		const std::vector<std::shared_ptr<IWidget>>& others = container.getChilds();
		float pad = widget->getPadding();
		float x = pad;
		float y = pad;

		for (std::shared_ptr<IWidget> other : others) {
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
private:
	BoxLayoutMode mode;
};

}

#endif /* SRC_PLANE_GUI_BOXLAYOUT_HPP_ */
