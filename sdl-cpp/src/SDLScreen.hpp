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
#include <core/MouseButton.hpp>
#include <core/MouseEvent.hpp>
#include <core/MouseListener.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <utils/Color.hpp>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "SDLException.hpp"

using std::vector;
using std::shared_ptr;

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
		this->width = width;
		this->height = height;

		if (TTF_Init() < 0) {
			throw SDLException("Error while initializing TTF engine");
		}
	}

	virtual ~SDLScreen() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
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
		TTF_Font* font = TTF_OpenFont("resources/arial.ttf", attribs.getSize());
		if (font == 0) {
			throw SDLException("Font not found.");
		}
		SDL_Color textColor = getSDLColor();
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, str.c_str(), textColor);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		int textWidth = textSurface->w;
		int textHeight = textSurface->h;
		SDL_Rect bounds = {(int) x, (int) y, textWidth, textHeight};

		SDL_RenderCopy(renderer, texture, 0, &bounds);

		SDL_DestroyTexture(texture);
		SDL_FreeSurface(textSurface);
		TTF_CloseFont(font);
	}

	virtual void drawLine(float startX, float startY, float endX, float endY) {
		// TODO
	}

	virtual void addKeyListener(shared_ptr<KeyListener> keyListener) {
		keyListeners.push_back(keyListener);
	}

	virtual void addMouseListener(shared_ptr<MouseListener> mouseListener) {
		mouseListeners.push_back(mouseListener);
	}

	virtual void removeKeyListener(shared_ptr<KeyListener> keyListener) {
		keyListeners.erase(std::remove(keyListeners.begin(), keyListeners.end(), keyListener), keyListeners.end());
	}

	virtual void removeMouseListener(shared_ptr<MouseListener> mouseListener) {
		mouseListeners.erase(std::remove(mouseListeners.begin(), mouseListeners.end(), mouseListener), mouseListeners.end());
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

	virtual void add(shared_ptr<IPaintable> paintable) {
		paintables.push_back(paintable);
	}

	virtual void remove(shared_ptr<IPaintable> paintable) {
		paintables.erase(std::remove(paintables.begin(), paintables.end(), paintable), paintables.end());
	}

	virtual float getWidth() {
		return width;
	}

	virtual float getHeight() {
		return height;
	}

	void runMainloop(long intervalMs) {
		SDL_Event event;

		while (!closed) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					closed = true;
				} else if (isSDLMouseEvent(event)) {
					MouseEvent e = mouseEventOf(event);
					switch (event.type) {
					case SDL_MOUSEBUTTONDOWN:
						withMouseListeners([e](MouseListener& listener) {listener.fireClick(e);});
						mouseDown = true;
						break;
					case SDL_MOUSEMOTION:
						if (mouseDown) {
							withMouseListeners([e](MouseListener& listener) {listener.fireDrag(e);});
						} else {
							withMouseListeners([e](MouseListener& listener) {listener.fireMove(e);});
						}
						break;
					case SDL_MOUSEBUTTONUP:
						withMouseListeners([e](MouseListener& listener) {listener.fireRelease(e);});
						mouseDown = false;
						break;
					}
				}
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
			SDL_RenderClear(renderer);

			for (shared_ptr<IPaintable> paintable : paintables) {
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
	vector<shared_ptr<MouseListener>> mouseListeners = vector<shared_ptr<MouseListener>>();
	vector<shared_ptr<KeyListener>> keyListeners = vector<shared_ptr<KeyListener>>();
	vector<shared_ptr<IPaintable>> paintables = vector<shared_ptr<IPaintable>>();
	bool closed = false;
	bool mouseDown = false;
	int width;
	int height;
	float lastMouseX = -1;
	float lastMouseY = -1;

	SDL_Color getSDLColor() {
		SDL_Color color;
		SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
		return color;
	}

	MouseButton toMouseButton(uint8_t sdlButton) {
		switch (sdlButton) {
		case SDL_BUTTON_LEFT:
			return MouseButton::MOUSE_LEFT;
		case SDL_BUTTON_RIGHT:
			return MouseButton::MOUSE_RIGHT;
		case SDL_BUTTON_MIDDLE:
			return MouseButton::MOUSE_MIDDLE;
		default:
			return MouseButton::MOUSE_INVALID;
		}
	}

	bool isSDLMouseEvent(const SDL_Event& event) {
		uint32_t t = event.type;
		return t == SDL_MOUSEBUTTONDOWN
				|| t == SDL_MOUSEBUTTONUP
				|| t == SDL_MOUSEMOTION
				|| t == SDL_MOUSEWHEEL
				|| t == SDL_MOUSEWHEEL_FLIPPED
				|| t == SDL_MOUSEWHEEL_NORMAL;
	}

	MouseEvent mouseEventOf(const SDL_Event& event) {
		const int x = event.motion.x;
		const int y = event.motion.y;

		// TODO: Handle touch events
		MouseEvent e = MouseEvent(lastMouseX, lastMouseY, x, y);
		e.setButton(toMouseButton(event.button.button));
		e.setClicks(event.button.clicks);

		lastMouseX = x;
		lastMouseY = y;
		return e;
	}

	void withMouseListeners(std::function<void(MouseListener&)> notifier) {
		for (shared_ptr<MouseListener> listener : mouseListeners) {
			notifier(*listener);
		}
	}

	void withKeyListeners(std::function<void(KeyListener&)> notifier) {
		for (shared_ptr<KeyListener> listener : keyListeners) {
			notifier(*listener);
		}
	}
};

}

#endif /* SRC_SDLSCREEN_HPP_ */
