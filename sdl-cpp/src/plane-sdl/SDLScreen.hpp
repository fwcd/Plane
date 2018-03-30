/*
 * SDLScreen.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_SDL_SDLSCREEN_HPP_
#define SRC_PLANE_SDL_SDLSCREEN_HPP_

#include <plane/core/FontAttributes.hpp>
#include <plane/core/IPaintable.hpp>
#include <plane/core/IScreen.hpp>
#include <plane/core/KeyListener.hpp>
#include <plane/core/MouseButton.hpp>
#include <plane/core/MouseEvent.hpp>
#include <plane/core/MouseListener.hpp>
#include <plane/utils/Color.hpp>
#include <plane/utils/Utilities.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

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
		if (TTF_Init() < 0) {
			throw SDLException("Error while initializing TTF engine");
		}

		window = SDL_CreateWindow(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_SHOWN
		);
		if (window == nullptr) {
			throw SDLException("Window creation error");
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			throw SDLException("Renderer creation error");
		}

		screenSurface = SDL_GetWindowSurface(window);
		this->width = width;
		this->height = height;
	}

	virtual ~SDLScreen() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
	}

	virtual void repaintSoon() {
		needsRepaint = true;
	}

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

	virtual float getStringWidth(std::string str, FontAttributes attribs) {
		return getStringBounds(str, attribs).w;
	}

	virtual float getStringHeight(std::string str, FontAttributes attribs) {
		return getStringBounds(str, attribs).h;
	}

	virtual void drawImage(std::string filePath, float x, float y, float& returnedW, float& returnedH) {
		drawImageImpl(filePath, x, y, returnedW, returnedH);
	}

	virtual void drawImageSized(std::string filePath, float x, float y, float w, float h) {
		drawImageImpl(filePath, x, y, w, h);
	}

	virtual void drawString(std::string str, float x, float y, FontAttributes attribs) {
		TTF_Font* font = openTTFFont(attribs);
		if (font == nullptr) {
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

	virtual void addOnTop(shared_ptr<IPaintable> paintable) {
		paintables.push_back(paintable);
	}

	virtual void addOnBottom(shared_ptr<IPaintable> paintable) {
		paintables.insert(paintables.begin(), paintable);
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
						repaintSoon();
						mouseDown = true;
						break;
					case SDL_MOUSEMOTION:
						if (mouseDown) {
							withMouseListeners([e](MouseListener& listener) {listener.fireDrag(e);});
							repaintSoon();
						} else {
							withMouseListeners([e](MouseListener& listener) {listener.fireMove(e);});
						}
						break;
					case SDL_MOUSEBUTTONUP:
						withMouseListeners([e](MouseListener& listener) {listener.fireRelease(e);});
						repaintSoon();
						mouseDown = false;
						break;
					}
				}
			}

			if (needsRepaint) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(renderer);

				for (shared_ptr<IPaintable> paintable : paintables) {
					paintable->paint(*this);
				}

				SDL_RenderPresent(renderer);
				needsRepaint = false;
			}

			SDL_Delay(intervalMs);
		}
	}
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
	vector<shared_ptr<MouseListener>> mouseListeners = vector<shared_ptr<MouseListener>>();
	vector<shared_ptr<KeyListener>> keyListeners = vector<shared_ptr<KeyListener>>();
	vector<shared_ptr<IPaintable>> paintables = vector<shared_ptr<IPaintable>>();
	bool closed = false;
	bool mouseDown = false;
	bool needsRepaint = true;
	int width;
	int height;
	float lastMouseX = -1;
	float lastMouseY = -1;

	void drawImageImpl(std::string filePath, float x, float y, float& w, float& h) {
		initSDLImage(filePath);
		SDL_Surface* imgSurface = imgToSurface(filePath);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imgSurface);
		if (w < 0) {
			w = imgSurface->w;
		}
		if (h < 0) {
			h = imgSurface->h;
		}

		SDL_Rect bounds = {(int) x, (int) y, (int) w, (int) h};

		SDL_RenderCopy(renderer, texture, 0, &bounds);

		SDL_DestroyTexture(texture);
		SDL_FreeSurface(imgSurface);
		IMG_Quit();
	}

	SDL_Rect getStringBounds(std::string str, FontAttributes attribs) {
		TTF_Font* font = openTTFFont(attribs);
		if (font == nullptr) {
			throw SDLException("Font not found.");
		}
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, str.c_str(), getSDLColor());
		int textWidth = textSurface->w;
		int textHeight = textSurface->h;
		SDL_FreeSurface(textSurface);
		TTF_CloseFont(font);

		return {0, 0, textWidth, textHeight};
	}

	TTF_Font* openTTFFont(FontAttributes attribs) {
		return TTF_OpenFont("resources/arial.ttf", attribs.getSize());
	}

	void initSDLImage(std::string path) {
		int imgFlags = 0;
		if (endsWith(path, "png") || endsWith(path, "PNG")) {
			imgFlags = IMG_INIT_PNG;
		} else if (endsWith(path, "jpg") || endsWith(path, "JPG")) {
			imgFlags = IMG_INIT_JPG;
		} else if (endsWith(path, "tif") || endsWith(path, "TIF")) {
			imgFlags = IMG_INIT_TIF;
		} else if (endsWith(path, "webp") || endsWith(path, "WEBP")) {
			imgFlags = IMG_INIT_WEBP;
		}
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			throw SDLException("SDL_image could not be initialized");
		}
	}

	SDL_Surface* imgToSurface(std::string path) {
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr) {
			throw SDLException("Could not load image at " + path);
		}

		SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
		if (optimizedSurface == nullptr) {
			throw SDLException("Could not optimize image at " + path);
		}

		SDL_FreeSurface(loadedSurface);
		return optimizedSurface;
	}

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

#endif /* SRC_PLANE_SDL_SDLSCREEN_HPP_ */
