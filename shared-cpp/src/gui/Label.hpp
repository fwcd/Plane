/*
 * Label.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_GUI_LABEL_HPP_
#define SRC_GUI_LABEL_HPP_

#include <string>

#include "../core/IScreen.hpp"
#include "../math/Vec2.hpp"
#include "BaseWidget.hpp"

namespace plane {

class Label : BaseWidget {
public:
	Label(std::string text) {
		this->text = text;
	}

	virtual ~Label() {}

	virtual void paint(IScreen& screen) {
		const Vec2<float>& pos = getPos();

	}
private:
	std::string text;
};

}

#endif /* SRC_GUI_LABEL_HPP_ */
