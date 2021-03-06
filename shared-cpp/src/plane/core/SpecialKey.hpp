/*
 * SpecialKey.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_CORE_SPECIALKEY_HPP_
#define SRC_PLANE_CORE_SPECIALKEY_HPP_

namespace plane {

/**
 * A key that can not be described
 * using a character.
 */
enum SpecialKey {
	NO_KEY,
	CTRL_KEY,
	SHIFT_KEY,
	ALT_KEY,
	SUPER_KEY,
	CAPS_KEY,
	TAB_KEY,
	ESC_KEY,
	BACKSPACE_KEY,
	ENTER_KEY,
	UP_KEY,
	DOWN_KEY,
	LEFT_KEY,
	RIGHT_KEY
};

}

#endif /* SRC_PLANE_CORE_SPECIALKEY_HPP_ */
