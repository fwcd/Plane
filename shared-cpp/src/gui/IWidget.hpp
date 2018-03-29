/*
 * IWidget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_CORE_IWIDGET_HPP_
#define SRC_CORE_IWIDGET_HPP_

#include <memory>

#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "GUI.hpp"

namespace plane {

class IWidget : public IPaintable {
public:
	virtual ~IWidget() {}

	virtual void setGUI(std::shared_ptr<GUI> ptr) = 0;

	virtual void moveBy(const Vec2<float>& delta) = 0;

	virtual void setPos(Vec2<float> pos) = 0;

	virtual Vec2<float> getPos() = 0;

	virtual void setBoundingBox(Rect2<float> bb) = 0;

	virtual Rect2<float> getBoundingBox() = 0;
};

}

#endif /* SRC_CORE_IWIDGET_HPP_ */
