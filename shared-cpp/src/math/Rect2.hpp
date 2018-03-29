/*
 * Rect2.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_MATH_RECT2_HPP_
#define SRC_MATH_RECT2_HPP_

#include "../core/IPaintable.hpp"
#include "../core/IScreen.hpp"
#include "../utils/Color.hpp"
#include "Vec2.hpp"

namespace plane {

/**
 * Immutable, two-dimensional rectangle.
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

	Rect2<T> movedBy(const Vec2<T>& delta) {
		return Rect2<T>(topLeft.add(delta), size);
	}

	Rect2<T> withTopLeft(const Vec2<T>& newTopLeft) {
		return Rect2<T>(newTopLeft, size);
	}

	void setColor(Color color) { this->color = color; }

	Color getColor() { return color; }

	T getWidth() { return size.getX(); }

	T getHeight() { return size.getY(); }

	virtual void paint(IScreen& screen) {
		screen.setColor(color);
		screen.drawRect((float) topLeft.getX(), (float) topLeft.getY(), (float) getWidth(), (float) getHeight());
	}
private:
	Vec2<T> topLeft;
	Vec2<T> size;
	Color color;
};

}

#endif /* SRC_MATH_RECT2_HPP_ */
