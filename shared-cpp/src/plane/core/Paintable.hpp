/*
 * Paintable.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_CORE_PAINTABLE_HPP_
#define SRC_PLANE_CORE_PAINTABLE_HPP_

namespace plane {

class Screen;

/**
 * An item that can be painted to
 * a Screen.
 */
class Paintable { // Interface
public:
	virtual ~Paintable() {}

	virtual void paint(Screen& screen) = 0;
};

}

#endif /* SRC_PLANE_CORE_PAINTABLE_HPP_ */
