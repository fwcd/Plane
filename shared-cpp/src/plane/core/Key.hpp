/*
 * Key.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_CORE_KEY_HPP_
#define SRC_PLANE_CORE_KEY_HPP_

#include "SpecialKey.hpp"
#include "../utils/PlaneException.hpp"

namespace plane {

class Key {
public:
	Key() {
		keyChar = 0;
		special = SpecialKey::NO_KEY;
	}

	Key(char keyChar) {
		this->keyChar = keyChar;
		special = SpecialKey::NO_KEY;
	}

	Key(SpecialKey special) {
		keyChar = 0;
		this->special = special;
	}

	char asChar() {
		if (!hasChar()) {
			throw PlaneException("Tried to fetch non-existent key character.");
		}

		return keyChar;
	}

	SpecialKey asSpecialKey() {
		if (!isSpecial()) {
			throw PlaneException("Tried to fetch non-existent special key.");
		}

		return special;
	}

	bool isEmpty() { return !hasChar() && !isSpecial(); }

	bool hasChar() { return keyChar != 0; }

	bool isSpecial() { return special != SpecialKey::NO_KEY; }

	virtual ~Key() {}
private:
	char keyChar;
	SpecialKey special;
};

}

#endif /* SRC_PLANE_CORE_KEY_HPP_ */
