/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <plane/gui/BaseWidget.hpp>
#include <plane/gui/GUI.hpp>
#include <plane/gui/ImageView.hpp>
#include <plane/gui/Label.hpp>
#include <plane/math/Vec2.hpp>
#include <plane/utils/Color.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <memory>

#include "../src/plane-sdl/SDLScreen.hpp"

#define PTR(T) std::shared_ptr<T>

using namespace plane;

int main(int argc, char* args[]) {
	SDLScreen screen("Test", 640, 480);

//	PTR(Rect2<float>) rect1(new Rect2<float>(10, 10, 50, 50));
//	rect1->setColor(COLOR_MAGENTA);
//	rect1->setFilled(true);
//	screen.addOnBottom(rect1);
//
//	PTR(Rect2<float>) rect2(new Rect2<float>(80, 20, 50, 50));
//	rect2->setColor(COLOR_YELLOW);
//	rect2->setFilled(false);
//	screen.addOnBottom(rect2);
//
//	PTR(MouseListener) rectDragListener(new MouseListener());
//	rectDragListener->setDragHandler([rect2](MouseEvent e) {
//		if (rect2->contains(e.getPos())) {
//			rect2->moveBy(e.getPosDelta());
//		}
//	});
//	screen.addMouseListener(rectDragListener);

	PTR(Label) label(new Label("Label", 24, screen));
	label->setPos(Vec2<float>(100, 20));
	label->setColor(COLOR_WHITE);

	PTR(ImageView) image(new ImageView("resources/demo.jpg"));
	image->setPos(Vec2<float>(300, 300));

	PTR(GUI) gui(new GUI());
	gui->add(label);
	gui->add(image);
	screen.addOnTop(gui);

	screen.runMainloop(1000 / 60); // 60 tps
	return 0;
}
