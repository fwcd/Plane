/*
 * IWidget.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_CORE_IWIDGET_HPP_
#define SRC_CORE_IWIDGET_HPP_

#include <memory>

#include "../core/IPaintable.hpp"
#include "../math/Vec2.hpp"
#include "IBoxBounded.hpp"
#include "GUI.hpp"

namespace plane {

class GUI;

class IWidget : public IPaintable, public IBoxBounded {
public:
	virtual ~IWidget() {}

	virtual void setGUI(std::shared_ptr<GUI> ptr) = 0;

	virtual void moveBy(const Vec2<float>& delta) = 0;

	virtual void setPos(Vec2<float> pos) = 0;

	virtual Vec2<float> getPos() = 0;

	virtual float getPadding() = 0;

	virtual void setPadding(float padding) = 0;
};

}

#endif /* SRC_CORE_IWIDGET_HPP_ */
