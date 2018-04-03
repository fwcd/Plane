/*
 * BoxBounded.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_BOX_BOUNDED_HPP_
#define SRC_PLANE_GUI_BOX_BOUNDED_HPP_

namespace plane {

/**
 * An item that has a two-dimensional
 * bounding box.
 */
class BoxBounded { // Interface
public:
	virtual ~BoxBounded() {}

	virtual Rect2<float> getBoundingBox() = 0;
};

}

#endif /* SRC_PLANE_GUI_BOX_BOUNDED_HPP_ */
