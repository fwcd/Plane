/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <SDL2/SDL_main.h>
#include <TestApp.hpp>
#include <memory>

#include "../src/plane-sdl/SDLScreen.hpp"

using namespace plane;

int main(int argc, char* args[]) {
	std::shared_ptr<SDLScreen> screen(new SDLScreen("Test", 640, 480));
	screen->setAppFolderPath("../test/");
	TestApp app;
	app.initialize(screen);
	screen->runMainloop(1000 / 60); // 60 tps
	return 0;
}
