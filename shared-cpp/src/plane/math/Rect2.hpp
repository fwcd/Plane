/*
 * Rect2.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_MATH_RECT2_HPP_
#define SRC_PLANE_MATH_RECT2_HPP_

#include "../core/IPaintable.hpp"
#include "../core/IScreen.hpp"
#include "../utils/Color.hpp"
#include "Vec2.hpp"

namespace plane {

/**
 * Mutable, two-dimensional rectangle.
 */
template <typename T> class Rect2 : public IPaintable {
public:
	Rect2() {
		this->topLeft = Vec2<float>(0, 0);
		this->size = Vec2<float>(0, 0);
	}

	Rect2(const Vec2<T>& topLeft, const Vec2<T>& size) {
		this->topLeft = topLeft;
		this->size = size;
	}

	Rect2(const Vec2<T>& topLeft, const T& width, const T& height) {
		this->topLeft = topLeft;
		this->size = Vec2<T>(width, height);
	}

	Rect2(const T& x, const T& y, const T& width, const T& height) {
		this->topLeft = Vec2<T>(x, y);
		this->size = Vec2<T>(width, height);
	}

	virtual ~Rect2() {}

	Vec2<T> getTopLeft() { return topLeft; }

	Vec2<T> getBottomRight() { return topLeft.add(size); }

	Vec2<T> getSize() { return size; }

	bool contains(const Vec2<T>& pos) {
		Vec2<T> bottomRight = getBottomRight();
		return pos.getX() > topLeft.getX()
				&& pos.getX() < bottomRight.getX()
				&& pos.getY() > topLeft.getY()
				&& pos.getY() < bottomRight.getY();
	}

	void moveBy(const Vec2<T>& delta) {
		topLeft = topLeft.add(delta);
	}

	void setTopLeft(Vec2<T> newTopLeft) {
		topLeft = newTopLeft;
	}

	void setSize(float width, float height) {
		size = Vec2<float>(width, height);
	}

	void setColor(Color color) {this->color = color; }

	Color getColor() { return color; }

	void setFilled(bool filled) { this->filled = filled; }

	bool isFilled() { return filled; }

	T getWidth() { return size.getX(); }

	T getHeight() { return size.getY(); }

	virtual void paint(IScreen& screen) {
		float x = (float) topLeft.getX();
		float y = (float) topLeft.getY();
		float w = (float) getWidth();
		float h = (float) getHeight();

		screen.setColor(color);
		if (filled) {
			screen.fillRect(x, y, w, h);
		} else {
			screen.drawRect(x, y, w, h);
		}
	}

	std::string toString() {
		return "{x: " + std::to_string(topLeft.getX())
			+ ", y: " + std::to_string(topLeft.getY())
			+ ", w: " + std::to_string(getWidth())
			+ ", h: " + std::to_string(getHeight());
	}
private:
	Vec2<T> topLeft;
	Vec2<T> size;
	Color color = COLOR_BLACK;
	bool filled = true;
};

}

#endif /* SRC_PLANE_MATH_RECT2_HPP_ */
