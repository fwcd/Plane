/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <core/MouseEvent.hpp>
#include <core/MouseListener.hpp>
#include <gui/BaseWidget.hpp>
#include <gui/Label.hpp>
#include <math/Rect2.hpp>
#include <math/Vec2.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <utils/Color.hpp>
#include <memory>

#include "../src/SDLScreen.hpp"

#define PTR(T) std::shared_ptr<T>

using namespace plane;

int main(int argc, char* args[]) {
	SDLScreen screen("Test", 640, 480);

	PTR(Rect2<float>) rect1(new Rect2<float>(10, 10, 50, 50));
	rect1->setColor(COLOR_MAGENTA);
	rect1->setFilled(true);
	screen.add(rect1);

	PTR(Rect2<float>) rect2(new Rect2<float>(40, 40, 50, 50));
	rect2->setColor(COLOR_YELLOW);
	rect2->setFilled(false);
	screen.add(rect2);

	PTR(Label) label(new Label("Label"));
	label->setPos(Vec2<float>(100, 20));
	label->setSize(24);
	label->setColor(COLOR_WHITE);
	screen.add(label);

	PTR(MouseListener) mouseListener(new MouseListener);
	mouseListener->setDragHandler([rect2](MouseEvent e) {rect2->moveBy(e.getPosDelta());});
	screen.addMouseListener(mouseListener);

	screen.runMainloop(1000 / 30); // 30 tps
	return 0;
}
