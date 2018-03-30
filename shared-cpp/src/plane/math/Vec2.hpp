/*
 * Vec2.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_MATH_VEC2_HPP_
#define SRC_PLANE_MATH_VEC2_HPP_

#include <cmath>

namespace plane {

/**
 * Immutable, two-dimensional vector.
 */
template <typename T> class Vec2 {
public:
	Vec2() {
		x = T();
		y = T();
	}

	Vec2(T x, T y) {
		this->x = x;
		this->y = y;
	}

	Vec2(const Vec2& other) {
		x = other.x;
		y = other.y;
	}

	virtual ~Vec2() {}

	Vec2 add(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }

	Vec2 sub(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }

	Vec2 scale(double factor) const { return Vec2(x * factor, y * factor); }

	Vec2 normalize() const {
		double len = length();
		return Vec2(x / len, y / len);
	}

	double length() const { return std::sqrt((x * x) + (y * y)); }

	T getX() const { return x; }

	T getY() const { return y; }
private:
	T x;
	T y;
};

}

#endif /* SRC_PLANE_MATH_VEC2_HPP_ */
