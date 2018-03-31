/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <memory>
#include "TestApp.hpp"

#include "../src/plane-sdl/SDLScreen.hpp"

using namespace plane;

int main(int argc, char* args[]) {
	std::shared_ptr<SDLScreen> screen(new SDLScreen("Test", 640, 480));
	TestApp app;
	app.initialize(screen);

	screen->runMainloop(1000 / 60); // 60 tps
	return 0;
}
