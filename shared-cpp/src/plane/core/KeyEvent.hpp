/*
 * KeyEvent.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_CORE_KEYEVENT_HPP_
#define SRC_PLANE_CORE_KEYEVENT_HPP_

#include <vector>

#include "Key.hpp"

namespace plane {

class KeyEvent {
public:
	KeyEvent(Key key) {
		this->key = key;
		modifiers = std::vector<Key>();
	}

	KeyEvent(char keyChar) {
		this->key = Key(keyChar);
		modifiers = std::vector<Key>();
	}

	KeyEvent(Key key, std::initializer_list<Key> modifiers) {
		this->key = key;
		this->modifiers = std::vector<Key>(modifiers);
	}

	virtual ~KeyEvent() {}

	Key getKey() { return key; }

	std::vector<Key> getModifiers() { return modifiers; }
private:
	Key key;
	std::vector<Key> modifiers;
};

}

#endif /* SRC_PLANE_CORE_KEYEVENT_HPP_ */
