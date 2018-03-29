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

	void setClickHandler(std::function<void(MouseEvent)> handler) { clickHandler = handler; }

	void setReleaseHandler(std::function<void(MouseEvent)> handler) { releaseHandler = handler; }

	void setDragHandler(std::function<void(MouseEvent)> handler) { dragHandler = handler; }

	void setMoveHandler(std::function<void(MouseEvent)> handler) { moveHandler = handler; }

	void fireClick(MouseEvent event) { clickHandler(event); }

	void fireRelease(MouseEvent event) { releaseHandler(event); }

	void fireDrag(MouseEvent event) { dragHandler(event); }

	void fireMove(MouseEvent event) { moveHandler(event); }
private:
	std::function<void(MouseEvent)> clickHandler;
	std::function<void(MouseEvent)> releaseHandler;
	std::function<void(MouseEvent)> dragHandler;
	std::function<void(MouseEvent)> moveHandler;
};

}

#endif /* SRC_API_MOUSELISTENER_HPP_ */
