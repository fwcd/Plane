/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "../src/SDLScreen.hpp"

using namespace plane;

int main(int argc, char* args[]) {
	SDLScreen screen("Test", 640, 480);
	screen.runMainloop(100); // 100 ms delay
	return 0;
}
