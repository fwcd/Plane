/*
 * KeyListener.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_CORE_KEYLISTENER_HPP_
#define SRC_CORE_KEYLISTENER_HPP_

#include <functional>

#include "KeyEvent.hpp"

namespace plane {

class KeyListener {
public:
	virtual ~KeyListener() {}

	void setPressHandler(std::function<void(KeyEvent)> handler) { pressHandler = handler; }

	void setReleaseHandler(std::function<void(KeyEvent)> handler) { releaseHandler = handler; }

	void firePress(KeyEvent event) { pressHandler(event); }

	void fireRelease(KeyEvent event) { releaseHandler(event); }
private:
	std::function<void(KeyEvent)> pressHandler;
	std::function<void(KeyEvent)> releaseHandler;
};

}

#endif /* SRC_CORE_KEYLISTENER_HPP_ */
