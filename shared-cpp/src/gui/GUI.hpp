/*
 * GUI.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_CORE_GUI_HPP_
#define SRC_CORE_GUI_HPP_

#include "../core/IPaintable.hpp"

namespace plane {

class GUI : IPaintable {
public:
	GUI() {}

	virtual ~GUI() {}

	virtual void paint(const IScreen& screen) {

	}
private:

};

}

#endif /* SRC_CORE_GUI_HPP_ */
