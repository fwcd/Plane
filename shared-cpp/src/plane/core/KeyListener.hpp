/*
 * KeyListener.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_CORE_KEYLISTENER_HPP_
#define SRC_PLANE_CORE_KEYLISTENER_HPP_

#include <functional>

#include "KeyEvent.hpp"

namespace plane {

class KeyListener {
public:
	virtual ~KeyListener() {}

	void setPressHandler(std::function<void(const KeyEvent&)> handler) { pressHandler = handler; }

	void setReleaseHandler(std::function<void(const KeyEvent&)> handler) { releaseHandler = handler; }

	void firePress(const KeyEvent& event) {
		if (pressHandler) {
			pressHandler(event);
		}
	}

	void fireRelease(const KeyEvent& event) {
		if (releaseHandler) {
			releaseHandler(event);
		}
	}
private:
	std::function<void(const KeyEvent&)> pressHandler;
	std::function<void(const KeyEvent&)> releaseHandler;
};

}

#endif /* SRC_PLANE_CORE_KEYLISTENER_HPP_ */
