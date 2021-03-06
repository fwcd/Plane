/*
 * SDLException.hpp
 *
 *  Created on: 28.03.2018
 */

#ifndef SRC_PLANE_SDL_SDLEXCEPTION_HPP_
#define SRC_PLANE_SDL_SDLEXCEPTION_HPP_

#include <plane/utils/PlaneException.hpp>
#include <SDL2/SDL_error.h>
#include <string>

namespace plane {

class SDLException : public PlaneException {
public:
	SDLException(std::string cause) : PlaneException(cause + ": " + std::string(SDL_GetError())) {}

	virtual ~SDLException() {}
};

}

#endif /* SRC_PLANE_SDL_SDLEXCEPTION_HPP_ */
