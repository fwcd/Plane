/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <math/Rect2.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <utils/Color.hpp>

#include "../src/SDLScreen.hpp"

using namespace plane;

int main(int argc, char* args[]) {
	SDLScreen screen("Test", 640, 480);
	std::shared_ptr<Rect2<float>> test(new Rect2<float>(10, 10, 100, 100));
	test->setColor(Color(255, 0, 0));
	screen.add(test);
	screen.runMainloop(100); // 100 ms delay
	return 0;
}
