/*
 * Label.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_LABEL_HPP_
#define SRC_PLANE_GUI_LABEL_HPP_

#include <iostream>
#include <string>

#include "../core/FontAttributes.hpp"
#include "../core/IScreen.hpp"
#include "../math/Rect2.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Color.hpp"
#include "BaseWidget.hpp"

namespace plane {

class Label : public BaseWidget {
public:
	Label(std::string text, float size, IScreen& screen) {
		this->text = text;
		attribs = FontAttributes(size);
		int w = screen.getStringWidth(text, attribs);
		int h = screen.getStringHeight(text, attribs);
		getBBReference() = Rect2<float>(0, 0, w, h);
	}

	virtual ~Label() {}

	void setColor(Color color) {
		this->color = color;
	}

	virtual void paint(IScreen& screen) {
		const Vec2<float>& pos = getPos();
		screen.setColor(color);
		screen.drawString(text, pos.getX(), pos.getY(), attribs);
	}
private:
	std::string text;
	Color color = COLOR_BLACK;
	FontAttributes attribs;
};

}

#endif /* SRC_PLANE_GUI_LABEL_HPP_ */
