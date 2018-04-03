/*
 * Stroke.hpp
 *
 *  Created on: 01.04.2018
 */

#ifndef SRC_PLANE_CORE_STROKE_HPP_
#define SRC_PLANE_CORE_STROKE_HPP_

#include "../utils/Color.hpp"

namespace plane {

/**
 * A set of attributes that specify how
 * strokes (e.g. lines) are painted.
 */
class Stroke {
public:
	Stroke() {
		width = 2;
		color = DEFAULT_COLOR;
	}
	
	Stroke(Color color) {
		width = 2;
		this->color = color;
	}
	
	Stroke(float width, Color color) {
		this->width = width;
		this->color = color;
	}
	
	virtual ~Stroke() {}
	
	float getWidth() { return width; }
	
	Color getColor() { return color; }
private:
	float width;
	Color color;
};

}

#endif /* SRC_PLANE_CORE_STROKE_HPP_ */
