#include "stdafx.h"
#include "SDLInit.h"
#include <SDL_image.h>
#include <stdexcept>


SDLInit::SDLInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}


SDLInit::~SDLInit()
{
	SDL_Quit();
}
