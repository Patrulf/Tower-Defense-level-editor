#pragma once
#include "Display.h"
#include <SDL.h>

class Display
{
public:
	Display();
	~Display();
	SDL_DisplayMode& GetDisplay();
private:
	SDL_DisplayMode _display;
};

