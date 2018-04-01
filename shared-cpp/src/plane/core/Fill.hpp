/*
 * Fill.hpp
 *
 *  Created on: 01.04.2018
 */

#ifndef SRC_PLANE_CORE_FILL_HPP_
#define SRC_PLANE_CORE_FILL_HPP_

#include "../utils/Color.hpp"

namespace plane {
	
class Fill {
public:
	Fill() {
		color = DEFAULT_COLOR;
	}
	
	Fill(Color color) {
		this->color = color;
	}
	
	virtual ~Fill() {}
	
	Color getColor() { return color; }
private:
	Color color;
};
	
}

#endif /* SRC_PLANE_CORE_FILL_HPP_ */
