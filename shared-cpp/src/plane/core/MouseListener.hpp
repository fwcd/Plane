/*
 * MouseListener.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_API_MOUSELISTENER_HPP_
#define SRC_API_MOUSELISTENER_HPP_

#include <functional>

#include "MouseEvent.hpp"

namespace plane {

/**
 * A mouse- or (multi-)touch listener.
 * If touch is used, move listeners can silently be ignored.
 */
class MouseListener {
public:
	virtual ~MouseListener() {}

	void setClickHandler(std::function<void(const MouseEvent&)> handler) { clickHandler = handler; }

	void setReleaseHandler(std::function<void(const MouseEvent&)> handler) { releaseHandler = handler; }

	void setDragHandler(std::function<void(const MouseEvent&)> handler) { dragHandler = handler; }

	void setMoveHandler(std::function<void(const MouseEvent&)> handler) { moveHandler = handler; }

	void fireClick(const MouseEvent& event) {
		if (clickHandler) {
			clickHandler(event);
		}
	}

	void fireRelease(const MouseEvent& event) {
		if (releaseHandler) {
			releaseHandler(event);
		}
	}

	void fireDrag(const MouseEvent& event) {
		if (dragHandler) {
			dragHandler(event);
		}
	}

	void fireMove(const MouseEvent& event) {
		if (moveHandler) {
			moveHandler(event);
		}
	}
private:
	std::function<void(const MouseEvent&)> clickHandler;
	std::function<void(const MouseEvent&)> releaseHandler;
	std::function<void(const MouseEvent&)> dragHandler;
	std::function<void(const MouseEvent&)> moveHandler;
};

}

#endif /* SRC_API_MOUSELISTENER_HPP_ */
