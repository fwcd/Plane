/*
 * GUI.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_GUI_HPP_
#define SRC_PLANE_GUI_GUI_HPP_

#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#include "../core/IScreen.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/PlaneException.hpp"
#include "BoxLayout.hpp"
#include "IContainer.hpp"
#include "IWidget.hpp"

namespace plane {

/**
 * An abstraction that specifically manages widgets
 * on top of the IScreen.
 */
class GUI : public IPaintable, public IContainer {
public:
	GUI(std::shared_ptr<IScreen> screen) {
		this->screen = screen;
		setLayout(std::shared_ptr<ILayout>(new BoxLayout(HORIZONTAL_BOXLAYOUT)));
	}

	virtual ~GUI() {}

	virtual Rect2<float> getBoundingBox() {
		return bb;
	}

	virtual void setLayout(std::shared_ptr<ILayout> layout) {
		this->layout = layout;
	}

	virtual void relayout() {
		layout->relayout(*this);
		screen->repaintSoon();
	}

	virtual void add(std::shared_ptr<IWidget> widget) {
		if (layout == nullptr) {
			throw PlaneException("Can't add a widget to a GUI without a layout.");
		}

		layout->add(widget, *this);
	}

	virtual void add(std::shared_ptr<IWidget> widget, Vec2<float> pos) {
		widget->setPos(pos);
		childs.push_back(widget);
	}

	virtual void remove(std::shared_ptr<IWidget> widget) {
		childs.erase(std::remove(childs.begin(), childs.end(), widget), childs.end());
	}

	virtual const std::vector<std::shared_ptr<IWidget>>& getChilds() {
		return childs;
	}

	virtual void paint(IScreen& screen) {
		bb = Rect2<float>(0, 0, screen.getWidth(), screen.getHeight());

		for (std::shared_ptr<IWidget> child : childs) {
			child->paint(screen);
		}
	}
private:
	std::shared_ptr<IScreen> screen;
	Rect2<float> bb = Rect2<float>();
	std::vector<std::shared_ptr<IWidget>> childs = std::vector<std::shared_ptr<IWidget>>();
	std::shared_ptr<ILayout> layout = std::shared_ptr<ILayout>();
};

}

#endif /* SRC_PLANE_GUI_GUI_HPP_ */
