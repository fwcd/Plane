/*
 * PlaneApp.hpp
 *
 *  Created on: 31.03.2018
 *      Author: fredrik
 */

#ifndef SRC_PLANE_CORE_PLANEAPP_HPP_
#define SRC_PLANE_CORE_PLANEAPP_HPP_

#include <memory>

#include "Screen.hpp"

namespace plane {

/**
 * The base class for all applications
 * that build upon the Plane API.
 */
class PlaneApp {
public:
	virtual ~PlaneApp() {}

    virtual void initialize(std::shared_ptr<Screen> screen) {}
	
	bool doesShowMobileStatusBar() { return false; }
};

}

#endif /* SRC_PLANE_CORE_PLANEAPP_HPP_ */
