/*
 * Container.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_CONTAINER_HPP_
#define SRC_PLANE_GUI_CONTAINER_HPP_

#include <memory>
#include <vector>

#include "../math/Vec2.hpp"
#include "BoxBounded.hpp"

namespace plane {

class Layout;
class Widget;

/**
 * A box-bounded element that contains widgets.
 */
class Container : public BoxBounded { // Interface
public:
	virtual ~Container() {}

	virtual void setLayout(std::shared_ptr<Layout> layout) = 0;

	/**
	 * Re-applies the layout to this component. Usually delegates
	 * to the provided layout (thus shouldn't be called from an Layout
	 * implementor).
	 */
	virtual void relayout() = 0;

	/**
	 * Adds a widget. Usually delegates to the provided layout
	 * (thus shouldn't be called from an Layout implementor).
	 */
	virtual void add(std::shared_ptr<Widget> widget) = 0;

	virtual void add(std::shared_ptr<Widget> widget, Vec2<float> pos) = 0;

	virtual void remove(std::shared_ptr<Widget> widget) = 0;

	virtual const std::vector<std::shared_ptr<Widget>>& getChilds() = 0;
};

}

#endif /* SRC_PLANE_GUI_CONTAINER_HPP_ */
