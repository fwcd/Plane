/*
 * SDLTest.cpp
 *
 *  Created on: 28.03.2018
 */

#include <plane/gui/GUI.hpp>
#include <plane/gui/Button.hpp>
#include <plane/gui/ImageView.hpp>
#include <plane/gui/Label.hpp>
#include <plane/utils/Color.hpp>
#include <plane/utils/Logger.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <memory>

#include "../src/plane-sdl/SDLScreen.hpp"

#define PTR(T) std::shared_ptr<T>

using namespace plane;

int main(int argc, char* args[]) {
	std::shared_ptr<SDLScreen> screen(new SDLScreen("Test", 640, 480));
	screen->setBackground(Color(60, 60, 60));

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

	PTR(Label) label(new Label("Label", 24, *screen));
	label->setColor(COLOR_WHITE);
	PTR(ImageView) image(new ImageView("resources/demo.jpg"));
	PTR(Button) button(new Button("Demo", 14, *screen));
	PTR(Button) button2(new Button("Demo", 18, *screen));

	PTR(GUI) gui(new GUI(screen));
	gui->add(label);
	gui->add(button);
	gui->add(image);
	gui->add(button2);
	screen->addOnTop(gui);
	LOG.info("Initialized GUI");

	screen->runMainloop(1000 / 60); // 60 tps
	return 0;
}
