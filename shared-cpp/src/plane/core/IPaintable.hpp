/*
 * PaintableInterface.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_CORE_IPAINTABLE_HPP_
#define SRC_PLANE_CORE_IPAINTABLE_HPP_

namespace plane {
class IScreen;
} /* namespace plane */

namespace plane {

class IPaintable {
public:
	virtual ~IPaintable() {}

	virtual void paint(IScreen& screen) = 0;
};

}

#endif /* SRC_PLANE_CORE_IPAINTABLE_HPP_ */
