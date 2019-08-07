#pragma once
#include <string>
#include <SDL_image.h>

class Surface
{
public:
	Surface(std::string p_filePath);
	~Surface();
	SDL_Surface* GetSurface();
private:
	SDL_Surface * _surface;
};

