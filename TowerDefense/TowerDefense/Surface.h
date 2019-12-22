#pragma once
#include <string>
#include <SDL_image.h>

class Surface
{
public:
	Surface(std::string p_filePath);
	~Surface();

	//Surface(const Surface& p_other);

	SDL_Surface* GetSurface() const;
private:
	std::string _filePath;
	SDL_Surface * _surface;
};

