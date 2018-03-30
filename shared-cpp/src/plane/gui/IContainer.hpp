/*
 * IContainer.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_ICONTAINER_HPP_
#define SRC_PLANE_GUI_ICONTAINER_HPP_

#include <memory>
#include <vector>

#include "../math/Vec2.hpp"
#include "IBoxBounded.hpp"

namespace plane {
class ILayout;
class IWidget;
} /* namespace plane */

namespace plane {

/**
 * A box-bounded element that contains widgets.
 */
class IContainer : public IBoxBounded {
public:
	virtual ~IContainer() {}

	virtual void setLayout(std::shared_ptr<ILayout> layout) = 0;

	/**
	 * Re-applies the layout to this component. Usually delegates
	 * to the provided layout (thus shouldn't be called from an ILayout
	 * implementor).
	 */
	virtual void relayout() = 0;

	/**
	 * Adds a widget. Usually delegates to the provided layout
	 * (thus shouldn't be called from an ILayout implementor).
	 */
	virtual void add(std::shared_ptr<IWidget> widget) = 0;

	virtual void add(std::shared_ptr<IWidget> widget, Vec2<float> pos) = 0;

	virtual void remove(std::shared_ptr<IWidget> widget) = 0;

	virtual const std::vector<std::shared_ptr<IWidget>>& getChilds() = 0;
};

}

#endif /* SRC_PLANE_GUI_ICONTAINER_HPP_ */
