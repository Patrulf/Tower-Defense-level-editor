#include "stdafx.h"
#include "Surface.h"
#include <stdexcept>

Surface::Surface(std::string p_filePath)
{
	_surface = IMG_Load(p_filePath.c_str());
	if (_surface == nullptr) {
		throw(std::runtime_error("Could not init surface"));
	}
}

Surface::~Surface()
{
	SDL_FreeSurface(_surface);
	_surface = nullptr;
}

SDL_Surface * Surface::GetSurface()
{
	return _surface;
}


