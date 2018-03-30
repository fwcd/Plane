/*
 * Utilities.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_UTILS_UTILITIES_HPP_
#define SRC_PLANE_UTILS_UTILITIES_HPP_

#include <sstream>
#include <string>
#include <vector>

namespace plane {

bool endsWith(const std::string& str, const std::string& end) {
	if (str.length() >= end.length()) {
		return str.compare(str.length() - end.length(), end.length(), end) == 0;
	} else {
		return false;
	}
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::stringstream stream(str);
    std::vector<std::string> elements;
    std::string item;

    while (std::getline(stream, item, delimiter)) {
        elements.push_back(item);
    }

    return elements;
}

}

#endif /* SRC_PLANE_UTILS_UTILITIES_HPP_ */
