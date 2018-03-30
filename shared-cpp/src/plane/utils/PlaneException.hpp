/*
 * PlaneException.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_API_PLANEEXCEPTION_HPP_
#define SRC_API_PLANEEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace plane {

/**
 * The superclass for all plane-related messages.
 */
class PlaneException : public std::runtime_error {
public:
	PlaneException(std::string msg) : std::runtime_error(msg) {}

	virtual ~PlaneException() {}
};

}

#endif /* SRC_API_PLANEEXCEPTION_HPP_ */
