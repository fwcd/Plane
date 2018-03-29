/*
 * SDLScreen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_SDLSCREEN_HPP_
#define SRC_SDLSCREEN_HPP_

#include <core/FontAttributes.hpp>
#include <core/IPaintable.hpp>
#include <core/IScreen.hpp>
#include <core/KeyListener.hpp>
#include <core/MouseListener.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <utils/Color.hpp>
#include <algorithm>
#include <cstdint>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "SDLException.hpp"

namespace plane {

class SDLScreen : public IScreen {
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

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == 0) {
			throw SDLException("Renderer creation error");
		}

		surface = SDL_GetWindowSurface(window);
		closed = false;
	}

	virtual ~SDLScreen() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	virtual void repaintSoon() {} // Repainting automatically happens

	virtual void drawRect(float x, float y, float w, float h) {
		SDL_Rect rect = {(int) x, (int) y, (int) w, (int) h};
		SDL_RenderDrawRect(renderer, &rect);
	}

	virtual void fillRect(float x, float y, float w, float h) {
		SDL_Rect rect = {(int) x, (int) y, (int) w, (int) h};
		SDL_RenderFillRect(renderer, &rect);
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

	virtual void setColor(Color color) {
		SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
	}

	virtual Color getColor() {
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 0;
		SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
		return Color(r, g, b, a);
	}

	virtual void add(std::shared_ptr<IPaintable> paintable) {
		paintables.push_back(paintable);
	}

	virtual void remove(std::shared_ptr<IPaintable> paintable) {
		paintables.erase(std::remove(paintables.begin(), paintables.end(), paintable), paintables.end());
	}

	void runMainloop(long intervalMs) {
		SDL_Event event;

		while (!closed) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					closed = true;
				}
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
			SDL_RenderClear(renderer);

			for (std::shared_ptr<IPaintable> paintable : paintables) {
				paintable->paint(*this);
			}

			SDL_RenderPresent(renderer);
			SDL_Delay(intervalMs);
		}
	}
private:
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	std::vector<std::shared_ptr<IPaintable>> paintables;
	bool closed;
};

}

#endif /* SRC_SDLSCREEN_HPP_ */
