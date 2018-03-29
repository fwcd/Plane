/*
 * Label.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_GUI_LABEL_HPP_
#define SRC_GUI_LABEL_HPP_

#include <string>

#include "../math/Vec2.hpp"
#include "../utils/Color.hpp"
#include "BaseWidget.hpp"

namespace plane {

class Label : public BaseWidget {
public:
	Label(std::string text) {
		this->text = text;
	}

	virtual ~Label() {}

	void setSize(float size) {
		attribs.setSize(size);
	}

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
	FontAttributes attribs = FontAttributes();
};

}

#endif /* SRC_GUI_LABEL_HPP_ */
