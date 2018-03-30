/*
 * Color.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_UTILS_COLOR_HPP_
#define SRC_PLANE_UTILS_COLOR_HPP_

#include <cstdint>

namespace plane {

/**
 * An 8-bit per channel RGBA color.
 */
class Color {
public:
	Color() {
		red = 0;
		green = 0;
		blue = 0;
		alpha = 0;
	}

	Color(uint8_t red, uint8_t green, uint8_t blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
		alpha = 0xFF;
	}

	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
	}

	uint8_t getRed() { return red; }

	uint8_t getGreen() { return green; }

	uint8_t getBlue() { return blue; }

	uint8_t getAlpha() { return alpha; }
private:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

const Color COLOR_RED = Color(255, 0, 0);
const Color COLOR_GREEN = Color(0, 255, 0);
const Color COLOR_BLUE = Color(0, 0, 255);
const Color COLOR_YELLOW = Color(255, 255, 0);
const Color COLOR_MAGENTA = Color(255, 0, 255);
const Color COLOR_WHITE = Color(255, 255, 255);
const Color COLOR_BLACK = Color(0, 0, 0);
const Color COLOR_TRANSPARENT = Color(0, 0, 0, 0);

}

#endif /* SRC_PLANE_UTILS_COLOR_HPP_ */
