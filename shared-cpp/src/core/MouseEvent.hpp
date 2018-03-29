/*
 * MouseEvent.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_API_MOUSEEVENT_HPP_
#define SRC_API_MOUSEEVENT_HPP_

#include "../math/Vec2.hpp"
#include "MouseButton.hpp"

namespace plane {

/**
 * A container for a mouse- or (multi-)touch event
 */
class MouseEvent {
public:
	MouseEvent(float x, float y, MouseButton button) {
		positions = std::vector<Vec2<float>>({Vec2<float>(x, y)});
		this->button = button;
		clicks = 1;
	}

	MouseEvent(std::initializer_list<Vec2<float>> positions, MouseButton button, int clicks) {
		this->positions = std::vector<Vec2<float>>(positions);
		this->button = button;
		this->clicks = 1;
	}

	virtual ~MouseEvent() {}

	bool usesTouch() { return button == MouseButton::TOUCH; }

	Vec2<float> getPos() { return positions[0]; }

	std::vector<Vec2<float>> getAllPositions() { return positions; }

	MouseButton getButton() { return button; }
private:
	std::vector<Vec2<float>> positions; // Multiple positions can be stored (e.g. if multi-touch is used)
	MouseButton button;
	int clicks;
};

}

#endif /* SRC_API_MOUSEEVENT_HPP_ */
