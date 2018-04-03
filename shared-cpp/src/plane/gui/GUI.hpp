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

#include "../core/Screen.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Logger.hpp"
#include "../utils/PlaneException.hpp"
#include "BoxLayout.hpp"
#include "Container.hpp"
#include "Widget.hpp"

namespace plane {

/**
 * A top-level container that manages widgets
 * on a Screen. Serves as the base to the Widget API.
 */
class GUI : public Paintable, public Container {
public:
	/**
	 * Creates a new GUI.
	 *
	 * DO NOT ALLOCATE THIS ON THE STACK BECAUSE THE
	 * THIS POINTER MIGHT GET PASSED AROUND AS
	 * A SHARED_PTR!!!
	 */
	GUI(std::shared_ptr<Screen> screen) {
		this->screen = screen;
		setLayout(std::shared_ptr<Layout>(new BoxLayout(HORIZONTAL_BOXLAYOUT)));
		addInputHooks(screen);
	}

	virtual ~GUI() {}

	virtual Rect2<float> getBoundingBox() {
		return bb;
	}

	virtual void setLayout(std::shared_ptr<Layout> layout) {
		this->layout = layout;
	}

	virtual void relayout() {
		LOG.trace("Now relayouting GUI...");
		layout->relayout(*this);
		screen->repaintSoon();
	}

	virtual void add(std::shared_ptr<Widget> widget) {
		if (layout == nullptr) {
			throw PlaneException("Can't add a widget to a GUI without a layout.");
		}

		layout->add(widget, *this);
	}

	virtual void add(std::shared_ptr<Widget> widget, Vec2<float> pos) {
		widget->setPos(pos);
		widget->setGUI(std::shared_ptr<GUI>(this));
		childs.push_back(widget);
	}

	virtual void remove(std::shared_ptr<Widget> widget) {
		childs.erase(std::remove(childs.begin(), childs.end(), widget), childs.end());
	}

	virtual const std::vector<std::shared_ptr<Widget>>& getChilds() {
		return childs;
	}

	virtual void paint(Screen& screen) {
		bb = Rect2<float>(0, 0, screen.getWidth(), screen.getHeight());

		for (std::shared_ptr<Widget> child : childs) {
			child->paint(screen);
		}
	}
private:
	std::shared_ptr<Screen> screen;
	Rect2<float> bb = Rect2<float>();
	std::vector<std::shared_ptr<Widget>> childs = std::vector<std::shared_ptr<Widget>>();
	std::shared_ptr<Layout> layout = std::shared_ptr<Layout>();

	void addInputHooks(const std::shared_ptr<Screen>& screen) {
		std::shared_ptr<MouseListener> mouseListener(new MouseListener());
		mouseListener->setClickHandler([this](MouseEvent e) {
			for (std::shared_ptr<Widget> child : childs) {
				child->onMouseClick(e);
			}
		});
		mouseListener->setDragHandler([this](MouseEvent e) {
			for (std::shared_ptr<Widget> child : childs) {
				child->onMouseDrag(e);
			}
		});
		mouseListener->setReleaseHandler([this](MouseEvent e) {
			for (std::shared_ptr<Widget> child : childs) {
				child->onMouseRelease(e);
			}
		});
		std::shared_ptr<KeyListener> keyListener(new KeyListener());
		keyListener->setPressHandler([this](KeyEvent e) {
			for (std::shared_ptr<Widget> child : childs) {
				child->onKeyPress(e);
			}
		});
		keyListener->setReleaseHandler([this](KeyEvent e) {
			for (std::shared_ptr<Widget> child : childs) {
				child->onKeyRelease(e);
			}
		});
		screen->addMouseListener(mouseListener);
		screen->addKeyListener(keyListener);
	}
};

}

#endif /* SRC_PLANE_GUI_GUI_HPP_ */
