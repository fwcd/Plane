/*
 * IBoxBounded.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_GUI_IBOXBOUNDED_HPP_
#define SRC_PLANE_GUI_IBOXBOUNDED_HPP_

namespace plane {

class IBoxBounded {
public:
	virtual ~IBoxBounded() {}

	virtual Rect2<float> getBoundingBox() = 0;
};

}

#endif /* SRC_PLANE_GUI_IBOXBOUNDED_HPP_ */
