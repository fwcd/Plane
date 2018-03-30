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
#include "../utils/Logger.hpp"
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
	/**
	 * Creates a new GUI.
	 *
	 * DO NOT ALLOCATE THIS ON THE STACK BECAUSE THE
	 * THIS POINTER MIGHT GET PASSED AROUND AS
	 * A SHARED_PTR!!!
	 */
	GUI(std::shared_ptr<IScreen> screen) {
		this->screen = screen;
		setLayout(std::shared_ptr<ILayout>(new BoxLayout(HORIZONTAL_BOXLAYOUT)));
		addInputHooks(screen);
	}

	virtual ~GUI() {}

	virtual Rect2<float> getBoundingBox() {
		return bb;
	}

	virtual void setLayout(std::shared_ptr<ILayout> layout) {
		this->layout = layout;
	}

	virtual void relayout() {
		LOG.trace("Now relayouting GUI...");
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
		widget->setGUI(std::shared_ptr<GUI>(this));
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

	void addInputHooks(const std::shared_ptr<IScreen>& screen) {
		std::shared_ptr<MouseListener> mouseListener(new MouseListener());
		mouseListener->setClickHandler([this](MouseEvent e) {
			for (std::shared_ptr<IWidget> child : childs) {
				child->onMouseClick(e);
			}
		});
		mouseListener->setDragHandler([this](MouseEvent e) {
			for (std::shared_ptr<IWidget> child : childs) {
				child->onMouseDrag(e);
			}
		});
		mouseListener->setReleaseHandler([this](MouseEvent e) {
			for (std::shared_ptr<IWidget> child : childs) {
				child->onMouseRelease(e);
			}
		});
		std::shared_ptr<KeyListener> keyListener(new KeyListener());
		keyListener->setPressHandler([this](KeyEvent e) {
			for (std::shared_ptr<IWidget> child : childs) {
				child->onKeyPress(e);
			}
		});
		keyListener->setReleaseHandler([this](KeyEvent e) {
			for (std::shared_ptr<IWidget> child : childs) {
				child->onKeyRelease(e);
			}
		});
		screen->addMouseListener(mouseListener);
		screen->addKeyListener(keyListener);
	}
};

}

#endif /* SRC_PLANE_GUI_GUI_HPP_ */