/*
 * Layout.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_LAYOUT_HPP_
#define SRC_PLANE_GUI_LAYOUT_HPP_

#include <memory>
#include "Container.hpp"

namespace plane {

class Container;

/**
 * An object that arranges widgets inside
 * a container (e.g. a GUI).
 */
class Layout { // Interface
public:
	virtual ~Layout() {}

	virtual void add(std::shared_ptr<Widget> widget, Container& container) = 0;

	virtual void relayout(Container& container) = 0;
};

}

#endif /* SRC_PLANE_GUI_LAYOUT_HPP_ */
