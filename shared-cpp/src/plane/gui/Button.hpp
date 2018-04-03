/*
 * Button.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_BUTTON_HPP_
#define SRC_PLANE_GUI_BUTTON_HPP_

#include <memory>
#include <string>

#include "../core/Screen.hpp"
#include "../core/MouseEvent.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Color.hpp"
#include "BaseWidget.hpp"
#include "Label.hpp"

namespace plane {

/**
 * A clickable widget that displays
 * another widget (usually a Label).
 */
class Button : public BaseWidget {
public:
	Button(std::shared_ptr<Widget> fg) : foreground(fg) {
		float padTwice = getPadding() * 2;
		Rect2<float> fgBB = fg->getBoundingBox();
		getBBReference().setSize(fgBB.getWidth() + padTwice, fgBB.getHeight() + padTwice);
	}

	Button(std::string text, float size, Screen& screen)
			: Button(std::shared_ptr<Widget>(new Label(text, size, COLOR_WHITE, screen))) {}

	virtual ~Button() {}

	void setClickTarget(std::function<void()> clickTarget) {
		this->clickTarget = clickTarget;
	}

	void setBGColor(Color color) {
		background = color;
	}

	virtual void paint(Screen& screen) {
		Rect2<float>& bb = getBBReference();
		const Vec2<float>& tl = bb.getTopLeft();
		float pad = getPadding();
		
		Fill fill(background);
		screen.fillRect(tl.getX(), tl.getY(), bb.getWidth(), bb.getHeight(), fill);

		foreground->setPos(tl.add(Vec2<float>(pad, pad)));
		foreground->paint(screen);
	}

	virtual void onMouseClick(MouseEvent e) {
		if (getBBReference().contains(e.getPos())) {
			LOG.deepTrace("Pressing button");
			active = true;
			background = activeBackground;
		}
	}

	virtual void onMouseRelease(MouseEvent e) {
	 	if (active) {
			clickTarget();
			background = inactiveBackground;
			active = false;
		}
	}
private:
	Color inactiveBackground = COLOR_BLACK;
	Color activeBackground = COLOR_GRAY;
	std::shared_ptr<Widget> foreground;
	Color background = inactiveBackground;
	std::function<void()> clickTarget = [] {};
	bool active = false;
};

}

#endif /* SRC_PLANE_GUI_BUTTON_HPP_ */
