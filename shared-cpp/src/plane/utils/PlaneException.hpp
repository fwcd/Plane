/*
 * PlaneException.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_API_PLANEEXCEPTION_HPP_
#define SRC_API_PLANEEXCEPTION_HPP_

#include <stdexcept>
#include <string>

#ifndef _NOEXCEPT
#define _NOEXCEPT
#endif

namespace plane {

/**
 * The superclass for all plane-related messages.
 */
class PlaneException : public std::runtime_error {
public:
	PlaneException(std::string msg) : std::runtime_error(msg) {}

	virtual ~PlaneException() _NOEXCEPT {}
};

}

#endif /* SRC_API_PLANEEXCEPTION_HPP_ */
