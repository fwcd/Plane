/*
 * PlaneTest.cpp
 *
 *  Created on: 29.03.2018
 */

#include "../src/gui/Label.hpp"
#include <iostream>

using namespace plane;

int main() {
	Label l("test");
	std::cout << &l;
	return 0;
}
