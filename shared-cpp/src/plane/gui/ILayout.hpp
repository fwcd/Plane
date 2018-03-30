/*
 * ILayout.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_ILAYOUT_HPP_
#define SRC_PLANE_GUI_ILAYOUT_HPP_

#include <memory>
#include "IContainer.hpp"

namespace plane {

class IContainer;

class ILayout {
public:
	virtual ~ILayout() {}

	virtual void add(std::shared_ptr<IWidget> widget, IContainer& container) = 0;
};

}

#endif /* SRC_PLANE_GUI_ILAYOUT_HPP_ */
