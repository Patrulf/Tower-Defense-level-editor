#include "stdafx.h"
#include "Display.h"
#include <stdexcept>

Display::Display()
{
	if (SDL_GetDesktopDisplayMode(0, &_display) != 0) {
		throw(std::runtime_error("Could not init display"));
	}
}


Display::~Display()
{
}

SDL_DisplayMode& Display::GetDisplay() {
	return _display;
}
