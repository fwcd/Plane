/*
 * Button.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_BUTTON_HPP_
#define SRC_PLANE_GUI_BUTTON_HPP_

#include <memory>
#include <string>

#include "../core/IScreen.hpp"
#include "../core/MouseEvent.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Color.hpp"
#include "BaseWidget.hpp"
#include "Label.hpp"

namespace plane {

class Button : public BaseWidget {
public:
	Button(std::shared_ptr<IWidget> fg) : foreground(fg) {
		float padTwice = getPadding() * 2;
		Rect2<float> fgBB = fg->getBoundingBox();
		getBBReference().setSize(fgBB.getWidth() + padTwice, fgBB.getHeight() + padTwice);
	}

	Button(std::string text, float size, IScreen& screen)
			: Button(std::shared_ptr<IWidget>(new Label(text, size, screen))) {}

	virtual ~Button() {}

	void setBGColor(Color color) {
		background = color;
	}

	virtual void paint(IScreen& screen) {
		Rect2<float>& bb = getBBReference();
		const Vec2<float>& tl = bb.getTopLeft();
		float pad = getPadding();

		screen.setColor(background);
		screen.fillRect(tl.getX(), tl.getY(), bb.getWidth(), bb.getHeight());

		foreground->setPos(tl.add(Vec2<float>(pad, pad)));
		foreground->paint(screen);
	}

	virtual void onMouseClick(MouseEvent e) {
		if (getBBReference().contains(e.getPos())) {
			active = true;
			background = activeBackground;
		}
	}

	virtual void onMouseRelease(MouseEvent e) {
		active = false;
		background = inactiveBackground;
	}
private:
	Color inactiveBackground = COLOR_BLACK;
	Color activeBackground = COLOR_TRANSLUCENT_BLACK;
	std::shared_ptr<IWidget> foreground;
	Color background = COLOR_BLACK;
	bool active = false;
};

}

#endif /* SRC_PLANE_GUI_BUTTON_HPP_ */
