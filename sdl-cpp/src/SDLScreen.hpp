/*
 * SDLScreen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_SDLSCREEN_HPP_
#define SRC_SDLSCREEN_HPP_

#include <core/FontAttributes.hpp>
#include <core/IScreen.hpp>
#include <core/KeyListener.hpp>
#include <core/MouseListener.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <string>

#include "SDLException.hpp"

namespace plane {

class SDLScreen: public IScreen {
public:
	SDLScreen(std::string title, int width, int height) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			throw SDLException("SDL initialization error");
		}

		window = SDL_CreateWindow(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_SHOWN
		);
		if (window == 0) {
			throw SDLException("Window creation error");
		}

		surface = SDL_GetWindowSurface(window);
		closed = false;
	}

	virtual ~SDLScreen() {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	virtual void repaintSoon() {
		// TODO
	}

	virtual void drawRect(float x, float y, float w, float h) {
		// TODO
	}

	virtual void fillRect(float x, float y, float w, float h) {
		// TODO
	}

	virtual void drawOval(float x, float y, float w, float h) {
		// TODO
	}

	virtual void fillOval(float x, float y, float w, float h) {
		// TODO
	}

	virtual void drawString(std::string str, float x, float y, FontAttributes attribs) {
		// TODO
	}

	virtual void drawLine(float startX, float startY, float endX, float endY) {
		// TODO
	}

	virtual void addKeyListener(KeyListener keyListener) {
		// TODO
	}

	virtual void addMouseListener(MouseListener mouseListener) {
		// TODO
	}

	virtual void removeKeyListener(KeyListener keyListener) {
		// TODO
	}

	virtual void removeMouseListener(MouseListener mouseListener) {
		// TODO
	}

	void runMainloop(long intervalMs) {
		SDL_Event event;

		while (!closed) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					closed = true;
				}
			}
			SDL_Delay(intervalMs);
		}
	}
private:
	SDL_Window* window;
	SDL_Surface* surface;
	bool closed;
};

}

#endif /* SRC_SDLSCREEN_HPP_ */
