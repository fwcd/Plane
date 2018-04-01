/*
 * PlaneApp.hpp
 *
 *  Created on: 31.03.2018
 *      Author: fredrik
 */

#ifndef SRC_PLANE_CORE_PLANEAPP_HPP_
#define SRC_PLANE_CORE_PLANEAPP_HPP_

#include <memory>

#include "IScreen.hpp"

namespace plane {

class PlaneApp {
public:
	virtual ~PlaneApp() {}

    virtual void initialize(std::shared_ptr<IScreen> screen) {}
};

}

#endif /* SRC_PLANE_CORE_PLANEAPP_HPP_ */
