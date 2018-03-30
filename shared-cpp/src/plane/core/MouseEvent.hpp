/*
 * MouseEvent.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_API_MOUSEEVENT_HPP_
#define SRC_API_MOUSEEVENT_HPP_

#include <initializer_list>
#include <vector>

#include "MouseButton.hpp"
#include "../math/Vec2.hpp"

namespace plane {

/**
 * A container for a mouse- or (multi-)touch event
 */
class MouseEvent {
public:
	MouseEvent(float x, float y) {
		lastPositions = std::vector<Vec2<float>>();
		positions = std::vector<Vec2<float>>({Vec2<float>(x, y)});
	}

	MouseEvent(float lastX, float lastY, float x, float y) {
		lastPositions = std::vector<Vec2<float>>({Vec2<float>(lastX, lastY)});
		positions = std::vector<Vec2<float>>({Vec2<float>(x, y)});
	}

	MouseEvent(
			std::initializer_list<Vec2<float>> lastPositions,
			std::initializer_list<Vec2<float>> positions
	) {
		this->lastPositions = std::vector<Vec2<float>>(lastPositions);
		this->positions = std::vector<Vec2<float>>(positions);
	}

	MouseEvent(std::vector<Vec2<float>> lastPositions, std::vector<Vec2<float>> positions) {
		this->lastPositions = lastPositions;
		this->positions = positions;
	}

	virtual ~MouseEvent() {}

	void setButton(MouseButton button) { this->button = button; }

	void setClicks(int clicks) { this->clicks = clicks; }

	bool usesTouch() { return button == MouseButton::TOUCH; }

	Vec2<float> getPosDelta() { return getPos().sub(getLastPos()); }

	Vec2<float> getLastPos() { return lastPositions[0]; }

	Vec2<float> getPos() { return positions[0]; }

	std::vector<Vec2<float>> getAllLastPositions() { return lastPositions; }

	std::vector<Vec2<float>> getAllPositions() { return positions; }

	MouseButton getButton() { return button; }

	int getClicks() { return clicks; }
private:
	std::vector<Vec2<float>> lastPositions;
	std::vector<Vec2<float>> positions; // Multiple positions can be stored (e.g. if multi-touch is used)
	MouseButton button = MouseButton::MOUSE_INVALID;
	int clicks = 1;
};

}

#endif /* SRC_API_MOUSEEVENT_HPP_ */
