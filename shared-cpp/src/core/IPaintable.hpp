/*
 * PaintableInterface.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_CORE_IPAINTABLE_HPP_
#define SRC_CORE_IPAINTABLE_HPP_

#include "IScreen.hpp"

namespace plane {

class IPaintable {
public:
	virtual ~IPaintable() {}

	virtual void paint(IScreen& screen) = 0;
};

}

#endif /* SRC_CORE_IPAINTABLE_HPP_ */
